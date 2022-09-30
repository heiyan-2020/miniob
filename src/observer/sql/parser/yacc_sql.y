
%{

#include "sql/parser/parse_defs.h"
#include "sql/parser/yacc_sql.tab.h"
#include "sql/parser/lex.yy.h"
// #include "common/log/log.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

typedef struct ParserContext {
  Query *ssql;
  size_t condition_length;
  size_t value_length;
  Value values[MAX_NUM];
  Condition conditions[MAX_NUM];
  CompOp comp;
} ParserContext;

// 获取子串
// 从 s 中提取下标为 n1 ~ n2 的字符组成一个新字符串，然后返回这个新串的首地址
char *substr(const char *s, int n1, int n2)
{
  char *sp = malloc(sizeof(char) * (n2 - n1 + 2));
  int i, j = 0;
  for (i = n1; i <= n2; i++) {
    sp[j++] = s[i];
  }
  sp[j] = 0;
  return sp;
}

void yyerror(yyscan_t scanner, const char *str)
{
  ParserContext *context = (ParserContext *)(yyget_extra(scanner));
  query_reset(context->ssql);
  context->ssql->flag = SCF_ERROR;
  context->condition_length = 0;
  context->value_length = 0;
  context->ssql->sstr.insertion.unit_cnt = 0;
  printf("parse sql failed. error=%s", str);
}

ParserContext *get_context(yyscan_t scanner)
{
  return (ParserContext *)yyget_extra(scanner);
}

#define CONTEXT get_context(scanner)

%}

%define api.pure full
%lex-param { yyscan_t scanner }
%parse-param { void *scanner }

// 标识 tokens
// 终结符
%token  SEMICOLON
        CREATE
        DROP
        TABLE
        TABLES
        INDEX
        SELECT
        DESC
        SHOW
        SYNC
        INSERT
        DELETE
        UPDATE
        LBRACE
        RBRACE
        COMMA
        TRX_BEGIN
        TRX_COMMIT
        TRX_ROLLBACK
        INT_T
        CHAR_T
        FLOAT_T
        DATE_T
        HELP
        EXIT
        DOT // QUOTE
        INTO
        VALUES
        FROM
        WHERE
        AND
        SET
        ON
        LOAD
        DATA
        INFILE
        UNIQUE
        EQ
        LT
        GT
        LE
        GE
        NE

%union {
  struct _Attr *attr;
  struct _Condition *condition_t;
  struct _Value *value_t;
  char *string;
  int number;
  float floats;
  char *position;
  int boolean;
}

%token <number> INT
%token <floats> FLOAT
%token <string> CHAR
%token <string> DATE

%token <string> STAR
%token <string> ID


// 非终结符
%type <number> type
%type <condition_t> condition
%type <value_t> value
%type <number> number
%type <boolean> unique_opt

%%

commands: // commands or sqls. parser starts here.
	/* empty */
|	commands command
;

command:
 	select
|	insert
|	update
|	delete
|	create_table
|	drop_table
|	show_tables
|	desc_table
|	create_index
|	drop_index
|	sync
|	begin
|	commit
|	rollback
|	load_data
|	help
|	exit
;

exit:			
	EXIT SEMICOLON
	{
		CONTEXT->ssql->flag = SCF_EXIT;
	}
;

help:
	HELP SEMICOLON
	{
		CONTEXT->ssql->flag = SCF_HELP;
	}
;

sync:
	SYNC SEMICOLON
	{
		CONTEXT->ssql->flag = SCF_SYNC;
	}
;

begin:
	TRX_BEGIN SEMICOLON
	{
		CONTEXT->ssql->flag = SCF_BEGIN;
	}
;

commit:
	TRX_COMMIT SEMICOLON
	{
		CONTEXT->ssql->flag = SCF_COMMIT;
	}
;

rollback:
	TRX_ROLLBACK SEMICOLON
	{
		CONTEXT->ssql->flag = SCF_ROLLBACK;
	}
;

drop_table:
	DROP TABLE ID SEMICOLON
	{
		CONTEXT->ssql->flag = SCF_DROP_TABLE;
		drop_table_init(&CONTEXT->ssql->sstr.drop_table, $3);
	}
;

show_tables:
	SHOW TABLES SEMICOLON
	{
		CONTEXT->ssql->flag = SCF_SHOW_TABLES;
	}
;

desc_table:
	DESC ID SEMICOLON
	{
		CONTEXT->ssql->flag = SCF_DESC_TABLE;
		desc_table_init(&CONTEXT->ssql->sstr.desc_table, $2);
	}
;

create_index:
	CREATE unique_opt INDEX ID ON ID LBRACE attr_ref attr_ref_list RBRACE SEMICOLON
	{
		CONTEXT->ssql->flag = SCF_CREATE_INDEX;
		create_index_init(&CONTEXT->ssql->sstr.create_index, $4, $6, $2);
	}
;

attr_ref:
	ID
	{
		create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, $1);
	}
;

attr_ref_list:
	/* empty */
|	COMMA attr_ref attr_ref_list
	{}
;

unique_opt:
	/* empty */
	{
		$$ = false;
	}
|	UNIQUE
	{
		$$ = true;
	}
;

drop_index:
	DROP INDEX ID SEMICOLON
	{
		CONTEXT->ssql->flag = SCF_DROP_INDEX;
		drop_index_init(&CONTEXT->ssql->sstr.drop_index, $3);
	}
;

create_table:
	CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON
	{
		CONTEXT->ssql->flag = SCF_CREATE_TABLE;
		create_table_init_name(&CONTEXT->ssql->sstr.create_table, $3);
	}
;

attr_def_list:
	/* empty */
|	COMMA attr_def attr_def_list
	{}
;

attr_def:
	ID CHAR_T LBRACE number RBRACE
	{
		AttrInfo attribute;
		attr_info_init(&attribute, $1, CHARS, $4);
		create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
	}
|	ID type
	{
		AttrInfo attribute;
		size_t len;
		switch ($2) {
			case CHARS:
			case INTS:
			case FLOATS:
				len = 4;
				break;
			case DATES:
				len = 12;
				break;
			default:
				// TODO: error handle
				assert(0);
		}
		attr_info_init(&attribute, $1, $2, len);
		create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
	}
;

number:
	INT
	{
		$$ = $1;
	}
;

type:
	INT_T
	{
		$$ = INTS;
	}
| 	CHAR_T
	{
		$$ = CHARS;
	}
| 	FLOAT_T
	{
		$$ = FLOATS;
	}
|	DATE_T
	{
		$$ = DATES;
	}
;

insert:
	INSERT INTO ID VALUES value_brace value_brace_list SEMICOLON
	{
		CONTEXT->ssql->flag = SCF_INSERT;
		CONTEXT->ssql->sstr.insertion.relation_name = strdup($3);
	}
;

value_brace_list:
		 /* empty */
| 		 COMMA value_brace value_brace_list
 		 {}
;

value_brace:
	    LBRACE value value_list RBRACE
	    {
		inserts_init(&CONTEXT->ssql->sstr.insertion, CONTEXT->values, CONTEXT->value_length);
		CONTEXT->value_length = 0;
	    }
;

value_list:
	/* empty */
|	COMMA value value_list
	{}
;

value:
	INT
	{
		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], $1);
	}
|	FLOAT
	{
		value_init_float(&CONTEXT->values[CONTEXT->value_length++], $1);
	}
|	CHAR
	{
		$1 = substr($1, 1, strlen($1) - 2);  // remove quote
		value_init_char(&CONTEXT->values[CONTEXT->value_length++], $1);
	}
|	DATE
	{
		$1 = substr($1, 1, strlen($1) - 2);  // remove quote
		value_init_date(&CONTEXT->values[CONTEXT->value_length++], $1);
	}
;
    
delete:
	DELETE FROM ID where SEMICOLON
	{
		CONTEXT->ssql->flag = SCF_DELETE;
		deletes_init_relation(&CONTEXT->ssql->sstr.deletion, $3);
		deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, CONTEXT->conditions, CONTEXT->condition_length);
		// reset
		CONTEXT->condition_length = 0;
	}
;

update:
	UPDATE ID SET ID EQ value where SEMICOLON
	{
		CONTEXT->ssql->flag = SCF_UPDATE;
		Value *value = &CONTEXT->values[0];
		updates_init(&CONTEXT->ssql->sstr.update, $2, $4, value, CONTEXT->conditions, CONTEXT->condition_length);
		// reset
		CONTEXT->value_length = 0;
		CONTEXT->condition_length = 0;
	}
;

select:
	SELECT select_attr FROM ID rel_list where SEMICOLON
	{
		selects_append_relation(&CONTEXT->ssql->sstr.selection, $4);
		selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
		CONTEXT->ssql->flag = SCF_SELECT;
		// reset
		CONTEXT->condition_length = 0;
		CONTEXT->value_length = 0;
	}
;

select_attr:
	STAR
	{
		RelAttr attr;
		relation_attr_init(&attr, NULL, "*");
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
| 	ID attr_list
	{
		RelAttr attr;
		relation_attr_init(&attr, NULL, $1);
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
| 	ID DOT ID attr_list
	{
		RelAttr attr;
		relation_attr_init(&attr, $1, $3);
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
;

attr_list:
	/* empty */
| 	COMMA ID attr_list
	{
		RelAttr attr;
		relation_attr_init(&attr, NULL, $2);
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
| 	COMMA ID DOT ID attr_list
	{
		RelAttr attr;
		relation_attr_init(&attr, $2, $4);
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
;

rel_list:
	/* empty */
| 	COMMA ID rel_list
	{
		selects_append_relation(&CONTEXT->ssql->sstr.selection, $2);
	}
;

where:
	/* empty */
| 	WHERE condition condition_list
	{}
;

condition_list:
	/* empty */
| 	AND condition condition_list
	{}
;

condition:
	ID comOp value
	{
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, $1);

		Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
|	value comOp value
	{
		Value *left_value = &CONTEXT->values[CONTEXT->value_length - 2];
		Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
|	ID comOp ID
	{
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, $1);
		RelAttr right_attr;
		relation_attr_init(&right_attr, NULL, $3);

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
|	value comOp ID
	{
		Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];
		RelAttr right_attr;
		relation_attr_init(&right_attr, NULL, $3);

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
|	ID DOT ID comOp value
	{
		RelAttr left_attr;
		relation_attr_init(&left_attr, $1, $3);
		Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
|	value comOp ID DOT ID
	{
		Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];

		RelAttr right_attr;
		relation_attr_init(&right_attr, $3, $5);

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
|	ID DOT ID comOp ID DOT ID
	{
		RelAttr left_attr;
		relation_attr_init(&left_attr, $1, $3);
		RelAttr right_attr;
		relation_attr_init(&right_attr, $5, $7);

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
;

comOp:
	EQ { CONTEXT->comp = EQUAL_TO; }
| 	LT { CONTEXT->comp = LESS_THAN; }
| 	GT { CONTEXT->comp = GREAT_THAN; }
| 	LE { CONTEXT->comp = LESS_EQUAL; }
| 	GE { CONTEXT->comp = GREAT_EQUAL; }
| 	NE { CONTEXT->comp = NOT_EQUAL; }
;

load_data:
	LOAD DATA INFILE CHAR INTO TABLE ID SEMICOLON
	{
		CONTEXT->ssql->flag = SCF_LOAD_DATA;
		load_data_init(&CONTEXT->ssql->sstr.load_data, $7, $4);
	}
;

%%
//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, Query *sqls) {
	ParserContext context;
	memset(&context, 0, sizeof(context));

	yyscan_t scanner;
	yylex_init_extra(&context, &scanner);
	context.ssql = sqls;
	scan_string(s, scanner);
	int result = yyparse(scanner);
	yylex_destroy(scanner);
	return result;
}
