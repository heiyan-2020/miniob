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
    SQL_EQUALS = 417,
    SQL_NOTEQUALS = 418,
    SQL_LESS = 419,
    SQL_GREATER = 420,
    SQL_LESSEQ = 421,
    SQL_GREATEREQ = 422,
    SQL_NOTNULL = 423,
    SQL_UMINUS = 424
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

#line 427 "bison_parser.cpp"

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
#define YYFINAL  70
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   896

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  187
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  128
/* YYNRULES -- Number of rules.  */
#define YYNRULES  325
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  581

#define YYUNDEFTOK  2
#define YYMAXUTOK   424


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
       0,   305,   305,   324,   330,   337,   341,   345,   346,   347,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     364,   365,   367,   371,   376,   380,   390,   391,   392,   394,
     394,   400,   406,   408,   412,   423,   429,   436,   451,   456,
     457,   463,   475,   476,   481,   486,   497,   510,   522,   529,
     537,   546,   547,   549,   550,   552,   556,   561,   562,   564,
     571,   572,   573,   574,   575,   576,   577,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   593,   594,
     596,   597,   598,   600,   601,   603,   607,   612,   613,   614,
     615,   617,   618,   626,   632,   638,   644,   650,   651,   658,
     664,   666,   676,   683,   694,   701,   709,   710,   717,   724,
     728,   733,   743,   747,   751,   763,   763,   765,   766,   775,
     776,   778,   792,   804,   809,   813,   817,   822,   823,   825,
     835,   836,   838,   840,   841,   843,   845,   846,   848,   853,
     855,   856,   858,   859,   861,   865,   870,   872,   873,   874,
     878,   879,   881,   882,   883,   884,   885,   886,   891,   895,
     900,   901,   903,   907,   912,   916,   920,   925,   933,   933,
     933,   933,   933,   935,   936,   936,   936,   936,   936,   936,
     936,   936,   937,   937,   941,   941,   943,   944,   945,   946,
     947,   949,   949,   950,   951,   952,   953,   954,   955,   956,
     957,   958,   960,   961,   963,   964,   965,   966,   970,   971,
     972,   973,   975,   976,   978,   979,   981,   982,   983,   984,
     985,   986,   987,   989,   990,   992,   994,   996,   997,   998,
     999,  1000,  1001,  1003,  1004,  1005,  1006,  1007,  1008,  1010,
    1010,  1012,  1014,  1016,  1018,  1019,  1020,  1021,  1023,  1023,
    1023,  1023,  1023,  1023,  1023,  1025,  1027,  1028,  1030,  1031,
    1033,  1035,  1037,  1048,  1052,  1063,  1095,  1104,  1104,  1111,
    1111,  1113,  1113,  1120,  1124,  1129,  1137,  1143,  1147,  1152,
    1153,  1155,  1155,  1157,  1157,  1159,  1160,  1162,  1162,  1168,
    1169,  1171,  1175,  1180,  1186,  1193,  1194,  1195,  1196,  1198,
    1199,  1200,  1206,  1206,  1208,  1210,  1214,  1219,  1229,  1236,
    1244,  1260,  1261,  1262,  1263,  1264,  1265,  1266,  1267,  1268,
    1269,  1271,  1277,  1277,  1280,  1284
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
  "ROLLBACK", "NOWAIT", "SKIP", "LOCKED", "SHARE", "'='", "EQUALS",
  "NOTEQUALS", "'<'", "'>'", "LESS", "GREATER", "LESSEQ", "GREATEREQ",
  "NOTNULL", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "UMINUS", "'['",
  "']'", "'('", "')'", "'.'", "';'", "','", "'?'", "$accept", "input",
  "statement_list", "statement", "preparable_statement", "opt_hints",
  "hint_list", "hint", "transaction_statement", "opt_transaction_keyword",
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
     415,   416,    61,   417,   418,    60,    62,   419,   420,   421,
     422,   423,    43,    45,    42,    47,    37,    94,   424,    91,
      93,    40,    41,    46,    59,    44,    63
};
# endif

#define YYPACT_NINF (-371)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-323)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     657,    54,    89,   143,   171,    89,   -20,    81,    95,   120,
      89,   152,    89,    89,    -8,    26,   228,   110,   110,   110,
     249,    91,  -371,   166,  -371,   166,  -371,  -371,  -371,  -371,
    -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,   -32,  -371,
     285,   111,  -371,   112,   205,  -371,  -371,   183,   183,   229,
      89,   312,    89,   191,  -371,   201,   -35,  -371,   201,   201,
     201,    89,  -371,   222,   131,  -371,  -371,  -371,  -371,  -371,
    -371,   652,  -371,   233,  -371,  -371,   227,   -32,   114,  -371,
      76,  -371,   360,    31,   361,   243,    89,    89,   183,   292,
    -371,   294,   213,   393,   351,    89,   394,   394,   398,    89,
      89,  -371,   223,   228,  -371,   226,   397,   400,   232,   237,
    -371,  -371,  -371,   -32,   295,   284,   -32,     3,  -371,  -371,
    -371,  -371,   416,  -371,   417,  -371,  -371,  -371,   240,   241,
    -371,  -371,  -371,  -371,   718,  -371,  -371,  -371,  -371,  -371,
    -371,   381,   -52,   213,   425,   320,  -371,   394,   426,   130,
     272,   -49,  -371,  -371,   345,   325,  -371,   325,  -371,  -371,
    -371,  -371,  -371,   437,  -371,  -371,   320,  -371,  -371,   366,
    -371,  -371,   114,  -371,  -371,   320,   366,   320,   122,   326,
    -371,   216,  -371,    31,  -371,  -371,  -371,  -371,  -371,  -371,
    -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,
     444,   336,   173,   327,  -371,   319,   -17,   273,   275,   276,
     265,   427,   274,   455,  -371,   314,   -68,   481,  -371,  -371,
    -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,
    -371,  -371,  -371,  -371,   364,  -371,  -116,   282,  -371,   320,
     393,  -371,   428,  -371,  -371,   419,  -371,  -371,   288,   104,
    -371,   382,   293,  -371,    22,     3,   -32,   296,  -371,   -41,
       3,   -68,   422,    93,     4,  -371,   326,  -371,  -371,  -371,
     386,  -371,   697,   362,   299,   119,  -371,  -371,  -371,   336,
      89,    11,    17,   431,   216,   320,   320,   165,    79,   302,
     455,   717,   320,    77,   303,    45,   320,   320,   455,  -371,
     455,    33,   305,   108,   455,   455,   455,   455,   455,   455,
     455,   455,   455,   455,   455,   455,   455,   455,   455,   397,
      89,  -371,   487,    31,   306,  -371,   -68,  -371,   201,   312,
      31,  -371,   437,    16,   292,  -371,   320,  -371,   493,  -371,
    -371,  -371,  -371,   320,  -371,  -371,  -371,   326,   320,   320,
    -371,   323,   377,  -371,    57,  -371,   394,  -371,  -371,   318,
    -371,   324,  -371,  -371,   328,  -371,  -371,   329,  -371,  -371,
    -371,  -371,   330,  -371,  -371,   118,   332,   426,  -371,   173,
    -371,   333,  -371,   320,  -371,  -371,   322,   413,   -54,   147,
     127,   320,   320,  -371,   431,   407,  -130,  -371,  -371,  -371,
     401,   658,   391,   455,   337,   314,  -371,   415,   338,   391,
     391,   391,   391,   169,   169,   169,   169,    77,    77,   -98,
     -98,   -98,   -97,   341,  -371,  -371,   124,   282,   519,  -371,
     155,  -371,   336,  -371,   106,  -371,   339,  -371,    25,  -371,
     453,  -371,  -371,  -371,  -371,   -68,   -68,  -371,   462,   426,
    -371,   369,  -371,  -371,   520,   524,  -371,   526,   527,   528,
    -371,   418,  -371,  -371,   432,  -371,   118,  -371,   426,   167,
    -371,   426,   188,  -371,   320,   697,   320,   320,  -371,   170,
     151,   355,  -371,   455,   391,   314,   357,   189,  -371,  -371,
    -371,  -371,  -371,  -371,   359,   443,  -371,  -371,  -371,   466,
     467,   468,   448,    16,   546,  -371,  -371,  -371,   424,  -371,
    -371,  -102,  -371,   370,   195,   376,   387,   389,  -371,  -371,
    -371,   197,  -371,   199,  -371,    48,   390,   -68,   175,  -371,
     320,  -371,   717,   392,   206,  -371,  -371,    25,    16,  -371,
    -371,  -371,    16,   142,   399,   320,  -371,  -371,  -371,   545,
    -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,   -68,  -371,
    -371,  -371,  -371,   311,   426,   -27,   402,   404,   320,   210,
     320,  -371,  -371,    18,   -68,  -371,  -371,   -68,   403,   405,
    -371
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     303,     0,     0,     0,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    30,    30,    30,
       0,   323,     3,    21,    19,    21,    18,     8,     9,     7,
      11,    16,    17,    13,    14,    12,    15,    10,     0,   302,
       0,   277,   103,    33,     0,    44,    53,    52,    52,     0,
       0,     0,     0,     0,   276,    98,     0,    45,    98,    98,
      98,     0,    42,     0,   304,   305,    29,    26,    28,    27,
       1,   303,     2,     0,     6,     5,   151,     0,   112,   113,
     143,    95,     0,   161,     0,     0,     0,     0,    52,   137,
      37,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,    43,     0,     0,     4,     0,     0,   131,     0,     0,
     125,   126,   124,     0,   128,     0,     0,   157,   278,   255,
     258,   260,     0,   261,     0,   256,   257,   266,     0,   160,
     165,   248,   249,   250,   259,   251,   252,   253,   254,    32,
      31,     0,     0,   107,   280,     0,   102,     0,     0,     0,
       0,   137,   109,    97,     0,    40,    38,    40,    96,    93,
      94,   307,   306,     0,   150,   130,     0,   120,   119,   143,
     116,   115,   117,   127,   123,     0,   143,     0,     0,   290,
     262,   265,    34,     0,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   263,    51,
       0,   303,     0,     0,   279,     0,   244,     0,     0,     0,
       0,     0,     0,     0,   246,     0,   136,   168,   175,   176,
     177,   170,   172,   178,   171,   191,   179,   180,   181,   182,
     174,   169,   184,   185,     0,   324,     0,     0,   105,     0,
       0,   108,     0,    99,   100,     0,    36,    41,    24,     0,
      22,   134,   132,   158,   288,   157,     0,   142,   144,   149,
     157,   153,   155,   152,     0,   121,   289,   291,   264,   166,
       0,    48,     0,     0,     0,     0,    55,    57,    58,   303,
       0,   131,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   187,     0,   186,     0,     0,     0,     0,     0,   188,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   106,     0,     0,   104,   162,   111,   110,    98,     0,
       0,    20,     0,     0,   137,   133,     0,   286,     0,   287,
     167,   114,   118,     0,   148,   147,   146,   290,     0,     0,
     295,     0,     0,   297,   301,   292,     0,    76,    70,     0,
      72,    82,    73,    60,     0,    67,    68,     0,    64,    65,
      71,    74,    79,    69,    61,    84,     0,     0,    47,     0,
      50,     0,   223,     0,   245,   247,     0,     0,     0,     0,
       0,     0,     0,   210,     0,     0,     0,   183,   173,   202,
     203,     0,   198,     0,     0,     0,   189,     0,   201,   200,
     216,   217,   218,   219,   220,   221,   222,   193,   192,   195,
     194,   196,   197,     0,    35,   325,     0,     0,     0,    39,
       0,    23,   303,   135,   267,   269,     0,   271,   284,   270,
     139,   159,   285,   145,   122,   156,   154,   298,     0,     0,
     300,     0,   293,    46,     0,     0,    66,     0,     0,     0,
      75,     0,    88,    89,     0,    59,    83,    85,     0,     0,
      56,     0,     0,   214,     0,     0,     0,     0,   208,     0,
       0,     0,   241,     0,   199,     0,     0,     0,   190,   242,
     164,   163,   101,    25,     0,     0,   319,   311,   317,   315,
     318,   313,     0,     0,     0,   283,   275,   281,     0,   129,
     296,   301,   299,     0,     0,     0,     0,     0,    87,    90,
      86,     0,    92,     0,   224,     0,     0,   212,     0,   211,
       0,   215,   243,     0,     0,   206,   204,   284,     0,   314,
     316,   312,     0,   268,   285,     0,   294,    63,    81,     0,
      77,    62,    78,    91,    49,   225,   226,   209,   213,   207,
     205,   272,   308,   320,     0,   141,     0,     0,     0,     0,
       0,   138,    80,     0,   321,   309,   282,   140,   244,     0,
     310
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -371,  -371,  -371,   502,  -371,   550,  -371,   251,  -371,   137,
    -371,  -371,  -371,  -371,   252,   -93,   434,  -371,  -371,  -371,
      -4,  -371,  -371,   209,  -371,   117,  -371,  -371,  -371,  -371,
     123,  -371,  -371,   -51,  -371,  -371,  -371,  -371,  -371,  -371,
     450,  -371,  -371,   354,  -184,   -94,  -371,    -9,   -72,   -40,
    -371,  -371,   -70,   315,  -371,  -371,  -371,  -135,  -371,  -371,
      64,  -371,   254,  -371,  -371,   -10,  -261,  -371,  -371,   168,
     -63,   262,  -145,  -201,  -371,  -371,  -371,  -371,  -371,  -371,
     316,  -371,  -371,  -371,  -371,  -371,  -154,  -371,  -371,  -371,
    -371,  -371,    38,   -65,   -95,  -371,  -371,   -91,  -371,  -371,
    -371,  -371,  -371,  -370,    61,  -371,  -371,  -371,     1,  -371,
    -371,    67,   358,  -371,   267,  -371,   349,  -371,   105,  -371,
    -371,  -371,   516,  -371,  -371,  -371,  -371,  -329
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    20,    21,    22,    23,    74,   249,   250,    24,    67,
      25,   140,    26,    27,    91,   155,   246,    28,    29,    30,
      86,    49,   275,   276,   277,   375,   460,   456,   465,   466,
     467,   278,    31,    95,    32,   243,   244,    33,    34,    35,
     149,    36,   151,   152,    37,   169,   170,   171,    79,   113,
     114,   174,    80,   166,   251,   334,   335,   146,   509,   571,
     117,   257,   258,   346,   107,   179,   252,   128,   324,   325,
     129,   253,   254,   217,   218,   219,   220,   221,   222,   223,
     288,   224,   225,   226,   227,   228,   196,   197,   198,   229,
     230,   231,   232,   233,   131,   132,   133,   134,   135,   136,
     137,   138,   433,   434,   435,   436,   437,    53,   438,   205,
     505,   506,   507,   340,   265,   266,   267,   354,   452,    38,
      39,    64,    65,   439,   502,   575,    72,   236
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     216,   156,   156,    42,   157,   109,    45,    98,    99,   100,
     291,    54,   293,    56,    57,   164,   241,   271,   130,    41,
     384,   578,   176,   165,   570,   337,    76,   268,   337,    78,
     259,   396,   261,   263,   145,   119,   120,   121,   304,   304,
     116,    46,   200,   172,    87,    61,   172,   296,   469,   344,
     482,    89,   156,    92,   234,   336,   450,   451,   177,    96,
      47,   296,   101,    58,   297,   287,   321,   350,   108,   322,
     295,   475,    59,   201,   296,   345,   178,   238,   297,   318,
      40,   319,   319,   322,   144,   110,    62,   142,   143,   291,
      48,   297,    41,   161,   326,   380,   154,   401,    97,   402,
     159,   160,    60,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   269,   122,
     511,   111,   472,   110,   351,   206,   119,   120,   121,   202,
     387,   495,   256,   543,   403,   123,   240,   296,   352,   521,
     388,   389,   523,   294,   487,   461,    43,   338,   349,    77,
     504,   399,   400,   115,   297,    68,    69,   112,   336,   111,
     296,   404,   342,   296,   281,   353,   282,   495,   207,   208,
     209,   391,   563,   496,    44,    50,   272,   297,   497,   462,
     297,   124,   125,   126,   498,   499,   172,   449,    76,    51,
     392,   385,   214,   382,   237,   112,   393,   432,   259,   440,
     273,   500,   484,   445,   446,  -320,   501,   210,   296,   496,
     122,   386,   406,   304,   497,   450,   451,   127,    52,   477,
     498,   499,   463,   299,   534,   297,   123,   398,   423,   407,
     555,    63,    55,   255,   274,   569,   262,   500,   392,   464,
     260,  -320,   501,   211,   478,   341,   479,   480,   494,    70,
     347,   315,   316,   317,   318,   476,   319,   212,   130,   530,
     426,   156,   296,   453,    66,   130,   296,   430,   206,   119,
     120,   121,   124,   125,   126,    71,   286,   428,    73,   297,
     296,   381,   532,   297,   565,   296,   331,   529,    81,   332,
     296,  -273,   557,    83,    82,   213,   214,   297,   303,    84,
      88,   378,   297,   215,   379,   304,   490,   297,   127,   183,
      85,   207,   208,   209,    93,    90,   103,   206,   119,   120,
     121,   424,   481,   206,   119,   120,   121,  -274,    94,   525,
     105,   527,   528,   486,  -323,  -323,   495,   493,  -323,  -323,
     183,   313,   314,   315,   316,   317,   318,   102,   319,   522,
     210,   106,   322,   122,   184,   185,   186,   187,   188,   189,
     207,   208,   209,   118,   141,   139,   207,   208,   209,   123,
     524,   536,    76,   336,   336,   145,   286,   548,   496,   553,
     549,   554,   322,   497,   322,   558,   211,   147,   560,   498,
     499,   336,   576,   567,   148,   322,   150,   153,   119,   210,
     212,   158,   122,   121,    77,   210,   500,   163,   122,   173,
     175,   501,   165,   533,   167,   124,   125,   126,   123,   168,
     180,   181,   182,   574,   123,   577,   183,   199,   204,   235,
     206,   119,   120,   121,   239,   211,   242,   245,   213,   214,
     248,   211,   568,   115,   264,   299,   215,   270,    16,   212,
     280,   127,   279,   292,   283,   212,   284,   285,   206,   119,
     120,   121,   320,   323,   124,   125,   126,   328,   329,   330,
     124,   125,   126,   289,   208,   209,   333,   348,   336,   356,
     377,   343,   376,   394,   447,   397,   405,   213,   214,    76,
     425,   427,  -323,   213,   214,   215,   442,   448,   298,   454,
     127,   215,   208,   209,   473,   455,   127,   474,   403,   457,
     458,   459,   210,   468,   471,   122,   296,   319,   485,   488,
     303,   489,   492,   508,   503,   510,   513,   304,  -323,   512,
     514,   123,   515,   516,   517,   299,   519,   531,   518,   535,
     210,   537,   538,   122,   539,   540,   541,   542,   290,   544,
     545,   566,   547,  -323,  -323,  -323,   309,   310,   550,   123,
     311,   312,   212,   313,   314,   315,   316,   317,   318,   551,
     319,   552,   556,   104,   559,    75,   290,   124,   125,   126,
     564,   429,   300,   431,   572,   573,   282,   580,   470,   520,
     212,   247,   526,   203,   327,   491,   383,   443,   441,   562,
     213,   214,   301,   390,   561,   124,   125,   126,   215,   302,
     303,   579,   339,   127,   444,   355,   546,   304,   305,   162,
       0,     0,     0,     0,     0,     0,     0,     0,   213,   214,
       0,     0,     0,     0,     0,     0,   215,     0,     0,     0,
       0,   127,     0,   306,   307,   308,   309,   310,     0,     0,
     311,   312,  -322,   313,   314,   315,   316,   317,   318,     1,
     319,     0,     0,     0,     1,     0,     0,     2,     0,     0,
       0,     0,     2,     0,     3,     0,     0,     0,     4,     3,
       0,     0,     0,     4,     0,     0,     0,     0,     0,     5,
       0,     0,     6,     7,     5,     0,     0,     6,     7,     0,
       0,     0,     0,     0,     8,     9,     0,     0,   357,     8,
       9,     0,   299,     0,     0,    10,     0,     0,    11,     0,
      10,   358,     0,    11,     0,     0,   359,   360,   361,   362,
     363,     0,   364,     0,     0,     0,     0,     0,     0,    12,
     365,     0,    13,    14,    12,     0,     0,    13,    14,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,   300,
       0,     0,     0,    15,    16,     0,   366,     0,     0,    16,
       0,   299,     0,   483,     0,     0,     0,     0,     0,   395,
       0,     0,     0,   367,     0,   368,   369,   303,     0,     0,
       0,     0,     0,     0,   304,   305,     0,     0,     0,     0,
     370,     0,     0,     0,   371,     0,   372,    17,    18,    19,
       0,     0,    17,    18,    19,     0,   373,     0,   300,     0,
     306,   307,   308,   309,   310,     0,     0,   311,   312,     0,
     313,   314,   315,   316,   317,   318,     0,   319,   395,     0,
       0,     0,     0,     0,     0,     0,   303,     0,     0,     0,
     374,     0,     0,   304,   305,     0,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   306,
     307,   308,   309,   310,     0,     0,   311,   312,     0,   313,
     314,   315,   316,   317,   318,     0,   319
};

static const yytype_int16 yycheck[] =
{
     145,    96,    97,     2,    97,    77,     5,    58,    59,    60,
     211,    10,   213,    12,    13,   106,   151,   201,    83,     3,
       3,     3,   116,    12,    51,     3,    58,   181,     3,    38,
     175,   292,   177,   178,    83,     4,     5,     6,   136,   136,
      80,    61,    94,   113,    48,    19,   116,   115,   377,    90,
     180,    50,   147,    52,   147,   185,   158,   159,    55,    94,
      80,   115,    61,    71,   132,   210,   182,    63,    77,   185,
     215,   125,    80,   125,   115,   116,    73,   149,   132,   177,
      26,   179,   179,   185,    88,     9,    60,    86,    87,   290,
     110,   132,     3,   102,   239,   279,    95,   298,   133,   300,
      99,   100,   110,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   183,    88,
     449,    45,   383,     9,   120,     3,     4,     5,     6,   181,
     284,    25,   172,   503,   101,   104,   185,   115,   134,   468,
     285,   286,   471,   215,   405,    27,     3,   125,    55,   181,
     125,   296,   297,    77,   132,    18,    19,    81,   185,    45,
     115,   128,   256,   115,   181,   161,   183,    25,    46,    47,
      48,    92,   542,    67,     3,    94,     3,   132,    72,    61,
     132,   150,   151,   152,    78,    79,   256,   130,    58,    94,
     111,   174,   174,   182,    64,    81,   117,   181,   343,   334,
      27,    95,   403,   348,   349,    99,   100,    85,   115,    67,
      88,   283,   104,   136,    72,   158,   159,   186,    98,    92,
      78,    79,   104,    54,   485,   132,   104,   182,   319,   121,
     182,     3,    80,   169,    61,   564,   114,    95,   111,   121,
     176,    99,   100,   121,   117,   255,   391,   392,   432,     0,
     260,   174,   175,   176,   177,   108,   179,   135,   323,   108,
     323,   356,   115,   356,   154,   330,   115,   330,     3,     4,
       5,     6,   150,   151,   152,   184,   111,   328,   112,   132,
     115,   280,   483,   132,   545,   115,   182,   117,     3,   185,
     115,   185,   117,   181,   183,   173,   174,   132,   129,    94,
      71,   182,   132,   181,   185,   136,   182,   132,   186,   185,
     127,    46,    47,    48,   123,     3,   185,     3,     4,     5,
       6,   320,   394,     3,     4,     5,     6,   185,   127,   474,
      97,   476,   477,   405,   165,   166,    25,   182,   169,   170,
     185,   172,   173,   174,   175,   176,   177,   125,   179,   182,
      85,   124,   185,    88,   138,   139,   140,   141,   142,   143,
      46,    47,    48,     3,   121,     4,    46,    47,    48,   104,
     182,   182,    58,   185,   185,    83,   111,   182,    67,   182,
     185,   182,   185,    72,   185,   530,   121,    93,   182,    78,
      79,   185,   182,    82,   181,   185,     3,    46,     4,    85,
     135,     3,    88,     6,   181,    85,    95,   181,    88,   114,
     126,   100,    12,   485,   182,   150,   151,   152,   104,   182,
       4,     4,   182,   568,   104,   570,   185,    46,     3,     3,
       3,     4,     5,     6,   162,   121,    91,   112,   173,   174,
       3,   121,   131,    77,   118,    54,   181,     3,   112,   135,
     131,   186,   125,   179,   181,   135,   181,   181,     3,     4,
       5,     6,    98,   181,   150,   151,   152,    39,    49,   181,
     150,   151,   152,    46,    47,    48,    94,    55,   185,    93,
     181,   185,   120,   181,   161,   182,   181,   173,   174,    58,
       3,   185,   101,   173,   174,   181,     3,   120,    17,   181,
     186,   181,    47,    48,   182,   181,   186,    94,   101,   181,
     181,   181,    85,   181,   181,    88,   115,   179,   181,   104,
     129,   180,     3,    70,   185,    63,     6,   136,   137,   160,
       6,   104,     6,     6,     6,    54,   104,   182,   120,   182,
      85,   182,    99,    88,    78,    78,    78,    99,   121,     3,
     126,     6,   182,   162,   163,   164,   165,   166,   182,   104,
     169,   170,   135,   172,   173,   174,   175,   176,   177,   182,
     179,   182,   182,    71,   182,    25,   121,   150,   151,   152,
     181,   329,   101,   332,   182,   181,   183,   182,   379,   466,
     135,   157,   475,   143,   240,   427,   281,   343,   336,   538,
     173,   174,   121,   287,   537,   150,   151,   152,   181,   128,
     129,   573,   254,   186,   347,   266,   511,   136,   137,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   173,   174,
      -1,    -1,    -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,
      -1,   186,    -1,   162,   163,   164,   165,   166,    -1,    -1,
     169,   170,     0,   172,   173,   174,   175,   176,   177,     7,
     179,    -1,    -1,    -1,     7,    -1,    -1,    15,    -1,    -1,
      -1,    -1,    15,    -1,    22,    -1,    -1,    -1,    26,    22,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    -1,    40,    41,    37,    -1,    -1,    40,    41,    -1,
      -1,    -1,    -1,    -1,    52,    53,    -1,    -1,    11,    52,
      53,    -1,    54,    -1,    -1,    63,    -1,    -1,    66,    -1,
      63,    24,    -1,    66,    -1,    -1,    29,    30,    31,    32,
      33,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      43,    -1,    90,    91,    87,    -1,    -1,    90,    91,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,   101,
      -1,    -1,    -1,   106,   112,    -1,    69,    -1,    -1,   112,
      -1,    54,    -1,   115,    -1,    -1,    -1,    -1,    -1,   121,
      -1,    -1,    -1,    86,    -1,    88,    89,   129,    -1,    -1,
      -1,    -1,    -1,    -1,   136,   137,    -1,    -1,    -1,    -1,
     103,    -1,    -1,    -1,   107,    -1,   109,   155,   156,   157,
      -1,    -1,   155,   156,   157,    -1,   119,    -1,   101,    -1,
     162,   163,   164,   165,   166,    -1,    -1,   169,   170,    -1,
     172,   173,   174,   175,   176,   177,    -1,   179,   121,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,
     153,    -1,    -1,   136,   137,    -1,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,
     163,   164,   165,   166,    -1,    -1,   169,   170,    -1,   172,
     173,   174,   175,   176,   177,    -1,   179
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     7,    15,    22,    26,    37,    40,    41,    52,    53,
      63,    66,    87,    90,    91,   106,   112,   155,   156,   157,
     188,   189,   190,   191,   195,   197,   199,   200,   204,   205,
     206,   219,   221,   224,   225,   226,   228,   231,   306,   307,
      26,     3,   295,     3,     3,   295,    61,    80,   110,   208,
      94,    94,    98,   294,   295,    80,   295,   295,    71,    80,
     110,    19,    60,     3,   308,   309,   154,   196,   196,   196,
       0,   184,   313,   112,   192,   192,    58,   181,   234,   235,
     239,     3,   183,   181,    94,   127,   207,   207,    71,   295,
       3,   201,   295,   123,   127,   220,    94,   133,   220,   220,
     220,   295,   125,   185,   190,    97,   124,   251,   234,   235,
       9,    45,    81,   236,   237,    77,   236,   247,     3,     4,
       5,     6,    88,   104,   150,   151,   152,   186,   254,   257,
     280,   281,   282,   283,   284,   285,   286,   287,   288,     4,
     198,   121,   295,   295,   207,    83,   244,    93,   181,   227,
       3,   229,   230,    46,   295,   202,   281,   202,     3,   295,
     295,   234,   309,   181,   284,    12,   240,   182,   182,   232,
     233,   234,   239,   114,   238,   126,   232,    55,    73,   252,
       4,     4,   182,   185,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   273,   274,   275,    46,
      94,   125,   181,   227,     3,   296,     3,    46,    47,    48,
      85,   121,   135,   173,   174,   181,   259,   260,   261,   262,
     263,   264,   265,   266,   268,   269,   270,   271,   272,   276,
     277,   278,   279,   280,   202,     3,   314,    64,   235,   162,
     185,   244,    91,   222,   223,   112,   203,   203,     3,   193,
     194,   241,   253,   258,   259,   247,   236,   248,   249,   259,
     247,   259,   114,   259,   118,   301,   302,   303,   273,   280,
       3,   231,     3,    27,    61,   209,   210,   211,   218,   125,
     131,   181,   183,   181,   181,   181,   111,   259,   267,    46,
     121,   260,   179,   260,   235,   259,   115,   132,    17,    54,
     101,   121,   128,   129,   136,   137,   162,   163,   164,   165,
     166,   169,   170,   172,   173,   174,   175,   176,   177,   179,
      98,   182,   185,   181,   255,   256,   259,   230,    39,    49,
     181,   182,   185,    94,   242,   243,   185,     3,   125,   299,
     300,   252,   232,   185,    90,   116,   250,   252,    55,    55,
      63,   120,   134,   161,   304,   303,    93,    11,    24,    29,
      30,    31,    32,    33,    35,    43,    69,    86,    88,    89,
     103,   107,   109,   119,   153,   212,   120,   181,   182,   185,
     231,   295,   182,   240,     3,   174,   235,   273,   259,   259,
     267,    92,   111,   117,   181,   121,   253,   182,   182,   259,
     259,   260,   260,   101,   128,   181,   104,   121,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   284,   295,     3,   257,   185,   220,   201,
     257,   194,   181,   289,   290,   291,   292,   293,   295,   310,
     244,   258,     3,   249,   301,   259,   259,   161,   120,   130,
     158,   159,   305,   202,   181,   181,   214,   181,   181,   181,
     213,    27,    61,   104,   121,   215,   216,   217,   181,   314,
     210,   181,   253,   182,    94,   125,   108,    92,   117,   259,
     259,   235,   180,   115,   260,   181,   235,   253,   104,   180,
     182,   256,     3,   182,   231,    25,    67,    72,    78,    79,
      95,   100,   311,   185,   125,   297,   298,   299,    70,   245,
      63,   314,   160,     6,     6,     6,     6,     6,   120,   104,
     217,   314,   182,   314,   182,   259,   212,   259,   259,   117,
     108,   182,   260,   235,   253,   182,   182,   182,    99,    78,
      78,    78,    99,   290,     3,   126,   305,   182,   182,   185,
     182,   182,   182,   182,   182,   182,   182,   117,   259,   182,
     182,   298,   291,   290,   181,   253,     6,    82,   131,   314,
      51,   246,   182,   181,   259,   312,   182,   259,     3,   279,
     182
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
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
     254,   254,   255,   255,   256,   257,   257,   258,   259,   259,
     259,   259,   259,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   261,   261,   262,   262,   262,   262,
     262,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   264,   264,   265,   265,   265,   265,   266,   266,
     266,   266,   267,   267,   268,   268,   269,   269,   269,   269,
     269,   269,   269,   270,   270,   271,   272,   273,   273,   273,
     273,   273,   273,   274,   274,   274,   274,   274,   274,   275,
     275,   276,   277,   278,   279,   279,   279,   279,   280,   280,
     280,   280,   280,   280,   280,   281,   282,   282,   283,   283,
     284,   285,   286,   287,   287,   287,   288,   289,   289,   290,
     290,   291,   291,   292,   292,   293,   294,   295,   295,   296,
     296,   297,   297,   298,   298,   299,   299,   300,   300,   301,
     301,   302,   302,   303,   303,   304,   304,   304,   304,   305,
     305,   305,   306,   306,   307,   308,   308,   309,   310,   310,
     310,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   312,   313,   313,   314,   314
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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
       1,     4,     4,     2,     6,     5,     3,     0,     5,     1,
       3,     3,     2,     2,     6,     1,     1,     1,     3,     3,
       3,     4,     6,     2,     1,     1,     1,     1,     0,     7,
       1,     0,     1,     1,     0,     2,     2,     0,     4,     0,
       2,     0,     3,     0,     1,     3,     2,     1,     1,     0,
       2,     0,     2,     2,     4,     2,     4,     0,     1,     3,
       1,     0,     1,     3,     3,     1,     3,     2,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     2,     2,     2,     3,
       4,     1,     3,     3,     3,     3,     3,     3,     3,     4,
       3,     3,     3,     3,     5,     6,     5,     6,     4,     6,
       3,     5,     4,     5,     4,     5,     3,     3,     3,     3,
       3,     3,     3,     3,     5,     6,     6,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     5,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     3,     2,     1,     1,     3,     1,
       1,     1,     4,     1,     3,     2,     1,     1,     3,     1,
       0,     1,     5,     1,     0,     2,     1,     1,     0,     1,
       0,     1,     2,     3,     5,     1,     3,     1,     2,     2,
       1,     0,     1,     0,     2,     1,     3,     3,     4,     6,
       8,     1,     2,     1,     2,     1,     2,     1,     1,     1,
       0,     1,     1,     0,     1,     3
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
#line 168 "bison_parser.y"
                { free( (((*yyvaluep).sval)) ); }
#line 1983 "bison_parser.cpp"
        break;

    case 4: /* STRING  */
#line 168 "bison_parser.y"
                { free( (((*yyvaluep).sval)) ); }
#line 1989 "bison_parser.cpp"
        break;

    case 5: /* FLOATVAL  */
#line 166 "bison_parser.y"
                { }
#line 1995 "bison_parser.cpp"
        break;

    case 6: /* INTVAL  */
#line 166 "bison_parser.y"
                { }
#line 2001 "bison_parser.cpp"
        break;

    case 189: /* statement_list  */
#line 169 "bison_parser.y"
                {
      if ((((*yyvaluep).stmt_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).stmt_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).stmt_vec));
    }
#line 2014 "bison_parser.cpp"
        break;

    case 190: /* statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).statement)); }
#line 2020 "bison_parser.cpp"
        break;

    case 191: /* preparable_statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).statement)); }
#line 2026 "bison_parser.cpp"
        break;

    case 192: /* opt_hints  */
#line 169 "bison_parser.y"
                {
      if ((((*yyvaluep).expr_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).expr_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).expr_vec));
    }
#line 2039 "bison_parser.cpp"
        break;

    case 193: /* hint_list  */
#line 169 "bison_parser.y"
                {
      if ((((*yyvaluep).expr_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).expr_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).expr_vec));
    }
#line 2052 "bison_parser.cpp"
        break;

    case 194: /* hint  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2058 "bison_parser.cpp"
        break;

    case 195: /* transaction_statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).transaction_stmt)); }
#line 2064 "bison_parser.cpp"
        break;

    case 197: /* prepare_statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).prep_stmt)); }
#line 2070 "bison_parser.cpp"
        break;

    case 198: /* prepare_target_query  */
#line 168 "bison_parser.y"
                { free( (((*yyvaluep).sval)) ); }
#line 2076 "bison_parser.cpp"
        break;

    case 199: /* execute_statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).exec_stmt)); }
#line 2082 "bison_parser.cpp"
        break;

    case 200: /* import_statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).import_stmt)); }
#line 2088 "bison_parser.cpp"
        break;

    case 201: /* file_type  */
#line 166 "bison_parser.y"
                { }
#line 2094 "bison_parser.cpp"
        break;

    case 202: /* file_path  */
#line 168 "bison_parser.y"
                { free( (((*yyvaluep).sval)) ); }
#line 2100 "bison_parser.cpp"
        break;

    case 203: /* opt_file_type  */
#line 166 "bison_parser.y"
                { }
#line 2106 "bison_parser.cpp"
        break;

    case 204: /* export_statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).export_stmt)); }
#line 2112 "bison_parser.cpp"
        break;

    case 205: /* show_statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).show_stmt)); }
#line 2118 "bison_parser.cpp"
        break;

    case 206: /* create_statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).create_stmt)); }
#line 2124 "bison_parser.cpp"
        break;

    case 207: /* opt_not_exists  */
#line 166 "bison_parser.y"
                { }
#line 2130 "bison_parser.cpp"
        break;

    case 208: /* opt_unique  */
#line 166 "bison_parser.y"
                { }
#line 2136 "bison_parser.cpp"
        break;

    case 209: /* table_elem_commalist  */
#line 169 "bison_parser.y"
                {
      if ((((*yyvaluep).table_element_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).table_element_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).table_element_vec));
    }
#line 2149 "bison_parser.cpp"
        break;

    case 210: /* table_elem  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).table_element_t)); }
#line 2155 "bison_parser.cpp"
        break;

    case 211: /* column_def  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).column_t)); }
#line 2161 "bison_parser.cpp"
        break;

    case 212: /* column_type  */
#line 166 "bison_parser.y"
                { }
#line 2167 "bison_parser.cpp"
        break;

    case 213: /* opt_time_precision  */
#line 166 "bison_parser.y"
                { }
#line 2173 "bison_parser.cpp"
        break;

    case 214: /* opt_decimal_specification  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).ival_pair)); }
#line 2179 "bison_parser.cpp"
        break;

    case 215: /* opt_column_constraints  */
#line 166 "bison_parser.y"
                { }
#line 2185 "bison_parser.cpp"
        break;

    case 216: /* column_constraint_set  */
#line 166 "bison_parser.y"
                { }
#line 2191 "bison_parser.cpp"
        break;

    case 217: /* column_constraint  */
#line 166 "bison_parser.y"
                { }
#line 2197 "bison_parser.cpp"
        break;

    case 218: /* table_constraint  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).table_constraint_t)); }
#line 2203 "bison_parser.cpp"
        break;

    case 219: /* drop_statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).drop_stmt)); }
#line 2209 "bison_parser.cpp"
        break;

    case 220: /* opt_exists  */
#line 166 "bison_parser.y"
                { }
#line 2215 "bison_parser.cpp"
        break;

    case 221: /* alter_statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).alter_stmt)); }
#line 2221 "bison_parser.cpp"
        break;

    case 222: /* alter_action  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).alter_action_t)); }
#line 2227 "bison_parser.cpp"
        break;

    case 223: /* drop_action  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).drop_action_t)); }
#line 2233 "bison_parser.cpp"
        break;

    case 224: /* delete_statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).delete_stmt)); }
#line 2239 "bison_parser.cpp"
        break;

    case 225: /* truncate_statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).delete_stmt)); }
#line 2245 "bison_parser.cpp"
        break;

    case 226: /* insert_statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).insert_stmt)); }
#line 2251 "bison_parser.cpp"
        break;

    case 227: /* opt_column_list  */
#line 169 "bison_parser.y"
                {
      if ((((*yyvaluep).str_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).str_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).str_vec));
    }
#line 2264 "bison_parser.cpp"
        break;

    case 228: /* update_statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).update_stmt)); }
#line 2270 "bison_parser.cpp"
        break;

    case 229: /* update_clause_commalist  */
#line 169 "bison_parser.y"
                {
      if ((((*yyvaluep).update_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).update_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).update_vec));
    }
#line 2283 "bison_parser.cpp"
        break;

    case 230: /* update_clause  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).update_t)); }
#line 2289 "bison_parser.cpp"
        break;

    case 231: /* select_statement  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2295 "bison_parser.cpp"
        break;

    case 232: /* select_within_set_operation  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2301 "bison_parser.cpp"
        break;

    case 233: /* select_within_set_operation_no_parentheses  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2307 "bison_parser.cpp"
        break;

    case 234: /* select_with_paren  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2313 "bison_parser.cpp"
        break;

    case 235: /* select_no_paren  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2319 "bison_parser.cpp"
        break;

    case 236: /* set_operator  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).set_operator_t)); }
#line 2325 "bison_parser.cpp"
        break;

    case 237: /* set_type  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).set_operator_t)); }
#line 2331 "bison_parser.cpp"
        break;

    case 238: /* opt_all  */
#line 166 "bison_parser.y"
                { }
#line 2337 "bison_parser.cpp"
        break;

    case 239: /* select_clause  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2343 "bison_parser.cpp"
        break;

    case 240: /* opt_distinct  */
#line 166 "bison_parser.y"
                { }
#line 2349 "bison_parser.cpp"
        break;

    case 241: /* select_list  */
#line 169 "bison_parser.y"
                {
      if ((((*yyvaluep).expr_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).expr_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).expr_vec));
    }
#line 2362 "bison_parser.cpp"
        break;

    case 242: /* opt_from_clause  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2368 "bison_parser.cpp"
        break;

    case 243: /* from_clause  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2374 "bison_parser.cpp"
        break;

    case 244: /* opt_where  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2380 "bison_parser.cpp"
        break;

    case 245: /* opt_group  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).group_t)); }
#line 2386 "bison_parser.cpp"
        break;

    case 246: /* opt_having  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2392 "bison_parser.cpp"
        break;

    case 247: /* opt_order  */
#line 169 "bison_parser.y"
                {
      if ((((*yyvaluep).order_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).order_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).order_vec));
    }
#line 2405 "bison_parser.cpp"
        break;

    case 248: /* order_list  */
#line 169 "bison_parser.y"
                {
      if ((((*yyvaluep).order_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).order_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).order_vec));
    }
#line 2418 "bison_parser.cpp"
        break;

    case 249: /* order_desc  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).order)); }
#line 2424 "bison_parser.cpp"
        break;

    case 250: /* opt_order_type  */
#line 166 "bison_parser.y"
                { }
#line 2430 "bison_parser.cpp"
        break;

    case 251: /* opt_top  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).limit)); }
#line 2436 "bison_parser.cpp"
        break;

    case 252: /* opt_limit  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).limit)); }
#line 2442 "bison_parser.cpp"
        break;

    case 253: /* expr_list  */
#line 169 "bison_parser.y"
                {
      if ((((*yyvaluep).expr_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).expr_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).expr_vec));
    }
#line 2455 "bison_parser.cpp"
        break;

    case 254: /* opt_literal_list  */
#line 169 "bison_parser.y"
                {
      if ((((*yyvaluep).expr_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).expr_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).expr_vec));
    }
#line 2468 "bison_parser.cpp"
        break;

    case 255: /* list_of_list  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).list_vec)); }
#line 2474 "bison_parser.cpp"
        break;

    case 256: /* list_item  */
#line 169 "bison_parser.y"
                {
      if ((((*yyvaluep).expr_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).expr_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).expr_vec));
    }
#line 2487 "bison_parser.cpp"
        break;

    case 257: /* literal_list  */
#line 169 "bison_parser.y"
                {
      if ((((*yyvaluep).expr_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).expr_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).expr_vec));
    }
#line 2500 "bison_parser.cpp"
        break;

    case 258: /* expr_alias  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2506 "bison_parser.cpp"
        break;

    case 259: /* expr  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2512 "bison_parser.cpp"
        break;

    case 260: /* operand  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2518 "bison_parser.cpp"
        break;

    case 261: /* scalar_expr  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2524 "bison_parser.cpp"
        break;

    case 262: /* unary_expr  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2530 "bison_parser.cpp"
        break;

    case 263: /* binary_expr  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2536 "bison_parser.cpp"
        break;

    case 264: /* logic_expr  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2542 "bison_parser.cpp"
        break;

    case 265: /* in_expr  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2548 "bison_parser.cpp"
        break;

    case 266: /* case_expr  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2554 "bison_parser.cpp"
        break;

    case 267: /* case_list  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2560 "bison_parser.cpp"
        break;

    case 268: /* exists_expr  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2566 "bison_parser.cpp"
        break;

    case 269: /* comp_expr  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2572 "bison_parser.cpp"
        break;

    case 270: /* function_expr  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2578 "bison_parser.cpp"
        break;

    case 271: /* extract_expr  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2584 "bison_parser.cpp"
        break;

    case 272: /* cast_expr  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2590 "bison_parser.cpp"
        break;

    case 273: /* datetime_field  */
#line 166 "bison_parser.y"
                { }
#line 2596 "bison_parser.cpp"
        break;

    case 274: /* datetime_field_plural  */
#line 166 "bison_parser.y"
                { }
#line 2602 "bison_parser.cpp"
        break;

    case 275: /* duration_field  */
#line 166 "bison_parser.y"
                { }
#line 2608 "bison_parser.cpp"
        break;

    case 276: /* array_expr  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2614 "bison_parser.cpp"
        break;

    case 277: /* array_index  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2620 "bison_parser.cpp"
        break;

    case 278: /* between_expr  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2626 "bison_parser.cpp"
        break;

    case 279: /* column_name  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2632 "bison_parser.cpp"
        break;

    case 280: /* literal  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2638 "bison_parser.cpp"
        break;

    case 281: /* string_literal  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2644 "bison_parser.cpp"
        break;

    case 282: /* bool_literal  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2650 "bison_parser.cpp"
        break;

    case 283: /* num_literal  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2656 "bison_parser.cpp"
        break;

    case 284: /* int_literal  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2662 "bison_parser.cpp"
        break;

    case 285: /* null_literal  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2668 "bison_parser.cpp"
        break;

    case 286: /* date_literal  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2674 "bison_parser.cpp"
        break;

    case 287: /* interval_literal  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2680 "bison_parser.cpp"
        break;

    case 288: /* param_expr  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2686 "bison_parser.cpp"
        break;

    case 289: /* table_ref  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2692 "bison_parser.cpp"
        break;

    case 290: /* table_ref_atomic  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2698 "bison_parser.cpp"
        break;

    case 291: /* nonjoin_table_ref_atomic  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2704 "bison_parser.cpp"
        break;

    case 292: /* table_ref_commalist  */
#line 169 "bison_parser.y"
                {
      if ((((*yyvaluep).table_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).table_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).table_vec));
    }
#line 2717 "bison_parser.cpp"
        break;

    case 293: /* table_ref_name  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2723 "bison_parser.cpp"
        break;

    case 294: /* table_ref_name_no_alias  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2729 "bison_parser.cpp"
        break;

    case 295: /* table_name  */
#line 167 "bison_parser.y"
                { free( (((*yyvaluep).table_name).name) ); free( (((*yyvaluep).table_name).schema) ); }
#line 2735 "bison_parser.cpp"
        break;

    case 296: /* opt_index_name  */
#line 168 "bison_parser.y"
                { free( (((*yyvaluep).sval)) ); }
#line 2741 "bison_parser.cpp"
        break;

    case 297: /* table_alias  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).alias_t)); }
#line 2747 "bison_parser.cpp"
        break;

    case 298: /* opt_table_alias  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).alias_t)); }
#line 2753 "bison_parser.cpp"
        break;

    case 299: /* alias  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).alias_t)); }
#line 2759 "bison_parser.cpp"
        break;

    case 300: /* opt_alias  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).alias_t)); }
#line 2765 "bison_parser.cpp"
        break;

    case 301: /* opt_locking_clause  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).locking_clause_vec)); }
#line 2771 "bison_parser.cpp"
        break;

    case 302: /* opt_locking_clause_list  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).locking_clause_vec)); }
#line 2777 "bison_parser.cpp"
        break;

    case 303: /* locking_clause  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).locking_t)); }
#line 2783 "bison_parser.cpp"
        break;

    case 304: /* row_lock_mode  */
#line 166 "bison_parser.y"
                { }
#line 2789 "bison_parser.cpp"
        break;

    case 305: /* opt_row_lock_policy  */
#line 166 "bison_parser.y"
                { }
#line 2795 "bison_parser.cpp"
        break;

    case 306: /* opt_with_clause  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).with_description_vec)); }
#line 2801 "bison_parser.cpp"
        break;

    case 307: /* with_clause  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).with_description_vec)); }
#line 2807 "bison_parser.cpp"
        break;

    case 308: /* with_description_list  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).with_description_vec)); }
#line 2813 "bison_parser.cpp"
        break;

    case 309: /* with_description  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).with_description_t)); }
#line 2819 "bison_parser.cpp"
        break;

    case 310: /* join_clause  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2825 "bison_parser.cpp"
        break;

    case 311: /* opt_join_type  */
#line 166 "bison_parser.y"
                { }
#line 2831 "bison_parser.cpp"
        break;

    case 312: /* join_condition  */
#line 177 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2837 "bison_parser.cpp"
        break;

    case 314: /* ident_commalist  */
#line 169 "bison_parser.y"
                {
      if ((((*yyvaluep).str_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).str_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).str_vec));
    }
#line 2850 "bison_parser.cpp"
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

#line 2968 "bison_parser.cpp"

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
#line 305 "bison_parser.y"
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
#line 3183 "bison_parser.cpp"
    break;

  case 3:
#line 324 "bison_parser.y"
                           {
  (yyvsp[0].statement)->stringLength = yylloc.string_length;
  yylloc.string_length = 0;
  (yyval.stmt_vec) = new std::vector<SQLStatement*>();
  (yyval.stmt_vec)->push_back((yyvsp[0].statement));
}
#line 3194 "bison_parser.cpp"
    break;

  case 4:
#line 330 "bison_parser.y"
                               {
  (yyvsp[0].statement)->stringLength = yylloc.string_length;
  yylloc.string_length = 0;
  (yyvsp[-2].stmt_vec)->push_back((yyvsp[0].statement));
  (yyval.stmt_vec) = (yyvsp[-2].stmt_vec);
}
#line 3205 "bison_parser.cpp"
    break;

  case 5:
#line 337 "bison_parser.y"
                                        {
  (yyval.statement) = (yyvsp[-1].prep_stmt);
  (yyval.statement)->hints = (yyvsp[0].expr_vec);
}
#line 3214 "bison_parser.cpp"
    break;

  case 6:
#line 341 "bison_parser.y"
                                 {
  (yyval.statement) = (yyvsp[-1].statement);
  (yyval.statement)->hints = (yyvsp[0].expr_vec);
}
#line 3223 "bison_parser.cpp"
    break;

  case 7:
#line 345 "bison_parser.y"
                 { (yyval.statement) = (yyvsp[0].show_stmt); }
#line 3229 "bison_parser.cpp"
    break;

  case 8:
#line 346 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].import_stmt); }
#line 3235 "bison_parser.cpp"
    break;

  case 9:
#line 347 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].export_stmt); }
#line 3241 "bison_parser.cpp"
    break;

  case 10:
#line 349 "bison_parser.y"
                                        { (yyval.statement) = (yyvsp[0].select_stmt); }
#line 3247 "bison_parser.cpp"
    break;

  case 11:
#line 350 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].create_stmt); }
#line 3253 "bison_parser.cpp"
    break;

  case 12:
#line 351 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].insert_stmt); }
#line 3259 "bison_parser.cpp"
    break;

  case 13:
#line 352 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].delete_stmt); }
#line 3265 "bison_parser.cpp"
    break;

  case 14:
#line 353 "bison_parser.y"
                     { (yyval.statement) = (yyvsp[0].delete_stmt); }
#line 3271 "bison_parser.cpp"
    break;

  case 15:
#line 354 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].update_stmt); }
#line 3277 "bison_parser.cpp"
    break;

  case 16:
#line 355 "bison_parser.y"
                 { (yyval.statement) = (yyvsp[0].drop_stmt); }
#line 3283 "bison_parser.cpp"
    break;

  case 17:
#line 356 "bison_parser.y"
                  { (yyval.statement) = (yyvsp[0].alter_stmt); }
#line 3289 "bison_parser.cpp"
    break;

  case 18:
#line 357 "bison_parser.y"
                    { (yyval.statement) = (yyvsp[0].exec_stmt); }
#line 3295 "bison_parser.cpp"
    break;

  case 19:
#line 358 "bison_parser.y"
                        { (yyval.statement) = (yyvsp[0].transaction_stmt); }
#line 3301 "bison_parser.cpp"
    break;

  case 20:
#line 364 "bison_parser.y"
                                        { (yyval.expr_vec) = (yyvsp[-1].expr_vec); }
#line 3307 "bison_parser.cpp"
    break;

  case 21:
#line 365 "bison_parser.y"
              { (yyval.expr_vec) = nullptr; }
#line 3313 "bison_parser.cpp"
    break;

  case 22:
#line 367 "bison_parser.y"
                 {
  (yyval.expr_vec) = new std::vector<Expr*>();
  (yyval.expr_vec)->push_back((yyvsp[0].expr));
}
#line 3322 "bison_parser.cpp"
    break;

  case 23:
#line 371 "bison_parser.y"
                     {
  (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr));
  (yyval.expr_vec) = (yyvsp[-2].expr_vec);
}
#line 3331 "bison_parser.cpp"
    break;

  case 24:
#line 376 "bison_parser.y"
                  {
  (yyval.expr) = Expr::make(kExprHint);
  (yyval.expr)->name = (yyvsp[0].sval);
}
#line 3340 "bison_parser.cpp"
    break;

  case 25:
#line 380 "bison_parser.y"
                                  {
  (yyval.expr) = Expr::make(kExprHint);
  (yyval.expr)->name = (yyvsp[-3].sval);
  (yyval.expr)->exprList = (yyvsp[-1].expr_vec);
}
#line 3350 "bison_parser.cpp"
    break;

  case 26:
#line 390 "bison_parser.y"
                                                      { (yyval.transaction_stmt) = new TransactionStatement(kBeginTransaction); }
#line 3356 "bison_parser.cpp"
    break;

  case 27:
#line 391 "bison_parser.y"
                                   { (yyval.transaction_stmt) = new TransactionStatement(kRollbackTransaction); }
#line 3362 "bison_parser.cpp"
    break;

  case 28:
#line 392 "bison_parser.y"
                                 { (yyval.transaction_stmt) = new TransactionStatement(kCommitTransaction); }
#line 3368 "bison_parser.cpp"
    break;

  case 31:
#line 400 "bison_parser.y"
                                                                 {
  (yyval.prep_stmt) = new PrepareStatement();
  (yyval.prep_stmt)->name = (yyvsp[-2].sval);
  (yyval.prep_stmt)->query = (yyvsp[0].sval);
}
#line 3378 "bison_parser.cpp"
    break;

  case 33:
#line 408 "bison_parser.y"
                                                                  {
  (yyval.exec_stmt) = new ExecuteStatement();
  (yyval.exec_stmt)->name = (yyvsp[0].sval);
}
#line 3387 "bison_parser.cpp"
    break;

  case 34:
#line 412 "bison_parser.y"
                                              {
  (yyval.exec_stmt) = new ExecuteStatement();
  (yyval.exec_stmt)->name = (yyvsp[-3].sval);
  (yyval.exec_stmt)->parameters = (yyvsp[-1].expr_vec);
}
#line 3397 "bison_parser.cpp"
    break;

  case 35:
#line 423 "bison_parser.y"
                                                                        {
  (yyval.import_stmt) = new ImportStatement((yyvsp[-4].import_type_t));
  (yyval.import_stmt)->filePath = (yyvsp[-2].sval);
  (yyval.import_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.import_stmt)->tableName = (yyvsp[0].table_name).name;
}
#line 3408 "bison_parser.cpp"
    break;

  case 36:
#line 429 "bison_parser.y"
                                               {
  (yyval.import_stmt) = new ImportStatement((yyvsp[0].import_type_t));
  (yyval.import_stmt)->filePath = (yyvsp[-1].sval);
  (yyval.import_stmt)->schema = (yyvsp[-3].table_name).schema;
  (yyval.import_stmt)->tableName = (yyvsp[-3].table_name).name;
}
#line 3419 "bison_parser.cpp"
    break;

  case 37:
#line 436 "bison_parser.y"
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
#line 3438 "bison_parser.cpp"
    break;

  case 38:
#line 451 "bison_parser.y"
                           {
  (yyval.sval) = strdup((yyvsp[0].expr)->name);
  delete (yyvsp[0].expr);
}
#line 3447 "bison_parser.cpp"
    break;

  case 39:
#line 456 "bison_parser.y"
                                      { (yyval.import_type_t) = (yyvsp[0].import_type_t); }
#line 3453 "bison_parser.cpp"
    break;

  case 40:
#line 457 "bison_parser.y"
              { (yyval.import_type_t) = kImportAuto; }
#line 3459 "bison_parser.cpp"
    break;

  case 41:
#line 463 "bison_parser.y"
                                                              {
  (yyval.export_stmt) = new ExportStatement((yyvsp[0].import_type_t));
  (yyval.export_stmt)->filePath = (yyvsp[-1].sval);
  (yyval.export_stmt)->schema = (yyvsp[-3].table_name).schema;
  (yyval.export_stmt)->tableName = (yyvsp[-3].table_name).name;
}
#line 3470 "bison_parser.cpp"
    break;

  case 42:
#line 475 "bison_parser.y"
                             { (yyval.show_stmt) = new ShowStatement(kShowTables); }
#line 3476 "bison_parser.cpp"
    break;

  case 43:
#line 476 "bison_parser.y"
                          {
  (yyval.show_stmt) = new ShowStatement(kShowColumns);
  (yyval.show_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.show_stmt)->name = (yyvsp[0].table_name).name;
}
#line 3486 "bison_parser.cpp"
    break;

  case 44:
#line 481 "bison_parser.y"
                      {
  (yyval.show_stmt) = new ShowStatement(kShowColumns);
  (yyval.show_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.show_stmt)->name = (yyvsp[0].table_name).name;
}
#line 3496 "bison_parser.cpp"
    break;

  case 45:
#line 486 "bison_parser.y"
                  {
  (yyval.show_stmt) = new ShowStatement(kShowColumns);
  (yyval.show_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.show_stmt)->name = (yyvsp[0].table_name).name;
}
#line 3506 "bison_parser.cpp"
    break;

  case 46:
#line 497 "bison_parser.y"
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
#line 3524 "bison_parser.cpp"
    break;

  case 47:
#line 510 "bison_parser.y"
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
#line 3541 "bison_parser.cpp"
    break;

  case 48:
#line 522 "bison_parser.y"
                                                             {
  (yyval.create_stmt) = new CreateStatement(kCreateTable);
  (yyval.create_stmt)->ifNotExists = (yyvsp[-3].bval);
  (yyval.create_stmt)->schema = (yyvsp[-2].table_name).schema;
  (yyval.create_stmt)->tableName = (yyvsp[-2].table_name).name;
  (yyval.create_stmt)->select = (yyvsp[0].select_stmt);
}
#line 3553 "bison_parser.cpp"
    break;

  case 49:
#line 529 "bison_parser.y"
                                                                                              {
  (yyval.create_stmt) = new CreateStatement(kCreateIndex);
  (yyval.create_stmt)->indexName = (yyvsp[-5].sval);
  (yyval.create_stmt)->ifNotExists = (yyvsp[-6].bval);
  (yyval.create_stmt)->isUnique = (yyvsp[-8].bval);
  (yyval.create_stmt)->tableName = (yyvsp[-3].table_name).name;
  (yyval.create_stmt)->indexColumns = (yyvsp[-1].str_vec);
}
#line 3566 "bison_parser.cpp"
    break;

  case 50:
#line 537 "bison_parser.y"
                                                                            {
  (yyval.create_stmt) = new CreateStatement(kCreateView);
  (yyval.create_stmt)->ifNotExists = (yyvsp[-4].bval);
  (yyval.create_stmt)->schema = (yyvsp[-3].table_name).schema;
  (yyval.create_stmt)->tableName = (yyvsp[-3].table_name).name;
  (yyval.create_stmt)->viewColumns = (yyvsp[-2].str_vec);
  (yyval.create_stmt)->select = (yyvsp[0].select_stmt);
}
#line 3579 "bison_parser.cpp"
    break;

  case 51:
#line 546 "bison_parser.y"
                               { (yyval.bval) = true; }
#line 3585 "bison_parser.cpp"
    break;

  case 52:
#line 547 "bison_parser.y"
              { (yyval.bval) = false; }
#line 3591 "bison_parser.cpp"
    break;

  case 53:
#line 549 "bison_parser.y"
                   { (yyval.bval) = true; }
#line 3597 "bison_parser.cpp"
    break;

  case 54:
#line 550 "bison_parser.y"
              { (yyval.bval) = false; }
#line 3603 "bison_parser.cpp"
    break;

  case 55:
#line 552 "bison_parser.y"
                                  {
  (yyval.table_element_vec) = new std::vector<TableElement*>();
  (yyval.table_element_vec)->push_back((yyvsp[0].table_element_t));
}
#line 3612 "bison_parser.cpp"
    break;

  case 56:
#line 556 "bison_parser.y"
                                      {
  (yyvsp[-2].table_element_vec)->push_back((yyvsp[0].table_element_t));
  (yyval.table_element_vec) = (yyvsp[-2].table_element_vec);
}
#line 3621 "bison_parser.cpp"
    break;

  case 57:
#line 561 "bison_parser.y"
                        { (yyval.table_element_t) = (yyvsp[0].column_t); }
#line 3627 "bison_parser.cpp"
    break;

  case 58:
#line 562 "bison_parser.y"
                   { (yyval.table_element_t) = (yyvsp[0].table_constraint_t); }
#line 3633 "bison_parser.cpp"
    break;

  case 59:
#line 564 "bison_parser.y"
                                                           {
  (yyval.column_t) = new ColumnDefinition((yyvsp[-2].sval), (yyvsp[-1].column_type_t), (yyvsp[0].column_constraint_set));
  if (!(yyval.column_t)->trySetNullableExplicit()) {
    yyerror(&yyloc, result, scanner, ("Conflicting nullability constraints for " + std::string{(yyvsp[-2].sval)}).c_str());
  }
}
#line 3644 "bison_parser.cpp"
    break;

  case 60:
#line 571 "bison_parser.y"
                     { (yyval.column_type_t) = ColumnType{DataType::BIGINT}; }
#line 3650 "bison_parser.cpp"
    break;

  case 61:
#line 572 "bison_parser.y"
          { (yyval.column_type_t) = ColumnType{DataType::BOOLEAN}; }
#line 3656 "bison_parser.cpp"
    break;

  case 62:
#line 573 "bison_parser.y"
                      { (yyval.column_type_t) = ColumnType{DataType::CHAR, (yyvsp[-1].ival)}; }
#line 3662 "bison_parser.cpp"
    break;

  case 63:
#line 574 "bison_parser.y"
                                   { (yyval.column_type_t) = ColumnType{DataType::VARCHAR, (yyvsp[-1].ival)}; }
#line 3668 "bison_parser.cpp"
    break;

  case 64:
#line 575 "bison_parser.y"
       { (yyval.column_type_t) = ColumnType{DataType::DATE}; }
#line 3674 "bison_parser.cpp"
    break;

  case 65:
#line 576 "bison_parser.y"
           { (yyval.column_type_t) = ColumnType{DataType::DATETIME}; }
#line 3680 "bison_parser.cpp"
    break;

  case 66:
#line 577 "bison_parser.y"
                                    {
  (yyval.column_type_t) = ColumnType{DataType::DECIMAL, 0, (yyvsp[0].ival_pair)->first, (yyvsp[0].ival_pair)->second};
  delete (yyvsp[0].ival_pair);
}
#line 3689 "bison_parser.cpp"
    break;

  case 67:
#line 581 "bison_parser.y"
         { (yyval.column_type_t) = ColumnType{DataType::DOUBLE}; }
#line 3695 "bison_parser.cpp"
    break;

  case 68:
#line 582 "bison_parser.y"
        { (yyval.column_type_t) = ColumnType{DataType::FLOAT}; }
#line 3701 "bison_parser.cpp"
    break;

  case 69:
#line 583 "bison_parser.y"
      { (yyval.column_type_t) = ColumnType{DataType::INT}; }
#line 3707 "bison_parser.cpp"
    break;

  case 70:
#line 584 "bison_parser.y"
          { (yyval.column_type_t) = ColumnType{DataType::INT}; }
#line 3713 "bison_parser.cpp"
    break;

  case 71:
#line 585 "bison_parser.y"
       { (yyval.column_type_t) = ColumnType{DataType::LONG}; }
#line 3719 "bison_parser.cpp"
    break;

  case 72:
#line 586 "bison_parser.y"
       { (yyval.column_type_t) = ColumnType{DataType::REAL}; }
#line 3725 "bison_parser.cpp"
    break;

  case 73:
#line 587 "bison_parser.y"
           { (yyval.column_type_t) = ColumnType{DataType::SMALLINT}; }
#line 3731 "bison_parser.cpp"
    break;

  case 74:
#line 588 "bison_parser.y"
       { (yyval.column_type_t) = ColumnType{DataType::TEXT}; }
#line 3737 "bison_parser.cpp"
    break;

  case 75:
#line 589 "bison_parser.y"
                          { (yyval.column_type_t) = ColumnType{DataType::TIME, 0, (yyvsp[0].ival)}; }
#line 3743 "bison_parser.cpp"
    break;

  case 76:
#line 590 "bison_parser.y"
            { (yyval.column_type_t) = ColumnType{DataType::DATETIME}; }
#line 3749 "bison_parser.cpp"
    break;

  case 77:
#line 591 "bison_parser.y"
                         { (yyval.column_type_t) = ColumnType{DataType::VARCHAR, (yyvsp[-1].ival)}; }
#line 3755 "bison_parser.cpp"
    break;

  case 78:
#line 593 "bison_parser.y"
                                    { (yyval.ival) = (yyvsp[-1].ival); }
#line 3761 "bison_parser.cpp"
    break;

  case 79:
#line 594 "bison_parser.y"
              { (yyval.ival) = 0; }
#line 3767 "bison_parser.cpp"
    break;

  case 80:
#line 596 "bison_parser.y"
                                                      { (yyval.ival_pair) = new std::pair<int64_t, int64_t>{(yyvsp[-3].ival), (yyvsp[-1].ival)}; }
#line 3773 "bison_parser.cpp"
    break;

  case 81:
#line 597 "bison_parser.y"
                 { (yyval.ival_pair) = new std::pair<int64_t, int64_t>{(yyvsp[-1].ival), 0}; }
#line 3779 "bison_parser.cpp"
    break;

  case 82:
#line 598 "bison_parser.y"
              { (yyval.ival_pair) = new std::pair<int64_t, int64_t>{0, 0}; }
#line 3785 "bison_parser.cpp"
    break;

  case 83:
#line 600 "bison_parser.y"
                                               { (yyval.column_constraint_set) = (yyvsp[0].column_constraint_set); }
#line 3791 "bison_parser.cpp"
    break;

  case 84:
#line 601 "bison_parser.y"
              { (yyval.column_constraint_set) = new std::unordered_set<ConstraintType>(); }
#line 3797 "bison_parser.cpp"
    break;

  case 85:
#line 603 "bison_parser.y"
                                          {
  (yyval.column_constraint_set) = new std::unordered_set<ConstraintType>();
  (yyval.column_constraint_set)->insert((yyvsp[0].column_constraint_t));
}
#line 3806 "bison_parser.cpp"
    break;

  case 86:
#line 607 "bison_parser.y"
                                          {
  (yyvsp[-1].column_constraint_set)->insert((yyvsp[0].column_constraint_t));
  (yyval.column_constraint_set) = (yyvsp[-1].column_constraint_set);
}
#line 3815 "bison_parser.cpp"
    break;

  case 87:
#line 612 "bison_parser.y"
                                { (yyval.column_constraint_t) = ConstraintType::PrimaryKey; }
#line 3821 "bison_parser.cpp"
    break;

  case 88:
#line 613 "bison_parser.y"
         { (yyval.column_constraint_t) = ConstraintType::Unique; }
#line 3827 "bison_parser.cpp"
    break;

  case 89:
#line 614 "bison_parser.y"
       { (yyval.column_constraint_t) = ConstraintType::Null; }
#line 3833 "bison_parser.cpp"
    break;

  case 90:
#line 615 "bison_parser.y"
           { (yyval.column_constraint_t) = ConstraintType::NotNull; }
#line 3839 "bison_parser.cpp"
    break;

  case 91:
#line 617 "bison_parser.y"
                                                       { (yyval.table_constraint_t) = new TableConstraint(ConstraintType::PrimaryKey, (yyvsp[-1].str_vec)); }
#line 3845 "bison_parser.cpp"
    break;

  case 92:
#line 618 "bison_parser.y"
                                 { (yyval.table_constraint_t) = new TableConstraint(ConstraintType::Unique, (yyvsp[-1].str_vec)); }
#line 3851 "bison_parser.cpp"
    break;

  case 93:
#line 626 "bison_parser.y"
                                                  {
  (yyval.drop_stmt) = new DropStatement(kDropTable);
  (yyval.drop_stmt)->ifExists = (yyvsp[-1].bval);
  (yyval.drop_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.drop_stmt)->name = (yyvsp[0].table_name).name;
}
#line 3862 "bison_parser.cpp"
    break;

  case 94:
#line 632 "bison_parser.y"
                                  {
  (yyval.drop_stmt) = new DropStatement(kDropView);
  (yyval.drop_stmt)->ifExists = (yyvsp[-1].bval);
  (yyval.drop_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.drop_stmt)->name = (yyvsp[0].table_name).name;
}
#line 3873 "bison_parser.cpp"
    break;

  case 95:
#line 638 "bison_parser.y"
                                {
  (yyval.drop_stmt) = new DropStatement(kDropPreparedStatement);
  (yyval.drop_stmt)->ifExists = false;
  (yyval.drop_stmt)->name = (yyvsp[0].sval);
}
#line 3883 "bison_parser.cpp"
    break;

  case 96:
#line 644 "bison_parser.y"
                                   {
  (yyval.drop_stmt) = new DropStatement(kDropIndex);
  (yyval.drop_stmt)->ifExists = (yyvsp[-1].bval);
  (yyval.drop_stmt)->indexName = (yyvsp[0].sval);
}
#line 3893 "bison_parser.cpp"
    break;

  case 97:
#line 650 "bison_parser.y"
                       { (yyval.bval) = true; }
#line 3899 "bison_parser.cpp"
    break;

  case 98:
#line 651 "bison_parser.y"
              { (yyval.bval) = false; }
#line 3905 "bison_parser.cpp"
    break;

  case 99:
#line 658 "bison_parser.y"
                                                                 {
  (yyval.alter_stmt) = new AlterStatement((yyvsp[-1].table_name).name, (yyvsp[0].alter_action_t));
  (yyval.alter_stmt)->ifTableExists = (yyvsp[-2].bval);
  (yyval.alter_stmt)->schema = (yyvsp[-1].table_name).schema;
}
#line 3915 "bison_parser.cpp"
    break;

  case 100:
#line 664 "bison_parser.y"
                           { (yyval.alter_action_t) = (yyvsp[0].drop_action_t); }
#line 3921 "bison_parser.cpp"
    break;

  case 101:
#line 666 "bison_parser.y"
                                                {
  (yyval.drop_action_t) = new DropColumnAction((yyvsp[0].sval));
  (yyval.drop_action_t)->ifExists = (yyvsp[-1].bval);
}
#line 3930 "bison_parser.cpp"
    break;

  case 102:
#line 676 "bison_parser.y"
                                                    {
  (yyval.delete_stmt) = new DeleteStatement();
  (yyval.delete_stmt)->schema = (yyvsp[-1].table_name).schema;
  (yyval.delete_stmt)->tableName = (yyvsp[-1].table_name).name;
  (yyval.delete_stmt)->expr = (yyvsp[0].expr);
}
#line 3941 "bison_parser.cpp"
    break;

  case 103:
#line 683 "bison_parser.y"
                                         {
  (yyval.delete_stmt) = new DeleteStatement();
  (yyval.delete_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.delete_stmt)->tableName = (yyvsp[0].table_name).name;
}
#line 3951 "bison_parser.cpp"
    break;

  case 104:
#line 694 "bison_parser.y"
                                                                              {
  (yyval.insert_stmt) = new InsertStatement(kInsertValues);
  (yyval.insert_stmt)->schema = (yyvsp[-3].table_name).schema;
  (yyval.insert_stmt)->tableName = (yyvsp[-3].table_name).name;
  (yyval.insert_stmt)->columns = (yyvsp[-2].str_vec);
  (yyval.insert_stmt)->values = (yyvsp[0].list_vec);
}
#line 3963 "bison_parser.cpp"
    break;

  case 105:
#line 701 "bison_parser.y"
                                                         {
  (yyval.insert_stmt) = new InsertStatement(kInsertSelect);
  (yyval.insert_stmt)->schema = (yyvsp[-2].table_name).schema;
  (yyval.insert_stmt)->tableName = (yyvsp[-2].table_name).name;
  (yyval.insert_stmt)->columns = (yyvsp[-1].str_vec);
  (yyval.insert_stmt)->select = (yyvsp[0].select_stmt);
}
#line 3975 "bison_parser.cpp"
    break;

  case 106:
#line 709 "bison_parser.y"
                                          { (yyval.str_vec) = (yyvsp[-1].str_vec); }
#line 3981 "bison_parser.cpp"
    break;

  case 107:
#line 710 "bison_parser.y"
              { (yyval.str_vec) = nullptr; }
#line 3987 "bison_parser.cpp"
    break;

  case 108:
#line 717 "bison_parser.y"
                                                                                        {
  (yyval.update_stmt) = new UpdateStatement();
  (yyval.update_stmt)->table = (yyvsp[-3].table);
  (yyval.update_stmt)->updates = (yyvsp[-1].update_vec);
  (yyval.update_stmt)->where = (yyvsp[0].expr);
}
#line 3998 "bison_parser.cpp"
    break;

  case 109:
#line 724 "bison_parser.y"
                                        {
  (yyval.update_vec) = new std::vector<UpdateClause*>();
  (yyval.update_vec)->push_back((yyvsp[0].update_t));
}
#line 4007 "bison_parser.cpp"
    break;

  case 110:
#line 728 "bison_parser.y"
                                            {
  (yyvsp[-2].update_vec)->push_back((yyvsp[0].update_t));
  (yyval.update_vec) = (yyvsp[-2].update_vec);
}
#line 4016 "bison_parser.cpp"
    break;

  case 111:
#line 733 "bison_parser.y"
                                    {
  (yyval.update_t) = new UpdateClause();
  (yyval.update_t)->column = (yyvsp[-2].sval);
  (yyval.update_t)->value = (yyvsp[0].expr);
}
#line 4026 "bison_parser.cpp"
    break;

  case 112:
#line 743 "bison_parser.y"
                                                     {
  (yyval.select_stmt) = (yyvsp[0].select_stmt);
  (yyval.select_stmt)->withDescriptions = (yyvsp[-1].with_description_vec);
}
#line 4035 "bison_parser.cpp"
    break;

  case 113:
#line 747 "bison_parser.y"
                                  {
  (yyval.select_stmt) = (yyvsp[0].select_stmt);
  (yyval.select_stmt)->withDescriptions = (yyvsp[-1].with_description_vec);
}
#line 4044 "bison_parser.cpp"
    break;

  case 114:
#line 751 "bison_parser.y"
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
#line 4060 "bison_parser.cpp"
    break;

  case 117:
#line 765 "bison_parser.y"
                                                           { (yyval.select_stmt) = (yyvsp[0].select_stmt); }
#line 4066 "bison_parser.cpp"
    break;

  case 118:
#line 766 "bison_parser.y"
                                                         {
  (yyval.select_stmt) = (yyvsp[-2].select_stmt);
  if ((yyval.select_stmt)->setOperations == nullptr) {
    (yyval.select_stmt)->setOperations = new std::vector<SetOperation*>();
  }
  (yyval.select_stmt)->setOperations->push_back((yyvsp[-1].set_operator_t));
  (yyval.select_stmt)->setOperations->back()->nestedSelectStatement = (yyvsp[0].select_stmt);
}
#line 4079 "bison_parser.cpp"
    break;

  case 119:
#line 775 "bison_parser.y"
                                            { (yyval.select_stmt) = (yyvsp[-1].select_stmt); }
#line 4085 "bison_parser.cpp"
    break;

  case 120:
#line 776 "bison_parser.y"
                            { (yyval.select_stmt) = (yyvsp[-1].select_stmt); }
#line 4091 "bison_parser.cpp"
    break;

  case 121:
#line 778 "bison_parser.y"
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
#line 4110 "bison_parser.cpp"
    break;

  case 122:
#line 792 "bison_parser.y"
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
#line 4126 "bison_parser.cpp"
    break;

  case 123:
#line 804 "bison_parser.y"
                                {
  (yyval.set_operator_t) = (yyvsp[-1].set_operator_t);
  (yyval.set_operator_t)->isAll = (yyvsp[0].bval);
}
#line 4135 "bison_parser.cpp"
    break;

  case 124:
#line 809 "bison_parser.y"
                 {
  (yyval.set_operator_t) = new SetOperation();
  (yyval.set_operator_t)->setType = SetType::kSetUnion;
}
#line 4144 "bison_parser.cpp"
    break;

  case 125:
#line 813 "bison_parser.y"
            {
  (yyval.set_operator_t) = new SetOperation();
  (yyval.set_operator_t)->setType = SetType::kSetIntersect;
}
#line 4153 "bison_parser.cpp"
    break;

  case 126:
#line 817 "bison_parser.y"
         {
  (yyval.set_operator_t) = new SetOperation();
  (yyval.set_operator_t)->setType = SetType::kSetExcept;
}
#line 4162 "bison_parser.cpp"
    break;

  case 127:
#line 822 "bison_parser.y"
              { (yyval.bval) = true; }
#line 4168 "bison_parser.cpp"
    break;

  case 128:
#line 823 "bison_parser.y"
              { (yyval.bval) = false; }
#line 4174 "bison_parser.cpp"
    break;

  case 129:
#line 825 "bison_parser.y"
                                                                                            {
  (yyval.select_stmt) = new SelectStatement();
  (yyval.select_stmt)->limit = (yyvsp[-5].limit);
  (yyval.select_stmt)->selectDistinct = (yyvsp[-4].bval);
  (yyval.select_stmt)->selectList = (yyvsp[-3].expr_vec);
  (yyval.select_stmt)->fromTable = (yyvsp[-2].table);
  (yyval.select_stmt)->whereClause = (yyvsp[-1].expr);
  (yyval.select_stmt)->groupBy = (yyvsp[0].group_t);
}
#line 4188 "bison_parser.cpp"
    break;

  case 130:
#line 835 "bison_parser.y"
                        { (yyval.bval) = true; }
#line 4194 "bison_parser.cpp"
    break;

  case 131:
#line 836 "bison_parser.y"
              { (yyval.bval) = false; }
#line 4200 "bison_parser.cpp"
    break;

  case 133:
#line 840 "bison_parser.y"
                              { (yyval.table) = (yyvsp[0].table); }
#line 4206 "bison_parser.cpp"
    break;

  case 134:
#line 841 "bison_parser.y"
              { (yyval.table) = nullptr; }
#line 4212 "bison_parser.cpp"
    break;

  case 135:
#line 843 "bison_parser.y"
                             { (yyval.table) = (yyvsp[0].table); }
#line 4218 "bison_parser.cpp"
    break;

  case 136:
#line 845 "bison_parser.y"
                       { (yyval.expr) = (yyvsp[0].expr); }
#line 4224 "bison_parser.cpp"
    break;

  case 137:
#line 846 "bison_parser.y"
              { (yyval.expr) = nullptr; }
#line 4230 "bison_parser.cpp"
    break;

  case 138:
#line 848 "bison_parser.y"
                                          {
  (yyval.group_t) = new GroupByDescription();
  (yyval.group_t)->columns = (yyvsp[-1].expr_vec);
  (yyval.group_t)->having = (yyvsp[0].expr);
}
#line 4240 "bison_parser.cpp"
    break;

  case 139:
#line 853 "bison_parser.y"
              { (yyval.group_t) = nullptr; }
#line 4246 "bison_parser.cpp"
    break;

  case 140:
#line 855 "bison_parser.y"
                         { (yyval.expr) = (yyvsp[0].expr); }
#line 4252 "bison_parser.cpp"
    break;

  case 141:
#line 856 "bison_parser.y"
              { (yyval.expr) = nullptr; }
#line 4258 "bison_parser.cpp"
    break;

  case 142:
#line 858 "bison_parser.y"
                                { (yyval.order_vec) = (yyvsp[0].order_vec); }
#line 4264 "bison_parser.cpp"
    break;

  case 143:
#line 859 "bison_parser.y"
              { (yyval.order_vec) = nullptr; }
#line 4270 "bison_parser.cpp"
    break;

  case 144:
#line 861 "bison_parser.y"
                        {
  (yyval.order_vec) = new std::vector<OrderDescription*>();
  (yyval.order_vec)->push_back((yyvsp[0].order));
}
#line 4279 "bison_parser.cpp"
    break;

  case 145:
#line 865 "bison_parser.y"
                            {
  (yyvsp[-2].order_vec)->push_back((yyvsp[0].order));
  (yyval.order_vec) = (yyvsp[-2].order_vec);
}
#line 4288 "bison_parser.cpp"
    break;

  case 146:
#line 870 "bison_parser.y"
                                 { (yyval.order) = new OrderDescription((yyvsp[0].order_type), (yyvsp[-1].expr)); }
#line 4294 "bison_parser.cpp"
    break;

  case 147:
#line 872 "bison_parser.y"
                     { (yyval.order_type) = kOrderAsc; }
#line 4300 "bison_parser.cpp"
    break;

  case 148:
#line 873 "bison_parser.y"
       { (yyval.order_type) = kOrderDesc; }
#line 4306 "bison_parser.cpp"
    break;

  case 149:
#line 874 "bison_parser.y"
              { (yyval.order_type) = kOrderAsc; }
#line 4312 "bison_parser.cpp"
    break;

  case 150:
#line 878 "bison_parser.y"
                          { (yyval.limit) = new LimitDescription((yyvsp[0].expr), nullptr); }
#line 4318 "bison_parser.cpp"
    break;

  case 151:
#line 879 "bison_parser.y"
              { (yyval.limit) = nullptr; }
#line 4324 "bison_parser.cpp"
    break;

  case 152:
#line 881 "bison_parser.y"
                       { (yyval.limit) = new LimitDescription((yyvsp[0].expr), nullptr); }
#line 4330 "bison_parser.cpp"
    break;

  case 153:
#line 882 "bison_parser.y"
              { (yyval.limit) = new LimitDescription(nullptr, (yyvsp[0].expr)); }
#line 4336 "bison_parser.cpp"
    break;

  case 154:
#line 883 "bison_parser.y"
                         { (yyval.limit) = new LimitDescription((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4342 "bison_parser.cpp"
    break;

  case 155:
#line 884 "bison_parser.y"
            { (yyval.limit) = new LimitDescription(nullptr, nullptr); }
#line 4348 "bison_parser.cpp"
    break;

  case 156:
#line 885 "bison_parser.y"
                        { (yyval.limit) = new LimitDescription(nullptr, (yyvsp[0].expr)); }
#line 4354 "bison_parser.cpp"
    break;

  case 157:
#line 886 "bison_parser.y"
              { (yyval.limit) = nullptr; }
#line 4360 "bison_parser.cpp"
    break;

  case 158:
#line 891 "bison_parser.y"
                       {
  (yyval.expr_vec) = new std::vector<Expr*>();
  (yyval.expr_vec)->push_back((yyvsp[0].expr));
}
#line 4369 "bison_parser.cpp"
    break;

  case 159:
#line 895 "bison_parser.y"
                           {
  (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr));
  (yyval.expr_vec) = (yyvsp[-2].expr_vec);
}
#line 4378 "bison_parser.cpp"
    break;

  case 160:
#line 900 "bison_parser.y"
                                { (yyval.expr_vec) = (yyvsp[0].expr_vec); }
#line 4384 "bison_parser.cpp"
    break;

  case 161:
#line 901 "bison_parser.y"
              { (yyval.expr_vec) = nullptr; }
#line 4390 "bison_parser.cpp"
    break;

  case 162:
#line 903 "bison_parser.y"
                         {
  (yyval.list_vec) = new std::vector<ValueList*>();
  (yyval.list_vec)->push_back((yyvsp[0].expr_vec));
}
#line 4399 "bison_parser.cpp"
    break;

  case 163:
#line 907 "bison_parser.y"
                             {
  (yyvsp[-2].list_vec)->push_back((yyvsp[0].expr_vec));
  (yyval.list_vec) = (yyvsp[-2].list_vec);
}
#line 4408 "bison_parser.cpp"
    break;

  case 164:
#line 912 "bison_parser.y"
                                 {
  (yyval.expr_vec) = (yyvsp[-1].expr_vec);
}
#line 4416 "bison_parser.cpp"
    break;

  case 165:
#line 916 "bison_parser.y"
                       {
  (yyval.expr_vec) = new std::vector<Expr*>();
  (yyval.expr_vec)->push_back((yyvsp[0].expr));
}
#line 4425 "bison_parser.cpp"
    break;

  case 166:
#line 920 "bison_parser.y"
                           {
  (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr));
  (yyval.expr_vec) = (yyvsp[-2].expr_vec);
}
#line 4434 "bison_parser.cpp"
    break;

  case 167:
#line 925 "bison_parser.y"
                            {
  (yyval.expr) = (yyvsp[-1].expr);
  if ((yyvsp[0].alias_t)) {
    (yyval.expr)->alias = strdup((yyvsp[0].alias_t)->name);
    delete (yyvsp[0].alias_t);
  }
}
#line 4446 "bison_parser.cpp"
    break;

  case 173:
#line 935 "bison_parser.y"
                       { (yyval.expr) = (yyvsp[-1].expr); }
#line 4452 "bison_parser.cpp"
    break;

  case 183:
#line 937 "bison_parser.y"
                                         {
  (yyval.expr) = Expr::makeSelect((yyvsp[-1].select_stmt));
}
#line 4460 "bison_parser.cpp"
    break;

  case 186:
#line 943 "bison_parser.y"
                         { (yyval.expr) = Expr::makeOpUnary(kOpUnaryMinus, (yyvsp[0].expr)); }
#line 4466 "bison_parser.cpp"
    break;

  case 187:
#line 944 "bison_parser.y"
              { (yyval.expr) = Expr::makeOpUnary(kOpNot, (yyvsp[0].expr)); }
#line 4472 "bison_parser.cpp"
    break;

  case 188:
#line 945 "bison_parser.y"
                 { (yyval.expr) = Expr::makeOpUnary(kOpIsNull, (yyvsp[-1].expr)); }
#line 4478 "bison_parser.cpp"
    break;

  case 189:
#line 946 "bison_parser.y"
                  { (yyval.expr) = Expr::makeOpUnary(kOpIsNull, (yyvsp[-2].expr)); }
#line 4484 "bison_parser.cpp"
    break;

  case 190:
#line 947 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeOpUnary(kOpIsNull, (yyvsp[-3].expr))); }
#line 4490 "bison_parser.cpp"
    break;

  case 192:
#line 949 "bison_parser.y"
                                              { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpMinus, (yyvsp[0].expr)); }
#line 4496 "bison_parser.cpp"
    break;

  case 193:
#line 950 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpPlus, (yyvsp[0].expr)); }
#line 4502 "bison_parser.cpp"
    break;

  case 194:
#line 951 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpSlash, (yyvsp[0].expr)); }
#line 4508 "bison_parser.cpp"
    break;

  case 195:
#line 952 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpAsterisk, (yyvsp[0].expr)); }
#line 4514 "bison_parser.cpp"
    break;

  case 196:
#line 953 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpPercentage, (yyvsp[0].expr)); }
#line 4520 "bison_parser.cpp"
    break;

  case 197:
#line 954 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpCaret, (yyvsp[0].expr)); }
#line 4526 "bison_parser.cpp"
    break;

  case 198:
#line 955 "bison_parser.y"
                       { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpLike, (yyvsp[0].expr)); }
#line 4532 "bison_parser.cpp"
    break;

  case 199:
#line 956 "bison_parser.y"
                           { (yyval.expr) = Expr::makeOpBinary((yyvsp[-3].expr), kOpNotLike, (yyvsp[0].expr)); }
#line 4538 "bison_parser.cpp"
    break;

  case 200:
#line 957 "bison_parser.y"
                        { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpILike, (yyvsp[0].expr)); }
#line 4544 "bison_parser.cpp"
    break;

  case 201:
#line 958 "bison_parser.y"
                         { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpConcat, (yyvsp[0].expr)); }
#line 4550 "bison_parser.cpp"
    break;

  case 202:
#line 960 "bison_parser.y"
                           { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpAnd, (yyvsp[0].expr)); }
#line 4556 "bison_parser.cpp"
    break;

  case 203:
#line 961 "bison_parser.y"
               { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpOr, (yyvsp[0].expr)); }
#line 4562 "bison_parser.cpp"
    break;

  case 204:
#line 963 "bison_parser.y"
                                       { (yyval.expr) = Expr::makeInOperator((yyvsp[-4].expr), (yyvsp[-1].expr_vec)); }
#line 4568 "bison_parser.cpp"
    break;

  case 205:
#line 964 "bison_parser.y"
                                   { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeInOperator((yyvsp[-5].expr), (yyvsp[-1].expr_vec))); }
#line 4574 "bison_parser.cpp"
    break;

  case 206:
#line 965 "bison_parser.y"
                                     { (yyval.expr) = Expr::makeInOperator((yyvsp[-4].expr), (yyvsp[-1].select_stmt)); }
#line 4580 "bison_parser.cpp"
    break;

  case 207:
#line 966 "bison_parser.y"
                                         { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeInOperator((yyvsp[-5].expr), (yyvsp[-1].select_stmt))); }
#line 4586 "bison_parser.cpp"
    break;

  case 208:
#line 970 "bison_parser.y"
                                    { (yyval.expr) = Expr::makeCase((yyvsp[-2].expr), (yyvsp[-1].expr), nullptr); }
#line 4592 "bison_parser.cpp"
    break;

  case 209:
#line 971 "bison_parser.y"
                                    { (yyval.expr) = Expr::makeCase((yyvsp[-4].expr), (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 4598 "bison_parser.cpp"
    break;

  case 210:
#line 972 "bison_parser.y"
                     { (yyval.expr) = Expr::makeCase(nullptr, (yyvsp[-1].expr), nullptr); }
#line 4604 "bison_parser.cpp"
    break;

  case 211:
#line 973 "bison_parser.y"
                               { (yyval.expr) = Expr::makeCase(nullptr, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 4610 "bison_parser.cpp"
    break;

  case 212:
#line 975 "bison_parser.y"
                                { (yyval.expr) = Expr::makeCaseList(Expr::makeCaseListElement((yyvsp[-2].expr), (yyvsp[0].expr))); }
#line 4616 "bison_parser.cpp"
    break;

  case 213:
#line 976 "bison_parser.y"
                                { (yyval.expr) = Expr::caseListAppend((yyvsp[-4].expr), Expr::makeCaseListElement((yyvsp[-2].expr), (yyvsp[0].expr))); }
#line 4622 "bison_parser.cpp"
    break;

  case 214:
#line 978 "bison_parser.y"
                                             { (yyval.expr) = Expr::makeExists((yyvsp[-1].select_stmt)); }
#line 4628 "bison_parser.cpp"
    break;

  case 215:
#line 979 "bison_parser.y"
                                     { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeExists((yyvsp[-1].select_stmt))); }
#line 4634 "bison_parser.cpp"
    break;

  case 216:
#line 981 "bison_parser.y"
                                { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpEquals, (yyvsp[0].expr)); }
#line 4640 "bison_parser.cpp"
    break;

  case 217:
#line 982 "bison_parser.y"
                         { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpEquals, (yyvsp[0].expr)); }
#line 4646 "bison_parser.cpp"
    break;

  case 218:
#line 983 "bison_parser.y"
                            { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpNotEquals, (yyvsp[0].expr)); }
#line 4652 "bison_parser.cpp"
    break;

  case 219:
#line 984 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpLess, (yyvsp[0].expr)); }
#line 4658 "bison_parser.cpp"
    break;

  case 220:
#line 985 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpGreater, (yyvsp[0].expr)); }
#line 4664 "bison_parser.cpp"
    break;

  case 221:
#line 986 "bison_parser.y"
                         { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpLessEq, (yyvsp[0].expr)); }
#line 4670 "bison_parser.cpp"
    break;

  case 222:
#line 987 "bison_parser.y"
                            { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpGreaterEq, (yyvsp[0].expr)); }
#line 4676 "bison_parser.cpp"
    break;

  case 223:
#line 989 "bison_parser.y"
                                   { (yyval.expr) = Expr::makeFunctionRef((yyvsp[-2].sval), new std::vector<Expr*>(), false); }
#line 4682 "bison_parser.cpp"
    break;

  case 224:
#line 990 "bison_parser.y"
                                            { (yyval.expr) = Expr::makeFunctionRef((yyvsp[-4].sval), (yyvsp[-1].expr_vec), (yyvsp[-2].bval)); }
#line 4688 "bison_parser.cpp"
    break;

  case 225:
#line 992 "bison_parser.y"
                                                        { (yyval.expr) = Expr::makeExtract((yyvsp[-3].datetime_field), (yyvsp[-1].expr)); }
#line 4694 "bison_parser.cpp"
    break;

  case 226:
#line 994 "bison_parser.y"
                                             { (yyval.expr) = Expr::makeCast((yyvsp[-3].expr), (yyvsp[-1].column_type_t)); }
#line 4700 "bison_parser.cpp"
    break;

  case 227:
#line 996 "bison_parser.y"
                        { (yyval.datetime_field) = kDatetimeSecond; }
#line 4706 "bison_parser.cpp"
    break;

  case 228:
#line 997 "bison_parser.y"
         { (yyval.datetime_field) = kDatetimeMinute; }
#line 4712 "bison_parser.cpp"
    break;

  case 229:
#line 998 "bison_parser.y"
       { (yyval.datetime_field) = kDatetimeHour; }
#line 4718 "bison_parser.cpp"
    break;

  case 230:
#line 999 "bison_parser.y"
      { (yyval.datetime_field) = kDatetimeDay; }
#line 4724 "bison_parser.cpp"
    break;

  case 231:
#line 1000 "bison_parser.y"
        { (yyval.datetime_field) = kDatetimeMonth; }
#line 4730 "bison_parser.cpp"
    break;

  case 232:
#line 1001 "bison_parser.y"
       { (yyval.datetime_field) = kDatetimeYear; }
#line 4736 "bison_parser.cpp"
    break;

  case 233:
#line 1003 "bison_parser.y"
                                { (yyval.datetime_field) = kDatetimeSecond; }
#line 4742 "bison_parser.cpp"
    break;

  case 234:
#line 1004 "bison_parser.y"
          { (yyval.datetime_field) = kDatetimeMinute; }
#line 4748 "bison_parser.cpp"
    break;

  case 235:
#line 1005 "bison_parser.y"
        { (yyval.datetime_field) = kDatetimeHour; }
#line 4754 "bison_parser.cpp"
    break;

  case 236:
#line 1006 "bison_parser.y"
       { (yyval.datetime_field) = kDatetimeDay; }
#line 4760 "bison_parser.cpp"
    break;

  case 237:
#line 1007 "bison_parser.y"
         { (yyval.datetime_field) = kDatetimeMonth; }
#line 4766 "bison_parser.cpp"
    break;

  case 238:
#line 1008 "bison_parser.y"
        { (yyval.datetime_field) = kDatetimeYear; }
#line 4772 "bison_parser.cpp"
    break;

  case 241:
#line 1012 "bison_parser.y"
                                     { (yyval.expr) = Expr::makeArray((yyvsp[-1].expr_vec)); }
#line 4778 "bison_parser.cpp"
    break;

  case 242:
#line 1014 "bison_parser.y"
                                          { (yyval.expr) = Expr::makeArrayIndex((yyvsp[-3].expr), (yyvsp[-1].expr)->ival); }
#line 4784 "bison_parser.cpp"
    break;

  case 243:
#line 1016 "bison_parser.y"
                                                   { (yyval.expr) = Expr::makeBetween((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4790 "bison_parser.cpp"
    break;

  case 244:
#line 1018 "bison_parser.y"
                         { (yyval.expr) = Expr::makeColumnRef((yyvsp[0].sval)); }
#line 4796 "bison_parser.cpp"
    break;

  case 245:
#line 1019 "bison_parser.y"
                            { (yyval.expr) = Expr::makeColumnRef((yyvsp[-2].sval), (yyvsp[0].sval)); }
#line 4802 "bison_parser.cpp"
    break;

  case 246:
#line 1020 "bison_parser.y"
      { (yyval.expr) = Expr::makeStar(); }
#line 4808 "bison_parser.cpp"
    break;

  case 247:
#line 1021 "bison_parser.y"
                     { (yyval.expr) = Expr::makeStar((yyvsp[-2].sval)); }
#line 4814 "bison_parser.cpp"
    break;

  case 255:
#line 1025 "bison_parser.y"
                        { (yyval.expr) = Expr::makeLiteral((yyvsp[0].sval)); }
#line 4820 "bison_parser.cpp"
    break;

  case 256:
#line 1027 "bison_parser.y"
                    { (yyval.expr) = Expr::makeLiteral(true); }
#line 4826 "bison_parser.cpp"
    break;

  case 257:
#line 1028 "bison_parser.y"
        { (yyval.expr) = Expr::makeLiteral(false); }
#line 4832 "bison_parser.cpp"
    break;

  case 258:
#line 1030 "bison_parser.y"
                       { (yyval.expr) = Expr::makeLiteral((yyvsp[0].fval)); }
#line 4838 "bison_parser.cpp"
    break;

  case 260:
#line 1033 "bison_parser.y"
                     { (yyval.expr) = Expr::makeLiteral((yyvsp[0].ival)); }
#line 4844 "bison_parser.cpp"
    break;

  case 261:
#line 1035 "bison_parser.y"
                    { (yyval.expr) = Expr::makeNullLiteral(); }
#line 4850 "bison_parser.cpp"
    break;

  case 262:
#line 1037 "bison_parser.y"
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
#line 4865 "bison_parser.cpp"
    break;

  case 263:
#line 1048 "bison_parser.y"
                                              {
  (yyval.expr) = Expr::makeIntervalLiteral((yyvsp[-1].expr)->ival, (yyvsp[0].datetime_field));
  delete (yyvsp[-1].expr);
}
#line 4874 "bison_parser.cpp"
    break;

  case 264:
#line 1052 "bison_parser.y"
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
#line 4890 "bison_parser.cpp"
    break;

  case 265:
#line 1063 "bison_parser.y"
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
#line 4926 "bison_parser.cpp"
    break;

  case 266:
#line 1095 "bison_parser.y"
                 {
  (yyval.expr) = Expr::makeParameter(yylloc.total_column);
  (yyval.expr)->ival2 = yyloc.param_list.size();
  yyloc.param_list.push_back((yyval.expr));
}
#line 4936 "bison_parser.cpp"
    break;

  case 268:
#line 1104 "bison_parser.y"
                                                                        {
  (yyvsp[-2].table_vec)->push_back((yyvsp[0].table));
  auto tbl = new TableRef(kTableCrossProduct);
  tbl->list = (yyvsp[-2].table_vec);
  (yyval.table) = tbl;
}
#line 4947 "bison_parser.cpp"
    break;

  case 272:
#line 1113 "bison_parser.y"
                                                                                     {
  auto tbl = new TableRef(kTableSelect);
  tbl->select = (yyvsp[-2].select_stmt);
  tbl->alias = (yyvsp[0].alias_t);
  (yyval.table) = tbl;
}
#line 4958 "bison_parser.cpp"
    break;

  case 273:
#line 1120 "bison_parser.y"
                                       {
  (yyval.table_vec) = new std::vector<TableRef*>();
  (yyval.table_vec)->push_back((yyvsp[0].table));
}
#line 4967 "bison_parser.cpp"
    break;

  case 274:
#line 1124 "bison_parser.y"
                                           {
  (yyvsp[-2].table_vec)->push_back((yyvsp[0].table));
  (yyval.table_vec) = (yyvsp[-2].table_vec);
}
#line 4976 "bison_parser.cpp"
    break;

  case 275:
#line 1129 "bison_parser.y"
                                            {
  auto tbl = new TableRef(kTableName);
  tbl->schema = (yyvsp[-1].table_name).schema;
  tbl->name = (yyvsp[-1].table_name).name;
  tbl->alias = (yyvsp[0].alias_t);
  (yyval.table) = tbl;
}
#line 4988 "bison_parser.cpp"
    break;

  case 276:
#line 1137 "bison_parser.y"
                                     {
  (yyval.table) = new TableRef(kTableName);
  (yyval.table)->schema = (yyvsp[0].table_name).schema;
  (yyval.table)->name = (yyvsp[0].table_name).name;
}
#line 4998 "bison_parser.cpp"
    break;

  case 277:
#line 1143 "bison_parser.y"
                        {
  (yyval.table_name).schema = nullptr;
  (yyval.table_name).name = (yyvsp[0].sval);
}
#line 5007 "bison_parser.cpp"
    break;

  case 278:
#line 1147 "bison_parser.y"
                            {
  (yyval.table_name).schema = (yyvsp[-2].sval);
  (yyval.table_name).name = (yyvsp[0].sval);
}
#line 5016 "bison_parser.cpp"
    break;

  case 279:
#line 1152 "bison_parser.y"
                            { (yyval.sval) = (yyvsp[0].sval); }
#line 5022 "bison_parser.cpp"
    break;

  case 280:
#line 1153 "bison_parser.y"
              { (yyval.sval) = nullptr; }
#line 5028 "bison_parser.cpp"
    break;

  case 282:
#line 1155 "bison_parser.y"
                                                            { (yyval.alias_t) = new Alias((yyvsp[-3].sval), (yyvsp[-1].str_vec)); }
#line 5034 "bison_parser.cpp"
    break;

  case 284:
#line 1157 "bison_parser.y"
                                            { (yyval.alias_t) = nullptr; }
#line 5040 "bison_parser.cpp"
    break;

  case 285:
#line 1159 "bison_parser.y"
                      { (yyval.alias_t) = new Alias((yyvsp[0].sval)); }
#line 5046 "bison_parser.cpp"
    break;

  case 286:
#line 1160 "bison_parser.y"
             { (yyval.alias_t) = new Alias((yyvsp[0].sval)); }
#line 5052 "bison_parser.cpp"
    break;

  case 288:
#line 1162 "bison_parser.y"
                                { (yyval.alias_t) = nullptr; }
#line 5058 "bison_parser.cpp"
    break;

  case 289:
#line 1168 "bison_parser.y"
                                             { (yyval.locking_clause_vec) = (yyvsp[0].locking_clause_vec); }
#line 5064 "bison_parser.cpp"
    break;

  case 290:
#line 1169 "bison_parser.y"
              { (yyval.locking_clause_vec) = nullptr; }
#line 5070 "bison_parser.cpp"
    break;

  case 291:
#line 1171 "bison_parser.y"
                                         {
  (yyval.locking_clause_vec) = new std::vector<LockingClause*>();
  (yyval.locking_clause_vec)->push_back((yyvsp[0].locking_t));
}
#line 5079 "bison_parser.cpp"
    break;

  case 292:
#line 1175 "bison_parser.y"
                                         {
  (yyvsp[-1].locking_clause_vec)->push_back((yyvsp[0].locking_t));
  (yyval.locking_clause_vec) = (yyvsp[-1].locking_clause_vec);
}
#line 5088 "bison_parser.cpp"
    break;

  case 293:
#line 1180 "bison_parser.y"
                                                       {
  (yyval.locking_t) = new LockingClause();
  (yyval.locking_t)->rowLockMode = (yyvsp[-1].lock_mode_t);
  (yyval.locking_t)->rowLockWaitPolicy = (yyvsp[0].lock_wait_policy_t);
  (yyval.locking_t)->tables = nullptr;
}
#line 5099 "bison_parser.cpp"
    break;

  case 294:
#line 1186 "bison_parser.y"
                                                           {
  (yyval.locking_t) = new LockingClause();
  (yyval.locking_t)->rowLockMode = (yyvsp[-3].lock_mode_t);
  (yyval.locking_t)->tables = (yyvsp[-1].str_vec);
  (yyval.locking_t)->rowLockWaitPolicy = (yyvsp[0].lock_wait_policy_t);
}
#line 5110 "bison_parser.cpp"
    break;

  case 295:
#line 1193 "bison_parser.y"
                       { (yyval.lock_mode_t) = RowLockMode::ForUpdate; }
#line 5116 "bison_parser.cpp"
    break;

  case 296:
#line 1194 "bison_parser.y"
                { (yyval.lock_mode_t) = RowLockMode::ForNoKeyUpdate; }
#line 5122 "bison_parser.cpp"
    break;

  case 297:
#line 1195 "bison_parser.y"
        { (yyval.lock_mode_t) = RowLockMode::ForShare; }
#line 5128 "bison_parser.cpp"
    break;

  case 298:
#line 1196 "bison_parser.y"
            { (yyval.lock_mode_t) = RowLockMode::ForKeyShare; }
#line 5134 "bison_parser.cpp"
    break;

  case 299:
#line 1198 "bison_parser.y"
                                  { (yyval.lock_wait_policy_t) = RowLockWaitPolicy::SkipLocked; }
#line 5140 "bison_parser.cpp"
    break;

  case 300:
#line 1199 "bison_parser.y"
         { (yyval.lock_wait_policy_t) = RowLockWaitPolicy::NoWait; }
#line 5146 "bison_parser.cpp"
    break;

  case 301:
#line 1200 "bison_parser.y"
              { (yyval.lock_wait_policy_t) = RowLockWaitPolicy::None; }
#line 5152 "bison_parser.cpp"
    break;

  case 303:
#line 1206 "bison_parser.y"
                                            { (yyval.with_description_vec) = nullptr; }
#line 5158 "bison_parser.cpp"
    break;

  case 304:
#line 1208 "bison_parser.y"
                                         { (yyval.with_description_vec) = (yyvsp[0].with_description_vec); }
#line 5164 "bison_parser.cpp"
    break;

  case 305:
#line 1210 "bison_parser.y"
                                         {
  (yyval.with_description_vec) = new std::vector<WithDescription*>();
  (yyval.with_description_vec)->push_back((yyvsp[0].with_description_t));
}
#line 5173 "bison_parser.cpp"
    break;

  case 306:
#line 1214 "bison_parser.y"
                                             {
  (yyvsp[-2].with_description_vec)->push_back((yyvsp[0].with_description_t));
  (yyval.with_description_vec) = (yyvsp[-2].with_description_vec);
}
#line 5182 "bison_parser.cpp"
    break;

  case 307:
#line 1219 "bison_parser.y"
                                                   {
  (yyval.with_description_t) = new WithDescription();
  (yyval.with_description_t)->alias = (yyvsp[-2].sval);
  (yyval.with_description_t)->select = (yyvsp[0].select_stmt);
}
#line 5192 "bison_parser.cpp"
    break;

  case 308:
#line 1229 "bison_parser.y"
                                                                     {
  (yyval.table) = new TableRef(kTableJoin);
  (yyval.table)->join = new JoinDefinition();
  (yyval.table)->join->type = kJoinNatural;
  (yyval.table)->join->left = (yyvsp[-3].table);
  (yyval.table)->join->right = (yyvsp[0].table);
}
#line 5204 "bison_parser.cpp"
    break;

  case 309:
#line 1236 "bison_parser.y"
                                                                         {
  (yyval.table) = new TableRef(kTableJoin);
  (yyval.table)->join = new JoinDefinition();
  (yyval.table)->join->type = (JoinType)(yyvsp[-4].join_type);
  (yyval.table)->join->left = (yyvsp[-5].table);
  (yyval.table)->join->right = (yyvsp[-2].table);
  (yyval.table)->join->condition = (yyvsp[0].expr);
}
#line 5217 "bison_parser.cpp"
    break;

  case 310:
#line 1244 "bison_parser.y"
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
#line 5237 "bison_parser.cpp"
    break;

  case 311:
#line 1260 "bison_parser.y"
                      { (yyval.join_type) = kJoinInner; }
#line 5243 "bison_parser.cpp"
    break;

  case 312:
#line 1261 "bison_parser.y"
             { (yyval.join_type) = kJoinLeft; }
#line 5249 "bison_parser.cpp"
    break;

  case 313:
#line 1262 "bison_parser.y"
       { (yyval.join_type) = kJoinLeft; }
#line 5255 "bison_parser.cpp"
    break;

  case 314:
#line 1263 "bison_parser.y"
              { (yyval.join_type) = kJoinRight; }
#line 5261 "bison_parser.cpp"
    break;

  case 315:
#line 1264 "bison_parser.y"
        { (yyval.join_type) = kJoinRight; }
#line 5267 "bison_parser.cpp"
    break;

  case 316:
#line 1265 "bison_parser.y"
             { (yyval.join_type) = kJoinFull; }
#line 5273 "bison_parser.cpp"
    break;

  case 317:
#line 1266 "bison_parser.y"
        { (yyval.join_type) = kJoinFull; }
#line 5279 "bison_parser.cpp"
    break;

  case 318:
#line 1267 "bison_parser.y"
       { (yyval.join_type) = kJoinFull; }
#line 5285 "bison_parser.cpp"
    break;

  case 319:
#line 1268 "bison_parser.y"
        { (yyval.join_type) = kJoinCross; }
#line 5291 "bison_parser.cpp"
    break;

  case 320:
#line 1269 "bison_parser.y"
                       { (yyval.join_type) = kJoinInner; }
#line 5297 "bison_parser.cpp"
    break;

  case 324:
#line 1280 "bison_parser.y"
                             {
  (yyval.str_vec) = new std::vector<char*>();
  (yyval.str_vec)->push_back((yyvsp[0].sval));
}
#line 5306 "bison_parser.cpp"
    break;

  case 325:
#line 1284 "bison_parser.y"
                                 {
  (yyvsp[-2].str_vec)->push_back((yyvsp[0].sval));
  (yyval.str_vec) = (yyvsp[-2].str_vec);
}
#line 5315 "bison_parser.cpp"
    break;


#line 5319 "bison_parser.cpp"

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
#line 1290 "bison_parser.y"

    // clang-format on
    /*********************************
 ** Section 4: Additional C code
 *********************************/

    /* empty */
