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
  YYSYMBOL_NULLABLE = 164,                 /* NULLABLE  */
  YYSYMBOL_165_ = 165,                     /* '='  */
  YYSYMBOL_EQUALS = 166,                   /* EQUALS  */
  YYSYMBOL_NOTEQUALS = 167,                /* NOTEQUALS  */
  YYSYMBOL_168_ = 168,                     /* '<'  */
  YYSYMBOL_169_ = 169,                     /* '>'  */
  YYSYMBOL_LESS = 170,                     /* LESS  */
  YYSYMBOL_GREATER = 171,                  /* GREATER  */
  YYSYMBOL_LESSEQ = 172,                   /* LESSEQ  */
  YYSYMBOL_GREATEREQ = 173,                /* GREATEREQ  */
  YYSYMBOL_NOTNULL = 174,                  /* NOTNULL  */
  YYSYMBOL_175_ = 175,                     /* '+'  */
  YYSYMBOL_176_ = 176,                     /* '-'  */
  YYSYMBOL_177_ = 177,                     /* '*'  */
  YYSYMBOL_178_ = 178,                     /* '/'  */
  YYSYMBOL_179_ = 179,                     /* '%'  */
  YYSYMBOL_180_ = 180,                     /* '^'  */
  YYSYMBOL_UMINUS = 181,                   /* UMINUS  */
  YYSYMBOL_182_ = 182,                     /* '['  */
  YYSYMBOL_183_ = 183,                     /* ']'  */
  YYSYMBOL_184_ = 184,                     /* '('  */
  YYSYMBOL_185_ = 185,                     /* ')'  */
  YYSYMBOL_186_ = 186,                     /* '.'  */
  YYSYMBOL_187_ = 187,                     /* ';'  */
  YYSYMBOL_188_ = 188,                     /* ','  */
  YYSYMBOL_189_ = 189,                     /* '?'  */
  YYSYMBOL_YYACCEPT = 190,                 /* $accept  */
  YYSYMBOL_input = 191,                    /* input  */
  YYSYMBOL_statement_list = 192,           /* statement_list  */
  YYSYMBOL_statement = 193,                /* statement  */
  YYSYMBOL_preparable_statement = 194,     /* preparable_statement  */
  YYSYMBOL_opt_hints = 195,                /* opt_hints  */
  YYSYMBOL_hint_list = 196,                /* hint_list  */
  YYSYMBOL_hint = 197,                     /* hint  */
  YYSYMBOL_transaction_statement = 198,    /* transaction_statement  */
  YYSYMBOL_opt_transaction_keyword = 199,  /* opt_transaction_keyword  */
  YYSYMBOL_other_statement = 200,          /* other_statement  */
  YYSYMBOL_prepare_statement = 201,        /* prepare_statement  */
  YYSYMBOL_prepare_target_query = 202,     /* prepare_target_query  */
  YYSYMBOL_execute_statement = 203,        /* execute_statement  */
  YYSYMBOL_import_statement = 204,         /* import_statement  */
  YYSYMBOL_file_type = 205,                /* file_type  */
  YYSYMBOL_file_path = 206,                /* file_path  */
  YYSYMBOL_opt_file_type = 207,            /* opt_file_type  */
  YYSYMBOL_export_statement = 208,         /* export_statement  */
  YYSYMBOL_show_statement = 209,           /* show_statement  */
  YYSYMBOL_create_statement = 210,         /* create_statement  */
  YYSYMBOL_opt_not_exists = 211,           /* opt_not_exists  */
  YYSYMBOL_opt_unique = 212,               /* opt_unique  */
  YYSYMBOL_table_elem_commalist = 213,     /* table_elem_commalist  */
  YYSYMBOL_table_elem = 214,               /* table_elem  */
  YYSYMBOL_column_def = 215,               /* column_def  */
  YYSYMBOL_column_type = 216,              /* column_type  */
  YYSYMBOL_opt_time_precision = 217,       /* opt_time_precision  */
  YYSYMBOL_opt_decimal_specification = 218, /* opt_decimal_specification  */
  YYSYMBOL_opt_column_constraints = 219,   /* opt_column_constraints  */
  YYSYMBOL_column_constraint_set = 220,    /* column_constraint_set  */
  YYSYMBOL_column_constraint = 221,        /* column_constraint  */
  YYSYMBOL_table_constraint = 222,         /* table_constraint  */
  YYSYMBOL_drop_statement = 223,           /* drop_statement  */
  YYSYMBOL_opt_exists = 224,               /* opt_exists  */
  YYSYMBOL_alter_statement = 225,          /* alter_statement  */
  YYSYMBOL_alter_action = 226,             /* alter_action  */
  YYSYMBOL_drop_action = 227,              /* drop_action  */
  YYSYMBOL_delete_statement = 228,         /* delete_statement  */
  YYSYMBOL_truncate_statement = 229,       /* truncate_statement  */
  YYSYMBOL_insert_statement = 230,         /* insert_statement  */
  YYSYMBOL_opt_column_list = 231,          /* opt_column_list  */
  YYSYMBOL_update_statement = 232,         /* update_statement  */
  YYSYMBOL_update_clause_commalist = 233,  /* update_clause_commalist  */
  YYSYMBOL_update_clause = 234,            /* update_clause  */
  YYSYMBOL_select_statement = 235,         /* select_statement  */
  YYSYMBOL_select_within_set_operation = 236, /* select_within_set_operation  */
  YYSYMBOL_select_within_set_operation_no_parentheses = 237, /* select_within_set_operation_no_parentheses  */
  YYSYMBOL_select_with_paren = 238,        /* select_with_paren  */
  YYSYMBOL_select_no_paren = 239,          /* select_no_paren  */
  YYSYMBOL_set_operator = 240,             /* set_operator  */
  YYSYMBOL_set_type = 241,                 /* set_type  */
  YYSYMBOL_opt_all = 242,                  /* opt_all  */
  YYSYMBOL_select_clause = 243,            /* select_clause  */
  YYSYMBOL_opt_distinct = 244,             /* opt_distinct  */
  YYSYMBOL_select_list = 245,              /* select_list  */
  YYSYMBOL_opt_from_clause = 246,          /* opt_from_clause  */
  YYSYMBOL_from_clause = 247,              /* from_clause  */
  YYSYMBOL_opt_where = 248,                /* opt_where  */
  YYSYMBOL_opt_group = 249,                /* opt_group  */
  YYSYMBOL_opt_having = 250,               /* opt_having  */
  YYSYMBOL_opt_order = 251,                /* opt_order  */
  YYSYMBOL_order_list = 252,               /* order_list  */
  YYSYMBOL_order_desc = 253,               /* order_desc  */
  YYSYMBOL_opt_order_type = 254,           /* opt_order_type  */
  YYSYMBOL_opt_top = 255,                  /* opt_top  */
  YYSYMBOL_opt_limit = 256,                /* opt_limit  */
  YYSYMBOL_expr_list = 257,                /* expr_list  */
  YYSYMBOL_opt_literal_list = 258,         /* opt_literal_list  */
  YYSYMBOL_list_of_list = 259,             /* list_of_list  */
  YYSYMBOL_list_item = 260,                /* list_item  */
  YYSYMBOL_literal_list = 261,             /* literal_list  */
  YYSYMBOL_expr_alias = 262,               /* expr_alias  */
  YYSYMBOL_expr = 263,                     /* expr  */
  YYSYMBOL_operand = 264,                  /* operand  */
  YYSYMBOL_scalar_expr = 265,              /* scalar_expr  */
  YYSYMBOL_unary_expr = 266,               /* unary_expr  */
  YYSYMBOL_binary_expr = 267,              /* binary_expr  */
  YYSYMBOL_logic_expr = 268,               /* logic_expr  */
  YYSYMBOL_in_expr = 269,                  /* in_expr  */
  YYSYMBOL_case_expr = 270,                /* case_expr  */
  YYSYMBOL_case_list = 271,                /* case_list  */
  YYSYMBOL_exists_expr = 272,              /* exists_expr  */
  YYSYMBOL_comp_expr = 273,                /* comp_expr  */
  YYSYMBOL_function_expr = 274,            /* function_expr  */
  YYSYMBOL_extract_expr = 275,             /* extract_expr  */
  YYSYMBOL_cast_expr = 276,                /* cast_expr  */
  YYSYMBOL_datetime_field = 277,           /* datetime_field  */
  YYSYMBOL_datetime_field_plural = 278,    /* datetime_field_plural  */
  YYSYMBOL_duration_field = 279,           /* duration_field  */
  YYSYMBOL_array_expr = 280,               /* array_expr  */
  YYSYMBOL_array_index = 281,              /* array_index  */
  YYSYMBOL_between_expr = 282,             /* between_expr  */
  YYSYMBOL_column_name = 283,              /* column_name  */
  YYSYMBOL_literal = 284,                  /* literal  */
  YYSYMBOL_string_literal = 285,           /* string_literal  */
  YYSYMBOL_bool_literal = 286,             /* bool_literal  */
  YYSYMBOL_num_literal = 287,              /* num_literal  */
  YYSYMBOL_int_literal = 288,              /* int_literal  */
  YYSYMBOL_null_literal = 289,             /* null_literal  */
  YYSYMBOL_date_literal = 290,             /* date_literal  */
  YYSYMBOL_interval_literal = 291,         /* interval_literal  */
  YYSYMBOL_param_expr = 292,               /* param_expr  */
  YYSYMBOL_table_ref = 293,                /* table_ref  */
  YYSYMBOL_table_ref_atomic = 294,         /* table_ref_atomic  */
  YYSYMBOL_nonjoin_table_ref_atomic = 295, /* nonjoin_table_ref_atomic  */
  YYSYMBOL_table_ref_commalist = 296,      /* table_ref_commalist  */
  YYSYMBOL_table_ref_name = 297,           /* table_ref_name  */
  YYSYMBOL_table_ref_name_no_alias = 298,  /* table_ref_name_no_alias  */
  YYSYMBOL_table_name = 299,               /* table_name  */
  YYSYMBOL_opt_index_name = 300,           /* opt_index_name  */
  YYSYMBOL_table_alias = 301,              /* table_alias  */
  YYSYMBOL_opt_table_alias = 302,          /* opt_table_alias  */
  YYSYMBOL_alias = 303,                    /* alias  */
  YYSYMBOL_opt_alias = 304,                /* opt_alias  */
  YYSYMBOL_opt_locking_clause = 305,       /* opt_locking_clause  */
  YYSYMBOL_opt_locking_clause_list = 306,  /* opt_locking_clause_list  */
  YYSYMBOL_locking_clause = 307,           /* locking_clause  */
  YYSYMBOL_row_lock_mode = 308,            /* row_lock_mode  */
  YYSYMBOL_opt_row_lock_policy = 309,      /* opt_row_lock_policy  */
  YYSYMBOL_opt_with_clause = 310,          /* opt_with_clause  */
  YYSYMBOL_with_clause = 311,              /* with_clause  */
  YYSYMBOL_with_description_list = 312,    /* with_description_list  */
  YYSYMBOL_with_description = 313,         /* with_description  */
  YYSYMBOL_join_clause = 314,              /* join_clause  */
  YYSYMBOL_opt_join_type = 315,            /* opt_join_type  */
  YYSYMBOL_join_condition = 316,           /* join_condition  */
  YYSYMBOL_opt_semicolon = 317,            /* opt_semicolon  */
  YYSYMBOL_ident_commalist = 318           /* ident_commalist  */
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
#define YYLAST   905

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  190
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  129
/* YYNRULES -- Number of rules.  */
#define YYNRULES  329
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  585

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   427


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
       2,     2,     2,     2,     2,     2,     2,   179,     2,     2,
     184,   185,   177,   175,   188,   176,   186,   178,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   187,
     168,   165,   169,   189,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   182,     2,   183,   180,     2,     2,     2,     2,     2,
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
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     166,   167,   170,   171,   172,   173,   174,   181
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
     624,   625,   626,   627,   628,   630,   631,   639,   645,   651,
     657,   663,   664,   671,   677,   679,   689,   696,   707,   714,
     722,   723,   730,   737,   741,   746,   756,   760,   764,   776,
     776,   778,   779,   788,   789,   791,   805,   817,   822,   826,
     830,   835,   836,   838,   848,   849,   851,   853,   854,   856,
     858,   859,   861,   866,   868,   869,   871,   872,   874,   878,
     883,   885,   886,   887,   891,   892,   894,   895,   896,   897,
     898,   899,   904,   908,   913,   914,   916,   920,   925,   929,
     933,   938,   946,   946,   946,   946,   946,   948,   949,   949,
     949,   949,   949,   949,   949,   949,   950,   950,   954,   954,
     956,   957,   958,   959,   960,   962,   962,   963,   964,   965,
     966,   967,   968,   969,   970,   971,   973,   974,   976,   977,
     978,   979,   983,   984,   985,   986,   988,   989,   991,   992,
     994,   995,   996,   997,   998,   999,  1000,  1002,  1003,  1005,
    1007,  1009,  1010,  1011,  1012,  1013,  1014,  1016,  1017,  1018,
    1019,  1020,  1021,  1023,  1023,  1025,  1027,  1029,  1031,  1032,
    1033,  1034,  1036,  1036,  1036,  1036,  1036,  1036,  1036,  1038,
    1040,  1041,  1043,  1044,  1046,  1048,  1050,  1061,  1065,  1076,
    1108,  1117,  1117,  1124,  1124,  1126,  1126,  1133,  1137,  1142,
    1150,  1156,  1160,  1165,  1166,  1168,  1168,  1170,  1170,  1172,
    1173,  1175,  1175,  1181,  1182,  1184,  1188,  1193,  1199,  1206,
    1207,  1208,  1209,  1211,  1212,  1213,  1219,  1219,  1221,  1223,
    1227,  1232,  1242,  1249,  1257,  1273,  1274,  1275,  1276,  1277,
    1278,  1279,  1280,  1281,  1282,  1284,  1290,  1290,  1293,  1297
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
  "HELP", "SYNC", "NULLABLE", "'='", "EQUALS", "NOTEQUALS", "'<'", "'>'",
  "LESS", "GREATER", "LESSEQ", "GREATEREQ", "NOTNULL", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'^'", "UMINUS", "'['", "']'", "'('", "')'", "'.'", "';'",
  "','", "'?'", "$accept", "input", "statement_list", "statement",
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

#define YYPACT_NINF (-446)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-327)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     593,    22,   144,   174,   184,   144,   101,   -36,    69,   123,
     144,   128,   144,   144,    -2,    21,   225,    75,    75,    75,
    -446,  -446,   253,    79,  -446,   149,  -446,  -446,   149,  -446,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,
    -446,   -30,  -446,   270,   102,  -446,   120,   216,  -446,  -446,
     207,   207,   268,   144,   341,   144,   226,  -446,   224,   -42,
    -446,   224,   224,   224,   144,  -446,   230,   175,  -446,  -446,
    -446,  -446,  -446,  -446,   584,  -446,   259,  -446,  -446,   238,
     -30,    54,  -446,   125,  -446,   376,    62,   380,   264,   144,
     144,   207,   297,  -446,   298,   211,   389,   347,   144,   393,
     393,   395,   144,   144,  -446,   215,   225,  -446,   217,   394,
     390,   219,   220,  -446,  -446,  -446,   -30,   295,   291,   -30,
     168,  -446,  -446,  -446,  -446,   412,  -446,   414,  -446,  -446,
    -446,   234,   233,  -446,  -446,  -446,  -446,   351,  -446,  -446,
    -446,  -446,  -446,  -446,   377,   -53,   211,   419,   290,  -446,
     393,   425,   190,   265,   -52,  -446,  -446,   338,   321,  -446,
     321,  -446,  -446,  -446,  -446,  -446,   431,  -446,  -446,   290,
    -446,  -446,   358,  -446,  -446,    54,  -446,  -446,   290,   358,
     290,    80,   318,  -446,   159,  -446,    62,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,
    -446,  -446,  -446,   434,   326,    44,   314,  -446,   312,    66,
     260,   262,   263,   170,   366,   267,   384,  -446,   231,   -72,
     410,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,   354,  -446,  -139,
     271,  -446,   290,   389,  -446,   422,  -446,  -446,   409,  -446,
    -446,   278,    55,  -446,   371,   280,  -446,    23,   168,   -30,
     283,  -446,   110,   168,   -72,   420,    27,    24,  -446,   318,
    -446,  -446,  -446,   387,  -446,   682,   362,   299,    74,  -446,
    -446,  -446,   326,   144,     8,    15,   426,   159,   290,   290,
      67,    72,   301,   384,   707,   290,   135,   317,   -76,   290,
     290,   384,  -446,   384,    60,   302,    28,   384,   384,   384,
     384,   384,   384,   384,   384,   384,   384,   384,   384,   384,
     384,   384,   394,   144,  -446,   500,    62,   316,  -446,   -72,
    -446,   224,   341,    62,  -446,   431,    12,   297,  -446,   290,
    -446,   503,  -446,  -446,  -446,  -446,   290,  -446,  -446,  -446,
     318,   290,   290,  -446,   346,   388,  -446,    13,  -446,   393,
    -446,  -446,   325,  -446,   329,  -446,  -446,   330,  -446,  -446,
     331,  -446,  -446,  -446,  -446,   336,  -446,  -446,   118,   337,
     425,  -446,    44,  -446,   339,  -446,   290,  -446,  -446,   340,
     416,    65,   152,   127,   290,   290,  -446,   426,   421,     3,
    -446,  -446,  -446,   411,   637,   689,   384,   343,   231,  -446,
     424,   342,   689,   689,   689,   689,   723,   723,   723,   723,
     135,   135,   -85,   -85,   -85,   -94,   349,  -446,  -446,   143,
     271,   526,  -446,   155,  -446,   326,  -446,   208,  -446,   345,
    -446,    32,  -446,   460,  -446,  -446,  -446,  -446,   -72,   -72,
    -446,   474,   425,  -446,   385,  -446,  -446,   534,   535,  -446,
     538,   542,   543,  -446,   432,  -446,  -446,   447,  -446,  -446,
     118,  -446,   425,   160,  -446,   425,   165,  -446,   290,   682,
     290,   290,  -446,   209,   177,   368,  -446,   384,   689,   231,
     369,   172,  -446,  -446,  -446,  -446,  -446,  -446,   372,   457,
    -446,  -446,  -446,   480,   481,   484,   464,    12,   561,  -446,
    -446,  -446,   439,  -446,  -446,  -114,  -446,   382,   173,   386,
     396,   408,  -446,  -446,  -446,   179,  -446,   180,  -446,   -39,
     413,   -72,   210,  -446,   290,  -446,   707,   417,   188,  -446,
    -446,    32,    12,  -446,  -446,  -446,    12,   378,   423,   290,
    -446,  -446,  -446,   563,  -446,  -446,  -446,  -446,  -446,  -446,
    -446,  -446,   -72,  -446,  -446,  -446,  -446,   381,   425,   -28,
     418,   427,   290,   189,   290,  -446,  -446,    18,   -72,  -446,
    -446,   -72,   415,   428,  -446
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     307,     0,     0,     0,     0,     0,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    31,    31,    31,
      32,    33,     0,   327,     3,    22,    19,    20,    22,    18,
       8,     9,     7,    11,    16,    17,    13,    14,    12,    15,
      10,     0,   306,     0,   281,   107,    36,     0,    47,    56,
      55,    55,     0,     0,     0,     0,     0,   280,   102,     0,
      48,   102,   102,   102,     0,    45,     0,   308,   309,    30,
      27,    29,    28,     1,   307,     2,     0,     6,     5,   155,
       0,   116,   117,   147,    99,     0,   165,     0,     0,     0,
       0,    55,   141,    40,     0,   111,     0,     0,     0,     0,
       0,     0,     0,     0,    46,     0,     0,     4,     0,     0,
     135,     0,     0,   129,   130,   128,     0,   132,     0,     0,
     161,   282,   259,   262,   264,     0,   265,     0,   260,   261,
     270,     0,   164,   169,   252,   253,   254,   263,   255,   256,
     257,   258,    35,    34,     0,     0,   111,   284,     0,   106,
       0,     0,     0,     0,   141,   113,   101,     0,    43,    41,
      43,   100,    97,    98,   311,   310,     0,   154,   134,     0,
     124,   123,   147,   120,   119,   121,   131,   127,     0,   147,
       0,     0,   294,   266,   269,    37,     0,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   267,    54,     0,   307,     0,     0,   283,     0,   248,
       0,     0,     0,     0,     0,     0,     0,   250,     0,   140,
     172,   179,   180,   181,   174,   176,   182,   175,   195,   183,
     184,   185,   186,   178,   173,   188,   189,     0,   328,     0,
       0,   109,     0,     0,   112,     0,   103,   104,     0,    39,
      44,    25,     0,    23,   138,   136,   162,   292,   161,     0,
     146,   148,   153,   161,   157,   159,   156,     0,   125,   293,
     295,   268,   170,     0,    51,     0,     0,     0,     0,    58,
      60,    61,   307,     0,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   191,     0,   190,     0,     0,     0,
       0,     0,   192,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   110,     0,     0,   108,   166,   115,
     114,   102,     0,     0,    21,     0,     0,   141,   137,     0,
     290,     0,   291,   171,   118,   122,     0,   152,   151,   150,
     294,     0,     0,   299,     0,     0,   301,   305,   296,     0,
      79,    73,     0,    75,    85,    76,    63,     0,    70,    71,
       0,    67,    68,    74,    77,    82,    72,    64,    87,     0,
       0,    50,     0,    53,     0,   227,     0,   249,   251,     0,
       0,     0,     0,     0,     0,     0,   214,     0,     0,     0,
     187,   177,   206,   207,     0,   202,     0,     0,     0,   193,
       0,   205,   204,   220,   221,   222,   223,   224,   225,   226,
     197,   196,   199,   198,   200,   201,     0,    38,   329,     0,
       0,     0,    42,     0,    24,   307,   139,   271,   273,     0,
     275,   288,   274,   143,   163,   289,   149,   126,   160,   158,
     302,     0,     0,   304,     0,   297,    49,     0,     0,    69,
       0,     0,     0,    78,     0,    91,    92,     0,    94,    62,
      86,    88,     0,     0,    59,     0,     0,   218,     0,     0,
       0,     0,   212,     0,     0,     0,   245,     0,   203,     0,
       0,     0,   194,   246,   168,   167,   105,    26,     0,     0,
     323,   315,   321,   319,   322,   317,     0,     0,     0,   287,
     279,   285,     0,   133,   300,   305,   303,     0,     0,     0,
       0,     0,    90,    93,    89,     0,    96,     0,   228,     0,
       0,   216,     0,   215,     0,   219,   247,     0,     0,   210,
     208,   288,     0,   318,   320,   316,     0,   272,   289,     0,
     298,    66,    84,     0,    80,    65,    81,    95,    52,   229,
     230,   213,   217,   211,   209,   276,   312,   324,     0,   145,
       0,     0,     0,     0,     0,   142,    83,     0,   325,   313,
     286,   144,   248,     0,   314
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -446,  -446,  -446,   496,  -446,   544,  -446,   239,  -446,    61,
    -446,  -446,  -446,  -446,  -446,   248,   -91,   435,  -446,  -446,
    -446,   -14,  -446,  -446,   212,  -446,   117,  -446,  -446,  -446,
    -446,   134,  -446,  -446,   -55,  -446,  -446,  -446,  -446,  -446,
    -446,   451,  -446,  -446,   373,  -190,   -90,  -446,    -5,   -79,
     -45,  -446,  -446,   -92,   328,  -446,  -446,  -446,  -132,  -446,
    -446,  -122,  -446,   272,  -446,  -446,    48,  -279,  -446,  -446,
     187,  -106,   266,  -148,  -197,  -446,  -446,  -446,  -446,  -446,
    -446,   319,  -446,  -446,  -446,  -446,  -446,  -150,  -446,  -446,
    -446,  -446,  -446,    37,   -61,   -96,  -446,  -446,   -98,  -446,
    -446,  -446,  -446,  -446,  -445,    78,  -446,  -446,  -446,     0,
    -446,  -446,    81,   370,  -446,   273,  -446,   357,  -446,   113,
    -446,  -446,  -446,   523,  -446,  -446,  -446,  -446,  -319
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    22,    23,    24,    25,    77,   252,   253,    26,    70,
      27,    28,   143,    29,    30,    94,   158,   249,    31,    32,
      33,    89,    52,   278,   279,   280,   378,   463,   459,   469,
     470,   471,   281,    34,    98,    35,   246,   247,    36,    37,
      38,   152,    39,   154,   155,    40,   172,   173,   174,    82,
     116,   117,   177,    83,   169,   254,   337,   338,   149,   513,
     575,   120,   260,   261,   349,   110,   182,   255,   131,   327,
     328,   132,   256,   257,   220,   221,   222,   223,   224,   225,
     226,   291,   227,   228,   229,   230,   231,   199,   200,   201,
     232,   233,   234,   235,   236,   134,   135,   136,   137,   138,
     139,   140,   141,   436,   437,   438,   439,   440,    56,   441,
     208,   509,   510,   511,   343,   268,   269,   270,   357,   455,
      41,    42,    67,    68,   442,   506,   579,    75,   239
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     219,   112,    45,   159,   159,    48,   101,   102,   103,   160,
      57,   167,    59,    60,   274,    44,   399,   294,   387,   296,
     168,   582,   244,   574,   175,   133,   340,   175,    79,   179,
     262,   148,   264,   266,   271,   340,    81,    90,   119,   299,
      64,   203,   307,   299,   453,   454,   324,   275,    43,   325,
     258,   307,    99,    92,   159,    95,   300,   263,    53,   237,
     300,   473,   547,   113,   104,   290,   122,   123,   124,    61,
     298,   276,   204,   241,   325,   111,   299,   147,    62,    71,
      72,    65,   352,   209,   122,   123,   124,   353,   322,   145,
     146,   100,   383,   300,   329,   321,   294,   322,   157,   114,
     164,   567,   162,   163,   404,   277,   405,   476,    63,   401,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   272,   210,   211,   212,   491,
     259,   205,   409,   515,   113,   115,   243,   390,   299,   297,
     391,   392,   299,   452,   354,   464,   559,    44,   341,   410,
     125,   402,   403,   525,    80,   300,   527,   508,   355,   300,
     339,   406,    49,    54,   394,   213,   126,   175,   125,   345,
     114,   453,   454,   209,   122,   123,   124,    46,   289,   465,
     299,    50,   299,   395,   126,   356,   486,    47,   407,   396,
     479,   339,   388,   385,   265,   217,   435,   300,   262,   300,
     347,   214,   118,   448,   449,   443,   115,   389,    58,   488,
     538,    51,   127,   128,   129,   215,   210,   211,   212,   481,
     429,    55,   466,   180,   426,   299,   348,   433,    66,    69,
     127,   128,   129,   499,   209,   122,   123,   124,   395,   467,
     334,   181,   300,   335,   482,   498,   483,   484,    79,   573,
     284,   130,   285,    73,   240,   213,   216,   217,   125,   381,
     480,    76,   382,   159,   218,   133,    74,   299,   456,   130,
     569,   307,   133,    84,   126,   500,   431,   210,   211,   212,
     501,   289,   468,   384,   300,   534,   502,   503,    85,    79,
     536,   214,   299,   209,   122,   123,   124,   187,   188,   189,
     190,   191,   192,   504,    86,   215,   344,  -324,   505,   300,
      87,   350,   318,   319,   320,   321,   213,   322,   485,   125,
     127,   128,   129,   427,   299,   299,   533,   561,   494,   490,
     529,   186,   531,   532,    88,   126,   210,   211,   212,    91,
     497,   300,   300,   186,    93,   526,   216,   217,   325,    96,
     528,    97,   214,   339,   218,   105,   108,   540,   552,   130,
     339,   553,   109,   106,   557,   558,   215,   325,   325,   209,
     122,   123,   124,   564,   580,   213,   339,   325,   125,   121,
     148,   127,   128,   129,   142,   144,   562,   209,   122,   123,
     124,   150,   153,   156,   126,   151,  -277,   122,   161,    80,
     124,   166,   168,   499,   170,   171,   499,   216,   217,   176,
     537,   214,   292,   211,   212,   218,   183,   178,   184,   185,
     130,   186,   207,   202,   578,   215,   581,   301,   238,   245,
     242,   211,   212,   248,   251,   118,   267,   273,    16,   282,
     127,   128,   129,   283,   286,   500,   287,   288,   500,   295,
     501,   213,   323,   501,   125,   326,   502,   503,   332,   502,
     503,   331,   333,   571,   302,   336,   216,   217,   339,   213,
     126,   346,   125,   504,   218,   351,   504,  -324,   505,   130,
     359,   505,   379,   380,    79,   397,   408,   293,   126,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   215,   400,   428,   430,   293,   445,   450,   451,   457,
     478,   303,   572,   458,   460,   461,   127,   128,   129,   215,
     462,   472,   406,   475,   322,   477,   299,   489,   492,   496,
     512,   304,   493,   507,   127,   128,   129,   514,   305,   306,
     517,   518,   216,   217,   519,   516,   307,   308,   520,   521,
     218,   523,   522,   535,   539,   130,   542,   541,   543,   544,
     216,   217,   545,   546,   548,   549,  -278,   551,   218,   570,
     107,   554,    78,   130,   434,   309,   310,   311,   312,   313,
     432,   555,   314,   315,  -326,   316,   317,   318,   319,   320,
     321,     1,   322,   556,   474,   250,   530,   206,   560,     2,
       1,   285,   563,   576,   524,   444,     3,   568,     2,   393,
       4,   577,   386,   584,   583,     3,   330,   495,   446,     4,
     566,     5,   565,   447,     6,     7,   358,   342,   550,   165,
       5,     0,     0,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,     0,     8,     9,    10,     0,     0,
      11,     0,     0,     0,     0,     0,    10,     0,     0,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,     0,     0,    13,    14,     0,     0,     0,     0,
      12,     0,     0,    13,    14,     0,     0,     0,     0,     0,
      15,   302,     0,   360,     0,     0,    16,     0,     0,    15,
       0,     0,     0,     0,     0,    16,   361,     0,     0,     0,
       0,   362,   363,   364,   365,   366,     0,   367,     0,     0,
       0,     0,     0,     0,     0,   368,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   303,    17,
      18,    19,     0,   302,     0,     0,    20,    21,    17,    18,
      19,   369,   487,     0,     0,    20,    21,     0,   398,     0,
       0,   302,     0,     0,     0,     0,   306,     0,   370,     0,
     371,   372,     0,   307,   308,     0,     0,   302,     0,     0,
       0,     0,     0,     0,     0,   373,     0,     0,     0,   374,
    -327,   375,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   376,   309,   310,   311,   312,   313,     0,   303,   314,
     315,     0,   316,   317,   318,   319,   320,   321,   306,   322,
       0,     0,     0,     0,     0,   307,  -327,     0,   398,     0,
       0,     0,     0,     0,     0,   377,   306,     0,     0,     0,
       0,     0,     0,   307,   308,     0,     0,     0,     0,     0,
       0,     0,   306,     0,  -327,  -327,  -327,   312,   313,   307,
       0,   314,   315,     0,   316,   317,   318,   319,   320,   321,
       0,   322,   309,   310,   311,   312,   313,     0,     0,   314,
     315,     0,   316,   317,   318,   319,   320,   321,     0,   322,
       0,  -327,  -327,     0,     0,  -327,  -327,     0,   316,   317,
     318,   319,   320,   321,     0,   322
};

static const yytype_int16 yycheck[] =
{
     148,    80,     2,    99,   100,     5,    61,    62,    63,   100,
      10,   109,    12,    13,   204,     3,   295,   214,     3,   216,
      12,     3,   154,    51,   116,    86,     3,   119,    58,   119,
     178,    83,   180,   181,   184,     3,    41,    51,    83,   115,
      19,    94,   136,   115,   158,   159,   185,     3,    26,   188,
     172,   136,    94,    53,   150,    55,   132,   179,    94,   150,
     132,   380,   507,     9,    64,   213,     4,     5,     6,    71,
     218,    27,   125,   152,   188,    80,   115,    91,    80,    18,
      19,    60,    55,     3,     4,     5,     6,    63,   182,    89,
      90,   133,   282,   132,   242,   180,   293,   182,    98,    45,
     105,   546,   102,   103,   301,    61,   303,   386,   110,   185,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   186,    46,    47,    48,   408,
     175,   184,   104,   452,     9,    81,   188,   287,   115,   218,
     288,   289,   115,   130,   120,    27,   185,     3,   125,   121,
      88,   299,   300,   472,   184,   132,   475,   125,   134,   132,
     188,   101,    61,    94,    92,    85,   104,   259,    88,   259,
      45,   158,   159,     3,     4,     5,     6,     3,   111,    61,
     115,    80,   115,   111,   104,   161,   183,     3,   128,   117,
     125,   188,   177,   185,   114,   177,   184,   132,   346,   132,
      90,   121,    77,   351,   352,   337,    81,   286,    80,   406,
     489,   110,   150,   151,   152,   135,    46,    47,    48,    92,
     326,    98,   104,    55,   322,   115,   116,   333,     3,   154,
     150,   151,   152,    25,     3,     4,     5,     6,   111,   121,
     185,    73,   132,   188,   117,   435,   394,   395,    58,   568,
     184,   189,   186,     0,    64,    85,   176,   177,    88,   185,
     108,   112,   188,   359,   184,   326,   187,   115,   359,   189,
     549,   136,   333,     3,   104,    67,   331,    46,    47,    48,
      72,   111,   164,   283,   132,   108,    78,    79,   186,    58,
     487,   121,   115,     3,     4,     5,     6,   138,   139,   140,
     141,   142,   143,    95,   184,   135,   258,    99,   100,   132,
      94,   263,   177,   178,   179,   180,    85,   182,   397,    88,
     150,   151,   152,   323,   115,   115,   117,   117,   185,   408,
     478,   188,   480,   481,   127,   104,    46,    47,    48,    71,
     185,   132,   132,   188,     3,   185,   176,   177,   188,   123,
     185,   127,   121,   188,   184,   125,    97,   185,   185,   189,
     188,   188,   124,   188,   185,   185,   135,   188,   188,     3,
       4,     5,     6,   185,   185,    85,   188,   188,    88,     3,
      83,   150,   151,   152,     4,   121,   534,     3,     4,     5,
       6,    93,     3,    46,   104,   184,   188,     4,     3,   184,
       6,   184,    12,    25,   185,   185,    25,   176,   177,   114,
     489,   121,    46,    47,    48,   184,     4,   126,     4,   185,
     189,   188,     3,    46,   572,   135,   574,    17,     3,    91,
     165,    47,    48,   112,     3,    77,   118,     3,   112,   125,
     150,   151,   152,   131,   184,    67,   184,   184,    67,   182,
      72,    85,    98,    72,    88,   184,    78,    79,    49,    78,
      79,    39,   184,    82,    54,    94,   176,   177,   188,    85,
     104,   188,    88,    95,   184,    55,    95,    99,   100,   189,
      93,   100,   120,   184,    58,   184,   184,   121,   104,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   135,   185,     3,   188,   121,     3,   161,   120,   184,
      94,   101,   131,   184,   184,   184,   150,   151,   152,   135,
     184,   184,   101,   184,   182,   185,   115,   184,   104,     3,
      70,   121,   183,   188,   150,   151,   152,    63,   128,   129,
       6,     6,   176,   177,     6,   160,   136,   137,     6,     6,
     184,   104,   120,   185,   185,   189,    99,   185,    78,    78,
     176,   177,    78,    99,     3,   126,   188,   185,   184,     6,
      74,   185,    28,   189,   335,   165,   166,   167,   168,   169,
     332,   185,   172,   173,     0,   175,   176,   177,   178,   179,
     180,     7,   182,   185,   382,   160,   479,   146,   185,    15,
       7,   186,   185,   185,   470,   339,    22,   184,    15,   290,
      26,   184,   284,   185,   577,    22,   243,   430,   346,    26,
     542,    37,   541,   350,    40,    41,   269,   257,   515,   106,
      37,    -1,    -1,    40,    41,    -1,    52,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    53,    63,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    -1,    -1,    90,    91,    -1,    -1,    -1,    -1,
      87,    -1,    -1,    90,    91,    -1,    -1,    -1,    -1,    -1,
     106,    54,    -1,    11,    -1,    -1,   112,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,   112,    24,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,   155,
     156,   157,    -1,    54,    -1,    -1,   162,   163,   155,   156,
     157,    69,   115,    -1,    -1,   162,   163,    -1,   121,    -1,
      -1,    54,    -1,    -1,    -1,    -1,   129,    -1,    86,    -1,
      88,    89,    -1,   136,   137,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,   107,
     101,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   119,   165,   166,   167,   168,   169,    -1,   101,   172,
     173,    -1,   175,   176,   177,   178,   179,   180,   129,   182,
      -1,    -1,    -1,    -1,    -1,   136,   137,    -1,   121,    -1,
      -1,    -1,    -1,    -1,    -1,   153,   129,    -1,    -1,    -1,
      -1,    -1,    -1,   136,   137,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,    -1,   165,   166,   167,   168,   169,   136,
      -1,   172,   173,    -1,   175,   176,   177,   178,   179,   180,
      -1,   182,   165,   166,   167,   168,   169,    -1,    -1,   172,
     173,    -1,   175,   176,   177,   178,   179,   180,    -1,   182,
      -1,   168,   169,    -1,    -1,   172,   173,    -1,   175,   176,
     177,   178,   179,   180,    -1,   182
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     7,    15,    22,    26,    37,    40,    41,    52,    53,
      63,    66,    87,    90,    91,   106,   112,   155,   156,   157,
     162,   163,   191,   192,   193,   194,   198,   200,   201,   203,
     204,   208,   209,   210,   223,   225,   228,   229,   230,   232,
     235,   310,   311,    26,     3,   299,     3,     3,   299,    61,
      80,   110,   212,    94,    94,    98,   298,   299,    80,   299,
     299,    71,    80,   110,    19,    60,     3,   312,   313,   154,
     199,   199,   199,     0,   187,   317,   112,   195,   195,    58,
     184,   238,   239,   243,     3,   186,   184,    94,   127,   211,
     211,    71,   299,     3,   205,   299,   123,   127,   224,    94,
     133,   224,   224,   224,   299,   125,   188,   193,    97,   124,
     255,   238,   239,     9,    45,    81,   240,   241,    77,   240,
     251,     3,     4,     5,     6,    88,   104,   150,   151,   152,
     189,   258,   261,   284,   285,   286,   287,   288,   289,   290,
     291,   292,     4,   202,   121,   299,   299,   211,    83,   248,
      93,   184,   231,     3,   233,   234,    46,   299,   206,   285,
     206,     3,   299,   299,   238,   313,   184,   288,    12,   244,
     185,   185,   236,   237,   238,   243,   114,   242,   126,   236,
      55,    73,   256,     4,     4,   185,   188,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   277,
     278,   279,    46,    94,   125,   184,   231,     3,   300,     3,
      46,    47,    48,    85,   121,   135,   176,   177,   184,   263,
     264,   265,   266,   267,   268,   269,   270,   272,   273,   274,
     275,   276,   280,   281,   282,   283,   284,   206,     3,   318,
      64,   239,   165,   188,   248,    91,   226,   227,   112,   207,
     207,     3,   196,   197,   245,   257,   262,   263,   251,   240,
     252,   253,   263,   251,   263,   114,   263,   118,   305,   306,
     307,   277,   284,     3,   235,     3,    27,    61,   213,   214,
     215,   222,   125,   131,   184,   186,   184,   184,   184,   111,
     263,   271,    46,   121,   264,   182,   264,   239,   263,   115,
     132,    17,    54,   101,   121,   128,   129,   136,   137,   165,
     166,   167,   168,   169,   172,   173,   175,   176,   177,   178,
     179,   180,   182,    98,   185,   188,   184,   259,   260,   263,
     234,    39,    49,   184,   185,   188,    94,   246,   247,   188,
       3,   125,   303,   304,   256,   236,   188,    90,   116,   254,
     256,    55,    55,    63,   120,   134,   161,   308,   307,    93,
      11,    24,    29,    30,    31,    32,    33,    35,    43,    69,
      86,    88,    89,   103,   107,   109,   119,   153,   216,   120,
     184,   185,   188,   235,   299,   185,   244,     3,   177,   239,
     277,   263,   263,   271,    92,   111,   117,   184,   121,   257,
     185,   185,   263,   263,   264,   264,   101,   128,   184,   104,
     121,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   288,   299,     3,   261,
     188,   224,   205,   261,   197,   184,   293,   294,   295,   296,
     297,   299,   314,   248,   262,     3,   253,   305,   263,   263,
     161,   120,   130,   158,   159,   309,   206,   184,   184,   218,
     184,   184,   184,   217,    27,    61,   104,   121,   164,   219,
     220,   221,   184,   318,   214,   184,   257,   185,    94,   125,
     108,    92,   117,   263,   263,   239,   183,   115,   264,   184,
     239,   257,   104,   183,   185,   260,     3,   185,   235,    25,
      67,    72,    78,    79,    95,   100,   315,   188,   125,   301,
     302,   303,    70,   249,    63,   318,   160,     6,     6,     6,
       6,     6,   120,   104,   221,   318,   185,   318,   185,   263,
     216,   263,   263,   117,   108,   185,   264,   239,   257,   185,
     185,   185,    99,    78,    78,    78,    99,   294,     3,   126,
     309,   185,   185,   188,   185,   185,   185,   185,   185,   185,
     185,   117,   263,   185,   185,   302,   295,   294,   184,   257,
       6,    82,   131,   318,    51,   250,   185,   184,   263,   316,
     185,   263,     3,   283,   185
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   190,   191,   192,   192,   193,   193,   193,   193,   193,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   195,   195,   196,   196,   197,   197,   198,   198,   198,
     199,   199,   200,   200,   201,   202,   203,   203,   204,   204,
     205,   206,   207,   207,   208,   209,   209,   209,   209,   210,
     210,   210,   210,   210,   211,   211,   212,   212,   213,   213,
     214,   214,   215,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   217,   217,   218,   218,   218,   219,   219,   220,   220,
     221,   221,   221,   221,   221,   222,   222,   223,   223,   223,
     223,   224,   224,   225,   226,   227,   228,   229,   230,   230,
     231,   231,   232,   233,   233,   234,   235,   235,   235,   236,
     236,   237,   237,   238,   238,   239,   239,   240,   241,   241,
     241,   242,   242,   243,   244,   244,   245,   246,   246,   247,
     248,   248,   249,   249,   250,   250,   251,   251,   252,   252,
     253,   254,   254,   254,   255,   255,   256,   256,   256,   256,
     256,   256,   257,   257,   258,   258,   259,   259,   260,   261,
     261,   262,   263,   263,   263,   263,   263,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   265,   265,
     266,   266,   266,   266,   266,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   268,   268,   269,   269,
     269,   269,   270,   270,   270,   270,   271,   271,   272,   272,
     273,   273,   273,   273,   273,   273,   273,   274,   274,   275,
     276,   277,   277,   277,   277,   277,   277,   278,   278,   278,
     278,   278,   278,   279,   279,   280,   281,   282,   283,   283,
     283,   283,   284,   284,   284,   284,   284,   284,   284,   285,
     286,   286,   287,   287,   288,   289,   290,   291,   291,   291,
     292,   293,   293,   294,   294,   295,   295,   296,   296,   297,
     298,   299,   299,   300,   300,   301,   301,   302,   302,   303,
     303,   304,   304,   305,   305,   306,   306,   307,   307,   308,
     308,   308,   308,   309,   309,   309,   310,   310,   311,   312,
     312,   313,   314,   314,   314,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   316,   317,   317,   318,   318
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
       2,     1,     1,     2,     1,     5,     4,     4,     4,     3,
       4,     2,     0,     5,     1,     4,     4,     2,     6,     5,
       3,     0,     5,     1,     3,     3,     2,     2,     6,     1,
       1,     1,     3,     3,     3,     4,     6,     2,     1,     1,
       1,     1,     0,     7,     1,     0,     1,     1,     0,     2,
       2,     0,     4,     0,     2,     0,     3,     0,     1,     3,
       2,     1,     1,     0,     2,     0,     2,     2,     4,     2,
       4,     0,     1,     3,     1,     0,     1,     3,     3,     1,
       3,     2,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       2,     2,     2,     3,     4,     1,     3,     3,     3,     3,
       3,     3,     3,     4,     3,     3,     3,     3,     5,     6,
       5,     6,     4,     6,     3,     5,     4,     5,     4,     5,
       3,     3,     3,     3,     3,     3,     3,     3,     5,     6,
       6,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     5,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     3,     2,
       1,     1,     3,     1,     1,     1,     4,     1,     3,     2,
       1,     1,     3,     1,     0,     1,     5,     1,     0,     2,
       1,     1,     0,     1,     0,     1,     2,     3,     5,     1,
       3,     1,     2,     2,     1,     0,     1,     0,     2,     1,
       3,     3,     4,     6,     8,     1,     2,     1,     2,     1,
       2,     1,     1,     1,     0,     1,     1,     0,     1,     3
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
#line 2052 "bison_parser.cpp"
        break;

    case YYSYMBOL_STRING: /* STRING  */
#line 170 "bison_parser.y"
                { free( (((*yyvaluep).sval)) ); }
#line 2058 "bison_parser.cpp"
        break;

    case YYSYMBOL_FLOATVAL: /* FLOATVAL  */
#line 168 "bison_parser.y"
                { }
#line 2064 "bison_parser.cpp"
        break;

    case YYSYMBOL_INTVAL: /* INTVAL  */
#line 168 "bison_parser.y"
                { }
#line 2070 "bison_parser.cpp"
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
#line 2083 "bison_parser.cpp"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).statement)); }
#line 2089 "bison_parser.cpp"
        break;

    case YYSYMBOL_preparable_statement: /* preparable_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).statement)); }
#line 2095 "bison_parser.cpp"
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
#line 2108 "bison_parser.cpp"
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
#line 2121 "bison_parser.cpp"
        break;

    case YYSYMBOL_hint: /* hint  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2127 "bison_parser.cpp"
        break;

    case YYSYMBOL_transaction_statement: /* transaction_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).transaction_stmt)); }
#line 2133 "bison_parser.cpp"
        break;

    case YYSYMBOL_other_statement: /* other_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).other_stmt)); }
#line 2139 "bison_parser.cpp"
        break;

    case YYSYMBOL_prepare_statement: /* prepare_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).prep_stmt)); }
#line 2145 "bison_parser.cpp"
        break;

    case YYSYMBOL_prepare_target_query: /* prepare_target_query  */
#line 170 "bison_parser.y"
                { free( (((*yyvaluep).sval)) ); }
#line 2151 "bison_parser.cpp"
        break;

    case YYSYMBOL_execute_statement: /* execute_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).exec_stmt)); }
#line 2157 "bison_parser.cpp"
        break;

    case YYSYMBOL_import_statement: /* import_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).import_stmt)); }
#line 2163 "bison_parser.cpp"
        break;

    case YYSYMBOL_file_type: /* file_type  */
#line 168 "bison_parser.y"
                { }
#line 2169 "bison_parser.cpp"
        break;

    case YYSYMBOL_file_path: /* file_path  */
#line 170 "bison_parser.y"
                { free( (((*yyvaluep).sval)) ); }
#line 2175 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_file_type: /* opt_file_type  */
#line 168 "bison_parser.y"
                { }
#line 2181 "bison_parser.cpp"
        break;

    case YYSYMBOL_export_statement: /* export_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).export_stmt)); }
#line 2187 "bison_parser.cpp"
        break;

    case YYSYMBOL_show_statement: /* show_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).show_stmt)); }
#line 2193 "bison_parser.cpp"
        break;

    case YYSYMBOL_create_statement: /* create_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).create_stmt)); }
#line 2199 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_not_exists: /* opt_not_exists  */
#line 168 "bison_parser.y"
                { }
#line 2205 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_unique: /* opt_unique  */
#line 168 "bison_parser.y"
                { }
#line 2211 "bison_parser.cpp"
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
#line 2224 "bison_parser.cpp"
        break;

    case YYSYMBOL_table_elem: /* table_elem  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).table_element_t)); }
#line 2230 "bison_parser.cpp"
        break;

    case YYSYMBOL_column_def: /* column_def  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).column_t)); }
#line 2236 "bison_parser.cpp"
        break;

    case YYSYMBOL_column_type: /* column_type  */
#line 168 "bison_parser.y"
                { }
#line 2242 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_time_precision: /* opt_time_precision  */
#line 168 "bison_parser.y"
                { }
#line 2248 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_decimal_specification: /* opt_decimal_specification  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).ival_pair)); }
#line 2254 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_column_constraints: /* opt_column_constraints  */
#line 168 "bison_parser.y"
                { }
#line 2260 "bison_parser.cpp"
        break;

    case YYSYMBOL_column_constraint_set: /* column_constraint_set  */
#line 168 "bison_parser.y"
                { }
#line 2266 "bison_parser.cpp"
        break;

    case YYSYMBOL_column_constraint: /* column_constraint  */
#line 168 "bison_parser.y"
                { }
#line 2272 "bison_parser.cpp"
        break;

    case YYSYMBOL_table_constraint: /* table_constraint  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).table_constraint_t)); }
#line 2278 "bison_parser.cpp"
        break;

    case YYSYMBOL_drop_statement: /* drop_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).drop_stmt)); }
#line 2284 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_exists: /* opt_exists  */
#line 168 "bison_parser.y"
                { }
#line 2290 "bison_parser.cpp"
        break;

    case YYSYMBOL_alter_statement: /* alter_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).alter_stmt)); }
#line 2296 "bison_parser.cpp"
        break;

    case YYSYMBOL_alter_action: /* alter_action  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).alter_action_t)); }
#line 2302 "bison_parser.cpp"
        break;

    case YYSYMBOL_drop_action: /* drop_action  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).drop_action_t)); }
#line 2308 "bison_parser.cpp"
        break;

    case YYSYMBOL_delete_statement: /* delete_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).delete_stmt)); }
#line 2314 "bison_parser.cpp"
        break;

    case YYSYMBOL_truncate_statement: /* truncate_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).delete_stmt)); }
#line 2320 "bison_parser.cpp"
        break;

    case YYSYMBOL_insert_statement: /* insert_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).insert_stmt)); }
#line 2326 "bison_parser.cpp"
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
#line 2339 "bison_parser.cpp"
        break;

    case YYSYMBOL_update_statement: /* update_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).update_stmt)); }
#line 2345 "bison_parser.cpp"
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
#line 2358 "bison_parser.cpp"
        break;

    case YYSYMBOL_update_clause: /* update_clause  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).update_t)); }
#line 2364 "bison_parser.cpp"
        break;

    case YYSYMBOL_select_statement: /* select_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2370 "bison_parser.cpp"
        break;

    case YYSYMBOL_select_within_set_operation: /* select_within_set_operation  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2376 "bison_parser.cpp"
        break;

    case YYSYMBOL_select_within_set_operation_no_parentheses: /* select_within_set_operation_no_parentheses  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2382 "bison_parser.cpp"
        break;

    case YYSYMBOL_select_with_paren: /* select_with_paren  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2388 "bison_parser.cpp"
        break;

    case YYSYMBOL_select_no_paren: /* select_no_paren  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2394 "bison_parser.cpp"
        break;

    case YYSYMBOL_set_operator: /* set_operator  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).set_operator_t)); }
#line 2400 "bison_parser.cpp"
        break;

    case YYSYMBOL_set_type: /* set_type  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).set_operator_t)); }
#line 2406 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_all: /* opt_all  */
#line 168 "bison_parser.y"
                { }
#line 2412 "bison_parser.cpp"
        break;

    case YYSYMBOL_select_clause: /* select_clause  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2418 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_distinct: /* opt_distinct  */
#line 168 "bison_parser.y"
                { }
#line 2424 "bison_parser.cpp"
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
#line 2437 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_from_clause: /* opt_from_clause  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2443 "bison_parser.cpp"
        break;

    case YYSYMBOL_from_clause: /* from_clause  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2449 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_where: /* opt_where  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2455 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_group: /* opt_group  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).group_t)); }
#line 2461 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_having: /* opt_having  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2467 "bison_parser.cpp"
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
#line 2480 "bison_parser.cpp"
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
#line 2493 "bison_parser.cpp"
        break;

    case YYSYMBOL_order_desc: /* order_desc  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).order)); }
#line 2499 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_order_type: /* opt_order_type  */
#line 168 "bison_parser.y"
                { }
#line 2505 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_top: /* opt_top  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).limit)); }
#line 2511 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_limit: /* opt_limit  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).limit)); }
#line 2517 "bison_parser.cpp"
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
#line 2530 "bison_parser.cpp"
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
#line 2543 "bison_parser.cpp"
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
#line 2556 "bison_parser.cpp"
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
#line 2569 "bison_parser.cpp"
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
#line 2582 "bison_parser.cpp"
        break;

    case YYSYMBOL_expr_alias: /* expr_alias  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2588 "bison_parser.cpp"
        break;

    case YYSYMBOL_expr: /* expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2594 "bison_parser.cpp"
        break;

    case YYSYMBOL_operand: /* operand  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2600 "bison_parser.cpp"
        break;

    case YYSYMBOL_scalar_expr: /* scalar_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2606 "bison_parser.cpp"
        break;

    case YYSYMBOL_unary_expr: /* unary_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2612 "bison_parser.cpp"
        break;

    case YYSYMBOL_binary_expr: /* binary_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2618 "bison_parser.cpp"
        break;

    case YYSYMBOL_logic_expr: /* logic_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2624 "bison_parser.cpp"
        break;

    case YYSYMBOL_in_expr: /* in_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2630 "bison_parser.cpp"
        break;

    case YYSYMBOL_case_expr: /* case_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2636 "bison_parser.cpp"
        break;

    case YYSYMBOL_case_list: /* case_list  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2642 "bison_parser.cpp"
        break;

    case YYSYMBOL_exists_expr: /* exists_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2648 "bison_parser.cpp"
        break;

    case YYSYMBOL_comp_expr: /* comp_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2654 "bison_parser.cpp"
        break;

    case YYSYMBOL_function_expr: /* function_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2660 "bison_parser.cpp"
        break;

    case YYSYMBOL_extract_expr: /* extract_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2666 "bison_parser.cpp"
        break;

    case YYSYMBOL_cast_expr: /* cast_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2672 "bison_parser.cpp"
        break;

    case YYSYMBOL_datetime_field: /* datetime_field  */
#line 168 "bison_parser.y"
                { }
#line 2678 "bison_parser.cpp"
        break;

    case YYSYMBOL_datetime_field_plural: /* datetime_field_plural  */
#line 168 "bison_parser.y"
                { }
#line 2684 "bison_parser.cpp"
        break;

    case YYSYMBOL_duration_field: /* duration_field  */
#line 168 "bison_parser.y"
                { }
#line 2690 "bison_parser.cpp"
        break;

    case YYSYMBOL_array_expr: /* array_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2696 "bison_parser.cpp"
        break;

    case YYSYMBOL_array_index: /* array_index  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2702 "bison_parser.cpp"
        break;

    case YYSYMBOL_between_expr: /* between_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2708 "bison_parser.cpp"
        break;

    case YYSYMBOL_column_name: /* column_name  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2714 "bison_parser.cpp"
        break;

    case YYSYMBOL_literal: /* literal  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2720 "bison_parser.cpp"
        break;

    case YYSYMBOL_string_literal: /* string_literal  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2726 "bison_parser.cpp"
        break;

    case YYSYMBOL_bool_literal: /* bool_literal  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2732 "bison_parser.cpp"
        break;

    case YYSYMBOL_num_literal: /* num_literal  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2738 "bison_parser.cpp"
        break;

    case YYSYMBOL_int_literal: /* int_literal  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2744 "bison_parser.cpp"
        break;

    case YYSYMBOL_null_literal: /* null_literal  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2750 "bison_parser.cpp"
        break;

    case YYSYMBOL_date_literal: /* date_literal  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2756 "bison_parser.cpp"
        break;

    case YYSYMBOL_interval_literal: /* interval_literal  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2762 "bison_parser.cpp"
        break;

    case YYSYMBOL_param_expr: /* param_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2768 "bison_parser.cpp"
        break;

    case YYSYMBOL_table_ref: /* table_ref  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2774 "bison_parser.cpp"
        break;

    case YYSYMBOL_table_ref_atomic: /* table_ref_atomic  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2780 "bison_parser.cpp"
        break;

    case YYSYMBOL_nonjoin_table_ref_atomic: /* nonjoin_table_ref_atomic  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2786 "bison_parser.cpp"
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
#line 2799 "bison_parser.cpp"
        break;

    case YYSYMBOL_table_ref_name: /* table_ref_name  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2805 "bison_parser.cpp"
        break;

    case YYSYMBOL_table_ref_name_no_alias: /* table_ref_name_no_alias  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2811 "bison_parser.cpp"
        break;

    case YYSYMBOL_table_name: /* table_name  */
#line 169 "bison_parser.y"
                { free( (((*yyvaluep).table_name).name) ); free( (((*yyvaluep).table_name).schema) ); }
#line 2817 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_index_name: /* opt_index_name  */
#line 170 "bison_parser.y"
                { free( (((*yyvaluep).sval)) ); }
#line 2823 "bison_parser.cpp"
        break;

    case YYSYMBOL_table_alias: /* table_alias  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).alias_t)); }
#line 2829 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_table_alias: /* opt_table_alias  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).alias_t)); }
#line 2835 "bison_parser.cpp"
        break;

    case YYSYMBOL_alias: /* alias  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).alias_t)); }
#line 2841 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_alias: /* opt_alias  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).alias_t)); }
#line 2847 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_locking_clause: /* opt_locking_clause  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).locking_clause_vec)); }
#line 2853 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_locking_clause_list: /* opt_locking_clause_list  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).locking_clause_vec)); }
#line 2859 "bison_parser.cpp"
        break;

    case YYSYMBOL_locking_clause: /* locking_clause  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).locking_t)); }
#line 2865 "bison_parser.cpp"
        break;

    case YYSYMBOL_row_lock_mode: /* row_lock_mode  */
#line 168 "bison_parser.y"
                { }
#line 2871 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_row_lock_policy: /* opt_row_lock_policy  */
#line 168 "bison_parser.y"
                { }
#line 2877 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_with_clause: /* opt_with_clause  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).with_description_vec)); }
#line 2883 "bison_parser.cpp"
        break;

    case YYSYMBOL_with_clause: /* with_clause  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).with_description_vec)); }
#line 2889 "bison_parser.cpp"
        break;

    case YYSYMBOL_with_description_list: /* with_description_list  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).with_description_vec)); }
#line 2895 "bison_parser.cpp"
        break;

    case YYSYMBOL_with_description: /* with_description  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).with_description_t)); }
#line 2901 "bison_parser.cpp"
        break;

    case YYSYMBOL_join_clause: /* join_clause  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2907 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_join_type: /* opt_join_type  */
#line 168 "bison_parser.y"
                { }
#line 2913 "bison_parser.cpp"
        break;

    case YYSYMBOL_join_condition: /* join_condition  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2919 "bison_parser.cpp"
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
#line 2932 "bison_parser.cpp"
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

#line 3040 "bison_parser.cpp"

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
#line 3269 "bison_parser.cpp"
    break;

  case 3: /* statement_list: statement  */
#line 328 "bison_parser.y"
                           {
  (yyvsp[0].statement)->stringLength = yylloc.string_length;
  yylloc.string_length = 0;
  (yyval.stmt_vec) = new std::vector<SQLStatement*>();
  (yyval.stmt_vec)->push_back((yyvsp[0].statement));
}
#line 3280 "bison_parser.cpp"
    break;

  case 4: /* statement_list: statement_list ';' statement  */
#line 334 "bison_parser.y"
                               {
  (yyvsp[0].statement)->stringLength = yylloc.string_length;
  yylloc.string_length = 0;
  (yyvsp[-2].stmt_vec)->push_back((yyvsp[0].statement));
  (yyval.stmt_vec) = (yyvsp[-2].stmt_vec);
}
#line 3291 "bison_parser.cpp"
    break;

  case 5: /* statement: prepare_statement opt_hints  */
#line 341 "bison_parser.y"
                                        {
  (yyval.statement) = (yyvsp[-1].prep_stmt);
  (yyval.statement)->hints = (yyvsp[0].expr_vec);
}
#line 3300 "bison_parser.cpp"
    break;

  case 6: /* statement: preparable_statement opt_hints  */
#line 345 "bison_parser.y"
                                 {
  (yyval.statement) = (yyvsp[-1].statement);
  (yyval.statement)->hints = (yyvsp[0].expr_vec);
}
#line 3309 "bison_parser.cpp"
    break;

  case 7: /* statement: show_statement  */
#line 349 "bison_parser.y"
                 { (yyval.statement) = (yyvsp[0].show_stmt); }
#line 3315 "bison_parser.cpp"
    break;

  case 8: /* statement: import_statement  */
#line 350 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].import_stmt); }
#line 3321 "bison_parser.cpp"
    break;

  case 9: /* statement: export_statement  */
#line 351 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].export_stmt); }
#line 3327 "bison_parser.cpp"
    break;

  case 10: /* preparable_statement: select_statement  */
#line 353 "bison_parser.y"
                                        { (yyval.statement) = (yyvsp[0].select_stmt); }
#line 3333 "bison_parser.cpp"
    break;

  case 11: /* preparable_statement: create_statement  */
#line 354 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].create_stmt); }
#line 3339 "bison_parser.cpp"
    break;

  case 12: /* preparable_statement: insert_statement  */
#line 355 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].insert_stmt); }
#line 3345 "bison_parser.cpp"
    break;

  case 13: /* preparable_statement: delete_statement  */
#line 356 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].delete_stmt); }
#line 3351 "bison_parser.cpp"
    break;

  case 14: /* preparable_statement: truncate_statement  */
#line 357 "bison_parser.y"
                     { (yyval.statement) = (yyvsp[0].delete_stmt); }
#line 3357 "bison_parser.cpp"
    break;

  case 15: /* preparable_statement: update_statement  */
#line 358 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].update_stmt); }
#line 3363 "bison_parser.cpp"
    break;

  case 16: /* preparable_statement: drop_statement  */
#line 359 "bison_parser.y"
                 { (yyval.statement) = (yyvsp[0].drop_stmt); }
#line 3369 "bison_parser.cpp"
    break;

  case 17: /* preparable_statement: alter_statement  */
#line 360 "bison_parser.y"
                  { (yyval.statement) = (yyvsp[0].alter_stmt); }
#line 3375 "bison_parser.cpp"
    break;

  case 18: /* preparable_statement: execute_statement  */
#line 361 "bison_parser.y"
                    { (yyval.statement) = (yyvsp[0].exec_stmt); }
#line 3381 "bison_parser.cpp"
    break;

  case 19: /* preparable_statement: transaction_statement  */
#line 362 "bison_parser.y"
                        { (yyval.statement) = (yyvsp[0].transaction_stmt); }
#line 3387 "bison_parser.cpp"
    break;

  case 20: /* preparable_statement: other_statement  */
#line 363 "bison_parser.y"
                  { (yyval.statement) = (yyvsp[0].other_stmt); }
#line 3393 "bison_parser.cpp"
    break;

  case 21: /* opt_hints: WITH HINT '(' hint_list ')'  */
#line 369 "bison_parser.y"
                                        { (yyval.expr_vec) = (yyvsp[-1].expr_vec); }
#line 3399 "bison_parser.cpp"
    break;

  case 22: /* opt_hints: %empty  */
#line 370 "bison_parser.y"
              { (yyval.expr_vec) = nullptr; }
#line 3405 "bison_parser.cpp"
    break;

  case 23: /* hint_list: hint  */
#line 372 "bison_parser.y"
                 {
  (yyval.expr_vec) = new std::vector<Expr*>();
  (yyval.expr_vec)->push_back((yyvsp[0].expr));
}
#line 3414 "bison_parser.cpp"
    break;

  case 24: /* hint_list: hint_list ',' hint  */
#line 376 "bison_parser.y"
                     {
  (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr));
  (yyval.expr_vec) = (yyvsp[-2].expr_vec);
}
#line 3423 "bison_parser.cpp"
    break;

  case 25: /* hint: IDENTIFIER  */
#line 381 "bison_parser.y"
                  {
  (yyval.expr) = Expr::make(kExprHint);
  (yyval.expr)->name = (yyvsp[0].sval);
}
#line 3432 "bison_parser.cpp"
    break;

  case 26: /* hint: IDENTIFIER '(' literal_list ')'  */
#line 385 "bison_parser.y"
                                  {
  (yyval.expr) = Expr::make(kExprHint);
  (yyval.expr)->name = (yyvsp[-3].sval);
  (yyval.expr)->exprList = (yyvsp[-1].expr_vec);
}
#line 3442 "bison_parser.cpp"
    break;

  case 27: /* transaction_statement: BEGIN opt_transaction_keyword  */
#line 395 "bison_parser.y"
                                                      { (yyval.transaction_stmt) = new TransactionStatement(kBeginTransaction); }
#line 3448 "bison_parser.cpp"
    break;

  case 28: /* transaction_statement: ROLLBACK opt_transaction_keyword  */
#line 396 "bison_parser.y"
                                   { (yyval.transaction_stmt) = new TransactionStatement(kRollbackTransaction); }
#line 3454 "bison_parser.cpp"
    break;

  case 29: /* transaction_statement: COMMIT opt_transaction_keyword  */
#line 397 "bison_parser.y"
                                 { (yyval.transaction_stmt) = new TransactionStatement(kCommitTransaction); }
#line 3460 "bison_parser.cpp"
    break;

  case 32: /* other_statement: HELP  */
#line 406 "bison_parser.y"
                       { (yyval.other_stmt) = new OtherStatement(kHelp); }
#line 3466 "bison_parser.cpp"
    break;

  case 33: /* other_statement: SYNC  */
#line 407 "bison_parser.y"
       { (yyval.other_stmt) = new OtherStatement(kSync); }
#line 3472 "bison_parser.cpp"
    break;

  case 34: /* prepare_statement: PREPARE IDENTIFIER FROM prepare_target_query  */
#line 412 "bison_parser.y"
                                                                 {
  (yyval.prep_stmt) = new PrepareStatement();
  (yyval.prep_stmt)->name = (yyvsp[-2].sval);
  (yyval.prep_stmt)->query = (yyvsp[0].sval);
}
#line 3482 "bison_parser.cpp"
    break;

  case 36: /* execute_statement: EXECUTE IDENTIFIER  */
#line 420 "bison_parser.y"
                                                                  {
  (yyval.exec_stmt) = new ExecuteStatement();
  (yyval.exec_stmt)->name = (yyvsp[0].sval);
}
#line 3491 "bison_parser.cpp"
    break;

  case 37: /* execute_statement: EXECUTE IDENTIFIER '(' opt_literal_list ')'  */
#line 424 "bison_parser.y"
                                              {
  (yyval.exec_stmt) = new ExecuteStatement();
  (yyval.exec_stmt)->name = (yyvsp[-3].sval);
  (yyval.exec_stmt)->parameters = (yyvsp[-1].expr_vec);
}
#line 3501 "bison_parser.cpp"
    break;

  case 38: /* import_statement: IMPORT FROM file_type FILE file_path INTO table_name  */
#line 435 "bison_parser.y"
                                                                        {
  (yyval.import_stmt) = new ImportStatement((yyvsp[-4].import_type_t));
  (yyval.import_stmt)->filePath = (yyvsp[-2].sval);
  (yyval.import_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.import_stmt)->tableName = (yyvsp[0].table_name).name;
}
#line 3512 "bison_parser.cpp"
    break;

  case 39: /* import_statement: COPY table_name FROM file_path opt_file_type  */
#line 441 "bison_parser.y"
                                               {
  (yyval.import_stmt) = new ImportStatement((yyvsp[0].import_type_t));
  (yyval.import_stmt)->filePath = (yyvsp[-1].sval);
  (yyval.import_stmt)->schema = (yyvsp[-3].table_name).schema;
  (yyval.import_stmt)->tableName = (yyvsp[-3].table_name).name;
}
#line 3523 "bison_parser.cpp"
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
#line 3542 "bison_parser.cpp"
    break;

  case 41: /* file_path: string_literal  */
#line 463 "bison_parser.y"
                           {
  (yyval.sval) = strdup((yyvsp[0].expr)->name);
  delete (yyvsp[0].expr);
}
#line 3551 "bison_parser.cpp"
    break;

  case 42: /* opt_file_type: WITH FORMAT file_type  */
#line 468 "bison_parser.y"
                                      { (yyval.import_type_t) = (yyvsp[0].import_type_t); }
#line 3557 "bison_parser.cpp"
    break;

  case 43: /* opt_file_type: %empty  */
#line 469 "bison_parser.y"
              { (yyval.import_type_t) = kImportAuto; }
#line 3563 "bison_parser.cpp"
    break;

  case 44: /* export_statement: COPY table_name TO file_path opt_file_type  */
#line 475 "bison_parser.y"
                                                              {
  (yyval.export_stmt) = new ExportStatement((yyvsp[0].import_type_t));
  (yyval.export_stmt)->filePath = (yyvsp[-1].sval);
  (yyval.export_stmt)->schema = (yyvsp[-3].table_name).schema;
  (yyval.export_stmt)->tableName = (yyvsp[-3].table_name).name;
}
#line 3574 "bison_parser.cpp"
    break;

  case 45: /* show_statement: SHOW TABLES  */
#line 487 "bison_parser.y"
                             { (yyval.show_stmt) = new ShowStatement(kShowTables); }
#line 3580 "bison_parser.cpp"
    break;

  case 46: /* show_statement: SHOW COLUMNS table_name  */
#line 488 "bison_parser.y"
                          {
  (yyval.show_stmt) = new ShowStatement(kShowColumns);
  (yyval.show_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.show_stmt)->name = (yyvsp[0].table_name).name;
}
#line 3590 "bison_parser.cpp"
    break;

  case 47: /* show_statement: DESCRIBE table_name  */
#line 493 "bison_parser.y"
                      {
  (yyval.show_stmt) = new ShowStatement(kShowColumns);
  (yyval.show_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.show_stmt)->name = (yyvsp[0].table_name).name;
}
#line 3600 "bison_parser.cpp"
    break;

  case 48: /* show_statement: DESC table_name  */
#line 498 "bison_parser.y"
                  {
  (yyval.show_stmt) = new ShowStatement(kShowColumns);
  (yyval.show_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.show_stmt)->name = (yyvsp[0].table_name).name;
}
#line 3610 "bison_parser.cpp"
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
#line 3628 "bison_parser.cpp"
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
#line 3645 "bison_parser.cpp"
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
#line 3657 "bison_parser.cpp"
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
#line 3670 "bison_parser.cpp"
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
#line 3683 "bison_parser.cpp"
    break;

  case 54: /* opt_not_exists: IF NOT EXISTS  */
#line 558 "bison_parser.y"
                               { (yyval.bval) = true; }
#line 3689 "bison_parser.cpp"
    break;

  case 55: /* opt_not_exists: %empty  */
#line 559 "bison_parser.y"
              { (yyval.bval) = false; }
#line 3695 "bison_parser.cpp"
    break;

  case 56: /* opt_unique: UNIQUE  */
#line 561 "bison_parser.y"
                   { (yyval.bval) = true; }
#line 3701 "bison_parser.cpp"
    break;

  case 57: /* opt_unique: %empty  */
#line 562 "bison_parser.y"
              { (yyval.bval) = false; }
#line 3707 "bison_parser.cpp"
    break;

  case 58: /* table_elem_commalist: table_elem  */
#line 564 "bison_parser.y"
                                  {
  (yyval.table_element_vec) = new std::vector<TableElement*>();
  (yyval.table_element_vec)->push_back((yyvsp[0].table_element_t));
}
#line 3716 "bison_parser.cpp"
    break;

  case 59: /* table_elem_commalist: table_elem_commalist ',' table_elem  */
#line 568 "bison_parser.y"
                                      {
  (yyvsp[-2].table_element_vec)->push_back((yyvsp[0].table_element_t));
  (yyval.table_element_vec) = (yyvsp[-2].table_element_vec);
}
#line 3725 "bison_parser.cpp"
    break;

  case 60: /* table_elem: column_def  */
#line 573 "bison_parser.y"
                        { (yyval.table_element_t) = (yyvsp[0].column_t); }
#line 3731 "bison_parser.cpp"
    break;

  case 61: /* table_elem: table_constraint  */
#line 574 "bison_parser.y"
                   { (yyval.table_element_t) = (yyvsp[0].table_constraint_t); }
#line 3737 "bison_parser.cpp"
    break;

  case 62: /* column_def: IDENTIFIER column_type opt_column_constraints  */
#line 576 "bison_parser.y"
                                                           {
  (yyval.column_t) = new ColumnDefinition((yyvsp[-2].sval), (yyvsp[-1].column_type_t), (yyvsp[0].column_constraint_set));
  if (!(yyval.column_t)->trySetNullableExplicit()) {
    yyerror(&yyloc, result, scanner, ("Conflicting nullability constraints for " + std::string{(yyvsp[-2].sval)}).c_str());
  }
}
#line 3748 "bison_parser.cpp"
    break;

  case 63: /* column_type: BIGINT  */
#line 583 "bison_parser.y"
                     { (yyval.column_type_t) = ColumnType{DataType::BIGINT}; }
#line 3754 "bison_parser.cpp"
    break;

  case 64: /* column_type: BOOLEAN  */
#line 584 "bison_parser.y"
          { (yyval.column_type_t) = ColumnType{DataType::BOOLEAN}; }
#line 3760 "bison_parser.cpp"
    break;

  case 65: /* column_type: CHAR '(' INTVAL ')'  */
#line 585 "bison_parser.y"
                      { (yyval.column_type_t) = ColumnType{DataType::CHAR, (yyvsp[-1].ival)}; }
#line 3766 "bison_parser.cpp"
    break;

  case 66: /* column_type: CHARACTER_VARYING '(' INTVAL ')'  */
#line 586 "bison_parser.y"
                                   { (yyval.column_type_t) = ColumnType{DataType::VARCHAR, (yyvsp[-1].ival)}; }
#line 3772 "bison_parser.cpp"
    break;

  case 67: /* column_type: DATE  */
#line 587 "bison_parser.y"
       { (yyval.column_type_t) = ColumnType{DataType::DATE}; }
#line 3778 "bison_parser.cpp"
    break;

  case 68: /* column_type: DATETIME  */
#line 588 "bison_parser.y"
           { (yyval.column_type_t) = ColumnType{DataType::DATETIME}; }
#line 3784 "bison_parser.cpp"
    break;

  case 69: /* column_type: DECIMAL opt_decimal_specification  */
#line 589 "bison_parser.y"
                                    {
  (yyval.column_type_t) = ColumnType{DataType::DECIMAL, 0, (yyvsp[0].ival_pair)->first, (yyvsp[0].ival_pair)->second};
  delete (yyvsp[0].ival_pair);
}
#line 3793 "bison_parser.cpp"
    break;

  case 70: /* column_type: DOUBLE  */
#line 593 "bison_parser.y"
         { (yyval.column_type_t) = ColumnType{DataType::DOUBLE}; }
#line 3799 "bison_parser.cpp"
    break;

  case 71: /* column_type: FLOAT  */
#line 594 "bison_parser.y"
        { (yyval.column_type_t) = ColumnType{DataType::FLOAT}; }
#line 3805 "bison_parser.cpp"
    break;

  case 72: /* column_type: INT  */
#line 595 "bison_parser.y"
      { (yyval.column_type_t) = ColumnType{DataType::INT}; }
#line 3811 "bison_parser.cpp"
    break;

  case 73: /* column_type: INTEGER  */
#line 596 "bison_parser.y"
          { (yyval.column_type_t) = ColumnType{DataType::INT}; }
#line 3817 "bison_parser.cpp"
    break;

  case 74: /* column_type: LONG  */
#line 597 "bison_parser.y"
       { (yyval.column_type_t) = ColumnType{DataType::LONG}; }
#line 3823 "bison_parser.cpp"
    break;

  case 75: /* column_type: REAL  */
#line 598 "bison_parser.y"
       { (yyval.column_type_t) = ColumnType{DataType::REAL}; }
#line 3829 "bison_parser.cpp"
    break;

  case 76: /* column_type: SMALLINT  */
#line 599 "bison_parser.y"
           { (yyval.column_type_t) = ColumnType{DataType::SMALLINT}; }
#line 3835 "bison_parser.cpp"
    break;

  case 77: /* column_type: TEXT  */
#line 600 "bison_parser.y"
       { (yyval.column_type_t) = ColumnType{DataType::TEXT}; }
#line 3841 "bison_parser.cpp"
    break;

  case 78: /* column_type: TIME opt_time_precision  */
#line 601 "bison_parser.y"
                          { (yyval.column_type_t) = ColumnType{DataType::TIME, 0, (yyvsp[0].ival)}; }
#line 3847 "bison_parser.cpp"
    break;

  case 79: /* column_type: TIMESTAMP  */
#line 602 "bison_parser.y"
            { (yyval.column_type_t) = ColumnType{DataType::DATETIME}; }
#line 3853 "bison_parser.cpp"
    break;

  case 80: /* column_type: VARCHAR '(' INTVAL ')'  */
#line 603 "bison_parser.y"
                         { (yyval.column_type_t) = ColumnType{DataType::VARCHAR, (yyvsp[-1].ival)}; }
#line 3859 "bison_parser.cpp"
    break;

  case 81: /* opt_time_precision: '(' INTVAL ')'  */
#line 605 "bison_parser.y"
                                    { (yyval.ival) = (yyvsp[-1].ival); }
#line 3865 "bison_parser.cpp"
    break;

  case 82: /* opt_time_precision: %empty  */
#line 606 "bison_parser.y"
              { (yyval.ival) = 0; }
#line 3871 "bison_parser.cpp"
    break;

  case 83: /* opt_decimal_specification: '(' INTVAL ',' INTVAL ')'  */
#line 608 "bison_parser.y"
                                                      { (yyval.ival_pair) = new std::pair<int64_t, int64_t>{(yyvsp[-3].ival), (yyvsp[-1].ival)}; }
#line 3877 "bison_parser.cpp"
    break;

  case 84: /* opt_decimal_specification: '(' INTVAL ')'  */
#line 609 "bison_parser.y"
                 { (yyval.ival_pair) = new std::pair<int64_t, int64_t>{(yyvsp[-1].ival), 0}; }
#line 3883 "bison_parser.cpp"
    break;

  case 85: /* opt_decimal_specification: %empty  */
#line 610 "bison_parser.y"
              { (yyval.ival_pair) = new std::pair<int64_t, int64_t>{0, 0}; }
#line 3889 "bison_parser.cpp"
    break;

  case 86: /* opt_column_constraints: column_constraint_set  */
#line 612 "bison_parser.y"
                                               { (yyval.column_constraint_set) = (yyvsp[0].column_constraint_set); }
#line 3895 "bison_parser.cpp"
    break;

  case 87: /* opt_column_constraints: %empty  */
#line 613 "bison_parser.y"
              { (yyval.column_constraint_set) = new std::unordered_set<ConstraintType>(); }
#line 3901 "bison_parser.cpp"
    break;

  case 88: /* column_constraint_set: column_constraint  */
#line 615 "bison_parser.y"
                                          {
  (yyval.column_constraint_set) = new std::unordered_set<ConstraintType>();
  (yyval.column_constraint_set)->insert((yyvsp[0].column_constraint_t));
}
#line 3910 "bison_parser.cpp"
    break;

  case 89: /* column_constraint_set: column_constraint_set column_constraint  */
#line 619 "bison_parser.y"
                                          {
  (yyvsp[-1].column_constraint_set)->insert((yyvsp[0].column_constraint_t));
  (yyval.column_constraint_set) = (yyvsp[-1].column_constraint_set);
}
#line 3919 "bison_parser.cpp"
    break;

  case 90: /* column_constraint: PRIMARY KEY  */
#line 624 "bison_parser.y"
                                { (yyval.column_constraint_t) = ConstraintType::PrimaryKey; }
#line 3925 "bison_parser.cpp"
    break;

  case 91: /* column_constraint: UNIQUE  */
#line 625 "bison_parser.y"
         { (yyval.column_constraint_t) = ConstraintType::Unique; }
#line 3931 "bison_parser.cpp"
    break;

  case 92: /* column_constraint: NULL  */
#line 626 "bison_parser.y"
       { (yyval.column_constraint_t) = ConstraintType::Null; }
#line 3937 "bison_parser.cpp"
    break;

  case 93: /* column_constraint: NOT NULL  */
#line 627 "bison_parser.y"
           { (yyval.column_constraint_t) = ConstraintType::NotNull; }
#line 3943 "bison_parser.cpp"
    break;

  case 94: /* column_constraint: NULLABLE  */
#line 628 "bison_parser.y"
           { (yyval.column_constraint_t) = ConstraintType::Null; }
#line 3949 "bison_parser.cpp"
    break;

  case 95: /* table_constraint: PRIMARY KEY '(' ident_commalist ')'  */
#line 630 "bison_parser.y"
                                                       { (yyval.table_constraint_t) = new TableConstraint(ConstraintType::PrimaryKey, (yyvsp[-1].str_vec)); }
#line 3955 "bison_parser.cpp"
    break;

  case 96: /* table_constraint: UNIQUE '(' ident_commalist ')'  */
#line 631 "bison_parser.y"
                                 { (yyval.table_constraint_t) = new TableConstraint(ConstraintType::Unique, (yyvsp[-1].str_vec)); }
#line 3961 "bison_parser.cpp"
    break;

  case 97: /* drop_statement: DROP TABLE opt_exists table_name  */
#line 639 "bison_parser.y"
                                                  {
  (yyval.drop_stmt) = new DropStatement(kDropTable);
  (yyval.drop_stmt)->ifExists = (yyvsp[-1].bval);
  (yyval.drop_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.drop_stmt)->name = (yyvsp[0].table_name).name;
}
#line 3972 "bison_parser.cpp"
    break;

  case 98: /* drop_statement: DROP VIEW opt_exists table_name  */
#line 645 "bison_parser.y"
                                  {
  (yyval.drop_stmt) = new DropStatement(kDropView);
  (yyval.drop_stmt)->ifExists = (yyvsp[-1].bval);
  (yyval.drop_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.drop_stmt)->name = (yyvsp[0].table_name).name;
}
#line 3983 "bison_parser.cpp"
    break;

  case 99: /* drop_statement: DEALLOCATE PREPARE IDENTIFIER  */
#line 651 "bison_parser.y"
                                {
  (yyval.drop_stmt) = new DropStatement(kDropPreparedStatement);
  (yyval.drop_stmt)->ifExists = false;
  (yyval.drop_stmt)->name = (yyvsp[0].sval);
}
#line 3993 "bison_parser.cpp"
    break;

  case 100: /* drop_statement: DROP INDEX opt_exists IDENTIFIER  */
#line 657 "bison_parser.y"
                                   {
  (yyval.drop_stmt) = new DropStatement(kDropIndex);
  (yyval.drop_stmt)->ifExists = (yyvsp[-1].bval);
  (yyval.drop_stmt)->indexName = (yyvsp[0].sval);
}
#line 4003 "bison_parser.cpp"
    break;

  case 101: /* opt_exists: IF EXISTS  */
#line 663 "bison_parser.y"
                       { (yyval.bval) = true; }
#line 4009 "bison_parser.cpp"
    break;

  case 102: /* opt_exists: %empty  */
#line 664 "bison_parser.y"
              { (yyval.bval) = false; }
#line 4015 "bison_parser.cpp"
    break;

  case 103: /* alter_statement: ALTER TABLE opt_exists table_name alter_action  */
#line 671 "bison_parser.y"
                                                                 {
  (yyval.alter_stmt) = new AlterStatement((yyvsp[-1].table_name).name, (yyvsp[0].alter_action_t));
  (yyval.alter_stmt)->ifTableExists = (yyvsp[-2].bval);
  (yyval.alter_stmt)->schema = (yyvsp[-1].table_name).schema;
}
#line 4025 "bison_parser.cpp"
    break;

  case 104: /* alter_action: drop_action  */
#line 677 "bison_parser.y"
                           { (yyval.alter_action_t) = (yyvsp[0].drop_action_t); }
#line 4031 "bison_parser.cpp"
    break;

  case 105: /* drop_action: DROP COLUMN opt_exists IDENTIFIER  */
#line 679 "bison_parser.y"
                                                {
  (yyval.drop_action_t) = new DropColumnAction((yyvsp[0].sval));
  (yyval.drop_action_t)->ifExists = (yyvsp[-1].bval);
}
#line 4040 "bison_parser.cpp"
    break;

  case 106: /* delete_statement: DELETE FROM table_name opt_where  */
#line 689 "bison_parser.y"
                                                    {
  (yyval.delete_stmt) = new DeleteStatement();
  (yyval.delete_stmt)->schema = (yyvsp[-1].table_name).schema;
  (yyval.delete_stmt)->tableName = (yyvsp[-1].table_name).name;
  (yyval.delete_stmt)->expr = (yyvsp[0].expr);
}
#line 4051 "bison_parser.cpp"
    break;

  case 107: /* truncate_statement: TRUNCATE table_name  */
#line 696 "bison_parser.y"
                                         {
  (yyval.delete_stmt) = new DeleteStatement();
  (yyval.delete_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.delete_stmt)->tableName = (yyvsp[0].table_name).name;
}
#line 4061 "bison_parser.cpp"
    break;

  case 108: /* insert_statement: INSERT INTO table_name opt_column_list VALUES list_of_list  */
#line 707 "bison_parser.y"
                                                                              {
  (yyval.insert_stmt) = new InsertStatement(kInsertValues);
  (yyval.insert_stmt)->schema = (yyvsp[-3].table_name).schema;
  (yyval.insert_stmt)->tableName = (yyvsp[-3].table_name).name;
  (yyval.insert_stmt)->columns = (yyvsp[-2].str_vec);
  (yyval.insert_stmt)->values = (yyvsp[0].list_vec);
}
#line 4073 "bison_parser.cpp"
    break;

  case 109: /* insert_statement: INSERT INTO table_name opt_column_list select_no_paren  */
#line 714 "bison_parser.y"
                                                         {
  (yyval.insert_stmt) = new InsertStatement(kInsertSelect);
  (yyval.insert_stmt)->schema = (yyvsp[-2].table_name).schema;
  (yyval.insert_stmt)->tableName = (yyvsp[-2].table_name).name;
  (yyval.insert_stmt)->columns = (yyvsp[-1].str_vec);
  (yyval.insert_stmt)->select = (yyvsp[0].select_stmt);
}
#line 4085 "bison_parser.cpp"
    break;

  case 110: /* opt_column_list: '(' ident_commalist ')'  */
#line 722 "bison_parser.y"
                                          { (yyval.str_vec) = (yyvsp[-1].str_vec); }
#line 4091 "bison_parser.cpp"
    break;

  case 111: /* opt_column_list: %empty  */
#line 723 "bison_parser.y"
              { (yyval.str_vec) = nullptr; }
#line 4097 "bison_parser.cpp"
    break;

  case 112: /* update_statement: UPDATE table_ref_name_no_alias SET update_clause_commalist opt_where  */
#line 730 "bison_parser.y"
                                                                                        {
  (yyval.update_stmt) = new UpdateStatement();
  (yyval.update_stmt)->table = (yyvsp[-3].table);
  (yyval.update_stmt)->updates = (yyvsp[-1].update_vec);
  (yyval.update_stmt)->where = (yyvsp[0].expr);
}
#line 4108 "bison_parser.cpp"
    break;

  case 113: /* update_clause_commalist: update_clause  */
#line 737 "bison_parser.y"
                                        {
  (yyval.update_vec) = new std::vector<UpdateClause*>();
  (yyval.update_vec)->push_back((yyvsp[0].update_t));
}
#line 4117 "bison_parser.cpp"
    break;

  case 114: /* update_clause_commalist: update_clause_commalist ',' update_clause  */
#line 741 "bison_parser.y"
                                            {
  (yyvsp[-2].update_vec)->push_back((yyvsp[0].update_t));
  (yyval.update_vec) = (yyvsp[-2].update_vec);
}
#line 4126 "bison_parser.cpp"
    break;

  case 115: /* update_clause: IDENTIFIER '=' expr  */
#line 746 "bison_parser.y"
                                    {
  (yyval.update_t) = new UpdateClause();
  (yyval.update_t)->column = (yyvsp[-2].sval);
  (yyval.update_t)->value = (yyvsp[0].expr);
}
#line 4136 "bison_parser.cpp"
    break;

  case 116: /* select_statement: opt_with_clause select_with_paren  */
#line 756 "bison_parser.y"
                                                     {
  (yyval.select_stmt) = (yyvsp[0].select_stmt);
  (yyval.select_stmt)->withDescriptions = (yyvsp[-1].with_description_vec);
}
#line 4145 "bison_parser.cpp"
    break;

  case 117: /* select_statement: opt_with_clause select_no_paren  */
#line 760 "bison_parser.y"
                                  {
  (yyval.select_stmt) = (yyvsp[0].select_stmt);
  (yyval.select_stmt)->withDescriptions = (yyvsp[-1].with_description_vec);
}
#line 4154 "bison_parser.cpp"
    break;

  case 118: /* select_statement: opt_with_clause select_with_paren set_operator select_within_set_operation opt_order opt_limit  */
#line 764 "bison_parser.y"
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
#line 4170 "bison_parser.cpp"
    break;

  case 121: /* select_within_set_operation_no_parentheses: select_clause  */
#line 778 "bison_parser.y"
                                                           { (yyval.select_stmt) = (yyvsp[0].select_stmt); }
#line 4176 "bison_parser.cpp"
    break;

  case 122: /* select_within_set_operation_no_parentheses: select_clause set_operator select_within_set_operation  */
#line 779 "bison_parser.y"
                                                         {
  (yyval.select_stmt) = (yyvsp[-2].select_stmt);
  if ((yyval.select_stmt)->setOperations == nullptr) {
    (yyval.select_stmt)->setOperations = new std::vector<SetOperation*>();
  }
  (yyval.select_stmt)->setOperations->push_back((yyvsp[-1].set_operator_t));
  (yyval.select_stmt)->setOperations->back()->nestedSelectStatement = (yyvsp[0].select_stmt);
}
#line 4189 "bison_parser.cpp"
    break;

  case 123: /* select_with_paren: '(' select_no_paren ')'  */
#line 788 "bison_parser.y"
                                            { (yyval.select_stmt) = (yyvsp[-1].select_stmt); }
#line 4195 "bison_parser.cpp"
    break;

  case 124: /* select_with_paren: '(' select_with_paren ')'  */
#line 789 "bison_parser.y"
                            { (yyval.select_stmt) = (yyvsp[-1].select_stmt); }
#line 4201 "bison_parser.cpp"
    break;

  case 125: /* select_no_paren: select_clause opt_order opt_limit opt_locking_clause  */
#line 791 "bison_parser.y"
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
#line 4220 "bison_parser.cpp"
    break;

  case 126: /* select_no_paren: select_clause set_operator select_within_set_operation opt_order opt_limit opt_locking_clause  */
#line 805 "bison_parser.y"
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
#line 4236 "bison_parser.cpp"
    break;

  case 127: /* set_operator: set_type opt_all  */
#line 817 "bison_parser.y"
                                {
  (yyval.set_operator_t) = (yyvsp[-1].set_operator_t);
  (yyval.set_operator_t)->isAll = (yyvsp[0].bval);
}
#line 4245 "bison_parser.cpp"
    break;

  case 128: /* set_type: UNION  */
#line 822 "bison_parser.y"
                 {
  (yyval.set_operator_t) = new SetOperation();
  (yyval.set_operator_t)->setType = SetType::kSetUnion;
}
#line 4254 "bison_parser.cpp"
    break;

  case 129: /* set_type: INTERSECT  */
#line 826 "bison_parser.y"
            {
  (yyval.set_operator_t) = new SetOperation();
  (yyval.set_operator_t)->setType = SetType::kSetIntersect;
}
#line 4263 "bison_parser.cpp"
    break;

  case 130: /* set_type: EXCEPT  */
#line 830 "bison_parser.y"
         {
  (yyval.set_operator_t) = new SetOperation();
  (yyval.set_operator_t)->setType = SetType::kSetExcept;
}
#line 4272 "bison_parser.cpp"
    break;

  case 131: /* opt_all: ALL  */
#line 835 "bison_parser.y"
              { (yyval.bval) = true; }
#line 4278 "bison_parser.cpp"
    break;

  case 132: /* opt_all: %empty  */
#line 836 "bison_parser.y"
              { (yyval.bval) = false; }
#line 4284 "bison_parser.cpp"
    break;

  case 133: /* select_clause: SELECT opt_top opt_distinct select_list opt_from_clause opt_where opt_group  */
#line 838 "bison_parser.y"
                                                                                            {
  (yyval.select_stmt) = new SelectStatement();
  (yyval.select_stmt)->limit = (yyvsp[-5].limit);
  (yyval.select_stmt)->selectDistinct = (yyvsp[-4].bval);
  (yyval.select_stmt)->selectList = (yyvsp[-3].expr_vec);
  (yyval.select_stmt)->fromTable = (yyvsp[-2].table);
  (yyval.select_stmt)->whereClause = (yyvsp[-1].expr);
  (yyval.select_stmt)->groupBy = (yyvsp[0].group_t);
}
#line 4298 "bison_parser.cpp"
    break;

  case 134: /* opt_distinct: DISTINCT  */
#line 848 "bison_parser.y"
                        { (yyval.bval) = true; }
#line 4304 "bison_parser.cpp"
    break;

  case 135: /* opt_distinct: %empty  */
#line 849 "bison_parser.y"
              { (yyval.bval) = false; }
#line 4310 "bison_parser.cpp"
    break;

  case 137: /* opt_from_clause: from_clause  */
#line 853 "bison_parser.y"
                              { (yyval.table) = (yyvsp[0].table); }
#line 4316 "bison_parser.cpp"
    break;

  case 138: /* opt_from_clause: %empty  */
#line 854 "bison_parser.y"
              { (yyval.table) = nullptr; }
#line 4322 "bison_parser.cpp"
    break;

  case 139: /* from_clause: FROM table_ref  */
#line 856 "bison_parser.y"
                             { (yyval.table) = (yyvsp[0].table); }
#line 4328 "bison_parser.cpp"
    break;

  case 140: /* opt_where: WHERE expr  */
#line 858 "bison_parser.y"
                       { (yyval.expr) = (yyvsp[0].expr); }
#line 4334 "bison_parser.cpp"
    break;

  case 141: /* opt_where: %empty  */
#line 859 "bison_parser.y"
              { (yyval.expr) = nullptr; }
#line 4340 "bison_parser.cpp"
    break;

  case 142: /* opt_group: GROUP BY expr_list opt_having  */
#line 861 "bison_parser.y"
                                          {
  (yyval.group_t) = new GroupByDescription();
  (yyval.group_t)->columns = (yyvsp[-1].expr_vec);
  (yyval.group_t)->having = (yyvsp[0].expr);
}
#line 4350 "bison_parser.cpp"
    break;

  case 143: /* opt_group: %empty  */
#line 866 "bison_parser.y"
              { (yyval.group_t) = nullptr; }
#line 4356 "bison_parser.cpp"
    break;

  case 144: /* opt_having: HAVING expr  */
#line 868 "bison_parser.y"
                         { (yyval.expr) = (yyvsp[0].expr); }
#line 4362 "bison_parser.cpp"
    break;

  case 145: /* opt_having: %empty  */
#line 869 "bison_parser.y"
              { (yyval.expr) = nullptr; }
#line 4368 "bison_parser.cpp"
    break;

  case 146: /* opt_order: ORDER BY order_list  */
#line 871 "bison_parser.y"
                                { (yyval.order_vec) = (yyvsp[0].order_vec); }
#line 4374 "bison_parser.cpp"
    break;

  case 147: /* opt_order: %empty  */
#line 872 "bison_parser.y"
              { (yyval.order_vec) = nullptr; }
#line 4380 "bison_parser.cpp"
    break;

  case 148: /* order_list: order_desc  */
#line 874 "bison_parser.y"
                        {
  (yyval.order_vec) = new std::vector<OrderDescription*>();
  (yyval.order_vec)->push_back((yyvsp[0].order));
}
#line 4389 "bison_parser.cpp"
    break;

  case 149: /* order_list: order_list ',' order_desc  */
#line 878 "bison_parser.y"
                            {
  (yyvsp[-2].order_vec)->push_back((yyvsp[0].order));
  (yyval.order_vec) = (yyvsp[-2].order_vec);
}
#line 4398 "bison_parser.cpp"
    break;

  case 150: /* order_desc: expr opt_order_type  */
#line 883 "bison_parser.y"
                                 { (yyval.order) = new OrderDescription((yyvsp[0].order_type), (yyvsp[-1].expr)); }
#line 4404 "bison_parser.cpp"
    break;

  case 151: /* opt_order_type: ASC  */
#line 885 "bison_parser.y"
                     { (yyval.order_type) = kOrderAsc; }
#line 4410 "bison_parser.cpp"
    break;

  case 152: /* opt_order_type: DESC  */
#line 886 "bison_parser.y"
       { (yyval.order_type) = kOrderDesc; }
#line 4416 "bison_parser.cpp"
    break;

  case 153: /* opt_order_type: %empty  */
#line 887 "bison_parser.y"
              { (yyval.order_type) = kOrderAsc; }
#line 4422 "bison_parser.cpp"
    break;

  case 154: /* opt_top: TOP int_literal  */
#line 891 "bison_parser.y"
                          { (yyval.limit) = new LimitDescription((yyvsp[0].expr), nullptr); }
#line 4428 "bison_parser.cpp"
    break;

  case 155: /* opt_top: %empty  */
#line 892 "bison_parser.y"
              { (yyval.limit) = nullptr; }
#line 4434 "bison_parser.cpp"
    break;

  case 156: /* opt_limit: LIMIT expr  */
#line 894 "bison_parser.y"
                       { (yyval.limit) = new LimitDescription((yyvsp[0].expr), nullptr); }
#line 4440 "bison_parser.cpp"
    break;

  case 157: /* opt_limit: OFFSET expr  */
#line 895 "bison_parser.y"
              { (yyval.limit) = new LimitDescription(nullptr, (yyvsp[0].expr)); }
#line 4446 "bison_parser.cpp"
    break;

  case 158: /* opt_limit: LIMIT expr OFFSET expr  */
#line 896 "bison_parser.y"
                         { (yyval.limit) = new LimitDescription((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4452 "bison_parser.cpp"
    break;

  case 159: /* opt_limit: LIMIT ALL  */
#line 897 "bison_parser.y"
            { (yyval.limit) = new LimitDescription(nullptr, nullptr); }
#line 4458 "bison_parser.cpp"
    break;

  case 160: /* opt_limit: LIMIT ALL OFFSET expr  */
#line 898 "bison_parser.y"
                        { (yyval.limit) = new LimitDescription(nullptr, (yyvsp[0].expr)); }
#line 4464 "bison_parser.cpp"
    break;

  case 161: /* opt_limit: %empty  */
#line 899 "bison_parser.y"
              { (yyval.limit) = nullptr; }
#line 4470 "bison_parser.cpp"
    break;

  case 162: /* expr_list: expr_alias  */
#line 904 "bison_parser.y"
                       {
  (yyval.expr_vec) = new std::vector<Expr*>();
  (yyval.expr_vec)->push_back((yyvsp[0].expr));
}
#line 4479 "bison_parser.cpp"
    break;

  case 163: /* expr_list: expr_list ',' expr_alias  */
#line 908 "bison_parser.y"
                           {
  (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr));
  (yyval.expr_vec) = (yyvsp[-2].expr_vec);
}
#line 4488 "bison_parser.cpp"
    break;

  case 164: /* opt_literal_list: literal_list  */
#line 913 "bison_parser.y"
                                { (yyval.expr_vec) = (yyvsp[0].expr_vec); }
#line 4494 "bison_parser.cpp"
    break;

  case 165: /* opt_literal_list: %empty  */
#line 914 "bison_parser.y"
              { (yyval.expr_vec) = nullptr; }
#line 4500 "bison_parser.cpp"
    break;

  case 166: /* list_of_list: list_item  */
#line 916 "bison_parser.y"
                         {
  (yyval.list_vec) = new std::vector<ValueList*>();
  (yyval.list_vec)->push_back((yyvsp[0].expr_vec));
}
#line 4509 "bison_parser.cpp"
    break;

  case 167: /* list_of_list: list_of_list ',' list_item  */
#line 920 "bison_parser.y"
                             {
  (yyvsp[-2].list_vec)->push_back((yyvsp[0].expr_vec));
  (yyval.list_vec) = (yyvsp[-2].list_vec);
}
#line 4518 "bison_parser.cpp"
    break;

  case 168: /* list_item: '(' literal_list ')'  */
#line 925 "bison_parser.y"
                                 {
  (yyval.expr_vec) = (yyvsp[-1].expr_vec);
}
#line 4526 "bison_parser.cpp"
    break;

  case 169: /* literal_list: literal  */
#line 929 "bison_parser.y"
                       {
  (yyval.expr_vec) = new std::vector<Expr*>();
  (yyval.expr_vec)->push_back((yyvsp[0].expr));
}
#line 4535 "bison_parser.cpp"
    break;

  case 170: /* literal_list: literal_list ',' literal  */
#line 933 "bison_parser.y"
                           {
  (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr));
  (yyval.expr_vec) = (yyvsp[-2].expr_vec);
}
#line 4544 "bison_parser.cpp"
    break;

  case 171: /* expr_alias: expr opt_alias  */
#line 938 "bison_parser.y"
                            {
  (yyval.expr) = (yyvsp[-1].expr);
  if ((yyvsp[0].alias_t)) {
    (yyval.expr)->alias = strdup((yyvsp[0].alias_t)->name);
    delete (yyvsp[0].alias_t);
  }
}
#line 4556 "bison_parser.cpp"
    break;

  case 177: /* operand: '(' expr ')'  */
#line 948 "bison_parser.y"
                       { (yyval.expr) = (yyvsp[-1].expr); }
#line 4562 "bison_parser.cpp"
    break;

  case 187: /* operand: '(' select_no_paren ')'  */
#line 950 "bison_parser.y"
                                         {
  (yyval.expr) = Expr::makeSelect((yyvsp[-1].select_stmt));
}
#line 4570 "bison_parser.cpp"
    break;

  case 190: /* unary_expr: '-' operand  */
#line 956 "bison_parser.y"
                         { (yyval.expr) = Expr::makeOpUnary(kOpUnaryMinus, (yyvsp[0].expr)); }
#line 4576 "bison_parser.cpp"
    break;

  case 191: /* unary_expr: NOT operand  */
#line 957 "bison_parser.y"
              { (yyval.expr) = Expr::makeOpUnary(kOpNot, (yyvsp[0].expr)); }
#line 4582 "bison_parser.cpp"
    break;

  case 192: /* unary_expr: operand ISNULL  */
#line 958 "bison_parser.y"
                 { (yyval.expr) = Expr::makeOpUnary(kOpIsNull, (yyvsp[-1].expr)); }
#line 4588 "bison_parser.cpp"
    break;

  case 193: /* unary_expr: operand IS NULL  */
#line 959 "bison_parser.y"
                  { (yyval.expr) = Expr::makeOpUnary(kOpIsNull, (yyvsp[-2].expr)); }
#line 4594 "bison_parser.cpp"
    break;

  case 194: /* unary_expr: operand IS NOT NULL  */
#line 960 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeOpUnary(kOpIsNull, (yyvsp[-3].expr))); }
#line 4600 "bison_parser.cpp"
    break;

  case 196: /* binary_expr: operand '-' operand  */
#line 962 "bison_parser.y"
                                              { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpMinus, (yyvsp[0].expr)); }
#line 4606 "bison_parser.cpp"
    break;

  case 197: /* binary_expr: operand '+' operand  */
#line 963 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpPlus, (yyvsp[0].expr)); }
#line 4612 "bison_parser.cpp"
    break;

  case 198: /* binary_expr: operand '/' operand  */
#line 964 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpSlash, (yyvsp[0].expr)); }
#line 4618 "bison_parser.cpp"
    break;

  case 199: /* binary_expr: operand '*' operand  */
#line 965 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpAsterisk, (yyvsp[0].expr)); }
#line 4624 "bison_parser.cpp"
    break;

  case 200: /* binary_expr: operand '%' operand  */
#line 966 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpPercentage, (yyvsp[0].expr)); }
#line 4630 "bison_parser.cpp"
    break;

  case 201: /* binary_expr: operand '^' operand  */
#line 967 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpCaret, (yyvsp[0].expr)); }
#line 4636 "bison_parser.cpp"
    break;

  case 202: /* binary_expr: operand LIKE operand  */
#line 968 "bison_parser.y"
                       { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpLike, (yyvsp[0].expr)); }
#line 4642 "bison_parser.cpp"
    break;

  case 203: /* binary_expr: operand NOT LIKE operand  */
#line 969 "bison_parser.y"
                           { (yyval.expr) = Expr::makeOpBinary((yyvsp[-3].expr), kOpNotLike, (yyvsp[0].expr)); }
#line 4648 "bison_parser.cpp"
    break;

  case 204: /* binary_expr: operand ILIKE operand  */
#line 970 "bison_parser.y"
                        { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpILike, (yyvsp[0].expr)); }
#line 4654 "bison_parser.cpp"
    break;

  case 205: /* binary_expr: operand CONCAT operand  */
#line 971 "bison_parser.y"
                         { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpConcat, (yyvsp[0].expr)); }
#line 4660 "bison_parser.cpp"
    break;

  case 206: /* logic_expr: expr AND expr  */
#line 973 "bison_parser.y"
                           { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpAnd, (yyvsp[0].expr)); }
#line 4666 "bison_parser.cpp"
    break;

  case 207: /* logic_expr: expr OR expr  */
#line 974 "bison_parser.y"
               { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpOr, (yyvsp[0].expr)); }
#line 4672 "bison_parser.cpp"
    break;

  case 208: /* in_expr: operand IN '(' expr_list ')'  */
#line 976 "bison_parser.y"
                                       { (yyval.expr) = Expr::makeInOperator((yyvsp[-4].expr), (yyvsp[-1].expr_vec)); }
#line 4678 "bison_parser.cpp"
    break;

  case 209: /* in_expr: operand NOT IN '(' expr_list ')'  */
#line 977 "bison_parser.y"
                                   { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeInOperator((yyvsp[-5].expr), (yyvsp[-1].expr_vec))); }
#line 4684 "bison_parser.cpp"
    break;

  case 210: /* in_expr: operand IN '(' select_no_paren ')'  */
#line 978 "bison_parser.y"
                                     { (yyval.expr) = Expr::makeInOperator((yyvsp[-4].expr), (yyvsp[-1].select_stmt)); }
#line 4690 "bison_parser.cpp"
    break;

  case 211: /* in_expr: operand NOT IN '(' select_no_paren ')'  */
#line 979 "bison_parser.y"
                                         { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeInOperator((yyvsp[-5].expr), (yyvsp[-1].select_stmt))); }
#line 4696 "bison_parser.cpp"
    break;

  case 212: /* case_expr: CASE expr case_list END  */
#line 983 "bison_parser.y"
                                    { (yyval.expr) = Expr::makeCase((yyvsp[-2].expr), (yyvsp[-1].expr), nullptr); }
#line 4702 "bison_parser.cpp"
    break;

  case 213: /* case_expr: CASE expr case_list ELSE expr END  */
#line 984 "bison_parser.y"
                                    { (yyval.expr) = Expr::makeCase((yyvsp[-4].expr), (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 4708 "bison_parser.cpp"
    break;

  case 214: /* case_expr: CASE case_list END  */
#line 985 "bison_parser.y"
                     { (yyval.expr) = Expr::makeCase(nullptr, (yyvsp[-1].expr), nullptr); }
#line 4714 "bison_parser.cpp"
    break;

  case 215: /* case_expr: CASE case_list ELSE expr END  */
#line 986 "bison_parser.y"
                               { (yyval.expr) = Expr::makeCase(nullptr, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 4720 "bison_parser.cpp"
    break;

  case 216: /* case_list: WHEN expr THEN expr  */
#line 988 "bison_parser.y"
                                { (yyval.expr) = Expr::makeCaseList(Expr::makeCaseListElement((yyvsp[-2].expr), (yyvsp[0].expr))); }
#line 4726 "bison_parser.cpp"
    break;

  case 217: /* case_list: case_list WHEN expr THEN expr  */
#line 989 "bison_parser.y"
                                { (yyval.expr) = Expr::caseListAppend((yyvsp[-4].expr), Expr::makeCaseListElement((yyvsp[-2].expr), (yyvsp[0].expr))); }
#line 4732 "bison_parser.cpp"
    break;

  case 218: /* exists_expr: EXISTS '(' select_no_paren ')'  */
#line 991 "bison_parser.y"
                                             { (yyval.expr) = Expr::makeExists((yyvsp[-1].select_stmt)); }
#line 4738 "bison_parser.cpp"
    break;

  case 219: /* exists_expr: NOT EXISTS '(' select_no_paren ')'  */
#line 992 "bison_parser.y"
                                     { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeExists((yyvsp[-1].select_stmt))); }
#line 4744 "bison_parser.cpp"
    break;

  case 220: /* comp_expr: operand '=' operand  */
#line 994 "bison_parser.y"
                                { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpEquals, (yyvsp[0].expr)); }
#line 4750 "bison_parser.cpp"
    break;

  case 221: /* comp_expr: operand EQUALS operand  */
#line 995 "bison_parser.y"
                         { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpEquals, (yyvsp[0].expr)); }
#line 4756 "bison_parser.cpp"
    break;

  case 222: /* comp_expr: operand NOTEQUALS operand  */
#line 996 "bison_parser.y"
                            { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpNotEquals, (yyvsp[0].expr)); }
#line 4762 "bison_parser.cpp"
    break;

  case 223: /* comp_expr: operand '<' operand  */
#line 997 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpLess, (yyvsp[0].expr)); }
#line 4768 "bison_parser.cpp"
    break;

  case 224: /* comp_expr: operand '>' operand  */
#line 998 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpGreater, (yyvsp[0].expr)); }
#line 4774 "bison_parser.cpp"
    break;

  case 225: /* comp_expr: operand LESSEQ operand  */
#line 999 "bison_parser.y"
                         { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpLessEq, (yyvsp[0].expr)); }
#line 4780 "bison_parser.cpp"
    break;

  case 226: /* comp_expr: operand GREATEREQ operand  */
#line 1000 "bison_parser.y"
                            { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpGreaterEq, (yyvsp[0].expr)); }
#line 4786 "bison_parser.cpp"
    break;

  case 227: /* function_expr: IDENTIFIER '(' ')'  */
#line 1002 "bison_parser.y"
                                   { (yyval.expr) = Expr::makeFunctionRef((yyvsp[-2].sval), new std::vector<Expr*>(), false); }
#line 4792 "bison_parser.cpp"
    break;

  case 228: /* function_expr: IDENTIFIER '(' opt_distinct expr_list ')'  */
#line 1003 "bison_parser.y"
                                            { (yyval.expr) = Expr::makeFunctionRef((yyvsp[-4].sval), (yyvsp[-1].expr_vec), (yyvsp[-2].bval)); }
#line 4798 "bison_parser.cpp"
    break;

  case 229: /* extract_expr: EXTRACT '(' datetime_field FROM expr ')'  */
#line 1005 "bison_parser.y"
                                                        { (yyval.expr) = Expr::makeExtract((yyvsp[-3].datetime_field), (yyvsp[-1].expr)); }
#line 4804 "bison_parser.cpp"
    break;

  case 230: /* cast_expr: CAST '(' expr AS column_type ')'  */
#line 1007 "bison_parser.y"
                                             { (yyval.expr) = Expr::makeCast((yyvsp[-3].expr), (yyvsp[-1].column_type_t)); }
#line 4810 "bison_parser.cpp"
    break;

  case 231: /* datetime_field: SECOND  */
#line 1009 "bison_parser.y"
                        { (yyval.datetime_field) = kDatetimeSecond; }
#line 4816 "bison_parser.cpp"
    break;

  case 232: /* datetime_field: MINUTE  */
#line 1010 "bison_parser.y"
         { (yyval.datetime_field) = kDatetimeMinute; }
#line 4822 "bison_parser.cpp"
    break;

  case 233: /* datetime_field: HOUR  */
#line 1011 "bison_parser.y"
       { (yyval.datetime_field) = kDatetimeHour; }
#line 4828 "bison_parser.cpp"
    break;

  case 234: /* datetime_field: DAY  */
#line 1012 "bison_parser.y"
      { (yyval.datetime_field) = kDatetimeDay; }
#line 4834 "bison_parser.cpp"
    break;

  case 235: /* datetime_field: MONTH  */
#line 1013 "bison_parser.y"
        { (yyval.datetime_field) = kDatetimeMonth; }
#line 4840 "bison_parser.cpp"
    break;

  case 236: /* datetime_field: YEAR  */
#line 1014 "bison_parser.y"
       { (yyval.datetime_field) = kDatetimeYear; }
#line 4846 "bison_parser.cpp"
    break;

  case 237: /* datetime_field_plural: SECONDS  */
#line 1016 "bison_parser.y"
                                { (yyval.datetime_field) = kDatetimeSecond; }
#line 4852 "bison_parser.cpp"
    break;

  case 238: /* datetime_field_plural: MINUTES  */
#line 1017 "bison_parser.y"
          { (yyval.datetime_field) = kDatetimeMinute; }
#line 4858 "bison_parser.cpp"
    break;

  case 239: /* datetime_field_plural: HOURS  */
#line 1018 "bison_parser.y"
        { (yyval.datetime_field) = kDatetimeHour; }
#line 4864 "bison_parser.cpp"
    break;

  case 240: /* datetime_field_plural: DAYS  */
#line 1019 "bison_parser.y"
       { (yyval.datetime_field) = kDatetimeDay; }
#line 4870 "bison_parser.cpp"
    break;

  case 241: /* datetime_field_plural: MONTHS  */
#line 1020 "bison_parser.y"
         { (yyval.datetime_field) = kDatetimeMonth; }
#line 4876 "bison_parser.cpp"
    break;

  case 242: /* datetime_field_plural: YEARS  */
#line 1021 "bison_parser.y"
        { (yyval.datetime_field) = kDatetimeYear; }
#line 4882 "bison_parser.cpp"
    break;

  case 245: /* array_expr: ARRAY '[' expr_list ']'  */
#line 1025 "bison_parser.y"
                                     { (yyval.expr) = Expr::makeArray((yyvsp[-1].expr_vec)); }
#line 4888 "bison_parser.cpp"
    break;

  case 246: /* array_index: operand '[' int_literal ']'  */
#line 1027 "bison_parser.y"
                                          { (yyval.expr) = Expr::makeArrayIndex((yyvsp[-3].expr), (yyvsp[-1].expr)->ival); }
#line 4894 "bison_parser.cpp"
    break;

  case 247: /* between_expr: operand BETWEEN operand AND operand  */
#line 1029 "bison_parser.y"
                                                   { (yyval.expr) = Expr::makeBetween((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4900 "bison_parser.cpp"
    break;

  case 248: /* column_name: IDENTIFIER  */
#line 1031 "bison_parser.y"
                         { (yyval.expr) = Expr::makeColumnRef((yyvsp[0].sval)); }
#line 4906 "bison_parser.cpp"
    break;

  case 249: /* column_name: IDENTIFIER '.' IDENTIFIER  */
#line 1032 "bison_parser.y"
                            { (yyval.expr) = Expr::makeColumnRef((yyvsp[-2].sval), (yyvsp[0].sval)); }
#line 4912 "bison_parser.cpp"
    break;

  case 250: /* column_name: '*'  */
#line 1033 "bison_parser.y"
      { (yyval.expr) = Expr::makeStar(); }
#line 4918 "bison_parser.cpp"
    break;

  case 251: /* column_name: IDENTIFIER '.' '*'  */
#line 1034 "bison_parser.y"
                     { (yyval.expr) = Expr::makeStar((yyvsp[-2].sval)); }
#line 4924 "bison_parser.cpp"
    break;

  case 259: /* string_literal: STRING  */
#line 1038 "bison_parser.y"
                        { (yyval.expr) = Expr::makeLiteral((yyvsp[0].sval)); }
#line 4930 "bison_parser.cpp"
    break;

  case 260: /* bool_literal: TRUE  */
#line 1040 "bison_parser.y"
                    { (yyval.expr) = Expr::makeLiteral(true); }
#line 4936 "bison_parser.cpp"
    break;

  case 261: /* bool_literal: FALSE  */
#line 1041 "bison_parser.y"
        { (yyval.expr) = Expr::makeLiteral(false); }
#line 4942 "bison_parser.cpp"
    break;

  case 262: /* num_literal: FLOATVAL  */
#line 1043 "bison_parser.y"
                       { (yyval.expr) = Expr::makeLiteral((yyvsp[0].fval)); }
#line 4948 "bison_parser.cpp"
    break;

  case 264: /* int_literal: INTVAL  */
#line 1046 "bison_parser.y"
                     { (yyval.expr) = Expr::makeLiteral((yyvsp[0].ival)); }
#line 4954 "bison_parser.cpp"
    break;

  case 265: /* null_literal: NULL  */
#line 1048 "bison_parser.y"
                    { (yyval.expr) = Expr::makeNullLiteral(); }
#line 4960 "bison_parser.cpp"
    break;

  case 266: /* date_literal: DATE STRING  */
#line 1050 "bison_parser.y"
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
#line 4975 "bison_parser.cpp"
    break;

  case 267: /* interval_literal: int_literal duration_field  */
#line 1061 "bison_parser.y"
                                              {
  (yyval.expr) = Expr::makeIntervalLiteral((yyvsp[-1].expr)->ival, (yyvsp[0].datetime_field));
  delete (yyvsp[-1].expr);
}
#line 4984 "bison_parser.cpp"
    break;

  case 268: /* interval_literal: INTERVAL STRING datetime_field  */
#line 1065 "bison_parser.y"
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
#line 5000 "bison_parser.cpp"
    break;

  case 269: /* interval_literal: INTERVAL STRING  */
#line 1076 "bison_parser.y"
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
#line 5036 "bison_parser.cpp"
    break;

  case 270: /* param_expr: '?'  */
#line 1108 "bison_parser.y"
                 {
  (yyval.expr) = Expr::makeParameter(yylloc.total_column);
  (yyval.expr)->ival2 = yyloc.param_list.size();
  yyloc.param_list.push_back((yyval.expr));
}
#line 5046 "bison_parser.cpp"
    break;

  case 272: /* table_ref: table_ref_commalist ',' table_ref_atomic  */
#line 1117 "bison_parser.y"
                                                                        {
  (yyvsp[-2].table_vec)->push_back((yyvsp[0].table));
  auto tbl = new TableRef(kTableCrossProduct);
  tbl->list = (yyvsp[-2].table_vec);
  (yyval.table) = tbl;
}
#line 5057 "bison_parser.cpp"
    break;

  case 276: /* nonjoin_table_ref_atomic: '(' select_statement ')' opt_table_alias  */
#line 1126 "bison_parser.y"
                                                                                     {
  auto tbl = new TableRef(kTableSelect);
  tbl->select = (yyvsp[-2].select_stmt);
  tbl->alias = (yyvsp[0].alias_t);
  (yyval.table) = tbl;
}
#line 5068 "bison_parser.cpp"
    break;

  case 277: /* table_ref_commalist: table_ref_atomic  */
#line 1133 "bison_parser.y"
                                       {
  (yyval.table_vec) = new std::vector<TableRef*>();
  (yyval.table_vec)->push_back((yyvsp[0].table));
}
#line 5077 "bison_parser.cpp"
    break;

  case 278: /* table_ref_commalist: table_ref_commalist ',' table_ref_atomic  */
#line 1137 "bison_parser.y"
                                           {
  (yyvsp[-2].table_vec)->push_back((yyvsp[0].table));
  (yyval.table_vec) = (yyvsp[-2].table_vec);
}
#line 5086 "bison_parser.cpp"
    break;

  case 279: /* table_ref_name: table_name opt_table_alias  */
#line 1142 "bison_parser.y"
                                            {
  auto tbl = new TableRef(kTableName);
  tbl->schema = (yyvsp[-1].table_name).schema;
  tbl->name = (yyvsp[-1].table_name).name;
  tbl->alias = (yyvsp[0].alias_t);
  (yyval.table) = tbl;
}
#line 5098 "bison_parser.cpp"
    break;

  case 280: /* table_ref_name_no_alias: table_name  */
#line 1150 "bison_parser.y"
                                     {
  (yyval.table) = new TableRef(kTableName);
  (yyval.table)->schema = (yyvsp[0].table_name).schema;
  (yyval.table)->name = (yyvsp[0].table_name).name;
}
#line 5108 "bison_parser.cpp"
    break;

  case 281: /* table_name: IDENTIFIER  */
#line 1156 "bison_parser.y"
                        {
  (yyval.table_name).schema = nullptr;
  (yyval.table_name).name = (yyvsp[0].sval);
}
#line 5117 "bison_parser.cpp"
    break;

  case 282: /* table_name: IDENTIFIER '.' IDENTIFIER  */
#line 1160 "bison_parser.y"
                            {
  (yyval.table_name).schema = (yyvsp[-2].sval);
  (yyval.table_name).name = (yyvsp[0].sval);
}
#line 5126 "bison_parser.cpp"
    break;

  case 283: /* opt_index_name: IDENTIFIER  */
#line 1165 "bison_parser.y"
                            { (yyval.sval) = (yyvsp[0].sval); }
#line 5132 "bison_parser.cpp"
    break;

  case 284: /* opt_index_name: %empty  */
#line 1166 "bison_parser.y"
              { (yyval.sval) = nullptr; }
#line 5138 "bison_parser.cpp"
    break;

  case 286: /* table_alias: AS IDENTIFIER '(' ident_commalist ')'  */
#line 1168 "bison_parser.y"
                                                            { (yyval.alias_t) = new Alias((yyvsp[-3].sval), (yyvsp[-1].str_vec)); }
#line 5144 "bison_parser.cpp"
    break;

  case 288: /* opt_table_alias: %empty  */
#line 1170 "bison_parser.y"
                                            { (yyval.alias_t) = nullptr; }
#line 5150 "bison_parser.cpp"
    break;

  case 289: /* alias: AS IDENTIFIER  */
#line 1172 "bison_parser.y"
                      { (yyval.alias_t) = new Alias((yyvsp[0].sval)); }
#line 5156 "bison_parser.cpp"
    break;

  case 290: /* alias: IDENTIFIER  */
#line 1173 "bison_parser.y"
             { (yyval.alias_t) = new Alias((yyvsp[0].sval)); }
#line 5162 "bison_parser.cpp"
    break;

  case 292: /* opt_alias: %empty  */
#line 1175 "bison_parser.y"
                                { (yyval.alias_t) = nullptr; }
#line 5168 "bison_parser.cpp"
    break;

  case 293: /* opt_locking_clause: opt_locking_clause_list  */
#line 1181 "bison_parser.y"
                                             { (yyval.locking_clause_vec) = (yyvsp[0].locking_clause_vec); }
#line 5174 "bison_parser.cpp"
    break;

  case 294: /* opt_locking_clause: %empty  */
#line 1182 "bison_parser.y"
              { (yyval.locking_clause_vec) = nullptr; }
#line 5180 "bison_parser.cpp"
    break;

  case 295: /* opt_locking_clause_list: locking_clause  */
#line 1184 "bison_parser.y"
                                         {
  (yyval.locking_clause_vec) = new std::vector<LockingClause*>();
  (yyval.locking_clause_vec)->push_back((yyvsp[0].locking_t));
}
#line 5189 "bison_parser.cpp"
    break;

  case 296: /* opt_locking_clause_list: opt_locking_clause_list locking_clause  */
#line 1188 "bison_parser.y"
                                         {
  (yyvsp[-1].locking_clause_vec)->push_back((yyvsp[0].locking_t));
  (yyval.locking_clause_vec) = (yyvsp[-1].locking_clause_vec);
}
#line 5198 "bison_parser.cpp"
    break;

  case 297: /* locking_clause: FOR row_lock_mode opt_row_lock_policy  */
#line 1193 "bison_parser.y"
                                                       {
  (yyval.locking_t) = new LockingClause();
  (yyval.locking_t)->rowLockMode = (yyvsp[-1].lock_mode_t);
  (yyval.locking_t)->rowLockWaitPolicy = (yyvsp[0].lock_wait_policy_t);
  (yyval.locking_t)->tables = nullptr;
}
#line 5209 "bison_parser.cpp"
    break;

  case 298: /* locking_clause: FOR row_lock_mode OF ident_commalist opt_row_lock_policy  */
#line 1199 "bison_parser.y"
                                                           {
  (yyval.locking_t) = new LockingClause();
  (yyval.locking_t)->rowLockMode = (yyvsp[-3].lock_mode_t);
  (yyval.locking_t)->tables = (yyvsp[-1].str_vec);
  (yyval.locking_t)->rowLockWaitPolicy = (yyvsp[0].lock_wait_policy_t);
}
#line 5220 "bison_parser.cpp"
    break;

  case 299: /* row_lock_mode: UPDATE  */
#line 1206 "bison_parser.y"
                       { (yyval.lock_mode_t) = RowLockMode::ForUpdate; }
#line 5226 "bison_parser.cpp"
    break;

  case 300: /* row_lock_mode: NO KEY UPDATE  */
#line 1207 "bison_parser.y"
                { (yyval.lock_mode_t) = RowLockMode::ForNoKeyUpdate; }
#line 5232 "bison_parser.cpp"
    break;

  case 301: /* row_lock_mode: SHARE  */
#line 1208 "bison_parser.y"
        { (yyval.lock_mode_t) = RowLockMode::ForShare; }
#line 5238 "bison_parser.cpp"
    break;

  case 302: /* row_lock_mode: KEY SHARE  */
#line 1209 "bison_parser.y"
            { (yyval.lock_mode_t) = RowLockMode::ForKeyShare; }
#line 5244 "bison_parser.cpp"
    break;

  case 303: /* opt_row_lock_policy: SKIP LOCKED  */
#line 1211 "bison_parser.y"
                                  { (yyval.lock_wait_policy_t) = RowLockWaitPolicy::SkipLocked; }
#line 5250 "bison_parser.cpp"
    break;

  case 304: /* opt_row_lock_policy: NOWAIT  */
#line 1212 "bison_parser.y"
         { (yyval.lock_wait_policy_t) = RowLockWaitPolicy::NoWait; }
#line 5256 "bison_parser.cpp"
    break;

  case 305: /* opt_row_lock_policy: %empty  */
#line 1213 "bison_parser.y"
              { (yyval.lock_wait_policy_t) = RowLockWaitPolicy::None; }
#line 5262 "bison_parser.cpp"
    break;

  case 307: /* opt_with_clause: %empty  */
#line 1219 "bison_parser.y"
                                            { (yyval.with_description_vec) = nullptr; }
#line 5268 "bison_parser.cpp"
    break;

  case 308: /* with_clause: WITH with_description_list  */
#line 1221 "bison_parser.y"
                                         { (yyval.with_description_vec) = (yyvsp[0].with_description_vec); }
#line 5274 "bison_parser.cpp"
    break;

  case 309: /* with_description_list: with_description  */
#line 1223 "bison_parser.y"
                                         {
  (yyval.with_description_vec) = new std::vector<WithDescription*>();
  (yyval.with_description_vec)->push_back((yyvsp[0].with_description_t));
}
#line 5283 "bison_parser.cpp"
    break;

  case 310: /* with_description_list: with_description_list ',' with_description  */
#line 1227 "bison_parser.y"
                                             {
  (yyvsp[-2].with_description_vec)->push_back((yyvsp[0].with_description_t));
  (yyval.with_description_vec) = (yyvsp[-2].with_description_vec);
}
#line 5292 "bison_parser.cpp"
    break;

  case 311: /* with_description: IDENTIFIER AS select_with_paren  */
#line 1232 "bison_parser.y"
                                                   {
  (yyval.with_description_t) = new WithDescription();
  (yyval.with_description_t)->alias = (yyvsp[-2].sval);
  (yyval.with_description_t)->select = (yyvsp[0].select_stmt);
}
#line 5302 "bison_parser.cpp"
    break;

  case 312: /* join_clause: table_ref_atomic NATURAL JOIN nonjoin_table_ref_atomic  */
#line 1242 "bison_parser.y"
                                                                     {
  (yyval.table) = new TableRef(kTableJoin);
  (yyval.table)->join = new JoinDefinition();
  (yyval.table)->join->type = kJoinNatural;
  (yyval.table)->join->left = (yyvsp[-3].table);
  (yyval.table)->join->right = (yyvsp[0].table);
}
#line 5314 "bison_parser.cpp"
    break;

  case 313: /* join_clause: table_ref_atomic opt_join_type JOIN table_ref_atomic ON join_condition  */
#line 1249 "bison_parser.y"
                                                                         {
  (yyval.table) = new TableRef(kTableJoin);
  (yyval.table)->join = new JoinDefinition();
  (yyval.table)->join->type = (JoinType)(yyvsp[-4].join_type);
  (yyval.table)->join->left = (yyvsp[-5].table);
  (yyval.table)->join->right = (yyvsp[-2].table);
  (yyval.table)->join->condition = (yyvsp[0].expr);
}
#line 5327 "bison_parser.cpp"
    break;

  case 314: /* join_clause: table_ref_atomic opt_join_type JOIN table_ref_atomic USING '(' column_name ')'  */
#line 1257 "bison_parser.y"
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
#line 5347 "bison_parser.cpp"
    break;

  case 315: /* opt_join_type: INNER  */
#line 1273 "bison_parser.y"
                      { (yyval.join_type) = kJoinInner; }
#line 5353 "bison_parser.cpp"
    break;

  case 316: /* opt_join_type: LEFT OUTER  */
#line 1274 "bison_parser.y"
             { (yyval.join_type) = kJoinLeft; }
#line 5359 "bison_parser.cpp"
    break;

  case 317: /* opt_join_type: LEFT  */
#line 1275 "bison_parser.y"
       { (yyval.join_type) = kJoinLeft; }
#line 5365 "bison_parser.cpp"
    break;

  case 318: /* opt_join_type: RIGHT OUTER  */
#line 1276 "bison_parser.y"
              { (yyval.join_type) = kJoinRight; }
#line 5371 "bison_parser.cpp"
    break;

  case 319: /* opt_join_type: RIGHT  */
#line 1277 "bison_parser.y"
        { (yyval.join_type) = kJoinRight; }
#line 5377 "bison_parser.cpp"
    break;

  case 320: /* opt_join_type: FULL OUTER  */
#line 1278 "bison_parser.y"
             { (yyval.join_type) = kJoinFull; }
#line 5383 "bison_parser.cpp"
    break;

  case 321: /* opt_join_type: OUTER  */
#line 1279 "bison_parser.y"
        { (yyval.join_type) = kJoinFull; }
#line 5389 "bison_parser.cpp"
    break;

  case 322: /* opt_join_type: FULL  */
#line 1280 "bison_parser.y"
       { (yyval.join_type) = kJoinFull; }
#line 5395 "bison_parser.cpp"
    break;

  case 323: /* opt_join_type: CROSS  */
#line 1281 "bison_parser.y"
        { (yyval.join_type) = kJoinCross; }
#line 5401 "bison_parser.cpp"
    break;

  case 324: /* opt_join_type: %empty  */
#line 1282 "bison_parser.y"
                       { (yyval.join_type) = kJoinInner; }
#line 5407 "bison_parser.cpp"
    break;

  case 328: /* ident_commalist: IDENTIFIER  */
#line 1293 "bison_parser.y"
                             {
  (yyval.str_vec) = new std::vector<char*>();
  (yyval.str_vec)->push_back((yyvsp[0].sval));
}
#line 5416 "bison_parser.cpp"
    break;

  case 329: /* ident_commalist: ident_commalist ',' IDENTIFIER  */
#line 1297 "bison_parser.y"
                                 {
  (yyvsp[-2].str_vec)->push_back((yyvsp[0].sval));
  (yyval.str_vec) = (yyvsp[-2].str_vec);
}
#line 5425 "bison_parser.cpp"
    break;


#line 5429 "bison_parser.cpp"

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

#line 1303 "bison_parser.y"

    // clang-format on
    /*********************************
 ** Section 4: Additional C code
 *********************************/

    /* empty */
