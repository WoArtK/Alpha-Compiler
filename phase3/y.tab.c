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
#include "quads.h"
#include <assert.h>


extern int yylex(void);
extern int yylineno;
extern char *yytext;
int scope=0;
int funcDef=0;	//flag gia anoixto orismo sunarthshs (active vars)
int funCall=0;
int loop=0;
int flag=0;
expr_e *elist_tmp = NULL;
expr_e *indexed_tmp = NULL;
int t=0;


//node *last_func=malloc(sizeof(node));

#line 91 "y.tab.c" /* yacc.c:339  */

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
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    WHILE = 258,
    FOR = 259,
    BREAK = 260,
    CONTINUE = 261,
    IF = 262,
    ELSE = 263,
    FUNCTION = 264,
    RETURN = 265,
    AND = 266,
    OR = 267,
    NOT = 268,
    LOCAL = 269,
    TRUE = 270,
    FALSE = 271,
    NIL = 272,
    EQUALS = 273,
    NOT_EQUALS = 274,
    PLUS_PLUS = 275,
    MINUS_MINUS = 276,
    ID = 277,
    INTEGER = 278,
    STRING = 279,
    REALNUMBER = 280,
    GREATER_EQUAL = 281,
    LESS_EQUAL = 282,
    DOUBLE_DOT = 283,
    GLOB = 284
  };
#endif
/* Tokens.  */
#define WHILE 258
#define FOR 259
#define BREAK 260
#define CONTINUE 261
#define IF 262
#define ELSE 263
#define FUNCTION 264
#define RETURN 265
#define AND 266
#define OR 267
#define NOT 268
#define LOCAL 269
#define TRUE 270
#define FALSE 271
#define NIL 272
#define EQUALS 273
#define NOT_EQUALS 274
#define PLUS_PLUS 275
#define MINUS_MINUS 276
#define ID 277
#define INTEGER 278
#define STRING 279
#define REALNUMBER 280
#define GREATER_EQUAL 281
#define LESS_EQUAL 282
#define DOUBLE_DOT 283
#define GLOB 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 29 "parser.y" /* yacc.c:355  */

	int intval;
	char* strval;
	float realval;
	 expr_e *exprval;
	 int method;
	 char *name;
	 expr_e *elist;
	 struct {
		 int test;
		 int enter;
		 
	 }forprefix;
	

#line 205 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 220 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   600

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  194

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    21,     2,     2,
      41,    42,    20,    18,    43,    19,    45,    22,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    44,    38,
      35,    28,    34,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    36,     2,    37,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      15,    16,    17,    23,    24,    25,    26,    27,    29,    30,
      31,    32,    33,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    80,    80,    81,    86,    86,    87,    89,    90,    91,
      95,   104,   113,   114,   115,   119,   124,   138,   150,   162,
     174,   186,   201,   214,   227,   240,   253,   265,   271,   277,
     283,   285,   291,   297,   338,   338,   378,   421,   421,   462,
     464,   464,   496,   497,   498,   499,   500,   504,   528,   540,
     561,   563,   567,   574,   575,   577,   582,   596,   604,   608,
     613,   622,   629,   630,   642,   644,   662,   677,   678,   687,
     694,   695,   697,   697,   697,   701,   742,   701,   750,   767,
     750,   774,   781,   785,   789,   794,   799,   805,   814,   827,
     829,   829,   842,   842,   842,   852,   852,   852,   852,   880,
     886,   888,   888,   888,   898,   898,   898,   924,   927
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "WHILE", "FOR", "BREAK", "CONTINUE",
  "IF", "ELSE", "FUNCTION", "RETURN", "AND", "OR", "NOT", "LOCAL", "TRUE",
  "FALSE", "NIL", "'+'", "'-'", "'*'", "'%'", "'/'", "EQUALS",
  "NOT_EQUALS", "PLUS_PLUS", "MINUS_MINUS", "ID", "'='", "INTEGER",
  "STRING", "REALNUMBER", "GREATER_EQUAL", "LESS_EQUAL", "'>'", "'<'",
  "'['", "']'", "';'", "'{'", "'}'", "'('", "')'", "','", "':'", "'.'",
  "DOUBLE_DOT", "GLOB", "$accept", "program", "stmt", "$@1", "expr",
  "term", "$@2", "$@3", "assignexpr", "$@4", "primary", "lvalue", "member",
  "call", "callsuffix", "normcall", "methodcall", "elist", "objectdef",
  "indexed", "indexedelem", "temp_st", "block", "$@5", "$@6", "funcdef",
  "$@7", "$@8", "$@9", "$@10", "const", "idlist", "ifstmt", "$@11", "$@12",
  "$@13", "whilestmt", "$@14", "$@15", "$@16", "N", "M", "forp", "$@17",
  "$@18", "forstmt", "$@19", "$@20", "returnstmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,    43,    45,
      42,    37,    47,   273,   274,   275,   276,   277,    61,   278,
     279,   280,   281,   282,    62,    60,    91,    93,    59,   123,
     125,    40,    41,    44,    58,    46,   283,   284
};
# endif

#define YYPACT_NINF -178

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-178)))

#define YYTABLE_NINF -93

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-93)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     100,  -178,   -36,     2,    14,    15,    56,   249,   307,    60,
    -178,  -178,  -178,   307,   -12,   -12,  -178,  -178,  -178,  -178,
     278,  -178,  -178,   220,    65,   101,   100,    27,  -178,  -178,
    -178,   554,  -178,    50,  -178,  -178,  -178,  -178,  -178,   110,
    -178,  -178,  -178,  -178,    83,  -178,  -178,  -178,   307,  -178,
      91,  -178,   456,  -178,  -178,    -3,   126,   -15,    50,   -15,
     307,    27,    20,    47,  -178,  -178,   356,    95,  -178,  -178,
    -178,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   106,   307,   307,   119,   127,   132,
     138,   130,  -178,  -178,  -178,   307,   307,   140,  -178,  -178,
    -178,   307,   381,   129,  -178,  -178,   136,   338,  -178,   307,
    -178,   135,   146,  -178,   139,   463,   553,    -3,    -3,  -178,
    -178,  -178,   488,   488,   -10,   -10,   -10,   -10,  -178,   506,
       1,  -178,   142,  -178,  -178,   307,   533,    12,  -178,   185,
     307,   307,    42,  -178,  -178,   141,   139,   307,    27,  -178,
    -178,  -178,   307,  -178,  -178,   307,    27,  -178,  -178,  -178,
      55,   406,  -178,   185,   141,  -178,    57,   431,  -178,    69,
      78,  -178,  -178,   307,  -178,    80,   157,   152,  -178,  -178,
    -178,  -178,   185,   481,   157,  -178,  -178,   185,  -178,  -178,
    -178,  -178,  -178,  -178
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    95,     0,     0,     0,     0,    78,     0,     0,     0,
      85,    86,    84,     0,     0,     0,    47,    81,    83,    82,
      64,    14,    72,     0,     0,     0,     3,     4,    29,    15,
      39,    42,    50,    43,    44,    12,    13,    46,     6,     0,
       7,    99,     8,     9,     0,   101,    10,    11,     0,    75,
       0,   107,     0,    32,    49,    31,     0,    33,     0,    36,
       0,    62,     0,     0,    67,    71,     0,     0,    48,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    64,     0,     0,     0,
       0,     0,    56,    58,    59,     0,    64,     0,    93,   104,
      96,    64,     0,     0,    79,   108,     0,     0,    65,     0,
      66,     0,    92,    30,    45,    27,    28,    16,    17,    18,
      20,    19,    25,    26,    22,    24,    21,    23,     5,     0,
       0,    51,     0,    35,    38,     0,     0,     0,    53,    92,
      64,     0,     0,    90,    76,    89,     0,     0,    63,    68,
      73,    70,    64,    52,    60,    64,    41,    54,    55,    94,
       0,     0,   100,    92,    89,    87,     0,     0,    74,     0,
       0,   105,    97,     0,    91,     0,     0,     0,    69,    57,
      61,    99,    92,     0,     0,    80,    88,    92,    98,   102,
      77,    99,   103,   106
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -178,   143,  -105,  -178,    -7,  -178,  -178,  -178,  -178,  -178,
    -178,    18,  -178,   128,  -178,  -178,  -178,   -59,  -178,  -178,
      70,  -178,  -156,  -178,  -178,   -20,  -178,  -178,  -178,  -178,
    -178,    33,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,
    -177,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    84,    27,    28,    89,    90,    29,    91,
      30,    31,    32,    33,    92,    93,    94,    62,    34,    63,
      64,   112,    35,    65,   168,    36,   103,   164,    50,   145,
      37,   166,    38,   163,    39,   139,    40,    44,   141,   182,
      99,   173,    41,   101,   192,    42,   140,   181,    43
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,    53,     9,    67,   187,    45,    55,   151,    73,    74,
      75,    76,    77,    61,   193,    16,    66,    75,    76,    77,
     185,    85,   -93,   -93,   -93,   -93,    86,   130,   190,    56,
      87,    88,    57,    59,   159,    24,   106,   137,    71,    72,
      46,   102,   142,   154,   109,    73,    74,    75,    76,    77,
      78,    79,    47,   107,   158,   109,    48,   108,   174,    80,
      81,    82,    83,   109,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   188,   129,    61,
     162,   160,   191,    49,   110,   109,    95,    54,   136,    61,
     111,    96,    68,   169,    61,    97,   170,   171,   109,   176,
     177,    69,   148,     1,     2,     3,     4,     5,   -92,     6,
       7,   179,   109,     8,     9,    10,    11,    12,    98,    13,
     180,   109,   184,   177,   100,    14,    15,    16,   156,    17,
      18,    19,   104,    61,   161,     6,    20,   114,    21,    22,
     167,    23,    58,    58,   128,    61,   131,    24,    61,     1,
       2,     3,     4,     5,   132,     6,     7,   133,   135,     8,
       9,    10,    11,    12,   134,    13,   183,   138,   165,    70,
     144,    14,    15,    16,    60,    17,    18,    19,   146,   186,
     152,   149,    20,   155,    21,    22,   150,    23,     1,     2,
       3,     4,     5,    24,     6,     7,    22,   175,     8,     9,
      10,    11,    12,     0,    13,     0,     0,     0,     0,     0,
      14,    15,    16,     0,    17,    18,    19,     0,     0,     0,
       0,    20,     0,    21,    22,     0,    23,     0,     0,     6,
       0,     0,    24,     8,     9,    10,    11,    12,     0,    13,
       0,     0,     0,     0,     0,    14,    15,    16,     0,    17,
      18,    19,     0,     0,     0,     0,    20,     0,     0,     0,
       0,    23,     8,     9,    10,    11,    12,    24,    13,     0,
       0,     0,     0,     0,    14,    15,    16,     0,    17,    18,
      19,     0,     0,     0,     0,    20,     0,    51,     0,     0,
      23,     8,     9,    10,    11,    12,    24,    13,     0,     0,
       0,     0,     0,    14,    15,    16,     0,    17,    18,    19,
       0,     0,     0,     0,    20,     0,     0,    60,     0,    23,
       8,     9,    10,    11,    12,    24,    13,     0,     0,     0,
       0,     0,    14,    15,    16,     0,    17,    18,    19,     0,
       0,     0,     0,    20,     0,     0,     0,     0,    23,    71,
      72,     0,     0,     0,    24,     0,    73,    74,    75,    76,
      77,    78,    79,     0,     0,     0,     0,    71,    72,     0,
      80,    81,    82,    83,    73,    74,    75,    76,    77,    78,
      79,     0,   147,     0,     0,     0,     0,     0,    80,    81,
      82,    83,    71,    72,     0,     0,     0,     0,   113,    73,
      74,    75,    76,    77,    78,    79,     0,     0,     0,     0,
       0,     0,     0,    80,    81,    82,    83,    71,    72,     0,
       0,     0,     0,   143,    73,    74,    75,    76,    77,    78,
      79,     0,     0,     0,     0,     0,     0,     0,    80,    81,
      82,    83,    71,    72,     0,     0,     0,     0,   172,    73,
      74,    75,    76,    77,    78,    79,     0,     0,     0,     0,
       0,     0,     0,    80,    81,    82,    83,    71,    72,     0,
       0,   178,     0,     0,    73,    74,    75,    76,    77,    78,
      79,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    71,    72,   105,    80,    81,    82,    83,    73,
      74,    75,    76,    77,    78,    79,    73,    74,    75,    76,
      77,   -93,   -93,    80,    81,    82,    83,    71,    72,   189,
      80,    81,    82,    83,    73,    74,    75,    76,    77,    78,
      79,     0,     0,     0,     0,     0,     0,     0,    80,    81,
      82,    83,     0,   153,    71,    72,     0,     0,     0,     0,
       0,    73,    74,    75,    76,    77,    78,    79,     0,     0,
       0,     0,     0,     0,    71,    80,    81,    82,    83,     0,
     157,    73,    74,    75,    76,    77,    78,    79,     0,   -34,
     -37,     0,   -40,     0,     0,    80,    81,    82,    83,     0,
      85,     0,     0,     0,     0,    86,     0,     0,     0,    87,
      88
};

static const yytype_int16 yycheck[] =
{
       7,     8,    14,    23,   181,    41,    13,   112,    18,    19,
      20,    21,    22,    20,   191,    27,    23,    20,    21,    22,
     176,    36,    32,    33,    34,    35,    41,    86,   184,    41,
      45,    46,    14,    15,   139,    47,    56,    96,    11,    12,
      38,    48,   101,    42,    43,    18,    19,    20,    21,    22,
      23,    24,    38,    60,    42,    43,    41,    37,   163,    32,
      33,    34,    35,    43,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,   182,    85,    86,
      38,   140,   187,    27,    37,    43,    36,    27,    95,    96,
      43,    41,    27,   152,   101,    45,   155,    42,    43,    42,
      43,     0,   109,     3,     4,     5,     6,     7,     8,     9,
      10,    42,    43,    13,    14,    15,    16,    17,     8,    19,
      42,    43,    42,    43,    41,    25,    26,    27,   135,    29,
      30,    31,    41,   140,   141,     9,    36,    42,    38,    39,
     147,    41,    14,    15,    38,   152,    27,    47,   155,     3,
       4,     5,     6,     7,    27,     9,    10,    25,    28,    13,
      14,    15,    16,    17,    26,    19,   173,    27,    27,    26,
      41,    25,    26,    27,    39,    29,    30,    31,    42,    27,
      41,   111,    36,    41,    38,    39,    40,    41,     3,     4,
       5,     6,     7,    47,     9,    10,    39,   164,    13,    14,
      15,    16,    17,    -1,    19,    -1,    -1,    -1,    -1,    -1,
      25,    26,    27,    -1,    29,    30,    31,    -1,    -1,    -1,
      -1,    36,    -1,    38,    39,    -1,    41,    -1,    -1,     9,
      -1,    -1,    47,    13,    14,    15,    16,    17,    -1,    19,
      -1,    -1,    -1,    -1,    -1,    25,    26,    27,    -1,    29,
      30,    31,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,
      -1,    41,    13,    14,    15,    16,    17,    47,    19,    -1,
      -1,    -1,    -1,    -1,    25,    26,    27,    -1,    29,    30,
      31,    -1,    -1,    -1,    -1,    36,    -1,    38,    -1,    -1,
      41,    13,    14,    15,    16,    17,    47,    19,    -1,    -1,
      -1,    -1,    -1,    25,    26,    27,    -1,    29,    30,    31,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    39,    -1,    41,
      13,    14,    15,    16,    17,    47,    19,    -1,    -1,    -1,
      -1,    -1,    25,    26,    27,    -1,    29,    30,    31,    -1,
      -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    41,    11,
      12,    -1,    -1,    -1,    47,    -1,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    11,    12,    -1,
      32,    33,    34,    35,    18,    19,    20,    21,    22,    23,
      24,    -1,    44,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    11,    12,    -1,    -1,    -1,    -1,    42,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    11,    12,    -1,
      -1,    -1,    -1,    42,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    11,    12,    -1,    -1,    -1,    -1,    42,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    11,    12,    -1,
      -1,    40,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    18,    19,    20,    21,    22,    23,    24,    32,    33,
      34,    35,    11,    12,    38,    32,    33,    34,    35,    18,
      19,    20,    21,    22,    23,    24,    18,    19,    20,    21,
      22,    23,    24,    32,    33,    34,    35,    11,    12,    38,
      32,    33,    34,    35,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    -1,    37,    11,    12,    -1,    -1,    -1,    -1,
      -1,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    11,    32,    33,    34,    35,    -1,
      37,    18,    19,    20,    21,    22,    23,    24,    -1,    25,
      26,    -1,    28,    -1,    -1,    32,    33,    34,    35,    -1,
      36,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    45,
      46
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     9,    10,    13,    14,
      15,    16,    17,    19,    25,    26,    27,    29,    30,    31,
      36,    38,    39,    41,    47,    49,    50,    52,    53,    56,
      58,    59,    60,    61,    66,    70,    73,    78,    80,    82,
      84,    90,    93,    96,    85,    41,    38,    38,    41,    27,
      76,    38,    52,    52,    27,    52,    41,    59,    61,    59,
      39,    52,    65,    67,    68,    71,    52,    73,    27,     0,
      49,    11,    12,    18,    19,    20,    21,    22,    23,    24,
      32,    33,    34,    35,    51,    36,    41,    45,    46,    54,
      55,    57,    62,    63,    64,    36,    41,    45,     8,    88,
      41,    91,    52,    74,    41,    38,    73,    52,    37,    43,
      37,    43,    69,    42,    42,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    38,    52,
      65,    27,    27,    25,    26,    28,    52,    65,    27,    83,
      94,    86,    65,    42,    41,    77,    42,    44,    52,    68,
      40,    50,    41,    37,    42,    41,    52,    37,    42,    50,
      65,    52,    38,    81,    75,    27,    79,    52,    72,    65,
      65,    42,    42,    89,    50,    79,    42,    43,    40,    42,
      42,    95,    87,    52,    42,    70,    27,    88,    50,    38,
      70,    50,    92,    88
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    49,    51,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      53,    53,    53,    53,    54,    53,    53,    55,    53,    53,
      57,    56,    58,    58,    58,    58,    58,    59,    59,    59,
      59,    60,    60,    60,    60,    61,    61,    61,    62,    62,
      63,    64,    65,    65,    65,    66,    66,    67,    67,    68,
      69,    69,    71,    72,    70,    74,    75,    73,    76,    77,
      73,    78,    78,    78,    78,    78,    78,    79,    79,    79,
      81,    80,    82,    83,    80,    85,    86,    87,    84,    88,
      89,    91,    92,    90,    94,    95,    93,    96,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     0,     3,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     2,     2,     2,     0,     3,     2,     0,     3,     1,
       0,     4,     1,     1,     1,     3,     1,     1,     2,     2,
       1,     3,     4,     3,     4,     4,     2,     6,     1,     1,
       3,     5,     1,     3,     0,     3,     3,     1,     3,     5,
       2,     0,     0,     0,     5,     0,     0,     8,     0,     0,
       7,     1,     1,     1,     1,     1,     1,     1,     3,     0,
       0,     6,     0,     0,     4,     0,     0,     0,     8,     0,
       0,     0,     0,     9,     0,     0,     9,     2,     3
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
#line 81 "parser.y" /* yacc.c:1646  */
    {
			printf("finished flag=%d\n\n\n",flag);
			
		}
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 86 "parser.y" /* yacc.c:1646  */
    {elist_tmp=NULL; indexed_tmp = NULL;	printf("$expr  \n");}
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 86 "parser.y" /* yacc.c:1646  */
    {printf("Expression to Statement\n"); resettemp();}
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 87 "parser.y" /* yacc.c:1646  */
    {	
				printf("ifstatement to Statement\n"); resettemp();}
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 89 "parser.y" /* yacc.c:1646  */
    {printf("whilestatement to Statement\n");resettemp();}
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 90 "parser.y" /* yacc.c:1646  */
    {printf("forstatement to Statement\n");resettemp();}
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 91 "parser.y" /* yacc.c:1646  */
    { if(funcDef==0)printf("\n ERROR in line %d . Return outside function definition \n\n",yylineno);
					printf("retstatement to Statement\n");
						resettemp();
						}
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 95 "parser.y" /* yacc.c:1646  */
    { 			if(loop>0){
							emit_Realop(jump,NULL,NULL,0);
							push(&breakstack,nextquad());
							
							}else{
							printf("\n\nBreak not inside loop in line %d \n\n",yylineno);	
							return 0;
							}
							 printf("break to Statement\n");}
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 104 "parser.y" /* yacc.c:1646  */
    { 
					if(loop>0){
					emit_Realop(jump,NULL,NULL,0); 
					push(&continuestack,nextquad());
					}else{
							printf("\n\nContinue not inside loop in line %d \n\n",yylineno);	
							return 0;
							}
					printf("continue to Statement\n");}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 113 "parser.y" /* yacc.c:1646  */
    {printf("block to Statement\n");resettemp();}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 114 "parser.y" /* yacc.c:1646  */
    {printf("funcdef to Statement\n");resettemp();}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 119 "parser.y" /* yacc.c:1646  */
    { 
		
		
		
		printf("assign expression to expression\n");}
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 124 "parser.y" /* yacc.c:1646  */
    {if(check_if_arithm((yyvsp[-2].exprval),(yyvsp[0].exprval))==0){
									
						printf("This type of expr cannot be part of arithm expression in line %d \n",yylineno);		
						exit(0);
						}
				
							
					(yyval.exprval) =newexpr(arithmexpr_e);
					//check_if_constNum($<exprval>1,$<exprval>3,$<exprval>$);
					  (yyval.exprval)->symbol=newtemp();
					 emit(add,(yyvsp[-2].exprval),(yyvsp[0].exprval), (yyval.exprval), yylineno);

				printf("expression  + expression to expression\n");
				}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 138 "parser.y" /* yacc.c:1646  */
    {
		if(check_if_arithm((yyvsp[-2].exprval),(yyvsp[0].exprval))==0){
									
						printf("This type of expr cannot be part of arithm expression in line %d \n",yylineno);		
						exit(0);
						}			
		(yyval.exprval) =newexpr(arithmexpr_e);
	  // check_if_constNum($<exprval>1,$<exprval>3,$<exprval>$);
		(yyval.exprval)->symbol=newtemp();
		emit(sub,(yyvsp[-2].exprval),(yyvsp[0].exprval), (yyval.exprval), yylineno);
		printf("expression - expression to expression\n");
		}
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 150 "parser.y" /* yacc.c:1646  */
    {
		if(check_if_arithm((yyvsp[-2].exprval),(yyvsp[0].exprval))==0){
									
						printf("This type of expr cannot be part of arithm expression in line %d \n",yylineno);		
						exit(0);
						}		
		(yyval.exprval) =newexpr(arithmexpr_e);
	//  check_if_constNum($<exprval>1,$<exprval>3,$<exprval>$);
		(yyval.exprval)->symbol=newtemp();
		emit(mul,(yyvsp[-2].exprval),(yyvsp[0].exprval), (yyval.exprval), yylineno);
		printf("expression * expression  to expression\n");
		}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 162 "parser.y" /* yacc.c:1646  */
    {
		if(check_if_arithm((yyvsp[-2].exprval),(yyvsp[0].exprval))==0){
									
						printf("This type of expr cannot be part of arithm expression in line %d \n",yylineno);		
						exit(0);
						}		
		(yyval.exprval) =newexpr(arithmexpr_e);
		//check_if_constNum($<exprval>1,$<exprval>3,$<exprval>$);
		(yyval.exprval)->symbol=newtemp();
		emit(div_op,(yyvsp[-2].exprval),(yyvsp[0].exprval), (yyval.exprval), yylineno);
		printf("expression / expression to expression \n");
		}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 174 "parser.y" /* yacc.c:1646  */
    {
	if(check_if_arithm((yyvsp[-2].exprval),(yyvsp[0].exprval))==0){
									
						printf("This type of expr cannot be part of arithm expression in line %d \n",yylineno);		
						exit(0);
						}		
		(yyval.exprval) =newexpr(arithmexpr_e);
		//check_if_constNum($<exprval>1,$<exprval>3,$<exprval>$);
		(yyval.exprval)->symbol=newtemp();
		emit(mod,(yyvsp[-2].exprval),(yyvsp[0].exprval), (yyval.exprval), yylineno);
		printf("expression % expression to expression\n");
		}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 186 "parser.y" /* yacc.c:1646  */
    {	
						(yyval.exprval)=newexpr(boolexpr_e);
						(yyval.exprval)->symbol=newtemp();
						expr_e *falseExp=newexpr(constbool_e);
						falseExp->boolConst=0;
						expr_e *trueExp=newexpr(constbool_e);
						trueExp->boolConst=1;
						emit_Realop(if_greater,(yyvsp[-2].exprval),(yyvsp[0].exprval),nextquad()+5);
						emit(assign,falseExp,NULL,(yyval.exprval),yylineno);
						emit_Realop(jump,NULL,NULL,nextquad()+4);
						emit(assign,trueExp,NULL,(yyval.exprval),yylineno);
						
							
						printf(" expression > expression to expression\n");
						}
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 201 "parser.y" /* yacc.c:1646  */
    {
						(yyval.exprval)=newexpr(boolexpr_e);
						(yyval.exprval)->symbol=newtemp();
						expr_e *falseExp=newexpr(constbool_e);
						falseExp->boolConst=0;
						expr_e *trueExp=newexpr(constbool_e);
						trueExp->boolConst=1;
						emit_Realop(if_greatereq,(yyvsp[-2].exprval),(yyvsp[0].exprval),nextquad()+5);
						emit(assign,falseExp,NULL,(yyval.exprval),yylineno);
						emit_Realop(jump,NULL,NULL,nextquad()+4);
						emit(assign,trueExp,NULL,(yyval.exprval),yylineno);
		      printf("expression >= expression  to expression\n");
			  }
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 214 "parser.y" /* yacc.c:1646  */
    {
						(yyval.exprval)=newexpr(boolexpr_e);
						(yyval.exprval)->symbol=newtemp();
						expr_e *falseExp=newexpr(constbool_e);
						falseExp->boolConst=0;
						expr_e *trueExp=newexpr(constbool_e);
						trueExp->boolConst=1;
						emit_Realop(if_less,(yyvsp[-2].exprval),(yyvsp[0].exprval),nextquad()+5);
						emit(assign,falseExp,NULL,(yyval.exprval),yylineno);
						emit_Realop(jump,NULL,NULL,nextquad()+4);
						emit(assign,trueExp,NULL,(yyval.exprval),yylineno);
						printf(" expression  < expression to expression \n");
				}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 227 "parser.y" /* yacc.c:1646  */
    {
						(yyval.exprval)=newexpr(boolexpr_e);
						(yyval.exprval)->symbol=newtemp();
						expr_e *falseExp=newexpr(constbool_e);
						falseExp->boolConst=0;
						expr_e *trueExp=newexpr(constbool_e);
						trueExp->boolConst=1;
						emit_Realop(if_lesseq,(yyvsp[-2].exprval),(yyvsp[0].exprval),nextquad()+5);
						emit(assign,falseExp,NULL,(yyval.exprval),yylineno);
						emit_Realop(jump,NULL,NULL,nextquad()+4);
						emit(assign,trueExp,NULL,(yyval.exprval),yylineno);
						printf("expression <= expression  to expression\n");
			}
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 240 "parser.y" /* yacc.c:1646  */
    {
						(yyval.exprval)=newexpr(boolexpr_e);
						(yyval.exprval)->symbol=newtemp();
						expr_e *falseExp=newexpr(constbool_e);
						falseExp->boolConst=0;
						expr_e *trueExp=newexpr(constbool_e);
						trueExp->boolConst=1;
						emit_Realop(if_eq,(yyvsp[-2].exprval),(yyvsp[0].exprval),nextquad()+5);
						emit(assign,falseExp,NULL,(yyval.exprval),yylineno);
						emit_Realop(jump,NULL,NULL,nextquad()+4);
						emit(assign,trueExp,NULL,(yyval.exprval),yylineno);
						printf("expression == expression to expression\n");
			}
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 253 "parser.y" /* yacc.c:1646  */
    {
						(yyval.exprval)=newexpr(boolexpr_e);
						(yyval.exprval)->symbol=newtemp();
						expr_e *falseExp=newexpr(constbool_e);
						falseExp->boolConst=0;
						expr_e *trueExp=newexpr(constbool_e);
						trueExp->boolConst=1;
						emit_Realop(if_noteq,(yyvsp[-2].exprval),(yyvsp[0].exprval),nextquad()+5);
						emit(assign,falseExp,NULL,(yyval.exprval),yylineno);
						emit_Realop(jump,NULL,NULL,nextquad()+4);
						emit(assign,trueExp,NULL,(yyval.exprval),yylineno);
						printf(" expression != expression  to expression\n");}
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 265 "parser.y" /* yacc.c:1646  */
    {
						(yyval.exprval)=newexpr(boolexpr_e);
						(yyval.exprval)->symbol=newtemp();
						emit(and,(yyvsp[-2].exprval),(yyvsp[0].exprval),(yyval.exprval),yylineno);
						printf("expression && expression  to expression\n");
						}
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 271 "parser.y" /* yacc.c:1646  */
    {
						(yyval.exprval)=newexpr(boolexpr_e);
						(yyval.exprval)->symbol=newtemp();
						emit(or,(yyvsp[-2].exprval),(yyvsp[0].exprval),(yyval.exprval),yylineno);
						printf("expression || expression to expression\n");
						}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 277 "parser.y" /* yacc.c:1646  */
    { 
    (yyval.exprval)=(yyvsp[0].exprval);
		    
	printf("term to expression\n");}
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 283 "parser.y" /* yacc.c:1646  */
    { (yyval.exprval)=(yyvsp[-1].exprval);
					printf("(expr) to term\n");}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 285 "parser.y" /* yacc.c:1646  */
    {
		checkuminus((yyvsp[0].exprval));
		(yyval.exprval) =newexpr(arithmexpr_e);
					  (yyval.exprval)->symbol=newtemp();
					 emit(uminus,(yyvsp[0].exprval),NULL, (yyval.exprval), yylineno);
		printf("-expr to term\n");}
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 291 "parser.y" /* yacc.c:1646  */
    { 
				printf("oxiexpr to term\n");
					 (yyval.exprval) = newexpr(boolexpr_e);
					 (yyval.exprval)->symbol = newtemp();
					 emit(not, (yyvsp[0].exprval),NULL,(yyval.exprval),yylineno);
				}
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 297 "parser.y" /* yacc.c:1646  */
    {
				if((yyvsp[0].exprval)->symbol->name!=NULL){
					node *temp=lookup_CertScope((yyvsp[0].exprval)->symbol->name,0);
					node *temp2=lookup_AllScopes((yyvsp[0].exprval)->symbol->name,scope);
					int valid=1; //holds if errors found 0=false 1 true
					if (temp==NULL && temp2==NULL)valid=0;
					if(temp!=NULL){
						if(temp->type==LIBFUNC){
							printf("\n ERROR in line %d. Cannot assign ++value to %s \n\n",yylineno,temp->name);
							valid=0;
						}
					}
					if(temp2!=NULL){
						if(temp2->type==USERFUNC){
							printf("\n ERROR in line %d. Cannot assign ++value to %s \n\n",yylineno,temp->name);
							valid=0;
						}
					}
					if(valid==1){
						
						if ((yyvsp[0].exprval)->type == tableitem_e) {
							expr_e *value = emit_iftableitem((yyvsp[0].exprval),yylineno);
							(yyval.exprval)=value;
							expr_e *num=newexpr(constnum_e);
							num->numConst=1;
							emit(add, value, num, value,yylineno);
							emit( tablesetelem, (yyvsp[0].exprval), (yyvsp[0].exprval)->index, value,yylineno);
						}
						else {
							expr_e *num=newexpr(constnum_e);
							num->numConst=1;
							emit(add, (yyvsp[0].exprval), num, (yyvsp[0].exprval),yylineno);
							(yyval.exprval)=newexpr(arithmexpr_e);
							(yyval.exprval)->symbol=newtemp();
							emit(assign, (yyvsp[0].exprval),NULL,(yyval.exprval),yylineno);

						}
					}
                }

		  printf("++lvalue to term\n");}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 338 "parser.y" /* yacc.c:1646  */
    { 
			if((yyvsp[0].exprval)->symbol->name!=NULL){
					node *temp=lookup_CertScope((yyvsp[0].exprval)->symbol->name,0);
					node *temp2=lookup_AllScopes((yyvsp[0].exprval)->symbol->name,scope);
					int valid=1;
					if (temp==NULL && temp2==NULL)valid=0;
					if(temp!=NULL){
						if(temp->type==LIBFUNC){
							printf("\n ERROR in line %d. Cannot assign value++ to %s \n\n",yylineno,temp->name);
							valid=0;
						}
					}
					if(temp2!=NULL){
						if(temp2->type==USERFUNC){
							printf("\n ERROR in line %d. Cannot assign value++ to %s \n\n",yylineno,temp->name);
							valid=0;
						}
					}
					
                }
	       }
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 358 "parser.y" /* yacc.c:1646  */
    {
							(yyval.exprval)=newexpr(var_e);
							(yyval.exprval)->symbol=newtemp();
							if((yyvsp[-2].exprval)->type==tableitem_e){
								expr_e * value=emit_iftableitem((yyvsp[-2].exprval),yylineno);
								expr_e *incr_exp=newexpr(constnum_e);
								incr_exp->numConst=1;
								emit(assign,value,NULL,(yyval.exprval),yylineno);
								emit(add,value,incr_exp,value,yylineno);
								emit(tablesetelem,(yyvsp[-2].exprval),(yyvsp[-2].exprval)->index,value,yylineno);
								
							}else{
							
								expr_e *incr_exp=newexpr(constnum_e);
								incr_exp->numConst=1;
								emit(assign,(yyvsp[-2].exprval),NULL,(yyval.exprval),yylineno);
								emit(add,(yyvsp[-2].exprval),incr_exp,(yyvsp[-2].exprval),yylineno);
							}
							printf(" lvalue++ to term\n");
							}
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 378 "parser.y" /* yacc.c:1646  */
    {  
	if((yyvsp[0].exprval)->symbol->name!=NULL){
					node *temp=lookup_CertScope((yyvsp[0].exprval)->symbol->name,0);
					node *temp2=lookup_AllScopes((yyvsp[0].exprval)->symbol->name,scope);
					int valid=1;
					if (temp==NULL && temp2==NULL)valid=0;
					if(temp!=NULL){
						if(temp->type==LIBFUNC){
							printf("\n ERROR in line %d. Cannot assign --value to %s \n\n",yylineno,temp->name);
							valid=0;
						}
					}
					if(temp2!=NULL){
						if(temp2->type==USERFUNC){
							printf("\n ERROR in line %d. Cannot assign --value to %s \n\n",yylineno,temp->name);
							valid=0;
						}
					}
					if(valid==1){
							
						if ((yyvsp[0].exprval)->type == tableitem_e) {
							expr_e *value = emit_iftableitem((yyvsp[0].exprval),yylineno);
							(yyval.exprval)=value;
							expr_e *num=newexpr(constnum_e);
							num->numConst=1;
							emit(sub, value, num, value,yylineno);
							emit( tablesetelem, (yyvsp[0].exprval), (yyvsp[0].exprval)->index, value,yylineno);
						}
						else {
							expr_e *num=newexpr(constnum_e);
							num->numConst=1;
							emit(sub, (yyvsp[0].exprval), num, (yyvsp[0].exprval),yylineno);
							(yyval.exprval)=newexpr(arithmexpr_e);
							(yyval.exprval)->symbol=newtemp();
							emit(assign, (yyvsp[0].exprval),NULL,(yyval.exprval),yylineno);

						}
					}
                

	}
 
        printf("--lvalue to term\n");}
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 421 "parser.y" /* yacc.c:1646  */
    { 
				if((yyvsp[0].exprval)->symbol->name!=NULL){
					node *temp=lookup_CertScope((yyvsp[0].exprval)->symbol->name,0);
					node *temp2=lookup_AllScopes((yyvsp[0].exprval)->symbol->name,scope);
					int valid=1;
					if (temp==NULL && temp2==NULL)valid=0;
					if(temp!=NULL){
						if(temp->type==LIBFUNC){
							printf("\n ERROR in line %d. Cannot assign value-- to %s \n\n",yylineno,temp->name);
							valid=0;
						}
						
					}
					if(temp2!=NULL){
						if(temp2->type==USERFUNC){
							printf("\n ERROR in line %d. Cannot assign value-- to %s \n\n",yylineno,temp->name);
							valid=0;
						}
					}
				
                }
		   }
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 442 "parser.y" /* yacc.c:1646  */
    {
						    (yyval.exprval)=newexpr(var_e);
							(yyval.exprval)->symbol=newtemp();
							if((yyvsp[-2].exprval)->type==tableitem_e){
								expr_e * value=emit_iftableitem((yyvsp[-2].exprval),yylineno);
								expr_e *incr_exp=newexpr(constnum_e);
								incr_exp->numConst=1;
								emit(assign,value,NULL,(yyval.exprval),yylineno);
								emit(sub,value,incr_exp,value,yylineno);
								emit(tablesetelem,(yyvsp[-2].exprval),(yyvsp[-2].exprval)->index,value,yylineno);
								
							}else{
							
								expr_e *incr_exp=newexpr(constnum_e);
								incr_exp->numConst=1;
								emit(assign,(yyvsp[-2].exprval),NULL,(yyval.exprval),yylineno);
								emit(sub,(yyvsp[-2].exprval),incr_exp,(yyvsp[-2].exprval),yylineno);
							}
							printf("lvalue-- to term\n");
							}
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 462 "parser.y" /* yacc.c:1646  */
    { printf("termprimary to term\n");}
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 464 "parser.y" /* yacc.c:1646  */
    {
					if((yyvsp[0].exprval)->symbol->name!=NULL){
					node *temp=lookup_CertScope((yyvsp[0].exprval)->symbol->name,0);
					node *temp2=lookup_AllScopes((yyvsp[0].exprval)->symbol->name,scope);
					if(temp!=NULL){
						if(temp->type==LIBFUNC)printf("\n ERROR in line %d. Cannot assign value to %s \n\n",yylineno,temp->name);
					}
					if(temp2!=NULL){
						if(temp2->type==USERFUNC){
							printf("\n ERROR in line %d. Cannot assign value to %s \n\n",yylineno,temp->name);
						}
					}
                    }
					}
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 477 "parser.y" /* yacc.c:1646  */
    {
						if ((yyvsp[-3].exprval)->type ==tableitem_e) {
							emit(tablesetelem, (yyvsp[-3].exprval), (yyvsp[-3].exprval)->index, (yyvsp[0].exprval),yylineno);
							(yyval.exprval) = emit_iftableitem((yyvsp[-3].exprval),yylineno);
							(yyval.exprval)->type=assignexpr_e;
						
						//ela kai pou sai
						  
						}else{
							emit(assign, (yyvsp[0].exprval), NULL, (yyvsp[-3].exprval),yylineno);
							
						}
							expr_e * tmp_exp=newexpr(var_e);
							tmp_exp->symbol=newtemp();
							emit(assign, (yyval.exprval), NULL, tmp_exp,yylineno);
					//$<exprval>$lvalue->symbol.var.type=Number;
			printf("lvalue=expr to assign expression\n");
			
			}
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 496 "parser.y" /* yacc.c:1646  */
    { printf("iiii\n"); (yyval.exprval) = emit_iftableitem((yyvsp[0].exprval),yylineno);printf("lvalue to primary\n");}
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 497 "parser.y" /* yacc.c:1646  */
    {printf("call to primary\n");}
#line 2125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 498 "parser.y" /* yacc.c:1646  */
    {printf("objectdef to primary\n");}
#line 2131 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 499 "parser.y" /* yacc.c:1646  */
    { (yyval.exprval)=(yyvsp[-1].exprval); printf("(funcdef) to primary\n");}
#line 2137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 500 "parser.y" /* yacc.c:1646  */
    {printf("const to primary\n");}
#line 2143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 504 "parser.y" /* yacc.c:1646  */
    {	
				node * temp = lookup_AllScopes(yytext,scope);
				node *symbol;
				if(temp != NULL){
					symbol=temp;
					if((temp->scope<scope) && (funcDef-1)>0 &&(temp->scope!=0) && (temp->type!=USERFUNC)){
						printf("\n ERROR in line :%d cannot access variable %s \n\n",yylineno,yytext);
					}
				}else{
					if(scope == 0){
						symbol=insertNode(yytext,scope,yylineno,GLOBL,currscopeoffset(),currscopespace()); 
						inccurrscopeoffset();
						
						
					}else{
						symbol=insertNode(yytext,scope,yylineno,LOCL,currscopeoffset(),currscopespace());//cursscopeoffset >2 kai oxi akairaio pollaplasio 
						inccurrscopeoffset();
					}
				}
				(yyval.exprval) = newexpr(var_e);
				(yyval.exprval)->symbol = symbol;
				
				printf("id to lvalue %s\n",yytext ); 
			}
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 528 "parser.y" /* yacc.c:1646  */
    {
				node * temp = lookup_CertScope(yytext,0);
				if(temp == NULL){
					printf("\n ERROR in line :%d GLOBal variable %s does not exists \n\n",yylineno,yytext);
				}else{
					(yyval.exprval) = newexpr(var_e);
				(yyval.exprval)->symbol = temp;
				}
				
				
				printf(" ::id to lvalue\n");
			}
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 540 "parser.y" /* yacc.c:1646  */
    { 
				node * temp = lookup_CertScope(yytext,scope);
				node *symbol;
	             if(temp == NULL){
					 if(scope == 0){
						symbol= insertNode(yytext,scope,yylineno,GLOBL,currscopeoffset(),currscopespace());
						 inccurrscopeoffset();
					 }else{
						symbol= insertNode(yytext,scope,yylineno,LOCL,currscopeoffset(),currscopespace());
						 inccurrscopeoffset();
					 }
					 (yyval.exprval) = newexpr(var_e);
				(yyval.exprval)->symbol = symbol;
				 }else{
					 printf("\n ERROR in line :%d local variable %s redefinition \n\n",yylineno,yytext);
				 }
				printf("LOCAL ID to lvalue\n");
			
			}
#line 2213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 561 "parser.y" /* yacc.c:1646  */
    {printf("member to lvalue\n"); }
#line 2219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 563 "parser.y" /* yacc.c:1646  */
    {
						(yyval.exprval)=member_item((yyvsp[-2].exprval),(yyvsp[0].strval),yylineno);
						printf("lvalue.identifier to member\n");
						}
#line 2228 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 567 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-3].exprval) = emit_iftableitem((yyvsp[-3].exprval),yylineno);
							(yyval.exprval) = newexpr (tableitem_e);
							(yyval.exprval)->symbol = (yyvsp[-3].exprval)->symbol;
							(yyval.exprval)->index = (yyvsp[-1].exprval);
							
								printf("lvalue expr to member\n");
						  }
#line 2240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 574 "parser.y" /* yacc.c:1646  */
    {printf("call.identifier to member\n");}
#line 2246 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 575 "parser.y" /* yacc.c:1646  */
    {printf("call expr to member\n");}
#line 2252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 577 "parser.y" /* yacc.c:1646  */
    { 
							(yyval.exprval)=make_call((yyvsp[-3].exprval),(yyvsp[-1].exprval),yylineno);//edw//
							printf("(elist)to call\n");
							elist_tmp = NULL;
							}
#line 2262 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 582 "parser.y" /* yacc.c:1646  */
    {printf("lvaluecallsuffix to call\n"); 
						if((yyvsp[0].exprval)->methodCalls.method==1){
							expr_e *self=(yyvsp[-1].exprval);
							
							
							(yyvsp[-1].exprval)=emit_iftableitem(member_item(self,(yyvsp[0].exprval)->methodCalls.name,yylineno),yylineno);//edw
							self->next = (yyvsp[0].exprval)->methodCalls.elist;
							(yyvsp[0].exprval)->methodCalls.elist = self;
							
						}
						printf("!!!!!!!!!lvalue null %s \n",(yyvsp[-1].strval));
						
						(yyval.exprval)=make_call((yyvsp[-1].exprval),(yyvsp[0].exprval)->methodCalls.elist,yylineno);
						printf("telos \n");}
#line 2281 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 596 "parser.y" /* yacc.c:1646  */
    {
							expr_e* func=newexpr(programfunc_e);
							func->symbol=(yyvsp[-4].exprval)->symbol;
							(yyval.exprval)=make_call(func,(yyvsp[-1].exprval),yylineno);//eedw
							elist_tmp = NULL;
							printf("(funcdef)(elist)to call\n");		
							}
#line 2293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 604 "parser.y" /* yacc.c:1646  */
    {	
						(yyval.strval)=(yyvsp[0].strval);
						printf("normcall to call suffix \n");//edw
						}
#line 2302 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 608 "parser.y" /* yacc.c:1646  */
    {
					(yyval.strval)=(yyvsp[0].strval);
					printf(" methodcall to call suffix\n");//edw
						}
#line 2311 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 613 "parser.y" /* yacc.c:1646  */
    {									
						(yyval.exprval) = newexpr(programfunc_e);
						if((yyval.exprval)->methodCalls.elist == NULL);
						(yyval.exprval)->methodCalls.elist=(yyvsp[-1].exprval);
						 (yyval.exprval)->methodCalls.method=0;
						(yyval.exprval)->methodCalls.name=NULL;//edw
						elist_tmp = NULL;
				printf("(elist)to normcall\n");
				}
#line 2325 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 622 "parser.y" /* yacc.c:1646  */
    {
						(yyval.exprval)->methodCalls.elist=(yyvsp[-1].exprval); //edw//
						(yyval.exprval)->methodCalls.method=1;
						(yyval.exprval)->methodCalls.name=strdup((yyvsp[-3].strval));
						elist_tmp = NULL;
						printf("method call");
						}
#line 2337 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 629 "parser.y" /* yacc.c:1646  */
    {elist_tmp = NULL;}
#line 2343 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 630 "parser.y" /* yacc.c:1646  */
    { 
					  if(elist_tmp == NULL){
											elist_tmp = (yyvsp[-2].exprval);
											while(elist_tmp->next != NULL) elist_tmp = elist_tmp->next;
											elist_tmp->next = (yyvsp[0].exprval);
											
					  }
					  elist_tmp->next = (yyvsp[0].exprval);
					  elist_tmp = (yyvsp[0].exprval);
											//printf("string %s \n",$<exprval>expr->symbol->name);
					  // tmp= elist->next=expr; elist->next-=expr; 
	}
#line 2360 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 642 "parser.y" /* yacc.c:1646  */
    {(yyval.exprval) = NULL; printf("helloooo\n");}
#line 2366 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 644 "parser.y" /* yacc.c:1646  */
    {
					printf("[elist] to objectdef \n");
					expr_e * t=newexpr(newtable_e);
					t->symbol=newtemp();
					emit(tablecreate, t,NULL,NULL,yylineno); 
					int i=0;
					expr_e *temp = (yyvsp[-1].exprval);
					expr_e *index_exp;
					while(temp != NULL){
						index_exp=newexpr(constnum_e);
						index_exp->numConst=i;
						emit(tablesetelem,t,index_exp,temp,yylineno);
						temp = temp->next;
						i++;
					}
					(yyval.exprval)=t;
					elist_tmp = NULL;
					}
#line 2389 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 662 "parser.y" /* yacc.c:1646  */
    {
							expr_e * t=newexpr(newtable_e);
					t->symbol=newtemp();
					emit(tablecreate, t,NULL,NULL,yylineno); 
					expr_e *temp = (yyvsp[-1].exprval);
					expr_e *index_exp;
					while(temp != NULL){
						emit(tablesetelem,t,temp->index,temp,yylineno);
						temp = temp->next;
						
					}
					(yyval.exprval)=t;
					
						printf("[indexed] to objectdef \n");}
#line 2408 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 677 "parser.y" /* yacc.c:1646  */
    { printf("indexedelem to indexed \n");}
#line 2414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 678 "parser.y" /* yacc.c:1646  */
    {
						  if(indexed_tmp == NULL){indexed_tmp = (yyvsp[-2].exprval);
											indexed_tmp->next = (yyvsp[0].exprval);}
					  indexed_tmp->next = (yyvsp[0].exprval);
					  indexed_tmp = (yyvsp[0].exprval);
				
					printf("indexe,indexelem to indexed\n");}
#line 2426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 687 "parser.y" /* yacc.c:1646  */
    {
				(yyval.exprval) = (yyvsp[-1].exprval);
				(yyval.exprval)->index = (yyvsp[-3].exprval);
				
				printf("{ Expr : Expr } to indexed\n");
				}
#line 2437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 694 "parser.y" /* yacc.c:1646  */
    {}
#line 2443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 695 "parser.y" /* yacc.c:1646  */
    {}
#line 2449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 697 "parser.y" /* yacc.c:1646  */
    {scope++;if(funcDef>0)enterscopespace();}
#line 2455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 697 "parser.y" /* yacc.c:1646  */
    {
																	hide(scope);  
																	scope--;}
#line 2463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 700 "parser.y" /* yacc.c:1646  */
    {printf("block\n");}
#line 2469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 701 "parser.y" /* yacc.c:1646  */
    {
			node * temp = lookup_AllScopes(yytext,scope);
			node * temp2=lookup_CertScope(yytext,scope);
			if(temp == NULL){
				temp=insertNode(yytext,scope,yylineno,USERFUNC,currscopeoffset(),currscopespace());
				
				expr_e *exp = newexpr(programfunc_e);
				exp->symbol=temp;
				(yyvsp[-1].exprval)=exp;
				emit(funcstart,exp,NULL,NULL,yylineno);
				temp->iadress=quad_count+1;
				inccurrscopeoffset();
			}else if(temp->type == LIBFUNC){
				printf("\n ERROR in line %d. Shadowing of libfunc %s \n\n",yylineno,yytext);
			}else if(temp2!=NULL && temp2->type == USERFUNC){
				printf("\n ERROR in line %d. Function %s redefinition \n\n",yylineno,yytext);
			}else if((temp->scope == scope) && (temp->type != USERFUNC)){
				printf("\n ERROR in line %d. %s is already defined as var \n\n",yylineno,yytext);
			}else if((temp->scope<scope)){
				
				temp=insertNode(yytext,scope,yylineno,USERFUNC,currscopeoffset(),currscopespace());
				expr_e *exp = newexpr(programfunc_e);
				exp->symbol=temp;
				(yyvsp[0].exprval)=exp;
				emit(funcstart,exp,NULL,NULL,yylineno);
				temp->iadress=quad_count+1;
				inccurrscopeoffset();
			}
		push(&loopstack,loop);
		loop=0;
		funcDef++;
		
		
		if(funcDef>1){
			offsets_table[scopeSpaceCounter]= currscopeoffset();
			functionLocalOffset=0;
			formalArgOffset=0;
		}
		
		
     }
#line 2515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 742 "parser.y" /* yacc.c:1646  */
    {enterscopespace();}
#line 2521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 742 "parser.y" /* yacc.c:1646  */
    {if(funcDef>0){	(yyvsp[-7].exprval)->symbol->locals_count=functionLocalOffset+1;
																		exitscopespace(); 
																		exitscopespace(); 
																		functionLocalOffset=offsets_table[scopeSpaceCounter];
																		
																	}  
																	emit(funcend,(yyvsp[-7].exprval),NULL,NULL,yylineno);
																	funcDef--;loop=pop(&loopstack);printf("function def \n");}
#line 2534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 750 "parser.y" /* yacc.c:1646  */
    {node *temp= insertAnon(scope,yylineno,currscopeoffset(),currscopespace());
			expr_e *exp=newexpr(programfunc_e);
			exp->symbol=temp;
			(yyvsp[0].exprval)=exp;
			emit(funcstart,exp,NULL,NULL,yylineno);
			temp->iadress=quad_count+1;
			
			inccurrscopeoffset();
			push(&loopstack,loop);
		   loop=0;
			funcDef++;
			if(funcDef>1){
					offsets_table[scopeSpaceCounter]= currscopeoffset();
					functionLocalOffset=0;
					formalArgOffset=0;
			}
			printf("temp_id <- empty\n");}
#line 2556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 767 "parser.y" /* yacc.c:1646  */
    {enterscopespace();}
#line 2562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 767 "parser.y" /* yacc.c:1646  */
    { if(funcDef>0){(yyvsp[-6].exprval)->symbol->locals_count=functionLocalOffset+1;
																		exitscopespace(); 
																		exitscopespace(); 
																		functionLocalOffset=offsets_table[scopeSpaceCounter];
																	} emit(funcend,(yyvsp[-6].exprval),NULL,NULL,yylineno);funcDef--;loop=pop(&loopstack);printf("function def \n");}
#line 2572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 774 "parser.y" /* yacc.c:1646  */
    {
     (yyval.exprval)=newexpr(constnum_e);
	 (yyval.exprval)->numConst=yylval.intval;
	 printf("NUMBER %d\n",yylval.intval);
	 
	
	}
#line 2584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 781 "parser.y" /* yacc.c:1646  */
    {
	 (yyval.exprval)=newexpr(constnum_e);
	 (yyval.exprval)->numConst=yylval.realval;
		printf("REALNUMBER %s\n",yytext);}
#line 2593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 785 "parser.y" /* yacc.c:1646  */
    {
		(yyval.exprval)=newexpr(conststring_e);
	 (yyval.exprval)->strConst=strdup(yylval.strval);
		printf("STRING to const\n");}
#line 2602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 789 "parser.y" /* yacc.c:1646  */
    {
		(yyval.exprval)=newexpr(nil_e);
		(yyval.exprval)->strConst=strdup("NIL");
			printf("NIL to const \n");
				}
#line 2612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 794 "parser.y" /* yacc.c:1646  */
    {
				(yyval.exprval)=newexpr(constbool_e);
			(yyval.exprval)->boolConst=1;
			printf("TRUE to const\n");
			}
#line 2622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 799 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exprval)=newexpr(constbool_e);
			(yyval.exprval)->boolConst=0;
		printf("FALSE to const\n");
	}
#line 2632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 805 "parser.y" /* yacc.c:1646  */
    {	node * temp = lookup_CertScope(yytext,0);
				if((temp != NULL) && (temp->type == LIBFUNC)){
					printf("\n ERROR in line %d. %s cannot be an argument \n\n",yylineno,yytext);
				}else{
					insertNode(yytext,scope+1,yylineno,FORMAL,currscopeoffset(),currscopespace());
					inccurrscopeoffset();
				}
			printf("ID to idlist\n");
			}
#line 2646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 814 "parser.y" /* yacc.c:1646  */
    {node * temp = lookup_CertScope(yytext,scope + 1);
					  node * temp2 = lookup_CertScope(yytext,0);
						if((temp2 != NULL) && (temp2->type == LIBFUNC)){
							printf("\n ERROR in line %d. %s cannot be an argument \n\n",yylineno,yytext);
						}else if((temp != NULL) && (temp->type == FORMAL)){
							printf("\n ERROR in line %d. argument redefinition\n\n",yylineno);
						}else{
							
							insertNode(yytext,scope+1,yylineno,FORMAL,currscopeoffset(),currscopespace()); 
							inccurrscopeoffset();
						}
		printf("idlist comma to idlist\n");
		}
#line 2664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 827 "parser.y" /* yacc.c:1646  */
    {;}
#line 2670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 829 "parser.y" /* yacc.c:1646  */
    {
	
				expr_e *trueExp=newexpr(boolexpr_e);
				trueExp->boolConst=1;
				emit_Realop(if_eq, (yyvsp[-1].exprval), trueExp,nextquad()+4);
			
				emit_Realop(jump,NULL,NULL,0);
					push(&ifstack,nextquad()); 
			}
#line 2684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 837 "parser.y" /* yacc.c:1646  */
    {
				t=pop(&ifstack);
				patchlabel(t,nextquad()+2);
				printf("if()\n");
			}
#line 2694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 842 "parser.y" /* yacc.c:1646  */
    {patchlabel(t,nextquad()+3);}
#line 2700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 842 "parser.y" /* yacc.c:1646  */
    {
			emit_Realop(jump,NULL,NULL,0);
					push(&ifstack,nextquad()); 
				}
#line 2709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 846 "parser.y" /* yacc.c:1646  */
    {
					
					patchlabel(pop(&ifstack),nextquad()+2);
					printf("ifelse stmt \n");
					}
#line 2719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 852 "parser.y" /* yacc.c:1646  */
    {push(&ifstack,nextquad()+2); }
#line 2725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 852 "parser.y" /* yacc.c:1646  */
    { scope++;loop++; set_loop(loop);}
#line 2731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 852 "parser.y" /* yacc.c:1646  */
    {
																	expr_e *tr=newexpr(constbool_e);
																	tr->boolConst=1;
																	emit_Realop(if_eq,(yyvsp[-1].exprval),tr,nextquad()+4);
																	
																	emit_Realop(jump,NULL,NULL,0);
																	push(&ifstack,nextquad());
																	scope--;
																	}
#line 2745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 860 "parser.y" /* yacc.c:1646  */
    {
																		
																				int temp1=pop(&ifstack);
																				int temp2=pop(&ifstack);
																				
																				printf("temp2 %d nex %d \n",temp2,nextquad()+2);
																				emit_Realop(jump,NULL,NULL,temp2);
																				patchlabel(temp1,nextquad()+2);
																				t = pop(&breakstack);
																				while(t != -1){
																				patchlabel(t,nextquad()+2);
																				t = pop(&breakstack);
																				}
																				t = pop(&continuestack);
																				while(t != -1){
																				patchlabel(t,temp2);
																				t = pop(&continuestack);
																				}
																				loop--; set_loop(loop);printf("while()stmt\n");
																				}
#line 2770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 880 "parser.y" /* yacc.c:1646  */
    {
	emit_Realop(jump,NULL,NULL,0);
	(yyval.intval)=nextquad();

	}
#line 2780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 886 "parser.y" /* yacc.c:1646  */
    {(yyval.intval)=nextquad();}
#line 2786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 888 "parser.y" /* yacc.c:1646  */
    {scope++;loop++;set_loop(loop); }
#line 2792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 888 "parser.y" /* yacc.c:1646  */
    {}
#line 2798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 888 "parser.y" /* yacc.c:1646  */
    { 
															(yyval.forprefix.test)=(yyvsp[-3].intval);
															printf("for.test %d \n",(yyvsp[-3].intval));
															expr_e *tr=newexpr(constbool_e);
															tr->boolConst=1;
															
															emit_Realop(if_eq,(yyvsp[-2].exprval),tr,0);
															
															(yyval.forprefix.enter)=nextquad();
															}
#line 2813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 898 "parser.y" /* yacc.c:1646  */
    {}
#line 2819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 898 "parser.y" /* yacc.c:1646  */
    {scope--;}
#line 2825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 898 "parser.y" /* yacc.c:1646  */
    {
																
																	printf("n1=%d\n",(yyvsp[-7].intval));
																	patchlabel((yyval.forprefix.enter),((yyvsp[-2].intval))+2);
																	printf("n2=%d\n",(yyvsp[-2].intval));
																	
																	patchlabel((yyvsp[-7].intval),nextquad()+2);
																	printf("n3=%d\n",(yyvsp[0].intval));
																	patchlabel((yyvsp[-2].intval),(yyval.forprefix.test)+2);
																	
																	patchlabel((yyvsp[0].intval),((yyvsp[-7].intval))+3);
																	t = pop(&breakstack);
																				while(t != -1){
																				patchlabel(t,nextquad()+2);
																				t = pop(&breakstack);
																				}
																				t = pop(&continuestack);
																				while(t != -1){
																				patchlabel(t,((yyvsp[-7].intval))+3);
																				t = pop(&continuestack);
																				}
																				loop--; set_loop(loop);
																	printf("FOR (ELIST;EXPR;ELIST)STMT\n");
															
																	}
#line 2855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 924 "parser.y" /* yacc.c:1646  */
    {printf("returnstmt\n");
								emit(ret,NULL,NULL,NULL,yylineno);
						}
#line 2863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 927 "parser.y" /* yacc.c:1646  */
    {printf("returnstmt with expr\n");
							emit(ret,(yyvsp[-1].exprval),NULL,NULL,yylineno);
					}
#line 2871 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2875 "y.tab.c" /* yacc.c:1646  */
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
#line 930 "parser.y" /* yacc.c:1906  */

int yyerror (const char * YaccProvidedMessage)
{	
	fprintf(stderr,"%s: at line %d,before token: %s\n",YaccProvidedMessage,yylineno,yytext);
	fprintf(stderr,"INPUT NOT VALID \n");
}


int main(int argc,char **argv)
{
		
	init_stacks();
	init_offsets_table();
	insert_libfunc();
	
	flag=1;
	
	yyparse();
    print_quads();
	print();

	return 0;
}
