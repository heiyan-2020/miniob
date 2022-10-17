/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

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

#line 107 "bison_parser.cpp"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_HSQL_BISON_PARSER_H_INCLUDED
# define YY_HSQL_BISON_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef HSQL_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define HSQL_DEBUG 1
#  else
#   define HSQL_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define HSQL_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined HSQL_DEBUG */
#if HSQL_DEBUG
extern int hsql_debug;
#endif
/* "%code requires" blocks.  */
#line 38 "bison_parser.y"

  // clang-format on
  // %code requires block

#include "../SQLParserResult.h"
#include "../sql/statements.h"
#include "parser_typedef.h"

// Auto update column and line number
#define YY_USER_ACTION                        \
  yylloc->first_line = yylloc->last_line;     \
  yylloc->first_column = yylloc->last_column; \
  for (int i = 0; yytext[i] != '\0'; i++) {   \
    yylloc->total_column++;                   \
    yylloc->string_length++;                  \
    if (yytext[i] == '\n') {                  \
      yylloc->last_line++;                    \
      yylloc->last_column = 0;                \
    } else {                                  \
      yylloc->last_column++;                  \
    }                                         \
  }

#line 182 "bison_parser.cpp"

/* Token type.  */
#ifndef HSQL_TOKENTYPE
# define HSQL_TOKENTYPE
  enum hsql_tokentype
  {
    SQL_IDENTIFIER = 258,
    SQL_STRING = 259,
    SQL_FLOATVAL = 260,
    SQL_INTVAL = 261,
    SQL_DEALLOCATE = 262,
    SQL_PARAMETERS = 263,
    SQL_INTERSECT = 264,
    SQL_TEMPORARY = 265,
    SQL_TIMESTAMP = 266,
    SQL_DISTINCT = 267,
    SQL_NVARCHAR = 268,
    SQL_RESTRICT = 269,
    SQL_TRUNCATE = 270,
    SQL_ANALYZE = 271,
    SQL_BETWEEN = 272,
    SQL_CASCADE = 273,
    SQL_COLUMNS = 274,
    SQL_CONTROL = 275,
    SQL_DEFAULT = 276,
    SQL_EXECUTE = 277,
    SQL_EXPLAIN = 278,
    SQL_INTEGER = 279,
    SQL_NATURAL = 280,
    SQL_PREPARE = 281,
    SQL_PRIMARY = 282,
    SQL_SCHEMAS = 283,
    SQL_CHARACTER_VARYING = 284,
    SQL_REAL = 285,
    SQL_DECIMAL = 286,
    SQL_SMALLINT = 287,
    SQL_BIGINT = 288,
    SQL_SPATIAL = 289,
    SQL_VARCHAR = 290,
    SQL_VIRTUAL = 291,
    SQL_DESCRIBE = 292,
    SQL_BEFORE = 293,
    SQL_COLUMN = 294,
    SQL_CREATE = 295,
    SQL_DELETE = 296,
    SQL_DIRECT = 297,
    SQL_DOUBLE = 298,
    SQL_ESCAPE = 299,
    SQL_EXCEPT = 300,
    SQL_EXISTS = 301,
    SQL_EXTRACT = 302,
    SQL_CAST = 303,
    SQL_FORMAT = 304,
    SQL_GLOBAL = 305,
    SQL_HAVING = 306,
    SQL_IMPORT = 307,
    SQL_INSERT = 308,
    SQL_ISNULL = 309,
    SQL_OFFSET = 310,
    SQL_RENAME = 311,
    SQL_SCHEMA = 312,
    SQL_SELECT = 313,
    SQL_SORTED = 314,
    SQL_TABLES = 315,
    SQL_UNIQUE = 316,
    SQL_UNLOAD = 317,
    SQL_UPDATE = 318,
    SQL_VALUES = 319,
    SQL_AFTER = 320,
    SQL_ALTER = 321,
    SQL_CROSS = 322,
    SQL_DELTA = 323,
    SQL_FLOAT = 324,
    SQL_GROUP = 325,
    SQL_INDEX = 326,
    SQL_INNER = 327,
    SQL_LIMIT = 328,
    SQL_LOCAL = 329,
    SQL_MERGE = 330,
    SQL_MINUS = 331,
    SQL_ORDER = 332,
    SQL_OUTER = 333,
    SQL_RIGHT = 334,
    SQL_TABLE = 335,
    SQL_UNION = 336,
    SQL_USING = 337,
    SQL_WHERE = 338,
    SQL_CALL = 339,
    SQL_CASE = 340,
    SQL_CHAR = 341,
    SQL_COPY = 342,
    SQL_DATE = 343,
    SQL_DATETIME = 344,
    SQL_DESC = 345,
    SQL_DROP = 346,
    SQL_ELSE = 347,
    SQL_FILE = 348,
    SQL_FROM = 349,
    SQL_FULL = 350,
    SQL_HASH = 351,
    SQL_HINT = 352,
    SQL_INTO = 353,
    SQL_JOIN = 354,
    SQL_LEFT = 355,
    SQL_LIKE = 356,
    SQL_LOAD = 357,
    SQL_LONG = 358,
    SQL_NULL = 359,
    SQL_PLAN = 360,
    SQL_SHOW = 361,
    SQL_TEXT = 362,
    SQL_THEN = 363,
    SQL_TIME = 364,
    SQL_VIEW = 365,
    SQL_WHEN = 366,
    SQL_WITH = 367,
    SQL_ADD = 368,
    SQL_ALL = 369,
    SQL_AND = 370,
    SQL_ASC = 371,
    SQL_END = 372,
    SQL_FOR = 373,
    SQL_INT = 374,
    SQL_KEY = 375,
    SQL_NOT = 376,
    SQL_OFF = 377,
    SQL_SET = 378,
    SQL_TOP = 379,
    SQL_AS = 380,
    SQL_BY = 381,
    SQL_IF = 382,
    SQL_IN = 383,
    SQL_IS = 384,
    SQL_OF = 385,
    SQL_ON = 386,
    SQL_OR = 387,
    SQL_TO = 388,
    SQL_NO = 389,
    SQL_ARRAY = 390,
    SQL_CONCAT = 391,
    SQL_ILIKE = 392,
    SQL_SECOND = 393,
    SQL_MINUTE = 394,
    SQL_HOUR = 395,
    SQL_DAY = 396,
    SQL_MONTH = 397,
    SQL_YEAR = 398,
    SQL_SECONDS = 399,
    SQL_MINUTES = 400,
    SQL_HOURS = 401,
    SQL_DAYS = 402,
    SQL_MONTHS = 403,
    SQL_YEARS = 404,
    SQL_INTERVAL = 405,
    SQL_TRUE = 406,
    SQL_FALSE = 407,
    SQL_BOOLEAN = 408,
    SQL_TRANSACTION = 409,
    SQL_BEGIN = 410,
    SQL_COMMIT = 411,
    SQL_ROLLBACK = 412,
    SQL_NOWAIT = 413,
    SQL_SKIP = 414,
    SQL_LOCKED = 415,
    SQL_SHARE = 416,
    SQL_HELP = 417,
    SQL_SYNC = 418,
    SQL_NULLABLE = 419,
    SQL_EQUALS = 420,
    SQL_NOTEQUALS = 421,
    SQL_LESS = 422,
    SQL_GREATER = 423,
    SQL_LESSEQ = 424,
    SQL_GREATEREQ = 425,
    SQL_NOTNULL = 426,
    SQL_UMINUS = 427
  };
#endif

/* Value type.  */
#if ! defined HSQL_STYPE && ! defined HSQL_STYPE_IS_DECLARED
union HSQL_STYPE
{
#line 98 "bison_parser.y"

  // clang-format on
  bool bval;
  char* sval;
  double fval;
  int64_t ival;
  uintmax_t uval;

  // statements
  hsql::AlterStatement* alter_stmt;
  hsql::CreateStatement* create_stmt;
  hsql::DeleteStatement* delete_stmt;
  hsql::DropStatement* drop_stmt;
  hsql::ExecuteStatement* exec_stmt;
  hsql::ExportStatement* export_stmt;
  hsql::ImportStatement* import_stmt;
  hsql::InsertStatement* insert_stmt;
  hsql::PrepareStatement* prep_stmt;
  hsql::SelectStatement* select_stmt;
  hsql::ShowStatement* show_stmt;
  hsql::SQLStatement* statement;
  hsql::TransactionStatement* transaction_stmt;
  hsql::OtherStatement* other_stmt;
  hsql::UpdateStatement* update_stmt;

  hsql::Alias* alias_t;
  hsql::AlterAction* alter_action_t;
  hsql::ColumnDefinition* column_t;
  hsql::ColumnType column_type_t;
  hsql::ConstraintType column_constraint_t;
  hsql::DatetimeField datetime_field;
  hsql::DropColumnAction* drop_action_t;
  hsql::Expr* expr;
  hsql::GroupByDescription* group_t;
  hsql::ImportType import_type_t;
  hsql::JoinType join_type;
  hsql::LimitDescription* limit;
  hsql::OrderDescription* order;
  hsql::OrderType order_type;
  hsql::SetOperation* set_operator_t;
  hsql::TableConstraint* table_constraint_t;
  hsql::TableElement* table_element_t;
  hsql::TableName table_name;
  hsql::TableRef* table;
  hsql::UpdateClause* update_t;
  hsql::WithDescription* with_description_t;
  hsql::LockingClause* locking_t;

  std::vector<char*>* str_vec;
  std::unordered_set<hsql::ConstraintType>* column_constraint_set;
  std::vector<hsql::Expr*>* expr_vec;
  std::vector<std::vector<hsql::Expr*>*>* list_vec;
  std::vector<hsql::OrderDescription*>* order_vec;
  std::vector<hsql::SQLStatement*>* stmt_vec;
  std::vector<hsql::TableElement*>* table_element_vec;
  std::vector<hsql::TableRef*>* table_vec;
  std::vector<hsql::UpdateClause*>* update_vec;
  std::vector<hsql::WithDescription*>* with_description_vec;
  std::vector<hsql::LockingClause*>* locking_clause_vec;

  std::pair<int64_t, int64_t>* ival_pair;

  hsql::RowLockMode lock_mode_t;
  hsql::RowLockWaitPolicy lock_wait_policy_t;

#line 432 "bison_parser.cpp"

};
typedef union HSQL_STYPE HSQL_STYPE;
# define HSQL_STYPE_IS_TRIVIAL 1
# define HSQL_STYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined HSQL_LTYPE && ! defined HSQL_LTYPE_IS_DECLARED
typedef struct HSQL_LTYPE HSQL_LTYPE;
struct HSQL_LTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define HSQL_LTYPE_IS_DECLARED 1
# define HSQL_LTYPE_IS_TRIVIAL 1
#endif



int hsql_parse (hsql::SQLParserResult* result, yyscan_t scanner);

#endif /* !YY_HSQL_BISON_PARSER_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  74
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   904

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  190
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  132
/* YYNRULES -- Number of rules.  */
#define YYNRULES  341
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  601

#define YYUNDEFTOK  2
#define YYMAXUTOK   427


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
       0,   310,   310,   329,   335,   342,   346,   350,   351,   352,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   370,   371,   373,   377,   382,   386,   396,   397,   398,
     400,   400,   407,   408,   413,   419,   421,   425,   436,   442,
     449,   464,   469,   470,   476,   488,   489,   494,   499,   504,
     515,   528,   540,   547,   555,   564,   565,   567,   568,   570,
     574,   579,   580,   582,   589,   590,   591,   592,   593,   594,
     595,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   611,   612,   614,   615,   616,   618,   619,   621,
     625,   630,   631,   632,   633,   634,   636,   637,   645,   651,
     657,   663,   669,   670,   677,   683,   685,   695,   702,   713,
     720,   728,   729,   736,   743,   747,   752,   762,   766,   770,
     782,   782,   784,   785,   794,   795,   797,   811,   823,   828,
     832,   836,   841,   842,   844,   854,   855,   857,   859,   860,
     862,   864,   865,   867,   872,   874,   875,   877,   878,   880,
     884,   889,   891,   892,   893,   897,   898,   900,   901,   902,
     903,   904,   905,   910,   914,   919,   920,   922,   926,   931,
     935,   939,   944,   952,   952,   952,   952,   952,   954,   955,
     955,   955,   955,   955,   955,   955,   955,   956,   956,   960,
     960,   962,   963,   964,   965,   966,   968,   968,   969,   970,
     971,   972,   973,   974,   975,   976,   977,   979,   980,   982,
     983,   984,   985,   989,   990,   991,   992,   994,   995,   997,
     998,  1000,  1001,  1002,  1003,  1004,  1005,  1006,  1008,  1009,
    1011,  1013,  1015,  1016,  1017,  1018,  1019,  1020,  1022,  1023,
    1024,  1025,  1026,  1027,  1029,  1029,  1031,  1033,  1035,  1037,
    1038,  1039,  1040,  1042,  1042,  1042,  1042,  1042,  1042,  1042,
    1044,  1044,  1044,  1044,  1044,  1044,  1044,  1046,  1047,  1049,
    1050,  1056,  1058,  1059,  1061,  1062,  1064,  1066,  1068,  1079,
    1083,  1094,  1126,  1135,  1135,  1142,  1142,  1144,  1144,  1151,
    1155,  1160,  1168,  1174,  1178,  1183,  1184,  1186,  1186,  1188,
    1188,  1190,  1191,  1193,  1193,  1199,  1200,  1202,  1206,  1211,
    1217,  1224,  1225,  1226,  1227,  1229,  1230,  1231,  1237,  1237,
    1239,  1241,  1245,  1250,  1260,  1267,  1275,  1291,  1292,  1293,
    1294,  1295,  1296,  1297,  1298,  1299,  1300,  1302,  1308,  1308,
    1311,  1315
};
#endif

#if HSQL_DEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING", "FLOATVAL",
  "INTVAL", "DEALLOCATE", "PARAMETERS", "INTERSECT", "TEMPORARY",
  "TIMESTAMP", "DISTINCT", "NVARCHAR", "RESTRICT", "TRUNCATE", "ANALYZE",
  "BETWEEN", "CASCADE", "COLUMNS", "CONTROL", "DEFAULT", "EXECUTE",
  "EXPLAIN", "INTEGER", "NATURAL", "PREPARE", "PRIMARY", "SCHEMAS",
  "CHARACTER_VARYING", "REAL", "DECIMAL", "SMALLINT", "BIGINT", "SPATIAL",
  "VARCHAR", "VIRTUAL", "DESCRIBE", "BEFORE", "COLUMN", "CREATE", "DELETE",
  "DIRECT", "DOUBLE", "ESCAPE", "EXCEPT", "EXISTS", "EXTRACT", "CAST",
  "FORMAT", "GLOBAL", "HAVING", "IMPORT", "INSERT", "ISNULL", "OFFSET",
  "RENAME", "SCHEMA", "SELECT", "SORTED", "TABLES", "UNIQUE", "UNLOAD",
  "UPDATE", "VALUES", "AFTER", "ALTER", "CROSS", "DELTA", "FLOAT", "GROUP",
  "INDEX", "INNER", "LIMIT", "LOCAL", "MERGE", "MINUS", "ORDER", "OUTER",
  "RIGHT", "TABLE", "UNION", "USING", "WHERE", "CALL", "CASE", "CHAR",
  "COPY", "DATE", "DATETIME", "DESC", "DROP", "ELSE", "FILE", "FROM",
  "FULL", "HASH", "HINT", "INTO", "JOIN", "LEFT", "LIKE", "LOAD", "LONG",
  "NULL", "PLAN", "SHOW", "TEXT", "THEN", "TIME", "VIEW", "WHEN", "WITH",
  "ADD", "ALL", "AND", "ASC", "END", "FOR", "INT", "KEY", "NOT", "OFF",
  "SET", "TOP", "AS", "BY", "IF", "IN", "IS", "OF", "ON", "OR", "TO", "NO",
  "ARRAY", "CONCAT", "ILIKE", "SECOND", "MINUTE", "HOUR", "DAY", "MONTH",
  "YEAR", "SECONDS", "MINUTES", "HOURS", "DAYS", "MONTHS", "YEARS",
  "INTERVAL", "TRUE", "FALSE", "BOOLEAN", "TRANSACTION", "BEGIN", "COMMIT",
  "ROLLBACK", "NOWAIT", "SKIP", "LOCKED", "SHARE", "HELP", "SYNC",
  "NULLABLE", "'='", "EQUALS", "NOTEQUALS", "'<'", "'>'", "LESS",
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
  "insert_literal", "unsigned_num_literal", "insert_num_literal",
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
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,    61,   420,   421,    60,    62,
     422,   423,   424,   425,   426,    43,    45,    42,    47,    37,
      94,   427,    91,    93,    40,    41,    46,    59,    44,    63
};
# endif

#define YYPACT_NINF (-471)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-339)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     607,    12,   146,   147,   167,   146,   -24,   -36,   118,   102,
     146,   152,   146,   146,    98,    24,   248,   101,   101,   101,
    -471,  -471,   264,    79,  -471,   163,  -471,  -471,   163,  -471,
    -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,
    -471,   -17,  -471,   274,   109,  -471,   112,   208,  -471,  -471,
     184,   184,   247,   146,   324,   146,   216,  -471,   214,   -45,
    -471,   214,   214,   214,   146,  -471,   253,   223,   165,  -471,
    -471,  -471,  -471,  -471,  -471,   590,  -471,   258,  -471,  -471,
     237,   -17,   156,  -471,   100,  -471,   370,    55,   380,   269,
     146,   146,   184,   291,  -471,   300,   210,   392,   350,   146,
     393,   393,   399,   146,   146,  -471,   146,   219,   248,  -471,
     222,   401,   396,   224,   225,  -471,  -471,  -471,   -17,   299,
     288,   -17,     2,  -471,  -471,  -471,  -471,   411,  -471,   418,
    -471,  -471,    65,  -471,   245,   243,  -471,  -471,  -471,  -471,
    -471,   733,  -471,  -471,  -471,  -471,  -471,  -471,   388,   -46,
     210,   432,   373,  -471,   393,   434,     9,   275,   -47,  -471,
    -471,   348,   329,  -471,   329,  -471,  -471,  -471,  -471,  -471,
    -471,   453,  -471,  -471,   373,  -471,  -471,   382,  -471,  -471,
     156,  -471,  -471,   373,   382,   373,   215,   339,  -471,   306,
    -471,  -471,  -471,    55,  -471,  -471,  -471,  -471,  -471,  -471,
    -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,
     457,   352,    74,   341,  -471,   336,     4,  -471,   284,   285,
     286,   180,   377,   290,   448,  -471,   266,    61,   409,  -471,
    -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,
    -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,   733,  -471,
    -471,  -471,  -471,   375,  -471,    -6,   294,  -471,   373,   392,
    -471,   435,  -471,  -471,   426,  -471,  -471,   295,    26,  -471,
     386,   296,  -471,    36,     2,   -17,   297,  -471,   114,     2,
      61,   431,    39,   -21,  -471,   339,  -471,  -471,  -471,   394,
    -471,   679,   368,   305,    69,  -471,  -471,  -471,   352,   146,
      10,    14,   433,   306,   373,   373,   -28,   106,   308,   448,
     688,   373,    56,   312,   -39,   373,   373,   448,  -471,   448,
     -37,   309,   205,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   401,   146,
    -471,   487,    55,   313,  -471,    61,  -471,   214,   324,    55,
    -471,   453,    13,   291,  -471,   373,  -471,   497,  -471,  -471,
    -471,  -471,   373,  -471,  -471,  -471,   339,   373,   373,  -471,
     344,   387,  -471,    44,  -471,   393,  -471,  -471,   318,  -471,
     322,  -471,  -471,   325,  -471,  -471,   327,  -471,  -471,  -471,
    -471,   330,  -471,  -471,    35,   331,   434,  -471,    74,  -471,
     332,  -471,   373,  -471,  -471,   328,   423,   191,   141,   130,
     373,   373,  -471,   433,   417,   145,  -471,  -471,  -471,   405,
     670,   722,   448,   335,   266,  -471,   422,   340,   722,   722,
     722,   722,   557,   557,   557,   557,    56,    56,    60,    60,
      60,   -70,   349,  -471,  -471,   132,   294,   528,  -471,   149,
    -471,   352,  -471,   333,  -471,   346,  -471,    37,  -471,   465,
    -471,  -471,  -471,  -471,    61,    61,  -471,   476,   434,  -471,
     381,  -471,  -471,   534,   536,  -471,   537,   538,   541,  -471,
     428,  -471,  -471,   447,  -471,  -471,    35,  -471,   434,   155,
    -471,   434,   164,  -471,   373,   679,   373,   373,  -471,   190,
     189,   371,  -471,   448,   722,   266,   374,   174,  -471,  -471,
    -471,  -471,  -471,  -471,   378,   456,  -471,  -471,  -471,   480,
     482,   486,   466,    13,   564,  -471,  -471,  -471,   442,  -471,
    -471,  -108,  -471,   385,   175,   395,   408,   410,  -471,  -471,
    -471,   183,  -471,   187,  -471,    40,   416,    61,   193,  -471,
     373,  -471,   688,   419,   200,  -471,  -471,    37,    13,  -471,
    -471,  -471,    13,   404,   389,   373,  -471,  -471,  -471,   565,
    -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,    61,  -471,
    -471,  -471,  -471,   649,   434,   -22,   421,   412,   373,   201,
     373,  -471,  -471,    17,    61,  -471,  -471,    61,   424,   430,
    -471
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     319,     0,     0,     0,     0,     0,    58,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    31,    31,    31,
      32,    33,     0,   339,     3,    22,    19,    20,    22,    18,
       8,     9,     7,    11,    16,    17,    13,    14,    12,    15,
      10,     0,   318,     0,   293,   108,    36,     0,    48,    57,
      56,    56,     0,     0,     0,     0,     0,   292,   103,     0,
      49,   103,   103,   103,     0,    45,     0,     0,   320,   321,
      30,    27,    29,    28,     1,   319,     2,     0,     6,     5,
     156,     0,   117,   118,   148,   100,     0,   166,     0,     0,
       0,     0,    56,   142,    40,     0,   112,     0,     0,     0,
       0,     0,     0,     0,     0,    47,     0,     0,     0,     4,
       0,     0,   136,     0,     0,   130,   131,   129,     0,   133,
       0,     0,   162,   294,   271,   267,   276,     0,   277,     0,
     272,   273,     0,   282,     0,   165,   170,   269,   262,   260,
     261,   268,   263,   264,   265,   266,    35,    34,     0,     0,
     112,   296,     0,   107,     0,     0,     0,     0,   142,   114,
     102,     0,    43,    41,    43,   101,    98,    99,    46,   323,
     322,     0,   155,   135,     0,   125,   124,   148,   121,   120,
     122,   132,   128,     0,   148,     0,     0,   306,   278,   281,
     270,   268,    37,     0,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   279,    55,
       0,   319,     0,     0,   295,     0,   249,   274,     0,     0,
       0,     0,     0,     0,     0,   251,     0,   141,   173,   180,
     181,   182,   175,   177,   183,   176,   196,   184,   185,   186,
     187,   179,   174,   189,   190,   253,   254,   255,   275,   256,
     257,   258,   259,     0,   340,     0,     0,   110,     0,     0,
     113,     0,   104,   105,     0,    39,    44,    25,     0,    23,
     139,   137,   163,   304,   162,     0,   147,   149,   154,   162,
     158,   160,   157,     0,   126,   305,   307,   280,   171,     0,
      52,     0,     0,     0,     0,    59,    61,    62,   319,     0,
     136,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     192,     0,   191,     0,     0,     0,     0,     0,   193,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     111,     0,     0,   109,   167,   116,   115,   103,     0,     0,
      21,     0,     0,   142,   138,     0,   302,     0,   303,   172,
     119,   123,     0,   153,   152,   151,   306,     0,     0,   311,
       0,     0,   313,   317,   308,     0,    80,    74,     0,    76,
      86,    77,    64,     0,    71,    72,     0,    68,    69,    75,
      78,    83,    73,    65,    88,     0,     0,    51,     0,    54,
       0,   228,     0,   250,   252,     0,     0,     0,     0,     0,
       0,     0,   215,     0,     0,     0,   188,   178,   207,   208,
       0,   203,     0,     0,     0,   194,     0,   206,   205,   221,
     222,   223,   224,   225,   226,   227,   198,   197,   200,   199,
     201,   202,     0,    38,   341,     0,     0,     0,    42,     0,
      24,   319,   140,   283,   285,     0,   287,   300,   286,   144,
     164,   301,   150,   127,   161,   159,   314,     0,     0,   316,
       0,   309,    50,     0,     0,    70,     0,     0,     0,    79,
       0,    92,    93,     0,    95,    63,    87,    89,     0,     0,
      60,     0,     0,   219,     0,     0,     0,     0,   213,     0,
       0,     0,   246,     0,   204,     0,     0,     0,   195,   247,
     169,   168,   106,    26,     0,     0,   335,   327,   333,   331,
     334,   329,     0,     0,     0,   299,   291,   297,     0,   134,
     312,   317,   315,     0,     0,     0,     0,     0,    91,    94,
      90,     0,    97,     0,   229,     0,     0,   217,     0,   216,
       0,   220,   248,     0,     0,   211,   209,   300,     0,   330,
     332,   328,     0,   284,   301,     0,   310,    67,    85,     0,
      81,    66,    82,    96,    53,   230,   231,   214,   218,   212,
     210,   288,   324,   336,     0,   146,     0,     0,     0,     0,
       0,   143,    84,     0,   337,   325,   298,   145,   249,     0,
     326
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -471,  -471,  -471,   504,  -471,   544,  -471,   251,  -471,    63,
    -471,  -471,  -471,  -471,  -471,   246,   -99,   439,  -471,  -471,
    -471,    -7,  -471,  -471,   209,  -471,   113,  -471,  -471,  -471,
    -471,   123,  -471,  -471,   -55,  -471,  -471,  -471,  -471,  -471,
    -471,   463,  -471,  -471,   358,  -201,  -100,  -471,    66,   -78,
     -38,  -471,  -471,   -86,   319,  -471,  -471,  -471,  -144,  -471,
    -471,     3,  -471,   256,  -471,  -471,   -31,  -266,  -471,  -471,
     177,   -97,   265,  -152,  -209,  -471,  -471,  -471,  -471,  -471,
    -471,   315,  -471,  -471,  -471,  -471,  -471,  -159,  -471,  -471,
    -471,  -471,  -471,    33,  -471,   441,   496,  -471,   -82,   -63,
    -471,   -64,   -62,   -61,   -60,   -59,  -471,  -470,    77,  -471,
    -471,  -471,    -1,  -471,  -471,    81,   363,  -471,   273,  -471,
     355,  -471,   110,  -471,  -471,  -471,   542,  -471,  -471,  -471,
    -471,  -331
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    22,    23,    24,    25,    78,   268,   269,    26,    71,
      27,    28,   147,    29,    30,    95,   162,   265,    31,    32,
      33,    90,    52,   294,   295,   296,   394,   479,   475,   485,
     486,   487,   297,    34,    99,    35,   262,   263,    36,    37,
      38,   156,    39,   158,   159,    40,   177,   178,   179,    83,
     118,   119,   182,    84,   174,   270,   353,   354,   153,   529,
     591,   122,   276,   277,   365,   112,   187,   271,   134,   343,
     344,   135,   272,   273,   228,   229,   230,   231,   232,   233,
     234,   307,   235,   236,   237,   238,   239,   206,   207,   208,
     240,   241,   242,   243,   244,   136,   137,   138,   245,   246,
     247,   248,   249,   250,   251,   252,   452,   453,   454,   455,
     456,    56,   457,   215,   525,   526,   527,   359,   284,   285,
     286,   373,   471,    41,    42,    68,    69,   458,   522,   595,
      76,   255
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     227,    45,   164,   114,    48,   139,   102,   103,   104,    57,
     290,    59,    60,   310,   260,   312,    44,   403,   163,   163,
     598,   184,   173,   141,   140,   142,   143,   144,   145,   590,
     287,   278,   180,   280,   282,   180,   152,    49,    43,   356,
     356,    80,   369,    64,    91,   415,   121,   172,   210,   100,
     469,   470,    93,   563,    96,   253,    50,   185,    53,   124,
     125,   126,   480,   105,   422,   489,   323,    80,   191,   306,
     125,   126,   163,   256,   314,   186,   315,   291,   257,   211,
     341,    72,    73,   305,    65,   151,    51,   315,   101,   149,
     150,   423,   583,   316,   368,    66,   481,   399,   161,   370,
     310,   292,   166,   167,   316,   168,   345,    82,   420,   115,
     421,   139,   338,   371,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   141,
     140,   142,   143,   144,   145,   293,   492,   531,   212,   482,
     372,   259,   275,   127,   406,   116,   417,   113,   313,    44,
      46,   315,   407,   408,   315,   315,   483,   541,   507,   128,
     543,   357,   524,   418,   419,   115,   355,    81,   316,    61,
      47,   316,   316,   169,   468,   361,   315,   120,    62,   340,
     274,   117,   341,   216,   124,   217,   126,   279,   300,   180,
     301,   404,   323,   316,   225,   401,   323,   451,   410,   484,
      55,   116,   469,   470,   363,   129,   130,   131,    63,   459,
     278,   350,    54,   504,   351,   464,   465,   411,   216,   124,
     217,   126,   497,   412,   405,   575,   218,   219,   220,   315,
     364,   132,    58,   334,   335,   336,   337,   117,   338,   554,
     337,   411,   338,   360,   133,   445,   316,   498,   366,   496,
     514,    67,   449,   589,   397,    70,   315,   398,   499,   500,
     139,   218,   219,   220,    74,   221,    75,   139,   127,   216,
     124,   217,   126,   316,   442,    77,   472,    85,   141,   140,
     142,   143,   144,   145,   128,   141,   140,   142,   143,   144,
     145,   305,   447,   163,   552,    86,    87,   550,   400,   585,
     221,   222,    88,   127,   315,   315,   315,   549,   315,   425,
     577,    89,   218,   219,   220,   223,   495,   510,    92,   128,
     193,   316,   316,   316,    80,   316,   426,    94,   502,   281,
     129,   130,   131,   355,   513,   501,   222,   193,   443,    97,
     542,    98,   545,   341,   547,   548,   506,   106,   107,   544,
     223,   221,   355,   108,   127,   110,   224,   225,   515,   556,
     568,   111,   355,   569,   226,   129,   130,   131,   573,   133,
     128,   341,   574,   123,   152,   341,   216,   124,   217,   126,
     216,   124,   217,   126,   146,   580,   596,   222,   355,   341,
     148,   224,   225,   154,   155,   157,   160,   124,   578,   226,
     516,   223,   165,    81,   133,   517,   171,   126,   173,   175,
     176,   518,   519,   181,   183,   188,   129,   130,   131,   218,
     219,   220,   189,   308,   219,   220,   317,   553,   520,   515,
     192,   193,  -336,   521,   209,   214,   594,   254,   597,   261,
     258,   264,   224,   225,   194,   195,   196,   197,   198,   199,
     226,   216,   124,   217,   126,   133,   267,   283,   221,   120,
     289,   127,   221,   318,    16,   127,   298,   299,   302,   303,
     304,   516,   311,   339,   347,   348,   517,   128,   342,   349,
     352,   128,   518,   519,   355,   362,   367,   375,   395,   396,
     444,    80,   413,   424,   222,   219,   220,   416,   309,   520,
     461,   446,   473,  -336,   521,   466,   474,   467,   223,   476,
     319,   477,   223,   493,   478,   488,   491,   494,   422,   505,
     315,  -289,   338,   129,   130,   131,   508,   129,   130,   131,
     320,   512,   509,   221,   523,   528,   127,   321,   322,   530,
     533,   532,   534,   535,   536,   323,   324,   537,   538,   224,
     225,   539,   128,   224,   225,   558,   551,   226,   559,   555,
     560,   226,   133,   557,   561,   562,   133,   564,   565,   309,
     567,   586,    79,   584,   325,   326,   327,   328,   329,   109,
     570,   330,   331,   223,   332,   333,   334,   335,   336,   337,
    -338,   338,  -290,   571,   448,   572,   593,     1,   129,   130,
     131,   576,   450,   266,   579,     2,   592,   490,   546,   540,
     301,   318,     3,   213,     1,   600,     4,   346,   462,   402,
     460,   409,     2,   511,   224,   225,   599,     5,   190,     3,
       6,     7,   226,     4,   288,   582,   358,   133,   581,   463,
     374,   566,     8,     9,     5,     0,     0,     6,     7,     0,
     170,     0,     0,    10,     0,     0,    11,     0,     0,     8,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,     0,     0,    11,   515,     0,     0,    12,     0,     0,
      13,    14,     0,     0,     0,     0,   322,     0,     0,     0,
     376,     0,     0,   323,    12,     0,    15,    13,    14,     0,
       0,     0,    16,   377,     0,     0,     0,     0,   378,   379,
     380,   381,   382,    15,   383,     0,   516,     0,     0,    16,
       0,   517,   384,     0,   318,  -339,  -339,   518,   519,  -339,
    -339,   587,   332,   333,   334,   335,   336,   337,     0,   338,
       0,     0,   318,     0,   520,    17,    18,    19,   385,   521,
       0,     0,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,    17,    18,    19,   386,     0,   387,   388,    20,
      21,   319,     0,     0,     0,     0,   318,     0,     0,     0,
     588,     0,   389,     0,     0,   503,   390,     0,   391,   319,
       0,   414,     0,     0,     0,     0,     0,     0,   392,   322,
       0,     0,     0,     0,     0,     0,   323,   324,     0,   414,
       0,     0,     0,     0,     0,     0,     0,   322,     0,     0,
       0,     0,     0,  -339,   323,   324,     0,     0,     0,     0,
       0,     0,   393,     0,     0,   325,   326,   327,   328,   329,
       0,     0,   330,   331,     0,   332,   333,   334,   335,   336,
     337,   322,   338,   325,   326,   327,   328,   329,   323,  -339,
     330,   331,     0,   332,   333,   334,   335,   336,   337,     0,
     338,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,     0,     0,     0,     0,  -339,  -339,  -339,
     328,   329,     0,     0,   330,   331,     0,   332,   333,   334,
     335,   336,   337,     0,   338
};

static const yytype_int16 yycheck[] =
{
     152,     2,   101,    81,     5,    87,    61,    62,    63,    10,
     211,    12,    13,   222,   158,   224,     3,     3,   100,   101,
       3,   121,    12,    87,    87,    87,    87,    87,    87,    51,
     189,   183,   118,   185,   186,   121,    83,    61,    26,     3,
       3,    58,    63,    19,    51,   311,    84,   111,    94,    94,
     158,   159,    53,   523,    55,   154,    80,    55,    94,     4,
       5,     6,    27,    64,   101,   396,   136,    58,   132,   221,
       5,     6,   154,    64,   226,    73,   115,     3,   156,   125,
     188,    18,    19,   111,    60,    92,   110,   115,   133,    90,
      91,   128,   562,   132,    55,    71,    61,   298,    99,   120,
     309,    27,   103,   104,   132,   106,   258,    41,   317,     9,
     319,   193,   182,   134,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   193,
     193,   193,   193,   193,   193,    61,   402,   468,   184,   104,
     161,   188,   180,    88,   303,    45,   185,    81,   226,     3,
       3,   115,   304,   305,   115,   115,   121,   488,   424,   104,
     491,   125,   125,   315,   316,     9,   188,   184,   132,    71,
       3,   132,   132,   107,   130,   275,   115,    77,    80,   185,
     177,    81,   188,     3,     4,     5,     6,   184,   184,   275,
     186,   177,   136,   132,   177,   185,   136,   184,    92,   164,
      98,    45,   158,   159,    90,   150,   151,   152,   110,   353,
     362,   185,    94,   422,   188,   367,   368,   111,     3,     4,
       5,     6,    92,   117,   302,   185,    46,    47,    48,   115,
     116,   176,    80,   177,   178,   179,   180,    81,   182,   505,
     180,   111,   182,   274,   189,   342,   132,   117,   279,   108,
     451,     3,   349,   584,   185,   154,   115,   188,   410,   411,
     342,    46,    47,    48,     0,    85,   187,   349,    88,     3,
       4,     5,     6,   132,   338,   112,   375,     3,   342,   342,
     342,   342,   342,   342,   104,   349,   349,   349,   349,   349,
     349,   111,   347,   375,   503,   186,   184,   108,   299,   565,
      85,   121,    94,    88,   115,   115,   115,   117,   115,   104,
     117,   127,    46,    47,    48,   135,   125,   185,    71,   104,
     188,   132,   132,   132,    58,   132,   121,     3,   183,   114,
     150,   151,   152,   188,   185,   413,   121,   188,   339,   123,
     185,   127,   494,   188,   496,   497,   424,    94,   125,   185,
     135,    85,   188,   188,    88,    97,   176,   177,    25,   185,
     185,   124,   188,   188,   184,   150,   151,   152,   185,   189,
     104,   188,   185,     3,    83,   188,     3,     4,     5,     6,
       3,     4,     5,     6,     4,   185,   185,   121,   188,   188,
     121,   176,   177,    93,   184,     3,    46,     4,   550,   184,
      67,   135,     3,   184,   189,    72,   184,     6,    12,   185,
     185,    78,    79,   114,   126,     4,   150,   151,   152,    46,
      47,    48,     4,    46,    47,    48,    17,   505,    95,    25,
     185,   188,    99,   100,    46,     3,   588,     3,   590,    91,
     165,   112,   176,   177,   138,   139,   140,   141,   142,   143,
     184,     3,     4,     5,     6,   189,     3,   118,    85,    77,
       3,    88,    85,    54,   112,    88,   125,   131,   184,   184,
     184,    67,   182,    98,    39,    49,    72,   104,   184,   184,
      94,   104,    78,    79,   188,   188,    55,    93,   120,   184,
       3,    58,   184,   184,   121,    47,    48,   185,   121,    95,
       3,   188,   184,    99,   100,   161,   184,   120,   135,   184,
     101,   184,   135,   185,   184,   184,   184,    94,   101,   184,
     115,   188,   182,   150,   151,   152,   104,   150,   151,   152,
     121,     3,   183,    85,   188,    70,    88,   128,   129,    63,
       6,   160,     6,     6,     6,   136,   137,     6,   120,   176,
     177,   104,   104,   176,   177,    99,   185,   184,    78,   185,
      78,   184,   189,   185,    78,    99,   189,     3,   126,   121,
     185,     6,    28,   184,   165,   166,   167,   168,   169,    75,
     185,   172,   173,   135,   175,   176,   177,   178,   179,   180,
       0,   182,   188,   185,   348,   185,   184,     7,   150,   151,
     152,   185,   351,   164,   185,    15,   185,   398,   495,   486,
     186,    54,    22,   150,     7,   185,    26,   259,   362,   300,
     355,   306,    15,   446,   176,   177,   593,    37,   132,    22,
      40,    41,   184,    26,   193,   558,   273,   189,   557,   366,
     285,   531,    52,    53,    37,    -1,    -1,    40,    41,    -1,
     108,    -1,    -1,    63,    -1,    -1,    66,    -1,    -1,    52,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    66,    25,    -1,    -1,    87,    -1,    -1,
      90,    91,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      11,    -1,    -1,   136,    87,    -1,   106,    90,    91,    -1,
      -1,    -1,   112,    24,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    33,   106,    35,    -1,    67,    -1,    -1,   112,
      -1,    72,    43,    -1,    54,   168,   169,    78,    79,   172,
     173,    82,   175,   176,   177,   178,   179,   180,    -1,   182,
      -1,    -1,    54,    -1,    95,   155,   156,   157,    69,   100,
      -1,    -1,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   155,   156,   157,    86,    -1,    88,    89,   162,
     163,   101,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
     131,    -1,   103,    -1,    -1,   115,   107,    -1,   109,   101,
      -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,   119,   129,
      -1,    -1,    -1,    -1,    -1,    -1,   136,   137,    -1,   121,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,   101,   136,   137,    -1,    -1,    -1,    -1,
      -1,    -1,   153,    -1,    -1,   165,   166,   167,   168,   169,
      -1,    -1,   172,   173,    -1,   175,   176,   177,   178,   179,
     180,   129,   182,   165,   166,   167,   168,   169,   136,   137,
     172,   173,    -1,   175,   176,   177,   178,   179,   180,    -1,
     182,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,    -1,    -1,   172,   173,    -1,   175,   176,   177,
     178,   179,   180,    -1,   182
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     7,    15,    22,    26,    37,    40,    41,    52,    53,
      63,    66,    87,    90,    91,   106,   112,   155,   156,   157,
     162,   163,   191,   192,   193,   194,   198,   200,   201,   203,
     204,   208,   209,   210,   223,   225,   228,   229,   230,   232,
     235,   313,   314,    26,     3,   302,     3,     3,   302,    61,
      80,   110,   212,    94,    94,    98,   301,   302,    80,   302,
     302,    71,    80,   110,    19,    60,    71,     3,   315,   316,
     154,   199,   199,   199,     0,   187,   320,   112,   195,   195,
      58,   184,   238,   239,   243,     3,   186,   184,    94,   127,
     211,   211,    71,   302,     3,   205,   302,   123,   127,   224,
      94,   133,   224,   224,   224,   302,    94,   125,   188,   193,
      97,   124,   255,   238,   239,     9,    45,    81,   240,   241,
      77,   240,   251,     3,     4,     5,     6,    88,   104,   150,
     151,   152,   176,   189,   258,   261,   285,   286,   287,   288,
     289,   291,   292,   293,   294,   295,     4,   202,   121,   302,
     302,   211,    83,   248,    93,   184,   231,     3,   233,   234,
      46,   302,   206,   288,   206,     3,   302,   302,   302,   238,
     316,   184,   291,    12,   244,   185,   185,   236,   237,   238,
     243,   114,   242,   126,   236,    55,    73,   256,     4,     4,
     286,   291,   185,   188,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   277,   278,   279,    46,
      94,   125,   184,   231,     3,   303,     3,     5,    46,    47,
      48,    85,   121,   135,   176,   177,   184,   263,   264,   265,
     266,   267,   268,   269,   270,   272,   273,   274,   275,   276,
     280,   281,   282,   283,   284,   288,   289,   290,   291,   292,
     293,   294,   295,   206,     3,   321,    64,   239,   165,   188,
     248,    91,   226,   227,   112,   207,   207,     3,   196,   197,
     245,   257,   262,   263,   251,   240,   252,   253,   263,   251,
     263,   114,   263,   118,   308,   309,   310,   277,   285,     3,
     235,     3,    27,    61,   213,   214,   215,   222,   125,   131,
     184,   186,   184,   184,   184,   111,   263,   271,    46,   121,
     264,   182,   264,   239,   263,   115,   132,    17,    54,   101,
     121,   128,   129,   136,   137,   165,   166,   167,   168,   169,
     172,   173,   175,   176,   177,   178,   179,   180,   182,    98,
     185,   188,   184,   259,   260,   263,   234,    39,    49,   184,
     185,   188,    94,   246,   247,   188,     3,   125,   306,   307,
     256,   236,   188,    90,   116,   254,   256,    55,    55,    63,
     120,   134,   161,   311,   310,    93,    11,    24,    29,    30,
      31,    32,    33,    35,    43,    69,    86,    88,    89,   103,
     107,   109,   119,   153,   216,   120,   184,   185,   188,   235,
     302,   185,   244,     3,   177,   239,   277,   263,   263,   271,
      92,   111,   117,   184,   121,   257,   185,   185,   263,   263,
     264,   264,   101,   128,   184,   104,   121,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   291,   302,     3,   261,   188,   224,   205,   261,
     197,   184,   296,   297,   298,   299,   300,   302,   317,   248,
     262,     3,   253,   308,   263,   263,   161,   120,   130,   158,
     159,   312,   206,   184,   184,   218,   184,   184,   184,   217,
      27,    61,   104,   121,   164,   219,   220,   221,   184,   321,
     214,   184,   257,   185,    94,   125,   108,    92,   117,   263,
     263,   239,   183,   115,   264,   184,   239,   257,   104,   183,
     185,   260,     3,   185,   235,    25,    67,    72,    78,    79,
      95,   100,   318,   188,   125,   304,   305,   306,    70,   249,
      63,   321,   160,     6,     6,     6,     6,     6,   120,   104,
     221,   321,   185,   321,   185,   263,   216,   263,   263,   117,
     108,   185,   264,   239,   257,   185,   185,   185,    99,    78,
      78,    78,    99,   297,     3,   126,   312,   185,   185,   188,
     185,   185,   185,   185,   185,   185,   185,   117,   263,   185,
     185,   305,   298,   297,   184,   257,     6,    82,   131,   321,
      51,   250,   185,   184,   263,   319,   185,   263,     3,   283,
     185
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   190,   191,   192,   192,   193,   193,   193,   193,   193,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   195,   195,   196,   196,   197,   197,   198,   198,   198,
     199,   199,   200,   200,   201,   202,   203,   203,   204,   204,
     205,   206,   207,   207,   208,   209,   209,   209,   209,   209,
     210,   210,   210,   210,   210,   211,   211,   212,   212,   213,
     213,   214,   214,   215,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   217,   217,   218,   218,   218,   219,   219,   220,
     220,   221,   221,   221,   221,   221,   222,   222,   223,   223,
     223,   223,   224,   224,   225,   226,   227,   228,   229,   230,
     230,   231,   231,   232,   233,   233,   234,   235,   235,   235,
     236,   236,   237,   237,   238,   238,   239,   239,   240,   241,
     241,   241,   242,   242,   243,   244,   244,   245,   246,   246,
     247,   248,   248,   249,   249,   250,   250,   251,   251,   252,
     252,   253,   254,   254,   254,   255,   255,   256,   256,   256,
     256,   256,   256,   257,   257,   258,   258,   259,   259,   260,
     261,   261,   262,   263,   263,   263,   263,   263,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   265,
     265,   266,   266,   266,   266,   266,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   268,   268,   269,
     269,   269,   269,   270,   270,   270,   270,   271,   271,   272,
     272,   273,   273,   273,   273,   273,   273,   273,   274,   274,
     275,   276,   277,   277,   277,   277,   277,   277,   278,   278,
     278,   278,   278,   278,   279,   279,   280,   281,   282,   283,
     283,   283,   283,   284,   284,   284,   284,   284,   284,   284,
     285,   285,   285,   285,   285,   285,   285,   286,   286,   287,
     287,   288,   289,   289,   290,   290,   291,   292,   293,   294,
     294,   294,   295,   296,   296,   297,   297,   298,   298,   299,
     299,   300,   301,   302,   302,   303,   303,   304,   304,   305,
     305,   306,   306,   307,   307,   308,   308,   309,   309,   310,
     310,   311,   311,   311,   311,   312,   312,   312,   313,   313,
     314,   315,   315,   316,   317,   317,   317,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   319,   320,   320,
     321,   321
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     0,     1,     3,     1,     4,     2,     2,     2,
       1,     0,     1,     1,     4,     1,     2,     5,     7,     5,
       1,     1,     3,     0,     5,     2,     4,     3,     2,     2,
       8,     7,     6,    10,     7,     3,     0,     1,     0,     1,
       3,     1,     1,     3,     1,     1,     4,     4,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     4,     3,     0,     5,     3,     0,     1,     0,     1,
       2,     2,     1,     1,     2,     1,     5,     4,     4,     4,
       3,     4,     2,     0,     5,     1,     4,     4,     2,     6,
       5,     3,     0,     5,     1,     3,     3,     2,     2,     6,
       1,     1,     1,     3,     3,     3,     4,     6,     2,     1,
       1,     1,     1,     0,     7,     1,     0,     1,     1,     0,
       2,     2,     0,     4,     0,     2,     0,     3,     0,     1,
       3,     2,     1,     1,     0,     2,     0,     2,     2,     4,
       2,     4,     0,     1,     3,     1,     0,     1,     3,     3,
       1,     3,     2,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     2,     2,     2,     3,     4,     1,     3,     3,     3,
       3,     3,     3,     3,     4,     3,     3,     3,     3,     5,
       6,     5,     6,     4,     6,     3,     5,     4,     5,     4,
       5,     3,     3,     3,     3,     3,     3,     3,     3,     5,
       6,     6,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     5,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     2,     1,     1,     3,     1,     1,     1,     4,     1,
       3,     2,     1,     1,     3,     1,     0,     1,     5,     1,
       0,     2,     1,     1,     0,     1,     0,     1,     2,     3,
       5,     1,     3,     1,     2,     2,     1,     0,     1,     0,
       2,     1,     3,     3,     4,     6,     8,     1,     2,     1,
       2,     1,     2,     1,     1,     1,     0,     1,     1,     0,
       1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined HSQL_LTYPE_IS_TRIVIAL && HSQL_LTYPE_IS_TRIVIAL

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

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, result, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, hsql::SQLParserResult* result, yyscan_t scanner)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  YYUSE (result);
  YYUSE (scanner);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, hsql::SQLParserResult* result, yyscan_t scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp, result, scanner);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, hsql::SQLParserResult* result, yyscan_t scanner)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , result, scanner);
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
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
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
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
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
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
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, hsql::SQLParserResult* result, yyscan_t scanner)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (result);
  YYUSE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
    case 3: /* IDENTIFIER  */
#line 170 "bison_parser.y"
                { free( (((*yyvaluep).sval)) ); }
#line 2006 "bison_parser.cpp"
        break;

    case 4: /* STRING  */
#line 170 "bison_parser.y"
                { free( (((*yyvaluep).sval)) ); }
#line 2012 "bison_parser.cpp"
        break;

    case 5: /* FLOATVAL  */
#line 168 "bison_parser.y"
                { }
#line 2018 "bison_parser.cpp"
        break;

    case 6: /* INTVAL  */
#line 168 "bison_parser.y"
                { }
#line 2024 "bison_parser.cpp"
        break;

    case 192: /* statement_list  */
#line 171 "bison_parser.y"
                {
      if ((((*yyvaluep).stmt_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).stmt_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).stmt_vec));
    }
#line 2037 "bison_parser.cpp"
        break;

    case 193: /* statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).statement)); }
#line 2043 "bison_parser.cpp"
        break;

    case 194: /* preparable_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).statement)); }
#line 2049 "bison_parser.cpp"
        break;

    case 195: /* opt_hints  */
#line 171 "bison_parser.y"
                {
      if ((((*yyvaluep).expr_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).expr_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).expr_vec));
    }
#line 2062 "bison_parser.cpp"
        break;

    case 196: /* hint_list  */
#line 171 "bison_parser.y"
                {
      if ((((*yyvaluep).expr_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).expr_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).expr_vec));
    }
#line 2075 "bison_parser.cpp"
        break;

    case 197: /* hint  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2081 "bison_parser.cpp"
        break;

    case 198: /* transaction_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).transaction_stmt)); }
#line 2087 "bison_parser.cpp"
        break;

    case 200: /* other_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).other_stmt)); }
#line 2093 "bison_parser.cpp"
        break;

    case 201: /* prepare_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).prep_stmt)); }
#line 2099 "bison_parser.cpp"
        break;

    case 202: /* prepare_target_query  */
#line 170 "bison_parser.y"
                { free( (((*yyvaluep).sval)) ); }
#line 2105 "bison_parser.cpp"
        break;

    case 203: /* execute_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).exec_stmt)); }
#line 2111 "bison_parser.cpp"
        break;

    case 204: /* import_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).import_stmt)); }
#line 2117 "bison_parser.cpp"
        break;

    case 205: /* file_type  */
#line 168 "bison_parser.y"
                { }
#line 2123 "bison_parser.cpp"
        break;

    case 206: /* file_path  */
#line 170 "bison_parser.y"
                { free( (((*yyvaluep).sval)) ); }
#line 2129 "bison_parser.cpp"
        break;

    case 207: /* opt_file_type  */
#line 168 "bison_parser.y"
                { }
#line 2135 "bison_parser.cpp"
        break;

    case 208: /* export_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).export_stmt)); }
#line 2141 "bison_parser.cpp"
        break;

    case 209: /* show_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).show_stmt)); }
#line 2147 "bison_parser.cpp"
        break;

    case 210: /* create_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).create_stmt)); }
#line 2153 "bison_parser.cpp"
        break;

    case 211: /* opt_not_exists  */
#line 168 "bison_parser.y"
                { }
#line 2159 "bison_parser.cpp"
        break;

    case 212: /* opt_unique  */
#line 168 "bison_parser.y"
                { }
#line 2165 "bison_parser.cpp"
        break;

    case 213: /* table_elem_commalist  */
#line 171 "bison_parser.y"
                {
      if ((((*yyvaluep).table_element_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).table_element_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).table_element_vec));
    }
#line 2178 "bison_parser.cpp"
        break;

    case 214: /* table_elem  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).table_element_t)); }
#line 2184 "bison_parser.cpp"
        break;

    case 215: /* column_def  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).column_t)); }
#line 2190 "bison_parser.cpp"
        break;

    case 216: /* column_type  */
#line 168 "bison_parser.y"
                { }
#line 2196 "bison_parser.cpp"
        break;

    case 217: /* opt_time_precision  */
#line 168 "bison_parser.y"
                { }
#line 2202 "bison_parser.cpp"
        break;

    case 218: /* opt_decimal_specification  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).ival_pair)); }
#line 2208 "bison_parser.cpp"
        break;

    case 219: /* opt_column_constraints  */
#line 168 "bison_parser.y"
                { }
#line 2214 "bison_parser.cpp"
        break;

    case 220: /* column_constraint_set  */
#line 168 "bison_parser.y"
                { }
#line 2220 "bison_parser.cpp"
        break;

    case 221: /* column_constraint  */
#line 168 "bison_parser.y"
                { }
#line 2226 "bison_parser.cpp"
        break;

    case 222: /* table_constraint  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).table_constraint_t)); }
#line 2232 "bison_parser.cpp"
        break;

    case 223: /* drop_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).drop_stmt)); }
#line 2238 "bison_parser.cpp"
        break;

    case 224: /* opt_exists  */
#line 168 "bison_parser.y"
                { }
#line 2244 "bison_parser.cpp"
        break;

    case 225: /* alter_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).alter_stmt)); }
#line 2250 "bison_parser.cpp"
        break;

    case 226: /* alter_action  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).alter_action_t)); }
#line 2256 "bison_parser.cpp"
        break;

    case 227: /* drop_action  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).drop_action_t)); }
#line 2262 "bison_parser.cpp"
        break;

    case 228: /* delete_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).delete_stmt)); }
#line 2268 "bison_parser.cpp"
        break;

    case 229: /* truncate_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).delete_stmt)); }
#line 2274 "bison_parser.cpp"
        break;

    case 230: /* insert_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).insert_stmt)); }
#line 2280 "bison_parser.cpp"
        break;

    case 231: /* opt_column_list  */
#line 171 "bison_parser.y"
                {
      if ((((*yyvaluep).str_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).str_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).str_vec));
    }
#line 2293 "bison_parser.cpp"
        break;

    case 232: /* update_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).update_stmt)); }
#line 2299 "bison_parser.cpp"
        break;

    case 233: /* update_clause_commalist  */
#line 171 "bison_parser.y"
                {
      if ((((*yyvaluep).update_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).update_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).update_vec));
    }
#line 2312 "bison_parser.cpp"
        break;

    case 234: /* update_clause  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).update_t)); }
#line 2318 "bison_parser.cpp"
        break;

    case 235: /* select_statement  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2324 "bison_parser.cpp"
        break;

    case 236: /* select_within_set_operation  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2330 "bison_parser.cpp"
        break;

    case 237: /* select_within_set_operation_no_parentheses  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2336 "bison_parser.cpp"
        break;

    case 238: /* select_with_paren  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2342 "bison_parser.cpp"
        break;

    case 239: /* select_no_paren  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2348 "bison_parser.cpp"
        break;

    case 240: /* set_operator  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).set_operator_t)); }
#line 2354 "bison_parser.cpp"
        break;

    case 241: /* set_type  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).set_operator_t)); }
#line 2360 "bison_parser.cpp"
        break;

    case 242: /* opt_all  */
#line 168 "bison_parser.y"
                { }
#line 2366 "bison_parser.cpp"
        break;

    case 243: /* select_clause  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2372 "bison_parser.cpp"
        break;

    case 244: /* opt_distinct  */
#line 168 "bison_parser.y"
                { }
#line 2378 "bison_parser.cpp"
        break;

    case 245: /* select_list  */
#line 171 "bison_parser.y"
                {
      if ((((*yyvaluep).expr_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).expr_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).expr_vec));
    }
#line 2391 "bison_parser.cpp"
        break;

    case 246: /* opt_from_clause  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2397 "bison_parser.cpp"
        break;

    case 247: /* from_clause  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2403 "bison_parser.cpp"
        break;

    case 248: /* opt_where  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2409 "bison_parser.cpp"
        break;

    case 249: /* opt_group  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).group_t)); }
#line 2415 "bison_parser.cpp"
        break;

    case 250: /* opt_having  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2421 "bison_parser.cpp"
        break;

    case 251: /* opt_order  */
#line 171 "bison_parser.y"
                {
      if ((((*yyvaluep).order_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).order_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).order_vec));
    }
#line 2434 "bison_parser.cpp"
        break;

    case 252: /* order_list  */
#line 171 "bison_parser.y"
                {
      if ((((*yyvaluep).order_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).order_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).order_vec));
    }
#line 2447 "bison_parser.cpp"
        break;

    case 253: /* order_desc  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).order)); }
#line 2453 "bison_parser.cpp"
        break;

    case 254: /* opt_order_type  */
#line 168 "bison_parser.y"
                { }
#line 2459 "bison_parser.cpp"
        break;

    case 255: /* opt_top  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).limit)); }
#line 2465 "bison_parser.cpp"
        break;

    case 256: /* opt_limit  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).limit)); }
#line 2471 "bison_parser.cpp"
        break;

    case 257: /* expr_list  */
#line 171 "bison_parser.y"
                {
      if ((((*yyvaluep).expr_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).expr_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).expr_vec));
    }
#line 2484 "bison_parser.cpp"
        break;

    case 258: /* opt_literal_list  */
#line 171 "bison_parser.y"
                {
      if ((((*yyvaluep).expr_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).expr_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).expr_vec));
    }
#line 2497 "bison_parser.cpp"
        break;

    case 259: /* list_of_list  */
#line 171 "bison_parser.y"
                {
      if ((((*yyvaluep).list_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).list_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).list_vec));
    }
#line 2510 "bison_parser.cpp"
        break;

    case 260: /* list_item  */
#line 171 "bison_parser.y"
                {
      if ((((*yyvaluep).expr_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).expr_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).expr_vec));
    }
#line 2523 "bison_parser.cpp"
        break;

    case 261: /* literal_list  */
#line 171 "bison_parser.y"
                {
      if ((((*yyvaluep).expr_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).expr_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).expr_vec));
    }
#line 2536 "bison_parser.cpp"
        break;

    case 262: /* expr_alias  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2542 "bison_parser.cpp"
        break;

    case 263: /* expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2548 "bison_parser.cpp"
        break;

    case 264: /* operand  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2554 "bison_parser.cpp"
        break;

    case 265: /* scalar_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2560 "bison_parser.cpp"
        break;

    case 266: /* unary_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2566 "bison_parser.cpp"
        break;

    case 267: /* binary_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2572 "bison_parser.cpp"
        break;

    case 268: /* logic_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2578 "bison_parser.cpp"
        break;

    case 269: /* in_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2584 "bison_parser.cpp"
        break;

    case 270: /* case_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2590 "bison_parser.cpp"
        break;

    case 271: /* case_list  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2596 "bison_parser.cpp"
        break;

    case 272: /* exists_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2602 "bison_parser.cpp"
        break;

    case 273: /* comp_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2608 "bison_parser.cpp"
        break;

    case 274: /* function_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2614 "bison_parser.cpp"
        break;

    case 275: /* extract_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2620 "bison_parser.cpp"
        break;

    case 276: /* cast_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2626 "bison_parser.cpp"
        break;

    case 277: /* datetime_field  */
#line 168 "bison_parser.y"
                { }
#line 2632 "bison_parser.cpp"
        break;

    case 278: /* datetime_field_plural  */
#line 168 "bison_parser.y"
                { }
#line 2638 "bison_parser.cpp"
        break;

    case 279: /* duration_field  */
#line 168 "bison_parser.y"
                { }
#line 2644 "bison_parser.cpp"
        break;

    case 280: /* array_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2650 "bison_parser.cpp"
        break;

    case 281: /* array_index  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2656 "bison_parser.cpp"
        break;

    case 282: /* between_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2662 "bison_parser.cpp"
        break;

    case 283: /* column_name  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2668 "bison_parser.cpp"
        break;

    case 284: /* literal  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2674 "bison_parser.cpp"
        break;

    case 285: /* insert_literal  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2680 "bison_parser.cpp"
        break;

    case 286: /* unsigned_num_literal  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2686 "bison_parser.cpp"
        break;

    case 287: /* insert_num_literal  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2692 "bison_parser.cpp"
        break;

    case 288: /* string_literal  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2698 "bison_parser.cpp"
        break;

    case 289: /* bool_literal  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2704 "bison_parser.cpp"
        break;

    case 290: /* num_literal  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2710 "bison_parser.cpp"
        break;

    case 291: /* int_literal  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2716 "bison_parser.cpp"
        break;

    case 292: /* null_literal  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2722 "bison_parser.cpp"
        break;

    case 293: /* date_literal  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2728 "bison_parser.cpp"
        break;

    case 294: /* interval_literal  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2734 "bison_parser.cpp"
        break;

    case 295: /* param_expr  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2740 "bison_parser.cpp"
        break;

    case 296: /* table_ref  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2746 "bison_parser.cpp"
        break;

    case 297: /* table_ref_atomic  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2752 "bison_parser.cpp"
        break;

    case 298: /* nonjoin_table_ref_atomic  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2758 "bison_parser.cpp"
        break;

    case 299: /* table_ref_commalist  */
#line 171 "bison_parser.y"
                {
      if ((((*yyvaluep).table_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).table_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).table_vec));
    }
#line 2771 "bison_parser.cpp"
        break;

    case 300: /* table_ref_name  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2777 "bison_parser.cpp"
        break;

    case 301: /* table_ref_name_no_alias  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2783 "bison_parser.cpp"
        break;

    case 302: /* table_name  */
#line 169 "bison_parser.y"
                { free( (((*yyvaluep).table_name).name) ); free( (((*yyvaluep).table_name).schema) ); }
#line 2789 "bison_parser.cpp"
        break;

    case 303: /* opt_index_name  */
#line 170 "bison_parser.y"
                { free( (((*yyvaluep).sval)) ); }
#line 2795 "bison_parser.cpp"
        break;

    case 304: /* table_alias  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).alias_t)); }
#line 2801 "bison_parser.cpp"
        break;

    case 305: /* opt_table_alias  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).alias_t)); }
#line 2807 "bison_parser.cpp"
        break;

    case 306: /* alias  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).alias_t)); }
#line 2813 "bison_parser.cpp"
        break;

    case 307: /* opt_alias  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).alias_t)); }
#line 2819 "bison_parser.cpp"
        break;

    case 308: /* opt_locking_clause  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).locking_clause_vec)); }
#line 2825 "bison_parser.cpp"
        break;

    case 309: /* opt_locking_clause_list  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).locking_clause_vec)); }
#line 2831 "bison_parser.cpp"
        break;

    case 310: /* locking_clause  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).locking_t)); }
#line 2837 "bison_parser.cpp"
        break;

    case 311: /* row_lock_mode  */
#line 168 "bison_parser.y"
                { }
#line 2843 "bison_parser.cpp"
        break;

    case 312: /* opt_row_lock_policy  */
#line 168 "bison_parser.y"
                { }
#line 2849 "bison_parser.cpp"
        break;

    case 313: /* opt_with_clause  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).with_description_vec)); }
#line 2855 "bison_parser.cpp"
        break;

    case 314: /* with_clause  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).with_description_vec)); }
#line 2861 "bison_parser.cpp"
        break;

    case 315: /* with_description_list  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).with_description_vec)); }
#line 2867 "bison_parser.cpp"
        break;

    case 316: /* with_description  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).with_description_t)); }
#line 2873 "bison_parser.cpp"
        break;

    case 317: /* join_clause  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2879 "bison_parser.cpp"
        break;

    case 318: /* opt_join_type  */
#line 168 "bison_parser.y"
                { }
#line 2885 "bison_parser.cpp"
        break;

    case 319: /* join_condition  */
#line 179 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2891 "bison_parser.cpp"
        break;

    case 321: /* ident_commalist  */
#line 171 "bison_parser.y"
                {
      if ((((*yyvaluep).str_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).str_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).str_vec));
    }
#line 2904 "bison_parser.cpp"
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
/* The lookahead symbol.  */
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
    int yynerrs;

    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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

#line 3022 "bison_parser.cpp"

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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, &yylloc, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  yychar = YYEMPTY;
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
  case 2:
#line 310 "bison_parser.y"
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
#line 3237 "bison_parser.cpp"
    break;

  case 3:
#line 329 "bison_parser.y"
                           {
  (yyvsp[0].statement)->stringLength = yylloc.string_length;
  yylloc.string_length = 0;
  (yyval.stmt_vec) = new std::vector<SQLStatement*>();
  (yyval.stmt_vec)->push_back((yyvsp[0].statement));
}
#line 3248 "bison_parser.cpp"
    break;

  case 4:
#line 335 "bison_parser.y"
                               {
  (yyvsp[0].statement)->stringLength = yylloc.string_length;
  yylloc.string_length = 0;
  (yyvsp[-2].stmt_vec)->push_back((yyvsp[0].statement));
  (yyval.stmt_vec) = (yyvsp[-2].stmt_vec);
}
#line 3259 "bison_parser.cpp"
    break;

  case 5:
#line 342 "bison_parser.y"
                                        {
  (yyval.statement) = (yyvsp[-1].prep_stmt);
  (yyval.statement)->hints = (yyvsp[0].expr_vec);
}
#line 3268 "bison_parser.cpp"
    break;

  case 6:
#line 346 "bison_parser.y"
                                 {
  (yyval.statement) = (yyvsp[-1].statement);
  (yyval.statement)->hints = (yyvsp[0].expr_vec);
}
#line 3277 "bison_parser.cpp"
    break;

  case 7:
#line 350 "bison_parser.y"
                 { (yyval.statement) = (yyvsp[0].show_stmt); }
#line 3283 "bison_parser.cpp"
    break;

  case 8:
#line 351 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].import_stmt); }
#line 3289 "bison_parser.cpp"
    break;

  case 9:
#line 352 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].export_stmt); }
#line 3295 "bison_parser.cpp"
    break;

  case 10:
#line 354 "bison_parser.y"
                                        { (yyval.statement) = (yyvsp[0].select_stmt); }
#line 3301 "bison_parser.cpp"
    break;

  case 11:
#line 355 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].create_stmt); }
#line 3307 "bison_parser.cpp"
    break;

  case 12:
#line 356 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].insert_stmt); }
#line 3313 "bison_parser.cpp"
    break;

  case 13:
#line 357 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].delete_stmt); }
#line 3319 "bison_parser.cpp"
    break;

  case 14:
#line 358 "bison_parser.y"
                     { (yyval.statement) = (yyvsp[0].delete_stmt); }
#line 3325 "bison_parser.cpp"
    break;

  case 15:
#line 359 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].update_stmt); }
#line 3331 "bison_parser.cpp"
    break;

  case 16:
#line 360 "bison_parser.y"
                 { (yyval.statement) = (yyvsp[0].drop_stmt); }
#line 3337 "bison_parser.cpp"
    break;

  case 17:
#line 361 "bison_parser.y"
                  { (yyval.statement) = (yyvsp[0].alter_stmt); }
#line 3343 "bison_parser.cpp"
    break;

  case 18:
#line 362 "bison_parser.y"
                    { (yyval.statement) = (yyvsp[0].exec_stmt); }
#line 3349 "bison_parser.cpp"
    break;

  case 19:
#line 363 "bison_parser.y"
                        { (yyval.statement) = (yyvsp[0].transaction_stmt); }
#line 3355 "bison_parser.cpp"
    break;

  case 20:
#line 364 "bison_parser.y"
                  { (yyval.statement) = (yyvsp[0].other_stmt); }
#line 3361 "bison_parser.cpp"
    break;

  case 21:
#line 370 "bison_parser.y"
                                        { (yyval.expr_vec) = (yyvsp[-1].expr_vec); }
#line 3367 "bison_parser.cpp"
    break;

  case 22:
#line 371 "bison_parser.y"
              { (yyval.expr_vec) = nullptr; }
#line 3373 "bison_parser.cpp"
    break;

  case 23:
#line 373 "bison_parser.y"
                 {
  (yyval.expr_vec) = new std::vector<Expr*>();
  (yyval.expr_vec)->push_back((yyvsp[0].expr));
}
#line 3382 "bison_parser.cpp"
    break;

  case 24:
#line 377 "bison_parser.y"
                     {
  (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr));
  (yyval.expr_vec) = (yyvsp[-2].expr_vec);
}
#line 3391 "bison_parser.cpp"
    break;

  case 25:
#line 382 "bison_parser.y"
                  {
  (yyval.expr) = Expr::make(kExprHint);
  (yyval.expr)->name = (yyvsp[0].sval);
}
#line 3400 "bison_parser.cpp"
    break;

  case 26:
#line 386 "bison_parser.y"
                                  {
  (yyval.expr) = Expr::make(kExprHint);
  (yyval.expr)->name = (yyvsp[-3].sval);
  (yyval.expr)->exprList = (yyvsp[-1].expr_vec);
}
#line 3410 "bison_parser.cpp"
    break;

  case 27:
#line 396 "bison_parser.y"
                                                      { (yyval.transaction_stmt) = new TransactionStatement(kBeginTransaction); }
#line 3416 "bison_parser.cpp"
    break;

  case 28:
#line 397 "bison_parser.y"
                                   { (yyval.transaction_stmt) = new TransactionStatement(kRollbackTransaction); }
#line 3422 "bison_parser.cpp"
    break;

  case 29:
#line 398 "bison_parser.y"
                                 { (yyval.transaction_stmt) = new TransactionStatement(kCommitTransaction); }
#line 3428 "bison_parser.cpp"
    break;

  case 32:
#line 407 "bison_parser.y"
                       { (yyval.other_stmt) = new OtherStatement(kHelp); }
#line 3434 "bison_parser.cpp"
    break;

  case 33:
#line 408 "bison_parser.y"
       { (yyval.other_stmt) = new OtherStatement(kSync); }
#line 3440 "bison_parser.cpp"
    break;

  case 34:
#line 413 "bison_parser.y"
                                                                 {
  (yyval.prep_stmt) = new PrepareStatement();
  (yyval.prep_stmt)->name = (yyvsp[-2].sval);
  (yyval.prep_stmt)->query = (yyvsp[0].sval);
}
#line 3450 "bison_parser.cpp"
    break;

  case 36:
#line 421 "bison_parser.y"
                                                                  {
  (yyval.exec_stmt) = new ExecuteStatement();
  (yyval.exec_stmt)->name = (yyvsp[0].sval);
}
#line 3459 "bison_parser.cpp"
    break;

  case 37:
#line 425 "bison_parser.y"
                                              {
  (yyval.exec_stmt) = new ExecuteStatement();
  (yyval.exec_stmt)->name = (yyvsp[-3].sval);
  (yyval.exec_stmt)->parameters = (yyvsp[-1].expr_vec);
}
#line 3469 "bison_parser.cpp"
    break;

  case 38:
#line 436 "bison_parser.y"
                                                                        {
  (yyval.import_stmt) = new ImportStatement((yyvsp[-4].import_type_t));
  (yyval.import_stmt)->filePath = (yyvsp[-2].sval);
  (yyval.import_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.import_stmt)->tableName = (yyvsp[0].table_name).name;
}
#line 3480 "bison_parser.cpp"
    break;

  case 39:
#line 442 "bison_parser.y"
                                               {
  (yyval.import_stmt) = new ImportStatement((yyvsp[0].import_type_t));
  (yyval.import_stmt)->filePath = (yyvsp[-1].sval);
  (yyval.import_stmt)->schema = (yyvsp[-3].table_name).schema;
  (yyval.import_stmt)->tableName = (yyvsp[-3].table_name).name;
}
#line 3491 "bison_parser.cpp"
    break;

  case 40:
#line 449 "bison_parser.y"
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
#line 3510 "bison_parser.cpp"
    break;

  case 41:
#line 464 "bison_parser.y"
                           {
  (yyval.sval) = strdup((yyvsp[0].expr)->name);
  delete (yyvsp[0].expr);
}
#line 3519 "bison_parser.cpp"
    break;

  case 42:
#line 469 "bison_parser.y"
                                      { (yyval.import_type_t) = (yyvsp[0].import_type_t); }
#line 3525 "bison_parser.cpp"
    break;

  case 43:
#line 470 "bison_parser.y"
              { (yyval.import_type_t) = kImportAuto; }
#line 3531 "bison_parser.cpp"
    break;

  case 44:
#line 476 "bison_parser.y"
                                                              {
  (yyval.export_stmt) = new ExportStatement((yyvsp[0].import_type_t));
  (yyval.export_stmt)->filePath = (yyvsp[-1].sval);
  (yyval.export_stmt)->schema = (yyvsp[-3].table_name).schema;
  (yyval.export_stmt)->tableName = (yyvsp[-3].table_name).name;
}
#line 3542 "bison_parser.cpp"
    break;

  case 45:
#line 488 "bison_parser.y"
                             { (yyval.show_stmt) = new ShowStatement(kShowTables); }
#line 3548 "bison_parser.cpp"
    break;

  case 46:
#line 489 "bison_parser.y"
                             {
  (yyval.show_stmt) = new ShowStatement(kShowIndex);
  (yyval.show_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.show_stmt)->name = (yyvsp[0].table_name).name;
}
#line 3558 "bison_parser.cpp"
    break;

  case 47:
#line 494 "bison_parser.y"
                          {
  (yyval.show_stmt) = new ShowStatement(kShowColumns);
  (yyval.show_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.show_stmt)->name = (yyvsp[0].table_name).name;
}
#line 3568 "bison_parser.cpp"
    break;

  case 48:
#line 499 "bison_parser.y"
                      {
  (yyval.show_stmt) = new ShowStatement(kShowColumns);
  (yyval.show_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.show_stmt)->name = (yyvsp[0].table_name).name;
}
#line 3578 "bison_parser.cpp"
    break;

  case 49:
#line 504 "bison_parser.y"
                  {
  (yyval.show_stmt) = new ShowStatement(kShowColumns);
  (yyval.show_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.show_stmt)->name = (yyvsp[0].table_name).name;
}
#line 3588 "bison_parser.cpp"
    break;

  case 50:
#line 515 "bison_parser.y"
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
#line 3606 "bison_parser.cpp"
    break;

  case 51:
#line 528 "bison_parser.y"
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
#line 3623 "bison_parser.cpp"
    break;

  case 52:
#line 540 "bison_parser.y"
                                                             {
  (yyval.create_stmt) = new CreateStatement(kCreateTable);
  (yyval.create_stmt)->ifNotExists = (yyvsp[-3].bval);
  (yyval.create_stmt)->schema = (yyvsp[-2].table_name).schema;
  (yyval.create_stmt)->tableName = (yyvsp[-2].table_name).name;
  (yyval.create_stmt)->select = (yyvsp[0].select_stmt);
}
#line 3635 "bison_parser.cpp"
    break;

  case 53:
#line 547 "bison_parser.y"
                                                                                              {
  (yyval.create_stmt) = new CreateStatement(kCreateIndex);
  (yyval.create_stmt)->indexName = (yyvsp[-5].sval);
  (yyval.create_stmt)->ifNotExists = (yyvsp[-6].bval);
  (yyval.create_stmt)->isUnique = (yyvsp[-8].bval);
  (yyval.create_stmt)->tableName = (yyvsp[-3].table_name).name;
  (yyval.create_stmt)->indexColumns = (yyvsp[-1].str_vec);
}
#line 3648 "bison_parser.cpp"
    break;

  case 54:
#line 555 "bison_parser.y"
                                                                            {
  (yyval.create_stmt) = new CreateStatement(kCreateView);
  (yyval.create_stmt)->ifNotExists = (yyvsp[-4].bval);
  (yyval.create_stmt)->schema = (yyvsp[-3].table_name).schema;
  (yyval.create_stmt)->tableName = (yyvsp[-3].table_name).name;
  (yyval.create_stmt)->viewColumns = (yyvsp[-2].str_vec);
  (yyval.create_stmt)->select = (yyvsp[0].select_stmt);
}
#line 3661 "bison_parser.cpp"
    break;

  case 55:
#line 564 "bison_parser.y"
                               { (yyval.bval) = true; }
#line 3667 "bison_parser.cpp"
    break;

  case 56:
#line 565 "bison_parser.y"
              { (yyval.bval) = false; }
#line 3673 "bison_parser.cpp"
    break;

  case 57:
#line 567 "bison_parser.y"
                   { (yyval.bval) = true; }
#line 3679 "bison_parser.cpp"
    break;

  case 58:
#line 568 "bison_parser.y"
              { (yyval.bval) = false; }
#line 3685 "bison_parser.cpp"
    break;

  case 59:
#line 570 "bison_parser.y"
                                  {
  (yyval.table_element_vec) = new std::vector<TableElement*>();
  (yyval.table_element_vec)->push_back((yyvsp[0].table_element_t));
}
#line 3694 "bison_parser.cpp"
    break;

  case 60:
#line 574 "bison_parser.y"
                                      {
  (yyvsp[-2].table_element_vec)->push_back((yyvsp[0].table_element_t));
  (yyval.table_element_vec) = (yyvsp[-2].table_element_vec);
}
#line 3703 "bison_parser.cpp"
    break;

  case 61:
#line 579 "bison_parser.y"
                        { (yyval.table_element_t) = (yyvsp[0].column_t); }
#line 3709 "bison_parser.cpp"
    break;

  case 62:
#line 580 "bison_parser.y"
                   { (yyval.table_element_t) = (yyvsp[0].table_constraint_t); }
#line 3715 "bison_parser.cpp"
    break;

  case 63:
#line 582 "bison_parser.y"
                                                           {
  (yyval.column_t) = new ColumnDefinition((yyvsp[-2].sval), (yyvsp[-1].column_type_t), (yyvsp[0].column_constraint_set));
  if (!(yyval.column_t)->trySetNullableExplicit()) {
    yyerror(&yyloc, result, scanner, ("Conflicting nullability constraints for " + std::string{(yyvsp[-2].sval)}).c_str());
  }
}
#line 3726 "bison_parser.cpp"
    break;

  case 64:
#line 589 "bison_parser.y"
                     { (yyval.column_type_t) = ColumnType{DataType::BIGINT}; }
#line 3732 "bison_parser.cpp"
    break;

  case 65:
#line 590 "bison_parser.y"
          { (yyval.column_type_t) = ColumnType{DataType::BOOLEAN}; }
#line 3738 "bison_parser.cpp"
    break;

  case 66:
#line 591 "bison_parser.y"
                      { (yyval.column_type_t) = ColumnType{DataType::CHAR, (yyvsp[-1].ival)}; }
#line 3744 "bison_parser.cpp"
    break;

  case 67:
#line 592 "bison_parser.y"
                                   { (yyval.column_type_t) = ColumnType{DataType::VARCHAR, (yyvsp[-1].ival)}; }
#line 3750 "bison_parser.cpp"
    break;

  case 68:
#line 593 "bison_parser.y"
       { (yyval.column_type_t) = ColumnType{DataType::DATE}; }
#line 3756 "bison_parser.cpp"
    break;

  case 69:
#line 594 "bison_parser.y"
           { (yyval.column_type_t) = ColumnType{DataType::DATETIME}; }
#line 3762 "bison_parser.cpp"
    break;

  case 70:
#line 595 "bison_parser.y"
                                    {
  (yyval.column_type_t) = ColumnType{DataType::DECIMAL, 0, (yyvsp[0].ival_pair)->first, (yyvsp[0].ival_pair)->second};
  delete (yyvsp[0].ival_pair);
}
#line 3771 "bison_parser.cpp"
    break;

  case 71:
#line 599 "bison_parser.y"
         { (yyval.column_type_t) = ColumnType{DataType::DOUBLE}; }
#line 3777 "bison_parser.cpp"
    break;

  case 72:
#line 600 "bison_parser.y"
        { (yyval.column_type_t) = ColumnType{DataType::FLOAT}; }
#line 3783 "bison_parser.cpp"
    break;

  case 73:
#line 601 "bison_parser.y"
      { (yyval.column_type_t) = ColumnType{DataType::INT}; }
#line 3789 "bison_parser.cpp"
    break;

  case 74:
#line 602 "bison_parser.y"
          { (yyval.column_type_t) = ColumnType{DataType::INT}; }
#line 3795 "bison_parser.cpp"
    break;

  case 75:
#line 603 "bison_parser.y"
       { (yyval.column_type_t) = ColumnType{DataType::LONG}; }
#line 3801 "bison_parser.cpp"
    break;

  case 76:
#line 604 "bison_parser.y"
       { (yyval.column_type_t) = ColumnType{DataType::REAL}; }
#line 3807 "bison_parser.cpp"
    break;

  case 77:
#line 605 "bison_parser.y"
           { (yyval.column_type_t) = ColumnType{DataType::SMALLINT}; }
#line 3813 "bison_parser.cpp"
    break;

  case 78:
#line 606 "bison_parser.y"
       { (yyval.column_type_t) = ColumnType{DataType::TEXT}; }
#line 3819 "bison_parser.cpp"
    break;

  case 79:
#line 607 "bison_parser.y"
                          { (yyval.column_type_t) = ColumnType{DataType::TIME, 0, (yyvsp[0].ival)}; }
#line 3825 "bison_parser.cpp"
    break;

  case 80:
#line 608 "bison_parser.y"
            { (yyval.column_type_t) = ColumnType{DataType::DATETIME}; }
#line 3831 "bison_parser.cpp"
    break;

  case 81:
#line 609 "bison_parser.y"
                         { (yyval.column_type_t) = ColumnType{DataType::VARCHAR, (yyvsp[-1].ival)}; }
#line 3837 "bison_parser.cpp"
    break;

  case 82:
#line 611 "bison_parser.y"
                                    { (yyval.ival) = (yyvsp[-1].ival); }
#line 3843 "bison_parser.cpp"
    break;

  case 83:
#line 612 "bison_parser.y"
              { (yyval.ival) = 0; }
#line 3849 "bison_parser.cpp"
    break;

  case 84:
#line 614 "bison_parser.y"
                                                      { (yyval.ival_pair) = new std::pair<int64_t, int64_t>{(yyvsp[-3].ival), (yyvsp[-1].ival)}; }
#line 3855 "bison_parser.cpp"
    break;

  case 85:
#line 615 "bison_parser.y"
                 { (yyval.ival_pair) = new std::pair<int64_t, int64_t>{(yyvsp[-1].ival), 0}; }
#line 3861 "bison_parser.cpp"
    break;

  case 86:
#line 616 "bison_parser.y"
              { (yyval.ival_pair) = new std::pair<int64_t, int64_t>{0, 0}; }
#line 3867 "bison_parser.cpp"
    break;

  case 87:
#line 618 "bison_parser.y"
                                               { (yyval.column_constraint_set) = (yyvsp[0].column_constraint_set); }
#line 3873 "bison_parser.cpp"
    break;

  case 88:
#line 619 "bison_parser.y"
              { (yyval.column_constraint_set) = new std::unordered_set<ConstraintType>(); }
#line 3879 "bison_parser.cpp"
    break;

  case 89:
#line 621 "bison_parser.y"
                                          {
  (yyval.column_constraint_set) = new std::unordered_set<ConstraintType>();
  (yyval.column_constraint_set)->insert((yyvsp[0].column_constraint_t));
}
#line 3888 "bison_parser.cpp"
    break;

  case 90:
#line 625 "bison_parser.y"
                                          {
  (yyvsp[-1].column_constraint_set)->insert((yyvsp[0].column_constraint_t));
  (yyval.column_constraint_set) = (yyvsp[-1].column_constraint_set);
}
#line 3897 "bison_parser.cpp"
    break;

  case 91:
#line 630 "bison_parser.y"
                                { (yyval.column_constraint_t) = ConstraintType::PrimaryKey; }
#line 3903 "bison_parser.cpp"
    break;

  case 92:
#line 631 "bison_parser.y"
         { (yyval.column_constraint_t) = ConstraintType::Unique; }
#line 3909 "bison_parser.cpp"
    break;

  case 93:
#line 632 "bison_parser.y"
       { (yyval.column_constraint_t) = ConstraintType::Null; }
#line 3915 "bison_parser.cpp"
    break;

  case 94:
#line 633 "bison_parser.y"
           { (yyval.column_constraint_t) = ConstraintType::NotNull; }
#line 3921 "bison_parser.cpp"
    break;

  case 95:
#line 634 "bison_parser.y"
           { (yyval.column_constraint_t) = ConstraintType::Null; }
#line 3927 "bison_parser.cpp"
    break;

  case 96:
#line 636 "bison_parser.y"
                                                       { (yyval.table_constraint_t) = new TableConstraint(ConstraintType::PrimaryKey, (yyvsp[-1].str_vec)); }
#line 3933 "bison_parser.cpp"
    break;

  case 97:
#line 637 "bison_parser.y"
                                 { (yyval.table_constraint_t) = new TableConstraint(ConstraintType::Unique, (yyvsp[-1].str_vec)); }
#line 3939 "bison_parser.cpp"
    break;

  case 98:
#line 645 "bison_parser.y"
                                                  {
  (yyval.drop_stmt) = new DropStatement(kDropTable);
  (yyval.drop_stmt)->ifExists = (yyvsp[-1].bval);
  (yyval.drop_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.drop_stmt)->name = (yyvsp[0].table_name).name;
}
#line 3950 "bison_parser.cpp"
    break;

  case 99:
#line 651 "bison_parser.y"
                                  {
  (yyval.drop_stmt) = new DropStatement(kDropView);
  (yyval.drop_stmt)->ifExists = (yyvsp[-1].bval);
  (yyval.drop_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.drop_stmt)->name = (yyvsp[0].table_name).name;
}
#line 3961 "bison_parser.cpp"
    break;

  case 100:
#line 657 "bison_parser.y"
                                {
  (yyval.drop_stmt) = new DropStatement(kDropPreparedStatement);
  (yyval.drop_stmt)->ifExists = false;
  (yyval.drop_stmt)->name = (yyvsp[0].sval);
}
#line 3971 "bison_parser.cpp"
    break;

  case 101:
#line 663 "bison_parser.y"
                                   {
  (yyval.drop_stmt) = new DropStatement(kDropIndex);
  (yyval.drop_stmt)->ifExists = (yyvsp[-1].bval);
  (yyval.drop_stmt)->indexName = (yyvsp[0].sval);
}
#line 3981 "bison_parser.cpp"
    break;

  case 102:
#line 669 "bison_parser.y"
                       { (yyval.bval) = true; }
#line 3987 "bison_parser.cpp"
    break;

  case 103:
#line 670 "bison_parser.y"
              { (yyval.bval) = false; }
#line 3993 "bison_parser.cpp"
    break;

  case 104:
#line 677 "bison_parser.y"
                                                                 {
  (yyval.alter_stmt) = new AlterStatement((yyvsp[-1].table_name).name, (yyvsp[0].alter_action_t));
  (yyval.alter_stmt)->ifTableExists = (yyvsp[-2].bval);
  (yyval.alter_stmt)->schema = (yyvsp[-1].table_name).schema;
}
#line 4003 "bison_parser.cpp"
    break;

  case 105:
#line 683 "bison_parser.y"
                           { (yyval.alter_action_t) = (yyvsp[0].drop_action_t); }
#line 4009 "bison_parser.cpp"
    break;

  case 106:
#line 685 "bison_parser.y"
                                                {
  (yyval.drop_action_t) = new DropColumnAction((yyvsp[0].sval));
  (yyval.drop_action_t)->ifExists = (yyvsp[-1].bval);
}
#line 4018 "bison_parser.cpp"
    break;

  case 107:
#line 695 "bison_parser.y"
                                                    {
  (yyval.delete_stmt) = new DeleteStatement();
  (yyval.delete_stmt)->schema = (yyvsp[-1].table_name).schema;
  (yyval.delete_stmt)->tableName = (yyvsp[-1].table_name).name;
  (yyval.delete_stmt)->expr = (yyvsp[0].expr);
}
#line 4029 "bison_parser.cpp"
    break;

  case 108:
#line 702 "bison_parser.y"
                                         {
  (yyval.delete_stmt) = new DeleteStatement();
  (yyval.delete_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.delete_stmt)->tableName = (yyvsp[0].table_name).name;
}
#line 4039 "bison_parser.cpp"
    break;

  case 109:
#line 713 "bison_parser.y"
                                                                              {
  (yyval.insert_stmt) = new InsertStatement(kInsertValues);
  (yyval.insert_stmt)->schema = (yyvsp[-3].table_name).schema;
  (yyval.insert_stmt)->tableName = (yyvsp[-3].table_name).name;
  (yyval.insert_stmt)->columns = (yyvsp[-2].str_vec);
  (yyval.insert_stmt)->values = (yyvsp[0].list_vec);
}
#line 4051 "bison_parser.cpp"
    break;

  case 110:
#line 720 "bison_parser.y"
                                                         {
  (yyval.insert_stmt) = new InsertStatement(kInsertSelect);
  (yyval.insert_stmt)->schema = (yyvsp[-2].table_name).schema;
  (yyval.insert_stmt)->tableName = (yyvsp[-2].table_name).name;
  (yyval.insert_stmt)->columns = (yyvsp[-1].str_vec);
  (yyval.insert_stmt)->select = (yyvsp[0].select_stmt);
}
#line 4063 "bison_parser.cpp"
    break;

  case 111:
#line 728 "bison_parser.y"
                                          { (yyval.str_vec) = (yyvsp[-1].str_vec); }
#line 4069 "bison_parser.cpp"
    break;

  case 112:
#line 729 "bison_parser.y"
              { (yyval.str_vec) = nullptr; }
#line 4075 "bison_parser.cpp"
    break;

  case 113:
#line 736 "bison_parser.y"
                                                                                        {
  (yyval.update_stmt) = new UpdateStatement();
  (yyval.update_stmt)->table = (yyvsp[-3].table);
  (yyval.update_stmt)->updates = (yyvsp[-1].update_vec);
  (yyval.update_stmt)->where = (yyvsp[0].expr);
}
#line 4086 "bison_parser.cpp"
    break;

  case 114:
#line 743 "bison_parser.y"
                                        {
  (yyval.update_vec) = new std::vector<UpdateClause*>();
  (yyval.update_vec)->push_back((yyvsp[0].update_t));
}
#line 4095 "bison_parser.cpp"
    break;

  case 115:
#line 747 "bison_parser.y"
                                            {
  (yyvsp[-2].update_vec)->push_back((yyvsp[0].update_t));
  (yyval.update_vec) = (yyvsp[-2].update_vec);
}
#line 4104 "bison_parser.cpp"
    break;

  case 116:
#line 752 "bison_parser.y"
                                    {
  (yyval.update_t) = new UpdateClause();
  (yyval.update_t)->column = (yyvsp[-2].sval);
  (yyval.update_t)->value = (yyvsp[0].expr);
}
#line 4114 "bison_parser.cpp"
    break;

  case 117:
#line 762 "bison_parser.y"
                                                     {
  (yyval.select_stmt) = (yyvsp[0].select_stmt);
  (yyval.select_stmt)->withDescriptions = (yyvsp[-1].with_description_vec);
}
#line 4123 "bison_parser.cpp"
    break;

  case 118:
#line 766 "bison_parser.y"
                                  {
  (yyval.select_stmt) = (yyvsp[0].select_stmt);
  (yyval.select_stmt)->withDescriptions = (yyvsp[-1].with_description_vec);
}
#line 4132 "bison_parser.cpp"
    break;

  case 119:
#line 770 "bison_parser.y"
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
#line 4148 "bison_parser.cpp"
    break;

  case 122:
#line 784 "bison_parser.y"
                                                           { (yyval.select_stmt) = (yyvsp[0].select_stmt); }
#line 4154 "bison_parser.cpp"
    break;

  case 123:
#line 785 "bison_parser.y"
                                                         {
  (yyval.select_stmt) = (yyvsp[-2].select_stmt);
  if ((yyval.select_stmt)->setOperations == nullptr) {
    (yyval.select_stmt)->setOperations = new std::vector<SetOperation*>();
  }
  (yyval.select_stmt)->setOperations->push_back((yyvsp[-1].set_operator_t));
  (yyval.select_stmt)->setOperations->back()->nestedSelectStatement = (yyvsp[0].select_stmt);
}
#line 4167 "bison_parser.cpp"
    break;

  case 124:
#line 794 "bison_parser.y"
                                            { (yyval.select_stmt) = (yyvsp[-1].select_stmt); }
#line 4173 "bison_parser.cpp"
    break;

  case 125:
#line 795 "bison_parser.y"
                            { (yyval.select_stmt) = (yyvsp[-1].select_stmt); }
#line 4179 "bison_parser.cpp"
    break;

  case 126:
#line 797 "bison_parser.y"
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
#line 4198 "bison_parser.cpp"
    break;

  case 127:
#line 811 "bison_parser.y"
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
#line 4214 "bison_parser.cpp"
    break;

  case 128:
#line 823 "bison_parser.y"
                                {
  (yyval.set_operator_t) = (yyvsp[-1].set_operator_t);
  (yyval.set_operator_t)->isAll = (yyvsp[0].bval);
}
#line 4223 "bison_parser.cpp"
    break;

  case 129:
#line 828 "bison_parser.y"
                 {
  (yyval.set_operator_t) = new SetOperation();
  (yyval.set_operator_t)->setType = SetType::kSetUnion;
}
#line 4232 "bison_parser.cpp"
    break;

  case 130:
#line 832 "bison_parser.y"
            {
  (yyval.set_operator_t) = new SetOperation();
  (yyval.set_operator_t)->setType = SetType::kSetIntersect;
}
#line 4241 "bison_parser.cpp"
    break;

  case 131:
#line 836 "bison_parser.y"
         {
  (yyval.set_operator_t) = new SetOperation();
  (yyval.set_operator_t)->setType = SetType::kSetExcept;
}
#line 4250 "bison_parser.cpp"
    break;

  case 132:
#line 841 "bison_parser.y"
              { (yyval.bval) = true; }
#line 4256 "bison_parser.cpp"
    break;

  case 133:
#line 842 "bison_parser.y"
              { (yyval.bval) = false; }
#line 4262 "bison_parser.cpp"
    break;

  case 134:
#line 844 "bison_parser.y"
                                                                                            {
  (yyval.select_stmt) = new SelectStatement();
  (yyval.select_stmt)->limit = (yyvsp[-5].limit);
  (yyval.select_stmt)->selectDistinct = (yyvsp[-4].bval);
  (yyval.select_stmt)->selectList = (yyvsp[-3].expr_vec);
  (yyval.select_stmt)->fromTable = (yyvsp[-2].table);
  (yyval.select_stmt)->whereClause = (yyvsp[-1].expr);
  (yyval.select_stmt)->groupBy = (yyvsp[0].group_t);
}
#line 4276 "bison_parser.cpp"
    break;

  case 135:
#line 854 "bison_parser.y"
                        { (yyval.bval) = true; }
#line 4282 "bison_parser.cpp"
    break;

  case 136:
#line 855 "bison_parser.y"
              { (yyval.bval) = false; }
#line 4288 "bison_parser.cpp"
    break;

  case 138:
#line 859 "bison_parser.y"
                              { (yyval.table) = (yyvsp[0].table); }
#line 4294 "bison_parser.cpp"
    break;

  case 139:
#line 860 "bison_parser.y"
              { (yyval.table) = nullptr; }
#line 4300 "bison_parser.cpp"
    break;

  case 140:
#line 862 "bison_parser.y"
                             { (yyval.table) = (yyvsp[0].table); }
#line 4306 "bison_parser.cpp"
    break;

  case 141:
#line 864 "bison_parser.y"
                       { (yyval.expr) = (yyvsp[0].expr); }
#line 4312 "bison_parser.cpp"
    break;

  case 142:
#line 865 "bison_parser.y"
              { (yyval.expr) = nullptr; }
#line 4318 "bison_parser.cpp"
    break;

  case 143:
#line 867 "bison_parser.y"
                                          {
  (yyval.group_t) = new GroupByDescription();
  (yyval.group_t)->columns = (yyvsp[-1].expr_vec);
  (yyval.group_t)->having = (yyvsp[0].expr);
}
#line 4328 "bison_parser.cpp"
    break;

  case 144:
#line 872 "bison_parser.y"
              { (yyval.group_t) = nullptr; }
#line 4334 "bison_parser.cpp"
    break;

  case 145:
#line 874 "bison_parser.y"
                         { (yyval.expr) = (yyvsp[0].expr); }
#line 4340 "bison_parser.cpp"
    break;

  case 146:
#line 875 "bison_parser.y"
              { (yyval.expr) = nullptr; }
#line 4346 "bison_parser.cpp"
    break;

  case 147:
#line 877 "bison_parser.y"
                                { (yyval.order_vec) = (yyvsp[0].order_vec); }
#line 4352 "bison_parser.cpp"
    break;

  case 148:
#line 878 "bison_parser.y"
              { (yyval.order_vec) = nullptr; }
#line 4358 "bison_parser.cpp"
    break;

  case 149:
#line 880 "bison_parser.y"
                        {
  (yyval.order_vec) = new std::vector<OrderDescription*>();
  (yyval.order_vec)->push_back((yyvsp[0].order));
}
#line 4367 "bison_parser.cpp"
    break;

  case 150:
#line 884 "bison_parser.y"
                            {
  (yyvsp[-2].order_vec)->push_back((yyvsp[0].order));
  (yyval.order_vec) = (yyvsp[-2].order_vec);
}
#line 4376 "bison_parser.cpp"
    break;

  case 151:
#line 889 "bison_parser.y"
                                 { (yyval.order) = new OrderDescription((yyvsp[0].order_type), (yyvsp[-1].expr)); }
#line 4382 "bison_parser.cpp"
    break;

  case 152:
#line 891 "bison_parser.y"
                     { (yyval.order_type) = kOrderAsc; }
#line 4388 "bison_parser.cpp"
    break;

  case 153:
#line 892 "bison_parser.y"
       { (yyval.order_type) = kOrderDesc; }
#line 4394 "bison_parser.cpp"
    break;

  case 154:
#line 893 "bison_parser.y"
              { (yyval.order_type) = kOrderAsc; }
#line 4400 "bison_parser.cpp"
    break;

  case 155:
#line 897 "bison_parser.y"
                          { (yyval.limit) = new LimitDescription((yyvsp[0].expr), nullptr); }
#line 4406 "bison_parser.cpp"
    break;

  case 156:
#line 898 "bison_parser.y"
              { (yyval.limit) = nullptr; }
#line 4412 "bison_parser.cpp"
    break;

  case 157:
#line 900 "bison_parser.y"
                       { (yyval.limit) = new LimitDescription((yyvsp[0].expr), nullptr); }
#line 4418 "bison_parser.cpp"
    break;

  case 158:
#line 901 "bison_parser.y"
              { (yyval.limit) = new LimitDescription(nullptr, (yyvsp[0].expr)); }
#line 4424 "bison_parser.cpp"
    break;

  case 159:
#line 902 "bison_parser.y"
                         { (yyval.limit) = new LimitDescription((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4430 "bison_parser.cpp"
    break;

  case 160:
#line 903 "bison_parser.y"
            { (yyval.limit) = new LimitDescription(nullptr, nullptr); }
#line 4436 "bison_parser.cpp"
    break;

  case 161:
#line 904 "bison_parser.y"
                        { (yyval.limit) = new LimitDescription(nullptr, (yyvsp[0].expr)); }
#line 4442 "bison_parser.cpp"
    break;

  case 162:
#line 905 "bison_parser.y"
              { (yyval.limit) = nullptr; }
#line 4448 "bison_parser.cpp"
    break;

  case 163:
#line 910 "bison_parser.y"
                       {
  (yyval.expr_vec) = new std::vector<Expr*>();
  (yyval.expr_vec)->push_back((yyvsp[0].expr));
}
#line 4457 "bison_parser.cpp"
    break;

  case 164:
#line 914 "bison_parser.y"
                           {
  (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr));
  (yyval.expr_vec) = (yyvsp[-2].expr_vec);
}
#line 4466 "bison_parser.cpp"
    break;

  case 165:
#line 919 "bison_parser.y"
                                { (yyval.expr_vec) = (yyvsp[0].expr_vec); }
#line 4472 "bison_parser.cpp"
    break;

  case 166:
#line 920 "bison_parser.y"
              { (yyval.expr_vec) = nullptr; }
#line 4478 "bison_parser.cpp"
    break;

  case 167:
#line 922 "bison_parser.y"
                         {
  (yyval.list_vec) = new std::vector<ValueList*>();
  (yyval.list_vec)->push_back((yyvsp[0].expr_vec));
}
#line 4487 "bison_parser.cpp"
    break;

  case 168:
#line 926 "bison_parser.y"
                             {
  (yyvsp[-2].list_vec)->push_back((yyvsp[0].expr_vec));
  (yyval.list_vec) = (yyvsp[-2].list_vec);
}
#line 4496 "bison_parser.cpp"
    break;

  case 169:
#line 931 "bison_parser.y"
                                 {
  (yyval.expr_vec) = (yyvsp[-1].expr_vec);
}
#line 4504 "bison_parser.cpp"
    break;

  case 170:
#line 935 "bison_parser.y"
                              {
  (yyval.expr_vec) = new std::vector<Expr*>();
  (yyval.expr_vec)->push_back((yyvsp[0].expr));
}
#line 4513 "bison_parser.cpp"
    break;

  case 171:
#line 939 "bison_parser.y"
                                  {
  (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr));
  (yyval.expr_vec) = (yyvsp[-2].expr_vec);
}
#line 4522 "bison_parser.cpp"
    break;

  case 172:
#line 944 "bison_parser.y"
                            {
  (yyval.expr) = (yyvsp[-1].expr);
  if ((yyvsp[0].alias_t)) {
    (yyval.expr)->alias = strdup((yyvsp[0].alias_t)->name);
    delete (yyvsp[0].alias_t);
  }
}
#line 4534 "bison_parser.cpp"
    break;

  case 178:
#line 954 "bison_parser.y"
                       { (yyval.expr) = (yyvsp[-1].expr); }
#line 4540 "bison_parser.cpp"
    break;

  case 188:
#line 956 "bison_parser.y"
                                         {
  (yyval.expr) = Expr::makeSelect((yyvsp[-1].select_stmt));
}
#line 4548 "bison_parser.cpp"
    break;

  case 191:
#line 962 "bison_parser.y"
                         { (yyval.expr) = Expr::makeOpUnary(kOpUnaryMinus, (yyvsp[0].expr)); }
#line 4554 "bison_parser.cpp"
    break;

  case 192:
#line 963 "bison_parser.y"
              { (yyval.expr) = Expr::makeOpUnary(kOpNot, (yyvsp[0].expr)); }
#line 4560 "bison_parser.cpp"
    break;

  case 193:
#line 964 "bison_parser.y"
                 { (yyval.expr) = Expr::makeOpUnary(kOpIsNull, (yyvsp[-1].expr)); }
#line 4566 "bison_parser.cpp"
    break;

  case 194:
#line 965 "bison_parser.y"
                  { (yyval.expr) = Expr::makeOpUnary(kOpIsNull, (yyvsp[-2].expr)); }
#line 4572 "bison_parser.cpp"
    break;

  case 195:
#line 966 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeOpUnary(kOpIsNull, (yyvsp[-3].expr))); }
#line 4578 "bison_parser.cpp"
    break;

  case 197:
#line 968 "bison_parser.y"
                                              { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpMinus, (yyvsp[0].expr)); }
#line 4584 "bison_parser.cpp"
    break;

  case 198:
#line 969 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpPlus, (yyvsp[0].expr)); }
#line 4590 "bison_parser.cpp"
    break;

  case 199:
#line 970 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpSlash, (yyvsp[0].expr)); }
#line 4596 "bison_parser.cpp"
    break;

  case 200:
#line 971 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpAsterisk, (yyvsp[0].expr)); }
#line 4602 "bison_parser.cpp"
    break;

  case 201:
#line 972 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpPercentage, (yyvsp[0].expr)); }
#line 4608 "bison_parser.cpp"
    break;

  case 202:
#line 973 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpCaret, (yyvsp[0].expr)); }
#line 4614 "bison_parser.cpp"
    break;

  case 203:
#line 974 "bison_parser.y"
                       { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpLike, (yyvsp[0].expr)); }
#line 4620 "bison_parser.cpp"
    break;

  case 204:
#line 975 "bison_parser.y"
                           { (yyval.expr) = Expr::makeOpBinary((yyvsp[-3].expr), kOpNotLike, (yyvsp[0].expr)); }
#line 4626 "bison_parser.cpp"
    break;

  case 205:
#line 976 "bison_parser.y"
                        { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpILike, (yyvsp[0].expr)); }
#line 4632 "bison_parser.cpp"
    break;

  case 206:
#line 977 "bison_parser.y"
                         { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpConcat, (yyvsp[0].expr)); }
#line 4638 "bison_parser.cpp"
    break;

  case 207:
#line 979 "bison_parser.y"
                           { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpAnd, (yyvsp[0].expr)); }
#line 4644 "bison_parser.cpp"
    break;

  case 208:
#line 980 "bison_parser.y"
               { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpOr, (yyvsp[0].expr)); }
#line 4650 "bison_parser.cpp"
    break;

  case 209:
#line 982 "bison_parser.y"
                                       { (yyval.expr) = Expr::makeInOperator((yyvsp[-4].expr), (yyvsp[-1].expr_vec)); }
#line 4656 "bison_parser.cpp"
    break;

  case 210:
#line 983 "bison_parser.y"
                                   { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeInOperator((yyvsp[-5].expr), (yyvsp[-1].expr_vec))); }
#line 4662 "bison_parser.cpp"
    break;

  case 211:
#line 984 "bison_parser.y"
                                     { (yyval.expr) = Expr::makeInOperator((yyvsp[-4].expr), (yyvsp[-1].select_stmt)); }
#line 4668 "bison_parser.cpp"
    break;

  case 212:
#line 985 "bison_parser.y"
                                         { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeInOperator((yyvsp[-5].expr), (yyvsp[-1].select_stmt))); }
#line 4674 "bison_parser.cpp"
    break;

  case 213:
#line 989 "bison_parser.y"
                                    { (yyval.expr) = Expr::makeCase((yyvsp[-2].expr), (yyvsp[-1].expr), nullptr); }
#line 4680 "bison_parser.cpp"
    break;

  case 214:
#line 990 "bison_parser.y"
                                    { (yyval.expr) = Expr::makeCase((yyvsp[-4].expr), (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 4686 "bison_parser.cpp"
    break;

  case 215:
#line 991 "bison_parser.y"
                     { (yyval.expr) = Expr::makeCase(nullptr, (yyvsp[-1].expr), nullptr); }
#line 4692 "bison_parser.cpp"
    break;

  case 216:
#line 992 "bison_parser.y"
                               { (yyval.expr) = Expr::makeCase(nullptr, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 4698 "bison_parser.cpp"
    break;

  case 217:
#line 994 "bison_parser.y"
                                { (yyval.expr) = Expr::makeCaseList(Expr::makeCaseListElement((yyvsp[-2].expr), (yyvsp[0].expr))); }
#line 4704 "bison_parser.cpp"
    break;

  case 218:
#line 995 "bison_parser.y"
                                { (yyval.expr) = Expr::caseListAppend((yyvsp[-4].expr), Expr::makeCaseListElement((yyvsp[-2].expr), (yyvsp[0].expr))); }
#line 4710 "bison_parser.cpp"
    break;

  case 219:
#line 997 "bison_parser.y"
                                             { (yyval.expr) = Expr::makeExists((yyvsp[-1].select_stmt)); }
#line 4716 "bison_parser.cpp"
    break;

  case 220:
#line 998 "bison_parser.y"
                                     { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeExists((yyvsp[-1].select_stmt))); }
#line 4722 "bison_parser.cpp"
    break;

  case 221:
#line 1000 "bison_parser.y"
                                { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpEquals, (yyvsp[0].expr)); }
#line 4728 "bison_parser.cpp"
    break;

  case 222:
#line 1001 "bison_parser.y"
                         { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpEquals, (yyvsp[0].expr)); }
#line 4734 "bison_parser.cpp"
    break;

  case 223:
#line 1002 "bison_parser.y"
                            { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpNotEquals, (yyvsp[0].expr)); }
#line 4740 "bison_parser.cpp"
    break;

  case 224:
#line 1003 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpLess, (yyvsp[0].expr)); }
#line 4746 "bison_parser.cpp"
    break;

  case 225:
#line 1004 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpGreater, (yyvsp[0].expr)); }
#line 4752 "bison_parser.cpp"
    break;

  case 226:
#line 1005 "bison_parser.y"
                         { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpLessEq, (yyvsp[0].expr)); }
#line 4758 "bison_parser.cpp"
    break;

  case 227:
#line 1006 "bison_parser.y"
                            { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpGreaterEq, (yyvsp[0].expr)); }
#line 4764 "bison_parser.cpp"
    break;

  case 228:
#line 1008 "bison_parser.y"
                                   { (yyval.expr) = Expr::makeFunctionRef((yyvsp[-2].sval), new std::vector<Expr*>(), false); }
#line 4770 "bison_parser.cpp"
    break;

  case 229:
#line 1009 "bison_parser.y"
                                            { (yyval.expr) = Expr::makeFunctionRef((yyvsp[-4].sval), (yyvsp[-1].expr_vec), (yyvsp[-2].bval)); }
#line 4776 "bison_parser.cpp"
    break;

  case 230:
#line 1011 "bison_parser.y"
                                                        { (yyval.expr) = Expr::makeExtract((yyvsp[-3].datetime_field), (yyvsp[-1].expr)); }
#line 4782 "bison_parser.cpp"
    break;

  case 231:
#line 1013 "bison_parser.y"
                                             { (yyval.expr) = Expr::makeCast((yyvsp[-3].expr), (yyvsp[-1].column_type_t)); }
#line 4788 "bison_parser.cpp"
    break;

  case 232:
#line 1015 "bison_parser.y"
                        { (yyval.datetime_field) = kDatetimeSecond; }
#line 4794 "bison_parser.cpp"
    break;

  case 233:
#line 1016 "bison_parser.y"
         { (yyval.datetime_field) = kDatetimeMinute; }
#line 4800 "bison_parser.cpp"
    break;

  case 234:
#line 1017 "bison_parser.y"
       { (yyval.datetime_field) = kDatetimeHour; }
#line 4806 "bison_parser.cpp"
    break;

  case 235:
#line 1018 "bison_parser.y"
      { (yyval.datetime_field) = kDatetimeDay; }
#line 4812 "bison_parser.cpp"
    break;

  case 236:
#line 1019 "bison_parser.y"
        { (yyval.datetime_field) = kDatetimeMonth; }
#line 4818 "bison_parser.cpp"
    break;

  case 237:
#line 1020 "bison_parser.y"
       { (yyval.datetime_field) = kDatetimeYear; }
#line 4824 "bison_parser.cpp"
    break;

  case 238:
#line 1022 "bison_parser.y"
                                { (yyval.datetime_field) = kDatetimeSecond; }
#line 4830 "bison_parser.cpp"
    break;

  case 239:
#line 1023 "bison_parser.y"
          { (yyval.datetime_field) = kDatetimeMinute; }
#line 4836 "bison_parser.cpp"
    break;

  case 240:
#line 1024 "bison_parser.y"
        { (yyval.datetime_field) = kDatetimeHour; }
#line 4842 "bison_parser.cpp"
    break;

  case 241:
#line 1025 "bison_parser.y"
       { (yyval.datetime_field) = kDatetimeDay; }
#line 4848 "bison_parser.cpp"
    break;

  case 242:
#line 1026 "bison_parser.y"
         { (yyval.datetime_field) = kDatetimeMonth; }
#line 4854 "bison_parser.cpp"
    break;

  case 243:
#line 1027 "bison_parser.y"
        { (yyval.datetime_field) = kDatetimeYear; }
#line 4860 "bison_parser.cpp"
    break;

  case 246:
#line 1031 "bison_parser.y"
                                     { (yyval.expr) = Expr::makeArray((yyvsp[-1].expr_vec)); }
#line 4866 "bison_parser.cpp"
    break;

  case 247:
#line 1033 "bison_parser.y"
                                          { (yyval.expr) = Expr::makeArrayIndex((yyvsp[-3].expr), (yyvsp[-1].expr)->ival); }
#line 4872 "bison_parser.cpp"
    break;

  case 248:
#line 1035 "bison_parser.y"
                                                   { (yyval.expr) = Expr::makeBetween((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4878 "bison_parser.cpp"
    break;

  case 249:
#line 1037 "bison_parser.y"
                         { (yyval.expr) = Expr::makeColumnRef((yyvsp[0].sval)); }
#line 4884 "bison_parser.cpp"
    break;

  case 250:
#line 1038 "bison_parser.y"
                            { (yyval.expr) = Expr::makeColumnRef((yyvsp[-2].sval), (yyvsp[0].sval)); }
#line 4890 "bison_parser.cpp"
    break;

  case 251:
#line 1039 "bison_parser.y"
      { (yyval.expr) = Expr::makeStar(); }
#line 4896 "bison_parser.cpp"
    break;

  case 252:
#line 1040 "bison_parser.y"
                     { (yyval.expr) = Expr::makeStar((yyvsp[-2].sval)); }
#line 4902 "bison_parser.cpp"
    break;

  case 267:
#line 1046 "bison_parser.y"
                               { (yyval.expr) = Expr::makeLiteral((yyvsp[0].fval)); }
#line 4908 "bison_parser.cpp"
    break;

  case 270:
#line 1050 "bison_parser.y"
                           {
  (yyvsp[0].expr)->ival = (yyvsp[0].expr)->ival * -1;
  (yyvsp[0].expr)->fval = (yyvsp[0].expr)->fval * -1;
  (yyval.expr) = (yyvsp[0].expr);
}
#line 4918 "bison_parser.cpp"
    break;

  case 271:
#line 1056 "bison_parser.y"
                        { (yyval.expr) = Expr::makeLiteral((yyvsp[0].sval)); }
#line 4924 "bison_parser.cpp"
    break;

  case 272:
#line 1058 "bison_parser.y"
                    { (yyval.expr) = Expr::makeLiteral(true); }
#line 4930 "bison_parser.cpp"
    break;

  case 273:
#line 1059 "bison_parser.y"
        { (yyval.expr) = Expr::makeLiteral(false); }
#line 4936 "bison_parser.cpp"
    break;

  case 274:
#line 1061 "bison_parser.y"
                       { (yyval.expr) = Expr::makeLiteral((yyvsp[0].fval)); }
#line 4942 "bison_parser.cpp"
    break;

  case 276:
#line 1064 "bison_parser.y"
                     { (yyval.expr) = Expr::makeLiteral((yyvsp[0].ival)); }
#line 4948 "bison_parser.cpp"
    break;

  case 277:
#line 1066 "bison_parser.y"
                    { (yyval.expr) = Expr::makeNullLiteral(); }
#line 4954 "bison_parser.cpp"
    break;

  case 278:
#line 1068 "bison_parser.y"
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
#line 4969 "bison_parser.cpp"
    break;

  case 279:
#line 1079 "bison_parser.y"
                                              {
  (yyval.expr) = Expr::makeIntervalLiteral((yyvsp[-1].expr)->ival, (yyvsp[0].datetime_field));
  delete (yyvsp[-1].expr);
}
#line 4978 "bison_parser.cpp"
    break;

  case 280:
#line 1083 "bison_parser.y"
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
#line 4994 "bison_parser.cpp"
    break;

  case 281:
#line 1094 "bison_parser.y"
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
#line 5030 "bison_parser.cpp"
    break;

  case 282:
#line 1126 "bison_parser.y"
                 {
  (yyval.expr) = Expr::makeParameter(yylloc.total_column);
  (yyval.expr)->ival2 = yyloc.param_list.size();
  yyloc.param_list.push_back((yyval.expr));
}
#line 5040 "bison_parser.cpp"
    break;

  case 284:
#line 1135 "bison_parser.y"
                                                                        {
  (yyvsp[-2].table_vec)->push_back((yyvsp[0].table));
  auto tbl = new TableRef(kTableCrossProduct);
  tbl->list = (yyvsp[-2].table_vec);
  (yyval.table) = tbl;
}
#line 5051 "bison_parser.cpp"
    break;

  case 288:
#line 1144 "bison_parser.y"
                                                                                     {
  auto tbl = new TableRef(kTableSelect);
  tbl->select = (yyvsp[-2].select_stmt);
  tbl->alias = (yyvsp[0].alias_t);
  (yyval.table) = tbl;
}
#line 5062 "bison_parser.cpp"
    break;

  case 289:
#line 1151 "bison_parser.y"
                                       {
  (yyval.table_vec) = new std::vector<TableRef*>();
  (yyval.table_vec)->push_back((yyvsp[0].table));
}
#line 5071 "bison_parser.cpp"
    break;

  case 290:
#line 1155 "bison_parser.y"
                                           {
  (yyvsp[-2].table_vec)->push_back((yyvsp[0].table));
  (yyval.table_vec) = (yyvsp[-2].table_vec);
}
#line 5080 "bison_parser.cpp"
    break;

  case 291:
#line 1160 "bison_parser.y"
                                            {
  auto tbl = new TableRef(kTableName);
  tbl->schema = (yyvsp[-1].table_name).schema;
  tbl->name = (yyvsp[-1].table_name).name;
  tbl->alias = (yyvsp[0].alias_t);
  (yyval.table) = tbl;
}
#line 5092 "bison_parser.cpp"
    break;

  case 292:
#line 1168 "bison_parser.y"
                                     {
  (yyval.table) = new TableRef(kTableName);
  (yyval.table)->schema = (yyvsp[0].table_name).schema;
  (yyval.table)->name = (yyvsp[0].table_name).name;
}
#line 5102 "bison_parser.cpp"
    break;

  case 293:
#line 1174 "bison_parser.y"
                        {
  (yyval.table_name).schema = nullptr;
  (yyval.table_name).name = (yyvsp[0].sval);
}
#line 5111 "bison_parser.cpp"
    break;

  case 294:
#line 1178 "bison_parser.y"
                            {
  (yyval.table_name).schema = (yyvsp[-2].sval);
  (yyval.table_name).name = (yyvsp[0].sval);
}
#line 5120 "bison_parser.cpp"
    break;

  case 295:
#line 1183 "bison_parser.y"
                            { (yyval.sval) = (yyvsp[0].sval); }
#line 5126 "bison_parser.cpp"
    break;

  case 296:
#line 1184 "bison_parser.y"
              { (yyval.sval) = nullptr; }
#line 5132 "bison_parser.cpp"
    break;

  case 298:
#line 1186 "bison_parser.y"
                                                            { (yyval.alias_t) = new Alias((yyvsp[-3].sval), (yyvsp[-1].str_vec)); }
#line 5138 "bison_parser.cpp"
    break;

  case 300:
#line 1188 "bison_parser.y"
                                            { (yyval.alias_t) = nullptr; }
#line 5144 "bison_parser.cpp"
    break;

  case 301:
#line 1190 "bison_parser.y"
                      { (yyval.alias_t) = new Alias((yyvsp[0].sval)); }
#line 5150 "bison_parser.cpp"
    break;

  case 302:
#line 1191 "bison_parser.y"
             { (yyval.alias_t) = new Alias((yyvsp[0].sval)); }
#line 5156 "bison_parser.cpp"
    break;

  case 304:
#line 1193 "bison_parser.y"
                                { (yyval.alias_t) = nullptr; }
#line 5162 "bison_parser.cpp"
    break;

  case 305:
#line 1199 "bison_parser.y"
                                             { (yyval.locking_clause_vec) = (yyvsp[0].locking_clause_vec); }
#line 5168 "bison_parser.cpp"
    break;

  case 306:
#line 1200 "bison_parser.y"
              { (yyval.locking_clause_vec) = nullptr; }
#line 5174 "bison_parser.cpp"
    break;

  case 307:
#line 1202 "bison_parser.y"
                                         {
  (yyval.locking_clause_vec) = new std::vector<LockingClause*>();
  (yyval.locking_clause_vec)->push_back((yyvsp[0].locking_t));
}
#line 5183 "bison_parser.cpp"
    break;

  case 308:
#line 1206 "bison_parser.y"
                                         {
  (yyvsp[-1].locking_clause_vec)->push_back((yyvsp[0].locking_t));
  (yyval.locking_clause_vec) = (yyvsp[-1].locking_clause_vec);
}
#line 5192 "bison_parser.cpp"
    break;

  case 309:
#line 1211 "bison_parser.y"
                                                       {
  (yyval.locking_t) = new LockingClause();
  (yyval.locking_t)->rowLockMode = (yyvsp[-1].lock_mode_t);
  (yyval.locking_t)->rowLockWaitPolicy = (yyvsp[0].lock_wait_policy_t);
  (yyval.locking_t)->tables = nullptr;
}
#line 5203 "bison_parser.cpp"
    break;

  case 310:
#line 1217 "bison_parser.y"
                                                           {
  (yyval.locking_t) = new LockingClause();
  (yyval.locking_t)->rowLockMode = (yyvsp[-3].lock_mode_t);
  (yyval.locking_t)->tables = (yyvsp[-1].str_vec);
  (yyval.locking_t)->rowLockWaitPolicy = (yyvsp[0].lock_wait_policy_t);
}
#line 5214 "bison_parser.cpp"
    break;

  case 311:
#line 1224 "bison_parser.y"
                       { (yyval.lock_mode_t) = RowLockMode::ForUpdate; }
#line 5220 "bison_parser.cpp"
    break;

  case 312:
#line 1225 "bison_parser.y"
                { (yyval.lock_mode_t) = RowLockMode::ForNoKeyUpdate; }
#line 5226 "bison_parser.cpp"
    break;

  case 313:
#line 1226 "bison_parser.y"
        { (yyval.lock_mode_t) = RowLockMode::ForShare; }
#line 5232 "bison_parser.cpp"
    break;

  case 314:
#line 1227 "bison_parser.y"
            { (yyval.lock_mode_t) = RowLockMode::ForKeyShare; }
#line 5238 "bison_parser.cpp"
    break;

  case 315:
#line 1229 "bison_parser.y"
                                  { (yyval.lock_wait_policy_t) = RowLockWaitPolicy::SkipLocked; }
#line 5244 "bison_parser.cpp"
    break;

  case 316:
#line 1230 "bison_parser.y"
         { (yyval.lock_wait_policy_t) = RowLockWaitPolicy::NoWait; }
#line 5250 "bison_parser.cpp"
    break;

  case 317:
#line 1231 "bison_parser.y"
              { (yyval.lock_wait_policy_t) = RowLockWaitPolicy::None; }
#line 5256 "bison_parser.cpp"
    break;

  case 319:
#line 1237 "bison_parser.y"
                                            { (yyval.with_description_vec) = nullptr; }
#line 5262 "bison_parser.cpp"
    break;

  case 320:
#line 1239 "bison_parser.y"
                                         { (yyval.with_description_vec) = (yyvsp[0].with_description_vec); }
#line 5268 "bison_parser.cpp"
    break;

  case 321:
#line 1241 "bison_parser.y"
                                         {
  (yyval.with_description_vec) = new std::vector<WithDescription*>();
  (yyval.with_description_vec)->push_back((yyvsp[0].with_description_t));
}
#line 5277 "bison_parser.cpp"
    break;

  case 322:
#line 1245 "bison_parser.y"
                                             {
  (yyvsp[-2].with_description_vec)->push_back((yyvsp[0].with_description_t));
  (yyval.with_description_vec) = (yyvsp[-2].with_description_vec);
}
#line 5286 "bison_parser.cpp"
    break;

  case 323:
#line 1250 "bison_parser.y"
                                                   {
  (yyval.with_description_t) = new WithDescription();
  (yyval.with_description_t)->alias = (yyvsp[-2].sval);
  (yyval.with_description_t)->select = (yyvsp[0].select_stmt);
}
#line 5296 "bison_parser.cpp"
    break;

  case 324:
#line 1260 "bison_parser.y"
                                                                     {
  (yyval.table) = new TableRef(kTableJoin);
  (yyval.table)->join = new JoinDefinition();
  (yyval.table)->join->type = kJoinNatural;
  (yyval.table)->join->left = (yyvsp[-3].table);
  (yyval.table)->join->right = (yyvsp[0].table);
}
#line 5308 "bison_parser.cpp"
    break;

  case 325:
#line 1267 "bison_parser.y"
                                                                         {
  (yyval.table) = new TableRef(kTableJoin);
  (yyval.table)->join = new JoinDefinition();
  (yyval.table)->join->type = (JoinType)(yyvsp[-4].join_type);
  (yyval.table)->join->left = (yyvsp[-5].table);
  (yyval.table)->join->right = (yyvsp[-2].table);
  (yyval.table)->join->condition = (yyvsp[0].expr);
}
#line 5321 "bison_parser.cpp"
    break;

  case 326:
#line 1275 "bison_parser.y"
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
#line 5341 "bison_parser.cpp"
    break;

  case 327:
#line 1291 "bison_parser.y"
                      { (yyval.join_type) = kJoinInner; }
#line 5347 "bison_parser.cpp"
    break;

  case 328:
#line 1292 "bison_parser.y"
             { (yyval.join_type) = kJoinLeft; }
#line 5353 "bison_parser.cpp"
    break;

  case 329:
#line 1293 "bison_parser.y"
       { (yyval.join_type) = kJoinLeft; }
#line 5359 "bison_parser.cpp"
    break;

  case 330:
#line 1294 "bison_parser.y"
              { (yyval.join_type) = kJoinRight; }
#line 5365 "bison_parser.cpp"
    break;

  case 331:
#line 1295 "bison_parser.y"
        { (yyval.join_type) = kJoinRight; }
#line 5371 "bison_parser.cpp"
    break;

  case 332:
#line 1296 "bison_parser.y"
             { (yyval.join_type) = kJoinFull; }
#line 5377 "bison_parser.cpp"
    break;

  case 333:
#line 1297 "bison_parser.y"
        { (yyval.join_type) = kJoinFull; }
#line 5383 "bison_parser.cpp"
    break;

  case 334:
#line 1298 "bison_parser.y"
       { (yyval.join_type) = kJoinFull; }
#line 5389 "bison_parser.cpp"
    break;

  case 335:
#line 1299 "bison_parser.y"
        { (yyval.join_type) = kJoinCross; }
#line 5395 "bison_parser.cpp"
    break;

  case 336:
#line 1300 "bison_parser.y"
                       { (yyval.join_type) = kJoinInner; }
#line 5401 "bison_parser.cpp"
    break;

  case 340:
#line 1311 "bison_parser.y"
                             {
  (yyval.str_vec) = new std::vector<char*>();
  (yyval.str_vec)->push_back((yyvsp[0].sval));
}
#line 5410 "bison_parser.cpp"
    break;

  case 341:
#line 1315 "bison_parser.y"
                                 {
  (yyvsp[-2].str_vec)->push_back((yyvsp[0].sval));
  (yyval.str_vec) = (yyvsp[-2].str_vec);
}
#line 5419 "bison_parser.cpp"
    break;


#line 5423 "bison_parser.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, result, scanner, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (&yylloc, result, scanner, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, result, scanner);
          yychar = YYEMPTY;
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp, yylsp, result, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, result, scanner, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
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
                  yystos[+*yyssp], yyvsp, yylsp, result, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1321 "bison_parser.y"

    // clang-format on
    /*********************************
 ** Section 4: Additional C code
 *********************************/

    /* empty */
