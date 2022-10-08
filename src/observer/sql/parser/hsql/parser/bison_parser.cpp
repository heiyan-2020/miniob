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
  YYSYMBOL_HELP = 162,                     /* HELP  */
  YYSYMBOL_SYNC = 163,                     /* SYNC  */
  YYSYMBOL_164_ = 164,                     /* '='  */
  YYSYMBOL_EQUALS = 165,                   /* EQUALS  */
  YYSYMBOL_NOTEQUALS = 166,                /* NOTEQUALS  */
  YYSYMBOL_167_ = 167,                     /* '<'  */
  YYSYMBOL_168_ = 168,                     /* '>'  */
  YYSYMBOL_LESS = 169,                     /* LESS  */
  YYSYMBOL_GREATER = 170,                  /* GREATER  */
  YYSYMBOL_LESSEQ = 171,                   /* LESSEQ  */
  YYSYMBOL_GREATEREQ = 172,                /* GREATEREQ  */
  YYSYMBOL_NOTNULL = 173,                  /* NOTNULL  */
  YYSYMBOL_174_ = 174,                     /* '+'  */
  YYSYMBOL_175_ = 175,                     /* '-'  */
  YYSYMBOL_176_ = 176,                     /* '*'  */
  YYSYMBOL_177_ = 177,                     /* '/'  */
  YYSYMBOL_178_ = 178,                     /* '%'  */
  YYSYMBOL_179_ = 179,                     /* '^'  */
  YYSYMBOL_UMINUS = 180,                   /* UMINUS  */
  YYSYMBOL_181_ = 181,                     /* '['  */
  YYSYMBOL_182_ = 182,                     /* ']'  */
  YYSYMBOL_183_ = 183,                     /* '('  */
  YYSYMBOL_184_ = 184,                     /* ')'  */
  YYSYMBOL_185_ = 185,                     /* '.'  */
  YYSYMBOL_186_ = 186,                     /* ';'  */
  YYSYMBOL_187_ = 187,                     /* ','  */
  YYSYMBOL_188_ = 188,                     /* '?'  */
  YYSYMBOL_YYACCEPT = 189,                 /* $accept  */
  YYSYMBOL_input = 190,                    /* input  */
  YYSYMBOL_statement_list = 191,           /* statement_list  */
  YYSYMBOL_statement = 192,                /* statement  */
  YYSYMBOL_preparable_statement = 193,     /* preparable_statement  */
  YYSYMBOL_opt_hints = 194,                /* opt_hints  */
  YYSYMBOL_hint_list = 195,                /* hint_list  */
  YYSYMBOL_hint = 196,                     /* hint  */
  YYSYMBOL_transaction_statement = 197,    /* transaction_statement  */
  YYSYMBOL_opt_transaction_keyword = 198,  /* opt_transaction_keyword  */
  YYSYMBOL_other_statement = 199,          /* other_statement  */
  YYSYMBOL_prepare_statement = 200,        /* prepare_statement  */
  YYSYMBOL_prepare_target_query = 201,     /* prepare_target_query  */
  YYSYMBOL_execute_statement = 202,        /* execute_statement  */
  YYSYMBOL_import_statement = 203,         /* import_statement  */
  YYSYMBOL_file_type = 204,                /* file_type  */
  YYSYMBOL_file_path = 205,                /* file_path  */
  YYSYMBOL_opt_file_type = 206,            /* opt_file_type  */
  YYSYMBOL_export_statement = 207,         /* export_statement  */
  YYSYMBOL_show_statement = 208,           /* show_statement  */
  YYSYMBOL_create_statement = 209,         /* create_statement  */
  YYSYMBOL_opt_not_exists = 210,           /* opt_not_exists  */
  YYSYMBOL_opt_unique = 211,               /* opt_unique  */
  YYSYMBOL_table_elem_commalist = 212,     /* table_elem_commalist  */
  YYSYMBOL_table_elem = 213,               /* table_elem  */
  YYSYMBOL_column_def = 214,               /* column_def  */
  YYSYMBOL_column_type = 215,              /* column_type  */
  YYSYMBOL_opt_time_precision = 216,       /* opt_time_precision  */
  YYSYMBOL_opt_decimal_specification = 217, /* opt_decimal_specification  */
  YYSYMBOL_opt_column_constraints = 218,   /* opt_column_constraints  */
  YYSYMBOL_column_constraint_set = 219,    /* column_constraint_set  */
  YYSYMBOL_column_constraint = 220,        /* column_constraint  */
  YYSYMBOL_table_constraint = 221,         /* table_constraint  */
  YYSYMBOL_drop_statement = 222,           /* drop_statement  */
  YYSYMBOL_opt_exists = 223,               /* opt_exists  */
  YYSYMBOL_alter_statement = 224,          /* alter_statement  */
  YYSYMBOL_alter_action = 225,             /* alter_action  */
  YYSYMBOL_drop_action = 226,              /* drop_action  */
  YYSYMBOL_delete_statement = 227,         /* delete_statement  */
  YYSYMBOL_truncate_statement = 228,       /* truncate_statement  */
  YYSYMBOL_insert_statement = 229,         /* insert_statement  */
  YYSYMBOL_opt_column_list = 230,          /* opt_column_list  */
  YYSYMBOL_update_statement = 231,         /* update_statement  */
  YYSYMBOL_update_clause_commalist = 232,  /* update_clause_commalist  */
  YYSYMBOL_update_clause = 233,            /* update_clause  */
  YYSYMBOL_select_statement = 234,         /* select_statement  */
  YYSYMBOL_select_within_set_operation = 235, /* select_within_set_operation  */
  YYSYMBOL_select_within_set_operation_no_parentheses = 236, /* select_within_set_operation_no_parentheses  */
  YYSYMBOL_select_with_paren = 237,        /* select_with_paren  */
  YYSYMBOL_select_no_paren = 238,          /* select_no_paren  */
  YYSYMBOL_set_operator = 239,             /* set_operator  */
  YYSYMBOL_set_type = 240,                 /* set_type  */
  YYSYMBOL_opt_all = 241,                  /* opt_all  */
  YYSYMBOL_select_clause = 242,            /* select_clause  */
  YYSYMBOL_opt_distinct = 243,             /* opt_distinct  */
  YYSYMBOL_select_list = 244,              /* select_list  */
  YYSYMBOL_opt_from_clause = 245,          /* opt_from_clause  */
  YYSYMBOL_from_clause = 246,              /* from_clause  */
  YYSYMBOL_opt_where = 247,                /* opt_where  */
  YYSYMBOL_opt_group = 248,                /* opt_group  */
  YYSYMBOL_opt_having = 249,               /* opt_having  */
  YYSYMBOL_opt_order = 250,                /* opt_order  */
  YYSYMBOL_order_list = 251,               /* order_list  */
  YYSYMBOL_order_desc = 252,               /* order_desc  */
  YYSYMBOL_opt_order_type = 253,           /* opt_order_type  */
  YYSYMBOL_opt_top = 254,                  /* opt_top  */
  YYSYMBOL_opt_limit = 255,                /* opt_limit  */
  YYSYMBOL_expr_list = 256,                /* expr_list  */
  YYSYMBOL_opt_literal_list = 257,         /* opt_literal_list  */
  YYSYMBOL_list_of_list = 258,             /* list_of_list  */
  YYSYMBOL_list_item = 259,                /* list_item  */
  YYSYMBOL_literal_list = 260,             /* literal_list  */
  YYSYMBOL_expr_alias = 261,               /* expr_alias  */
  YYSYMBOL_expr = 262,                     /* expr  */
  YYSYMBOL_operand = 263,                  /* operand  */
  YYSYMBOL_scalar_expr = 264,              /* scalar_expr  */
  YYSYMBOL_unary_expr = 265,               /* unary_expr  */
  YYSYMBOL_binary_expr = 266,              /* binary_expr  */
  YYSYMBOL_logic_expr = 267,               /* logic_expr  */
  YYSYMBOL_in_expr = 268,                  /* in_expr  */
  YYSYMBOL_case_expr = 269,                /* case_expr  */
  YYSYMBOL_case_list = 270,                /* case_list  */
  YYSYMBOL_exists_expr = 271,              /* exists_expr  */
  YYSYMBOL_comp_expr = 272,                /* comp_expr  */
  YYSYMBOL_function_expr = 273,            /* function_expr  */
  YYSYMBOL_extract_expr = 274,             /* extract_expr  */
  YYSYMBOL_cast_expr = 275,                /* cast_expr  */
  YYSYMBOL_datetime_field = 276,           /* datetime_field  */
  YYSYMBOL_datetime_field_plural = 277,    /* datetime_field_plural  */
  YYSYMBOL_duration_field = 278,           /* duration_field  */
  YYSYMBOL_array_expr = 279,               /* array_expr  */
  YYSYMBOL_array_index = 280,              /* array_index  */
  YYSYMBOL_between_expr = 281,             /* between_expr  */
  YYSYMBOL_column_name = 282,              /* column_name  */
  YYSYMBOL_literal = 283,                  /* literal  */
  YYSYMBOL_string_literal = 284,           /* string_literal  */
  YYSYMBOL_bool_literal = 285,             /* bool_literal  */
  YYSYMBOL_num_literal = 286,              /* num_literal  */
  YYSYMBOL_int_literal = 287,              /* int_literal  */
  YYSYMBOL_null_literal = 288,             /* null_literal  */
  YYSYMBOL_date_literal = 289,             /* date_literal  */
  YYSYMBOL_interval_literal = 290,         /* interval_literal  */
  YYSYMBOL_param_expr = 291,               /* param_expr  */
  YYSYMBOL_table_ref = 292,                /* table_ref  */
  YYSYMBOL_table_ref_atomic = 293,         /* table_ref_atomic  */
  YYSYMBOL_nonjoin_table_ref_atomic = 294, /* nonjoin_table_ref_atomic  */
  YYSYMBOL_table_ref_commalist = 295,      /* table_ref_commalist  */
  YYSYMBOL_table_ref_name = 296,           /* table_ref_name  */
  YYSYMBOL_table_ref_name_no_alias = 297,  /* table_ref_name_no_alias  */
  YYSYMBOL_table_name = 298,               /* table_name  */
  YYSYMBOL_opt_index_name = 299,           /* opt_index_name  */
  YYSYMBOL_table_alias = 300,              /* table_alias  */
  YYSYMBOL_opt_table_alias = 301,          /* opt_table_alias  */
  YYSYMBOL_alias = 302,                    /* alias  */
  YYSYMBOL_opt_alias = 303,                /* opt_alias  */
  YYSYMBOL_opt_locking_clause = 304,       /* opt_locking_clause  */
  YYSYMBOL_opt_locking_clause_list = 305,  /* opt_locking_clause_list  */
  YYSYMBOL_locking_clause = 306,           /* locking_clause  */
  YYSYMBOL_row_lock_mode = 307,            /* row_lock_mode  */
  YYSYMBOL_opt_row_lock_policy = 308,      /* opt_row_lock_policy  */
  YYSYMBOL_opt_with_clause = 309,          /* opt_with_clause  */
  YYSYMBOL_with_clause = 310,              /* with_clause  */
  YYSYMBOL_with_description_list = 311,    /* with_description_list  */
  YYSYMBOL_with_description = 312,         /* with_description  */
  YYSYMBOL_join_clause = 313,              /* join_clause  */
  YYSYMBOL_opt_join_type = 314,            /* opt_join_type  */
  YYSYMBOL_join_condition = 315,           /* join_condition  */
  YYSYMBOL_opt_semicolon = 316,            /* opt_semicolon  */
  YYSYMBOL_ident_commalist = 317           /* ident_commalist  */
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
#define YYFINAL  73
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   859

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  189
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  129
/* YYNRULES -- Number of rules.  */
#define YYNRULES  328
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  584

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   426


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
       2,     2,     2,     2,     2,     2,     2,   178,     2,     2,
     183,   184,   176,   174,   187,   175,   185,   177,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   186,
     167,   164,   168,   188,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   181,     2,   182,   179,     2,     2,     2,     2,     2,
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
     155,   156,   157,   158,   159,   160,   161,   162,   163,   165,
     166,   169,   170,   171,   172,   173,   180
};

#if HSQL_DEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   309,   309,   328,   334,   341,   345,   349,   350,   351,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   369,   370,   372,   376,   381,   385,   395,   396,   397,
     399,   399,   406,   407,   412,   418,   420,   424,   435,   441,
     448,   463,   468,   469,   475,   487,   488,   493,   498,   509,
     522,   534,   541,   549,   558,   559,   561,   562,   564,   568,
     573,   574,   576,   583,   584,   585,   586,   587,   588,   589,
     593,   594,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   605,   606,   608,   609,   610,   612,   613,   615,   619,
     624,   625,   626,   627,   629,   630,   638,   644,   650,   656,
     662,   663,   670,   676,   678,   688,   695,   706,   713,   721,
     722,   729,   736,   740,   745,   755,   759,   763,   775,   775,
     777,   778,   787,   788,   790,   804,   816,   821,   825,   829,
     834,   835,   837,   847,   848,   850,   852,   853,   855,   857,
     858,   860,   865,   867,   868,   870,   871,   873,   877,   882,
     884,   885,   886,   890,   891,   893,   894,   895,   896,   897,
     898,   903,   907,   912,   913,   915,   919,   924,   928,   932,
     937,   945,   945,   945,   945,   945,   947,   948,   948,   948,
     948,   948,   948,   948,   948,   949,   949,   953,   953,   955,
     956,   957,   958,   959,   961,   961,   962,   963,   964,   965,
     966,   967,   968,   969,   970,   972,   973,   975,   976,   977,
     978,   982,   983,   984,   985,   987,   988,   990,   991,   993,
     994,   995,   996,   997,   998,   999,  1001,  1002,  1004,  1006,
    1008,  1009,  1010,  1011,  1012,  1013,  1015,  1016,  1017,  1018,
    1019,  1020,  1022,  1022,  1024,  1026,  1028,  1030,  1031,  1032,
    1033,  1035,  1035,  1035,  1035,  1035,  1035,  1035,  1037,  1039,
    1040,  1042,  1043,  1045,  1047,  1049,  1060,  1064,  1075,  1107,
    1116,  1116,  1123,  1123,  1125,  1125,  1132,  1136,  1141,  1149,
    1155,  1159,  1164,  1165,  1167,  1167,  1169,  1169,  1171,  1172,
    1174,  1174,  1180,  1181,  1183,  1187,  1192,  1198,  1205,  1206,
    1207,  1208,  1210,  1211,  1212,  1218,  1218,  1220,  1222,  1226,
    1231,  1241,  1248,  1256,  1272,  1273,  1274,  1275,  1276,  1277,
    1278,  1279,  1280,  1281,  1283,  1289,  1289,  1292,  1296
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
  "HELP", "SYNC", "'='", "EQUALS", "NOTEQUALS", "'<'", "'>'", "LESS",
  "GREATER", "LESSEQ", "GREATEREQ", "NOTNULL", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'^'", "UMINUS", "'['", "']'", "'('", "')'", "'.'", "';'", "','",
  "'?'", "$accept", "input", "statement_list", "statement",
  "preparable_statement", "opt_hints", "hint_list", "hint",
  "transaction_statement", "opt_transaction_keyword", "other_statement",
  "prepare_statement", "prepare_target_query", "execute_statement",
  "import_statement", "file_type", "file_path", "opt_file_type",
  "export_statement", "show_statement", "create_statement",
  "opt_not_exists", "opt_unique", "table_elem_commalist", "table_elem",
  "column_def", "column_type", "opt_time_precision",
  "opt_decimal_specification", "opt_column_constraints",
  "column_constraint_set", "column_constraint", "table_constraint",
  "drop_statement", "opt_exists", "alter_statement", "alter_action",
  "drop_action", "delete_statement", "truncate_statement",
  "insert_statement", "opt_column_list", "update_statement",
  "update_clause_commalist", "update_clause", "select_statement",
  "select_within_set_operation",
  "select_within_set_operation_no_parentheses", "select_with_paren",
  "select_no_paren", "set_operator", "set_type", "opt_all",
  "select_clause", "opt_distinct", "select_list", "opt_from_clause",
  "from_clause", "opt_where", "opt_group", "opt_having", "opt_order",
  "order_list", "order_desc", "opt_order_type", "opt_top", "opt_limit",
  "expr_list", "opt_literal_list", "list_of_list", "list_item",
  "literal_list", "expr_alias", "expr", "operand", "scalar_expr",
  "unary_expr", "binary_expr", "logic_expr", "in_expr", "case_expr",
  "case_list", "exists_expr", "comp_expr", "function_expr", "extract_expr",
  "cast_expr", "datetime_field", "datetime_field_plural", "duration_field",
  "array_expr", "array_index", "between_expr", "column_name", "literal",
  "string_literal", "bool_literal", "num_literal", "int_literal",
  "null_literal", "date_literal", "interval_literal", "param_expr",
  "table_ref", "table_ref_atomic", "nonjoin_table_ref_atomic",
  "table_ref_commalist", "table_ref_name", "table_ref_name_no_alias",
  "table_name", "opt_index_name", "table_alias", "opt_table_alias",
  "alias", "opt_alias", "opt_locking_clause", "opt_locking_clause_list",
  "locking_clause", "row_lock_mode", "opt_row_lock_policy",
  "opt_with_clause", "with_clause", "with_description_list",
  "with_description", "join_clause", "opt_join_type", "join_condition",
  "opt_semicolon", "ident_commalist", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-359)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-326)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     566,    37,    81,    93,    95,    81,   -22,    60,    92,    64,
      81,   149,    81,    81,   104,    30,   206,    76,    76,    76,
    -359,  -359,   233,    72,  -359,   128,  -359,  -359,   128,  -359,
    -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,   -33,  -359,   276,   101,  -359,   108,   193,  -359,  -359,
     170,   170,   228,    81,   314,    81,   196,  -359,   201,   -59,
    -359,   201,   201,   201,    81,  -359,   205,   147,  -359,  -359,
    -359,  -359,  -359,  -359,   534,  -359,   248,  -359,  -359,   226,
     -33,   150,  -359,   138,  -359,   358,    40,   347,   242,    81,
      81,   170,   288,  -359,   285,   200,   381,   340,    81,   383,
     383,   385,    81,    81,  -359,   207,   206,  -359,   213,   395,
     377,   218,   219,  -359,  -359,  -359,   -33,   291,   286,   -33,
       5,  -359,  -359,  -359,  -359,   407,  -359,   410,  -359,  -359,
    -359,   232,   230,  -359,  -359,  -359,  -359,   710,  -359,  -359,
    -359,  -359,  -359,  -359,   372,   -23,   200,   418,   334,  -359,
     383,   421,   118,   264,   -45,  -359,  -359,   338,   321,  -359,
     321,  -359,  -359,  -359,  -359,  -359,   431,  -359,  -359,   334,
    -359,  -359,   359,  -359,  -359,   150,  -359,  -359,   334,   359,
     334,   160,   317,  -359,   351,  -359,    40,  -359,  -359,  -359,
    -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,  -359,  -359,   439,   333,   178,   324,  -359,   315,  -121,
     268,   269,   270,   132,   352,   273,   362,  -359,   256,   119,
     387,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,  -359,  -359,  -359,  -359,  -359,  -359,   360,  -359,    82,
     274,  -359,   334,   381,  -359,   420,  -359,  -359,   411,  -359,
    -359,   278,    91,  -359,   369,   277,  -359,    24,     5,   -33,
     280,  -359,   -47,     5,   119,   413,    42,    12,  -359,   317,
    -359,  -359,  -359,   378,  -359,   606,   345,   287,   109,  -359,
    -359,  -359,   333,    81,    16,    20,   414,   351,   334,   334,
      56,   121,   292,   362,   615,   334,   216,   290,   -81,   334,
     334,   362,  -359,   362,   -48,   293,   133,   362,   362,   362,
     362,   362,   362,   362,   362,   362,   362,   362,   362,   362,
     362,   362,   395,    81,  -359,   474,    40,   294,  -359,   119,
    -359,   201,   314,    40,  -359,   431,    18,   288,  -359,   334,
    -359,   475,  -359,  -359,  -359,  -359,   334,  -359,  -359,  -359,
     317,   334,   334,  -359,   319,   375,  -359,    63,  -359,   383,
    -359,  -359,   299,  -359,   313,  -359,  -359,   316,  -359,  -359,
     318,  -359,  -359,  -359,  -359,   322,  -359,  -359,    68,   323,
     421,  -359,   178,  -359,   328,  -359,   334,  -359,  -359,   335,
     404,   148,    53,   124,   334,   334,  -359,   414,   399,   107,
    -359,  -359,  -359,   392,   597,   648,   362,   337,   256,  -359,
     417,   344,   648,   648,   648,   648,   666,   666,   666,   666,
     216,   216,  -100,  -100,  -100,   -88,   336,  -359,  -359,   114,
     274,   523,  -359,   122,  -359,   333,  -359,   177,  -359,   342,
    -359,    28,  -359,   460,  -359,  -359,  -359,  -359,   119,   119,
    -359,   468,   421,  -359,   373,  -359,  -359,   526,   530,  -359,
     533,   536,   537,  -359,   424,  -359,  -359,   442,  -359,    68,
    -359,   421,   129,  -359,   421,   134,  -359,   334,   606,   334,
     334,  -359,   -65,    62,   363,  -359,   362,   648,   256,   364,
     139,  -359,  -359,  -359,  -359,  -359,  -359,   386,   458,  -359,
    -359,  -359,   489,   491,   494,   477,    18,   574,  -359,  -359,
    -359,   452,  -359,  -359,    65,  -359,   396,   140,   398,   400,
     401,  -359,  -359,  -359,   162,  -359,   175,  -359,   -78,   405,
     119,   173,  -359,   334,  -359,   615,   406,   185,  -359,  -359,
      28,    18,  -359,  -359,  -359,    18,   275,   408,   334,  -359,
    -359,  -359,   573,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,   119,  -359,  -359,  -359,  -359,   348,   421,   -32,   409,
     412,   334,   192,   334,  -359,  -359,    21,   119,  -359,  -359,
     119,   416,   415,  -359
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     306,     0,     0,     0,     0,     0,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    31,    31,    31,
      32,    33,     0,   326,     3,    22,    19,    20,    22,    18,
       8,     9,     7,    11,    16,    17,    13,    14,    12,    15,
      10,     0,   305,     0,   280,   106,    36,     0,    47,    56,
      55,    55,     0,     0,     0,     0,     0,   279,   101,     0,
      48,   101,   101,   101,     0,    45,     0,   307,   308,    30,
      27,    29,    28,     1,   306,     2,     0,     6,     5,   154,
       0,   115,   116,   146,    98,     0,   164,     0,     0,     0,
       0,    55,   140,    40,     0,   110,     0,     0,     0,     0,
       0,     0,     0,     0,    46,     0,     0,     4,     0,     0,
     134,     0,     0,   128,   129,   127,     0,   131,     0,     0,
     160,   281,   258,   261,   263,     0,   264,     0,   259,   260,
     269,     0,   163,   168,   251,   252,   253,   262,   254,   255,
     256,   257,    35,    34,     0,     0,   110,   283,     0,   105,
       0,     0,     0,     0,   140,   112,   100,     0,    43,    41,
      43,    99,    96,    97,   310,   309,     0,   153,   133,     0,
     123,   122,   146,   119,   118,   120,   130,   126,     0,   146,
       0,     0,   293,   265,   268,    37,     0,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   266,    54,     0,   306,     0,     0,   282,     0,   247,
       0,     0,     0,     0,     0,     0,     0,   249,     0,   139,
     171,   178,   179,   180,   173,   175,   181,   174,   194,   182,
     183,   184,   185,   177,   172,   187,   188,     0,   327,     0,
       0,   108,     0,     0,   111,     0,   102,   103,     0,    39,
      44,    25,     0,    23,   137,   135,   161,   291,   160,     0,
     145,   147,   152,   160,   156,   158,   155,     0,   124,   292,
     294,   267,   169,     0,    51,     0,     0,     0,     0,    58,
      60,    61,   306,     0,   134,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   190,     0,   189,     0,     0,     0,
       0,     0,   191,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   109,     0,     0,   107,   165,   114,
     113,   101,     0,     0,    21,     0,     0,   140,   136,     0,
     289,     0,   290,   170,   117,   121,     0,   151,   150,   149,
     293,     0,     0,   298,     0,     0,   300,   304,   295,     0,
      79,    73,     0,    75,    85,    76,    63,     0,    70,    71,
       0,    67,    68,    74,    77,    82,    72,    64,    87,     0,
       0,    50,     0,    53,     0,   226,     0,   248,   250,     0,
       0,     0,     0,     0,     0,     0,   213,     0,     0,     0,
     186,   176,   205,   206,     0,   201,     0,     0,     0,   192,
       0,   204,   203,   219,   220,   221,   222,   223,   224,   225,
     196,   195,   198,   197,   199,   200,     0,    38,   328,     0,
       0,     0,    42,     0,    24,   306,   138,   270,   272,     0,
     274,   287,   273,   142,   162,   288,   148,   125,   159,   157,
     301,     0,     0,   303,     0,   296,    49,     0,     0,    69,
       0,     0,     0,    78,     0,    91,    92,     0,    62,    86,
      88,     0,     0,    59,     0,     0,   217,     0,     0,     0,
       0,   211,     0,     0,     0,   244,     0,   202,     0,     0,
       0,   193,   245,   167,   166,   104,    26,     0,     0,   322,
     314,   320,   318,   321,   316,     0,     0,     0,   286,   278,
     284,     0,   132,   299,   304,   302,     0,     0,     0,     0,
       0,    90,    93,    89,     0,    95,     0,   227,     0,     0,
     215,     0,   214,     0,   218,   246,     0,     0,   209,   207,
     287,     0,   317,   319,   315,     0,   271,   288,     0,   297,
      66,    84,     0,    80,    65,    81,    94,    52,   228,   229,
     212,   216,   210,   208,   275,   311,   323,     0,   144,     0,
       0,     0,     0,     0,   141,    83,     0,   324,   312,   285,
     143,   247,     0,   313
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -359,  -359,  -359,   509,  -359,   568,  -359,   259,  -359,    54,
    -359,  -359,  -359,  -359,  -359,   266,   -94,   444,  -359,  -359,
    -359,    10,  -359,  -359,   220,  -359,   127,  -359,  -359,  -359,
    -359,   141,  -359,  -359,   -60,  -359,  -359,  -359,  -359,  -359,
    -359,   462,  -359,  -359,   366,  -193,  -101,  -359,     6,   -75,
     -42,  -359,  -359,   -90,   327,  -359,  -359,  -359,  -138,  -359,
    -359,    46,  -359,   267,  -359,  -359,  -176,  -278,  -359,  -359,
     182,  -250,   281,  -148,  -194,  -359,  -359,  -359,  -359,  -359,
    -359,   325,  -359,  -359,  -359,  -359,  -359,  -142,  -359,  -359,
    -359,  -359,  -359,    38,   -76,   -91,  -359,  -359,   -96,  -359,
    -359,  -359,  -359,  -359,  -358,    75,  -359,  -359,  -359,     2,
    -359,  -359,    83,   365,  -359,   283,  -359,   357,  -359,   113,
    -359,  -359,  -359,   522,  -359,  -359,  -359,  -359,  -340
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    22,    23,    24,    25,    77,   252,   253,    26,    70,
      27,    28,   143,    29,    30,    94,   158,   249,    31,    32,
      33,    89,    52,   278,   279,   280,   378,   463,   459,   468,
     469,   470,   281,    34,    98,    35,   246,   247,    36,    37,
      38,   152,    39,   154,   155,    40,   172,   173,   174,    82,
     116,   117,   177,    83,   169,   254,   337,   338,   149,   512,
     574,   120,   260,   261,   349,   110,   182,   255,   131,   327,
     328,   132,   256,   257,   220,   221,   222,   223,   224,   225,
     226,   291,   227,   228,   229,   230,   231,   199,   200,   201,
     232,   233,   234,   235,   236,   134,   135,   136,   137,   138,
     139,   140,   141,   436,   437,   438,   439,   440,    56,   441,
     208,   508,   509,   510,   343,   268,   269,   270,   357,   455,
      41,    42,    67,    68,   442,   505,   578,    75,   239
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     219,   101,   102,   103,    45,   112,   160,    48,   159,   159,
     133,   274,    57,   167,    59,    60,   244,   399,   179,   573,
     294,    44,   296,   387,   581,    79,   175,   340,   168,   175,
     262,   340,   264,   266,   299,    99,   307,   299,   148,    49,
     472,   119,   271,   347,   122,   123,   124,    81,   307,    64,
     299,   300,   532,   406,   300,    92,   237,    95,    50,   159,
     180,    90,   284,    43,   285,   290,   104,   300,   299,   348,
     298,   203,    71,    72,   100,   353,   429,   241,   181,   321,
     407,   322,   344,   433,    44,   300,   111,   350,    51,   383,
      65,   145,   146,   322,   329,   464,    46,   352,    47,   294,
     157,   147,   204,   401,   162,   163,   558,   404,   475,   405,
     272,   164,   514,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   125,   465,
     490,   524,   354,   259,   526,   209,   122,   123,   124,   299,
     391,   392,   243,   297,   126,   390,   355,   113,   546,   341,
      80,   402,   403,   507,    53,   339,   300,   299,   345,   113,
     205,   479,    55,   209,   122,   123,   124,   289,   299,   175,
     533,   299,   466,   356,   300,    61,    79,   299,   210,   211,
     212,   275,   240,   114,    62,   300,    54,   566,   300,   467,
     127,   128,   129,   452,   300,   114,   388,   217,   262,   443,
     385,   435,   498,   448,   449,   276,   210,   211,   212,    66,
     537,   389,   487,   394,    63,   118,   480,   213,   258,   115,
     125,   453,   454,   453,   454,   263,   426,   572,   130,    58,
      69,   115,   395,    73,   299,   395,   126,   409,   396,   277,
      76,   481,   497,   289,   499,   213,   482,   483,   125,   500,
     133,   300,   325,   214,   410,   501,   502,   133,    74,   209,
     122,   123,   124,   299,   126,   456,   324,   215,   159,   325,
     568,   431,   503,   478,   265,   334,  -323,   504,   335,    84,
     300,   214,   127,   128,   129,   384,    85,    87,   299,   485,
     560,    86,   535,   381,   339,   215,   382,    88,   493,    91,
     498,   186,   210,   211,   212,   300,   496,   216,   217,   186,
     127,   128,   129,   525,    79,   218,   325,    93,   527,    96,
     130,   339,   484,   539,   551,   427,   339,   552,    97,   528,
     105,   530,   531,   489,   106,   216,   217,   209,   122,   123,
     124,   213,   499,   218,   125,   108,   556,   500,   130,   325,
     109,   142,   307,   501,   502,   209,   122,   123,   124,   557,
     126,   121,   325,   144,  -276,   209,   122,   123,   124,   563,
     503,   148,   339,   498,  -323,   504,   579,   214,   150,   325,
     210,   211,   212,   151,   153,   561,   156,   122,   161,   168,
      80,   215,   318,   319,   320,   321,   166,   322,   292,   211,
     212,   124,   170,   171,   301,   176,   127,   128,   129,   211,
     212,   183,   178,   536,   184,   499,   185,   186,   202,   213,
     500,   207,   125,   577,   238,   580,   501,   502,   242,   245,
     570,   216,   217,   248,   251,   267,   118,   213,   126,   218,
     125,   302,   273,   503,   130,    16,   283,   213,   504,   282,
     125,   286,   287,   288,   295,   214,   126,   326,   323,   331,
     332,   333,  -277,   336,   339,   379,   126,   346,   351,   215,
     380,   359,    79,   293,   400,   397,   408,   428,   445,   571,
     450,   430,   457,   293,   127,   128,   129,   215,   303,   187,
     188,   189,   190,   191,   192,   451,   458,   215,   477,   460,
     406,   461,   127,   128,   129,   462,   471,   299,   304,   216,
     217,   474,   127,   128,   129,   305,   306,   218,   492,   476,
     488,   491,   130,   307,   308,   322,   495,   216,   217,   506,
     511,   513,   516,   515,  -325,   218,   517,   216,   217,   518,
     130,     1,   519,   520,   521,   218,   522,   534,   538,     2,
     130,   309,   310,   311,   312,   313,     3,   541,   314,   315,
       4,   316,   317,   318,   319,   320,   321,   542,   322,   543,
     540,     5,   544,     1,     6,     7,   545,   547,   548,   569,
     550,     2,   553,   107,   554,   555,     8,     9,     3,   559,
     562,   567,     4,   575,   434,   576,    78,    10,   432,   583,
      11,   285,   473,     5,   250,   529,     6,     7,   206,   330,
     523,   386,   494,   446,   582,   393,   565,   360,     8,     9,
     444,    12,   342,   564,    13,    14,   358,   549,   165,    10,
     361,     0,    11,   447,     0,   362,   363,   364,   365,   366,
      15,   367,     0,     0,     0,     0,    16,     0,     0,   368,
       0,   302,     0,    12,     0,     0,    13,    14,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   302,
       0,     0,    15,     0,     0,   369,     0,     0,    16,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
      18,    19,   370,     0,   371,   372,    20,    21,   303,     0,
       0,     0,   302,     0,     0,     0,     0,     0,     0,   373,
       0,     0,   486,   374,     0,   375,   303,     0,   398,     0,
     302,    17,    18,    19,     0,   376,   306,     0,    20,    21,
       0,     0,     0,   307,   308,     0,   398,     0,     0,     0,
       0,     0,     0,     0,   306,     0,     0,     0,     0,  -326,
       0,   307,   308,     0,     0,     0,     0,     0,     0,   377,
       0,   309,   310,   311,   312,   313,     0,     0,   314,   315,
       0,   316,   317,   318,   319,   320,   321,   306,   322,   309,
     310,   311,   312,   313,   307,  -326,   314,   315,     0,   316,
     317,   318,   319,   320,   321,   306,   322,     0,     0,     0,
       0,     0,   307,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -326,  -326,  -326,   312,   313,     0,     0,   314,
     315,     0,   316,   317,   318,   319,   320,   321,     0,   322,
       0,     0,     0,  -326,  -326,     0,     0,  -326,  -326,     0,
     316,   317,   318,   319,   320,   321,     0,   322,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198
};

static const yytype_int16 yycheck[] =
{
     148,    61,    62,    63,     2,    80,   100,     5,    99,   100,
      86,   204,    10,   109,    12,    13,   154,   295,   119,    51,
     214,     3,   216,     3,     3,    58,   116,     3,    12,   119,
     178,     3,   180,   181,   115,    94,   136,   115,    83,    61,
     380,    83,   184,    90,     4,     5,     6,    41,   136,    19,
     115,   132,   117,   101,   132,    53,   150,    55,    80,   150,
      55,    51,   183,    26,   185,   213,    64,   132,   115,   116,
     218,    94,    18,    19,   133,    63,   326,   152,    73,   179,
     128,   181,   258,   333,     3,   132,    80,   263,   110,   282,
      60,    89,    90,   181,   242,    27,     3,    55,     3,   293,
      98,    91,   125,   184,   102,   103,   184,   301,   386,   303,
     186,   105,   452,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,    88,    61,
     408,   471,   120,   175,   474,     3,     4,     5,     6,   115,
     288,   289,   187,   218,   104,   287,   134,     9,   506,   125,
     183,   299,   300,   125,    94,   187,   132,   115,   259,     9,
     183,   108,    98,     3,     4,     5,     6,   111,   115,   259,
     108,   115,   104,   161,   132,    71,    58,   115,    46,    47,
      48,     3,    64,    45,    80,   132,    94,   545,   132,   121,
     150,   151,   152,   130,   132,    45,   176,   176,   346,   337,
     184,   183,    25,   351,   352,    27,    46,    47,    48,     3,
     488,   286,   406,    92,   110,    77,    92,    85,   172,    81,
      88,   158,   159,   158,   159,   179,   322,   567,   188,    80,
     154,    81,   111,     0,   115,   111,   104,   104,   117,    61,
     112,   117,   435,   111,    67,    85,   394,   395,    88,    72,
     326,   132,   187,   121,   121,    78,    79,   333,   186,     3,
       4,     5,     6,   115,   104,   359,   184,   135,   359,   187,
     548,   331,    95,   125,   114,   184,    99,   100,   187,     3,
     132,   121,   150,   151,   152,   283,   185,    94,   115,   182,
     117,   183,   486,   184,   187,   135,   187,   127,   184,    71,
      25,   187,    46,    47,    48,   132,   184,   175,   176,   187,
     150,   151,   152,   184,    58,   183,   187,     3,   184,   123,
     188,   187,   397,   184,   184,   323,   187,   187,   127,   477,
     125,   479,   480,   408,   187,   175,   176,     3,     4,     5,
       6,    85,    67,   183,    88,    97,   184,    72,   188,   187,
     124,     4,   136,    78,    79,     3,     4,     5,     6,   184,
     104,     3,   187,   121,   187,     3,     4,     5,     6,   184,
      95,    83,   187,    25,    99,   100,   184,   121,    93,   187,
      46,    47,    48,   183,     3,   533,    46,     4,     3,    12,
     183,   135,   176,   177,   178,   179,   183,   181,    46,    47,
      48,     6,   184,   184,    17,   114,   150,   151,   152,    47,
      48,     4,   126,   488,     4,    67,   184,   187,    46,    85,
      72,     3,    88,   571,     3,   573,    78,    79,   164,    91,
      82,   175,   176,   112,     3,   118,    77,    85,   104,   183,
      88,    54,     3,    95,   188,   112,   131,    85,   100,   125,
      88,   183,   183,   183,   181,   121,   104,   183,    98,    39,
      49,   183,   187,    94,   187,   120,   104,   187,    55,   135,
     183,    93,    58,   121,   184,   183,   183,     3,     3,   131,
     161,   187,   183,   121,   150,   151,   152,   135,   101,   138,
     139,   140,   141,   142,   143,   120,   183,   135,    94,   183,
     101,   183,   150,   151,   152,   183,   183,   115,   121,   175,
     176,   183,   150,   151,   152,   128,   129,   183,   182,   184,
     183,   104,   188,   136,   137,   181,     3,   175,   176,   187,
      70,    63,     6,   160,     0,   183,     6,   175,   176,     6,
     188,     7,     6,     6,   120,   183,   104,   184,   184,    15,
     188,   164,   165,   166,   167,   168,    22,    99,   171,   172,
      26,   174,   175,   176,   177,   178,   179,    78,   181,    78,
     184,    37,    78,     7,    40,    41,    99,     3,   126,     6,
     184,    15,   184,    74,   184,   184,    52,    53,    22,   184,
     184,   183,    26,   184,   335,   183,    28,    63,   332,   184,
      66,   185,   382,    37,   160,   478,    40,    41,   146,   243,
     469,   284,   430,   346,   576,   290,   541,    11,    52,    53,
     339,    87,   257,   540,    90,    91,   269,   514,   106,    63,
      24,    -1,    66,   350,    -1,    29,    30,    31,    32,    33,
     106,    35,    -1,    -1,    -1,    -1,   112,    -1,    -1,    43,
      -1,    54,    -1,    87,    -1,    -1,    90,    91,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      -1,    -1,   106,    -1,    -1,    69,    -1,    -1,   112,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,
     156,   157,    86,    -1,    88,    89,   162,   163,   101,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,   103,
      -1,    -1,   115,   107,    -1,   109,   101,    -1,   121,    -1,
      54,   155,   156,   157,    -1,   119,   129,    -1,   162,   163,
      -1,    -1,    -1,   136,   137,    -1,   121,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,   101,
      -1,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,   153,
      -1,   164,   165,   166,   167,   168,    -1,    -1,   171,   172,
      -1,   174,   175,   176,   177,   178,   179,   129,   181,   164,
     165,   166,   167,   168,   136,   137,   171,   172,    -1,   174,
     175,   176,   177,   178,   179,   129,   181,    -1,    -1,    -1,
      -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,   168,    -1,    -1,   171,
     172,    -1,   174,   175,   176,   177,   178,   179,    -1,   181,
      -1,    -1,    -1,   167,   168,    -1,    -1,   171,   172,    -1,
     174,   175,   176,   177,   178,   179,    -1,   181,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     7,    15,    22,    26,    37,    40,    41,    52,    53,
      63,    66,    87,    90,    91,   106,   112,   155,   156,   157,
     162,   163,   190,   191,   192,   193,   197,   199,   200,   202,
     203,   207,   208,   209,   222,   224,   227,   228,   229,   231,
     234,   309,   310,    26,     3,   298,     3,     3,   298,    61,
      80,   110,   211,    94,    94,    98,   297,   298,    80,   298,
     298,    71,    80,   110,    19,    60,     3,   311,   312,   154,
     198,   198,   198,     0,   186,   316,   112,   194,   194,    58,
     183,   237,   238,   242,     3,   185,   183,    94,   127,   210,
     210,    71,   298,     3,   204,   298,   123,   127,   223,    94,
     133,   223,   223,   223,   298,   125,   187,   192,    97,   124,
     254,   237,   238,     9,    45,    81,   239,   240,    77,   239,
     250,     3,     4,     5,     6,    88,   104,   150,   151,   152,
     188,   257,   260,   283,   284,   285,   286,   287,   288,   289,
     290,   291,     4,   201,   121,   298,   298,   210,    83,   247,
      93,   183,   230,     3,   232,   233,    46,   298,   205,   284,
     205,     3,   298,   298,   237,   312,   183,   287,    12,   243,
     184,   184,   235,   236,   237,   242,   114,   241,   126,   235,
      55,    73,   255,     4,     4,   184,   187,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   276,
     277,   278,    46,    94,   125,   183,   230,     3,   299,     3,
      46,    47,    48,    85,   121,   135,   175,   176,   183,   262,
     263,   264,   265,   266,   267,   268,   269,   271,   272,   273,
     274,   275,   279,   280,   281,   282,   283,   205,     3,   317,
      64,   238,   164,   187,   247,    91,   225,   226,   112,   206,
     206,     3,   195,   196,   244,   256,   261,   262,   250,   239,
     251,   252,   262,   250,   262,   114,   262,   118,   304,   305,
     306,   276,   283,     3,   234,     3,    27,    61,   212,   213,
     214,   221,   125,   131,   183,   185,   183,   183,   183,   111,
     262,   270,    46,   121,   263,   181,   263,   238,   262,   115,
     132,    17,    54,   101,   121,   128,   129,   136,   137,   164,
     165,   166,   167,   168,   171,   172,   174,   175,   176,   177,
     178,   179,   181,    98,   184,   187,   183,   258,   259,   262,
     233,    39,    49,   183,   184,   187,    94,   245,   246,   187,
       3,   125,   302,   303,   255,   235,   187,    90,   116,   253,
     255,    55,    55,    63,   120,   134,   161,   307,   306,    93,
      11,    24,    29,    30,    31,    32,    33,    35,    43,    69,
      86,    88,    89,   103,   107,   109,   119,   153,   215,   120,
     183,   184,   187,   234,   298,   184,   243,     3,   176,   238,
     276,   262,   262,   270,    92,   111,   117,   183,   121,   256,
     184,   184,   262,   262,   263,   263,   101,   128,   183,   104,
     121,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   287,   298,     3,   260,
     187,   223,   204,   260,   196,   183,   292,   293,   294,   295,
     296,   298,   313,   247,   261,     3,   252,   304,   262,   262,
     161,   120,   130,   158,   159,   308,   205,   183,   183,   217,
     183,   183,   183,   216,    27,    61,   104,   121,   218,   219,
     220,   183,   317,   213,   183,   256,   184,    94,   125,   108,
      92,   117,   262,   262,   238,   182,   115,   263,   183,   238,
     256,   104,   182,   184,   259,     3,   184,   234,    25,    67,
      72,    78,    79,    95,   100,   314,   187,   125,   300,   301,
     302,    70,   248,    63,   317,   160,     6,     6,     6,     6,
       6,   120,   104,   220,   317,   184,   317,   184,   262,   215,
     262,   262,   117,   108,   184,   263,   238,   256,   184,   184,
     184,    99,    78,    78,    78,    99,   293,     3,   126,   308,
     184,   184,   187,   184,   184,   184,   184,   184,   184,   184,
     117,   262,   184,   184,   301,   294,   293,   183,   256,     6,
      82,   131,   317,    51,   249,   184,   183,   262,   315,   184,
     262,     3,   282,   184
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   189,   190,   191,   191,   192,   192,   192,   192,   192,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   194,   194,   195,   195,   196,   196,   197,   197,   197,
     198,   198,   199,   199,   200,   201,   202,   202,   203,   203,
     204,   205,   206,   206,   207,   208,   208,   208,   208,   209,
     209,   209,   209,   209,   210,   210,   211,   211,   212,   212,
     213,   213,   214,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   216,   216,   217,   217,   217,   218,   218,   219,   219,
     220,   220,   220,   220,   221,   221,   222,   222,   222,   222,
     223,   223,   224,   225,   226,   227,   228,   229,   229,   230,
     230,   231,   232,   232,   233,   234,   234,   234,   235,   235,
     236,   236,   237,   237,   238,   238,   239,   240,   240,   240,
     241,   241,   242,   243,   243,   244,   245,   245,   246,   247,
     247,   248,   248,   249,   249,   250,   250,   251,   251,   252,
     253,   253,   253,   254,   254,   255,   255,   255,   255,   255,
     255,   256,   256,   257,   257,   258,   258,   259,   260,   260,
     261,   262,   262,   262,   262,   262,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   264,   264,   265,
     265,   265,   265,   265,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   267,   267,   268,   268,   268,
     268,   269,   269,   269,   269,   270,   270,   271,   271,   272,
     272,   272,   272,   272,   272,   272,   273,   273,   274,   275,
     276,   276,   276,   276,   276,   276,   277,   277,   277,   277,
     277,   277,   278,   278,   279,   280,   281,   282,   282,   282,
     282,   283,   283,   283,   283,   283,   283,   283,   284,   285,
     285,   286,   286,   287,   288,   289,   290,   290,   290,   291,
     292,   292,   293,   293,   294,   294,   295,   295,   296,   297,
     298,   298,   299,   299,   300,   300,   301,   301,   302,   302,
     303,   303,   304,   304,   305,   305,   306,   306,   307,   307,
     307,   307,   308,   308,   308,   309,   309,   310,   311,   311,
     312,   313,   313,   313,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   315,   316,   316,   317,   317
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     0,     1,     3,     1,     4,     2,     2,     2,
       1,     0,     1,     1,     4,     1,     2,     5,     7,     5,
       1,     1,     3,     0,     5,     2,     3,     2,     2,     8,
       7,     6,    10,     7,     3,     0,     1,     0,     1,     3,
       1,     1,     3,     1,     1,     4,     4,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       4,     3,     0,     5,     3,     0,     1,     0,     1,     2,
       2,     1,     1,     2,     5,     4,     4,     4,     3,     4,
       2,     0,     5,     1,     4,     4,     2,     6,     5,     3,
       0,     5,     1,     3,     3,     2,     2,     6,     1,     1,
       1,     3,     3,     3,     4,     6,     2,     1,     1,     1,
       1,     0,     7,     1,     0,     1,     1,     0,     2,     2,
       0,     4,     0,     2,     0,     3,     0,     1,     3,     2,
       1,     1,     0,     2,     0,     2,     2,     4,     2,     4,
       0,     1,     3,     1,     0,     1,     3,     3,     1,     3,
       2,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     2,
       2,     2,     3,     4,     1,     3,     3,     3,     3,     3,
       3,     3,     4,     3,     3,     3,     3,     5,     6,     5,
       6,     4,     6,     3,     5,     4,     5,     4,     5,     3,
       3,     3,     3,     3,     3,     3,     3,     5,     6,     6,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     5,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     3,     2,     1,
       1,     3,     1,     1,     1,     4,     1,     3,     2,     1,
       1,     3,     1,     0,     1,     5,     1,     0,     2,     1,
       1,     0,     1,     0,     1,     2,     3,     5,     1,     3,
       1,     2,     2,     1,     0,     1,     0,     2,     1,     3,
       3,     4,     6,     8,     1,     2,     1,     2,     1,     2,
       1,     1,     1,     0,     1,     1,     0,     1,     3
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
#line 170 "bison_parser.y"
                { free( (((*yyvaluep).sval)) ); }
#line 2041 "bison_parser.cpp"
        break;

    case YYSYMBOL_STRING: /* STRING  */
#line 170 "bison_parser.y"
                { free( (((*yyvaluep).sval)) ); }
#line 2047 "bison_parser.cpp"
        break;

    case YYSYMBOL_FLOATVAL: /* FLOATVAL  */
#line 168 "bison_parser.y"
                { }
#line 2053 "bison_parser.cpp"
        break;

    case YYSYMBOL_INTVAL: /* INTVAL  */
#line 168 "bison_parser.y"
                { }
#line 2059 "bison_parser.cpp"
        break;

    case YYSYMBOL_statement_list: /* statement_list  */
#line 171 "bison_parser.y"
                {
      if ((((*yyvaluep).stmt_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).stmt_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).stmt_vec));
    }
#line 2072 "bison_parser.cpp"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).statement)); }
#line 2078 "bison_parser.cpp"
        break;

    case YYSYMBOL_preparable_statement: /* preparable_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).statement)); }
#line 2084 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_hints: /* opt_hints  */
#line 171 "bison_parser.y"
                {
      if ((((*yyvaluep).expr_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).expr_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).expr_vec));
    }
#line 2097 "bison_parser.cpp"
        break;

    case YYSYMBOL_hint_list: /* hint_list  */
#line 171 "bison_parser.y"
                {
      if ((((*yyvaluep).expr_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).expr_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).expr_vec));
    }
#line 2110 "bison_parser.cpp"
        break;

    case YYSYMBOL_hint: /* hint  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2116 "bison_parser.cpp"
        break;

    case YYSYMBOL_transaction_statement: /* transaction_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).transaction_stmt)); }
#line 2122 "bison_parser.cpp"
        break;

    case YYSYMBOL_other_statement: /* other_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).other_stmt)); }
#line 2128 "bison_parser.cpp"
        break;

    case YYSYMBOL_prepare_statement: /* prepare_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).prep_stmt)); }
#line 2134 "bison_parser.cpp"
        break;

    case YYSYMBOL_prepare_target_query: /* prepare_target_query  */
#line 170 "bison_parser.y"
                { free( (((*yyvaluep).sval)) ); }
#line 2140 "bison_parser.cpp"
        break;

    case YYSYMBOL_execute_statement: /* execute_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).exec_stmt)); }
#line 2146 "bison_parser.cpp"
        break;

    case YYSYMBOL_import_statement: /* import_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).import_stmt)); }
#line 2152 "bison_parser.cpp"
        break;

    case YYSYMBOL_file_type: /* file_type  */
#line 168 "bison_parser.y"
                { }
#line 2158 "bison_parser.cpp"
        break;

    case YYSYMBOL_file_path: /* file_path  */
#line 170 "bison_parser.y"
                { free( (((*yyvaluep).sval)) ); }
#line 2164 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_file_type: /* opt_file_type  */
#line 168 "bison_parser.y"
                { }
#line 2170 "bison_parser.cpp"
        break;

    case YYSYMBOL_export_statement: /* export_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).export_stmt)); }
#line 2176 "bison_parser.cpp"
        break;

    case YYSYMBOL_show_statement: /* show_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).show_stmt)); }
#line 2182 "bison_parser.cpp"
        break;

    case YYSYMBOL_create_statement: /* create_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).create_stmt)); }
#line 2188 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_not_exists: /* opt_not_exists  */
#line 168 "bison_parser.y"
                { }
#line 2194 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_unique: /* opt_unique  */
#line 168 "bison_parser.y"
                { }
#line 2200 "bison_parser.cpp"
        break;

    case YYSYMBOL_table_elem_commalist: /* table_elem_commalist  */
#line 171 "bison_parser.y"
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
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).table_element_t)); }
#line 2219 "bison_parser.cpp"
        break;

    case YYSYMBOL_column_def: /* column_def  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).column_t)); }
#line 2225 "bison_parser.cpp"
        break;

    case YYSYMBOL_column_type: /* column_type  */
#line 168 "bison_parser.y"
                { }
#line 2231 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_time_precision: /* opt_time_precision  */
#line 168 "bison_parser.y"
                { }
#line 2237 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_decimal_specification: /* opt_decimal_specification  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).ival_pair)); }
#line 2243 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_column_constraints: /* opt_column_constraints  */
#line 168 "bison_parser.y"
                { }
#line 2249 "bison_parser.cpp"
        break;

    case YYSYMBOL_column_constraint_set: /* column_constraint_set  */
#line 168 "bison_parser.y"
                { }
#line 2255 "bison_parser.cpp"
        break;

    case YYSYMBOL_column_constraint: /* column_constraint  */
#line 168 "bison_parser.y"
                { }
#line 2261 "bison_parser.cpp"
        break;

    case YYSYMBOL_table_constraint: /* table_constraint  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).table_constraint_t)); }
#line 2267 "bison_parser.cpp"
        break;

    case YYSYMBOL_drop_statement: /* drop_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).drop_stmt)); }
#line 2273 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_exists: /* opt_exists  */
#line 168 "bison_parser.y"
                { }
#line 2279 "bison_parser.cpp"
        break;

    case YYSYMBOL_alter_statement: /* alter_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).alter_stmt)); }
#line 2285 "bison_parser.cpp"
        break;

    case YYSYMBOL_alter_action: /* alter_action  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).alter_action_t)); }
#line 2291 "bison_parser.cpp"
        break;

    case YYSYMBOL_drop_action: /* drop_action  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).drop_action_t)); }
#line 2297 "bison_parser.cpp"
        break;

    case YYSYMBOL_delete_statement: /* delete_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).delete_stmt)); }
#line 2303 "bison_parser.cpp"
        break;

    case YYSYMBOL_truncate_statement: /* truncate_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).delete_stmt)); }
#line 2309 "bison_parser.cpp"
        break;

    case YYSYMBOL_insert_statement: /* insert_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).insert_stmt)); }
#line 2315 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_column_list: /* opt_column_list  */
#line 171 "bison_parser.y"
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
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).update_stmt)); }
#line 2334 "bison_parser.cpp"
        break;

    case YYSYMBOL_update_clause_commalist: /* update_clause_commalist  */
#line 171 "bison_parser.y"
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
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).update_t)); }
#line 2353 "bison_parser.cpp"
        break;

    case YYSYMBOL_select_statement: /* select_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2359 "bison_parser.cpp"
        break;

    case YYSYMBOL_select_within_set_operation: /* select_within_set_operation  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2365 "bison_parser.cpp"
        break;

    case YYSYMBOL_select_within_set_operation_no_parentheses: /* select_within_set_operation_no_parentheses  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2371 "bison_parser.cpp"
        break;

    case YYSYMBOL_select_with_paren: /* select_with_paren  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2377 "bison_parser.cpp"
        break;

    case YYSYMBOL_select_no_paren: /* select_no_paren  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2383 "bison_parser.cpp"
        break;

    case YYSYMBOL_set_operator: /* set_operator  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).set_operator_t)); }
#line 2389 "bison_parser.cpp"
        break;

    case YYSYMBOL_set_type: /* set_type  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).set_operator_t)); }
#line 2395 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_all: /* opt_all  */
#line 168 "bison_parser.y"
                { }
#line 2401 "bison_parser.cpp"
        break;

    case YYSYMBOL_select_clause: /* select_clause  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2407 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_distinct: /* opt_distinct  */
#line 168 "bison_parser.y"
                { }
#line 2413 "bison_parser.cpp"
        break;

    case YYSYMBOL_select_list: /* select_list  */
#line 171 "bison_parser.y"
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
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2432 "bison_parser.cpp"
        break;

    case YYSYMBOL_from_clause: /* from_clause  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2438 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_where: /* opt_where  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2444 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_group: /* opt_group  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).group_t)); }
#line 2450 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_having: /* opt_having  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2456 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_order: /* opt_order  */
#line 171 "bison_parser.y"
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
#line 171 "bison_parser.y"
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
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).order)); }
#line 2488 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_order_type: /* opt_order_type  */
#line 168 "bison_parser.y"
                { }
#line 2494 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_top: /* opt_top  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).limit)); }
#line 2500 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_limit: /* opt_limit  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).limit)); }
#line 2506 "bison_parser.cpp"
        break;

    case YYSYMBOL_expr_list: /* expr_list  */
#line 171 "bison_parser.y"
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
#line 171 "bison_parser.y"
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

    case YYSYMBOL_list_of_list: /* list_of_list  */
#line 171 "bison_parser.y"
                {
      if ((((*yyvaluep).list_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).list_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).list_vec));
    }
#line 2545 "bison_parser.cpp"
        break;

    case YYSYMBOL_list_item: /* list_item  */
#line 171 "bison_parser.y"
                {
      if ((((*yyvaluep).expr_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).expr_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).expr_vec));
    }
#line 2558 "bison_parser.cpp"
        break;

    case YYSYMBOL_literal_list: /* literal_list  */
#line 171 "bison_parser.y"
                {
      if ((((*yyvaluep).expr_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).expr_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).expr_vec));
    }
#line 2571 "bison_parser.cpp"
        break;

    case YYSYMBOL_expr_alias: /* expr_alias  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2577 "bison_parser.cpp"
        break;

    case YYSYMBOL_expr: /* expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2583 "bison_parser.cpp"
        break;

    case YYSYMBOL_operand: /* operand  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2589 "bison_parser.cpp"
        break;

    case YYSYMBOL_scalar_expr: /* scalar_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2595 "bison_parser.cpp"
        break;

    case YYSYMBOL_unary_expr: /* unary_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2601 "bison_parser.cpp"
        break;

    case YYSYMBOL_binary_expr: /* binary_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2607 "bison_parser.cpp"
        break;

    case YYSYMBOL_logic_expr: /* logic_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2613 "bison_parser.cpp"
        break;

    case YYSYMBOL_in_expr: /* in_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2619 "bison_parser.cpp"
        break;

    case YYSYMBOL_case_expr: /* case_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2625 "bison_parser.cpp"
        break;

    case YYSYMBOL_case_list: /* case_list  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2631 "bison_parser.cpp"
        break;

    case YYSYMBOL_exists_expr: /* exists_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2637 "bison_parser.cpp"
        break;

    case YYSYMBOL_comp_expr: /* comp_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2643 "bison_parser.cpp"
        break;

    case YYSYMBOL_function_expr: /* function_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2649 "bison_parser.cpp"
        break;

    case YYSYMBOL_extract_expr: /* extract_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2655 "bison_parser.cpp"
        break;

    case YYSYMBOL_cast_expr: /* cast_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2661 "bison_parser.cpp"
        break;

    case YYSYMBOL_datetime_field: /* datetime_field  */
#line 168 "bison_parser.y"
                { }
#line 2667 "bison_parser.cpp"
        break;

    case YYSYMBOL_datetime_field_plural: /* datetime_field_plural  */
#line 168 "bison_parser.y"
                { }
#line 2673 "bison_parser.cpp"
        break;

    case YYSYMBOL_duration_field: /* duration_field  */
#line 168 "bison_parser.y"
                { }
#line 2679 "bison_parser.cpp"
        break;

    case YYSYMBOL_array_expr: /* array_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2685 "bison_parser.cpp"
        break;

    case YYSYMBOL_array_index: /* array_index  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2691 "bison_parser.cpp"
        break;

    case YYSYMBOL_between_expr: /* between_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2697 "bison_parser.cpp"
        break;

    case YYSYMBOL_column_name: /* column_name  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2703 "bison_parser.cpp"
        break;

    case YYSYMBOL_literal: /* literal  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2709 "bison_parser.cpp"
        break;

    case YYSYMBOL_string_literal: /* string_literal  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2715 "bison_parser.cpp"
        break;

    case YYSYMBOL_bool_literal: /* bool_literal  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2721 "bison_parser.cpp"
        break;

    case YYSYMBOL_num_literal: /* num_literal  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2727 "bison_parser.cpp"
        break;

    case YYSYMBOL_int_literal: /* int_literal  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2733 "bison_parser.cpp"
        break;

    case YYSYMBOL_null_literal: /* null_literal  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2739 "bison_parser.cpp"
        break;

    case YYSYMBOL_date_literal: /* date_literal  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2745 "bison_parser.cpp"
        break;

    case YYSYMBOL_interval_literal: /* interval_literal  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2751 "bison_parser.cpp"
        break;

    case YYSYMBOL_param_expr: /* param_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2757 "bison_parser.cpp"
        break;

    case YYSYMBOL_table_ref: /* table_ref  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2763 "bison_parser.cpp"
        break;

    case YYSYMBOL_table_ref_atomic: /* table_ref_atomic  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2769 "bison_parser.cpp"
        break;

    case YYSYMBOL_nonjoin_table_ref_atomic: /* nonjoin_table_ref_atomic  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2775 "bison_parser.cpp"
        break;

    case YYSYMBOL_table_ref_commalist: /* table_ref_commalist  */
#line 171 "bison_parser.y"
                {
      if ((((*yyvaluep).table_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).table_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).table_vec));
    }
#line 2788 "bison_parser.cpp"
        break;

    case YYSYMBOL_table_ref_name: /* table_ref_name  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2794 "bison_parser.cpp"
        break;

    case YYSYMBOL_table_ref_name_no_alias: /* table_ref_name_no_alias  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2800 "bison_parser.cpp"
        break;

    case YYSYMBOL_table_name: /* table_name  */
#line 169 "bison_parser.y"
                { free( (((*yyvaluep).table_name).name) ); free( (((*yyvaluep).table_name).schema) ); }
#line 2806 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_index_name: /* opt_index_name  */
#line 170 "bison_parser.y"
                { free( (((*yyvaluep).sval)) ); }
#line 2812 "bison_parser.cpp"
        break;

    case YYSYMBOL_table_alias: /* table_alias  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).alias_t)); }
#line 2818 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_table_alias: /* opt_table_alias  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).alias_t)); }
#line 2824 "bison_parser.cpp"
        break;

    case YYSYMBOL_alias: /* alias  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).alias_t)); }
#line 2830 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_alias: /* opt_alias  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).alias_t)); }
#line 2836 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_locking_clause: /* opt_locking_clause  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).locking_clause_vec)); }
#line 2842 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_locking_clause_list: /* opt_locking_clause_list  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).locking_clause_vec)); }
#line 2848 "bison_parser.cpp"
        break;

    case YYSYMBOL_locking_clause: /* locking_clause  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).locking_t)); }
#line 2854 "bison_parser.cpp"
        break;

    case YYSYMBOL_row_lock_mode: /* row_lock_mode  */
#line 168 "bison_parser.y"
                { }
#line 2860 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_row_lock_policy: /* opt_row_lock_policy  */
#line 168 "bison_parser.y"
                { }
#line 2866 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_with_clause: /* opt_with_clause  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).with_description_vec)); }
#line 2872 "bison_parser.cpp"
        break;

    case YYSYMBOL_with_clause: /* with_clause  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).with_description_vec)); }
#line 2878 "bison_parser.cpp"
        break;

    case YYSYMBOL_with_description_list: /* with_description_list  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).with_description_vec)); }
#line 2884 "bison_parser.cpp"
        break;

    case YYSYMBOL_with_description: /* with_description  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).with_description_t)); }
#line 2890 "bison_parser.cpp"
        break;

    case YYSYMBOL_join_clause: /* join_clause  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2896 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_join_type: /* opt_join_type  */
#line 168 "bison_parser.y"
                { }
#line 2902 "bison_parser.cpp"
        break;

    case YYSYMBOL_join_condition: /* join_condition  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2908 "bison_parser.cpp"
        break;

    case YYSYMBOL_ident_commalist: /* ident_commalist  */
#line 171 "bison_parser.y"
                {
      if ((((*yyvaluep).str_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).str_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).str_vec));
    }
#line 2921 "bison_parser.cpp"
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

#line 3029 "bison_parser.cpp"

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
#line 309 "bison_parser.y"
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
#line 3258 "bison_parser.cpp"
    break;

  case 3: /* statement_list: statement  */
#line 328 "bison_parser.y"
                           {
  (yyvsp[0].statement)->stringLength = yylloc.string_length;
  yylloc.string_length = 0;
  (yyval.stmt_vec) = new std::vector<SQLStatement*>();
  (yyval.stmt_vec)->push_back((yyvsp[0].statement));
}
#line 3269 "bison_parser.cpp"
    break;

  case 4: /* statement_list: statement_list ';' statement  */
#line 334 "bison_parser.y"
                               {
  (yyvsp[0].statement)->stringLength = yylloc.string_length;
  yylloc.string_length = 0;
  (yyvsp[-2].stmt_vec)->push_back((yyvsp[0].statement));
  (yyval.stmt_vec) = (yyvsp[-2].stmt_vec);
}
#line 3280 "bison_parser.cpp"
    break;

  case 5: /* statement: prepare_statement opt_hints  */
#line 341 "bison_parser.y"
                                        {
  (yyval.statement) = (yyvsp[-1].prep_stmt);
  (yyval.statement)->hints = (yyvsp[0].expr_vec);
}
#line 3289 "bison_parser.cpp"
    break;

  case 6: /* statement: preparable_statement opt_hints  */
#line 345 "bison_parser.y"
                                 {
  (yyval.statement) = (yyvsp[-1].statement);
  (yyval.statement)->hints = (yyvsp[0].expr_vec);
}
#line 3298 "bison_parser.cpp"
    break;

  case 7: /* statement: show_statement  */
#line 349 "bison_parser.y"
                 { (yyval.statement) = (yyvsp[0].show_stmt); }
#line 3304 "bison_parser.cpp"
    break;

  case 8: /* statement: import_statement  */
#line 350 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].import_stmt); }
#line 3310 "bison_parser.cpp"
    break;

  case 9: /* statement: export_statement  */
#line 351 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].export_stmt); }
#line 3316 "bison_parser.cpp"
    break;

  case 10: /* preparable_statement: select_statement  */
#line 353 "bison_parser.y"
                                        { (yyval.statement) = (yyvsp[0].select_stmt); }
#line 3322 "bison_parser.cpp"
    break;

  case 11: /* preparable_statement: create_statement  */
#line 354 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].create_stmt); }
#line 3328 "bison_parser.cpp"
    break;

  case 12: /* preparable_statement: insert_statement  */
#line 355 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].insert_stmt); }
#line 3334 "bison_parser.cpp"
    break;

  case 13: /* preparable_statement: delete_statement  */
#line 356 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].delete_stmt); }
#line 3340 "bison_parser.cpp"
    break;

  case 14: /* preparable_statement: truncate_statement  */
#line 357 "bison_parser.y"
                     { (yyval.statement) = (yyvsp[0].delete_stmt); }
#line 3346 "bison_parser.cpp"
    break;

  case 15: /* preparable_statement: update_statement  */
#line 358 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].update_stmt); }
#line 3352 "bison_parser.cpp"
    break;

  case 16: /* preparable_statement: drop_statement  */
#line 359 "bison_parser.y"
                 { (yyval.statement) = (yyvsp[0].drop_stmt); }
#line 3358 "bison_parser.cpp"
    break;

  case 17: /* preparable_statement: alter_statement  */
#line 360 "bison_parser.y"
                  { (yyval.statement) = (yyvsp[0].alter_stmt); }
#line 3364 "bison_parser.cpp"
    break;

  case 18: /* preparable_statement: execute_statement  */
#line 361 "bison_parser.y"
                    { (yyval.statement) = (yyvsp[0].exec_stmt); }
#line 3370 "bison_parser.cpp"
    break;

  case 19: /* preparable_statement: transaction_statement  */
#line 362 "bison_parser.y"
                        { (yyval.statement) = (yyvsp[0].transaction_stmt); }
#line 3376 "bison_parser.cpp"
    break;

  case 20: /* preparable_statement: other_statement  */
#line 363 "bison_parser.y"
                  { (yyval.statement) = (yyvsp[0].other_stmt); }
#line 3382 "bison_parser.cpp"
    break;

  case 21: /* opt_hints: WITH HINT '(' hint_list ')'  */
#line 369 "bison_parser.y"
                                        { (yyval.expr_vec) = (yyvsp[-1].expr_vec); }
#line 3388 "bison_parser.cpp"
    break;

  case 22: /* opt_hints: %empty  */
#line 370 "bison_parser.y"
              { (yyval.expr_vec) = nullptr; }
#line 3394 "bison_parser.cpp"
    break;

  case 23: /* hint_list: hint  */
#line 372 "bison_parser.y"
                 {
  (yyval.expr_vec) = new std::vector<Expr*>();
  (yyval.expr_vec)->push_back((yyvsp[0].expr));
}
#line 3403 "bison_parser.cpp"
    break;

  case 24: /* hint_list: hint_list ',' hint  */
#line 376 "bison_parser.y"
                     {
  (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr));
  (yyval.expr_vec) = (yyvsp[-2].expr_vec);
}
#line 3412 "bison_parser.cpp"
    break;

  case 25: /* hint: IDENTIFIER  */
#line 381 "bison_parser.y"
                  {
  (yyval.expr) = Expr::make(kExprHint);
  (yyval.expr)->name = (yyvsp[0].sval);
}
#line 3421 "bison_parser.cpp"
    break;

  case 26: /* hint: IDENTIFIER '(' literal_list ')'  */
#line 385 "bison_parser.y"
                                  {
  (yyval.expr) = Expr::make(kExprHint);
  (yyval.expr)->name = (yyvsp[-3].sval);
  (yyval.expr)->exprList = (yyvsp[-1].expr_vec);
}
#line 3431 "bison_parser.cpp"
    break;

  case 27: /* transaction_statement: BEGIN opt_transaction_keyword  */
#line 395 "bison_parser.y"
                                                      { (yyval.transaction_stmt) = new TransactionStatement(kBeginTransaction); }
#line 3437 "bison_parser.cpp"
    break;

  case 28: /* transaction_statement: ROLLBACK opt_transaction_keyword  */
#line 396 "bison_parser.y"
                                   { (yyval.transaction_stmt) = new TransactionStatement(kRollbackTransaction); }
#line 3443 "bison_parser.cpp"
    break;

  case 29: /* transaction_statement: COMMIT opt_transaction_keyword  */
#line 397 "bison_parser.y"
                                 { (yyval.transaction_stmt) = new TransactionStatement(kCommitTransaction); }
#line 3449 "bison_parser.cpp"
    break;

  case 32: /* other_statement: HELP  */
#line 406 "bison_parser.y"
                       { (yyval.other_stmt) = new OtherStatement(kHelp); }
#line 3455 "bison_parser.cpp"
    break;

  case 33: /* other_statement: SYNC  */
#line 407 "bison_parser.y"
       { (yyval.other_stmt) = new OtherStatement(kSync); }
#line 3461 "bison_parser.cpp"
    break;

  case 34: /* prepare_statement: PREPARE IDENTIFIER FROM prepare_target_query  */
#line 412 "bison_parser.y"
                                                                 {
  (yyval.prep_stmt) = new PrepareStatement();
  (yyval.prep_stmt)->name = (yyvsp[-2].sval);
  (yyval.prep_stmt)->query = (yyvsp[0].sval);
}
#line 3471 "bison_parser.cpp"
    break;

  case 36: /* execute_statement: EXECUTE IDENTIFIER  */
#line 420 "bison_parser.y"
                                                                  {
  (yyval.exec_stmt) = new ExecuteStatement();
  (yyval.exec_stmt)->name = (yyvsp[0].sval);
}
#line 3480 "bison_parser.cpp"
    break;

  case 37: /* execute_statement: EXECUTE IDENTIFIER '(' opt_literal_list ')'  */
#line 424 "bison_parser.y"
                                              {
  (yyval.exec_stmt) = new ExecuteStatement();
  (yyval.exec_stmt)->name = (yyvsp[-3].sval);
  (yyval.exec_stmt)->parameters = (yyvsp[-1].expr_vec);
}
#line 3490 "bison_parser.cpp"
    break;

  case 38: /* import_statement: IMPORT FROM file_type FILE file_path INTO table_name  */
#line 435 "bison_parser.y"
                                                                        {
  (yyval.import_stmt) = new ImportStatement((yyvsp[-4].import_type_t));
  (yyval.import_stmt)->filePath = (yyvsp[-2].sval);
  (yyval.import_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.import_stmt)->tableName = (yyvsp[0].table_name).name;
}
#line 3501 "bison_parser.cpp"
    break;

  case 39: /* import_statement: COPY table_name FROM file_path opt_file_type  */
#line 441 "bison_parser.y"
                                               {
  (yyval.import_stmt) = new ImportStatement((yyvsp[0].import_type_t));
  (yyval.import_stmt)->filePath = (yyvsp[-1].sval);
  (yyval.import_stmt)->schema = (yyvsp[-3].table_name).schema;
  (yyval.import_stmt)->tableName = (yyvsp[-3].table_name).name;
}
#line 3512 "bison_parser.cpp"
    break;

  case 40: /* file_type: IDENTIFIER  */
#line 448 "bison_parser.y"
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
#line 3531 "bison_parser.cpp"
    break;

  case 41: /* file_path: string_literal  */
#line 463 "bison_parser.y"
                           {
  (yyval.sval) = strdup((yyvsp[0].expr)->name);
  delete (yyvsp[0].expr);
}
#line 3540 "bison_parser.cpp"
    break;

  case 42: /* opt_file_type: WITH FORMAT file_type  */
#line 468 "bison_parser.y"
                                      { (yyval.import_type_t) = (yyvsp[0].import_type_t); }
#line 3546 "bison_parser.cpp"
    break;

  case 43: /* opt_file_type: %empty  */
#line 469 "bison_parser.y"
              { (yyval.import_type_t) = kImportAuto; }
#line 3552 "bison_parser.cpp"
    break;

  case 44: /* export_statement: COPY table_name TO file_path opt_file_type  */
#line 475 "bison_parser.y"
                                                              {
  (yyval.export_stmt) = new ExportStatement((yyvsp[0].import_type_t));
  (yyval.export_stmt)->filePath = (yyvsp[-1].sval);
  (yyval.export_stmt)->schema = (yyvsp[-3].table_name).schema;
  (yyval.export_stmt)->tableName = (yyvsp[-3].table_name).name;
}
#line 3563 "bison_parser.cpp"
    break;

  case 45: /* show_statement: SHOW TABLES  */
#line 487 "bison_parser.y"
                             { (yyval.show_stmt) = new ShowStatement(kShowTables); }
#line 3569 "bison_parser.cpp"
    break;

  case 46: /* show_statement: SHOW COLUMNS table_name  */
#line 488 "bison_parser.y"
                          {
  (yyval.show_stmt) = new ShowStatement(kShowColumns);
  (yyval.show_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.show_stmt)->name = (yyvsp[0].table_name).name;
}
#line 3579 "bison_parser.cpp"
    break;

  case 47: /* show_statement: DESCRIBE table_name  */
#line 493 "bison_parser.y"
                      {
  (yyval.show_stmt) = new ShowStatement(kShowColumns);
  (yyval.show_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.show_stmt)->name = (yyvsp[0].table_name).name;
}
#line 3589 "bison_parser.cpp"
    break;

  case 48: /* show_statement: DESC table_name  */
#line 498 "bison_parser.y"
                  {
  (yyval.show_stmt) = new ShowStatement(kShowColumns);
  (yyval.show_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.show_stmt)->name = (yyvsp[0].table_name).name;
}
#line 3599 "bison_parser.cpp"
    break;

  case 49: /* create_statement: CREATE TABLE opt_not_exists table_name FROM IDENTIFIER FILE file_path  */
#line 509 "bison_parser.y"
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
#line 3617 "bison_parser.cpp"
    break;

  case 50: /* create_statement: CREATE TABLE opt_not_exists table_name '(' table_elem_commalist ')'  */
#line 522 "bison_parser.y"
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
#line 3634 "bison_parser.cpp"
    break;

  case 51: /* create_statement: CREATE TABLE opt_not_exists table_name AS select_statement  */
#line 534 "bison_parser.y"
                                                             {
  (yyval.create_stmt) = new CreateStatement(kCreateTable);
  (yyval.create_stmt)->ifNotExists = (yyvsp[-3].bval);
  (yyval.create_stmt)->schema = (yyvsp[-2].table_name).schema;
  (yyval.create_stmt)->tableName = (yyvsp[-2].table_name).name;
  (yyval.create_stmt)->select = (yyvsp[0].select_stmt);
}
#line 3646 "bison_parser.cpp"
    break;

  case 52: /* create_statement: CREATE opt_unique INDEX opt_not_exists opt_index_name ON table_name '(' ident_commalist ')'  */
#line 541 "bison_parser.y"
                                                                                              {
  (yyval.create_stmt) = new CreateStatement(kCreateIndex);
  (yyval.create_stmt)->indexName = (yyvsp[-5].sval);
  (yyval.create_stmt)->ifNotExists = (yyvsp[-6].bval);
  (yyval.create_stmt)->isUnique = (yyvsp[-8].bval);
  (yyval.create_stmt)->tableName = (yyvsp[-3].table_name).name;
  (yyval.create_stmt)->indexColumns = (yyvsp[-1].str_vec);
}
#line 3659 "bison_parser.cpp"
    break;

  case 53: /* create_statement: CREATE VIEW opt_not_exists table_name opt_column_list AS select_statement  */
#line 549 "bison_parser.y"
                                                                            {
  (yyval.create_stmt) = new CreateStatement(kCreateView);
  (yyval.create_stmt)->ifNotExists = (yyvsp[-4].bval);
  (yyval.create_stmt)->schema = (yyvsp[-3].table_name).schema;
  (yyval.create_stmt)->tableName = (yyvsp[-3].table_name).name;
  (yyval.create_stmt)->viewColumns = (yyvsp[-2].str_vec);
  (yyval.create_stmt)->select = (yyvsp[0].select_stmt);
}
#line 3672 "bison_parser.cpp"
    break;

  case 54: /* opt_not_exists: IF NOT EXISTS  */
#line 558 "bison_parser.y"
                               { (yyval.bval) = true; }
#line 3678 "bison_parser.cpp"
    break;

  case 55: /* opt_not_exists: %empty  */
#line 559 "bison_parser.y"
              { (yyval.bval) = false; }
#line 3684 "bison_parser.cpp"
    break;

  case 56: /* opt_unique: UNIQUE  */
#line 561 "bison_parser.y"
                   { (yyval.bval) = true; }
#line 3690 "bison_parser.cpp"
    break;

  case 57: /* opt_unique: %empty  */
#line 562 "bison_parser.y"
              { (yyval.bval) = false; }
#line 3696 "bison_parser.cpp"
    break;

  case 58: /* table_elem_commalist: table_elem  */
#line 564 "bison_parser.y"
                                  {
  (yyval.table_element_vec) = new std::vector<TableElement*>();
  (yyval.table_element_vec)->push_back((yyvsp[0].table_element_t));
}
#line 3705 "bison_parser.cpp"
    break;

  case 59: /* table_elem_commalist: table_elem_commalist ',' table_elem  */
#line 568 "bison_parser.y"
                                      {
  (yyvsp[-2].table_element_vec)->push_back((yyvsp[0].table_element_t));
  (yyval.table_element_vec) = (yyvsp[-2].table_element_vec);
}
#line 3714 "bison_parser.cpp"
    break;

  case 60: /* table_elem: column_def  */
#line 573 "bison_parser.y"
                        { (yyval.table_element_t) = (yyvsp[0].column_t); }
#line 3720 "bison_parser.cpp"
    break;

  case 61: /* table_elem: table_constraint  */
#line 574 "bison_parser.y"
                   { (yyval.table_element_t) = (yyvsp[0].table_constraint_t); }
#line 3726 "bison_parser.cpp"
    break;

  case 62: /* column_def: IDENTIFIER column_type opt_column_constraints  */
#line 576 "bison_parser.y"
                                                           {
  (yyval.column_t) = new ColumnDefinition((yyvsp[-2].sval), (yyvsp[-1].column_type_t), (yyvsp[0].column_constraint_set));
  if (!(yyval.column_t)->trySetNullableExplicit()) {
    yyerror(&yyloc, result, scanner, ("Conflicting nullability constraints for " + std::string{(yyvsp[-2].sval)}).c_str());
  }
}
#line 3737 "bison_parser.cpp"
    break;

  case 63: /* column_type: BIGINT  */
#line 583 "bison_parser.y"
                     { (yyval.column_type_t) = ColumnType{DataType::BIGINT}; }
#line 3743 "bison_parser.cpp"
    break;

  case 64: /* column_type: BOOLEAN  */
#line 584 "bison_parser.y"
          { (yyval.column_type_t) = ColumnType{DataType::BOOLEAN}; }
#line 3749 "bison_parser.cpp"
    break;

  case 65: /* column_type: CHAR '(' INTVAL ')'  */
#line 585 "bison_parser.y"
                      { (yyval.column_type_t) = ColumnType{DataType::CHAR, (yyvsp[-1].ival)}; }
#line 3755 "bison_parser.cpp"
    break;

  case 66: /* column_type: CHARACTER_VARYING '(' INTVAL ')'  */
#line 586 "bison_parser.y"
                                   { (yyval.column_type_t) = ColumnType{DataType::VARCHAR, (yyvsp[-1].ival)}; }
#line 3761 "bison_parser.cpp"
    break;

  case 67: /* column_type: DATE  */
#line 587 "bison_parser.y"
       { (yyval.column_type_t) = ColumnType{DataType::DATE}; }
#line 3767 "bison_parser.cpp"
    break;

  case 68: /* column_type: DATETIME  */
#line 588 "bison_parser.y"
           { (yyval.column_type_t) = ColumnType{DataType::DATETIME}; }
#line 3773 "bison_parser.cpp"
    break;

  case 69: /* column_type: DECIMAL opt_decimal_specification  */
#line 589 "bison_parser.y"
                                    {
  (yyval.column_type_t) = ColumnType{DataType::DECIMAL, 0, (yyvsp[0].ival_pair)->first, (yyvsp[0].ival_pair)->second};
  delete (yyvsp[0].ival_pair);
}
#line 3782 "bison_parser.cpp"
    break;

  case 70: /* column_type: DOUBLE  */
#line 593 "bison_parser.y"
         { (yyval.column_type_t) = ColumnType{DataType::DOUBLE}; }
#line 3788 "bison_parser.cpp"
    break;

  case 71: /* column_type: FLOAT  */
#line 594 "bison_parser.y"
        { (yyval.column_type_t) = ColumnType{DataType::FLOAT}; }
#line 3794 "bison_parser.cpp"
    break;

  case 72: /* column_type: INT  */
#line 595 "bison_parser.y"
      { (yyval.column_type_t) = ColumnType{DataType::INT}; }
#line 3800 "bison_parser.cpp"
    break;

  case 73: /* column_type: INTEGER  */
#line 596 "bison_parser.y"
          { (yyval.column_type_t) = ColumnType{DataType::INT}; }
#line 3806 "bison_parser.cpp"
    break;

  case 74: /* column_type: LONG  */
#line 597 "bison_parser.y"
       { (yyval.column_type_t) = ColumnType{DataType::LONG}; }
#line 3812 "bison_parser.cpp"
    break;

  case 75: /* column_type: REAL  */
#line 598 "bison_parser.y"
       { (yyval.column_type_t) = ColumnType{DataType::REAL}; }
#line 3818 "bison_parser.cpp"
    break;

  case 76: /* column_type: SMALLINT  */
#line 599 "bison_parser.y"
           { (yyval.column_type_t) = ColumnType{DataType::SMALLINT}; }
#line 3824 "bison_parser.cpp"
    break;

  case 77: /* column_type: TEXT  */
#line 600 "bison_parser.y"
       { (yyval.column_type_t) = ColumnType{DataType::TEXT}; }
#line 3830 "bison_parser.cpp"
    break;

  case 78: /* column_type: TIME opt_time_precision  */
#line 601 "bison_parser.y"
                          { (yyval.column_type_t) = ColumnType{DataType::TIME, 0, (yyvsp[0].ival)}; }
#line 3836 "bison_parser.cpp"
    break;

  case 79: /* column_type: TIMESTAMP  */
#line 602 "bison_parser.y"
            { (yyval.column_type_t) = ColumnType{DataType::DATETIME}; }
#line 3842 "bison_parser.cpp"
    break;

  case 80: /* column_type: VARCHAR '(' INTVAL ')'  */
#line 603 "bison_parser.y"
                         { (yyval.column_type_t) = ColumnType{DataType::VARCHAR, (yyvsp[-1].ival)}; }
#line 3848 "bison_parser.cpp"
    break;

  case 81: /* opt_time_precision: '(' INTVAL ')'  */
#line 605 "bison_parser.y"
                                    { (yyval.ival) = (yyvsp[-1].ival); }
#line 3854 "bison_parser.cpp"
    break;

  case 82: /* opt_time_precision: %empty  */
#line 606 "bison_parser.y"
              { (yyval.ival) = 0; }
#line 3860 "bison_parser.cpp"
    break;

  case 83: /* opt_decimal_specification: '(' INTVAL ',' INTVAL ')'  */
#line 608 "bison_parser.y"
                                                      { (yyval.ival_pair) = new std::pair<int64_t, int64_t>{(yyvsp[-3].ival), (yyvsp[-1].ival)}; }
#line 3866 "bison_parser.cpp"
    break;

  case 84: /* opt_decimal_specification: '(' INTVAL ')'  */
#line 609 "bison_parser.y"
                 { (yyval.ival_pair) = new std::pair<int64_t, int64_t>{(yyvsp[-1].ival), 0}; }
#line 3872 "bison_parser.cpp"
    break;

  case 85: /* opt_decimal_specification: %empty  */
#line 610 "bison_parser.y"
              { (yyval.ival_pair) = new std::pair<int64_t, int64_t>{0, 0}; }
#line 3878 "bison_parser.cpp"
    break;

  case 86: /* opt_column_constraints: column_constraint_set  */
#line 612 "bison_parser.y"
                                               { (yyval.column_constraint_set) = (yyvsp[0].column_constraint_set); }
#line 3884 "bison_parser.cpp"
    break;

  case 87: /* opt_column_constraints: %empty  */
#line 613 "bison_parser.y"
              { (yyval.column_constraint_set) = new std::unordered_set<ConstraintType>(); }
#line 3890 "bison_parser.cpp"
    break;

  case 88: /* column_constraint_set: column_constraint  */
#line 615 "bison_parser.y"
                                          {
  (yyval.column_constraint_set) = new std::unordered_set<ConstraintType>();
  (yyval.column_constraint_set)->insert((yyvsp[0].column_constraint_t));
}
#line 3899 "bison_parser.cpp"
    break;

  case 89: /* column_constraint_set: column_constraint_set column_constraint  */
#line 619 "bison_parser.y"
                                          {
  (yyvsp[-1].column_constraint_set)->insert((yyvsp[0].column_constraint_t));
  (yyval.column_constraint_set) = (yyvsp[-1].column_constraint_set);
}
#line 3908 "bison_parser.cpp"
    break;

  case 90: /* column_constraint: PRIMARY KEY  */
#line 624 "bison_parser.y"
                                { (yyval.column_constraint_t) = ConstraintType::PrimaryKey; }
#line 3914 "bison_parser.cpp"
    break;

  case 91: /* column_constraint: UNIQUE  */
#line 625 "bison_parser.y"
         { (yyval.column_constraint_t) = ConstraintType::Unique; }
#line 3920 "bison_parser.cpp"
    break;

  case 92: /* column_constraint: NULL  */
#line 626 "bison_parser.y"
       { (yyval.column_constraint_t) = ConstraintType::Null; }
#line 3926 "bison_parser.cpp"
    break;

  case 93: /* column_constraint: NOT NULL  */
#line 627 "bison_parser.y"
           { (yyval.column_constraint_t) = ConstraintType::NotNull; }
#line 3932 "bison_parser.cpp"
    break;

  case 94: /* table_constraint: PRIMARY KEY '(' ident_commalist ')'  */
#line 629 "bison_parser.y"
                                                       { (yyval.table_constraint_t) = new TableConstraint(ConstraintType::PrimaryKey, (yyvsp[-1].str_vec)); }
#line 3938 "bison_parser.cpp"
    break;

  case 95: /* table_constraint: UNIQUE '(' ident_commalist ')'  */
#line 630 "bison_parser.y"
                                 { (yyval.table_constraint_t) = new TableConstraint(ConstraintType::Unique, (yyvsp[-1].str_vec)); }
#line 3944 "bison_parser.cpp"
    break;

  case 96: /* drop_statement: DROP TABLE opt_exists table_name  */
#line 638 "bison_parser.y"
                                                  {
  (yyval.drop_stmt) = new DropStatement(kDropTable);
  (yyval.drop_stmt)->ifExists = (yyvsp[-1].bval);
  (yyval.drop_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.drop_stmt)->name = (yyvsp[0].table_name).name;
}
#line 3955 "bison_parser.cpp"
    break;

  case 97: /* drop_statement: DROP VIEW opt_exists table_name  */
#line 644 "bison_parser.y"
                                  {
  (yyval.drop_stmt) = new DropStatement(kDropView);
  (yyval.drop_stmt)->ifExists = (yyvsp[-1].bval);
  (yyval.drop_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.drop_stmt)->name = (yyvsp[0].table_name).name;
}
#line 3966 "bison_parser.cpp"
    break;

  case 98: /* drop_statement: DEALLOCATE PREPARE IDENTIFIER  */
#line 650 "bison_parser.y"
                                {
  (yyval.drop_stmt) = new DropStatement(kDropPreparedStatement);
  (yyval.drop_stmt)->ifExists = false;
  (yyval.drop_stmt)->name = (yyvsp[0].sval);
}
#line 3976 "bison_parser.cpp"
    break;

  case 99: /* drop_statement: DROP INDEX opt_exists IDENTIFIER  */
#line 656 "bison_parser.y"
                                   {
  (yyval.drop_stmt) = new DropStatement(kDropIndex);
  (yyval.drop_stmt)->ifExists = (yyvsp[-1].bval);
  (yyval.drop_stmt)->indexName = (yyvsp[0].sval);
}
#line 3986 "bison_parser.cpp"
    break;

  case 100: /* opt_exists: IF EXISTS  */
#line 662 "bison_parser.y"
                       { (yyval.bval) = true; }
#line 3992 "bison_parser.cpp"
    break;

  case 101: /* opt_exists: %empty  */
#line 663 "bison_parser.y"
              { (yyval.bval) = false; }
#line 3998 "bison_parser.cpp"
    break;

  case 102: /* alter_statement: ALTER TABLE opt_exists table_name alter_action  */
#line 670 "bison_parser.y"
                                                                 {
  (yyval.alter_stmt) = new AlterStatement((yyvsp[-1].table_name).name, (yyvsp[0].alter_action_t));
  (yyval.alter_stmt)->ifTableExists = (yyvsp[-2].bval);
  (yyval.alter_stmt)->schema = (yyvsp[-1].table_name).schema;
}
#line 4008 "bison_parser.cpp"
    break;

  case 103: /* alter_action: drop_action  */
#line 676 "bison_parser.y"
                           { (yyval.alter_action_t) = (yyvsp[0].drop_action_t); }
#line 4014 "bison_parser.cpp"
    break;

  case 104: /* drop_action: DROP COLUMN opt_exists IDENTIFIER  */
#line 678 "bison_parser.y"
                                                {
  (yyval.drop_action_t) = new DropColumnAction((yyvsp[0].sval));
  (yyval.drop_action_t)->ifExists = (yyvsp[-1].bval);
}
#line 4023 "bison_parser.cpp"
    break;

  case 105: /* delete_statement: DELETE FROM table_name opt_where  */
#line 688 "bison_parser.y"
                                                    {
  (yyval.delete_stmt) = new DeleteStatement();
  (yyval.delete_stmt)->schema = (yyvsp[-1].table_name).schema;
  (yyval.delete_stmt)->tableName = (yyvsp[-1].table_name).name;
  (yyval.delete_stmt)->expr = (yyvsp[0].expr);
}
#line 4034 "bison_parser.cpp"
    break;

  case 106: /* truncate_statement: TRUNCATE table_name  */
#line 695 "bison_parser.y"
                                         {
  (yyval.delete_stmt) = new DeleteStatement();
  (yyval.delete_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.delete_stmt)->tableName = (yyvsp[0].table_name).name;
}
#line 4044 "bison_parser.cpp"
    break;

  case 107: /* insert_statement: INSERT INTO table_name opt_column_list VALUES list_of_list  */
#line 706 "bison_parser.y"
                                                                              {
  (yyval.insert_stmt) = new InsertStatement(kInsertValues);
  (yyval.insert_stmt)->schema = (yyvsp[-3].table_name).schema;
  (yyval.insert_stmt)->tableName = (yyvsp[-3].table_name).name;
  (yyval.insert_stmt)->columns = (yyvsp[-2].str_vec);
  (yyval.insert_stmt)->values = (yyvsp[0].list_vec);
}
#line 4056 "bison_parser.cpp"
    break;

  case 108: /* insert_statement: INSERT INTO table_name opt_column_list select_no_paren  */
#line 713 "bison_parser.y"
                                                         {
  (yyval.insert_stmt) = new InsertStatement(kInsertSelect);
  (yyval.insert_stmt)->schema = (yyvsp[-2].table_name).schema;
  (yyval.insert_stmt)->tableName = (yyvsp[-2].table_name).name;
  (yyval.insert_stmt)->columns = (yyvsp[-1].str_vec);
  (yyval.insert_stmt)->select = (yyvsp[0].select_stmt);
}
#line 4068 "bison_parser.cpp"
    break;

  case 109: /* opt_column_list: '(' ident_commalist ')'  */
#line 721 "bison_parser.y"
                                          { (yyval.str_vec) = (yyvsp[-1].str_vec); }
#line 4074 "bison_parser.cpp"
    break;

  case 110: /* opt_column_list: %empty  */
#line 722 "bison_parser.y"
              { (yyval.str_vec) = nullptr; }
#line 4080 "bison_parser.cpp"
    break;

  case 111: /* update_statement: UPDATE table_ref_name_no_alias SET update_clause_commalist opt_where  */
#line 729 "bison_parser.y"
                                                                                        {
  (yyval.update_stmt) = new UpdateStatement();
  (yyval.update_stmt)->table = (yyvsp[-3].table);
  (yyval.update_stmt)->updates = (yyvsp[-1].update_vec);
  (yyval.update_stmt)->where = (yyvsp[0].expr);
}
#line 4091 "bison_parser.cpp"
    break;

  case 112: /* update_clause_commalist: update_clause  */
#line 736 "bison_parser.y"
                                        {
  (yyval.update_vec) = new std::vector<UpdateClause*>();
  (yyval.update_vec)->push_back((yyvsp[0].update_t));
}
#line 4100 "bison_parser.cpp"
    break;

  case 113: /* update_clause_commalist: update_clause_commalist ',' update_clause  */
#line 740 "bison_parser.y"
                                            {
  (yyvsp[-2].update_vec)->push_back((yyvsp[0].update_t));
  (yyval.update_vec) = (yyvsp[-2].update_vec);
}
#line 4109 "bison_parser.cpp"
    break;

  case 114: /* update_clause: IDENTIFIER '=' expr  */
#line 745 "bison_parser.y"
                                    {
  (yyval.update_t) = new UpdateClause();
  (yyval.update_t)->column = (yyvsp[-2].sval);
  (yyval.update_t)->value = (yyvsp[0].expr);
}
#line 4119 "bison_parser.cpp"
    break;

  case 115: /* select_statement: opt_with_clause select_with_paren  */
#line 755 "bison_parser.y"
                                                     {
  (yyval.select_stmt) = (yyvsp[0].select_stmt);
  (yyval.select_stmt)->withDescriptions = (yyvsp[-1].with_description_vec);
}
#line 4128 "bison_parser.cpp"
    break;

  case 116: /* select_statement: opt_with_clause select_no_paren  */
#line 759 "bison_parser.y"
                                  {
  (yyval.select_stmt) = (yyvsp[0].select_stmt);
  (yyval.select_stmt)->withDescriptions = (yyvsp[-1].with_description_vec);
}
#line 4137 "bison_parser.cpp"
    break;

  case 117: /* select_statement: opt_with_clause select_with_paren set_operator select_within_set_operation opt_order opt_limit  */
#line 763 "bison_parser.y"
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
#line 4153 "bison_parser.cpp"
    break;

  case 120: /* select_within_set_operation_no_parentheses: select_clause  */
#line 777 "bison_parser.y"
                                                           { (yyval.select_stmt) = (yyvsp[0].select_stmt); }
#line 4159 "bison_parser.cpp"
    break;

  case 121: /* select_within_set_operation_no_parentheses: select_clause set_operator select_within_set_operation  */
#line 778 "bison_parser.y"
                                                         {
  (yyval.select_stmt) = (yyvsp[-2].select_stmt);
  if ((yyval.select_stmt)->setOperations == nullptr) {
    (yyval.select_stmt)->setOperations = new std::vector<SetOperation*>();
  }
  (yyval.select_stmt)->setOperations->push_back((yyvsp[-1].set_operator_t));
  (yyval.select_stmt)->setOperations->back()->nestedSelectStatement = (yyvsp[0].select_stmt);
}
#line 4172 "bison_parser.cpp"
    break;

  case 122: /* select_with_paren: '(' select_no_paren ')'  */
#line 787 "bison_parser.y"
                                            { (yyval.select_stmt) = (yyvsp[-1].select_stmt); }
#line 4178 "bison_parser.cpp"
    break;

  case 123: /* select_with_paren: '(' select_with_paren ')'  */
#line 788 "bison_parser.y"
                            { (yyval.select_stmt) = (yyvsp[-1].select_stmt); }
#line 4184 "bison_parser.cpp"
    break;

  case 124: /* select_no_paren: select_clause opt_order opt_limit opt_locking_clause  */
#line 790 "bison_parser.y"
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
#line 4203 "bison_parser.cpp"
    break;

  case 125: /* select_no_paren: select_clause set_operator select_within_set_operation opt_order opt_limit opt_locking_clause  */
#line 804 "bison_parser.y"
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
#line 4219 "bison_parser.cpp"
    break;

  case 126: /* set_operator: set_type opt_all  */
#line 816 "bison_parser.y"
                                {
  (yyval.set_operator_t) = (yyvsp[-1].set_operator_t);
  (yyval.set_operator_t)->isAll = (yyvsp[0].bval);
}
#line 4228 "bison_parser.cpp"
    break;

  case 127: /* set_type: UNION  */
#line 821 "bison_parser.y"
                 {
  (yyval.set_operator_t) = new SetOperation();
  (yyval.set_operator_t)->setType = SetType::kSetUnion;
}
#line 4237 "bison_parser.cpp"
    break;

  case 128: /* set_type: INTERSECT  */
#line 825 "bison_parser.y"
            {
  (yyval.set_operator_t) = new SetOperation();
  (yyval.set_operator_t)->setType = SetType::kSetIntersect;
}
#line 4246 "bison_parser.cpp"
    break;

  case 129: /* set_type: EXCEPT  */
#line 829 "bison_parser.y"
         {
  (yyval.set_operator_t) = new SetOperation();
  (yyval.set_operator_t)->setType = SetType::kSetExcept;
}
#line 4255 "bison_parser.cpp"
    break;

  case 130: /* opt_all: ALL  */
#line 834 "bison_parser.y"
              { (yyval.bval) = true; }
#line 4261 "bison_parser.cpp"
    break;

  case 131: /* opt_all: %empty  */
#line 835 "bison_parser.y"
              { (yyval.bval) = false; }
#line 4267 "bison_parser.cpp"
    break;

  case 132: /* select_clause: SELECT opt_top opt_distinct select_list opt_from_clause opt_where opt_group  */
#line 837 "bison_parser.y"
                                                                                            {
  (yyval.select_stmt) = new SelectStatement();
  (yyval.select_stmt)->limit = (yyvsp[-5].limit);
  (yyval.select_stmt)->selectDistinct = (yyvsp[-4].bval);
  (yyval.select_stmt)->selectList = (yyvsp[-3].expr_vec);
  (yyval.select_stmt)->fromTable = (yyvsp[-2].table);
  (yyval.select_stmt)->whereClause = (yyvsp[-1].expr);
  (yyval.select_stmt)->groupBy = (yyvsp[0].group_t);
}
#line 4281 "bison_parser.cpp"
    break;

  case 133: /* opt_distinct: DISTINCT  */
#line 847 "bison_parser.y"
                        { (yyval.bval) = true; }
#line 4287 "bison_parser.cpp"
    break;

  case 134: /* opt_distinct: %empty  */
#line 848 "bison_parser.y"
              { (yyval.bval) = false; }
#line 4293 "bison_parser.cpp"
    break;

  case 136: /* opt_from_clause: from_clause  */
#line 852 "bison_parser.y"
                              { (yyval.table) = (yyvsp[0].table); }
#line 4299 "bison_parser.cpp"
    break;

  case 137: /* opt_from_clause: %empty  */
#line 853 "bison_parser.y"
              { (yyval.table) = nullptr; }
#line 4305 "bison_parser.cpp"
    break;

  case 138: /* from_clause: FROM table_ref  */
#line 855 "bison_parser.y"
                             { (yyval.table) = (yyvsp[0].table); }
#line 4311 "bison_parser.cpp"
    break;

  case 139: /* opt_where: WHERE expr  */
#line 857 "bison_parser.y"
                       { (yyval.expr) = (yyvsp[0].expr); }
#line 4317 "bison_parser.cpp"
    break;

  case 140: /* opt_where: %empty  */
#line 858 "bison_parser.y"
              { (yyval.expr) = nullptr; }
#line 4323 "bison_parser.cpp"
    break;

  case 141: /* opt_group: GROUP BY expr_list opt_having  */
#line 860 "bison_parser.y"
                                          {
  (yyval.group_t) = new GroupByDescription();
  (yyval.group_t)->columns = (yyvsp[-1].expr_vec);
  (yyval.group_t)->having = (yyvsp[0].expr);
}
#line 4333 "bison_parser.cpp"
    break;

  case 142: /* opt_group: %empty  */
#line 865 "bison_parser.y"
              { (yyval.group_t) = nullptr; }
#line 4339 "bison_parser.cpp"
    break;

  case 143: /* opt_having: HAVING expr  */
#line 867 "bison_parser.y"
                         { (yyval.expr) = (yyvsp[0].expr); }
#line 4345 "bison_parser.cpp"
    break;

  case 144: /* opt_having: %empty  */
#line 868 "bison_parser.y"
              { (yyval.expr) = nullptr; }
#line 4351 "bison_parser.cpp"
    break;

  case 145: /* opt_order: ORDER BY order_list  */
#line 870 "bison_parser.y"
                                { (yyval.order_vec) = (yyvsp[0].order_vec); }
#line 4357 "bison_parser.cpp"
    break;

  case 146: /* opt_order: %empty  */
#line 871 "bison_parser.y"
              { (yyval.order_vec) = nullptr; }
#line 4363 "bison_parser.cpp"
    break;

  case 147: /* order_list: order_desc  */
#line 873 "bison_parser.y"
                        {
  (yyval.order_vec) = new std::vector<OrderDescription*>();
  (yyval.order_vec)->push_back((yyvsp[0].order));
}
#line 4372 "bison_parser.cpp"
    break;

  case 148: /* order_list: order_list ',' order_desc  */
#line 877 "bison_parser.y"
                            {
  (yyvsp[-2].order_vec)->push_back((yyvsp[0].order));
  (yyval.order_vec) = (yyvsp[-2].order_vec);
}
#line 4381 "bison_parser.cpp"
    break;

  case 149: /* order_desc: expr opt_order_type  */
#line 882 "bison_parser.y"
                                 { (yyval.order) = new OrderDescription((yyvsp[0].order_type), (yyvsp[-1].expr)); }
#line 4387 "bison_parser.cpp"
    break;

  case 150: /* opt_order_type: ASC  */
#line 884 "bison_parser.y"
                     { (yyval.order_type) = kOrderAsc; }
#line 4393 "bison_parser.cpp"
    break;

  case 151: /* opt_order_type: DESC  */
#line 885 "bison_parser.y"
       { (yyval.order_type) = kOrderDesc; }
#line 4399 "bison_parser.cpp"
    break;

  case 152: /* opt_order_type: %empty  */
#line 886 "bison_parser.y"
              { (yyval.order_type) = kOrderAsc; }
#line 4405 "bison_parser.cpp"
    break;

  case 153: /* opt_top: TOP int_literal  */
#line 890 "bison_parser.y"
                          { (yyval.limit) = new LimitDescription((yyvsp[0].expr), nullptr); }
#line 4411 "bison_parser.cpp"
    break;

  case 154: /* opt_top: %empty  */
#line 891 "bison_parser.y"
              { (yyval.limit) = nullptr; }
#line 4417 "bison_parser.cpp"
    break;

  case 155: /* opt_limit: LIMIT expr  */
#line 893 "bison_parser.y"
                       { (yyval.limit) = new LimitDescription((yyvsp[0].expr), nullptr); }
#line 4423 "bison_parser.cpp"
    break;

  case 156: /* opt_limit: OFFSET expr  */
#line 894 "bison_parser.y"
              { (yyval.limit) = new LimitDescription(nullptr, (yyvsp[0].expr)); }
#line 4429 "bison_parser.cpp"
    break;

  case 157: /* opt_limit: LIMIT expr OFFSET expr  */
#line 895 "bison_parser.y"
                         { (yyval.limit) = new LimitDescription((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4435 "bison_parser.cpp"
    break;

  case 158: /* opt_limit: LIMIT ALL  */
#line 896 "bison_parser.y"
            { (yyval.limit) = new LimitDescription(nullptr, nullptr); }
#line 4441 "bison_parser.cpp"
    break;

  case 159: /* opt_limit: LIMIT ALL OFFSET expr  */
#line 897 "bison_parser.y"
                        { (yyval.limit) = new LimitDescription(nullptr, (yyvsp[0].expr)); }
#line 4447 "bison_parser.cpp"
    break;

  case 160: /* opt_limit: %empty  */
#line 898 "bison_parser.y"
              { (yyval.limit) = nullptr; }
#line 4453 "bison_parser.cpp"
    break;

  case 161: /* expr_list: expr_alias  */
#line 903 "bison_parser.y"
                       {
  (yyval.expr_vec) = new std::vector<Expr*>();
  (yyval.expr_vec)->push_back((yyvsp[0].expr));
}
#line 4462 "bison_parser.cpp"
    break;

  case 162: /* expr_list: expr_list ',' expr_alias  */
#line 907 "bison_parser.y"
                           {
  (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr));
  (yyval.expr_vec) = (yyvsp[-2].expr_vec);
}
#line 4471 "bison_parser.cpp"
    break;

  case 163: /* opt_literal_list: literal_list  */
#line 912 "bison_parser.y"
                                { (yyval.expr_vec) = (yyvsp[0].expr_vec); }
#line 4477 "bison_parser.cpp"
    break;

  case 164: /* opt_literal_list: %empty  */
#line 913 "bison_parser.y"
              { (yyval.expr_vec) = nullptr; }
#line 4483 "bison_parser.cpp"
    break;

  case 165: /* list_of_list: list_item  */
#line 915 "bison_parser.y"
                         {
  (yyval.list_vec) = new std::vector<ValueList*>();
  (yyval.list_vec)->push_back((yyvsp[0].expr_vec));
}
#line 4492 "bison_parser.cpp"
    break;

  case 166: /* list_of_list: list_of_list ',' list_item  */
#line 919 "bison_parser.y"
                             {
  (yyvsp[-2].list_vec)->push_back((yyvsp[0].expr_vec));
  (yyval.list_vec) = (yyvsp[-2].list_vec);
}
#line 4501 "bison_parser.cpp"
    break;

  case 167: /* list_item: '(' literal_list ')'  */
#line 924 "bison_parser.y"
                                 {
  (yyval.expr_vec) = (yyvsp[-1].expr_vec);
}
#line 4509 "bison_parser.cpp"
    break;

  case 168: /* literal_list: literal  */
#line 928 "bison_parser.y"
                       {
  (yyval.expr_vec) = new std::vector<Expr*>();
  (yyval.expr_vec)->push_back((yyvsp[0].expr));
}
#line 4518 "bison_parser.cpp"
    break;

  case 169: /* literal_list: literal_list ',' literal  */
#line 932 "bison_parser.y"
                           {
  (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr));
  (yyval.expr_vec) = (yyvsp[-2].expr_vec);
}
#line 4527 "bison_parser.cpp"
    break;

  case 170: /* expr_alias: expr opt_alias  */
#line 937 "bison_parser.y"
                            {
  (yyval.expr) = (yyvsp[-1].expr);
  if ((yyvsp[0].alias_t)) {
    (yyval.expr)->alias = strdup((yyvsp[0].alias_t)->name);
    delete (yyvsp[0].alias_t);
  }
}
#line 4539 "bison_parser.cpp"
    break;

  case 176: /* operand: '(' expr ')'  */
#line 947 "bison_parser.y"
                       { (yyval.expr) = (yyvsp[-1].expr); }
#line 4545 "bison_parser.cpp"
    break;

  case 186: /* operand: '(' select_no_paren ')'  */
#line 949 "bison_parser.y"
                                         {
  (yyval.expr) = Expr::makeSelect((yyvsp[-1].select_stmt));
}
#line 4553 "bison_parser.cpp"
    break;

  case 189: /* unary_expr: '-' operand  */
#line 955 "bison_parser.y"
                         { (yyval.expr) = Expr::makeOpUnary(kOpUnaryMinus, (yyvsp[0].expr)); }
#line 4559 "bison_parser.cpp"
    break;

  case 190: /* unary_expr: NOT operand  */
#line 956 "bison_parser.y"
              { (yyval.expr) = Expr::makeOpUnary(kOpNot, (yyvsp[0].expr)); }
#line 4565 "bison_parser.cpp"
    break;

  case 191: /* unary_expr: operand ISNULL  */
#line 957 "bison_parser.y"
                 { (yyval.expr) = Expr::makeOpUnary(kOpIsNull, (yyvsp[-1].expr)); }
#line 4571 "bison_parser.cpp"
    break;

  case 192: /* unary_expr: operand IS NULL  */
#line 958 "bison_parser.y"
                  { (yyval.expr) = Expr::makeOpUnary(kOpIsNull, (yyvsp[-2].expr)); }
#line 4577 "bison_parser.cpp"
    break;

  case 193: /* unary_expr: operand IS NOT NULL  */
#line 959 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeOpUnary(kOpIsNull, (yyvsp[-3].expr))); }
#line 4583 "bison_parser.cpp"
    break;

  case 195: /* binary_expr: operand '-' operand  */
#line 961 "bison_parser.y"
                                              { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpMinus, (yyvsp[0].expr)); }
#line 4589 "bison_parser.cpp"
    break;

  case 196: /* binary_expr: operand '+' operand  */
#line 962 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpPlus, (yyvsp[0].expr)); }
#line 4595 "bison_parser.cpp"
    break;

  case 197: /* binary_expr: operand '/' operand  */
#line 963 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpSlash, (yyvsp[0].expr)); }
#line 4601 "bison_parser.cpp"
    break;

  case 198: /* binary_expr: operand '*' operand  */
#line 964 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpAsterisk, (yyvsp[0].expr)); }
#line 4607 "bison_parser.cpp"
    break;

  case 199: /* binary_expr: operand '%' operand  */
#line 965 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpPercentage, (yyvsp[0].expr)); }
#line 4613 "bison_parser.cpp"
    break;

  case 200: /* binary_expr: operand '^' operand  */
#line 966 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpCaret, (yyvsp[0].expr)); }
#line 4619 "bison_parser.cpp"
    break;

  case 201: /* binary_expr: operand LIKE operand  */
#line 967 "bison_parser.y"
                       { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpLike, (yyvsp[0].expr)); }
#line 4625 "bison_parser.cpp"
    break;

  case 202: /* binary_expr: operand NOT LIKE operand  */
#line 968 "bison_parser.y"
                           { (yyval.expr) = Expr::makeOpBinary((yyvsp[-3].expr), kOpNotLike, (yyvsp[0].expr)); }
#line 4631 "bison_parser.cpp"
    break;

  case 203: /* binary_expr: operand ILIKE operand  */
#line 969 "bison_parser.y"
                        { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpILike, (yyvsp[0].expr)); }
#line 4637 "bison_parser.cpp"
    break;

  case 204: /* binary_expr: operand CONCAT operand  */
#line 970 "bison_parser.y"
                         { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpConcat, (yyvsp[0].expr)); }
#line 4643 "bison_parser.cpp"
    break;

  case 205: /* logic_expr: expr AND expr  */
#line 972 "bison_parser.y"
                           { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpAnd, (yyvsp[0].expr)); }
#line 4649 "bison_parser.cpp"
    break;

  case 206: /* logic_expr: expr OR expr  */
#line 973 "bison_parser.y"
               { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpOr, (yyvsp[0].expr)); }
#line 4655 "bison_parser.cpp"
    break;

  case 207: /* in_expr: operand IN '(' expr_list ')'  */
#line 975 "bison_parser.y"
                                       { (yyval.expr) = Expr::makeInOperator((yyvsp[-4].expr), (yyvsp[-1].expr_vec)); }
#line 4661 "bison_parser.cpp"
    break;

  case 208: /* in_expr: operand NOT IN '(' expr_list ')'  */
#line 976 "bison_parser.y"
                                   { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeInOperator((yyvsp[-5].expr), (yyvsp[-1].expr_vec))); }
#line 4667 "bison_parser.cpp"
    break;

  case 209: /* in_expr: operand IN '(' select_no_paren ')'  */
#line 977 "bison_parser.y"
                                     { (yyval.expr) = Expr::makeInOperator((yyvsp[-4].expr), (yyvsp[-1].select_stmt)); }
#line 4673 "bison_parser.cpp"
    break;

  case 210: /* in_expr: operand NOT IN '(' select_no_paren ')'  */
#line 978 "bison_parser.y"
                                         { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeInOperator((yyvsp[-5].expr), (yyvsp[-1].select_stmt))); }
#line 4679 "bison_parser.cpp"
    break;

  case 211: /* case_expr: CASE expr case_list END  */
#line 982 "bison_parser.y"
                                    { (yyval.expr) = Expr::makeCase((yyvsp[-2].expr), (yyvsp[-1].expr), nullptr); }
#line 4685 "bison_parser.cpp"
    break;

  case 212: /* case_expr: CASE expr case_list ELSE expr END  */
#line 983 "bison_parser.y"
                                    { (yyval.expr) = Expr::makeCase((yyvsp[-4].expr), (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 4691 "bison_parser.cpp"
    break;

  case 213: /* case_expr: CASE case_list END  */
#line 984 "bison_parser.y"
                     { (yyval.expr) = Expr::makeCase(nullptr, (yyvsp[-1].expr), nullptr); }
#line 4697 "bison_parser.cpp"
    break;

  case 214: /* case_expr: CASE case_list ELSE expr END  */
#line 985 "bison_parser.y"
                               { (yyval.expr) = Expr::makeCase(nullptr, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 4703 "bison_parser.cpp"
    break;

  case 215: /* case_list: WHEN expr THEN expr  */
#line 987 "bison_parser.y"
                                { (yyval.expr) = Expr::makeCaseList(Expr::makeCaseListElement((yyvsp[-2].expr), (yyvsp[0].expr))); }
#line 4709 "bison_parser.cpp"
    break;

  case 216: /* case_list: case_list WHEN expr THEN expr  */
#line 988 "bison_parser.y"
                                { (yyval.expr) = Expr::caseListAppend((yyvsp[-4].expr), Expr::makeCaseListElement((yyvsp[-2].expr), (yyvsp[0].expr))); }
#line 4715 "bison_parser.cpp"
    break;

  case 217: /* exists_expr: EXISTS '(' select_no_paren ')'  */
#line 990 "bison_parser.y"
                                             { (yyval.expr) = Expr::makeExists((yyvsp[-1].select_stmt)); }
#line 4721 "bison_parser.cpp"
    break;

  case 218: /* exists_expr: NOT EXISTS '(' select_no_paren ')'  */
#line 991 "bison_parser.y"
                                     { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeExists((yyvsp[-1].select_stmt))); }
#line 4727 "bison_parser.cpp"
    break;

  case 219: /* comp_expr: operand '=' operand  */
#line 993 "bison_parser.y"
                                { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpEquals, (yyvsp[0].expr)); }
#line 4733 "bison_parser.cpp"
    break;

  case 220: /* comp_expr: operand EQUALS operand  */
#line 994 "bison_parser.y"
                         { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpEquals, (yyvsp[0].expr)); }
#line 4739 "bison_parser.cpp"
    break;

  case 221: /* comp_expr: operand NOTEQUALS operand  */
#line 995 "bison_parser.y"
                            { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpNotEquals, (yyvsp[0].expr)); }
#line 4745 "bison_parser.cpp"
    break;

  case 222: /* comp_expr: operand '<' operand  */
#line 996 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpLess, (yyvsp[0].expr)); }
#line 4751 "bison_parser.cpp"
    break;

  case 223: /* comp_expr: operand '>' operand  */
#line 997 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpGreater, (yyvsp[0].expr)); }
#line 4757 "bison_parser.cpp"
    break;

  case 224: /* comp_expr: operand LESSEQ operand  */
#line 998 "bison_parser.y"
                         { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpLessEq, (yyvsp[0].expr)); }
#line 4763 "bison_parser.cpp"
    break;

  case 225: /* comp_expr: operand GREATEREQ operand  */
#line 999 "bison_parser.y"
                            { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpGreaterEq, (yyvsp[0].expr)); }
#line 4769 "bison_parser.cpp"
    break;

  case 226: /* function_expr: IDENTIFIER '(' ')'  */
#line 1001 "bison_parser.y"
                                   { (yyval.expr) = Expr::makeFunctionRef((yyvsp[-2].sval), new std::vector<Expr*>(), false); }
#line 4775 "bison_parser.cpp"
    break;

  case 227: /* function_expr: IDENTIFIER '(' opt_distinct expr_list ')'  */
#line 1002 "bison_parser.y"
                                            { (yyval.expr) = Expr::makeFunctionRef((yyvsp[-4].sval), (yyvsp[-1].expr_vec), (yyvsp[-2].bval)); }
#line 4781 "bison_parser.cpp"
    break;

  case 228: /* extract_expr: EXTRACT '(' datetime_field FROM expr ')'  */
#line 1004 "bison_parser.y"
                                                        { (yyval.expr) = Expr::makeExtract((yyvsp[-3].datetime_field), (yyvsp[-1].expr)); }
#line 4787 "bison_parser.cpp"
    break;

  case 229: /* cast_expr: CAST '(' expr AS column_type ')'  */
#line 1006 "bison_parser.y"
                                             { (yyval.expr) = Expr::makeCast((yyvsp[-3].expr), (yyvsp[-1].column_type_t)); }
#line 4793 "bison_parser.cpp"
    break;

  case 230: /* datetime_field: SECOND  */
#line 1008 "bison_parser.y"
                        { (yyval.datetime_field) = kDatetimeSecond; }
#line 4799 "bison_parser.cpp"
    break;

  case 231: /* datetime_field: MINUTE  */
#line 1009 "bison_parser.y"
         { (yyval.datetime_field) = kDatetimeMinute; }
#line 4805 "bison_parser.cpp"
    break;

  case 232: /* datetime_field: HOUR  */
#line 1010 "bison_parser.y"
       { (yyval.datetime_field) = kDatetimeHour; }
#line 4811 "bison_parser.cpp"
    break;

  case 233: /* datetime_field: DAY  */
#line 1011 "bison_parser.y"
      { (yyval.datetime_field) = kDatetimeDay; }
#line 4817 "bison_parser.cpp"
    break;

  case 234: /* datetime_field: MONTH  */
#line 1012 "bison_parser.y"
        { (yyval.datetime_field) = kDatetimeMonth; }
#line 4823 "bison_parser.cpp"
    break;

  case 235: /* datetime_field: YEAR  */
#line 1013 "bison_parser.y"
       { (yyval.datetime_field) = kDatetimeYear; }
#line 4829 "bison_parser.cpp"
    break;

  case 236: /* datetime_field_plural: SECONDS  */
#line 1015 "bison_parser.y"
                                { (yyval.datetime_field) = kDatetimeSecond; }
#line 4835 "bison_parser.cpp"
    break;

  case 237: /* datetime_field_plural: MINUTES  */
#line 1016 "bison_parser.y"
          { (yyval.datetime_field) = kDatetimeMinute; }
#line 4841 "bison_parser.cpp"
    break;

  case 238: /* datetime_field_plural: HOURS  */
#line 1017 "bison_parser.y"
        { (yyval.datetime_field) = kDatetimeHour; }
#line 4847 "bison_parser.cpp"
    break;

  case 239: /* datetime_field_plural: DAYS  */
#line 1018 "bison_parser.y"
       { (yyval.datetime_field) = kDatetimeDay; }
#line 4853 "bison_parser.cpp"
    break;

  case 240: /* datetime_field_plural: MONTHS  */
#line 1019 "bison_parser.y"
         { (yyval.datetime_field) = kDatetimeMonth; }
#line 4859 "bison_parser.cpp"
    break;

  case 241: /* datetime_field_plural: YEARS  */
#line 1020 "bison_parser.y"
        { (yyval.datetime_field) = kDatetimeYear; }
#line 4865 "bison_parser.cpp"
    break;

  case 244: /* array_expr: ARRAY '[' expr_list ']'  */
#line 1024 "bison_parser.y"
                                     { (yyval.expr) = Expr::makeArray((yyvsp[-1].expr_vec)); }
#line 4871 "bison_parser.cpp"
    break;

  case 245: /* array_index: operand '[' int_literal ']'  */
#line 1026 "bison_parser.y"
                                          { (yyval.expr) = Expr::makeArrayIndex((yyvsp[-3].expr), (yyvsp[-1].expr)->ival); }
#line 4877 "bison_parser.cpp"
    break;

  case 246: /* between_expr: operand BETWEEN operand AND operand  */
#line 1028 "bison_parser.y"
                                                   { (yyval.expr) = Expr::makeBetween((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4883 "bison_parser.cpp"
    break;

  case 247: /* column_name: IDENTIFIER  */
#line 1030 "bison_parser.y"
                         { (yyval.expr) = Expr::makeColumnRef((yyvsp[0].sval)); }
#line 4889 "bison_parser.cpp"
    break;

  case 248: /* column_name: IDENTIFIER '.' IDENTIFIER  */
#line 1031 "bison_parser.y"
                            { (yyval.expr) = Expr::makeColumnRef((yyvsp[-2].sval), (yyvsp[0].sval)); }
#line 4895 "bison_parser.cpp"
    break;

  case 249: /* column_name: '*'  */
#line 1032 "bison_parser.y"
      { (yyval.expr) = Expr::makeStar(); }
#line 4901 "bison_parser.cpp"
    break;

  case 250: /* column_name: IDENTIFIER '.' '*'  */
#line 1033 "bison_parser.y"
                     { (yyval.expr) = Expr::makeStar((yyvsp[-2].sval)); }
#line 4907 "bison_parser.cpp"
    break;

  case 258: /* string_literal: STRING  */
#line 1037 "bison_parser.y"
                        { (yyval.expr) = Expr::makeLiteral((yyvsp[0].sval)); }
#line 4913 "bison_parser.cpp"
    break;

  case 259: /* bool_literal: TRUE  */
#line 1039 "bison_parser.y"
                    { (yyval.expr) = Expr::makeLiteral(true); }
#line 4919 "bison_parser.cpp"
    break;

  case 260: /* bool_literal: FALSE  */
#line 1040 "bison_parser.y"
        { (yyval.expr) = Expr::makeLiteral(false); }
#line 4925 "bison_parser.cpp"
    break;

  case 261: /* num_literal: FLOATVAL  */
#line 1042 "bison_parser.y"
                       { (yyval.expr) = Expr::makeLiteral((yyvsp[0].fval)); }
#line 4931 "bison_parser.cpp"
    break;

  case 263: /* int_literal: INTVAL  */
#line 1045 "bison_parser.y"
                     { (yyval.expr) = Expr::makeLiteral((yyvsp[0].ival)); }
#line 4937 "bison_parser.cpp"
    break;

  case 264: /* null_literal: NULL  */
#line 1047 "bison_parser.y"
                    { (yyval.expr) = Expr::makeNullLiteral(); }
#line 4943 "bison_parser.cpp"
    break;

  case 265: /* date_literal: DATE STRING  */
#line 1049 "bison_parser.y"
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
#line 4958 "bison_parser.cpp"
    break;

  case 266: /* interval_literal: int_literal duration_field  */
#line 1060 "bison_parser.y"
                                              {
  (yyval.expr) = Expr::makeIntervalLiteral((yyvsp[-1].expr)->ival, (yyvsp[0].datetime_field));
  delete (yyvsp[-1].expr);
}
#line 4967 "bison_parser.cpp"
    break;

  case 267: /* interval_literal: INTERVAL STRING datetime_field  */
#line 1064 "bison_parser.y"
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
#line 4983 "bison_parser.cpp"
    break;

  case 268: /* interval_literal: INTERVAL STRING  */
#line 1075 "bison_parser.y"
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
#line 5019 "bison_parser.cpp"
    break;

  case 269: /* param_expr: '?'  */
#line 1107 "bison_parser.y"
                 {
  (yyval.expr) = Expr::makeParameter(yylloc.total_column);
  (yyval.expr)->ival2 = yyloc.param_list.size();
  yyloc.param_list.push_back((yyval.expr));
}
#line 5029 "bison_parser.cpp"
    break;

  case 271: /* table_ref: table_ref_commalist ',' table_ref_atomic  */
#line 1116 "bison_parser.y"
                                                                        {
  (yyvsp[-2].table_vec)->push_back((yyvsp[0].table));
  auto tbl = new TableRef(kTableCrossProduct);
  tbl->list = (yyvsp[-2].table_vec);
  (yyval.table) = tbl;
}
#line 5040 "bison_parser.cpp"
    break;

  case 275: /* nonjoin_table_ref_atomic: '(' select_statement ')' opt_table_alias  */
#line 1125 "bison_parser.y"
                                                                                     {
  auto tbl = new TableRef(kTableSelect);
  tbl->select = (yyvsp[-2].select_stmt);
  tbl->alias = (yyvsp[0].alias_t);
  (yyval.table) = tbl;
}
#line 5051 "bison_parser.cpp"
    break;

  case 276: /* table_ref_commalist: table_ref_atomic  */
#line 1132 "bison_parser.y"
                                       {
  (yyval.table_vec) = new std::vector<TableRef*>();
  (yyval.table_vec)->push_back((yyvsp[0].table));
}
#line 5060 "bison_parser.cpp"
    break;

  case 277: /* table_ref_commalist: table_ref_commalist ',' table_ref_atomic  */
#line 1136 "bison_parser.y"
                                           {
  (yyvsp[-2].table_vec)->push_back((yyvsp[0].table));
  (yyval.table_vec) = (yyvsp[-2].table_vec);
}
#line 5069 "bison_parser.cpp"
    break;

  case 278: /* table_ref_name: table_name opt_table_alias  */
#line 1141 "bison_parser.y"
                                            {
  auto tbl = new TableRef(kTableName);
  tbl->schema = (yyvsp[-1].table_name).schema;
  tbl->name = (yyvsp[-1].table_name).name;
  tbl->alias = (yyvsp[0].alias_t);
  (yyval.table) = tbl;
}
#line 5081 "bison_parser.cpp"
    break;

  case 279: /* table_ref_name_no_alias: table_name  */
#line 1149 "bison_parser.y"
                                     {
  (yyval.table) = new TableRef(kTableName);
  (yyval.table)->schema = (yyvsp[0].table_name).schema;
  (yyval.table)->name = (yyvsp[0].table_name).name;
}
#line 5091 "bison_parser.cpp"
    break;

  case 280: /* table_name: IDENTIFIER  */
#line 1155 "bison_parser.y"
                        {
  (yyval.table_name).schema = nullptr;
  (yyval.table_name).name = (yyvsp[0].sval);
}
#line 5100 "bison_parser.cpp"
    break;

  case 281: /* table_name: IDENTIFIER '.' IDENTIFIER  */
#line 1159 "bison_parser.y"
                            {
  (yyval.table_name).schema = (yyvsp[-2].sval);
  (yyval.table_name).name = (yyvsp[0].sval);
}
#line 5109 "bison_parser.cpp"
    break;

  case 282: /* opt_index_name: IDENTIFIER  */
#line 1164 "bison_parser.y"
                            { (yyval.sval) = (yyvsp[0].sval); }
#line 5115 "bison_parser.cpp"
    break;

  case 283: /* opt_index_name: %empty  */
#line 1165 "bison_parser.y"
              { (yyval.sval) = nullptr; }
#line 5121 "bison_parser.cpp"
    break;

  case 285: /* table_alias: AS IDENTIFIER '(' ident_commalist ')'  */
#line 1167 "bison_parser.y"
                                                            { (yyval.alias_t) = new Alias((yyvsp[-3].sval), (yyvsp[-1].str_vec)); }
#line 5127 "bison_parser.cpp"
    break;

  case 287: /* opt_table_alias: %empty  */
#line 1169 "bison_parser.y"
                                            { (yyval.alias_t) = nullptr; }
#line 5133 "bison_parser.cpp"
    break;

  case 288: /* alias: AS IDENTIFIER  */
#line 1171 "bison_parser.y"
                      { (yyval.alias_t) = new Alias((yyvsp[0].sval)); }
#line 5139 "bison_parser.cpp"
    break;

  case 289: /* alias: IDENTIFIER  */
#line 1172 "bison_parser.y"
             { (yyval.alias_t) = new Alias((yyvsp[0].sval)); }
#line 5145 "bison_parser.cpp"
    break;

  case 291: /* opt_alias: %empty  */
#line 1174 "bison_parser.y"
                                { (yyval.alias_t) = nullptr; }
#line 5151 "bison_parser.cpp"
    break;

  case 292: /* opt_locking_clause: opt_locking_clause_list  */
#line 1180 "bison_parser.y"
                                             { (yyval.locking_clause_vec) = (yyvsp[0].locking_clause_vec); }
#line 5157 "bison_parser.cpp"
    break;

  case 293: /* opt_locking_clause: %empty  */
#line 1181 "bison_parser.y"
              { (yyval.locking_clause_vec) = nullptr; }
#line 5163 "bison_parser.cpp"
    break;

  case 294: /* opt_locking_clause_list: locking_clause  */
#line 1183 "bison_parser.y"
                                         {
  (yyval.locking_clause_vec) = new std::vector<LockingClause*>();
  (yyval.locking_clause_vec)->push_back((yyvsp[0].locking_t));
}
#line 5172 "bison_parser.cpp"
    break;

  case 295: /* opt_locking_clause_list: opt_locking_clause_list locking_clause  */
#line 1187 "bison_parser.y"
                                         {
  (yyvsp[-1].locking_clause_vec)->push_back((yyvsp[0].locking_t));
  (yyval.locking_clause_vec) = (yyvsp[-1].locking_clause_vec);
}
#line 5181 "bison_parser.cpp"
    break;

  case 296: /* locking_clause: FOR row_lock_mode opt_row_lock_policy  */
#line 1192 "bison_parser.y"
                                                       {
  (yyval.locking_t) = new LockingClause();
  (yyval.locking_t)->rowLockMode = (yyvsp[-1].lock_mode_t);
  (yyval.locking_t)->rowLockWaitPolicy = (yyvsp[0].lock_wait_policy_t);
  (yyval.locking_t)->tables = nullptr;
}
#line 5192 "bison_parser.cpp"
    break;

  case 297: /* locking_clause: FOR row_lock_mode OF ident_commalist opt_row_lock_policy  */
#line 1198 "bison_parser.y"
                                                           {
  (yyval.locking_t) = new LockingClause();
  (yyval.locking_t)->rowLockMode = (yyvsp[-3].lock_mode_t);
  (yyval.locking_t)->tables = (yyvsp[-1].str_vec);
  (yyval.locking_t)->rowLockWaitPolicy = (yyvsp[0].lock_wait_policy_t);
}
#line 5203 "bison_parser.cpp"
    break;

  case 298: /* row_lock_mode: UPDATE  */
#line 1205 "bison_parser.y"
                       { (yyval.lock_mode_t) = RowLockMode::ForUpdate; }
#line 5209 "bison_parser.cpp"
    break;

  case 299: /* row_lock_mode: NO KEY UPDATE  */
#line 1206 "bison_parser.y"
                { (yyval.lock_mode_t) = RowLockMode::ForNoKeyUpdate; }
#line 5215 "bison_parser.cpp"
    break;

  case 300: /* row_lock_mode: SHARE  */
#line 1207 "bison_parser.y"
        { (yyval.lock_mode_t) = RowLockMode::ForShare; }
#line 5221 "bison_parser.cpp"
    break;

  case 301: /* row_lock_mode: KEY SHARE  */
#line 1208 "bison_parser.y"
            { (yyval.lock_mode_t) = RowLockMode::ForKeyShare; }
#line 5227 "bison_parser.cpp"
    break;

  case 302: /* opt_row_lock_policy: SKIP LOCKED  */
#line 1210 "bison_parser.y"
                                  { (yyval.lock_wait_policy_t) = RowLockWaitPolicy::SkipLocked; }
#line 5233 "bison_parser.cpp"
    break;

  case 303: /* opt_row_lock_policy: NOWAIT  */
#line 1211 "bison_parser.y"
         { (yyval.lock_wait_policy_t) = RowLockWaitPolicy::NoWait; }
#line 5239 "bison_parser.cpp"
    break;

  case 304: /* opt_row_lock_policy: %empty  */
#line 1212 "bison_parser.y"
              { (yyval.lock_wait_policy_t) = RowLockWaitPolicy::None; }
#line 5245 "bison_parser.cpp"
    break;

  case 306: /* opt_with_clause: %empty  */
#line 1218 "bison_parser.y"
                                            { (yyval.with_description_vec) = nullptr; }
#line 5251 "bison_parser.cpp"
    break;

  case 307: /* with_clause: WITH with_description_list  */
#line 1220 "bison_parser.y"
                                         { (yyval.with_description_vec) = (yyvsp[0].with_description_vec); }
#line 5257 "bison_parser.cpp"
    break;

  case 308: /* with_description_list: with_description  */
#line 1222 "bison_parser.y"
                                         {
  (yyval.with_description_vec) = new std::vector<WithDescription*>();
  (yyval.with_description_vec)->push_back((yyvsp[0].with_description_t));
}
#line 5266 "bison_parser.cpp"
    break;

  case 309: /* with_description_list: with_description_list ',' with_description  */
#line 1226 "bison_parser.y"
                                             {
  (yyvsp[-2].with_description_vec)->push_back((yyvsp[0].with_description_t));
  (yyval.with_description_vec) = (yyvsp[-2].with_description_vec);
}
#line 5275 "bison_parser.cpp"
    break;

  case 310: /* with_description: IDENTIFIER AS select_with_paren  */
#line 1231 "bison_parser.y"
                                                   {
  (yyval.with_description_t) = new WithDescription();
  (yyval.with_description_t)->alias = (yyvsp[-2].sval);
  (yyval.with_description_t)->select = (yyvsp[0].select_stmt);
}
#line 5285 "bison_parser.cpp"
    break;

  case 311: /* join_clause: table_ref_atomic NATURAL JOIN nonjoin_table_ref_atomic  */
#line 1241 "bison_parser.y"
                                                                     {
  (yyval.table) = new TableRef(kTableJoin);
  (yyval.table)->join = new JoinDefinition();
  (yyval.table)->join->type = kJoinNatural;
  (yyval.table)->join->left = (yyvsp[-3].table);
  (yyval.table)->join->right = (yyvsp[0].table);
}
#line 5297 "bison_parser.cpp"
    break;

  case 312: /* join_clause: table_ref_atomic opt_join_type JOIN table_ref_atomic ON join_condition  */
#line 1248 "bison_parser.y"
                                                                         {
  (yyval.table) = new TableRef(kTableJoin);
  (yyval.table)->join = new JoinDefinition();
  (yyval.table)->join->type = (JoinType)(yyvsp[-4].join_type);
  (yyval.table)->join->left = (yyvsp[-5].table);
  (yyval.table)->join->right = (yyvsp[-2].table);
  (yyval.table)->join->condition = (yyvsp[0].expr);
}
#line 5310 "bison_parser.cpp"
    break;

  case 313: /* join_clause: table_ref_atomic opt_join_type JOIN table_ref_atomic USING '(' column_name ')'  */
#line 1256 "bison_parser.y"
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
#line 5330 "bison_parser.cpp"
    break;

  case 314: /* opt_join_type: INNER  */
#line 1272 "bison_parser.y"
                      { (yyval.join_type) = kJoinInner; }
#line 5336 "bison_parser.cpp"
    break;

  case 315: /* opt_join_type: LEFT OUTER  */
#line 1273 "bison_parser.y"
             { (yyval.join_type) = kJoinLeft; }
#line 5342 "bison_parser.cpp"
    break;

  case 316: /* opt_join_type: LEFT  */
#line 1274 "bison_parser.y"
       { (yyval.join_type) = kJoinLeft; }
#line 5348 "bison_parser.cpp"
    break;

  case 317: /* opt_join_type: RIGHT OUTER  */
#line 1275 "bison_parser.y"
              { (yyval.join_type) = kJoinRight; }
#line 5354 "bison_parser.cpp"
    break;

  case 318: /* opt_join_type: RIGHT  */
#line 1276 "bison_parser.y"
        { (yyval.join_type) = kJoinRight; }
#line 5360 "bison_parser.cpp"
    break;

  case 319: /* opt_join_type: FULL OUTER  */
#line 1277 "bison_parser.y"
             { (yyval.join_type) = kJoinFull; }
#line 5366 "bison_parser.cpp"
    break;

  case 320: /* opt_join_type: OUTER  */
#line 1278 "bison_parser.y"
        { (yyval.join_type) = kJoinFull; }
#line 5372 "bison_parser.cpp"
    break;

  case 321: /* opt_join_type: FULL  */
#line 1279 "bison_parser.y"
       { (yyval.join_type) = kJoinFull; }
#line 5378 "bison_parser.cpp"
    break;

  case 322: /* opt_join_type: CROSS  */
#line 1280 "bison_parser.y"
        { (yyval.join_type) = kJoinCross; }
#line 5384 "bison_parser.cpp"
    break;

  case 323: /* opt_join_type: %empty  */
#line 1281 "bison_parser.y"
                       { (yyval.join_type) = kJoinInner; }
#line 5390 "bison_parser.cpp"
    break;

  case 327: /* ident_commalist: IDENTIFIER  */
#line 1292 "bison_parser.y"
                             {
  (yyval.str_vec) = new std::vector<char*>();
  (yyval.str_vec)->push_back((yyvsp[0].sval));
}
#line 5399 "bison_parser.cpp"
    break;

  case 328: /* ident_commalist: ident_commalist ',' IDENTIFIER  */
#line 1296 "bison_parser.y"
                                 {
  (yyvsp[-2].str_vec)->push_back((yyvsp[0].sval));
  (yyval.str_vec) = (yyvsp[-2].str_vec);
}
#line 5408 "bison_parser.cpp"
    break;


#line 5412 "bison_parser.cpp"

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

#line 1302 "bison_parser.y"

    // clang-format on
    /*********************************
 ** Section 4: Additional C code
 *********************************/

    /* empty */
