/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         HSQL_STYPE
#define YYLTYPE         HSQL_LTYPE
/* Substitute the variable and function names.  */
#define yyparse         hsql_parse
#define yylex           hsql_lex
#define yyerror         hsql_error
#define yydebug         hsql_debug
#define yynerrs         hsql_nerrs

/* First part of user prologue.  */
#line 2 "bison_parser.y"

  // clang-format on
  /**
 * bison_parser.y
 * defines bison_parser.h
 * outputs bison_parser.c
 *
 * Grammar File Spec: http://dinosaur.compilertools.net/bison/bison_6.html
 *
 */
  /*********************************
 ** Section 1: C Declarations
 *********************************/

#include "bison_parser.h"
#include "flex_lexer.h"

#include <stdio.h>
#include <string.h>

  using namespace hsql;

  int yyerror(YYLTYPE * llocp, SQLParserResult * result, yyscan_t scanner, const char* msg) {
    result->setIsValid(false);
    result->setErrorDetails(strdup(msg), llocp->first_line, llocp->first_column);
    return 0;
  }
  // clang-format off

#line 108 "bison_parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "bison_parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_STRING = 4,                     /* STRING  */
  YYSYMBOL_FLOATVAL = 5,                   /* FLOATVAL  */
  YYSYMBOL_INTVAL = 6,                     /* INTVAL  */
  YYSYMBOL_DEALLOCATE = 7,                 /* DEALLOCATE  */
  YYSYMBOL_PARAMETERS = 8,                 /* PARAMETERS  */
  YYSYMBOL_INTERSECT = 9,                  /* INTERSECT  */
  YYSYMBOL_TEMPORARY = 10,                 /* TEMPORARY  */
  YYSYMBOL_TIMESTAMP = 11,                 /* TIMESTAMP  */
  YYSYMBOL_DISTINCT = 12,                  /* DISTINCT  */
  YYSYMBOL_NVARCHAR = 13,                  /* NVARCHAR  */
  YYSYMBOL_RESTRICT = 14,                  /* RESTRICT  */
  YYSYMBOL_TRUNCATE = 15,                  /* TRUNCATE  */
  YYSYMBOL_ANALYZE = 16,                   /* ANALYZE  */
  YYSYMBOL_BETWEEN = 17,                   /* BETWEEN  */
  YYSYMBOL_CASCADE = 18,                   /* CASCADE  */
  YYSYMBOL_COLUMNS = 19,                   /* COLUMNS  */
  YYSYMBOL_CONTROL = 20,                   /* CONTROL  */
  YYSYMBOL_DEFAULT = 21,                   /* DEFAULT  */
  YYSYMBOL_EXECUTE = 22,                   /* EXECUTE  */
  YYSYMBOL_EXPLAIN = 23,                   /* EXPLAIN  */
  YYSYMBOL_INTEGER = 24,                   /* INTEGER  */
  YYSYMBOL_NATURAL = 25,                   /* NATURAL  */
  YYSYMBOL_PREPARE = 26,                   /* PREPARE  */
  YYSYMBOL_PRIMARY = 27,                   /* PRIMARY  */
  YYSYMBOL_SCHEMAS = 28,                   /* SCHEMAS  */
  YYSYMBOL_CHARACTER_VARYING = 29,         /* CHARACTER_VARYING  */
  YYSYMBOL_REAL = 30,                      /* REAL  */
  YYSYMBOL_DECIMAL = 31,                   /* DECIMAL  */
  YYSYMBOL_SMALLINT = 32,                  /* SMALLINT  */
  YYSYMBOL_BIGINT = 33,                    /* BIGINT  */
  YYSYMBOL_SPATIAL = 34,                   /* SPATIAL  */
  YYSYMBOL_VARCHAR = 35,                   /* VARCHAR  */
  YYSYMBOL_VIRTUAL = 36,                   /* VIRTUAL  */
  YYSYMBOL_DESCRIBE = 37,                  /* DESCRIBE  */
  YYSYMBOL_BEFORE = 38,                    /* BEFORE  */
  YYSYMBOL_COLUMN = 39,                    /* COLUMN  */
  YYSYMBOL_CREATE = 40,                    /* CREATE  */
  YYSYMBOL_DELETE = 41,                    /* DELETE  */
  YYSYMBOL_DIRECT = 42,                    /* DIRECT  */
  YYSYMBOL_DOUBLE = 43,                    /* DOUBLE  */
  YYSYMBOL_ESCAPE = 44,                    /* ESCAPE  */
  YYSYMBOL_EXCEPT = 45,                    /* EXCEPT  */
  YYSYMBOL_EXISTS = 46,                    /* EXISTS  */
  YYSYMBOL_EXTRACT = 47,                   /* EXTRACT  */
  YYSYMBOL_CAST = 48,                      /* CAST  */
  YYSYMBOL_FORMAT = 49,                    /* FORMAT  */
  YYSYMBOL_GLOBAL = 50,                    /* GLOBAL  */
  YYSYMBOL_HAVING = 51,                    /* HAVING  */
  YYSYMBOL_IMPORT = 52,                    /* IMPORT  */
  YYSYMBOL_INSERT = 53,                    /* INSERT  */
  YYSYMBOL_ISNULL = 54,                    /* ISNULL  */
  YYSYMBOL_OFFSET = 55,                    /* OFFSET  */
  YYSYMBOL_RENAME = 56,                    /* RENAME  */
  YYSYMBOL_SCHEMA = 57,                    /* SCHEMA  */
  YYSYMBOL_SELECT = 58,                    /* SELECT  */
  YYSYMBOL_SORTED = 59,                    /* SORTED  */
  YYSYMBOL_TABLES = 60,                    /* TABLES  */
  YYSYMBOL_UNIQUE = 61,                    /* UNIQUE  */
  YYSYMBOL_UNLOAD = 62,                    /* UNLOAD  */
  YYSYMBOL_UPDATE = 63,                    /* UPDATE  */
  YYSYMBOL_VALUES = 64,                    /* VALUES  */
  YYSYMBOL_AFTER = 65,                     /* AFTER  */
  YYSYMBOL_ALTER = 66,                     /* ALTER  */
  YYSYMBOL_CROSS = 67,                     /* CROSS  */
  YYSYMBOL_DELTA = 68,                     /* DELTA  */
  YYSYMBOL_FLOAT = 69,                     /* FLOAT  */
  YYSYMBOL_GROUP = 70,                     /* GROUP  */
  YYSYMBOL_INDEX = 71,                     /* INDEX  */
  YYSYMBOL_INNER = 72,                     /* INNER  */
  YYSYMBOL_LIMIT = 73,                     /* LIMIT  */
  YYSYMBOL_LOCAL = 74,                     /* LOCAL  */
  YYSYMBOL_MERGE = 75,                     /* MERGE  */
  YYSYMBOL_MINUS = 76,                     /* MINUS  */
  YYSYMBOL_ORDER = 77,                     /* ORDER  */
  YYSYMBOL_OUTER = 78,                     /* OUTER  */
  YYSYMBOL_RIGHT = 79,                     /* RIGHT  */
  YYSYMBOL_TABLE = 80,                     /* TABLE  */
  YYSYMBOL_UNION = 81,                     /* UNION  */
  YYSYMBOL_USING = 82,                     /* USING  */
  YYSYMBOL_WHERE = 83,                     /* WHERE  */
  YYSYMBOL_CALL = 84,                      /* CALL  */
  YYSYMBOL_CASE = 85,                      /* CASE  */
  YYSYMBOL_CHAR = 86,                      /* CHAR  */
  YYSYMBOL_COPY = 87,                      /* COPY  */
  YYSYMBOL_DATE = 88,                      /* DATE  */
  YYSYMBOL_DATETIME = 89,                  /* DATETIME  */
  YYSYMBOL_DESC = 90,                      /* DESC  */
  YYSYMBOL_DROP = 91,                      /* DROP  */
  YYSYMBOL_ELSE = 92,                      /* ELSE  */
  YYSYMBOL_FILE = 93,                      /* FILE  */
  YYSYMBOL_FROM = 94,                      /* FROM  */
  YYSYMBOL_FULL = 95,                      /* FULL  */
  YYSYMBOL_HASH = 96,                      /* HASH  */
  YYSYMBOL_HINT = 97,                      /* HINT  */
  YYSYMBOL_INTO = 98,                      /* INTO  */
  YYSYMBOL_JOIN = 99,                      /* JOIN  */
  YYSYMBOL_LEFT = 100,                     /* LEFT  */
  YYSYMBOL_LIKE = 101,                     /* LIKE  */
  YYSYMBOL_LOAD = 102,                     /* LOAD  */
  YYSYMBOL_LONG = 103,                     /* LONG  */
  YYSYMBOL_NULL = 104,                     /* NULL  */
  YYSYMBOL_PLAN = 105,                     /* PLAN  */
  YYSYMBOL_SHOW = 106,                     /* SHOW  */
  YYSYMBOL_TEXT = 107,                     /* TEXT  */
  YYSYMBOL_THEN = 108,                     /* THEN  */
  YYSYMBOL_TIME = 109,                     /* TIME  */
  YYSYMBOL_VIEW = 110,                     /* VIEW  */
  YYSYMBOL_WHEN = 111,                     /* WHEN  */
  YYSYMBOL_WITH = 112,                     /* WITH  */
  YYSYMBOL_ADD = 113,                      /* ADD  */
  YYSYMBOL_ALL = 114,                      /* ALL  */
  YYSYMBOL_AND = 115,                      /* AND  */
  YYSYMBOL_ASC = 116,                      /* ASC  */
  YYSYMBOL_END = 117,                      /* END  */
  YYSYMBOL_FOR = 118,                      /* FOR  */
  YYSYMBOL_INT = 119,                      /* INT  */
  YYSYMBOL_KEY = 120,                      /* KEY  */
  YYSYMBOL_NOT = 121,                      /* NOT  */
  YYSYMBOL_OFF = 122,                      /* OFF  */
  YYSYMBOL_SET = 123,                      /* SET  */
  YYSYMBOL_TOP = 124,                      /* TOP  */
  YYSYMBOL_AS = 125,                       /* AS  */
  YYSYMBOL_BY = 126,                       /* BY  */
  YYSYMBOL_IF = 127,                       /* IF  */
  YYSYMBOL_IN = 128,                       /* IN  */
  YYSYMBOL_IS = 129,                       /* IS  */
  YYSYMBOL_OF = 130,                       /* OF  */
  YYSYMBOL_ON = 131,                       /* ON  */
  YYSYMBOL_OR = 132,                       /* OR  */
  YYSYMBOL_TO = 133,                       /* TO  */
  YYSYMBOL_NO = 134,                       /* NO  */
  YYSYMBOL_ARRAY = 135,                    /* ARRAY  */
  YYSYMBOL_CONCAT = 136,                   /* CONCAT  */
  YYSYMBOL_ILIKE = 137,                    /* ILIKE  */
  YYSYMBOL_SECOND = 138,                   /* SECOND  */
  YYSYMBOL_MINUTE = 139,                   /* MINUTE  */
  YYSYMBOL_HOUR = 140,                     /* HOUR  */
  YYSYMBOL_DAY = 141,                      /* DAY  */
  YYSYMBOL_MONTH = 142,                    /* MONTH  */
  YYSYMBOL_YEAR = 143,                     /* YEAR  */
  YYSYMBOL_SECONDS = 144,                  /* SECONDS  */
  YYSYMBOL_MINUTES = 145,                  /* MINUTES  */
  YYSYMBOL_HOURS = 146,                    /* HOURS  */
  YYSYMBOL_DAYS = 147,                     /* DAYS  */
  YYSYMBOL_MONTHS = 148,                   /* MONTHS  */
  YYSYMBOL_YEARS = 149,                    /* YEARS  */
  YYSYMBOL_INTERVAL = 150,                 /* INTERVAL  */
  YYSYMBOL_TRUE = 151,                     /* TRUE  */
  YYSYMBOL_FALSE = 152,                    /* FALSE  */
  YYSYMBOL_BOOLEAN = 153,                  /* BOOLEAN  */
  YYSYMBOL_TRANSACTION = 154,              /* TRANSACTION  */
  YYSYMBOL_BEGIN = 155,                    /* BEGIN  */
  YYSYMBOL_COMMIT = 156,                   /* COMMIT  */
  YYSYMBOL_ROLLBACK = 157,                 /* ROLLBACK  */
  YYSYMBOL_NOWAIT = 158,                   /* NOWAIT  */
  YYSYMBOL_SKIP = 159,                     /* SKIP  */
  YYSYMBOL_LOCKED = 160,                   /* LOCKED  */
  YYSYMBOL_SHARE = 161,                    /* SHARE  */
  YYSYMBOL_162_ = 162,                     /* '='  */
  YYSYMBOL_EQUALS = 163,                   /* EQUALS  */
  YYSYMBOL_NOTEQUALS = 164,                /* NOTEQUALS  */
  YYSYMBOL_165_ = 165,                     /* '<'  */
  YYSYMBOL_166_ = 166,                     /* '>'  */
  YYSYMBOL_LESS = 167,                     /* LESS  */
  YYSYMBOL_GREATER = 168,                  /* GREATER  */
  YYSYMBOL_LESSEQ = 169,                   /* LESSEQ  */
  YYSYMBOL_GREATEREQ = 170,                /* GREATEREQ  */
  YYSYMBOL_NOTNULL = 171,                  /* NOTNULL  */
  YYSYMBOL_172_ = 172,                     /* '+'  */
  YYSYMBOL_173_ = 173,                     /* '-'  */
  YYSYMBOL_174_ = 174,                     /* '*'  */
  YYSYMBOL_175_ = 175,                     /* '/'  */
  YYSYMBOL_176_ = 176,                     /* '%'  */
  YYSYMBOL_177_ = 177,                     /* '^'  */
  YYSYMBOL_UMINUS = 178,                   /* UMINUS  */
  YYSYMBOL_179_ = 179,                     /* '['  */
  YYSYMBOL_180_ = 180,                     /* ']'  */
  YYSYMBOL_181_ = 181,                     /* '('  */
  YYSYMBOL_182_ = 182,                     /* ')'  */
  YYSYMBOL_183_ = 183,                     /* '.'  */
  YYSYMBOL_184_ = 184,                     /* ';'  */
  YYSYMBOL_185_ = 185,                     /* ','  */
  YYSYMBOL_186_ = 186,                     /* '?'  */
  YYSYMBOL_YYACCEPT = 187,                 /* $accept  */
  YYSYMBOL_input = 188,                    /* input  */
  YYSYMBOL_statement_list = 189,           /* statement_list  */
  YYSYMBOL_statement = 190,                /* statement  */
  YYSYMBOL_preparable_statement = 191,     /* preparable_statement  */
  YYSYMBOL_opt_hints = 192,                /* opt_hints  */
  YYSYMBOL_hint_list = 193,                /* hint_list  */
  YYSYMBOL_hint = 194,                     /* hint  */
  YYSYMBOL_transaction_statement = 195,    /* transaction_statement  */
  YYSYMBOL_opt_transaction_keyword = 196,  /* opt_transaction_keyword  */
  YYSYMBOL_prepare_statement = 197,        /* prepare_statement  */
  YYSYMBOL_prepare_target_query = 198,     /* prepare_target_query  */
  YYSYMBOL_execute_statement = 199,        /* execute_statement  */
  YYSYMBOL_import_statement = 200,         /* import_statement  */
  YYSYMBOL_file_type = 201,                /* file_type  */
  YYSYMBOL_file_path = 202,                /* file_path  */
  YYSYMBOL_opt_file_type = 203,            /* opt_file_type  */
  YYSYMBOL_export_statement = 204,         /* export_statement  */
  YYSYMBOL_show_statement = 205,           /* show_statement  */
  YYSYMBOL_create_statement = 206,         /* create_statement  */
  YYSYMBOL_opt_not_exists = 207,           /* opt_not_exists  */
  YYSYMBOL_opt_unique = 208,               /* opt_unique  */
  YYSYMBOL_table_elem_commalist = 209,     /* table_elem_commalist  */
  YYSYMBOL_table_elem = 210,               /* table_elem  */
  YYSYMBOL_column_def = 211,               /* column_def  */
  YYSYMBOL_column_type = 212,              /* column_type  */
  YYSYMBOL_opt_time_precision = 213,       /* opt_time_precision  */
  YYSYMBOL_opt_decimal_specification = 214, /* opt_decimal_specification  */
  YYSYMBOL_opt_column_constraints = 215,   /* opt_column_constraints  */
  YYSYMBOL_column_constraint_set = 216,    /* column_constraint_set  */
  YYSYMBOL_column_constraint = 217,        /* column_constraint  */
  YYSYMBOL_table_constraint = 218,         /* table_constraint  */
  YYSYMBOL_drop_statement = 219,           /* drop_statement  */
  YYSYMBOL_opt_exists = 220,               /* opt_exists  */
  YYSYMBOL_alter_statement = 221,          /* alter_statement  */
  YYSYMBOL_alter_action = 222,             /* alter_action  */
  YYSYMBOL_drop_action = 223,              /* drop_action  */
  YYSYMBOL_delete_statement = 224,         /* delete_statement  */
  YYSYMBOL_truncate_statement = 225,       /* truncate_statement  */
  YYSYMBOL_insert_statement = 226,         /* insert_statement  */
  YYSYMBOL_opt_column_list = 227,          /* opt_column_list  */
  YYSYMBOL_update_statement = 228,         /* update_statement  */
  YYSYMBOL_update_clause_commalist = 229,  /* update_clause_commalist  */
  YYSYMBOL_update_clause = 230,            /* update_clause  */
  YYSYMBOL_select_statement = 231,         /* select_statement  */
  YYSYMBOL_select_within_set_operation = 232, /* select_within_set_operation  */
  YYSYMBOL_select_within_set_operation_no_parentheses = 233, /* select_within_set_operation_no_parentheses  */
  YYSYMBOL_select_with_paren = 234,        /* select_with_paren  */
  YYSYMBOL_select_no_paren = 235,          /* select_no_paren  */
  YYSYMBOL_set_operator = 236,             /* set_operator  */
  YYSYMBOL_set_type = 237,                 /* set_type  */
  YYSYMBOL_opt_all = 238,                  /* opt_all  */
  YYSYMBOL_select_clause = 239,            /* select_clause  */
  YYSYMBOL_opt_distinct = 240,             /* opt_distinct  */
  YYSYMBOL_select_list = 241,              /* select_list  */
  YYSYMBOL_opt_from_clause = 242,          /* opt_from_clause  */
  YYSYMBOL_from_clause = 243,              /* from_clause  */
  YYSYMBOL_opt_where = 244,                /* opt_where  */
  YYSYMBOL_opt_group = 245,                /* opt_group  */
  YYSYMBOL_opt_having = 246,               /* opt_having  */
  YYSYMBOL_opt_order = 247,                /* opt_order  */
  YYSYMBOL_order_list = 248,               /* order_list  */
  YYSYMBOL_order_desc = 249,               /* order_desc  */
  YYSYMBOL_opt_order_type = 250,           /* opt_order_type  */
  YYSYMBOL_opt_top = 251,                  /* opt_top  */
  YYSYMBOL_opt_limit = 252,                /* opt_limit  */
  YYSYMBOL_expr_list = 253,                /* expr_list  */
  YYSYMBOL_opt_literal_list = 254,         /* opt_literal_list  */
  YYSYMBOL_literal_list = 255,             /* literal_list  */
  YYSYMBOL_expr_alias = 256,               /* expr_alias  */
  YYSYMBOL_expr = 257,                     /* expr  */
  YYSYMBOL_operand = 258,                  /* operand  */
  YYSYMBOL_scalar_expr = 259,              /* scalar_expr  */
  YYSYMBOL_unary_expr = 260,               /* unary_expr  */
  YYSYMBOL_binary_expr = 261,              /* binary_expr  */
  YYSYMBOL_logic_expr = 262,               /* logic_expr  */
  YYSYMBOL_in_expr = 263,                  /* in_expr  */
  YYSYMBOL_case_expr = 264,                /* case_expr  */
  YYSYMBOL_case_list = 265,                /* case_list  */
  YYSYMBOL_exists_expr = 266,              /* exists_expr  */
  YYSYMBOL_comp_expr = 267,                /* comp_expr  */
  YYSYMBOL_function_expr = 268,            /* function_expr  */
  YYSYMBOL_extract_expr = 269,             /* extract_expr  */
  YYSYMBOL_cast_expr = 270,                /* cast_expr  */
  YYSYMBOL_datetime_field = 271,           /* datetime_field  */
  YYSYMBOL_datetime_field_plural = 272,    /* datetime_field_plural  */
  YYSYMBOL_duration_field = 273,           /* duration_field  */
  YYSYMBOL_array_expr = 274,               /* array_expr  */
  YYSYMBOL_array_index = 275,              /* array_index  */
  YYSYMBOL_between_expr = 276,             /* between_expr  */
  YYSYMBOL_column_name = 277,              /* column_name  */
  YYSYMBOL_literal = 278,                  /* literal  */
  YYSYMBOL_string_literal = 279,           /* string_literal  */
  YYSYMBOL_bool_literal = 280,             /* bool_literal  */
  YYSYMBOL_num_literal = 281,              /* num_literal  */
  YYSYMBOL_int_literal = 282,              /* int_literal  */
  YYSYMBOL_null_literal = 283,             /* null_literal  */
  YYSYMBOL_date_literal = 284,             /* date_literal  */
  YYSYMBOL_interval_literal = 285,         /* interval_literal  */
  YYSYMBOL_param_expr = 286,               /* param_expr  */
  YYSYMBOL_table_ref = 287,                /* table_ref  */
  YYSYMBOL_table_ref_atomic = 288,         /* table_ref_atomic  */
  YYSYMBOL_nonjoin_table_ref_atomic = 289, /* nonjoin_table_ref_atomic  */
  YYSYMBOL_table_ref_commalist = 290,      /* table_ref_commalist  */
  YYSYMBOL_table_ref_name = 291,           /* table_ref_name  */
  YYSYMBOL_table_ref_name_no_alias = 292,  /* table_ref_name_no_alias  */
  YYSYMBOL_table_name = 293,               /* table_name  */
  YYSYMBOL_opt_index_name = 294,           /* opt_index_name  */
  YYSYMBOL_table_alias = 295,              /* table_alias  */
  YYSYMBOL_opt_table_alias = 296,          /* opt_table_alias  */
  YYSYMBOL_alias = 297,                    /* alias  */
  YYSYMBOL_opt_alias = 298,                /* opt_alias  */
  YYSYMBOL_opt_locking_clause = 299,       /* opt_locking_clause  */
  YYSYMBOL_opt_locking_clause_list = 300,  /* opt_locking_clause_list  */
  YYSYMBOL_locking_clause = 301,           /* locking_clause  */
  YYSYMBOL_row_lock_mode = 302,            /* row_lock_mode  */
  YYSYMBOL_opt_row_lock_policy = 303,      /* opt_row_lock_policy  */
  YYSYMBOL_opt_with_clause = 304,          /* opt_with_clause  */
  YYSYMBOL_with_clause = 305,              /* with_clause  */
  YYSYMBOL_with_description_list = 306,    /* with_description_list  */
  YYSYMBOL_with_description = 307,         /* with_description  */
  YYSYMBOL_join_clause = 308,              /* join_clause  */
  YYSYMBOL_opt_join_type = 309,            /* opt_join_type  */
  YYSYMBOL_join_condition = 310,           /* join_condition  */
  YYSYMBOL_opt_semicolon = 311,            /* opt_semicolon  */
  YYSYMBOL_ident_commalist = 312           /* ident_commalist  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined HSQL_LTYPE_IS_TRIVIAL && HSQL_LTYPE_IS_TRIVIAL \
             && defined HSQL_STYPE_IS_TRIVIAL && HSQL_STYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  70
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   936

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  187
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  126
/* YYNRULES -- Number of rules.  */
#define YYNRULES  322
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  577

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   424


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   176,     2,     2,
     181,   182,   174,   172,   185,   173,   183,   175,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   184,
     165,   162,   166,   186,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   179,     2,   180,   177,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   163,   164,   167,
     168,   169,   170,   171,   178
};

#if HSQL_DEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   304,   304,   323,   329,   336,   340,   344,   345,   346,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     363,   364,   366,   370,   375,   379,   389,   390,   391,   393,
     393,   399,   405,   407,   411,   422,   428,   435,   450,   455,
     456,   462,   474,   475,   480,   485,   496,   509,   521,   528,
     536,   545,   546,   548,   549,   551,   555,   560,   561,   563,
     570,   571,   572,   573,   574,   575,   576,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   592,   593,
     595,   596,   597,   599,   600,   602,   606,   611,   612,   613,
     614,   616,   617,   625,   631,   637,   643,   649,   650,   657,
     663,   665,   675,   682,   693,   700,   708,   709,   716,   723,
     727,   732,   742,   746,   750,   762,   762,   764,   765,   774,
     775,   777,   791,   803,   808,   812,   816,   821,   822,   824,
     834,   835,   837,   839,   840,   842,   844,   845,   847,   852,
     854,   855,   857,   858,   860,   864,   869,   871,   872,   873,
     877,   878,   880,   881,   882,   883,   884,   885,   890,   894,
     899,   900,   902,   906,   911,   919,   919,   919,   919,   919,
     921,   922,   922,   922,   922,   922,   922,   922,   922,   923,
     923,   927,   927,   929,   930,   931,   932,   933,   935,   935,
     936,   937,   938,   939,   940,   941,   942,   943,   944,   946,
     947,   949,   950,   951,   952,   956,   957,   958,   959,   961,
     962,   964,   965,   967,   968,   969,   970,   971,   972,   973,
     975,   976,   978,   980,   982,   983,   984,   985,   986,   987,
     989,   990,   991,   992,   993,   994,   996,   996,   998,  1000,
    1002,  1004,  1005,  1006,  1007,  1009,  1009,  1009,  1009,  1009,
    1009,  1009,  1011,  1013,  1014,  1016,  1017,  1019,  1021,  1023,
    1034,  1038,  1049,  1081,  1090,  1090,  1097,  1097,  1099,  1099,
    1106,  1110,  1115,  1123,  1129,  1133,  1138,  1139,  1141,  1141,
    1143,  1143,  1145,  1146,  1148,  1148,  1154,  1155,  1157,  1161,
    1166,  1172,  1179,  1180,  1181,  1182,  1184,  1185,  1186,  1192,
    1192,  1194,  1196,  1200,  1205,  1215,  1222,  1230,  1246,  1247,
    1248,  1249,  1250,  1251,  1252,  1253,  1254,  1255,  1257,  1263,
    1263,  1266,  1270
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER", "STRING",
  "FLOATVAL", "INTVAL", "DEALLOCATE", "PARAMETERS", "INTERSECT",
  "TEMPORARY", "TIMESTAMP", "DISTINCT", "NVARCHAR", "RESTRICT", "TRUNCATE",
  "ANALYZE", "BETWEEN", "CASCADE", "COLUMNS", "CONTROL", "DEFAULT",
  "EXECUTE", "EXPLAIN", "INTEGER", "NATURAL", "PREPARE", "PRIMARY",
  "SCHEMAS", "CHARACTER_VARYING", "REAL", "DECIMAL", "SMALLINT", "BIGINT",
  "SPATIAL", "VARCHAR", "VIRTUAL", "DESCRIBE", "BEFORE", "COLUMN",
  "CREATE", "DELETE", "DIRECT", "DOUBLE", "ESCAPE", "EXCEPT", "EXISTS",
  "EXTRACT", "CAST", "FORMAT", "GLOBAL", "HAVING", "IMPORT", "INSERT",
  "ISNULL", "OFFSET", "RENAME", "SCHEMA", "SELECT", "SORTED", "TABLES",
  "UNIQUE", "UNLOAD", "UPDATE", "VALUES", "AFTER", "ALTER", "CROSS",
  "DELTA", "FLOAT", "GROUP", "INDEX", "INNER", "LIMIT", "LOCAL", "MERGE",
  "MINUS", "ORDER", "OUTER", "RIGHT", "TABLE", "UNION", "USING", "WHERE",
  "CALL", "CASE", "CHAR", "COPY", "DATE", "DATETIME", "DESC", "DROP",
  "ELSE", "FILE", "FROM", "FULL", "HASH", "HINT", "INTO", "JOIN", "LEFT",
  "LIKE", "LOAD", "LONG", "NULL", "PLAN", "SHOW", "TEXT", "THEN", "TIME",
  "VIEW", "WHEN", "WITH", "ADD", "ALL", "AND", "ASC", "END", "FOR", "INT",
  "KEY", "NOT", "OFF", "SET", "TOP", "AS", "BY", "IF", "IN", "IS", "OF",
  "ON", "OR", "TO", "NO", "ARRAY", "CONCAT", "ILIKE", "SECOND", "MINUTE",
  "HOUR", "DAY", "MONTH", "YEAR", "SECONDS", "MINUTES", "HOURS", "DAYS",
  "MONTHS", "YEARS", "INTERVAL", "TRUE", "FALSE", "BOOLEAN", "TRANSACTION",
  "BEGIN", "COMMIT", "ROLLBACK", "NOWAIT", "SKIP", "LOCKED", "SHARE",
  "'='", "EQUALS", "NOTEQUALS", "'<'", "'>'", "LESS", "GREATER", "LESSEQ",
  "GREATEREQ", "NOTNULL", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'",
  "UMINUS", "'['", "']'", "'('", "')'", "'.'", "';'", "','", "'?'",
  "$accept", "input", "statement_list", "statement",
  "preparable_statement", "opt_hints", "hint_list", "hint",
  "transaction_statement", "opt_transaction_keyword", "prepare_statement",
  "prepare_target_query", "execute_statement", "import_statement",
  "file_type", "file_path", "opt_file_type", "export_statement",
  "show_statement", "create_statement", "opt_not_exists", "opt_unique",
  "table_elem_commalist", "table_elem", "column_def", "column_type",
  "opt_time_precision", "opt_decimal_specification",
  "opt_column_constraints", "column_constraint_set", "column_constraint",
  "table_constraint", "drop_statement", "opt_exists", "alter_statement",
  "alter_action", "drop_action", "delete_statement", "truncate_statement",
  "insert_statement", "opt_column_list", "update_statement",
  "update_clause_commalist", "update_clause", "select_statement",
  "select_within_set_operation",
  "select_within_set_operation_no_parentheses", "select_with_paren",
  "select_no_paren", "set_operator", "set_type", "opt_all",
  "select_clause", "opt_distinct", "select_list", "opt_from_clause",
  "from_clause", "opt_where", "opt_group", "opt_having", "opt_order",
  "order_list", "order_desc", "opt_order_type", "opt_top", "opt_limit",
  "expr_list", "opt_literal_list", "literal_list", "expr_alias", "expr",
  "operand", "scalar_expr", "unary_expr", "binary_expr", "logic_expr",
  "in_expr", "case_expr", "case_list", "exists_expr", "comp_expr",
  "function_expr", "extract_expr", "cast_expr", "datetime_field",
  "datetime_field_plural", "duration_field", "array_expr", "array_index",
  "between_expr", "column_name", "literal", "string_literal",
  "bool_literal", "num_literal", "int_literal", "null_literal",
  "date_literal", "interval_literal", "param_expr", "table_ref",
  "table_ref_atomic", "nonjoin_table_ref_atomic", "table_ref_commalist",
  "table_ref_name", "table_ref_name_no_alias", "table_name",
  "opt_index_name", "table_alias", "opt_table_alias", "alias", "opt_alias",
  "opt_locking_clause", "opt_locking_clause_list", "locking_clause",
  "row_lock_mode", "opt_row_lock_policy", "opt_with_clause", "with_clause",
  "with_description_list", "with_description", "join_clause",
  "opt_join_type", "join_condition", "opt_semicolon", "ident_commalist", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-454)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-320)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     648,    63,    77,   172,   215,    77,   -32,    35,    94,   124,
      77,   152,    77,    77,   105,    41,   234,    98,    98,    98,
     263,    86,  -454,   160,  -454,   160,  -454,  -454,  -454,  -454,
    -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,   -31,  -454,
     276,   102,  -454,   127,   192,  -454,  -454,   198,   198,   236,
      77,   328,    77,   211,  -454,   208,    64,  -454,   208,   208,
     208,    77,  -454,   216,   157,  -454,  -454,  -454,  -454,  -454,
    -454,   616,  -454,   246,  -454,  -454,   224,   -31,    46,  -454,
      83,  -454,   347,    31,   356,   249,    77,    77,   198,   288,
    -454,   285,   209,   388,   351,    77,   389,   389,   395,    77,
      77,  -454,   218,   234,  -454,   219,   396,   392,   223,   226,
    -454,  -454,  -454,   -31,   287,   281,   -31,    -4,  -454,  -454,
    -454,  -454,   405,  -454,   410,  -454,  -454,  -454,   233,   231,
    -454,  -454,  -454,  -454,   318,  -454,  -454,  -454,  -454,  -454,
    -454,   371,   -63,   209,   415,   348,  -454,   389,   419,   126,
     261,   -41,  -454,  -454,   333,   313,  -454,   313,  -454,  -454,
    -454,  -454,  -454,   423,  -454,  -454,   348,  -454,  -454,   350,
    -454,  -454,    46,  -454,  -454,   348,   350,   348,   163,   310,
    -454,   225,  -454,    31,  -454,  -454,  -454,  -454,  -454,  -454,
    -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,
     426,   319,    36,   305,  -454,   301,    50,   254,   256,   257,
     188,   407,   260,   439,  -454,   299,   143,   471,  -454,  -454,
    -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,
    -454,  -454,  -454,  -454,   342,  -454,    71,   265,  -454,   348,
     388,  -454,   402,  -454,  -454,   398,  -454,  -454,   267,   137,
    -454,   374,   286,  -454,    23,    -4,   -31,   289,  -454,    88,
      -4,   143,   420,    27,   107,  -454,   310,  -454,  -454,  -454,
     377,  -454,   688,   357,   295,   139,  -454,  -454,  -454,   319,
      77,    26,    15,   421,   225,   348,   348,   149,   -43,   297,
     439,   708,   348,   114,   300,   -57,   348,   348,   439,  -454,
     439,   -56,   303,   -45,   439,   439,   439,   439,   439,   439,
     439,   439,   439,   439,   439,   439,   439,   439,   439,   396,
      77,  -454,   478,    31,   143,  -454,   208,   328,    31,  -454,
     423,    17,   288,  -454,   348,  -454,   486,  -454,  -454,  -454,
    -454,   348,  -454,  -454,  -454,   310,   348,   348,  -454,   329,
     373,  -454,    47,  -454,   389,  -454,  -454,   315,  -454,   316,
    -454,  -454,   320,  -454,  -454,   321,  -454,  -454,  -454,  -454,
     322,  -454,  -454,    16,   323,   419,  -454,    36,  -454,   324,
    -454,   348,  -454,  -454,   309,   400,   185,    48,   138,   348,
     348,  -454,   421,   406,  -114,  -454,  -454,  -454,   391,   687,
     739,   439,   327,   299,  -454,   408,   330,   739,   739,   739,
     739,   757,   757,   757,   757,   114,   114,    -6,    -6,    -6,
     -89,   334,  -454,  -454,   148,   507,  -454,   173,  -454,   319,
    -454,    54,  -454,   331,  -454,    37,  -454,   443,  -454,  -454,
    -454,  -454,   143,   143,  -454,   452,   419,  -454,   358,  -454,
    -454,   511,   513,  -454,   514,   517,   520,  -454,   411,  -454,
    -454,   428,  -454,    16,  -454,   419,   174,  -454,   419,   190,
    -454,   348,   688,   348,   348,  -454,   179,   108,   353,  -454,
     439,   739,   299,   354,   191,  -454,  -454,  -454,  -454,  -454,
     355,   431,  -454,  -454,  -454,   455,   460,   461,   441,    17,
     538,  -454,  -454,  -454,   418,  -454,  -454,    28,  -454,   363,
     195,   364,   365,   366,  -454,  -454,  -454,   197,  -454,   201,
    -454,   -48,   367,   143,   180,  -454,   348,  -454,   708,   368,
     203,  -454,  -454,    37,    17,  -454,  -454,  -454,    17,   147,
     370,   348,  -454,  -454,  -454,   546,  -454,  -454,  -454,  -454,
    -454,  -454,  -454,  -454,   143,  -454,  -454,  -454,  -454,   187,
     419,   -28,   372,   375,   348,   207,   348,  -454,  -454,    21,
     143,  -454,  -454,   143,   378,   380,  -454
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     300,     0,     0,     0,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    30,    30,    30,
       0,   320,     3,    21,    19,    21,    18,     8,     9,     7,
      11,    16,    17,    13,    14,    12,    15,    10,     0,   299,
       0,   274,   103,    33,     0,    44,    53,    52,    52,     0,
       0,     0,     0,     0,   273,    98,     0,    45,    98,    98,
      98,     0,    42,     0,   301,   302,    29,    26,    28,    27,
       1,   300,     2,     0,     6,     5,   151,     0,   112,   113,
     143,    95,     0,   161,     0,     0,     0,     0,    52,   137,
      37,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,    43,     0,     0,     4,     0,     0,   131,     0,     0,
     125,   126,   124,     0,   128,     0,     0,   157,   275,   252,
     255,   257,     0,   258,     0,   253,   254,   263,     0,   160,
     162,   245,   246,   247,   256,   248,   249,   250,   251,    32,
      31,     0,     0,   107,   277,     0,   102,     0,     0,     0,
       0,   137,   109,    97,     0,    40,    38,    40,    96,    93,
      94,   304,   303,     0,   150,   130,     0,   120,   119,   143,
     116,   115,   117,   127,   123,     0,   143,     0,     0,   287,
     259,   262,    34,     0,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   260,    51,
       0,   300,     0,     0,   276,     0,   241,     0,     0,     0,
       0,     0,     0,     0,   243,     0,   136,   165,   172,   173,
     174,   167,   169,   175,   168,   188,   176,   177,   178,   179,
     171,   166,   181,   182,     0,   321,     0,     0,   105,     0,
       0,   108,     0,    99,   100,     0,    36,    41,    24,     0,
      22,   134,   132,   158,   285,   157,     0,   142,   144,   149,
     157,   153,   155,   152,     0,   121,   286,   288,   261,   163,
       0,    48,     0,     0,     0,     0,    55,    57,    58,   300,
       0,   131,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   184,     0,   183,     0,     0,     0,     0,     0,   185,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   106,     0,     0,   111,   110,    98,     0,     0,    20,
       0,     0,   137,   133,     0,   283,     0,   284,   164,   114,
     118,     0,   148,   147,   146,   287,     0,     0,   292,     0,
       0,   294,   298,   289,     0,    76,    70,     0,    72,    82,
      73,    60,     0,    67,    68,     0,    64,    65,    71,    74,
      79,    69,    61,    84,     0,     0,    47,     0,    50,     0,
     220,     0,   242,   244,     0,     0,     0,     0,     0,     0,
       0,   207,     0,     0,     0,   180,   170,   199,   200,     0,
     195,     0,     0,     0,   186,     0,   198,   197,   213,   214,
     215,   216,   217,   218,   219,   190,   189,   192,   191,   193,
     194,     0,    35,   322,     0,     0,    39,     0,    23,   300,
     135,   264,   266,     0,   268,   281,   267,   139,   159,   282,
     145,   122,   156,   154,   295,     0,     0,   297,     0,   290,
      46,     0,     0,    66,     0,     0,     0,    75,     0,    88,
      89,     0,    59,    83,    85,     0,     0,    56,     0,     0,
     211,     0,     0,     0,     0,   205,     0,     0,     0,   238,
       0,   196,     0,     0,     0,   187,   239,   104,   101,    25,
       0,     0,   316,   308,   314,   312,   315,   310,     0,     0,
       0,   280,   272,   278,     0,   129,   293,   298,   296,     0,
       0,     0,     0,     0,    87,    90,    86,     0,    92,     0,
     221,     0,     0,   209,     0,   208,     0,   212,   240,     0,
       0,   203,   201,   281,     0,   311,   313,   309,     0,   265,
     282,     0,   291,    63,    81,     0,    77,    62,    78,    91,
      49,   222,   223,   206,   210,   204,   202,   269,   305,   317,
       0,   141,     0,     0,     0,     0,     0,   138,    80,     0,
     318,   306,   279,   140,   241,     0,   307
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -454,  -454,  -454,   482,  -454,   530,  -454,   235,  -454,    38,
    -454,  -454,  -454,  -454,   237,   -83,   409,  -454,  -454,  -454,
      -7,  -454,  -454,   186,  -454,    95,  -454,  -454,  -454,  -454,
     106,  -454,  -454,   -52,  -454,  -454,  -454,  -454,  -454,  -454,
     425,  -454,  -454,   335,  -186,   -95,  -454,    45,   -76,   -36,
    -454,  -454,   -91,   290,  -454,  -454,  -454,  -132,  -454,  -454,
      52,  -454,   229,  -454,  -454,   -81,  -258,  -454,   -22,   239,
    -145,  -202,  -454,  -454,  -454,  -454,  -454,  -454,   291,  -454,
    -454,  -454,  -454,  -454,  -153,  -454,  -454,  -454,  -454,  -454,
       7,   -66,   -93,  -454,  -454,   -90,  -454,  -454,  -454,  -454,
    -454,  -453,    43,  -454,  -454,  -454,     0,  -454,  -454,    49,
     325,  -454,   238,  -454,   332,  -454,    78,  -454,  -454,  -454,
     481,  -454,  -454,  -454,  -454,  -322
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    20,    21,    22,    23,    74,   249,   250,    24,    67,
      25,   140,    26,    27,    91,   155,   246,    28,    29,    30,
      86,    49,   275,   276,   277,   373,   457,   453,   462,   463,
     464,   278,    31,    95,    32,   243,   244,    33,    34,    35,
     149,    36,   151,   152,    37,   169,   170,   171,    79,   113,
     114,   174,    80,   166,   251,   332,   333,   146,   505,   567,
     117,   257,   258,   344,   107,   179,   252,   128,   129,   253,
     254,   217,   218,   219,   220,   221,   222,   223,   288,   224,
     225,   226,   227,   228,   196,   197,   198,   229,   230,   231,
     232,   233,   131,   132,   133,   134,   135,   136,   137,   138,
     430,   431,   432,   433,   434,    53,   435,   205,   501,   502,
     503,   338,   265,   266,   267,   352,   449,    38,    39,    64,
      65,   436,   498,   571,    72,   236
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     216,   109,    42,   156,   156,    45,    98,    99,   100,   291,
      54,   293,    56,    57,   157,   271,   164,   130,   382,   241,
      41,   176,   172,   566,   574,   172,   335,    76,   268,    46,
     259,   200,   261,   263,   394,   119,   120,   121,   165,   272,
     335,    87,   145,   458,   116,   401,   539,   304,    47,   389,
      89,   177,    92,   466,   156,   110,    68,    69,   296,   404,
      61,   101,   201,   273,   234,   287,   479,   296,   390,   178,
     295,   334,   402,   238,   391,   297,   405,   459,    48,   491,
      41,   144,   347,    78,   297,   559,   142,   143,   291,    40,
     319,   111,   110,   378,   324,   154,   399,   274,   400,   159,
     160,    62,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   269,   202,   122,
     460,   492,   108,   469,   507,   396,   493,   112,   111,    50,
     304,   385,   494,   495,   551,   123,   256,   461,   296,   294,
     386,   387,   296,   517,   240,   484,   519,   161,   336,   496,
      77,   397,   398,  -317,   497,   297,   473,   334,    96,   297,
     115,   340,   500,   296,   112,   172,   206,   119,   120,   121,
     348,   318,   491,   319,   339,    43,    58,   446,   342,   345,
     297,   124,   125,   126,    76,    59,   447,   448,    51,   383,
     237,   206,   119,   120,   121,   214,   259,    97,   429,   481,
     437,   442,   443,   296,   343,   447,   448,   384,   380,   207,
     208,   209,   491,   322,   492,    60,   526,   127,    44,   493,
     297,   255,    52,   296,   530,   494,   495,   349,   260,   421,
     474,   281,    55,   282,   207,   208,   209,    63,   565,  -270,
     297,   350,   496,   490,   476,   477,  -317,   497,   210,   390,
     304,   122,    66,   321,   492,   475,   322,   130,   296,   493,
     286,   156,   130,    70,   296,   494,   495,   123,   351,   563,
      71,   450,    73,   210,   425,   297,   122,   262,   528,    81,
     379,   297,   496,   561,   211,    82,    84,   497,   315,   316,
     317,   318,   123,   319,   296,   296,   525,   553,   212,   286,
     296,   424,   206,   119,   120,   121,   427,    88,    83,   211,
     472,   297,   297,   124,   125,   126,   478,   297,   564,   329,
     422,   376,   330,   212,   377,    85,   521,   483,   523,   524,
     487,    90,  -271,   183,    93,    94,   213,   214,   124,   125,
     126,   102,   103,   105,   215,   207,   208,   209,   106,   127,
     118,   206,   119,   120,   121,   489,   518,    76,   183,   322,
     139,   213,   214,   184,   185,   186,   187,   188,   189,   215,
     141,   145,   520,   532,   127,   334,   334,   544,   147,   549,
     545,   554,   322,   550,   210,   556,   322,   122,   334,   572,
     148,   150,   322,   119,   207,   208,   209,   153,   158,    77,
     163,   173,   121,   123,   165,   167,   529,   175,   168,   180,
     206,   119,   120,   121,   181,   182,   183,   199,   204,   570,
     211,   573,   235,   239,   242,   245,   248,   115,   264,   270,
     279,    16,   280,   210,   212,   283,   122,   284,   285,   292,
     320,   326,   206,   119,   120,   121,   323,   327,   328,   124,
     125,   126,   123,   289,   208,   209,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   331,   211,
     354,   334,   213,   214,   341,   346,   375,   374,   392,    76,
     215,   423,   395,   212,   403,   127,   208,   209,   298,   439,
     444,   470,   210,   445,   471,   122,   451,   452,   124,   125,
     126,   454,   455,   456,   465,   468,   296,   401,   482,   319,
     488,   123,   485,   504,   486,   506,   499,   509,   508,   510,
     511,   213,   214,   512,   210,   299,   513,   122,   290,   215,
     534,   514,   515,   535,   127,   527,   531,   533,   536,   537,
     538,   540,   212,   123,   541,   543,   546,   547,   548,   552,
     555,   560,   562,   104,   568,    75,   569,   124,   125,   126,
     290,   282,   576,   467,   426,   428,   247,   522,   203,   516,
     440,   381,   300,   438,   212,   325,   575,   558,   388,   337,
     213,   214,   557,   441,   162,   542,     0,     0,   215,   124,
     125,   126,   301,   127,     0,     0,     0,     0,   353,   302,
     303,     0,     0,     0,     0,     0,     0,   304,   305,     0,
       0,     0,   213,   214,     0,     0,  -319,     0,     0,     0,
     215,     0,     0,     1,     0,   127,     0,     0,     0,     0,
       0,     2,     0,   306,   307,   308,   309,   310,     3,     0,
     311,   312,     4,   313,   314,   315,   316,   317,   318,     0,
     319,     0,     0,     5,     0,     1,     6,     7,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,     8,     9,
       3,     0,     0,     0,     4,     0,     0,     0,     0,    10,
       0,     0,    11,     0,     0,     5,     0,     0,     6,     7,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   355,
       8,     9,     0,    12,     0,     0,    13,    14,     0,     0,
       0,    10,   356,     0,    11,     0,     0,   357,   358,   359,
     360,   361,    15,   362,     0,     0,     0,     0,    16,     0,
       0,   363,     0,     0,     0,    12,     0,     0,    13,    14,
       0,   299,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    15,     0,     0,   364,     0,     0,
      16,     0,   299,     0,     0,     0,     0,     0,     0,     0,
       0,    17,    18,    19,   365,     0,   366,   367,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   300,     0,
       0,   368,     0,   299,     0,   369,     0,   370,     0,     0,
       0,     0,   480,    17,    18,    19,     0,   371,   393,   300,
       0,   299,     0,     0,     0,     0,   303,     0,     0,     0,
       0,     0,     0,   304,   305,     0,     0,     0,     0,   393,
       0,     0,     0,     0,     0,     0,     0,   303,     0,     0,
    -320,   372,     0,     0,   304,   305,     0,     0,     0,   306,
     307,   308,   309,   310,     0,     0,   311,   312,     0,   313,
     314,   315,   316,   317,   318,     0,   319,     0,   303,     0,
     306,   307,   308,   309,   310,   304,  -320,   311,   312,     0,
     313,   314,   315,   316,   317,   318,   303,   319,     0,     0,
       0,     0,     0,   304,     0,     0,     0,     0,     0,     0,
       0,  -320,  -320,  -320,   309,   310,     0,     0,   311,   312,
       0,   313,   314,   315,   316,   317,   318,     0,   319,     0,
       0,     0,  -320,  -320,     0,     0,  -320,  -320,     0,   313,
     314,   315,   316,   317,   318,     0,   319
};

static const yytype_int16 yycheck[] =
{
     145,    77,     2,    96,    97,     5,    58,    59,    60,   211,
      10,   213,    12,    13,    97,   201,   106,    83,     3,   151,
       3,   116,   113,    51,     3,   116,     3,    58,   181,    61,
     175,    94,   177,   178,   292,     4,     5,     6,    12,     3,
       3,    48,    83,    27,    80,   101,   499,   136,    80,    92,
      50,    55,    52,   375,   147,     9,    18,    19,   115,   104,
      19,    61,   125,    27,   147,   210,   180,   115,   111,    73,
     215,   185,   128,   149,   117,   132,   121,    61,   110,    25,
       3,    88,    55,    38,   132,   538,    86,    87,   290,    26,
     179,    45,     9,   279,   239,    95,   298,    61,   300,    99,
     100,    60,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   183,   181,    88,
     104,    67,    77,   381,   446,   182,    72,    81,    45,    94,
     136,   284,    78,    79,   182,   104,   172,   121,   115,   215,
     285,   286,   115,   465,   185,   403,   468,   102,   125,    95,
     181,   296,   297,    99,   100,   132,   108,   185,    94,   132,
      77,   256,   125,   115,    81,   256,     3,     4,     5,     6,
      63,   177,    25,   179,   255,     3,    71,   130,    90,   260,
     132,   150,   151,   152,    58,    80,   158,   159,    94,   174,
      64,     3,     4,     5,     6,   174,   341,   133,   181,   401,
     332,   346,   347,   115,   116,   158,   159,   283,   182,    46,
      47,    48,    25,   185,    67,   110,   108,   186,     3,    72,
     132,   169,    98,   115,   482,    78,    79,   120,   176,   319,
      92,   181,    80,   183,    46,    47,    48,     3,   560,   185,
     132,   134,    95,   429,   389,   390,    99,   100,    85,   111,
     136,    88,   154,   182,    67,   117,   185,   323,   115,    72,
     111,   354,   328,     0,   115,    78,    79,   104,   161,    82,
     184,   354,   112,    85,   326,   132,    88,   114,   480,     3,
     280,   132,    95,   541,   121,   183,    94,   100,   174,   175,
     176,   177,   104,   179,   115,   115,   117,   117,   135,   111,
     115,   323,     3,     4,     5,     6,   328,    71,   181,   121,
     125,   132,   132,   150,   151,   152,   392,   132,   131,   182,
     320,   182,   185,   135,   185,   127,   471,   403,   473,   474,
     182,     3,   185,   185,   123,   127,   173,   174,   150,   151,
     152,   125,   185,    97,   181,    46,    47,    48,   124,   186,
       3,     3,     4,     5,     6,   182,   182,    58,   185,   185,
       4,   173,   174,   138,   139,   140,   141,   142,   143,   181,
     121,    83,   182,   182,   186,   185,   185,   182,    93,   182,
     185,   526,   185,   182,    85,   182,   185,    88,   185,   182,
     181,     3,   185,     4,    46,    47,    48,    46,     3,   181,
     181,   114,     6,   104,    12,   182,   482,   126,   182,     4,
       3,     4,     5,     6,     4,   182,   185,    46,     3,   564,
     121,   566,     3,   162,    91,   112,     3,    77,   118,     3,
     125,   112,   131,    85,   135,   181,    88,   181,   181,   179,
      98,    39,     3,     4,     5,     6,   181,    49,   181,   150,
     151,   152,   104,    46,    47,    48,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    94,   121,
      93,   185,   173,   174,   185,    55,   181,   120,   181,    58,
     181,     3,   182,   135,   181,   186,    47,    48,    17,     3,
     161,   182,    85,   120,    94,    88,   181,   181,   150,   151,
     152,   181,   181,   181,   181,   181,   115,   101,   181,   179,
       3,   104,   104,    70,   180,    63,   185,     6,   160,     6,
       6,   173,   174,     6,    85,    54,     6,    88,   121,   181,
      99,   120,   104,    78,   186,   182,   182,   182,    78,    78,
      99,     3,   135,   104,   126,   182,   182,   182,   182,   182,
     182,   181,     6,    71,   182,    25,   181,   150,   151,   152,
     121,   183,   182,   377,   327,   330,   157,   472,   143,   463,
     341,   281,   101,   334,   135,   240,   569,   534,   287,   254,
     173,   174,   533,   345,   103,   507,    -1,    -1,   181,   150,
     151,   152,   121,   186,    -1,    -1,    -1,    -1,   266,   128,
     129,    -1,    -1,    -1,    -1,    -1,    -1,   136,   137,    -1,
      -1,    -1,   173,   174,    -1,    -1,     0,    -1,    -1,    -1,
     181,    -1,    -1,     7,    -1,   186,    -1,    -1,    -1,    -1,
      -1,    15,    -1,   162,   163,   164,   165,   166,    22,    -1,
     169,   170,    26,   172,   173,   174,   175,   176,   177,    -1,
     179,    -1,    -1,    37,    -1,     7,    40,    41,    -1,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    52,    53,
      22,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    66,    -1,    -1,    37,    -1,    -1,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,
      52,    53,    -1,    87,    -1,    -1,    90,    91,    -1,    -1,
      -1,    63,    24,    -1,    66,    -1,    -1,    29,    30,    31,
      32,    33,   106,    35,    -1,    -1,    -1,    -1,   112,    -1,
      -1,    43,    -1,    -1,    -1,    87,    -1,    -1,    90,    91,
      -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   106,    -1,    -1,    69,    -1,    -1,
     112,    -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   155,   156,   157,    86,    -1,    88,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,
      -1,   103,    -1,    54,    -1,   107,    -1,   109,    -1,    -1,
      -1,    -1,   115,   155,   156,   157,    -1,   119,   121,   101,
      -1,    54,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    -1,   136,   137,    -1,    -1,    -1,    -1,   121,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,
     101,   153,    -1,    -1,   136,   137,    -1,    -1,    -1,   162,
     163,   164,   165,   166,    -1,    -1,   169,   170,    -1,   172,
     173,   174,   175,   176,   177,    -1,   179,    -1,   129,    -1,
     162,   163,   164,   165,   166,   136,   137,   169,   170,    -1,
     172,   173,   174,   175,   176,   177,   129,   179,    -1,    -1,
      -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   162,   163,   164,   165,   166,    -1,    -1,   169,   170,
      -1,   172,   173,   174,   175,   176,   177,    -1,   179,    -1,
      -1,    -1,   165,   166,    -1,    -1,   169,   170,    -1,   172,
     173,   174,   175,   176,   177,    -1,   179
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     7,    15,    22,    26,    37,    40,    41,    52,    53,
      63,    66,    87,    90,    91,   106,   112,   155,   156,   157,
     188,   189,   190,   191,   195,   197,   199,   200,   204,   205,
     206,   219,   221,   224,   225,   226,   228,   231,   304,   305,
      26,     3,   293,     3,     3,   293,    61,    80,   110,   208,
      94,    94,    98,   292,   293,    80,   293,   293,    71,    80,
     110,    19,    60,     3,   306,   307,   154,   196,   196,   196,
       0,   184,   311,   112,   192,   192,    58,   181,   234,   235,
     239,     3,   183,   181,    94,   127,   207,   207,    71,   293,
       3,   201,   293,   123,   127,   220,    94,   133,   220,   220,
     220,   293,   125,   185,   190,    97,   124,   251,   234,   235,
       9,    45,    81,   236,   237,    77,   236,   247,     3,     4,
       5,     6,    88,   104,   150,   151,   152,   186,   254,   255,
     278,   279,   280,   281,   282,   283,   284,   285,   286,     4,
     198,   121,   293,   293,   207,    83,   244,    93,   181,   227,
       3,   229,   230,    46,   293,   202,   279,   202,     3,   293,
     293,   234,   307,   181,   282,    12,   240,   182,   182,   232,
     233,   234,   239,   114,   238,   126,   232,    55,    73,   252,
       4,     4,   182,   185,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   271,   272,   273,    46,
      94,   125,   181,   227,     3,   294,     3,    46,    47,    48,
      85,   121,   135,   173,   174,   181,   257,   258,   259,   260,
     261,   262,   263,   264,   266,   267,   268,   269,   270,   274,
     275,   276,   277,   278,   202,     3,   312,    64,   235,   162,
     185,   244,    91,   222,   223,   112,   203,   203,     3,   193,
     194,   241,   253,   256,   257,   247,   236,   248,   249,   257,
     247,   257,   114,   257,   118,   299,   300,   301,   271,   278,
       3,   231,     3,    27,    61,   209,   210,   211,   218,   125,
     131,   181,   183,   181,   181,   181,   111,   257,   265,    46,
     121,   258,   179,   258,   235,   257,   115,   132,    17,    54,
     101,   121,   128,   129,   136,   137,   162,   163,   164,   165,
     166,   169,   170,   172,   173,   174,   175,   176,   177,   179,
      98,   182,   185,   181,   257,   230,    39,    49,   181,   182,
     185,    94,   242,   243,   185,     3,   125,   297,   298,   252,
     232,   185,    90,   116,   250,   252,    55,    55,    63,   120,
     134,   161,   302,   301,    93,    11,    24,    29,    30,    31,
      32,    33,    35,    43,    69,    86,    88,    89,   103,   107,
     109,   119,   153,   212,   120,   181,   182,   185,   231,   293,
     182,   240,     3,   174,   235,   271,   257,   257,   265,    92,
     111,   117,   181,   121,   253,   182,   182,   257,   257,   258,
     258,   101,   128,   181,   104,   121,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   282,   293,     3,   255,   220,   201,   255,   194,   181,
     287,   288,   289,   290,   291,   293,   308,   244,   256,     3,
     249,   299,   257,   257,   161,   120,   130,   158,   159,   303,
     202,   181,   181,   214,   181,   181,   181,   213,    27,    61,
     104,   121,   215,   216,   217,   181,   312,   210,   181,   253,
     182,    94,   125,   108,    92,   117,   257,   257,   235,   180,
     115,   258,   181,   235,   253,   104,   180,   182,     3,   182,
     231,    25,    67,    72,    78,    79,    95,   100,   309,   185,
     125,   295,   296,   297,    70,   245,    63,   312,   160,     6,
       6,     6,     6,     6,   120,   104,   217,   312,   182,   312,
     182,   257,   212,   257,   257,   117,   108,   182,   258,   235,
     253,   182,   182,   182,    99,    78,    78,    78,    99,   288,
       3,   126,   303,   182,   182,   185,   182,   182,   182,   182,
     182,   182,   182,   117,   257,   182,   182,   296,   289,   288,
     181,   253,     6,    82,   131,   312,    51,   246,   182,   181,
     257,   310,   182,   257,     3,   277,   182
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   187,   188,   189,   189,   190,   190,   190,   190,   190,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     192,   192,   193,   193,   194,   194,   195,   195,   195,   196,
     196,   197,   198,   199,   199,   200,   200,   201,   202,   203,
     203,   204,   205,   205,   205,   205,   206,   206,   206,   206,
     206,   207,   207,   208,   208,   209,   209,   210,   210,   211,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   213,   213,
     214,   214,   214,   215,   215,   216,   216,   217,   217,   217,
     217,   218,   218,   219,   219,   219,   219,   220,   220,   221,
     222,   223,   224,   225,   226,   226,   227,   227,   228,   229,
     229,   230,   231,   231,   231,   232,   232,   233,   233,   234,
     234,   235,   235,   236,   237,   237,   237,   238,   238,   239,
     240,   240,   241,   242,   242,   243,   244,   244,   245,   245,
     246,   246,   247,   247,   248,   248,   249,   250,   250,   250,
     251,   251,   252,   252,   252,   252,   252,   252,   253,   253,
     254,   254,   255,   255,   256,   257,   257,   257,   257,   257,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   259,   259,   260,   260,   260,   260,   260,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   262,
     262,   263,   263,   263,   263,   264,   264,   264,   264,   265,
     265,   266,   266,   267,   267,   267,   267,   267,   267,   267,
     268,   268,   269,   270,   271,   271,   271,   271,   271,   271,
     272,   272,   272,   272,   272,   272,   273,   273,   274,   275,
     276,   277,   277,   277,   277,   278,   278,   278,   278,   278,
     278,   278,   279,   280,   280,   281,   281,   282,   283,   284,
     285,   285,   285,   286,   287,   287,   288,   288,   289,   289,
     290,   290,   291,   292,   293,   293,   294,   294,   295,   295,
     296,   296,   297,   297,   298,   298,   299,   299,   300,   300,
     301,   301,   302,   302,   302,   302,   303,   303,   303,   304,
     304,   305,   306,   306,   307,   308,   308,   308,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   310,   311,
     311,   312,   312
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     0,     1,     3,     1,     4,     2,     2,     2,     1,
       0,     4,     1,     2,     5,     7,     5,     1,     1,     3,
       0,     5,     2,     3,     2,     2,     8,     7,     6,    10,
       7,     3,     0,     1,     0,     1,     3,     1,     1,     3,
       1,     1,     4,     4,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     4,     3,     0,
       5,     3,     0,     1,     0,     1,     2,     2,     1,     1,
       2,     5,     4,     4,     4,     3,     4,     2,     0,     5,
       1,     4,     4,     2,     8,     5,     3,     0,     5,     1,
       3,     3,     2,     2,     6,     1,     1,     1,     3,     3,
       3,     4,     6,     2,     1,     1,     1,     1,     0,     7,
       1,     0,     1,     1,     0,     2,     2,     0,     4,     0,
       2,     0,     3,     0,     1,     3,     2,     1,     1,     0,
       2,     0,     2,     2,     4,     2,     4,     0,     1,     3,
       1,     0,     1,     3,     2,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     2,     2,     2,     3,     4,     1,     3,
       3,     3,     3,     3,     3,     3,     4,     3,     3,     3,
       3,     5,     6,     5,     6,     4,     6,     3,     5,     4,
       5,     4,     5,     3,     3,     3,     3,     3,     3,     3,
       3,     5,     6,     6,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       5,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     3,     2,     1,     1,     3,     1,     1,     1,     4,
       1,     3,     2,     1,     1,     3,     1,     0,     1,     5,
       1,     0,     2,     1,     1,     0,     1,     0,     1,     2,
       3,     5,     1,     3,     1,     2,     2,     1,     0,     1,
       0,     2,     1,     3,     3,     4,     6,     8,     1,     2,
       1,     2,     1,     2,     1,     1,     1,     0,     1,     1,
       0,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = SQL_HSQL_EMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == SQL_HSQL_EMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (&yylloc, result, scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use SQL_HSQL_error or SQL_HSQL_UNDEF. */
#define YYERRCODE SQL_HSQL_UNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if HSQL_DEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined HSQL_LTYPE_IS_TRIVIAL && HSQL_LTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, result, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, hsql::SQLParserResult* result, yyscan_t scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (result);
  YY_USE (scanner);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, hsql::SQLParserResult* result, yyscan_t scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, result, scanner);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, hsql::SQLParserResult* result, yyscan_t scanner)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), result, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, result, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !HSQL_DEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !HSQL_DEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, hsql::SQLParserResult* result, yyscan_t scanner)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (result);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_IDENTIFIER: /* IDENTIFIER  */
#line 168 "bison_parser.y"
                { free( (((*yyvaluep).sval)) ); }
#line 2047 "bison_parser.cpp"
        break;

    case YYSYMBOL_STRING: /* STRING  */
#line 168 "bison_parser.y"
                { free( (((*yyvaluep).sval)) ); }
#line 2053 "bison_parser.cpp"
        break;

    case YYSYMBOL_FLOATVAL: /* FLOATVAL  */
#line 166 "bison_parser.y"
                { }
#line 2059 "bison_parser.cpp"
        break;

    case YYSYMBOL_INTVAL: /* INTVAL  */
#line 166 "bison_parser.y"
                { }
#line 2065 "bison_parser.cpp"
        break;

    case YYSYMBOL_statement_list: /* statement_list  */
#line 169 "bison_parser.y"
                {
      if ((((*yyvaluep).stmt_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).stmt_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).stmt_vec));
    }
#line 2078 "bison_parser.cpp"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).statement)); }
#line 2084 "bison_parser.cpp"
        break;

    case YYSYMBOL_preparable_statement: /* preparable_statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).statement)); }
#line 2090 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_hints: /* opt_hints  */
#line 169 "bison_parser.y"
                {
      if ((((*yyvaluep).expr_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).expr_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).expr_vec));
    }
#line 2103 "bison_parser.cpp"
        break;

    case YYSYMBOL_hint_list: /* hint_list  */
#line 169 "bison_parser.y"
                {
      if ((((*yyvaluep).expr_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).expr_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).expr_vec));
    }
#line 2116 "bison_parser.cpp"
        break;

    case YYSYMBOL_hint: /* hint  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2122 "bison_parser.cpp"
        break;

    case YYSYMBOL_transaction_statement: /* transaction_statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).transaction_stmt)); }
#line 2128 "bison_parser.cpp"
        break;

    case YYSYMBOL_prepare_statement: /* prepare_statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).prep_stmt)); }
#line 2134 "bison_parser.cpp"
        break;

    case YYSYMBOL_prepare_target_query: /* prepare_target_query  */
#line 168 "bison_parser.y"
                { free( (((*yyvaluep).sval)) ); }
#line 2140 "bison_parser.cpp"
        break;

    case YYSYMBOL_execute_statement: /* execute_statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).exec_stmt)); }
#line 2146 "bison_parser.cpp"
        break;

    case YYSYMBOL_import_statement: /* import_statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).import_stmt)); }
#line 2152 "bison_parser.cpp"
        break;

    case YYSYMBOL_file_type: /* file_type  */
#line 166 "bison_parser.y"
                { }
#line 2158 "bison_parser.cpp"
        break;

    case YYSYMBOL_file_path: /* file_path  */
#line 168 "bison_parser.y"
                { free( (((*yyvaluep).sval)) ); }
#line 2164 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_file_type: /* opt_file_type  */
#line 166 "bison_parser.y"
                { }
#line 2170 "bison_parser.cpp"
        break;

    case YYSYMBOL_export_statement: /* export_statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).export_stmt)); }
#line 2176 "bison_parser.cpp"
        break;

    case YYSYMBOL_show_statement: /* show_statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).show_stmt)); }
#line 2182 "bison_parser.cpp"
        break;

    case YYSYMBOL_create_statement: /* create_statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).create_stmt)); }
#line 2188 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_not_exists: /* opt_not_exists  */
#line 166 "bison_parser.y"
                { }
#line 2194 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_unique: /* opt_unique  */
#line 166 "bison_parser.y"
                { }
#line 2200 "bison_parser.cpp"
        break;

    case YYSYMBOL_table_elem_commalist: /* table_elem_commalist  */
#line 169 "bison_parser.y"
                {
      if ((((*yyvaluep).table_element_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).table_element_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).table_element_vec));
    }
#line 2213 "bison_parser.cpp"
        break;

    case YYSYMBOL_table_elem: /* table_elem  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).table_element_t)); }
#line 2219 "bison_parser.cpp"
        break;

    case YYSYMBOL_column_def: /* column_def  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).column_t)); }
#line 2225 "bison_parser.cpp"
        break;

    case YYSYMBOL_column_type: /* column_type  */
#line 166 "bison_parser.y"
                { }
#line 2231 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_time_precision: /* opt_time_precision  */
#line 166 "bison_parser.y"
                { }
#line 2237 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_decimal_specification: /* opt_decimal_specification  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).ival_pair)); }
#line 2243 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_column_constraints: /* opt_column_constraints  */
#line 166 "bison_parser.y"
                { }
#line 2249 "bison_parser.cpp"
        break;

    case YYSYMBOL_column_constraint_set: /* column_constraint_set  */
#line 166 "bison_parser.y"
                { }
#line 2255 "bison_parser.cpp"
        break;

    case YYSYMBOL_column_constraint: /* column_constraint  */
#line 166 "bison_parser.y"
                { }
#line 2261 "bison_parser.cpp"
        break;

    case YYSYMBOL_table_constraint: /* table_constraint  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).table_constraint_t)); }
#line 2267 "bison_parser.cpp"
        break;

    case YYSYMBOL_drop_statement: /* drop_statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).drop_stmt)); }
#line 2273 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_exists: /* opt_exists  */
#line 166 "bison_parser.y"
                { }
#line 2279 "bison_parser.cpp"
        break;

    case YYSYMBOL_alter_statement: /* alter_statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).alter_stmt)); }
#line 2285 "bison_parser.cpp"
        break;

    case YYSYMBOL_alter_action: /* alter_action  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).alter_action_t)); }
#line 2291 "bison_parser.cpp"
        break;

    case YYSYMBOL_drop_action: /* drop_action  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).drop_action_t)); }
#line 2297 "bison_parser.cpp"
        break;

    case YYSYMBOL_delete_statement: /* delete_statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).delete_stmt)); }
#line 2303 "bison_parser.cpp"
        break;

    case YYSYMBOL_truncate_statement: /* truncate_statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).delete_stmt)); }
#line 2309 "bison_parser.cpp"
        break;

    case YYSYMBOL_insert_statement: /* insert_statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).insert_stmt)); }
#line 2315 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_column_list: /* opt_column_list  */
#line 169 "bison_parser.y"
                {
      if ((((*yyvaluep).str_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).str_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).str_vec));
    }
#line 2328 "bison_parser.cpp"
        break;

    case YYSYMBOL_update_statement: /* update_statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).update_stmt)); }
#line 2334 "bison_parser.cpp"
        break;

    case YYSYMBOL_update_clause_commalist: /* update_clause_commalist  */
#line 169 "bison_parser.y"
                {
      if ((((*yyvaluep).update_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).update_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).update_vec));
    }
#line 2347 "bison_parser.cpp"
        break;

    case YYSYMBOL_update_clause: /* update_clause  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).update_t)); }
#line 2353 "bison_parser.cpp"
        break;

    case YYSYMBOL_select_statement: /* select_statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2359 "bison_parser.cpp"
        break;

    case YYSYMBOL_select_within_set_operation: /* select_within_set_operation  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2365 "bison_parser.cpp"
        break;

    case YYSYMBOL_select_within_set_operation_no_parentheses: /* select_within_set_operation_no_parentheses  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2371 "bison_parser.cpp"
        break;

    case YYSYMBOL_select_with_paren: /* select_with_paren  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2377 "bison_parser.cpp"
        break;

    case YYSYMBOL_select_no_paren: /* select_no_paren  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2383 "bison_parser.cpp"
        break;

    case YYSYMBOL_set_operator: /* set_operator  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).set_operator_t)); }
#line 2389 "bison_parser.cpp"
        break;

    case YYSYMBOL_set_type: /* set_type  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).set_operator_t)); }
#line 2395 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_all: /* opt_all  */
#line 166 "bison_parser.y"
                { }
#line 2401 "bison_parser.cpp"
        break;

    case YYSYMBOL_select_clause: /* select_clause  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2407 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_distinct: /* opt_distinct  */
#line 166 "bison_parser.y"
                { }
#line 2413 "bison_parser.cpp"
        break;

    case YYSYMBOL_select_list: /* select_list  */
#line 169 "bison_parser.y"
                {
      if ((((*yyvaluep).expr_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).expr_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).expr_vec));
    }
#line 2426 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_from_clause: /* opt_from_clause  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2432 "bison_parser.cpp"
        break;

    case YYSYMBOL_from_clause: /* from_clause  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2438 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_where: /* opt_where  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2444 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_group: /* opt_group  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).group_t)); }
#line 2450 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_having: /* opt_having  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2456 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_order: /* opt_order  */
#line 169 "bison_parser.y"
                {
      if ((((*yyvaluep).order_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).order_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).order_vec));
    }
#line 2469 "bison_parser.cpp"
        break;

    case YYSYMBOL_order_list: /* order_list  */
#line 169 "bison_parser.y"
                {
      if ((((*yyvaluep).order_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).order_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).order_vec));
    }
#line 2482 "bison_parser.cpp"
        break;

    case YYSYMBOL_order_desc: /* order_desc  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).order)); }
#line 2488 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_order_type: /* opt_order_type  */
#line 166 "bison_parser.y"
                { }
#line 2494 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_top: /* opt_top  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).limit)); }
#line 2500 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_limit: /* opt_limit  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).limit)); }
#line 2506 "bison_parser.cpp"
        break;

    case YYSYMBOL_expr_list: /* expr_list  */
#line 169 "bison_parser.y"
                {
      if ((((*yyvaluep).expr_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).expr_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).expr_vec));
    }
#line 2519 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_literal_list: /* opt_literal_list  */
#line 169 "bison_parser.y"
                {
      if ((((*yyvaluep).expr_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).expr_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).expr_vec));
    }
#line 2532 "bison_parser.cpp"
        break;

    case YYSYMBOL_literal_list: /* literal_list  */
#line 169 "bison_parser.y"
                {
      if ((((*yyvaluep).expr_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).expr_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).expr_vec));
    }
#line 2545 "bison_parser.cpp"
        break;

    case YYSYMBOL_expr_alias: /* expr_alias  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2551 "bison_parser.cpp"
        break;

    case YYSYMBOL_expr: /* expr  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2557 "bison_parser.cpp"
        break;

    case YYSYMBOL_operand: /* operand  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2563 "bison_parser.cpp"
        break;

    case YYSYMBOL_scalar_expr: /* scalar_expr  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2569 "bison_parser.cpp"
        break;

    case YYSYMBOL_unary_expr: /* unary_expr  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2575 "bison_parser.cpp"
        break;

    case YYSYMBOL_binary_expr: /* binary_expr  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2581 "bison_parser.cpp"
        break;

    case YYSYMBOL_logic_expr: /* logic_expr  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2587 "bison_parser.cpp"
        break;

    case YYSYMBOL_in_expr: /* in_expr  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2593 "bison_parser.cpp"
        break;

    case YYSYMBOL_case_expr: /* case_expr  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2599 "bison_parser.cpp"
        break;

    case YYSYMBOL_case_list: /* case_list  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2605 "bison_parser.cpp"
        break;

    case YYSYMBOL_exists_expr: /* exists_expr  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2611 "bison_parser.cpp"
        break;

    case YYSYMBOL_comp_expr: /* comp_expr  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2617 "bison_parser.cpp"
        break;

    case YYSYMBOL_function_expr: /* function_expr  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2623 "bison_parser.cpp"
        break;

    case YYSYMBOL_extract_expr: /* extract_expr  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2629 "bison_parser.cpp"
        break;

    case YYSYMBOL_cast_expr: /* cast_expr  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2635 "bison_parser.cpp"
        break;

    case YYSYMBOL_datetime_field: /* datetime_field  */
#line 166 "bison_parser.y"
                { }
#line 2641 "bison_parser.cpp"
        break;

    case YYSYMBOL_datetime_field_plural: /* datetime_field_plural  */
#line 166 "bison_parser.y"
                { }
#line 2647 "bison_parser.cpp"
        break;

    case YYSYMBOL_duration_field: /* duration_field  */
#line 166 "bison_parser.y"
                { }
#line 2653 "bison_parser.cpp"
        break;

    case YYSYMBOL_array_expr: /* array_expr  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2659 "bison_parser.cpp"
        break;

    case YYSYMBOL_array_index: /* array_index  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2665 "bison_parser.cpp"
        break;

    case YYSYMBOL_between_expr: /* between_expr  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2671 "bison_parser.cpp"
        break;

    case YYSYMBOL_column_name: /* column_name  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2677 "bison_parser.cpp"
        break;

    case YYSYMBOL_literal: /* literal  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2683 "bison_parser.cpp"
        break;

    case YYSYMBOL_string_literal: /* string_literal  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2689 "bison_parser.cpp"
        break;

    case YYSYMBOL_bool_literal: /* bool_literal  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2695 "bison_parser.cpp"
        break;

    case YYSYMBOL_num_literal: /* num_literal  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2701 "bison_parser.cpp"
        break;

    case YYSYMBOL_int_literal: /* int_literal  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2707 "bison_parser.cpp"
        break;

    case YYSYMBOL_null_literal: /* null_literal  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2713 "bison_parser.cpp"
        break;

    case YYSYMBOL_date_literal: /* date_literal  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2719 "bison_parser.cpp"
        break;

    case YYSYMBOL_interval_literal: /* interval_literal  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2725 "bison_parser.cpp"
        break;

    case YYSYMBOL_param_expr: /* param_expr  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2731 "bison_parser.cpp"
        break;

    case YYSYMBOL_table_ref: /* table_ref  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2737 "bison_parser.cpp"
        break;

    case YYSYMBOL_table_ref_atomic: /* table_ref_atomic  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2743 "bison_parser.cpp"
        break;

    case YYSYMBOL_nonjoin_table_ref_atomic: /* nonjoin_table_ref_atomic  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2749 "bison_parser.cpp"
        break;

    case YYSYMBOL_table_ref_commalist: /* table_ref_commalist  */
#line 169 "bison_parser.y"
                {
      if ((((*yyvaluep).table_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).table_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).table_vec));
    }
#line 2762 "bison_parser.cpp"
        break;

    case YYSYMBOL_table_ref_name: /* table_ref_name  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2768 "bison_parser.cpp"
        break;

    case YYSYMBOL_table_ref_name_no_alias: /* table_ref_name_no_alias  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2774 "bison_parser.cpp"
        break;

    case YYSYMBOL_table_name: /* table_name  */
#line 167 "bison_parser.y"
                { free( (((*yyvaluep).table_name).name) ); free( (((*yyvaluep).table_name).schema) ); }
#line 2780 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_index_name: /* opt_index_name  */
#line 168 "bison_parser.y"
                { free( (((*yyvaluep).sval)) ); }
#line 2786 "bison_parser.cpp"
        break;

    case YYSYMBOL_table_alias: /* table_alias  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).alias_t)); }
#line 2792 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_table_alias: /* opt_table_alias  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).alias_t)); }
#line 2798 "bison_parser.cpp"
        break;

    case YYSYMBOL_alias: /* alias  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).alias_t)); }
#line 2804 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_alias: /* opt_alias  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).alias_t)); }
#line 2810 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_locking_clause: /* opt_locking_clause  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).locking_clause_vec)); }
#line 2816 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_locking_clause_list: /* opt_locking_clause_list  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).locking_clause_vec)); }
#line 2822 "bison_parser.cpp"
        break;

    case YYSYMBOL_locking_clause: /* locking_clause  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).locking_t)); }
#line 2828 "bison_parser.cpp"
        break;

    case YYSYMBOL_row_lock_mode: /* row_lock_mode  */
#line 166 "bison_parser.y"
                { }
#line 2834 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_row_lock_policy: /* opt_row_lock_policy  */
#line 166 "bison_parser.y"
                { }
#line 2840 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_with_clause: /* opt_with_clause  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).with_description_vec)); }
#line 2846 "bison_parser.cpp"
        break;

    case YYSYMBOL_with_clause: /* with_clause  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).with_description_vec)); }
#line 2852 "bison_parser.cpp"
        break;

    case YYSYMBOL_with_description_list: /* with_description_list  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).with_description_vec)); }
#line 2858 "bison_parser.cpp"
        break;

    case YYSYMBOL_with_description: /* with_description  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).with_description_t)); }
#line 2864 "bison_parser.cpp"
        break;

    case YYSYMBOL_join_clause: /* join_clause  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2870 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_join_type: /* opt_join_type  */
#line 166 "bison_parser.y"
                { }
#line 2876 "bison_parser.cpp"
        break;

    case YYSYMBOL_join_condition: /* join_condition  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2882 "bison_parser.cpp"
        break;

    case YYSYMBOL_ident_commalist: /* ident_commalist  */
#line 169 "bison_parser.y"
                {
      if ((((*yyvaluep).str_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).str_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).str_vec));
    }
#line 2895 "bison_parser.cpp"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (hsql::SQLParserResult* result, yyscan_t scanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined HSQL_LTYPE_IS_TRIVIAL && HSQL_LTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = SQL_HSQL_EMPTY; /* Cause a token to be read.  */


/* User initialization code.  */
#line 77 "bison_parser.y"
{
  // Initialize
  yylloc.first_column = 0;
  yylloc.last_column = 0;
  yylloc.first_line = 0;
  yylloc.last_line = 0;
  yylloc.total_column = 0;
  yylloc.string_length = 0;
}

#line 3003 "bison_parser.cpp"

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == SQL_HSQL_EMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, &yylloc, scanner);
    }

  if (yychar <= SQL_YYEOF)
    {
      yychar = SQL_YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == SQL_HSQL_error)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = SQL_HSQL_UNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = SQL_HSQL_EMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* input: statement_list opt_semicolon  */
#line 304 "bison_parser.y"
                                     {
  for (SQLStatement* stmt : *(yyvsp[-1].stmt_vec)) {
    // Transfers ownership of the statement.
    result->addStatement(stmt);
  }

  unsigned param_id = 0;
  for (void* param : yyloc.param_list) {
    if (param != nullptr) {
      Expr* expr = (Expr*)param;
      expr->ival = param_id;
      result->addParameter(expr);
      ++param_id;
    }
  }
    delete (yyvsp[-1].stmt_vec);
  }
#line 3232 "bison_parser.cpp"
    break;

  case 3: /* statement_list: statement  */
#line 323 "bison_parser.y"
                           {
  (yyvsp[0].statement)->stringLength = yylloc.string_length;
  yylloc.string_length = 0;
  (yyval.stmt_vec) = new std::vector<SQLStatement*>();
  (yyval.stmt_vec)->push_back((yyvsp[0].statement));
}
#line 3243 "bison_parser.cpp"
    break;

  case 4: /* statement_list: statement_list ';' statement  */
#line 329 "bison_parser.y"
                               {
  (yyvsp[0].statement)->stringLength = yylloc.string_length;
  yylloc.string_length = 0;
  (yyvsp[-2].stmt_vec)->push_back((yyvsp[0].statement));
  (yyval.stmt_vec) = (yyvsp[-2].stmt_vec);
}
#line 3254 "bison_parser.cpp"
    break;

  case 5: /* statement: prepare_statement opt_hints  */
#line 336 "bison_parser.y"
                                        {
  (yyval.statement) = (yyvsp[-1].prep_stmt);
  (yyval.statement)->hints = (yyvsp[0].expr_vec);
}
#line 3263 "bison_parser.cpp"
    break;

  case 6: /* statement: preparable_statement opt_hints  */
#line 340 "bison_parser.y"
                                 {
  (yyval.statement) = (yyvsp[-1].statement);
  (yyval.statement)->hints = (yyvsp[0].expr_vec);
}
#line 3272 "bison_parser.cpp"
    break;

  case 7: /* statement: show_statement  */
#line 344 "bison_parser.y"
                 { (yyval.statement) = (yyvsp[0].show_stmt); }
#line 3278 "bison_parser.cpp"
    break;

  case 8: /* statement: import_statement  */
#line 345 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].import_stmt); }
#line 3284 "bison_parser.cpp"
    break;

  case 9: /* statement: export_statement  */
#line 346 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].export_stmt); }
#line 3290 "bison_parser.cpp"
    break;

  case 10: /* preparable_statement: select_statement  */
#line 348 "bison_parser.y"
                                        { (yyval.statement) = (yyvsp[0].select_stmt); }
#line 3296 "bison_parser.cpp"
    break;

  case 11: /* preparable_statement: create_statement  */
#line 349 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].create_stmt); }
#line 3302 "bison_parser.cpp"
    break;

  case 12: /* preparable_statement: insert_statement  */
#line 350 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].insert_stmt); }
#line 3308 "bison_parser.cpp"
    break;

  case 13: /* preparable_statement: delete_statement  */
#line 351 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].delete_stmt); }
#line 3314 "bison_parser.cpp"
    break;

  case 14: /* preparable_statement: truncate_statement  */
#line 352 "bison_parser.y"
                     { (yyval.statement) = (yyvsp[0].delete_stmt); }
#line 3320 "bison_parser.cpp"
    break;

  case 15: /* preparable_statement: update_statement  */
#line 353 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].update_stmt); }
#line 3326 "bison_parser.cpp"
    break;

  case 16: /* preparable_statement: drop_statement  */
#line 354 "bison_parser.y"
                 { (yyval.statement) = (yyvsp[0].drop_stmt); }
#line 3332 "bison_parser.cpp"
    break;

  case 17: /* preparable_statement: alter_statement  */
#line 355 "bison_parser.y"
                  { (yyval.statement) = (yyvsp[0].alter_stmt); }
#line 3338 "bison_parser.cpp"
    break;

  case 18: /* preparable_statement: execute_statement  */
#line 356 "bison_parser.y"
                    { (yyval.statement) = (yyvsp[0].exec_stmt); }
#line 3344 "bison_parser.cpp"
    break;

  case 19: /* preparable_statement: transaction_statement  */
#line 357 "bison_parser.y"
                        { (yyval.statement) = (yyvsp[0].transaction_stmt); }
#line 3350 "bison_parser.cpp"
    break;

  case 20: /* opt_hints: WITH HINT '(' hint_list ')'  */
#line 363 "bison_parser.y"
                                        { (yyval.expr_vec) = (yyvsp[-1].expr_vec); }
#line 3356 "bison_parser.cpp"
    break;

  case 21: /* opt_hints: %empty  */
#line 364 "bison_parser.y"
              { (yyval.expr_vec) = nullptr; }
#line 3362 "bison_parser.cpp"
    break;

  case 22: /* hint_list: hint  */
#line 366 "bison_parser.y"
                 {
  (yyval.expr_vec) = new std::vector<Expr*>();
  (yyval.expr_vec)->push_back((yyvsp[0].expr));
}
#line 3371 "bison_parser.cpp"
    break;

  case 23: /* hint_list: hint_list ',' hint  */
#line 370 "bison_parser.y"
                     {
  (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr));
  (yyval.expr_vec) = (yyvsp[-2].expr_vec);
}
#line 3380 "bison_parser.cpp"
    break;

  case 24: /* hint: IDENTIFIER  */
#line 375 "bison_parser.y"
                  {
  (yyval.expr) = Expr::make(kExprHint);
  (yyval.expr)->name = (yyvsp[0].sval);
}
#line 3389 "bison_parser.cpp"
    break;

  case 25: /* hint: IDENTIFIER '(' literal_list ')'  */
#line 379 "bison_parser.y"
                                  {
  (yyval.expr) = Expr::make(kExprHint);
  (yyval.expr)->name = (yyvsp[-3].sval);
  (yyval.expr)->exprList = (yyvsp[-1].expr_vec);
}
#line 3399 "bison_parser.cpp"
    break;

  case 26: /* transaction_statement: BEGIN opt_transaction_keyword  */
#line 389 "bison_parser.y"
                                                      { (yyval.transaction_stmt) = new TransactionStatement(kBeginTransaction); }
#line 3405 "bison_parser.cpp"
    break;

  case 27: /* transaction_statement: ROLLBACK opt_transaction_keyword  */
#line 390 "bison_parser.y"
                                   { (yyval.transaction_stmt) = new TransactionStatement(kRollbackTransaction); }
#line 3411 "bison_parser.cpp"
    break;

  case 28: /* transaction_statement: COMMIT opt_transaction_keyword  */
#line 391 "bison_parser.y"
                                 { (yyval.transaction_stmt) = new TransactionStatement(kCommitTransaction); }
#line 3417 "bison_parser.cpp"
    break;

  case 31: /* prepare_statement: PREPARE IDENTIFIER FROM prepare_target_query  */
#line 399 "bison_parser.y"
                                                                 {
  (yyval.prep_stmt) = new PrepareStatement();
  (yyval.prep_stmt)->name = (yyvsp[-2].sval);
  (yyval.prep_stmt)->query = (yyvsp[0].sval);
}
#line 3427 "bison_parser.cpp"
    break;

  case 33: /* execute_statement: EXECUTE IDENTIFIER  */
#line 407 "bison_parser.y"
                                                                  {
  (yyval.exec_stmt) = new ExecuteStatement();
  (yyval.exec_stmt)->name = (yyvsp[0].sval);
}
#line 3436 "bison_parser.cpp"
    break;

  case 34: /* execute_statement: EXECUTE IDENTIFIER '(' opt_literal_list ')'  */
#line 411 "bison_parser.y"
                                              {
  (yyval.exec_stmt) = new ExecuteStatement();
  (yyval.exec_stmt)->name = (yyvsp[-3].sval);
  (yyval.exec_stmt)->parameters = (yyvsp[-1].expr_vec);
}
#line 3446 "bison_parser.cpp"
    break;

  case 35: /* import_statement: IMPORT FROM file_type FILE file_path INTO table_name  */
#line 422 "bison_parser.y"
                                                                        {
  (yyval.import_stmt) = new ImportStatement((yyvsp[-4].import_type_t));
  (yyval.import_stmt)->filePath = (yyvsp[-2].sval);
  (yyval.import_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.import_stmt)->tableName = (yyvsp[0].table_name).name;
}
#line 3457 "bison_parser.cpp"
    break;

  case 36: /* import_statement: COPY table_name FROM file_path opt_file_type  */
#line 428 "bison_parser.y"
                                               {
  (yyval.import_stmt) = new ImportStatement((yyvsp[0].import_type_t));
  (yyval.import_stmt)->filePath = (yyvsp[-1].sval);
  (yyval.import_stmt)->schema = (yyvsp[-3].table_name).schema;
  (yyval.import_stmt)->tableName = (yyvsp[-3].table_name).name;
}
#line 3468 "bison_parser.cpp"
    break;

  case 37: /* file_type: IDENTIFIER  */
#line 435 "bison_parser.y"
                       {
  if (strcasecmp((yyvsp[0].sval), "csv") == 0) {
    (yyval.import_type_t) = kImportCSV;
  } else if (strcasecmp((yyvsp[0].sval), "tbl") == 0) {
    (yyval.import_type_t) = kImportTbl;
  } else if (strcasecmp((yyvsp[0].sval), "binary") == 0 || strcasecmp((yyvsp[0].sval), "bin") == 0) {
    (yyval.import_type_t) = kImportBinary;
  } else {
    free((yyvsp[0].sval));
    yyerror(&yyloc, result, scanner, "File type is unknown.");
    YYERROR;
  }
  free((yyvsp[0].sval));
}
#line 3487 "bison_parser.cpp"
    break;

  case 38: /* file_path: string_literal  */
#line 450 "bison_parser.y"
                           {
  (yyval.sval) = strdup((yyvsp[0].expr)->name);
  delete (yyvsp[0].expr);
}
#line 3496 "bison_parser.cpp"
    break;

  case 39: /* opt_file_type: WITH FORMAT file_type  */
#line 455 "bison_parser.y"
                                      { (yyval.import_type_t) = (yyvsp[0].import_type_t); }
#line 3502 "bison_parser.cpp"
    break;

  case 40: /* opt_file_type: %empty  */
#line 456 "bison_parser.y"
              { (yyval.import_type_t) = kImportAuto; }
#line 3508 "bison_parser.cpp"
    break;

  case 41: /* export_statement: COPY table_name TO file_path opt_file_type  */
#line 462 "bison_parser.y"
                                                              {
  (yyval.export_stmt) = new ExportStatement((yyvsp[0].import_type_t));
  (yyval.export_stmt)->filePath = (yyvsp[-1].sval);
  (yyval.export_stmt)->schema = (yyvsp[-3].table_name).schema;
  (yyval.export_stmt)->tableName = (yyvsp[-3].table_name).name;
}
#line 3519 "bison_parser.cpp"
    break;

  case 42: /* show_statement: SHOW TABLES  */
#line 474 "bison_parser.y"
                             { (yyval.show_stmt) = new ShowStatement(kShowTables); }
#line 3525 "bison_parser.cpp"
    break;

  case 43: /* show_statement: SHOW COLUMNS table_name  */
#line 475 "bison_parser.y"
                          {
  (yyval.show_stmt) = new ShowStatement(kShowColumns);
  (yyval.show_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.show_stmt)->name = (yyvsp[0].table_name).name;
}
#line 3535 "bison_parser.cpp"
    break;

  case 44: /* show_statement: DESCRIBE table_name  */
#line 480 "bison_parser.y"
                      {
  (yyval.show_stmt) = new ShowStatement(kShowColumns);
  (yyval.show_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.show_stmt)->name = (yyvsp[0].table_name).name;
}
#line 3545 "bison_parser.cpp"
    break;

  case 45: /* show_statement: DESC table_name  */
#line 485 "bison_parser.y"
                  {
  (yyval.show_stmt) = new ShowStatement(kShowColumns);
  (yyval.show_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.show_stmt)->name = (yyvsp[0].table_name).name;
}
#line 3555 "bison_parser.cpp"
    break;

  case 46: /* create_statement: CREATE TABLE opt_not_exists table_name FROM IDENTIFIER FILE file_path  */
#line 496 "bison_parser.y"
                                                                                         {
  (yyval.create_stmt) = new CreateStatement(kCreateTableFromTbl);
  (yyval.create_stmt)->ifNotExists = (yyvsp[-5].bval);
  (yyval.create_stmt)->schema = (yyvsp[-4].table_name).schema;
  (yyval.create_stmt)->tableName = (yyvsp[-4].table_name).name;
  if (strcasecmp((yyvsp[-2].sval), "tbl") != 0) {
    free((yyvsp[-2].sval));
    yyerror(&yyloc, result, scanner, "File type is unknown.");
    YYERROR;
  }
  free((yyvsp[-2].sval));
  (yyval.create_stmt)->filePath = (yyvsp[0].sval);
}
#line 3573 "bison_parser.cpp"
    break;

  case 47: /* create_statement: CREATE TABLE opt_not_exists table_name '(' table_elem_commalist ')'  */
#line 509 "bison_parser.y"
                                                                      {
  (yyval.create_stmt) = new CreateStatement(kCreateTable);
  (yyval.create_stmt)->ifNotExists = (yyvsp[-4].bval);
  (yyval.create_stmt)->schema = (yyvsp[-3].table_name).schema;
  (yyval.create_stmt)->tableName = (yyvsp[-3].table_name).name;
  (yyval.create_stmt)->setColumnDefsAndConstraints((yyvsp[-1].table_element_vec));
  delete (yyvsp[-1].table_element_vec);
  if (result->errorMsg()) {
    delete (yyval.create_stmt);
    YYERROR;
  }
}
#line 3590 "bison_parser.cpp"
    break;

  case 48: /* create_statement: CREATE TABLE opt_not_exists table_name AS select_statement  */
#line 521 "bison_parser.y"
                                                             {
  (yyval.create_stmt) = new CreateStatement(kCreateTable);
  (yyval.create_stmt)->ifNotExists = (yyvsp[-3].bval);
  (yyval.create_stmt)->schema = (yyvsp[-2].table_name).schema;
  (yyval.create_stmt)->tableName = (yyvsp[-2].table_name).name;
  (yyval.create_stmt)->select = (yyvsp[0].select_stmt);
}
#line 3602 "bison_parser.cpp"
    break;

  case 49: /* create_statement: CREATE opt_unique INDEX opt_not_exists opt_index_name ON table_name '(' ident_commalist ')'  */
#line 528 "bison_parser.y"
                                                                                              {
  (yyval.create_stmt) = new CreateStatement(kCreateIndex);
  (yyval.create_stmt)->indexName = (yyvsp[-5].sval);
  (yyval.create_stmt)->ifNotExists = (yyvsp[-6].bval);
  (yyval.create_stmt)->isUnique = (yyvsp[-8].bval);
  (yyval.create_stmt)->tableName = (yyvsp[-3].table_name).name;
  (yyval.create_stmt)->indexColumns = (yyvsp[-1].str_vec);
}
#line 3615 "bison_parser.cpp"
    break;

  case 50: /* create_statement: CREATE VIEW opt_not_exists table_name opt_column_list AS select_statement  */
#line 536 "bison_parser.y"
                                                                            {
  (yyval.create_stmt) = new CreateStatement(kCreateView);
  (yyval.create_stmt)->ifNotExists = (yyvsp[-4].bval);
  (yyval.create_stmt)->schema = (yyvsp[-3].table_name).schema;
  (yyval.create_stmt)->tableName = (yyvsp[-3].table_name).name;
  (yyval.create_stmt)->viewColumns = (yyvsp[-2].str_vec);
  (yyval.create_stmt)->select = (yyvsp[0].select_stmt);
}
#line 3628 "bison_parser.cpp"
    break;

  case 51: /* opt_not_exists: IF NOT EXISTS  */
#line 545 "bison_parser.y"
                               { (yyval.bval) = true; }
#line 3634 "bison_parser.cpp"
    break;

  case 52: /* opt_not_exists: %empty  */
#line 546 "bison_parser.y"
              { (yyval.bval) = false; }
#line 3640 "bison_parser.cpp"
    break;

  case 53: /* opt_unique: UNIQUE  */
#line 548 "bison_parser.y"
                   { (yyval.bval) = true; }
#line 3646 "bison_parser.cpp"
    break;

  case 54: /* opt_unique: %empty  */
#line 549 "bison_parser.y"
              { (yyval.bval) = false; }
#line 3652 "bison_parser.cpp"
    break;

  case 55: /* table_elem_commalist: table_elem  */
#line 551 "bison_parser.y"
                                  {
  (yyval.table_element_vec) = new std::vector<TableElement*>();
  (yyval.table_element_vec)->push_back((yyvsp[0].table_element_t));
}
#line 3661 "bison_parser.cpp"
    break;

  case 56: /* table_elem_commalist: table_elem_commalist ',' table_elem  */
#line 555 "bison_parser.y"
                                      {
  (yyvsp[-2].table_element_vec)->push_back((yyvsp[0].table_element_t));
  (yyval.table_element_vec) = (yyvsp[-2].table_element_vec);
}
#line 3670 "bison_parser.cpp"
    break;

  case 57: /* table_elem: column_def  */
#line 560 "bison_parser.y"
                        { (yyval.table_element_t) = (yyvsp[0].column_t); }
#line 3676 "bison_parser.cpp"
    break;

  case 58: /* table_elem: table_constraint  */
#line 561 "bison_parser.y"
                   { (yyval.table_element_t) = (yyvsp[0].table_constraint_t); }
#line 3682 "bison_parser.cpp"
    break;

  case 59: /* column_def: IDENTIFIER column_type opt_column_constraints  */
#line 563 "bison_parser.y"
                                                           {
  (yyval.column_t) = new ColumnDefinition((yyvsp[-2].sval), (yyvsp[-1].column_type_t), (yyvsp[0].column_constraint_set));
  if (!(yyval.column_t)->trySetNullableExplicit()) {
    yyerror(&yyloc, result, scanner, ("Conflicting nullability constraints for " + std::string{(yyvsp[-2].sval)}).c_str());
  }
}
#line 3693 "bison_parser.cpp"
    break;

  case 60: /* column_type: BIGINT  */
#line 570 "bison_parser.y"
                     { (yyval.column_type_t) = ColumnType{DataType::BIGINT}; }
#line 3699 "bison_parser.cpp"
    break;

  case 61: /* column_type: BOOLEAN  */
#line 571 "bison_parser.y"
          { (yyval.column_type_t) = ColumnType{DataType::BOOLEAN}; }
#line 3705 "bison_parser.cpp"
    break;

  case 62: /* column_type: CHAR '(' INTVAL ')'  */
#line 572 "bison_parser.y"
                      { (yyval.column_type_t) = ColumnType{DataType::CHAR, (yyvsp[-1].ival)}; }
#line 3711 "bison_parser.cpp"
    break;

  case 63: /* column_type: CHARACTER_VARYING '(' INTVAL ')'  */
#line 573 "bison_parser.y"
                                   { (yyval.column_type_t) = ColumnType{DataType::VARCHAR, (yyvsp[-1].ival)}; }
#line 3717 "bison_parser.cpp"
    break;

  case 64: /* column_type: DATE  */
#line 574 "bison_parser.y"
       { (yyval.column_type_t) = ColumnType{DataType::DATE}; }
#line 3723 "bison_parser.cpp"
    break;

  case 65: /* column_type: DATETIME  */
#line 575 "bison_parser.y"
           { (yyval.column_type_t) = ColumnType{DataType::DATETIME}; }
#line 3729 "bison_parser.cpp"
    break;

  case 66: /* column_type: DECIMAL opt_decimal_specification  */
#line 576 "bison_parser.y"
                                    {
  (yyval.column_type_t) = ColumnType{DataType::DECIMAL, 0, (yyvsp[0].ival_pair)->first, (yyvsp[0].ival_pair)->second};
  delete (yyvsp[0].ival_pair);
}
#line 3738 "bison_parser.cpp"
    break;

  case 67: /* column_type: DOUBLE  */
#line 580 "bison_parser.y"
         { (yyval.column_type_t) = ColumnType{DataType::DOUBLE}; }
#line 3744 "bison_parser.cpp"
    break;

  case 68: /* column_type: FLOAT  */
#line 581 "bison_parser.y"
        { (yyval.column_type_t) = ColumnType{DataType::FLOAT}; }
#line 3750 "bison_parser.cpp"
    break;

  case 69: /* column_type: INT  */
#line 582 "bison_parser.y"
      { (yyval.column_type_t) = ColumnType{DataType::INT}; }
#line 3756 "bison_parser.cpp"
    break;

  case 70: /* column_type: INTEGER  */
#line 583 "bison_parser.y"
          { (yyval.column_type_t) = ColumnType{DataType::INT}; }
#line 3762 "bison_parser.cpp"
    break;

  case 71: /* column_type: LONG  */
#line 584 "bison_parser.y"
       { (yyval.column_type_t) = ColumnType{DataType::LONG}; }
#line 3768 "bison_parser.cpp"
    break;

  case 72: /* column_type: REAL  */
#line 585 "bison_parser.y"
       { (yyval.column_type_t) = ColumnType{DataType::REAL}; }
#line 3774 "bison_parser.cpp"
    break;

  case 73: /* column_type: SMALLINT  */
#line 586 "bison_parser.y"
           { (yyval.column_type_t) = ColumnType{DataType::SMALLINT}; }
#line 3780 "bison_parser.cpp"
    break;

  case 74: /* column_type: TEXT  */
#line 587 "bison_parser.y"
       { (yyval.column_type_t) = ColumnType{DataType::TEXT}; }
#line 3786 "bison_parser.cpp"
    break;

  case 75: /* column_type: TIME opt_time_precision  */
#line 588 "bison_parser.y"
                          { (yyval.column_type_t) = ColumnType{DataType::TIME, 0, (yyvsp[0].ival)}; }
#line 3792 "bison_parser.cpp"
    break;

  case 76: /* column_type: TIMESTAMP  */
#line 589 "bison_parser.y"
            { (yyval.column_type_t) = ColumnType{DataType::DATETIME}; }
#line 3798 "bison_parser.cpp"
    break;

  case 77: /* column_type: VARCHAR '(' INTVAL ')'  */
#line 590 "bison_parser.y"
                         { (yyval.column_type_t) = ColumnType{DataType::VARCHAR, (yyvsp[-1].ival)}; }
#line 3804 "bison_parser.cpp"
    break;

  case 78: /* opt_time_precision: '(' INTVAL ')'  */
#line 592 "bison_parser.y"
                                    { (yyval.ival) = (yyvsp[-1].ival); }
#line 3810 "bison_parser.cpp"
    break;

  case 79: /* opt_time_precision: %empty  */
#line 593 "bison_parser.y"
              { (yyval.ival) = 0; }
#line 3816 "bison_parser.cpp"
    break;

  case 80: /* opt_decimal_specification: '(' INTVAL ',' INTVAL ')'  */
#line 595 "bison_parser.y"
                                                      { (yyval.ival_pair) = new std::pair<int64_t, int64_t>{(yyvsp[-3].ival), (yyvsp[-1].ival)}; }
#line 3822 "bison_parser.cpp"
    break;

  case 81: /* opt_decimal_specification: '(' INTVAL ')'  */
#line 596 "bison_parser.y"
                 { (yyval.ival_pair) = new std::pair<int64_t, int64_t>{(yyvsp[-1].ival), 0}; }
#line 3828 "bison_parser.cpp"
    break;

  case 82: /* opt_decimal_specification: %empty  */
#line 597 "bison_parser.y"
              { (yyval.ival_pair) = new std::pair<int64_t, int64_t>{0, 0}; }
#line 3834 "bison_parser.cpp"
    break;

  case 83: /* opt_column_constraints: column_constraint_set  */
#line 599 "bison_parser.y"
                                               { (yyval.column_constraint_set) = (yyvsp[0].column_constraint_set); }
#line 3840 "bison_parser.cpp"
    break;

  case 84: /* opt_column_constraints: %empty  */
#line 600 "bison_parser.y"
              { (yyval.column_constraint_set) = new std::unordered_set<ConstraintType>(); }
#line 3846 "bison_parser.cpp"
    break;

  case 85: /* column_constraint_set: column_constraint  */
#line 602 "bison_parser.y"
                                          {
  (yyval.column_constraint_set) = new std::unordered_set<ConstraintType>();
  (yyval.column_constraint_set)->insert((yyvsp[0].column_constraint_t));
}
#line 3855 "bison_parser.cpp"
    break;

  case 86: /* column_constraint_set: column_constraint_set column_constraint  */
#line 606 "bison_parser.y"
                                          {
  (yyvsp[-1].column_constraint_set)->insert((yyvsp[0].column_constraint_t));
  (yyval.column_constraint_set) = (yyvsp[-1].column_constraint_set);
}
#line 3864 "bison_parser.cpp"
    break;

  case 87: /* column_constraint: PRIMARY KEY  */
#line 611 "bison_parser.y"
                                { (yyval.column_constraint_t) = ConstraintType::PrimaryKey; }
#line 3870 "bison_parser.cpp"
    break;

  case 88: /* column_constraint: UNIQUE  */
#line 612 "bison_parser.y"
         { (yyval.column_constraint_t) = ConstraintType::Unique; }
#line 3876 "bison_parser.cpp"
    break;

  case 89: /* column_constraint: NULL  */
#line 613 "bison_parser.y"
       { (yyval.column_constraint_t) = ConstraintType::Null; }
#line 3882 "bison_parser.cpp"
    break;

  case 90: /* column_constraint: NOT NULL  */
#line 614 "bison_parser.y"
           { (yyval.column_constraint_t) = ConstraintType::NotNull; }
#line 3888 "bison_parser.cpp"
    break;

  case 91: /* table_constraint: PRIMARY KEY '(' ident_commalist ')'  */
#line 616 "bison_parser.y"
                                                       { (yyval.table_constraint_t) = new TableConstraint(ConstraintType::PrimaryKey, (yyvsp[-1].str_vec)); }
#line 3894 "bison_parser.cpp"
    break;

  case 92: /* table_constraint: UNIQUE '(' ident_commalist ')'  */
#line 617 "bison_parser.y"
                                 { (yyval.table_constraint_t) = new TableConstraint(ConstraintType::Unique, (yyvsp[-1].str_vec)); }
#line 3900 "bison_parser.cpp"
    break;

  case 93: /* drop_statement: DROP TABLE opt_exists table_name  */
#line 625 "bison_parser.y"
                                                  {
  (yyval.drop_stmt) = new DropStatement(kDropTable);
  (yyval.drop_stmt)->ifExists = (yyvsp[-1].bval);
  (yyval.drop_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.drop_stmt)->name = (yyvsp[0].table_name).name;
}
#line 3911 "bison_parser.cpp"
    break;

  case 94: /* drop_statement: DROP VIEW opt_exists table_name  */
#line 631 "bison_parser.y"
                                  {
  (yyval.drop_stmt) = new DropStatement(kDropView);
  (yyval.drop_stmt)->ifExists = (yyvsp[-1].bval);
  (yyval.drop_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.drop_stmt)->name = (yyvsp[0].table_name).name;
}
#line 3922 "bison_parser.cpp"
    break;

  case 95: /* drop_statement: DEALLOCATE PREPARE IDENTIFIER  */
#line 637 "bison_parser.y"
                                {
  (yyval.drop_stmt) = new DropStatement(kDropPreparedStatement);
  (yyval.drop_stmt)->ifExists = false;
  (yyval.drop_stmt)->name = (yyvsp[0].sval);
}
#line 3932 "bison_parser.cpp"
    break;

  case 96: /* drop_statement: DROP INDEX opt_exists IDENTIFIER  */
#line 643 "bison_parser.y"
                                   {
  (yyval.drop_stmt) = new DropStatement(kDropIndex);
  (yyval.drop_stmt)->ifExists = (yyvsp[-1].bval);
  (yyval.drop_stmt)->indexName = (yyvsp[0].sval);
}
#line 3942 "bison_parser.cpp"
    break;

  case 97: /* opt_exists: IF EXISTS  */
#line 649 "bison_parser.y"
                       { (yyval.bval) = true; }
#line 3948 "bison_parser.cpp"
    break;

  case 98: /* opt_exists: %empty  */
#line 650 "bison_parser.y"
              { (yyval.bval) = false; }
#line 3954 "bison_parser.cpp"
    break;

  case 99: /* alter_statement: ALTER TABLE opt_exists table_name alter_action  */
#line 657 "bison_parser.y"
                                                                 {
  (yyval.alter_stmt) = new AlterStatement((yyvsp[-1].table_name).name, (yyvsp[0].alter_action_t));
  (yyval.alter_stmt)->ifTableExists = (yyvsp[-2].bval);
  (yyval.alter_stmt)->schema = (yyvsp[-1].table_name).schema;
}
#line 3964 "bison_parser.cpp"
    break;

  case 100: /* alter_action: drop_action  */
#line 663 "bison_parser.y"
                           { (yyval.alter_action_t) = (yyvsp[0].drop_action_t); }
#line 3970 "bison_parser.cpp"
    break;

  case 101: /* drop_action: DROP COLUMN opt_exists IDENTIFIER  */
#line 665 "bison_parser.y"
                                                {
  (yyval.drop_action_t) = new DropColumnAction((yyvsp[0].sval));
  (yyval.drop_action_t)->ifExists = (yyvsp[-1].bval);
}
#line 3979 "bison_parser.cpp"
    break;

  case 102: /* delete_statement: DELETE FROM table_name opt_where  */
#line 675 "bison_parser.y"
                                                    {
  (yyval.delete_stmt) = new DeleteStatement();
  (yyval.delete_stmt)->schema = (yyvsp[-1].table_name).schema;
  (yyval.delete_stmt)->tableName = (yyvsp[-1].table_name).name;
  (yyval.delete_stmt)->expr = (yyvsp[0].expr);
}
#line 3990 "bison_parser.cpp"
    break;

  case 103: /* truncate_statement: TRUNCATE table_name  */
#line 682 "bison_parser.y"
                                         {
  (yyval.delete_stmt) = new DeleteStatement();
  (yyval.delete_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.delete_stmt)->tableName = (yyvsp[0].table_name).name;
}
#line 4000 "bison_parser.cpp"
    break;

  case 104: /* insert_statement: INSERT INTO table_name opt_column_list VALUES '(' literal_list ')'  */
#line 693 "bison_parser.y"
                                                                                      {
  (yyval.insert_stmt) = new InsertStatement(kInsertValues);
  (yyval.insert_stmt)->schema = (yyvsp[-5].table_name).schema;
  (yyval.insert_stmt)->tableName = (yyvsp[-5].table_name).name;
  (yyval.insert_stmt)->columns = (yyvsp[-4].str_vec);
  (yyval.insert_stmt)->values = (yyvsp[-1].expr_vec);
}
#line 4012 "bison_parser.cpp"
    break;

  case 105: /* insert_statement: INSERT INTO table_name opt_column_list select_no_paren  */
#line 700 "bison_parser.y"
                                                         {
  (yyval.insert_stmt) = new InsertStatement(kInsertSelect);
  (yyval.insert_stmt)->schema = (yyvsp[-2].table_name).schema;
  (yyval.insert_stmt)->tableName = (yyvsp[-2].table_name).name;
  (yyval.insert_stmt)->columns = (yyvsp[-1].str_vec);
  (yyval.insert_stmt)->select = (yyvsp[0].select_stmt);
}
#line 4024 "bison_parser.cpp"
    break;

  case 106: /* opt_column_list: '(' ident_commalist ')'  */
#line 708 "bison_parser.y"
                                          { (yyval.str_vec) = (yyvsp[-1].str_vec); }
#line 4030 "bison_parser.cpp"
    break;

  case 107: /* opt_column_list: %empty  */
#line 709 "bison_parser.y"
              { (yyval.str_vec) = nullptr; }
#line 4036 "bison_parser.cpp"
    break;

  case 108: /* update_statement: UPDATE table_ref_name_no_alias SET update_clause_commalist opt_where  */
#line 716 "bison_parser.y"
                                                                                        {
  (yyval.update_stmt) = new UpdateStatement();
  (yyval.update_stmt)->table = (yyvsp[-3].table);
  (yyval.update_stmt)->updates = (yyvsp[-1].update_vec);
  (yyval.update_stmt)->where = (yyvsp[0].expr);
}
#line 4047 "bison_parser.cpp"
    break;

  case 109: /* update_clause_commalist: update_clause  */
#line 723 "bison_parser.y"
                                        {
  (yyval.update_vec) = new std::vector<UpdateClause*>();
  (yyval.update_vec)->push_back((yyvsp[0].update_t));
}
#line 4056 "bison_parser.cpp"
    break;

  case 110: /* update_clause_commalist: update_clause_commalist ',' update_clause  */
#line 727 "bison_parser.y"
                                            {
  (yyvsp[-2].update_vec)->push_back((yyvsp[0].update_t));
  (yyval.update_vec) = (yyvsp[-2].update_vec);
}
#line 4065 "bison_parser.cpp"
    break;

  case 111: /* update_clause: IDENTIFIER '=' expr  */
#line 732 "bison_parser.y"
                                    {
  (yyval.update_t) = new UpdateClause();
  (yyval.update_t)->column = (yyvsp[-2].sval);
  (yyval.update_t)->value = (yyvsp[0].expr);
}
#line 4075 "bison_parser.cpp"
    break;

  case 112: /* select_statement: opt_with_clause select_with_paren  */
#line 742 "bison_parser.y"
                                                     {
  (yyval.select_stmt) = (yyvsp[0].select_stmt);
  (yyval.select_stmt)->withDescriptions = (yyvsp[-1].with_description_vec);
}
#line 4084 "bison_parser.cpp"
    break;

  case 113: /* select_statement: opt_with_clause select_no_paren  */
#line 746 "bison_parser.y"
                                  {
  (yyval.select_stmt) = (yyvsp[0].select_stmt);
  (yyval.select_stmt)->withDescriptions = (yyvsp[-1].with_description_vec);
}
#line 4093 "bison_parser.cpp"
    break;

  case 114: /* select_statement: opt_with_clause select_with_paren set_operator select_within_set_operation opt_order opt_limit  */
#line 750 "bison_parser.y"
                                                                                                 {
  (yyval.select_stmt) = (yyvsp[-4].select_stmt);
  if ((yyval.select_stmt)->setOperations == nullptr) {
    (yyval.select_stmt)->setOperations = new std::vector<SetOperation*>();
  }
  (yyval.select_stmt)->setOperations->push_back((yyvsp[-3].set_operator_t));
  (yyval.select_stmt)->setOperations->back()->nestedSelectStatement = (yyvsp[-2].select_stmt);
  (yyval.select_stmt)->setOperations->back()->resultOrder = (yyvsp[-1].order_vec);
  (yyval.select_stmt)->setOperations->back()->resultLimit = (yyvsp[0].limit);
  (yyval.select_stmt)->withDescriptions = (yyvsp[-5].with_description_vec);
}
#line 4109 "bison_parser.cpp"
    break;

  case 117: /* select_within_set_operation_no_parentheses: select_clause  */
#line 764 "bison_parser.y"
                                                           { (yyval.select_stmt) = (yyvsp[0].select_stmt); }
#line 4115 "bison_parser.cpp"
    break;

  case 118: /* select_within_set_operation_no_parentheses: select_clause set_operator select_within_set_operation  */
#line 765 "bison_parser.y"
                                                         {
  (yyval.select_stmt) = (yyvsp[-2].select_stmt);
  if ((yyval.select_stmt)->setOperations == nullptr) {
    (yyval.select_stmt)->setOperations = new std::vector<SetOperation*>();
  }
  (yyval.select_stmt)->setOperations->push_back((yyvsp[-1].set_operator_t));
  (yyval.select_stmt)->setOperations->back()->nestedSelectStatement = (yyvsp[0].select_stmt);
}
#line 4128 "bison_parser.cpp"
    break;

  case 119: /* select_with_paren: '(' select_no_paren ')'  */
#line 774 "bison_parser.y"
                                            { (yyval.select_stmt) = (yyvsp[-1].select_stmt); }
#line 4134 "bison_parser.cpp"
    break;

  case 120: /* select_with_paren: '(' select_with_paren ')'  */
#line 775 "bison_parser.y"
                            { (yyval.select_stmt) = (yyvsp[-1].select_stmt); }
#line 4140 "bison_parser.cpp"
    break;

  case 121: /* select_no_paren: select_clause opt_order opt_limit opt_locking_clause  */
#line 777 "bison_parser.y"
                                                                       {
  (yyval.select_stmt) = (yyvsp[-3].select_stmt);
  (yyval.select_stmt)->order = (yyvsp[-2].order_vec);

  // Limit could have been set by TOP.
  if ((yyvsp[-1].limit) != nullptr) {
    delete (yyval.select_stmt)->limit;
    (yyval.select_stmt)->limit = (yyvsp[-1].limit);
  }

  if ((yyvsp[0].locking_clause_vec) != nullptr) {
    (yyval.select_stmt)->lockings = (yyvsp[0].locking_clause_vec);
  }
}
#line 4159 "bison_parser.cpp"
    break;

  case 122: /* select_no_paren: select_clause set_operator select_within_set_operation opt_order opt_limit opt_locking_clause  */
#line 791 "bison_parser.y"
                                                                                                {
  (yyval.select_stmt) = (yyvsp[-5].select_stmt);
  if ((yyval.select_stmt)->setOperations == nullptr) {
    (yyval.select_stmt)->setOperations = new std::vector<SetOperation*>();
  }
  (yyval.select_stmt)->setOperations->push_back((yyvsp[-4].set_operator_t));
  (yyval.select_stmt)->setOperations->back()->nestedSelectStatement = (yyvsp[-3].select_stmt);
  (yyval.select_stmt)->setOperations->back()->resultOrder = (yyvsp[-2].order_vec);
  (yyval.select_stmt)->setOperations->back()->resultLimit = (yyvsp[-1].limit);
  (yyval.select_stmt)->lockings = (yyvsp[0].locking_clause_vec);
}
#line 4175 "bison_parser.cpp"
    break;

  case 123: /* set_operator: set_type opt_all  */
#line 803 "bison_parser.y"
                                {
  (yyval.set_operator_t) = (yyvsp[-1].set_operator_t);
  (yyval.set_operator_t)->isAll = (yyvsp[0].bval);
}
#line 4184 "bison_parser.cpp"
    break;

  case 124: /* set_type: UNION  */
#line 808 "bison_parser.y"
                 {
  (yyval.set_operator_t) = new SetOperation();
  (yyval.set_operator_t)->setType = SetType::kSetUnion;
}
#line 4193 "bison_parser.cpp"
    break;

  case 125: /* set_type: INTERSECT  */
#line 812 "bison_parser.y"
            {
  (yyval.set_operator_t) = new SetOperation();
  (yyval.set_operator_t)->setType = SetType::kSetIntersect;
}
#line 4202 "bison_parser.cpp"
    break;

  case 126: /* set_type: EXCEPT  */
#line 816 "bison_parser.y"
         {
  (yyval.set_operator_t) = new SetOperation();
  (yyval.set_operator_t)->setType = SetType::kSetExcept;
}
#line 4211 "bison_parser.cpp"
    break;

  case 127: /* opt_all: ALL  */
#line 821 "bison_parser.y"
              { (yyval.bval) = true; }
#line 4217 "bison_parser.cpp"
    break;

  case 128: /* opt_all: %empty  */
#line 822 "bison_parser.y"
              { (yyval.bval) = false; }
#line 4223 "bison_parser.cpp"
    break;

  case 129: /* select_clause: SELECT opt_top opt_distinct select_list opt_from_clause opt_where opt_group  */
#line 824 "bison_parser.y"
                                                                                            {
  (yyval.select_stmt) = new SelectStatement();
  (yyval.select_stmt)->limit = (yyvsp[-5].limit);
  (yyval.select_stmt)->selectDistinct = (yyvsp[-4].bval);
  (yyval.select_stmt)->selectList = (yyvsp[-3].expr_vec);
  (yyval.select_stmt)->fromTable = (yyvsp[-2].table);
  (yyval.select_stmt)->whereClause = (yyvsp[-1].expr);
  (yyval.select_stmt)->groupBy = (yyvsp[0].group_t);
}
#line 4237 "bison_parser.cpp"
    break;

  case 130: /* opt_distinct: DISTINCT  */
#line 834 "bison_parser.y"
                        { (yyval.bval) = true; }
#line 4243 "bison_parser.cpp"
    break;

  case 131: /* opt_distinct: %empty  */
#line 835 "bison_parser.y"
              { (yyval.bval) = false; }
#line 4249 "bison_parser.cpp"
    break;

  case 133: /* opt_from_clause: from_clause  */
#line 839 "bison_parser.y"
                              { (yyval.table) = (yyvsp[0].table); }
#line 4255 "bison_parser.cpp"
    break;

  case 134: /* opt_from_clause: %empty  */
#line 840 "bison_parser.y"
              { (yyval.table) = nullptr; }
#line 4261 "bison_parser.cpp"
    break;

  case 135: /* from_clause: FROM table_ref  */
#line 842 "bison_parser.y"
                             { (yyval.table) = (yyvsp[0].table); }
#line 4267 "bison_parser.cpp"
    break;

  case 136: /* opt_where: WHERE expr  */
#line 844 "bison_parser.y"
                       { (yyval.expr) = (yyvsp[0].expr); }
#line 4273 "bison_parser.cpp"
    break;

  case 137: /* opt_where: %empty  */
#line 845 "bison_parser.y"
              { (yyval.expr) = nullptr; }
#line 4279 "bison_parser.cpp"
    break;

  case 138: /* opt_group: GROUP BY expr_list opt_having  */
#line 847 "bison_parser.y"
                                          {
  (yyval.group_t) = new GroupByDescription();
  (yyval.group_t)->columns = (yyvsp[-1].expr_vec);
  (yyval.group_t)->having = (yyvsp[0].expr);
}
#line 4289 "bison_parser.cpp"
    break;

  case 139: /* opt_group: %empty  */
#line 852 "bison_parser.y"
              { (yyval.group_t) = nullptr; }
#line 4295 "bison_parser.cpp"
    break;

  case 140: /* opt_having: HAVING expr  */
#line 854 "bison_parser.y"
                         { (yyval.expr) = (yyvsp[0].expr); }
#line 4301 "bison_parser.cpp"
    break;

  case 141: /* opt_having: %empty  */
#line 855 "bison_parser.y"
              { (yyval.expr) = nullptr; }
#line 4307 "bison_parser.cpp"
    break;

  case 142: /* opt_order: ORDER BY order_list  */
#line 857 "bison_parser.y"
                                { (yyval.order_vec) = (yyvsp[0].order_vec); }
#line 4313 "bison_parser.cpp"
    break;

  case 143: /* opt_order: %empty  */
#line 858 "bison_parser.y"
              { (yyval.order_vec) = nullptr; }
#line 4319 "bison_parser.cpp"
    break;

  case 144: /* order_list: order_desc  */
#line 860 "bison_parser.y"
                        {
  (yyval.order_vec) = new std::vector<OrderDescription*>();
  (yyval.order_vec)->push_back((yyvsp[0].order));
}
#line 4328 "bison_parser.cpp"
    break;

  case 145: /* order_list: order_list ',' order_desc  */
#line 864 "bison_parser.y"
                            {
  (yyvsp[-2].order_vec)->push_back((yyvsp[0].order));
  (yyval.order_vec) = (yyvsp[-2].order_vec);
}
#line 4337 "bison_parser.cpp"
    break;

  case 146: /* order_desc: expr opt_order_type  */
#line 869 "bison_parser.y"
                                 { (yyval.order) = new OrderDescription((yyvsp[0].order_type), (yyvsp[-1].expr)); }
#line 4343 "bison_parser.cpp"
    break;

  case 147: /* opt_order_type: ASC  */
#line 871 "bison_parser.y"
                     { (yyval.order_type) = kOrderAsc; }
#line 4349 "bison_parser.cpp"
    break;

  case 148: /* opt_order_type: DESC  */
#line 872 "bison_parser.y"
       { (yyval.order_type) = kOrderDesc; }
#line 4355 "bison_parser.cpp"
    break;

  case 149: /* opt_order_type: %empty  */
#line 873 "bison_parser.y"
              { (yyval.order_type) = kOrderAsc; }
#line 4361 "bison_parser.cpp"
    break;

  case 150: /* opt_top: TOP int_literal  */
#line 877 "bison_parser.y"
                          { (yyval.limit) = new LimitDescription((yyvsp[0].expr), nullptr); }
#line 4367 "bison_parser.cpp"
    break;

  case 151: /* opt_top: %empty  */
#line 878 "bison_parser.y"
              { (yyval.limit) = nullptr; }
#line 4373 "bison_parser.cpp"
    break;

  case 152: /* opt_limit: LIMIT expr  */
#line 880 "bison_parser.y"
                       { (yyval.limit) = new LimitDescription((yyvsp[0].expr), nullptr); }
#line 4379 "bison_parser.cpp"
    break;

  case 153: /* opt_limit: OFFSET expr  */
#line 881 "bison_parser.y"
              { (yyval.limit) = new LimitDescription(nullptr, (yyvsp[0].expr)); }
#line 4385 "bison_parser.cpp"
    break;

  case 154: /* opt_limit: LIMIT expr OFFSET expr  */
#line 882 "bison_parser.y"
                         { (yyval.limit) = new LimitDescription((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4391 "bison_parser.cpp"
    break;

  case 155: /* opt_limit: LIMIT ALL  */
#line 883 "bison_parser.y"
            { (yyval.limit) = new LimitDescription(nullptr, nullptr); }
#line 4397 "bison_parser.cpp"
    break;

  case 156: /* opt_limit: LIMIT ALL OFFSET expr  */
#line 884 "bison_parser.y"
                        { (yyval.limit) = new LimitDescription(nullptr, (yyvsp[0].expr)); }
#line 4403 "bison_parser.cpp"
    break;

  case 157: /* opt_limit: %empty  */
#line 885 "bison_parser.y"
              { (yyval.limit) = nullptr; }
#line 4409 "bison_parser.cpp"
    break;

  case 158: /* expr_list: expr_alias  */
#line 890 "bison_parser.y"
                       {
  (yyval.expr_vec) = new std::vector<Expr*>();
  (yyval.expr_vec)->push_back((yyvsp[0].expr));
}
#line 4418 "bison_parser.cpp"
    break;

  case 159: /* expr_list: expr_list ',' expr_alias  */
#line 894 "bison_parser.y"
                           {
  (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr));
  (yyval.expr_vec) = (yyvsp[-2].expr_vec);
}
#line 4427 "bison_parser.cpp"
    break;

  case 160: /* opt_literal_list: literal_list  */
#line 899 "bison_parser.y"
                                { (yyval.expr_vec) = (yyvsp[0].expr_vec); }
#line 4433 "bison_parser.cpp"
    break;

  case 161: /* opt_literal_list: %empty  */
#line 900 "bison_parser.y"
              { (yyval.expr_vec) = nullptr; }
#line 4439 "bison_parser.cpp"
    break;

  case 162: /* literal_list: literal  */
#line 902 "bison_parser.y"
                       {
  (yyval.expr_vec) = new std::vector<Expr*>();
  (yyval.expr_vec)->push_back((yyvsp[0].expr));
}
#line 4448 "bison_parser.cpp"
    break;

  case 163: /* literal_list: literal_list ',' literal  */
#line 906 "bison_parser.y"
                           {
  (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr));
  (yyval.expr_vec) = (yyvsp[-2].expr_vec);
}
#line 4457 "bison_parser.cpp"
    break;

  case 164: /* expr_alias: expr opt_alias  */
#line 911 "bison_parser.y"
                            {
  (yyval.expr) = (yyvsp[-1].expr);
  if ((yyvsp[0].alias_t)) {
    (yyval.expr)->alias = strdup((yyvsp[0].alias_t)->name);
    delete (yyvsp[0].alias_t);
  }
}
#line 4469 "bison_parser.cpp"
    break;

  case 170: /* operand: '(' expr ')'  */
#line 921 "bison_parser.y"
                       { (yyval.expr) = (yyvsp[-1].expr); }
#line 4475 "bison_parser.cpp"
    break;

  case 180: /* operand: '(' select_no_paren ')'  */
#line 923 "bison_parser.y"
                                         {
  (yyval.expr) = Expr::makeSelect((yyvsp[-1].select_stmt));
}
#line 4483 "bison_parser.cpp"
    break;

  case 183: /* unary_expr: '-' operand  */
#line 929 "bison_parser.y"
                         { (yyval.expr) = Expr::makeOpUnary(kOpUnaryMinus, (yyvsp[0].expr)); }
#line 4489 "bison_parser.cpp"
    break;

  case 184: /* unary_expr: NOT operand  */
#line 930 "bison_parser.y"
              { (yyval.expr) = Expr::makeOpUnary(kOpNot, (yyvsp[0].expr)); }
#line 4495 "bison_parser.cpp"
    break;

  case 185: /* unary_expr: operand ISNULL  */
#line 931 "bison_parser.y"
                 { (yyval.expr) = Expr::makeOpUnary(kOpIsNull, (yyvsp[-1].expr)); }
#line 4501 "bison_parser.cpp"
    break;

  case 186: /* unary_expr: operand IS NULL  */
#line 932 "bison_parser.y"
                  { (yyval.expr) = Expr::makeOpUnary(kOpIsNull, (yyvsp[-2].expr)); }
#line 4507 "bison_parser.cpp"
    break;

  case 187: /* unary_expr: operand IS NOT NULL  */
#line 933 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeOpUnary(kOpIsNull, (yyvsp[-3].expr))); }
#line 4513 "bison_parser.cpp"
    break;

  case 189: /* binary_expr: operand '-' operand  */
#line 935 "bison_parser.y"
                                              { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpMinus, (yyvsp[0].expr)); }
#line 4519 "bison_parser.cpp"
    break;

  case 190: /* binary_expr: operand '+' operand  */
#line 936 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpPlus, (yyvsp[0].expr)); }
#line 4525 "bison_parser.cpp"
    break;

  case 191: /* binary_expr: operand '/' operand  */
#line 937 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpSlash, (yyvsp[0].expr)); }
#line 4531 "bison_parser.cpp"
    break;

  case 192: /* binary_expr: operand '*' operand  */
#line 938 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpAsterisk, (yyvsp[0].expr)); }
#line 4537 "bison_parser.cpp"
    break;

  case 193: /* binary_expr: operand '%' operand  */
#line 939 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpPercentage, (yyvsp[0].expr)); }
#line 4543 "bison_parser.cpp"
    break;

  case 194: /* binary_expr: operand '^' operand  */
#line 940 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpCaret, (yyvsp[0].expr)); }
#line 4549 "bison_parser.cpp"
    break;

  case 195: /* binary_expr: operand LIKE operand  */
#line 941 "bison_parser.y"
                       { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpLike, (yyvsp[0].expr)); }
#line 4555 "bison_parser.cpp"
    break;

  case 196: /* binary_expr: operand NOT LIKE operand  */
#line 942 "bison_parser.y"
                           { (yyval.expr) = Expr::makeOpBinary((yyvsp[-3].expr), kOpNotLike, (yyvsp[0].expr)); }
#line 4561 "bison_parser.cpp"
    break;

  case 197: /* binary_expr: operand ILIKE operand  */
#line 943 "bison_parser.y"
                        { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpILike, (yyvsp[0].expr)); }
#line 4567 "bison_parser.cpp"
    break;

  case 198: /* binary_expr: operand CONCAT operand  */
#line 944 "bison_parser.y"
                         { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpConcat, (yyvsp[0].expr)); }
#line 4573 "bison_parser.cpp"
    break;

  case 199: /* logic_expr: expr AND expr  */
#line 946 "bison_parser.y"
                           { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpAnd, (yyvsp[0].expr)); }
#line 4579 "bison_parser.cpp"
    break;

  case 200: /* logic_expr: expr OR expr  */
#line 947 "bison_parser.y"
               { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpOr, (yyvsp[0].expr)); }
#line 4585 "bison_parser.cpp"
    break;

  case 201: /* in_expr: operand IN '(' expr_list ')'  */
#line 949 "bison_parser.y"
                                       { (yyval.expr) = Expr::makeInOperator((yyvsp[-4].expr), (yyvsp[-1].expr_vec)); }
#line 4591 "bison_parser.cpp"
    break;

  case 202: /* in_expr: operand NOT IN '(' expr_list ')'  */
#line 950 "bison_parser.y"
                                   { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeInOperator((yyvsp[-5].expr), (yyvsp[-1].expr_vec))); }
#line 4597 "bison_parser.cpp"
    break;

  case 203: /* in_expr: operand IN '(' select_no_paren ')'  */
#line 951 "bison_parser.y"
                                     { (yyval.expr) = Expr::makeInOperator((yyvsp[-4].expr), (yyvsp[-1].select_stmt)); }
#line 4603 "bison_parser.cpp"
    break;

  case 204: /* in_expr: operand NOT IN '(' select_no_paren ')'  */
#line 952 "bison_parser.y"
                                         { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeInOperator((yyvsp[-5].expr), (yyvsp[-1].select_stmt))); }
#line 4609 "bison_parser.cpp"
    break;

  case 205: /* case_expr: CASE expr case_list END  */
#line 956 "bison_parser.y"
                                    { (yyval.expr) = Expr::makeCase((yyvsp[-2].expr), (yyvsp[-1].expr), nullptr); }
#line 4615 "bison_parser.cpp"
    break;

  case 206: /* case_expr: CASE expr case_list ELSE expr END  */
#line 957 "bison_parser.y"
                                    { (yyval.expr) = Expr::makeCase((yyvsp[-4].expr), (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 4621 "bison_parser.cpp"
    break;

  case 207: /* case_expr: CASE case_list END  */
#line 958 "bison_parser.y"
                     { (yyval.expr) = Expr::makeCase(nullptr, (yyvsp[-1].expr), nullptr); }
#line 4627 "bison_parser.cpp"
    break;

  case 208: /* case_expr: CASE case_list ELSE expr END  */
#line 959 "bison_parser.y"
                               { (yyval.expr) = Expr::makeCase(nullptr, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 4633 "bison_parser.cpp"
    break;

  case 209: /* case_list: WHEN expr THEN expr  */
#line 961 "bison_parser.y"
                                { (yyval.expr) = Expr::makeCaseList(Expr::makeCaseListElement((yyvsp[-2].expr), (yyvsp[0].expr))); }
#line 4639 "bison_parser.cpp"
    break;

  case 210: /* case_list: case_list WHEN expr THEN expr  */
#line 962 "bison_parser.y"
                                { (yyval.expr) = Expr::caseListAppend((yyvsp[-4].expr), Expr::makeCaseListElement((yyvsp[-2].expr), (yyvsp[0].expr))); }
#line 4645 "bison_parser.cpp"
    break;

  case 211: /* exists_expr: EXISTS '(' select_no_paren ')'  */
#line 964 "bison_parser.y"
                                             { (yyval.expr) = Expr::makeExists((yyvsp[-1].select_stmt)); }
#line 4651 "bison_parser.cpp"
    break;

  case 212: /* exists_expr: NOT EXISTS '(' select_no_paren ')'  */
#line 965 "bison_parser.y"
                                     { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeExists((yyvsp[-1].select_stmt))); }
#line 4657 "bison_parser.cpp"
    break;

  case 213: /* comp_expr: operand '=' operand  */
#line 967 "bison_parser.y"
                                { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpEquals, (yyvsp[0].expr)); }
#line 4663 "bison_parser.cpp"
    break;

  case 214: /* comp_expr: operand EQUALS operand  */
#line 968 "bison_parser.y"
                         { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpEquals, (yyvsp[0].expr)); }
#line 4669 "bison_parser.cpp"
    break;

  case 215: /* comp_expr: operand NOTEQUALS operand  */
#line 969 "bison_parser.y"
                            { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpNotEquals, (yyvsp[0].expr)); }
#line 4675 "bison_parser.cpp"
    break;

  case 216: /* comp_expr: operand '<' operand  */
#line 970 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpLess, (yyvsp[0].expr)); }
#line 4681 "bison_parser.cpp"
    break;

  case 217: /* comp_expr: operand '>' operand  */
#line 971 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpGreater, (yyvsp[0].expr)); }
#line 4687 "bison_parser.cpp"
    break;

  case 218: /* comp_expr: operand LESSEQ operand  */
#line 972 "bison_parser.y"
                         { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpLessEq, (yyvsp[0].expr)); }
#line 4693 "bison_parser.cpp"
    break;

  case 219: /* comp_expr: operand GREATEREQ operand  */
#line 973 "bison_parser.y"
                            { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpGreaterEq, (yyvsp[0].expr)); }
#line 4699 "bison_parser.cpp"
    break;

  case 220: /* function_expr: IDENTIFIER '(' ')'  */
#line 975 "bison_parser.y"
                                   { (yyval.expr) = Expr::makeFunctionRef((yyvsp[-2].sval), new std::vector<Expr*>(), false); }
#line 4705 "bison_parser.cpp"
    break;

  case 221: /* function_expr: IDENTIFIER '(' opt_distinct expr_list ')'  */
#line 976 "bison_parser.y"
                                            { (yyval.expr) = Expr::makeFunctionRef((yyvsp[-4].sval), (yyvsp[-1].expr_vec), (yyvsp[-2].bval)); }
#line 4711 "bison_parser.cpp"
    break;

  case 222: /* extract_expr: EXTRACT '(' datetime_field FROM expr ')'  */
#line 978 "bison_parser.y"
                                                        { (yyval.expr) = Expr::makeExtract((yyvsp[-3].datetime_field), (yyvsp[-1].expr)); }
#line 4717 "bison_parser.cpp"
    break;

  case 223: /* cast_expr: CAST '(' expr AS column_type ')'  */
#line 980 "bison_parser.y"
                                             { (yyval.expr) = Expr::makeCast((yyvsp[-3].expr), (yyvsp[-1].column_type_t)); }
#line 4723 "bison_parser.cpp"
    break;

  case 224: /* datetime_field: SECOND  */
#line 982 "bison_parser.y"
                        { (yyval.datetime_field) = kDatetimeSecond; }
#line 4729 "bison_parser.cpp"
    break;

  case 225: /* datetime_field: MINUTE  */
#line 983 "bison_parser.y"
         { (yyval.datetime_field) = kDatetimeMinute; }
#line 4735 "bison_parser.cpp"
    break;

  case 226: /* datetime_field: HOUR  */
#line 984 "bison_parser.y"
       { (yyval.datetime_field) = kDatetimeHour; }
#line 4741 "bison_parser.cpp"
    break;

  case 227: /* datetime_field: DAY  */
#line 985 "bison_parser.y"
      { (yyval.datetime_field) = kDatetimeDay; }
#line 4747 "bison_parser.cpp"
    break;

  case 228: /* datetime_field: MONTH  */
#line 986 "bison_parser.y"
        { (yyval.datetime_field) = kDatetimeMonth; }
#line 4753 "bison_parser.cpp"
    break;

  case 229: /* datetime_field: YEAR  */
#line 987 "bison_parser.y"
       { (yyval.datetime_field) = kDatetimeYear; }
#line 4759 "bison_parser.cpp"
    break;

  case 230: /* datetime_field_plural: SECONDS  */
#line 989 "bison_parser.y"
                                { (yyval.datetime_field) = kDatetimeSecond; }
#line 4765 "bison_parser.cpp"
    break;

  case 231: /* datetime_field_plural: MINUTES  */
#line 990 "bison_parser.y"
          { (yyval.datetime_field) = kDatetimeMinute; }
#line 4771 "bison_parser.cpp"
    break;

  case 232: /* datetime_field_plural: HOURS  */
#line 991 "bison_parser.y"
        { (yyval.datetime_field) = kDatetimeHour; }
#line 4777 "bison_parser.cpp"
    break;

  case 233: /* datetime_field_plural: DAYS  */
#line 992 "bison_parser.y"
       { (yyval.datetime_field) = kDatetimeDay; }
#line 4783 "bison_parser.cpp"
    break;

  case 234: /* datetime_field_plural: MONTHS  */
#line 993 "bison_parser.y"
         { (yyval.datetime_field) = kDatetimeMonth; }
#line 4789 "bison_parser.cpp"
    break;

  case 235: /* datetime_field_plural: YEARS  */
#line 994 "bison_parser.y"
        { (yyval.datetime_field) = kDatetimeYear; }
#line 4795 "bison_parser.cpp"
    break;

  case 238: /* array_expr: ARRAY '[' expr_list ']'  */
#line 998 "bison_parser.y"
                                     { (yyval.expr) = Expr::makeArray((yyvsp[-1].expr_vec)); }
#line 4801 "bison_parser.cpp"
    break;

  case 239: /* array_index: operand '[' int_literal ']'  */
#line 1000 "bison_parser.y"
                                          { (yyval.expr) = Expr::makeArrayIndex((yyvsp[-3].expr), (yyvsp[-1].expr)->ival); }
#line 4807 "bison_parser.cpp"
    break;

  case 240: /* between_expr: operand BETWEEN operand AND operand  */
#line 1002 "bison_parser.y"
                                                   { (yyval.expr) = Expr::makeBetween((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4813 "bison_parser.cpp"
    break;

  case 241: /* column_name: IDENTIFIER  */
#line 1004 "bison_parser.y"
                         { (yyval.expr) = Expr::makeColumnRef((yyvsp[0].sval)); }
#line 4819 "bison_parser.cpp"
    break;

  case 242: /* column_name: IDENTIFIER '.' IDENTIFIER  */
#line 1005 "bison_parser.y"
                            { (yyval.expr) = Expr::makeColumnRef((yyvsp[-2].sval), (yyvsp[0].sval)); }
#line 4825 "bison_parser.cpp"
    break;

  case 243: /* column_name: '*'  */
#line 1006 "bison_parser.y"
      { (yyval.expr) = Expr::makeStar(); }
#line 4831 "bison_parser.cpp"
    break;

  case 244: /* column_name: IDENTIFIER '.' '*'  */
#line 1007 "bison_parser.y"
                     { (yyval.expr) = Expr::makeStar((yyvsp[-2].sval)); }
#line 4837 "bison_parser.cpp"
    break;

  case 252: /* string_literal: STRING  */
#line 1011 "bison_parser.y"
                        { (yyval.expr) = Expr::makeLiteral((yyvsp[0].sval)); }
#line 4843 "bison_parser.cpp"
    break;

  case 253: /* bool_literal: TRUE  */
#line 1013 "bison_parser.y"
                    { (yyval.expr) = Expr::makeLiteral(true); }
#line 4849 "bison_parser.cpp"
    break;

  case 254: /* bool_literal: FALSE  */
#line 1014 "bison_parser.y"
        { (yyval.expr) = Expr::makeLiteral(false); }
#line 4855 "bison_parser.cpp"
    break;

  case 255: /* num_literal: FLOATVAL  */
#line 1016 "bison_parser.y"
                       { (yyval.expr) = Expr::makeLiteral((yyvsp[0].fval)); }
#line 4861 "bison_parser.cpp"
    break;

  case 257: /* int_literal: INTVAL  */
#line 1019 "bison_parser.y"
                     { (yyval.expr) = Expr::makeLiteral((yyvsp[0].ival)); }
#line 4867 "bison_parser.cpp"
    break;

  case 258: /* null_literal: NULL  */
#line 1021 "bison_parser.y"
                    { (yyval.expr) = Expr::makeNullLiteral(); }
#line 4873 "bison_parser.cpp"
    break;

  case 259: /* date_literal: DATE STRING  */
#line 1023 "bison_parser.y"
                           {
  int day{0}, month{0}, year{0}, chars_parsed{0};
  // If the whole string is parsed, chars_parsed points to the terminating null byte after the last character
  if (sscanf((yyvsp[0].sval), "%4d-%2d-%2d%n", &day, &month, &year, &chars_parsed) != 3 || (yyvsp[0].sval)[chars_parsed] != 0) {
    free((yyvsp[0].sval));
    yyerror(&yyloc, result, scanner, "Found incorrect date format. Expected format: YYYY-MM-DD");
    YYERROR;
  }
  (yyval.expr) = Expr::makeDateLiteral((yyvsp[0].sval));
}
#line 4888 "bison_parser.cpp"
    break;

  case 260: /* interval_literal: int_literal duration_field  */
#line 1034 "bison_parser.y"
                                              {
  (yyval.expr) = Expr::makeIntervalLiteral((yyvsp[-1].expr)->ival, (yyvsp[0].datetime_field));
  delete (yyvsp[-1].expr);
}
#line 4897 "bison_parser.cpp"
    break;

  case 261: /* interval_literal: INTERVAL STRING datetime_field  */
#line 1038 "bison_parser.y"
                                 {
  int duration{0}, chars_parsed{0};
  // If the whole string is parsed, chars_parsed points to the terminating null byte after the last character
  if (sscanf((yyvsp[-1].sval), "%d%n", &duration, &chars_parsed) != 1 || (yyvsp[-1].sval)[chars_parsed] != 0) {
    free((yyvsp[-1].sval));
    yyerror(&yyloc, result, scanner, "Found incorrect interval format. Expected format: INTEGER");
    YYERROR;
  }
  free((yyvsp[-1].sval));
  (yyval.expr) = Expr::makeIntervalLiteral(duration, (yyvsp[0].datetime_field));
}
#line 4913 "bison_parser.cpp"
    break;

  case 262: /* interval_literal: INTERVAL STRING  */
#line 1049 "bison_parser.y"
                  {
  int duration{0}, chars_parsed{0};
  // 'seconds' and 'minutes' are the longest accepted interval qualifiers (7 chars) + null byte
  char unit_string[8];
  // If the whole string is parsed, chars_parsed points to the terminating null byte after the last character
  if (sscanf((yyvsp[0].sval), "%d %7s%n", &duration, unit_string, &chars_parsed) != 2 || (yyvsp[0].sval)[chars_parsed] != 0) {
    free((yyvsp[0].sval));
    yyerror(&yyloc, result, scanner, "Found incorrect interval format. Expected format: INTEGER INTERVAL_QUALIIFIER");
    YYERROR;
  }
  free((yyvsp[0].sval));

  DatetimeField unit;
  if (strcasecmp(unit_string, "second") == 0 || strcasecmp(unit_string, "seconds") == 0) {
    unit = kDatetimeSecond;
  } else if (strcasecmp(unit_string, "minute") == 0 || strcasecmp(unit_string, "minutes") == 0) {
    unit = kDatetimeMinute;
  } else if (strcasecmp(unit_string, "hour") == 0 || strcasecmp(unit_string, "hours") == 0) {
    unit = kDatetimeHour;
  } else if (strcasecmp(unit_string, "day") == 0 || strcasecmp(unit_string, "days") == 0) {
    unit = kDatetimeDay;
  } else if (strcasecmp(unit_string, "month") == 0 || strcasecmp(unit_string, "months") == 0) {
    unit = kDatetimeMonth;
  } else if (strcasecmp(unit_string, "year") == 0 || strcasecmp(unit_string, "years") == 0) {
    unit = kDatetimeYear;
  } else {
    yyerror(&yyloc, result, scanner, "Interval qualifier is unknown.");
    YYERROR;
  }
  (yyval.expr) = Expr::makeIntervalLiteral(duration, unit);
}
#line 4949 "bison_parser.cpp"
    break;

  case 263: /* param_expr: '?'  */
#line 1081 "bison_parser.y"
                 {
  (yyval.expr) = Expr::makeParameter(yylloc.total_column);
  (yyval.expr)->ival2 = yyloc.param_list.size();
  yyloc.param_list.push_back((yyval.expr));
}
#line 4959 "bison_parser.cpp"
    break;

  case 265: /* table_ref: table_ref_commalist ',' table_ref_atomic  */
#line 1090 "bison_parser.y"
                                                                        {
  (yyvsp[-2].table_vec)->push_back((yyvsp[0].table));
  auto tbl = new TableRef(kTableCrossProduct);
  tbl->list = (yyvsp[-2].table_vec);
  (yyval.table) = tbl;
}
#line 4970 "bison_parser.cpp"
    break;

  case 269: /* nonjoin_table_ref_atomic: '(' select_statement ')' opt_table_alias  */
#line 1099 "bison_parser.y"
                                                                                     {
  auto tbl = new TableRef(kTableSelect);
  tbl->select = (yyvsp[-2].select_stmt);
  tbl->alias = (yyvsp[0].alias_t);
  (yyval.table) = tbl;
}
#line 4981 "bison_parser.cpp"
    break;

  case 270: /* table_ref_commalist: table_ref_atomic  */
#line 1106 "bison_parser.y"
                                       {
  (yyval.table_vec) = new std::vector<TableRef*>();
  (yyval.table_vec)->push_back((yyvsp[0].table));
}
#line 4990 "bison_parser.cpp"
    break;

  case 271: /* table_ref_commalist: table_ref_commalist ',' table_ref_atomic  */
#line 1110 "bison_parser.y"
                                           {
  (yyvsp[-2].table_vec)->push_back((yyvsp[0].table));
  (yyval.table_vec) = (yyvsp[-2].table_vec);
}
#line 4999 "bison_parser.cpp"
    break;

  case 272: /* table_ref_name: table_name opt_table_alias  */
#line 1115 "bison_parser.y"
                                            {
  auto tbl = new TableRef(kTableName);
  tbl->schema = (yyvsp[-1].table_name).schema;
  tbl->name = (yyvsp[-1].table_name).name;
  tbl->alias = (yyvsp[0].alias_t);
  (yyval.table) = tbl;
}
#line 5011 "bison_parser.cpp"
    break;

  case 273: /* table_ref_name_no_alias: table_name  */
#line 1123 "bison_parser.y"
                                     {
  (yyval.table) = new TableRef(kTableName);
  (yyval.table)->schema = (yyvsp[0].table_name).schema;
  (yyval.table)->name = (yyvsp[0].table_name).name;
}
#line 5021 "bison_parser.cpp"
    break;

  case 274: /* table_name: IDENTIFIER  */
#line 1129 "bison_parser.y"
                        {
  (yyval.table_name).schema = nullptr;
  (yyval.table_name).name = (yyvsp[0].sval);
}
#line 5030 "bison_parser.cpp"
    break;

  case 275: /* table_name: IDENTIFIER '.' IDENTIFIER  */
#line 1133 "bison_parser.y"
                            {
  (yyval.table_name).schema = (yyvsp[-2].sval);
  (yyval.table_name).name = (yyvsp[0].sval);
}
#line 5039 "bison_parser.cpp"
    break;

  case 276: /* opt_index_name: IDENTIFIER  */
#line 1138 "bison_parser.y"
                            { (yyval.sval) = (yyvsp[0].sval); }
#line 5045 "bison_parser.cpp"
    break;

  case 277: /* opt_index_name: %empty  */
#line 1139 "bison_parser.y"
              { (yyval.sval) = nullptr; }
#line 5051 "bison_parser.cpp"
    break;

  case 279: /* table_alias: AS IDENTIFIER '(' ident_commalist ')'  */
#line 1141 "bison_parser.y"
                                                            { (yyval.alias_t) = new Alias((yyvsp[-3].sval), (yyvsp[-1].str_vec)); }
#line 5057 "bison_parser.cpp"
    break;

  case 281: /* opt_table_alias: %empty  */
#line 1143 "bison_parser.y"
                                            { (yyval.alias_t) = nullptr; }
#line 5063 "bison_parser.cpp"
    break;

  case 282: /* alias: AS IDENTIFIER  */
#line 1145 "bison_parser.y"
                      { (yyval.alias_t) = new Alias((yyvsp[0].sval)); }
#line 5069 "bison_parser.cpp"
    break;

  case 283: /* alias: IDENTIFIER  */
#line 1146 "bison_parser.y"
             { (yyval.alias_t) = new Alias((yyvsp[0].sval)); }
#line 5075 "bison_parser.cpp"
    break;

  case 285: /* opt_alias: %empty  */
#line 1148 "bison_parser.y"
                                { (yyval.alias_t) = nullptr; }
#line 5081 "bison_parser.cpp"
    break;

  case 286: /* opt_locking_clause: opt_locking_clause_list  */
#line 1154 "bison_parser.y"
                                             { (yyval.locking_clause_vec) = (yyvsp[0].locking_clause_vec); }
#line 5087 "bison_parser.cpp"
    break;

  case 287: /* opt_locking_clause: %empty  */
#line 1155 "bison_parser.y"
              { (yyval.locking_clause_vec) = nullptr; }
#line 5093 "bison_parser.cpp"
    break;

  case 288: /* opt_locking_clause_list: locking_clause  */
#line 1157 "bison_parser.y"
                                         {
  (yyval.locking_clause_vec) = new std::vector<LockingClause*>();
  (yyval.locking_clause_vec)->push_back((yyvsp[0].locking_t));
}
#line 5102 "bison_parser.cpp"
    break;

  case 289: /* opt_locking_clause_list: opt_locking_clause_list locking_clause  */
#line 1161 "bison_parser.y"
                                         {
  (yyvsp[-1].locking_clause_vec)->push_back((yyvsp[0].locking_t));
  (yyval.locking_clause_vec) = (yyvsp[-1].locking_clause_vec);
}
#line 5111 "bison_parser.cpp"
    break;

  case 290: /* locking_clause: FOR row_lock_mode opt_row_lock_policy  */
#line 1166 "bison_parser.y"
                                                       {
  (yyval.locking_t) = new LockingClause();
  (yyval.locking_t)->rowLockMode = (yyvsp[-1].lock_mode_t);
  (yyval.locking_t)->rowLockWaitPolicy = (yyvsp[0].lock_wait_policy_t);
  (yyval.locking_t)->tables = nullptr;
}
#line 5122 "bison_parser.cpp"
    break;

  case 291: /* locking_clause: FOR row_lock_mode OF ident_commalist opt_row_lock_policy  */
#line 1172 "bison_parser.y"
                                                           {
  (yyval.locking_t) = new LockingClause();
  (yyval.locking_t)->rowLockMode = (yyvsp[-3].lock_mode_t);
  (yyval.locking_t)->tables = (yyvsp[-1].str_vec);
  (yyval.locking_t)->rowLockWaitPolicy = (yyvsp[0].lock_wait_policy_t);
}
#line 5133 "bison_parser.cpp"
    break;

  case 292: /* row_lock_mode: UPDATE  */
#line 1179 "bison_parser.y"
                       { (yyval.lock_mode_t) = RowLockMode::ForUpdate; }
#line 5139 "bison_parser.cpp"
    break;

  case 293: /* row_lock_mode: NO KEY UPDATE  */
#line 1180 "bison_parser.y"
                { (yyval.lock_mode_t) = RowLockMode::ForNoKeyUpdate; }
#line 5145 "bison_parser.cpp"
    break;

  case 294: /* row_lock_mode: SHARE  */
#line 1181 "bison_parser.y"
        { (yyval.lock_mode_t) = RowLockMode::ForShare; }
#line 5151 "bison_parser.cpp"
    break;

  case 295: /* row_lock_mode: KEY SHARE  */
#line 1182 "bison_parser.y"
            { (yyval.lock_mode_t) = RowLockMode::ForKeyShare; }
#line 5157 "bison_parser.cpp"
    break;

  case 296: /* opt_row_lock_policy: SKIP LOCKED  */
#line 1184 "bison_parser.y"
                                  { (yyval.lock_wait_policy_t) = RowLockWaitPolicy::SkipLocked; }
#line 5163 "bison_parser.cpp"
    break;

  case 297: /* opt_row_lock_policy: NOWAIT  */
#line 1185 "bison_parser.y"
         { (yyval.lock_wait_policy_t) = RowLockWaitPolicy::NoWait; }
#line 5169 "bison_parser.cpp"
    break;

  case 298: /* opt_row_lock_policy: %empty  */
#line 1186 "bison_parser.y"
              { (yyval.lock_wait_policy_t) = RowLockWaitPolicy::None; }
#line 5175 "bison_parser.cpp"
    break;

  case 300: /* opt_with_clause: %empty  */
#line 1192 "bison_parser.y"
                                            { (yyval.with_description_vec) = nullptr; }
#line 5181 "bison_parser.cpp"
    break;

  case 301: /* with_clause: WITH with_description_list  */
#line 1194 "bison_parser.y"
                                         { (yyval.with_description_vec) = (yyvsp[0].with_description_vec); }
#line 5187 "bison_parser.cpp"
    break;

  case 302: /* with_description_list: with_description  */
#line 1196 "bison_parser.y"
                                         {
  (yyval.with_description_vec) = new std::vector<WithDescription*>();
  (yyval.with_description_vec)->push_back((yyvsp[0].with_description_t));
}
#line 5196 "bison_parser.cpp"
    break;

  case 303: /* with_description_list: with_description_list ',' with_description  */
#line 1200 "bison_parser.y"
                                             {
  (yyvsp[-2].with_description_vec)->push_back((yyvsp[0].with_description_t));
  (yyval.with_description_vec) = (yyvsp[-2].with_description_vec);
}
#line 5205 "bison_parser.cpp"
    break;

  case 304: /* with_description: IDENTIFIER AS select_with_paren  */
#line 1205 "bison_parser.y"
                                                   {
  (yyval.with_description_t) = new WithDescription();
  (yyval.with_description_t)->alias = (yyvsp[-2].sval);
  (yyval.with_description_t)->select = (yyvsp[0].select_stmt);
}
#line 5215 "bison_parser.cpp"
    break;

  case 305: /* join_clause: table_ref_atomic NATURAL JOIN nonjoin_table_ref_atomic  */
#line 1215 "bison_parser.y"
                                                                     {
  (yyval.table) = new TableRef(kTableJoin);
  (yyval.table)->join = new JoinDefinition();
  (yyval.table)->join->type = kJoinNatural;
  (yyval.table)->join->left = (yyvsp[-3].table);
  (yyval.table)->join->right = (yyvsp[0].table);
}
#line 5227 "bison_parser.cpp"
    break;

  case 306: /* join_clause: table_ref_atomic opt_join_type JOIN table_ref_atomic ON join_condition  */
#line 1222 "bison_parser.y"
                                                                         {
  (yyval.table) = new TableRef(kTableJoin);
  (yyval.table)->join = new JoinDefinition();
  (yyval.table)->join->type = (JoinType)(yyvsp[-4].join_type);
  (yyval.table)->join->left = (yyvsp[-5].table);
  (yyval.table)->join->right = (yyvsp[-2].table);
  (yyval.table)->join->condition = (yyvsp[0].expr);
}
#line 5240 "bison_parser.cpp"
    break;

  case 307: /* join_clause: table_ref_atomic opt_join_type JOIN table_ref_atomic USING '(' column_name ')'  */
#line 1230 "bison_parser.y"
                                                                                 {
  (yyval.table) = new TableRef(kTableJoin);
  (yyval.table)->join = new JoinDefinition();
  (yyval.table)->join->type = (JoinType)(yyvsp[-6].join_type);
  (yyval.table)->join->left = (yyvsp[-7].table);
  (yyval.table)->join->right = (yyvsp[-4].table);
  auto left_col = Expr::makeColumnRef(strdup((yyvsp[-1].expr)->name));
  if ((yyvsp[-1].expr)->alias != nullptr) left_col->alias = strdup((yyvsp[-1].expr)->alias);
  if ((yyvsp[-7].table)->getName() != nullptr) left_col->table = strdup((yyvsp[-7].table)->getName());
  auto right_col = Expr::makeColumnRef(strdup((yyvsp[-1].expr)->name));
  if ((yyvsp[-1].expr)->alias != nullptr) right_col->alias = strdup((yyvsp[-1].expr)->alias);
  if ((yyvsp[-4].table)->getName() != nullptr) right_col->table = strdup((yyvsp[-4].table)->getName());
  (yyval.table)->join->condition = Expr::makeOpBinary(left_col, kOpEquals, right_col);
  delete (yyvsp[-1].expr);
}
#line 5260 "bison_parser.cpp"
    break;

  case 308: /* opt_join_type: INNER  */
#line 1246 "bison_parser.y"
                      { (yyval.join_type) = kJoinInner; }
#line 5266 "bison_parser.cpp"
    break;

  case 309: /* opt_join_type: LEFT OUTER  */
#line 1247 "bison_parser.y"
             { (yyval.join_type) = kJoinLeft; }
#line 5272 "bison_parser.cpp"
    break;

  case 310: /* opt_join_type: LEFT  */
#line 1248 "bison_parser.y"
       { (yyval.join_type) = kJoinLeft; }
#line 5278 "bison_parser.cpp"
    break;

  case 311: /* opt_join_type: RIGHT OUTER  */
#line 1249 "bison_parser.y"
              { (yyval.join_type) = kJoinRight; }
#line 5284 "bison_parser.cpp"
    break;

  case 312: /* opt_join_type: RIGHT  */
#line 1250 "bison_parser.y"
        { (yyval.join_type) = kJoinRight; }
#line 5290 "bison_parser.cpp"
    break;

  case 313: /* opt_join_type: FULL OUTER  */
#line 1251 "bison_parser.y"
             { (yyval.join_type) = kJoinFull; }
#line 5296 "bison_parser.cpp"
    break;

  case 314: /* opt_join_type: OUTER  */
#line 1252 "bison_parser.y"
        { (yyval.join_type) = kJoinFull; }
#line 5302 "bison_parser.cpp"
    break;

  case 315: /* opt_join_type: FULL  */
#line 1253 "bison_parser.y"
       { (yyval.join_type) = kJoinFull; }
#line 5308 "bison_parser.cpp"
    break;

  case 316: /* opt_join_type: CROSS  */
#line 1254 "bison_parser.y"
        { (yyval.join_type) = kJoinCross; }
#line 5314 "bison_parser.cpp"
    break;

  case 317: /* opt_join_type: %empty  */
#line 1255 "bison_parser.y"
                       { (yyval.join_type) = kJoinInner; }
#line 5320 "bison_parser.cpp"
    break;

  case 321: /* ident_commalist: IDENTIFIER  */
#line 1266 "bison_parser.y"
                             {
  (yyval.str_vec) = new std::vector<char*>();
  (yyval.str_vec)->push_back((yyvsp[0].sval));
}
#line 5329 "bison_parser.cpp"
    break;

  case 322: /* ident_commalist: ident_commalist ',' IDENTIFIER  */
#line 1270 "bison_parser.y"
                                 {
  (yyvsp[-2].str_vec)->push_back((yyvsp[0].sval));
  (yyval.str_vec) = (yyvsp[-2].str_vec);
}
#line 5338 "bison_parser.cpp"
    break;


#line 5342 "bison_parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == SQL_HSQL_EMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (&yylloc, result, scanner, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= SQL_YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == SQL_YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, result, scanner);
          yychar = SQL_HSQL_EMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, result, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, result, scanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != SQL_HSQL_EMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, result, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, result, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1276 "bison_parser.y"

    // clang-format on
    /*********************************
 ** Section 4: Additional C code
 *********************************/

    /* empty */
