/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "symtable.h"
extern int yylex(void);
extern int yylineno;
extern char *yytext;
int scope=0;
int funcDef=0;	//flag gia anoixto orismo sunarthshs (active vars)
int funCall=0;
int loop=0;
//node *last_func=malloc(sizeof(node));

#line 82 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER = 258,
    STRING = 259,
    WHILE = 260,
    FOR = 261,
    IF = 262,
    ELSE = 263,
    FUNCTION = 264,
    RETURN = 265,
    BREAK = 266,
    CONTINUE = 267,
    AND = 268,
    OR = 269,
    NOT = 270,
    LOCAL = 271,
    TRUE = 272,
    FALSE = 273,
    NIL = 274,
    PLUS = 275,
    MINUS = 276,
    MUL = 277,
    MOD = 278,
    DIV = 279,
    EQUALS = 280,
    N_EQL = 281,
    PLUSPLUS = 282,
    MINUSMINUS = 283,
    ID = 284,
    ASSIGN = 285,
    REALNUMBER = 286,
    GRTR_EQL = 287,
    LESS_EQL = 288,
    GRTR = 289,
    LESS = 290,
    L_BRACKET = 291,
    R_BRACKET = 292,
    L_BRACE = 293,
    R_BRACE = 294,
    L_PAR = 295,
    R_PAR = 296,
    COMMA = 297,
    SEMCOL = 298,
    COLON = 299,
    DOT = 300,
    DBL_DOT = 301,
    WRONG_DEFINITION = 302,
    GLOB = 303
  };
#endif
/* Tokens.  */
#define INTEGER 258
#define STRING 259
#define WHILE 260
#define FOR 261
#define IF 262
#define ELSE 263
#define FUNCTION 264
#define RETURN 265
#define BREAK 266
#define CONTINUE 267
#define AND 268
#define OR 269
#define NOT 270
#define LOCAL 271
#define TRUE 272
#define FALSE 273
#define NIL 274
#define PLUS 275
#define MINUS 276
#define MUL 277
#define MOD 278
#define DIV 279
#define EQUALS 280
#define N_EQL 281
#define PLUSPLUS 282
#define MINUSMINUS 283
#define ID 284
#define ASSIGN 285
#define REALNUMBER 286
#define GRTR_EQL 287
#define LESS_EQL 288
#define GRTR 289
#define LESS 290
#define L_BRACKET 291
#define R_BRACKET 292
#define L_BRACE 293
#define R_BRACE 294
#define L_PAR 295
#define R_PAR 296
#define COMMA 297
#define SEMCOL 298
#define COLON 299
#define DOT 300
#define DBL_DOT 301
#define WRONG_DEFINITION 302
#define GLOB 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 20 "parser.y" /* yacc.c:355  */

	int intval;
	char* strval;
	float realval;

#line 224 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 239 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  69
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   585

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  175

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    55,    55,    56,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    86,    91,
      92,    93,    94,    97,    97,   102,   105,   105,   111,   113,
     113,   120,   121,   122,   123,   124,   128,   182,   188,   213,
     215,   216,   217,   218,   220,   221,   222,   224,   225,   227,
     228,   229,   230,   231,   233,   234,   236,   237,   240,   241,
     260,   262,   263,   265,   265,   265,   266,   266,   267,   268,
     269,   270,   271,   272,   274,   284,   297,   299,   299,   300,
     302,   302,   303,   303,   304,   305
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "STRING", "WHILE", "FOR",
  "IF", "ELSE", "FUNCTION", "RETURN", "BREAK", "CONTINUE", "AND", "OR",
  "NOT", "LOCAL", "TRUE", "FALSE", "NIL", "PLUS", "MINUS", "MUL", "MOD",
  "DIV", "EQUALS", "N_EQL", "PLUSPLUS", "MINUSMINUS", "ID", "ASSIGN",
  "REALNUMBER", "GRTR_EQL", "LESS_EQL", "GRTR", "LESS", "L_BRACKET",
  "R_BRACKET", "L_BRACE", "R_BRACE", "L_PAR", "R_PAR", "COMMA", "SEMCOL",
  "COLON", "DOT", "DBL_DOT", "WRONG_DEFINITION", "GLOB", "$accept",
  "program", "stmt", "expr", "term", "$@1", "$@2", "assignexpr", "$@3",
  "primary", "lvalue", "member", "call", "callsuffix", "normcall",
  "methodcall", "elist", "objectdef", "indexed", "indexedelem", "temp_id",
  "temp_st", "block", "$@4", "$@5", "funcdef", "$@6", "const", "idlist",
  "ifstmt", "$@7", "whilestmt", "$@8", "forstmt", "$@9", "returnstmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

#define YYPACT_NINF -86

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-86)))

#define YYTABLE_NINF -40

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-40)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     102,   -86,   -86,   -37,   -27,    -9,   102,    13,     5,    11,
      15,   275,    33,   -86,   -86,   -86,   275,   -11,   -11,   -86,
     -86,   203,   -86,   241,   -86,    51,    44,   102,   312,   -86,
     -86,   -86,    19,   -86,    21,   -86,   -86,   -86,   -86,   -86,
     -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,
     328,   -86,   -86,   -86,   -86,    28,    74,   -30,    21,   -30,
     275,   502,   -12,     1,   -86,   -86,   360,    49,   -86,   -86,
     -86,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   -86,   275,   275,    64,    72,    77,
      94,    96,   -86,   -86,   -86,   275,   275,    99,   275,   275,
     275,    92,   -86,    98,   296,   -86,   275,   -86,   105,   165,
     -86,    97,   534,   518,    28,    28,   -86,   -86,   -86,   550,
     550,    65,    65,    65,    65,   452,   -14,   -86,   107,   -86,
     -86,   275,   477,    -2,   -86,   383,    73,   406,   130,    97,
     275,   502,   -86,   -86,   -86,   275,   -86,   -86,   275,   502,
     -86,   -86,   102,   275,   102,   -86,    83,   429,   -86,    93,
     110,   -86,   344,   -86,   122,   132,   -86,   -86,   -86,   275,
     -86,   -86,   112,   102,   -86
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    78,    80,     0,     0,     0,     0,    70,     0,     0,
       0,     0,     0,    82,    83,    81,     0,     0,     0,    46,
      79,    63,    73,     0,    13,     0,     0,     3,     0,    28,
      14,    38,    41,    49,    42,    43,    11,    12,    45,     5,
       6,     7,     8,    90,    92,    87,    89,    69,    76,    94,
       0,     9,    10,    31,    48,    30,     0,    32,     0,    35,
       0,    61,     0,     0,    66,    72,     0,     0,    47,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     4,     0,    63,     0,     0,     0,
       0,     0,    55,    57,    58,     0,    63,     0,     0,    63,
       0,     0,    95,     0,     0,    64,     0,    65,     0,     0,
      29,    44,    26,    27,    15,    16,    17,    19,    18,    24,
      25,    21,    23,    20,    22,     0,     0,    50,     0,    34,
      37,     0,     0,     0,    52,     0,     0,     0,    86,     0,
       0,    62,    67,    74,    71,    63,    51,    59,    63,    40,
      53,    54,     0,     0,     0,    84,     0,     0,    75,     0,
       0,    91,     0,    88,     0,     0,    68,    56,    60,    63,
      77,    85,     0,     0,    93
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -86,   135,    -6,    -4,   -86,   -86,   -86,   -86,   -86,   -86,
     138,   -86,   140,   -86,   -86,   -86,   -85,   -86,   -86,    55,
     -86,   -86,     0,   -86,   -86,   -21,   -86,   -86,   -86,   -86,
     -86,   -86,   -86,   -86,   -86,   -86
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    26,    27,    28,    29,    89,    90,    30,    91,    31,
      32,    33,    34,    92,    93,    94,    62,    35,    63,    64,
      48,   109,    36,    65,   158,    37,   101,    38,   156,    39,
     100,    40,    98,    41,    99,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      46,   126,    67,    43,    50,    12,    85,    53,     1,     2,
      86,   133,    55,    44,   136,    87,    88,    61,    19,    66,
      11,    12,    13,    14,    15,   105,    16,   147,   106,    56,
     106,    45,    17,    18,    19,   103,    20,    25,   107,   151,
     106,    21,    47,   108,    69,    23,   -33,   -36,    49,   -39,
      75,    76,    77,    25,    51,    85,   104,    95,    52,    86,
     159,    96,    54,   160,    87,    88,    97,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      68,   125,    61,     7,   172,    73,    74,    75,    76,    77,
     111,   132,    61,   127,   135,    61,   137,   -40,   -40,   -40,
     -40,   128,   141,   144,   129,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,   106,   153,    11,    12,    13,
      14,    15,   130,    16,   164,   165,   131,   149,   134,    17,
      18,    19,   138,    20,   167,   106,   157,   145,    21,   139,
      22,    61,    23,    60,    61,    24,   161,   148,   163,   162,
      25,   168,   106,   173,   106,    57,    59,    58,    58,   155,
      22,   171,    70,   142,   170,    61,     0,   174,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,     0,     0,
      11,    12,    13,    14,    15,     0,    16,     0,     0,     0,
       0,     0,    17,    18,    19,     0,    20,     0,     0,     0,
       0,    21,     0,    22,   143,    23,     1,     2,    24,     0,
       0,     0,     0,    25,     0,     0,     0,     0,    11,    12,
      13,    14,    15,     0,    16,     0,     0,     0,     0,     0,
      17,    18,    19,     0,    20,     0,     0,     0,     0,    21,
       0,    60,     0,    23,     1,     2,     0,     0,     0,     0,
       7,    25,     0,     0,     0,     0,    11,    12,    13,    14,
      15,     0,    16,     0,     0,     0,     0,     0,    17,    18,
      19,     0,    20,     0,     0,     0,     0,    21,     1,     2,
       0,    23,     0,     0,     0,     0,     0,     0,     0,    25,
      11,    12,    13,    14,    15,     0,    16,     0,     0,     0,
       0,     0,    17,    18,    19,     0,    20,     0,     0,    71,
      72,    21,     0,     0,     0,    23,    73,    74,    75,    76,
      77,    78,    79,    25,     0,    71,    72,     0,    80,    81,
      82,    83,    73,    74,    75,    76,    77,    78,    79,     0,
     140,    71,    72,     0,    80,    81,    82,    83,    73,    74,
      75,    76,    77,    78,    79,    84,     0,    71,    72,     0,
      80,    81,    82,    83,    73,    74,    75,    76,    77,    78,
      79,   102,     0,    71,    72,     0,    80,    81,    82,    83,
      73,    74,    75,    76,    77,    78,    79,   169,     0,     0,
       0,     0,    80,    81,    82,    83,    71,    72,     0,     0,
       0,   110,     0,    73,    74,    75,    76,    77,    78,    79,
       0,     0,     0,     0,     0,    80,    81,    82,    83,    71,
      72,     0,     0,     0,   152,     0,    73,    74,    75,    76,
      77,    78,    79,     0,     0,     0,     0,     0,    80,    81,
      82,    83,    71,    72,     0,     0,     0,   154,     0,    73,
      74,    75,    76,    77,    78,    79,     0,     0,     0,     0,
       0,    80,    81,    82,    83,    71,    72,     0,   166,     0,
       0,     0,    73,    74,    75,    76,    77,    78,    79,     0,
       0,     0,     0,     0,    80,    81,    82,    83,     0,   146,
      71,    72,     0,     0,     0,     0,     0,    73,    74,    75,
      76,    77,    78,    79,     0,     0,     0,     0,     0,    80,
      81,    82,    83,     0,   150,    71,    72,     0,     0,     0,
       0,     0,    73,    74,    75,    76,    77,    78,    79,     0,
       0,    71,     0,     0,    80,    81,    82,    83,    73,    74,
      75,    76,    77,    78,    79,     0,     0,     0,     0,     0,
      80,    81,    82,    83,    73,    74,    75,    76,    77,    78,
      79,     0,     0,     0,     0,     0,    80,    81,    82,    83,
      73,    74,    75,    76,    77,   -40,   -40,     0,     0,     0,
       0,     0,    80,    81,    82,    83
};

static const yytype_int16 yycheck[] =
{
       6,    86,    23,    40,     8,    16,    36,    11,     3,     4,
      40,    96,    16,    40,    99,    45,    46,    21,    29,    23,
      15,    16,    17,    18,    19,    37,    21,    41,    42,    40,
      42,    40,    27,    28,    29,    56,    31,    48,    37,    41,
      42,    36,    29,    42,     0,    40,    27,    28,    43,    30,
      22,    23,    24,    48,    43,    36,    60,    36,    43,    40,
     145,    40,    29,   148,    45,    46,    45,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      29,    85,    86,     9,   169,    20,    21,    22,    23,    24,
      41,    95,    96,    29,    98,    99,   100,    32,    33,    34,
      35,    29,   106,   109,    27,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    42,    43,    15,    16,    17,
      18,    19,    28,    21,    41,    42,    30,   131,    29,    27,
      28,    29,    40,    31,    41,    42,   140,    40,    36,    41,
      38,   145,    40,    38,   148,    43,   152,    40,   154,   153,
      48,    41,    42,    41,    42,    17,    18,    17,    18,    29,
      38,    29,    27,   108,   164,   169,    -1,   173,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    -1,    21,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    -1,    31,    -1,    -1,    -1,
      -1,    36,    -1,    38,    39,    40,     3,     4,    43,    -1,
      -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    -1,    21,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    -1,    31,    -1,    -1,    -1,    -1,    36,
      -1,    38,    -1,    40,     3,     4,    -1,    -1,    -1,    -1,
       9,    48,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    -1,    21,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    -1,    31,    -1,    -1,    -1,    -1,    36,     3,     4,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      15,    16,    17,    18,    19,    -1,    21,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    -1,    31,    -1,    -1,    13,
      14,    36,    -1,    -1,    -1,    40,    20,    21,    22,    23,
      24,    25,    26,    48,    -1,    13,    14,    -1,    32,    33,
      34,    35,    20,    21,    22,    23,    24,    25,    26,    -1,
      44,    13,    14,    -1,    32,    33,    34,    35,    20,    21,
      22,    23,    24,    25,    26,    43,    -1,    13,    14,    -1,
      32,    33,    34,    35,    20,    21,    22,    23,    24,    25,
      26,    43,    -1,    13,    14,    -1,    32,    33,    34,    35,
      20,    21,    22,    23,    24,    25,    26,    43,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    13,    14,    -1,    -1,
      -1,    41,    -1,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    13,
      14,    -1,    -1,    -1,    41,    -1,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    13,    14,    -1,    -1,    -1,    41,    -1,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    13,    14,    -1,    39,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    -1,    37,
      13,    14,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    -1,    37,    13,    14,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    13,    -1,    -1,    32,    33,    34,    35,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    15,    16,    17,    18,    19,    21,    27,    28,    29,
      31,    36,    38,    40,    43,    48,    50,    51,    52,    53,
      56,    58,    59,    60,    61,    66,    71,    74,    76,    78,
      80,    82,    84,    40,    40,    40,    51,    29,    69,    43,
      52,    43,    43,    52,    29,    52,    40,    59,    61,    59,
      38,    52,    65,    67,    68,    72,    52,    74,    29,     0,
      50,    13,    14,    20,    21,    22,    23,    24,    25,    26,
      32,    33,    34,    35,    43,    36,    40,    45,    46,    54,
      55,    57,    62,    63,    64,    36,    40,    45,    81,    83,
      79,    75,    43,    74,    52,    37,    42,    37,    42,    70,
      41,    41,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    65,    29,    29,    27,
      28,    30,    52,    65,    29,    52,    65,    52,    40,    41,
      44,    52,    68,    39,    51,    40,    37,    41,    40,    52,
      37,    41,    41,    43,    41,    29,    77,    52,    73,    65,
      65,    51,    52,    51,    41,    42,    39,    41,    41,    43,
      71,    29,    65,    41,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    53,
      53,    53,    53,    54,    53,    53,    55,    53,    53,    57,
      56,    58,    58,    58,    58,    58,    59,    59,    59,    59,
      60,    60,    60,    60,    61,    61,    61,    62,    62,    63,
      64,    65,    65,    65,    66,    66,    67,    67,    68,    69,
      69,    70,    70,    72,    73,    71,    75,    74,    76,    76,
      76,    76,    76,    76,    77,    77,    77,    79,    78,    78,
      81,    80,    83,    82,    84,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       2,     2,     2,     0,     3,     2,     0,     3,     1,     0,
       4,     1,     1,     1,     3,     1,     1,     2,     2,     1,
       3,     4,     3,     4,     4,     2,     6,     1,     1,     3,
       5,     1,     3,     0,     3,     3,     1,     3,     5,     1,
       0,     2,     0,     0,     0,     5,     0,     7,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     0,     6,     2,
       0,     6,     0,    10,     2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 56 "parser.y" /* yacc.c:1646  */
    {
			printf("finished\n");
		}
#line 1525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 60 "parser.y" /* yacc.c:1646  */
    {printf("stmt <- Expression \n");}
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 61 "parser.y" /* yacc.c:1646  */
    {printf("stmt <- ifstatement\n");}
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 62 "parser.y" /* yacc.c:1646  */
    {printf("stmt <- whilestatement\n");}
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 63 "parser.y" /* yacc.c:1646  */
    {printf("stmt <- forstatement\n");}
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 64 "parser.y" /* yacc.c:1646  */
    {if(funcDef==0)printf("\n Error return outside a function \n\n"); printf("stmt <- retstatement\n");}
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 65 "parser.y" /* yacc.c:1646  */
    { if(loop==0)printf("\n Error break not in an active loop \n\n"); printf("stmt <- break\n");}
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 66 "parser.y" /* yacc.c:1646  */
    {if(loop==0)printf("\n Error Continue not in an active loop \n\n");  printf("stmt <- continue\n");}
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 67 "parser.y" /* yacc.c:1646  */
    {printf("stmt <- block\n");}
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 68 "parser.y" /* yacc.c:1646  */
    {printf("stmt <- funcdef\n");}
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 71 "parser.y" /* yacc.c:1646  */
    { printf("expr <- assign expression\n");}
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 72 "parser.y" /* yacc.c:1646  */
    {printf("expr <- expression  + expression \n");}
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 73 "parser.y" /* yacc.c:1646  */
    {printf("expr <- expression - expression \n");}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 74 "parser.y" /* yacc.c:1646  */
    { printf("expr <- expression * expression  \n");}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 75 "parser.y" /* yacc.c:1646  */
    {printf("expr <- expression / expression  \n");}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 76 "parser.y" /* yacc.c:1646  */
    {printf("expr <- expression % expression \n");}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 77 "parser.y" /* yacc.c:1646  */
    {printf("expr <- expression > expression %d>%d \n");}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 78 "parser.y" /* yacc.c:1646  */
    {printf("expr <- expression >= expression  \n");}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 79 "parser.y" /* yacc.c:1646  */
    {printf("expr <- expression  < expression  \n");}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 80 "parser.y" /* yacc.c:1646  */
    {printf("expr <- expression <= expression  \n");}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 81 "parser.y" /* yacc.c:1646  */
    {printf("expr <- expression == expression \n");}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 82 "parser.y" /* yacc.c:1646  */
    {printf("expr <- expression != expression  \n");}
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 83 "parser.y" /* yacc.c:1646  */
    {printf("expr <- expression && expression  \n");}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 84 "parser.y" /* yacc.c:1646  */
    {printf("expr <- expression || expression \n");}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 86 "parser.y" /* yacc.c:1646  */
    { 
			
		
	printf("expr <- term\n");}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 91 "parser.y" /* yacc.c:1646  */
    {printf("term <- (expr)\n");}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 92 "parser.y" /* yacc.c:1646  */
    { printf("term <- -expr\n");}
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 93 "parser.y" /* yacc.c:1646  */
    { printf("term <- oxiexpr\n");}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 94 "parser.y" /* yacc.c:1646  */
    {if(lookupLib(yylval.strval,yylineno)==1 || lookup_func(yylval.strval,scope,yylineno)==1 || lookup_prevScope(yylval.strval,scope,yylineno)==2){
						printf("\nERROR:  Cannot ++value to %s in line %d!!!\n\n",yylval.strval,yylineno);
					}	printf("term <- ++lvalue\n");}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 97 "parser.y" /* yacc.c:1646  */
    {
		if(lookupLib(yylval.strval,yylineno)==1 || lookup_func(yylval.strval,scope,yylineno)==1 || lookup_prevScope(yylval.strval,scope,yylineno)==2){
						printf("\nERROR:  Cannot  value++ to %s in line %d!!!\n\n",yylval.strval,yylineno);
					}
	}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 101 "parser.y" /* yacc.c:1646  */
    {printf("term <- lvalue++\n");}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 102 "parser.y" /* yacc.c:1646  */
    {if(lookupLib(yylval.strval,yylineno)==1 || lookup_func(yylval.strval,scope,yylineno)==1 || lookup_prevScope(yylval.strval,scope,yylineno)==2){
						printf("\nERROR:  Cannot  --value to %s in line %d!!!\n\n",yylval.strval,yylineno);
					}    printf("term <- --lvalue\n");}
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 105 "parser.y" /* yacc.c:1646  */
    {
		if(lookupLib(yylval.strval,yylineno)==1 || lookup_func(yylval.strval,scope,yylineno)==1 || lookup_prevScope(yylval.strval,scope,yylineno)==2){
						printf("\nERROR:  Cannot value -- to %s in line %d!!!\n\n",yylval.strval,yylineno);
					}
		
	}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 110 "parser.y" /* yacc.c:1646  */
    {printf("term <- lvalue--\n");}
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 111 "parser.y" /* yacc.c:1646  */
    { printf("term <- termprimary\n");}
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 113 "parser.y" /* yacc.c:1646  */
    {
					if(lookupLib(yylval.strval,yylineno)==1 || (lookup_func(yylval.strval,scope,yylineno)==1 && lookup_localRedef(yylval.strval,scope,yylineno)==1) || lookup_prevScope(yylval.strval,scope,yylineno)==2){
						printf("\nERROR:  Cannot assign value to %s in line %d!!!\n\n",yylval.strval,yylineno);
					}
					}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 117 "parser.y" /* yacc.c:1646  */
    {
					
			printf("assignexpr <- lvalue=expr\n");}
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 120 "parser.y" /* yacc.c:1646  */
    {printf("primary <- lvalue\n");}
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 121 "parser.y" /* yacc.c:1646  */
    {printf("primary <- call\n");}
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 122 "parser.y" /* yacc.c:1646  */
    {printf("primary <- objectdef\n");}
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 123 "parser.y" /* yacc.c:1646  */
    {printf("primary <- (funcdef)\n");}
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 124 "parser.y" /* yacc.c:1646  */
    {printf("primary <- const\n");}
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 128 "parser.y" /* yacc.c:1646  */
    {
				
	
					
						if(funcDef>0){
							
							if(lookup_currScope(yytext,scope,yylineno)==0){
								
								if(lookup_prevScope(yytext,scope,yylineno)==1){
									if((funcDef-1)>0){
										printf("\nERROR variable %s is not accessible in line : %d\n\n",yytext,yylineno);
									}
									else if(loop==0 && lookup_global(yytext)==0){
										printf("\nERROR variable %s is not accessible in line : %d\n\n",yytext,yylineno);
									}
									else{
										printf("einai i else edw\n");
									}
									
								}else if( lookup_prevScope(yytext,scope,yylineno)==2){
									printf("\nERROR:	 %s already in use as function in line %d!!!\n\n",yytext,yylineno);
								}else if(lookup_prevScope(yytext,scope,yylineno)==4){
									
								}
								else if(lookup_prevScope(yytext,scope,yylineno)!=3){
									if(lookup_global(yytext)==0 ){
									insertNode(yytext,scope,yylineno,LOCL);
									}
								}
								
								
							}
	
						}else{
								
							if(lookup_global(yytext)==0 && lookup_prevScope(yytext,scope,yylineno)==0){
							
								if(scope==0){
									insertNode(yytext,scope,yylineno,GLOBL);
								}
								else{
									insertNode(yytext,scope,yylineno,LOCL);		
								}
							}
							printf("after %d\n",yylineno);
						}
					
				
					
					
				
				
				printf("lvalue <- identifier\n"); 
			}
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 182 "parser.y" /* yacc.c:1646  */
    {
				if(lookup_global(yytext)==0){
					printf("\nERROR GLOBAL VAR %s doesn't exist \n\n",yytext);
				}
				printf("lvalue <- global id\n");
			}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 188 "parser.y" /* yacc.c:1646  */
    { 
	             if(scope==0){
					 if(lookup_localRedef(yytext,scope,yylineno)==1){
						insertNode(yytext,scope,yylineno,GLOBL);
					 }
					 else{
						printf("\nERROR LOCAL VAR %s redefinition in line %d\n\n",yytext,yylineno);
					 }
				
				}else{
					if(lookup_localRedef(yytext,scope,yylineno)==1){
						insertNode(yytext,scope,yylineno,LOCL);
					
					}
					else{
						printf("\nERROR LOCAL VAR %s redefinition in line %d\n\n",yytext,yylineno);
					}
				}
				 
				
				printf("lvalue <- |LOCAL ID\n");
			
			}
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 213 "parser.y" /* yacc.c:1646  */
    {printf("lvalue <- member\n");}
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 215 "parser.y" /* yacc.c:1646  */
    {printf("member <- lvalue.identifier\n");}
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 216 "parser.y" /* yacc.c:1646  */
    {printf("member <- lvalue expr\n");}
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 217 "parser.y" /* yacc.c:1646  */
    {printf("member <- call.identifier\n");}
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 218 "parser.y" /* yacc.c:1646  */
    {printf("member <- call expr\n");}
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 220 "parser.y" /* yacc.c:1646  */
    {printf("call <- (elist)\n");}
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 221 "parser.y" /* yacc.c:1646  */
    {printf("call <- lvaluecallsuffix\n");}
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 222 "parser.y" /* yacc.c:1646  */
    {printf("call <- (funcdef)(elist)\n");}
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 224 "parser.y" /* yacc.c:1646  */
    {printf("callsuffix <- normcall\n");}
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 225 "parser.y" /* yacc.c:1646  */
    {printf("callsuffix <- methodcall\n");}
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 227 "parser.y" /* yacc.c:1646  */
    {printf("normcall <- (elist)\n");}
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 228 "parser.y" /* yacc.c:1646  */
    {printf("methodcall <- method call\n");}
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 229 "parser.y" /* yacc.c:1646  */
    { printf("elist <- Expr\n");}
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 230 "parser.y" /* yacc.c:1646  */
    {printf("elist <- Expr,..,Expr\n");}
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 231 "parser.y" /* yacc.c:1646  */
    {printf("elist <- Empty Elist\n");}
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 233 "parser.y" /* yacc.c:1646  */
    {printf("objectdef <- [ Elist ] \n");}
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 234 "parser.y" /* yacc.c:1646  */
    {printf("objectdef <- [ Indexed ] \n");}
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 236 "parser.y" /* yacc.c:1646  */
    {printf("indexed <- Idexedelem\n");}
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 237 "parser.y" /* yacc.c:1646  */
    {printf("indexed <- indexedelem , indexedelem\n");}
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 240 "parser.y" /* yacc.c:1646  */
    {printf("indexedelem <- { Expr : Expr }\n");}
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 241 "parser.y" /* yacc.c:1646  */
    { 
				if(lookupLib(yytext,yylineno)==0){
					if(lookup_name(yytext,scope,yylineno)==0){
						insertNode(yytext,scope,yylineno,USERFUNC);
						
					}
					else if(lookup_name(yytext,scope,yylineno)==1){
						printf("\nERROR func %s redefinition in line %d\n\n",yytext,yylineno);
					}
					else{
						printf("\nERROR in line %d %s is already defined as var\n\n",yylineno,yytext);
					}
								
				}
				else{
					printf("\nERROR:	shadowing is not permitted in line %d!!!\n\n",yylineno);
				}
		
		  }
#line 2035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 260 "parser.y" /* yacc.c:1646  */
    { insertAnon(scope,yylineno); printf("temp_id <- empty\n");}
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 262 "parser.y" /* yacc.c:1646  */
    {}
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 263 "parser.y" /* yacc.c:1646  */
    {}
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 265 "parser.y" /* yacc.c:1646  */
    {scope++;}
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 265 "parser.y" /* yacc.c:1646  */
    {hide(scope);scope--;}
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 265 "parser.y" /* yacc.c:1646  */
    {printf("block\n");}
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 266 "parser.y" /* yacc.c:1646  */
    {funcDef++; }
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 266 "parser.y" /* yacc.c:1646  */
    {funcDef--;printf("funcdef <- function def \n");}
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 267 "parser.y" /* yacc.c:1646  */
    {printf("const <- |NUMBER %s\n",yytext);}
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 268 "parser.y" /* yacc.c:1646  */
    {printf("const <- |REALNUMBER %s\n",yytext);}
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 269 "parser.y" /* yacc.c:1646  */
    {printf("const <- |STRING\n");}
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 270 "parser.y" /* yacc.c:1646  */
    {printf("const <- |NIL\n");}
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 271 "parser.y" /* yacc.c:1646  */
    {printf("const <- |TRUE\n");}
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 272 "parser.y" /* yacc.c:1646  */
    {printf("const <- |FALSE\n");}
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 274 "parser.y" /* yacc.c:1646  */
    {	printf("to id einai %s\n",yytext);

			if(lookupLib(yytext,yylineno)==1){
				printf("\nERROR: Library function used as argument in line %d \n\n",yylineno);
			}else{
				insertNode(yytext,scope+1,yylineno,FORMAL);
			}

			printf("idlist <- ID\n");
			}
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 284 "parser.y" /* yacc.c:1646  */
    {
		
		if(lookupLib(yytext,yylineno)==1){
			printf("\nERROR: Library function used as argument in line %d \n\n",yylineno);
		}else if(lookupArgs(yytext)==1){
			printf("\n ERROR : Argument %s redefinition in line %d \n\n",yytext,yylineno);
		}else{
			insertNode(yytext,scope+1,yylineno,FORMAL);
			
		}

		printf("idlist <- idlist comma \n");
		}
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 297 "parser.y" /* yacc.c:1646  */
    {;}
#line 2158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 299 "parser.y" /* yacc.c:1646  */
    {}
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 299 "parser.y" /* yacc.c:1646  */
    {printf("ifstmt <- if()\n");}
#line 2170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 300 "parser.y" /* yacc.c:1646  */
    {printf("ifstmt <- ifelse stmt \n");}
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 302 "parser.y" /* yacc.c:1646  */
    { scope++;loop++;}
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 302 "parser.y" /* yacc.c:1646  */
    {scope--;loop--;printf("whilestmt <- while()stmt\n");}
#line 2188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 303 "parser.y" /* yacc.c:1646  */
    {scope++;loop++;}
#line 2194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 303 "parser.y" /* yacc.c:1646  */
    {loop--;scope--;printf("forstmt <- |FOR (ELIST;EXPR;ELIST)STMT\n");}
#line 2200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 304 "parser.y" /* yacc.c:1646  */
    {printf("returnstmt <- return;\n");}
#line 2206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 305 "parser.y" /* yacc.c:1646  */
    {printf("returnstmt <- RETURN EXPR;\n");}
#line 2212 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2216 "y.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
      yyerror (YY_("syntax error"));
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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
                      yytoken, &yylval);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
#line 306 "parser.y" /* yacc.c:1906  */

int yyerror (const char * YaccProvidedMessage)
{	
	if ((strstr(YaccProvidedMessage,"$end")))
		printf("Unexpected reach of the EOF.\n");
	else
		printf("%s -- in line %d , token %s \n ",YaccProvidedMessage,yylineno,yytext);
	return 0;
}


int main(int argc,char **argv)
{
	
	insert_libfunc();

	
	yyparse();
	print();
	return 0;
}
