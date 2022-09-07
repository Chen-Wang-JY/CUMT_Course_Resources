
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 3 "cgrammar-new.y"


#include "parser.h"

extern int yylineno;
extern int root;

extern int yylex();
extern void addchild( Node * node1, Node * node2 );
Node * link(int tid, Node * rExp, ... );

struct Node * parse_tree;


/* Line 189 of yacc.c  */
#line 88 "cgrammar-new.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     COLON = 258,
     OR_OP = 259,
     AND_OP = 260,
     NE_OP = 261,
     EQ_OP = 262,
     GE_OP = 263,
     LE_OP = 264,
     RIGHT_OP = 265,
     LEFT_OP = 266,
     IDENTIFIER = 267,
     CONSTANT = 268,
     STRING_LITERAL = 269,
     SIZEOF = 270,
     PTR_OP = 271,
     INC_OP = 272,
     DEC_OP = 273,
     MUL_ASSIGN = 274,
     DIV_ASSIGN = 275,
     MOD_ASSIGN = 276,
     ADD_ASSIGN = 277,
     SUB_ASSIGN = 278,
     LEFT_ASSIGN = 279,
     RIGHT_ASSIGN = 280,
     AND_ASSIGN = 281,
     XOR_ASSIGN = 282,
     OR_ASSIGN = 283,
     TYPE_NAME = 284,
     TYPEDEF = 285,
     EXTERN = 286,
     STATIC = 287,
     AUTO = 288,
     REGISTER = 289,
     CHAR = 290,
     SHORT = 291,
     INT = 292,
     LONG = 293,
     SIGNED = 294,
     UNSIGNED = 295,
     FLOAT = 296,
     DOUBLE = 297,
     CONST = 298,
     VOLATILE = 299,
     VOID = 300,
     STRUCT = 301,
     UNION = 302,
     ENUM = 303,
     ELLIPSIS = 304,
     CASE = 305,
     DEFAULT = 306,
     IF = 307,
     ELSE = 308,
     SWITCH = 309,
     WHILE = 310,
     DO = 311,
     FOR = 312,
     GOTO = 313,
     CONTINUE = 314,
     BREAK = 315,
     RETURN = 316,
     LOWER_THAN_ELSE = 317
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 17 "cgrammar-new.y"

  struct Node * node;



/* Line 214 of yacc.c  */
#line 192 "cgrammar-new.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 204 "cgrammar-new.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  61
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1410

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  203
/* YYNRULES -- Number of states.  */
#define YYNSTATES  356

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   317

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    81,     2,     2,     2,    22,     9,     2,
      74,    75,    20,    18,    79,    19,    78,    21,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    82,    84,
      12,    83,    13,     3,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    76,     2,    77,     8,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    85,     7,    86,    80,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     4,     5,
       6,    10,    11,    14,    15,    16,    17,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    13,    15,    20,    24,
      29,    33,    37,    40,    43,    45,    49,    51,    54,    57,
      60,    63,    66,    69,    72,    75,    78,    83,    85,    90,
      92,    98,   102,   106,   110,   114,   118,   122,   126,   130,
     134,   138,   142,   146,   150,   154,   158,   162,   166,   170,
     172,   176,   180,   184,   188,   192,   196,   200,   204,   208,
     212,   216,   218,   222,   224,   227,   231,   233,   236,   238,
     241,   243,   246,   248,   252,   254,   258,   260,   262,   264,
     266,   268,   270,   272,   274,   276,   278,   280,   282,   284,
     286,   288,   290,   292,   294,   296,   298,   301,   307,   312,
     315,   321,   326,   329,   331,   334,   338,   341,   343,   346,
     348,   350,   354,   356,   359,   363,   368,   374,   377,   379,
     383,   385,   389,   392,   394,   396,   400,   405,   409,   414,
     419,   423,   425,   428,   431,   435,   437,   441,   443,   447,
     450,   453,   455,   457,   461,   463,   466,   468,   470,   473,
     477,   480,   484,   488,   493,   496,   500,   504,   509,   511,
     515,   520,   522,   526,   530,   535,   539,   541,   543,   546,
     552,   560,   566,   572,   580,   590,   594,   597,   600,   603,
     607,   608,   610,   611,   613,   614,   616,   619,   623,   627,
     632,   634,   637,   639,   642,   644,   647,   649,   651,   654,
     658,   661,   664,   666
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     133,     0,    -1,    23,    -1,    24,    -1,    25,    -1,    74,
      95,    75,    -1,    88,    -1,    89,    76,    95,    77,    -1,
      89,    74,    75,    -1,    89,    74,    90,    75,    -1,    89,
      78,    23,    -1,    89,    27,    23,    -1,    89,    28,    -1,
      89,    29,    -1,    94,    -1,    90,    79,    94,    -1,    89,
      -1,    28,    91,    -1,    29,    91,    -1,     9,    92,    -1,
      20,    92,    -1,    18,    92,    -1,    19,    92,    -1,    80,
      92,    -1,    81,    92,    -1,    26,    91,    -1,    26,    74,
     121,    75,    -1,    91,    -1,    74,   121,    75,    92,    -1,
      92,    -1,    93,     3,    95,    82,    93,    -1,    93,     5,
      93,    -1,    93,     6,    93,    -1,    93,     7,    93,    -1,
      93,     8,    93,    -1,    93,     9,    93,    -1,    93,    11,
      93,    -1,    93,    10,    93,    -1,    93,    12,    93,    -1,
      93,    13,    93,    -1,    93,    15,    93,    -1,    93,    14,
      93,    -1,    93,    17,    93,    -1,    93,    16,    93,    -1,
      93,    18,    93,    -1,    93,    19,    93,    -1,    93,    20,
      93,    -1,    93,    21,    93,    -1,    93,    22,    93,    -1,
      93,    -1,    91,    83,    94,    -1,    91,    30,    94,    -1,
      91,    31,    94,    -1,    91,    32,    94,    -1,    91,    33,
      94,    -1,    91,    34,    94,    -1,    91,    35,    94,    -1,
      91,    36,    94,    -1,    91,    37,    94,    -1,    91,    38,
      94,    -1,    91,    39,    94,    -1,    94,    -1,    95,    79,
      94,    -1,    93,    -1,    98,    84,    -1,    98,    99,    84,
      -1,   101,    -1,   101,    98,    -1,   102,    -1,   102,    98,
      -1,   103,    -1,   103,    98,    -1,   100,    -1,    99,    79,
     100,    -1,   114,    -1,   114,    83,   124,    -1,    41,    -1,
      42,    -1,    43,    -1,    44,    -1,    45,    -1,    56,    -1,
      46,    -1,    47,    -1,    48,    -1,    49,    -1,    52,    -1,
      53,    -1,    50,    -1,    51,    -1,   105,    -1,   111,    -1,
      40,    -1,    54,    -1,    55,    -1,   103,    -1,   104,   103,
      -1,    57,    23,    85,   106,    86,    -1,    57,    85,   106,
      86,    -1,    57,    23,    -1,    58,    23,    85,   106,    86,
      -1,    58,    85,   106,    86,    -1,    58,    23,    -1,   107,
      -1,   106,   107,    -1,   108,   109,    84,    -1,   102,   108,
      -1,   102,    -1,   103,   108,    -1,   103,    -1,   110,    -1,
     109,    79,   110,    -1,   114,    -1,    82,    96,    -1,   114,
      82,    96,    -1,    59,    85,   112,    86,    -1,    59,    23,
      85,   112,    86,    -1,    59,    23,    -1,   113,    -1,   112,
      79,   113,    -1,    23,    -1,    23,    83,    96,    -1,   116,
     115,    -1,   115,    -1,    23,    -1,    74,   114,    75,    -1,
     115,    76,    96,    77,    -1,   115,    76,    77,    -1,   115,
      74,   117,    75,    -1,   115,    74,   120,    75,    -1,   115,
      74,    75,    -1,    20,    -1,    20,   104,    -1,    20,   116,
      -1,    20,   104,   116,    -1,   118,    -1,   118,    79,    60,
      -1,   119,    -1,   118,    79,   119,    -1,    98,   114,    -1,
      98,   122,    -1,    98,    -1,    23,    -1,   120,    79,    23,
      -1,   108,    -1,   108,   122,    -1,   116,    -1,   123,    -1,
     116,   123,    -1,    74,   122,    75,    -1,    76,    77,    -1,
      76,    96,    77,    -1,   123,    76,    77,    -1,   123,    76,
      96,    77,    -1,    74,    75,    -1,    74,   117,    75,    -1,
     123,    74,    75,    -1,   123,    74,   117,    75,    -1,    94,
      -1,    85,   125,    86,    -1,    85,   125,    79,    86,    -1,
     124,    -1,   125,    79,   124,    -1,    23,    82,   126,    -1,
      61,    96,    82,   126,    -1,    62,    82,   126,    -1,   130,
      -1,    84,    -1,    95,    84,    -1,    63,    74,    95,    75,
     126,    -1,    63,    74,    95,    75,   126,    64,   126,    -1,
      65,    74,    95,    75,   126,    -1,    66,    74,    95,    75,
     126,    -1,    67,   126,    66,    74,    95,    75,    84,    -1,
      68,    74,   127,    84,   128,    84,   129,    75,   126,    -1,
      69,    23,    84,    -1,    70,    84,    -1,    71,    84,    -1,
      72,    84,    -1,    72,    95,    84,    -1,    -1,    95,    -1,
      -1,    95,    -1,    -1,    95,    -1,    85,    86,    -1,    85,
     132,    86,    -1,    85,   131,    86,    -1,    85,   131,   132,
      86,    -1,    97,    -1,   131,    97,    -1,   126,    -1,   132,
     126,    -1,   134,    -1,   133,   134,    -1,   135,    -1,    97,
      -1,   136,   137,    -1,    98,   114,   131,    -1,    98,   114,
      -1,   114,   131,    -1,   114,    -1,   130,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    71,    71,    72,    73,    74,    78,    79,    80,    81,
      82,    83,    84,    85,    89,    90,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   108,   109,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   151,   152,   156,   160,   161,   165,   166,   167,   168,
     169,   170,   174,   175,   179,   180,   184,   185,   186,   187,
     188,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   207,   208,   212,   213,   217,   218,   219,
     220,   221,   222,   227,   228,   232,   236,   237,   238,   239,
     243,   244,   248,   249,   250,   254,   255,   256,   260,   261,
     265,   266,   270,   271,   275,   276,   277,   278,   279,   280,
     281,   285,   286,   287,   288,   292,   293,   297,   298,   302,
     303,   304,   308,   309,   313,   314,   318,   319,   320,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   336,   337,
     338,   342,   343,   347,   348,   349,   351,   352,   353,   355,
     356,   357,   359,   360,   361,   363,   364,   365,   366,   367,
     371,   372,   376,   377,   381,   382,   386,   387,   388,   389,
     393,   394,   398,   399,   403,   404,   408,   409,   413,   417,
     418,   419,   420,   424
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'?'", "COLON", "OR_OP", "AND_OP", "'|'",
  "'^'", "'&'", "NE_OP", "EQ_OP", "'<'", "'>'", "GE_OP", "LE_OP",
  "RIGHT_OP", "LEFT_OP", "'+'", "'-'", "'*'", "'/'", "'%'", "IDENTIFIER",
  "CONSTANT", "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "CHAR",
  "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST",
  "VOLATILE", "VOID", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "LOWER_THAN_ELSE", "'('", "')'", "'['",
  "']'", "'.'", "','", "'~'", "'!'", "':'", "'='", "';'", "'{'", "'}'",
  "$accept", "PrimaryExp", "PostfixExp", "ArgExpList", "UnaryExp",
  "CastExp", "CondExp", "AssignExp", "Exp", "ConstExp", "Declaration",
  "Declaration_Spec", "init_decl_s", "init_decl", "StorageSpec",
  "TypeSpec", "TypeQua", "TypeQua_s", "StructUnionSpec",
  "struct_Declaration_s", "struct_Declaration", "SpecQua_s",
  "struct_decl_s", "struct_decl", "EnumSpec", "Enum_s", "Enum",
  "declarator", "direct_decl", "pointer", "ParamType_s", "Param_s",
  "Param_Declaration", "Ident_s", "type_name", "abs_decl",
  "direct_abs_decl", "Init", "Init_s", "Stmt", "Exp1", "Exp2", "Exp3",
  "Block", "Declaration_s", "Stmt_s", "TransUnit", "ExternalDef",
  "FunctionDef", "FunctionDecl", "FunctionBody", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    63,   258,   259,   260,   124,    94,    38,
     261,   262,    60,    62,   263,   264,   265,   266,    43,    45,
      42,    47,    37,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,    40,    41,    91,    93,    46,    44,
     126,    33,    58,    61,    59,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    87,    88,    88,    88,    88,    89,    89,    89,    89,
      89,    89,    89,    89,    90,    90,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    92,    92,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    95,    95,    96,    97,    97,    98,    98,    98,    98,
      98,    98,    99,    99,   100,   100,   101,   101,   101,   101,
     101,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   103,   103,   104,   104,   105,   105,   105,
     105,   105,   105,   106,   106,   107,   108,   108,   108,   108,
     109,   109,   110,   110,   110,   111,   111,   111,   112,   112,
     113,   113,   114,   114,   115,   115,   115,   115,   115,   115,
     115,   116,   116,   116,   116,   117,   117,   118,   118,   119,
     119,   119,   120,   120,   121,   121,   122,   122,   122,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   124,   124,
     124,   125,   125,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     127,   127,   128,   128,   129,   129,   130,   130,   130,   130,
     131,   131,   132,   132,   133,   133,   134,   134,   135,   136,
     136,   136,   136,   137
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     4,     1,     4,     1,
       5,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     1,     2,     3,     1,     2,     1,     2,
       1,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     5,     4,     2,
       5,     4,     2,     1,     2,     3,     2,     1,     2,     1,
       1,     3,     1,     2,     3,     4,     5,     2,     1,     3,
       1,     3,     2,     1,     1,     3,     4,     3,     4,     4,
       3,     1,     2,     2,     3,     1,     3,     1,     3,     2,
       2,     1,     1,     3,     1,     2,     1,     1,     2,     3,
       2,     3,     3,     4,     2,     3,     3,     4,     1,     3,
       4,     1,     3,     3,     4,     3,     1,     1,     2,     5,
       7,     5,     5,     7,     9,     3,     2,     2,     2,     3,
       0,     1,     0,     1,     0,     1,     2,     3,     3,     4,
       1,     2,     1,     2,     1,     2,     1,     1,     2,     3,
       2,     2,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   131,   124,    92,    76,    77,    78,    79,    80,    82,
      83,    84,    85,    88,    89,    86,    87,    93,    94,    81,
       0,     0,     0,     0,   197,     0,    66,    68,    70,    90,
      91,   202,   123,     0,     0,   194,   196,     0,    95,   132,
     133,    99,     0,   102,     0,   117,     0,     0,    64,     0,
      72,    74,    67,    69,    71,   190,     0,   201,     0,     0,
     122,     1,   195,     0,   203,   198,    96,   134,     0,   107,
     109,     0,   103,     0,     0,     0,     0,   120,     0,   118,
     125,     0,    65,     0,   199,    74,   191,   142,   130,   141,
       0,   135,   137,     0,     0,     0,     0,     0,     2,     3,
       4,     0,     0,     0,     0,   127,     0,     0,     6,    16,
      27,    29,    63,     0,     2,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   167,   186,    27,    49,
      61,     0,   192,   166,     0,     0,     0,   106,   108,    98,
     104,     0,     0,   110,   112,     0,   101,     0,     0,     0,
     115,    73,     0,   158,    75,     0,     0,   139,   146,   140,
     147,   128,     0,   129,     0,    19,    21,    22,    20,     0,
      25,     0,    17,    18,     0,   144,     0,    23,    24,     0,
      12,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   126,     0,     0,     0,     0,     0,
       0,     0,   180,     0,   176,   177,   178,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     168,   188,     0,   187,   193,    97,   113,     0,   105,     0,
     100,   116,   121,   119,   161,     0,   154,     0,     0,   150,
       0,   148,     0,     0,   136,   138,   143,     0,     5,     0,
     146,   145,     0,    11,     8,     0,    14,     0,    10,     0,
      31,    32,    33,    34,    35,    37,    36,    38,    39,    41,
      40,    43,    42,    44,    45,    46,    47,    48,   163,     0,
     165,     0,     0,     0,     0,   181,     0,   175,   179,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    50,
      62,   189,   111,   114,     0,   159,   155,   149,   151,   156,
       0,   152,     0,    26,    28,     9,     0,     7,     0,   164,
       0,     0,     0,     0,   182,   160,   162,   157,   153,    15,
      30,   169,   171,   172,     0,   183,     0,     0,     0,   184,
     170,   173,   185,     0,     0,   174
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   108,   109,   265,   128,   111,   129,   130,   131,   113,
      55,    56,    49,    50,    26,    27,    28,    39,    29,    71,
      72,    73,   142,   143,    30,    78,    79,    31,    32,    33,
     247,    91,    92,    93,   176,   248,   160,   154,   245,   132,
     296,   346,   353,   133,    57,   135,    34,    35,    36,    37,
      65
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -156
static const yytype_int16 yypact[] =
{
     985,    38,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,
     -17,   -10,    -8,    50,  -156,     4,  1238,  1238,  1238,  -156,
    -156,  1238,   -44,     5,   675,  -156,  -156,   -40,  -156,    38,
    -156,   -31,  1258,   -19,  1258,    -9,    63,    20,  -156,   -63,
    -156,  1161,  -156,  -156,  -156,  -156,     4,  1238,  1023,   685,
     -44,  -156,  -156,   341,  -156,  -156,  -156,  -156,  1258,  1258,
    1258,  1053,  -156,    39,  1258,  1073,    63,    11,   -45,  -156,
    -156,    50,  -156,   612,  1238,    36,  -156,  -156,  -156,    40,
      99,   104,  -156,    47,   828,   828,   828,   828,  -156,  -156,
    -156,   863,   892,   892,   727,  -156,   828,   828,  -156,   238,
    -156,  -156,  1176,   107,   109,   828,   110,   125,   145,   181,
     600,   187,   190,   180,   186,   197,  -156,  -156,   979,  1176,
    -156,    19,  -156,  -156,   410,   479,  1094,  -156,  -156,  -156,
    -156,   828,    97,  -156,   191,  1114,  -156,    87,   828,    63,
    -156,  -156,   612,  -156,  -156,   905,   786,  -156,    30,  -156,
      49,  -156,  1217,  -156,   256,  -156,  -156,  -156,  -156,   727,
    -156,   828,  -156,  -156,   111,    44,   205,  -156,  -156,   266,
    -156,  -156,   804,   828,   267,   828,   828,   828,   828,   828,
     828,   828,   828,   828,   828,   828,   828,   828,   828,   828,
     828,   828,   828,   828,  -156,   600,   211,   600,   828,   828,
     828,   225,   828,   213,  -156,  -156,  -156,   103,   828,   828,
     828,   828,   828,   828,   828,   828,   828,   828,   828,   828,
    -156,  -156,   505,  -156,  -156,  -156,  -156,    39,  -156,   828,
    -156,  -156,  -156,  -156,  -156,    93,  -156,   223,   224,  -156,
     227,    49,  1181,   816,  -156,  -156,  -156,   230,  -156,   945,
     155,  -156,   828,  -156,  -156,   118,  -156,   209,  -156,   169,
    1330,  1346,  1361,  1375,  1388,  1035,  1035,   309,   309,   309,
     309,   189,   189,   263,   263,  -156,  -156,  -156,  -156,   600,
    -156,   126,   139,   149,   234,   231,   229,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,   574,  -156,  -156,  -156,  -156,  -156,
     240,  -156,   242,  -156,  -156,  -156,   828,  -156,   828,  -156,
     600,   600,   600,   828,   828,  -156,  -156,  -156,  -156,  -156,
    1313,   245,  -156,  -156,   175,   231,   233,   600,   236,   828,
    -156,  -156,   231,   246,   600,  -156
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -156,  -156,  -156,  -156,   -59,   -87,   -41,    18,  -100,   -76,
      33,    23,  -156,   241,  -156,   232,   188,  -156,  -156,   -13,
     -49,   -58,  -156,    86,  -156,   259,   192,   179,     7,    13,
     -57,  -156,   176,  -156,   168,   -84,  -155,  -150,  -156,   -36,
    -156,  -156,  -156,   302,   -34,   206,  -156,   308,  -156,  -156,
    -156
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -201
static const yytype_int16 yytable[] =
{
     110,    90,   244,   251,   174,   159,    41,   165,   166,   167,
     168,   137,   138,    43,    40,    45,    81,    84,   112,   177,
     178,    82,   140,    25,     1,   217,   140,     2,     2,   134,
      58,    75,    59,    24,   149,   110,   110,   110,   110,   206,
      60,   150,   170,   172,   173,    63,   175,   110,   110,    52,
      53,    54,    67,     2,    68,   136,   110,    25,     1,     1,
       1,   145,     2,     2,     1,   236,    74,    24,    42,   174,
       1,   174,   242,     2,   112,    44,    76,    46,    23,    23,
     250,    89,   110,   267,   211,   269,    77,   140,    48,   110,
      86,   261,    17,    18,   148,    80,   140,   110,   229,   234,
     112,   153,   158,   230,   155,   251,   156,   112,   291,   292,
     293,   175,   295,    23,   155,   112,   156,    86,   259,    83,
     156,   141,   163,   252,    23,   253,   164,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   313,   336,    60,   149,    86,   158,   288,
     153,   290,   314,   241,   161,   324,   237,   322,    89,   315,
     110,   238,   229,   162,   204,    89,   258,   298,   260,    38,
     229,   205,   207,   325,   110,   320,   234,   326,   112,   208,
     266,   330,    47,   110,    51,   229,    94,   199,   200,   201,
     202,   203,   112,   213,   331,    95,    96,    97,   229,   209,
      98,    99,   100,   101,   332,   102,   103,    66,   229,   259,
      70,   156,    70,   344,   345,    85,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   229,   352,
     348,   328,   144,   329,   229,   210,    70,    70,    70,    70,
      85,   212,    70,    70,   214,   179,   180,   181,   157,   110,
     215,   104,   260,   239,    69,    89,    69,   106,   107,   256,
     262,   216,    89,   201,   202,   203,   327,   340,   229,   263,
     268,   294,    70,   289,   341,   342,   343,   297,   316,   317,
      69,    69,    69,    69,   318,   323,    69,    69,   333,   347,
     229,   350,   182,   334,   183,   337,   184,   349,   355,   338,
     351,   354,   151,   312,    70,   197,   198,   199,   200,   201,
     202,   203,   153,    70,    47,   147,    69,   257,   255,    64,
     232,   243,    62,     0,   339,     0,     0,     0,     0,     0,
      94,     0,     0,     0,     0,     0,     0,    70,     0,    95,
      96,    97,     0,     0,   114,    99,   100,   101,    69,   102,
     103,     0,     0,     0,     0,     0,     0,    69,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    69,   115,   116,   117,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   104,   144,     0,     0,    94,
       0,   106,   107,     0,     0,   126,    63,   127,    95,    96,
      97,     0,     0,   114,    99,   100,   101,     0,   102,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
       0,   115,   116,   117,     0,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   104,     0,     0,     0,    94,     0,
     106,   107,     0,     0,   126,    63,   231,    95,    96,    97,
       0,     0,   114,    99,   100,   101,     0,   102,   103,     0,
       0,     0,     0,     0,    94,     0,     0,     0,     0,     0,
       0,     0,     0,    95,    96,    97,     0,     0,   114,    99,
     100,   101,     0,   102,   103,     0,     0,     0,     0,     0,
     115,   116,   117,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   104,     0,     0,     0,     0,     0,   106,
     107,     0,     0,   126,    63,   233,   115,   116,   117,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   104,
       0,     0,     0,    94,     0,   106,   107,     0,     0,   126,
      63,   311,    95,    96,    97,     0,     0,    98,    99,   100,
     101,     0,   102,   103,     0,     0,     0,     0,     0,    94,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    96,
      97,    94,     0,   114,    99,   100,   101,     0,   102,   103,
      95,    96,    97,     0,     0,    98,    99,   100,   101,     0,
     102,   103,     0,     0,     0,     0,     0,     0,   104,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,   152,
     335,   115,   116,   117,     0,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   104,    61,     0,     0,     0,     0,
     106,   107,     0,     0,   126,    63,   104,     0,     0,     0,
       0,     0,   106,   107,    94,     1,     0,   152,     2,     0,
       0,     0,     0,    95,    96,    97,     0,     0,    98,    99,
     100,   101,     0,   102,   103,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,     0,    94,     0,     0,     0,
       0,     0,     0,     0,     0,    95,    96,    97,     0,    23,
      98,    99,   100,   101,     0,   102,   103,     0,     0,   104,
       0,     0,   105,     0,     0,   106,   107,     3,     0,     0,
       0,     0,     0,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,     0,     0,     0,
       0,     0,     0,     0,     0,    94,     0,     0,     0,     0,
       0,   104,     0,     0,    95,    96,    97,   106,   107,    98,
      99,   100,   101,    94,   102,   103,     0,     0,     0,     0,
       0,     0,    95,    96,    97,    94,     0,    98,    99,   100,
     101,     0,   102,   103,    95,    96,    97,    94,     0,    98,
      99,   100,   101,     0,   102,   103,    95,    96,    97,     0,
       0,    98,    99,   100,   101,     0,   102,   103,     0,     0,
     104,     0,     0,   249,     0,     0,   106,   107,     0,     0,
       0,     0,    94,     0,     0,     0,     0,     0,   104,   264,
       0,    95,    96,    97,   106,   107,    98,    99,   100,   101,
     104,   102,   103,   321,     0,     0,   106,   107,     0,     0,
       0,    94,   104,     0,     0,     0,     0,     0,   106,   107,
      95,    96,    97,     0,     0,    98,    99,   100,   101,     0,
     102,   103,     0,     0,     0,     1,     0,     0,     2,     0,
       0,     0,     0,     0,     0,     0,     0,   169,     0,     0,
       0,     0,     0,   106,   107,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,     1,   171,     0,     0,     0,
       0,     0,   106,   107,     0,     0,     0,     0,     0,   155,
     246,   156,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,     1,     0,     0,     2,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   259,
     246,   156,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,     0,    87,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,     0,    23,
       0,     0,   228,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     3,     0,     0,     0,     0,    88,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,     3,     0,     0,     0,     0,     0,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,     0,     3,     0,     0,     0,     0,   139,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,     3,     0,     0,     0,     0,   146,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,     0,     0,     0,     0,     0,   185,
     235,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,     0,
     240,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,     0,     0,     0,    83,     0,  -200,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   319,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,   254,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,     3,     0,
       0,     0,     0,     0,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203
};

static const yytype_int16 yycheck[] =
{
      59,    58,   152,   158,   104,    89,    23,    94,    95,    96,
      97,    69,    70,    23,     1,    23,    79,    51,    59,   106,
     107,    84,    71,     0,    20,   125,    75,    23,    23,    63,
      74,    44,    76,     0,    79,    94,    95,    96,    97,   115,
      33,    86,   101,   102,   103,    85,   104,   106,   107,    26,
      27,    28,    39,    23,    85,    68,   115,    34,    20,    20,
      20,    74,    23,    23,    20,   141,    85,    34,    85,   169,
      20,   171,   148,    23,   115,    85,    85,    85,    74,    74,
     156,    58,   141,   183,   120,   185,    23,   136,    84,   148,
      57,   175,    54,    55,    83,    75,   145,   156,    79,   135,
     141,    83,    89,    84,    74,   260,    76,   148,   208,   209,
     210,   169,   212,    74,    74,   156,    76,    84,    74,    83,
      76,    82,    75,    74,    74,    76,    79,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   239,   314,   158,    79,   134,   155,   205,
     152,   207,    79,    86,    75,   262,    79,   253,   155,    86,
     239,    84,    79,    79,    77,   162,    75,    84,   175,     1,
      79,    82,    82,    75,   253,   252,   232,    79,   239,    74,
     182,    75,    23,   262,    25,    79,     9,    18,    19,    20,
      21,    22,   253,    23,    75,    18,    19,    20,    79,    74,
      23,    24,    25,    26,    75,    28,    29,    39,    79,    74,
      42,    76,    44,   333,   334,    56,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,    79,   349,
      75,    82,    73,   289,    79,    74,    68,    69,    70,    71,
      81,    74,    74,    75,    84,    27,    28,    29,    89,   328,
      84,    74,   259,    82,    42,   252,    44,    80,    81,    23,
      75,    84,   259,    20,    21,    22,    77,   328,    79,    23,
      23,    66,   104,    82,   330,   331,   332,    84,    75,    75,
      68,    69,    70,    71,    77,    75,    74,    75,    74,    64,
      79,   347,    74,    84,    76,    75,    78,    84,   354,    77,
      84,    75,    81,   237,   136,    16,    17,    18,    19,    20,
      21,    22,   314,   145,   155,    76,   104,   169,   162,    37,
     134,   149,    34,    -1,   326,    -1,    -1,    -1,    -1,    -1,
       9,    -1,    -1,    -1,    -1,    -1,    -1,   169,    -1,    18,
      19,    20,    -1,    -1,    23,    24,    25,    26,   136,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,   145,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,   169,    61,    62,    63,    -1,    65,    66,    67,    68,
      69,    70,    71,    72,    -1,    74,   237,    -1,    -1,     9,
      -1,    80,    81,    -1,    -1,    84,    85,    86,    18,    19,
      20,    -1,    -1,    23,    24,    25,    26,    -1,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    -1,    65,    66,    67,    68,    69,
      70,    71,    72,    -1,    74,    -1,    -1,    -1,     9,    -1,
      80,    81,    -1,    -1,    84,    85,    86,    18,    19,    20,
      -1,    -1,    23,    24,    25,    26,    -1,    28,    29,    -1,
      -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    -1,    -1,    23,    24,
      25,    26,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,
      61,    62,    63,    -1,    65,    66,    67,    68,    69,    70,
      71,    72,    -1,    74,    -1,    -1,    -1,    -1,    -1,    80,
      81,    -1,    -1,    84,    85,    86,    61,    62,    63,    -1,
      65,    66,    67,    68,    69,    70,    71,    72,    -1,    74,
      -1,    -1,    -1,     9,    -1,    80,    81,    -1,    -1,    84,
      85,    86,    18,    19,    20,    -1,    -1,    23,    24,    25,
      26,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,     9,    -1,    23,    24,    25,    26,    -1,    28,    29,
      18,    19,    20,    -1,    -1,    23,    24,    25,    26,    -1,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,
      -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    85,
      86,    61,    62,    63,    -1,    65,    66,    67,    68,    69,
      70,    71,    72,    -1,    74,     0,    -1,    -1,    -1,    -1,
      80,    81,    -1,    -1,    84,    85,    74,    -1,    -1,    -1,
      -1,    -1,    80,    81,     9,    20,    -1,    85,    23,    -1,
      -1,    -1,    -1,    18,    19,    20,    -1,    -1,    23,    24,
      25,    26,    -1,    28,    29,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,    74,
      23,    24,    25,    26,    -1,    28,    29,    -1,    -1,    74,
      -1,    -1,    77,    -1,    -1,    80,    81,    40,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    18,    19,    20,    80,    81,    23,
      24,    25,    26,     9,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,     9,    -1,    23,    24,    25,
      26,    -1,    28,    29,    18,    19,    20,     9,    -1,    23,
      24,    25,    26,    -1,    28,    29,    18,    19,    20,    -1,
      -1,    23,    24,    25,    26,    -1,    28,    29,    -1,    -1,
      74,    -1,    -1,    77,    -1,    -1,    80,    81,    -1,    -1,
      -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,    74,    75,
      -1,    18,    19,    20,    80,    81,    23,    24,    25,    26,
      74,    28,    29,    77,    -1,    -1,    80,    81,    -1,    -1,
      -1,     9,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,
      18,    19,    20,    -1,    -1,    23,    24,    25,    26,    -1,
      28,    29,    -1,    -1,    -1,    20,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    80,    81,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    20,    74,    -1,    -1,    -1,
      -1,    -1,    80,    81,    -1,    -1,    -1,    -1,    -1,    74,
      75,    76,    -1,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    20,    -1,    -1,    23,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    74,
      75,    76,    -1,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    23,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    74,
      -1,    -1,    83,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    75,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    40,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    40,    -1,    -1,    -1,    -1,    86,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    40,    -1,    -1,    -1,    -1,    86,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,     3,
      86,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      86,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    -1,    -1,    83,    -1,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    40,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    23,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    74,    97,    98,   101,   102,   103,   105,
     111,   114,   115,   116,   133,   134,   135,   136,   103,   104,
     116,    23,    85,    23,    85,    23,    85,   114,    84,    99,
     100,   114,    98,    98,    98,    97,    98,   131,    74,    76,
     115,     0,   134,    85,   130,   137,   103,   116,    85,   102,
     103,   106,   107,   108,    85,   106,    85,    23,   112,   113,
      75,    79,    84,    83,   131,   114,    97,    23,    75,    98,
     117,   118,   119,   120,     9,    18,    19,    20,    23,    24,
      25,    26,    28,    29,    74,    77,    80,    81,    88,    89,
      91,    92,    93,    96,    23,    61,    62,    63,    65,    66,
      67,    68,    69,    70,    71,    72,    84,    86,    91,    93,
      94,    95,   126,   130,   131,   132,   106,   108,   108,    86,
     107,    82,   109,   110,   114,   106,    86,   112,    83,    79,
      86,   100,    85,    94,   124,    74,    76,   114,   116,   122,
     123,    75,    79,    75,    79,    92,    92,    92,    92,    74,
      91,    74,    91,    91,    95,   108,   121,    92,    92,    27,
      28,    29,    74,    76,    78,     3,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    77,    82,    96,    82,    74,    74,
      74,   126,    74,    23,    84,    84,    84,    95,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    83,    79,
      84,    86,   132,    86,   126,    86,    96,    79,    84,    82,
      86,    86,    96,   113,   124,   125,    75,   117,   122,    77,
      96,   123,    74,    76,    60,   119,    23,   121,    75,    74,
     116,   122,    75,    23,    75,    90,    94,    95,    23,    95,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,   126,    82,
     126,    95,    95,    95,    66,    95,   127,    84,    84,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    86,   110,    96,    79,    86,    75,    75,    77,    75,
     117,    77,    96,    75,    92,    75,    79,    77,    82,   126,
      75,    75,    75,    74,    84,    86,   124,    75,    77,    94,
      93,   126,   126,   126,    95,    95,   128,    64,    75,    84,
     126,    84,    95,   129,    75,   126
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 71 "cgrammar-new.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 72 "cgrammar-new.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 73 "cgrammar-new.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 74 "cgrammar-new.y"
    { (yyval.node) = link(exp_, (yyvsp[(2) - (3)].node), 0); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 78 "cgrammar-new.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 79 "cgrammar-new.y"
    { (yyval.node) = link(array_, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node), 0); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 80 "cgrammar-new.y"
    { (yyval.node) = link(funccall_, (yyvsp[(1) - (3)].node), 0); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 81 "cgrammar-new.y"
    { (yyval.node) = link(funccall_, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node), 0); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 82 "cgrammar-new.y"
    { (yyval.node) = link(member_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 83 "cgrammar-new.y"
    { (yyval.node) = link(ptrto_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 84 "cgrammar-new.y"
    { (yyval.node) = link(postinc_, (yyvsp[(1) - (2)].node), 0); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 85 "cgrammar-new.y"
    { (yyval.node) = link(postdec_, (yyvsp[(1) - (2)].node), 0); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 89 "cgrammar-new.y"
    { (yyval.node) = link(arguments_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 90 "cgrammar-new.y"
    { (yyval.node) = (yyvsp[(1) - (3)].node); addchild((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 94 "cgrammar-new.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 95 "cgrammar-new.y"
    { (yyval.node) = link(preinc_, (yyvsp[(2) - (2)].node), 0); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 96 "cgrammar-new.y"
    { (yyval.node) = link(predec_, (yyvsp[(2) - (2)].node), 0); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 97 "cgrammar-new.y"
    { (yyval.node) = link(addressof_, (yyvsp[(2) - (2)].node), 0); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 98 "cgrammar-new.y"
    { (yyval.node) = link(contentsof_, (yyvsp[(2) - (2)].node), 0); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 99 "cgrammar-new.y"
    { (yyval.node) = link(positive_, (yyvsp[(2) - (2)].node), 0); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 100 "cgrammar-new.y"
    { (yyval.node) = link(negative_, (yyvsp[(2) - (2)].node), 0); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 101 "cgrammar-new.y"
    { (yyval.node) = link(complement_, (yyvsp[(2) - (2)].node), 0); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 102 "cgrammar-new.y"
    { (yyval.node) = link(not_, (yyvsp[(2) - (2)].node), 0); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 103 "cgrammar-new.y"
    { (yyval.node) = link(sizeof_, (yyvsp[(2) - (2)].node), 0); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 104 "cgrammar-new.y"
    { (yyval.node) = link(sizeof_, (yyvsp[(3) - (4)].node), 0); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 108 "cgrammar-new.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 109 "cgrammar-new.y"
    { (yyval.node) = link(cast_, (yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node), 0); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 113 "cgrammar-new.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 114 "cgrammar-new.y"
    { (yyval.node) = link(question_, (yyvsp[(1) - (5)].node), (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node), 0); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 115 "cgrammar-new.y"
    { (yyval.node) = link(or_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 116 "cgrammar-new.y"
    { (yyval.node) = link(and_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0);;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 117 "cgrammar-new.y"
    { (yyval.node) = link(bitor_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 118 "cgrammar-new.y"
    { (yyval.node) = link(bitxor_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0);;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 119 "cgrammar-new.y"
    { (yyval.node) = link(bitand_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0);;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 120 "cgrammar-new.y"
    { (yyval.node) = link(eq_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0);;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 121 "cgrammar-new.y"
    { (yyval.node) = link(ne_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0);;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 122 "cgrammar-new.y"
    { (yyval.node) = link(lt_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0);;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 123 "cgrammar-new.y"
    { (yyval.node) = link(gt_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0);;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 124 "cgrammar-new.y"
    { (yyval.node) = link(le_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0);;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 125 "cgrammar-new.y"
    { (yyval.node) = link(ge_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0);;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 126 "cgrammar-new.y"
    { (yyval.node) = link(shl_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0);;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 127 "cgrammar-new.y"
    { (yyval.node) = link(shr_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0);;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 128 "cgrammar-new.y"
    { (yyval.node) = link(add_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0);;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 129 "cgrammar-new.y"
    { (yyval.node) = link(sub_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0);;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 130 "cgrammar-new.y"
    { (yyval.node) = link(mul_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0);;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 131 "cgrammar-new.y"
    { (yyval.node) = link(div_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 132 "cgrammar-new.y"
    { (yyval.node) = link(mod_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 136 "cgrammar-new.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 137 "cgrammar-new.y"
    { (yyval.node) = link(equals_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 138 "cgrammar-new.y"
    { (yyval.node) = link(muleq_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 139 "cgrammar-new.y"
    { (yyval.node) = link(diveq_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 140 "cgrammar-new.y"
    { (yyval.node) = link(modeq_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 141 "cgrammar-new.y"
    { (yyval.node) = link(addeq_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 142 "cgrammar-new.y"
    { (yyval.node) = link(subeq_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 143 "cgrammar-new.y"
    { (yyval.node) = link(shleq_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 144 "cgrammar-new.y"
    { (yyval.node) = link(shreq_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 145 "cgrammar-new.y"
    { (yyval.node) = link(andeq_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 146 "cgrammar-new.y"
    { (yyval.node) = link(xoreq_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 147 "cgrammar-new.y"
    { (yyval.node) = link(oreq_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 151 "cgrammar-new.y"
    { (yyval.node) = link(assignment_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 152 "cgrammar-new.y"
    { (yyval.node) = link(comma_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 156 "cgrammar-new.y"
    { (yyval.node) = link(condexp_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 160 "cgrammar-new.y"
    { (yyval.node) = link(decl_, (yyvsp[(1) - (2)].node), 0); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 161 "cgrammar-new.y"
    { (yyval.node) = link(decl_init_, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), 0); adjust_term((yyval.node), 4) ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 165 "cgrammar-new.y"
    { (yyval.node) = link(decl_spec_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 166 "cgrammar-new.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); addchild((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 167 "cgrammar-new.y"
    { (yyval.node) = link(decl_spec_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 168 "cgrammar-new.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); addchild((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 169 "cgrammar-new.y"
    { (yyval.node) = link(decl_spec_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 170 "cgrammar-new.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); addchild((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 174 "cgrammar-new.y"
    { (yyval.node) = link(init_declarators_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 175 "cgrammar-new.y"
    { (yyval.node) = (yyvsp[(1) - (3)].node); addchild((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 179 "cgrammar-new.y"
    { (yyval.node) = link(declarator_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 180 "cgrammar-new.y"
    { (yyval.node) = link(declaratorinit_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 184 "cgrammar-new.y"
    { (yyval.node) = link(typedef_, 0); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 185 "cgrammar-new.y"
    { (yyval.node) = link(extern_, 0); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 186 "cgrammar-new.y"
    { (yyval.node) = link(static_, 0); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 187 "cgrammar-new.y"
    { (yyval.node) = link(auto_, 0); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 188 "cgrammar-new.y"
    { (yyval.node) = link(register_, 0); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 192 "cgrammar-new.y"
    { (yyval.node) = link(void_, 0); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 193 "cgrammar-new.y"
    { (yyval.node) = link(char_, 0); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 194 "cgrammar-new.y"
    { (yyval.node) = link(short_, 0); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 195 "cgrammar-new.y"
    { (yyval.node) = link(int_, 0); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 196 "cgrammar-new.y"
    { (yyval.node) = link(long_, 0); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 197 "cgrammar-new.y"
    { (yyval.node) = link(float_, 0); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 198 "cgrammar-new.y"
    { (yyval.node) = link(double_, 0); ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 199 "cgrammar-new.y"
    { (yyval.node) = link(signed_, 0); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 200 "cgrammar-new.y"
    { (yyval.node) = link(unsigned_, 0); ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 201 "cgrammar-new.y"
    { (yyval.node) = link(struct_or_union_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 202 "cgrammar-new.y"
    { (yyval.node) = link(enum_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 203 "cgrammar-new.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 207 "cgrammar-new.y"
    { (yyval.node) = link(const_, 0); ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 208 "cgrammar-new.y"
    { (yyval.node) = link(volatile_, 0); ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 212 "cgrammar-new.y"
    { (yyval.node) = link(type_qualifiers_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 213 "cgrammar-new.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); addchild((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 217 "cgrammar-new.y"
    { (yyval.node) = link(struct_, (yyvsp[(2) - (5)].node), (yyvsp[(4) - (5)].node), 0); ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 218 "cgrammar-new.y"
    { (yyval.node) = link(struct_, (yyvsp[(3) - (4)].node), 0); ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 219 "cgrammar-new.y"
    { (yyval.node) = link(struct_, (yyvsp[(2) - (2)].node), 0); ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 220 "cgrammar-new.y"
    { (yyval.node) = link(union_, (yyvsp[(2) - (5)].node), (yyvsp[(4) - (5)].node), 0); ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 221 "cgrammar-new.y"
    { (yyval.node) = link(union_, (yyvsp[(3) - (4)].node), 0); ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 222 "cgrammar-new.y"
    { (yyval.node) = link(union_, (yyvsp[(2) - (2)].node), 0); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 227 "cgrammar-new.y"
    { (yyval.node) = link(struct_declarations_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 228 "cgrammar-new.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); addchild((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 232 "cgrammar-new.y"
    { (yyval.node) = link(struct_declaration_, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), 0); ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 236 "cgrammar-new.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); addchild((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 237 "cgrammar-new.y"
    { (yyval.node) = link(spec_qua_s_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 238 "cgrammar-new.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); addchild((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 239 "cgrammar-new.y"
    { (yyval.node) = link(spec_qua_s_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 243 "cgrammar-new.y"
    { (yyval.node) = link(struct_declarators_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 244 "cgrammar-new.y"
    { (yyval.node) = (yyvsp[(1) - (3)].node); addchild((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 248 "cgrammar-new.y"
    { (yyval.node) = link(struct_declarator_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 249 "cgrammar-new.y"
    { (yyval.node) = link(struct_declarator_, (yyvsp[(2) - (2)].node), 0); ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 250 "cgrammar-new.y"
    { (yyval.node) = link(struct_declarator_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0); ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 254 "cgrammar-new.y"
    { (yyval.node) = link(enum_spec_, (yyvsp[(3) - (4)].node), 0); ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 255 "cgrammar-new.y"
    { (yyval.node) = link(enum_spec_, (yyvsp[(2) - (5)].node), (yyvsp[(4) - (5)].node), 0); ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 256 "cgrammar-new.y"
    { (yyval.node) = link(enum_spec_, (yyvsp[(2) - (2)].node), 0); ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 260 "cgrammar-new.y"
    { (yyval.node) = link(enumerators_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 261 "cgrammar-new.y"
    { (yyval.node) = (yyvsp[(1) - (3)].node); addchild((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 265 "cgrammar-new.y"
    { (yyval.node) = link(enumident_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 266 "cgrammar-new.y"
    { (yyval.node) = link(enumequals_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0); ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 270 "cgrammar-new.y"
    { (yyval.node) = link(direct_decl_, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), 0); ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 271 "cgrammar-new.y"
    { (yyval.node) = link(direct_decl_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 275 "cgrammar-new.y"
    { (yyval.node) = link(ident_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 276 "cgrammar-new.y"
    { (yyval.node) = link(declarator_, (yyvsp[(2) - (3)].node), 0); ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 277 "cgrammar-new.y"
    { (yyval.node) = link(arraydecl_, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node), 0); ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 278 "cgrammar-new.y"
    { (yyval.node) = link(arraydecl_, (yyvsp[(1) - (3)].node), 0); ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 279 "cgrammar-new.y"
    { (yyval.node) = link(funcdecl_, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node), 0); ;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 280 "cgrammar-new.y"
    { (yyval.node) = link(funcdecl_, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node), 0); ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 281 "cgrammar-new.y"
    { (yyval.node) = link(funcdecl_, (yyvsp[(1) - (3)].node), 0); ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 285 "cgrammar-new.y"
    {(yyval.node) = link(pointer_, 0); ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 286 "cgrammar-new.y"
    { (yyval.node) = link(pointer_, (yyvsp[(2) - (2)].node), 0); ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 287 "cgrammar-new.y"
    { (yyval.node) = link(pointer_, (yyvsp[(2) - (2)].node), 0); ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 288 "cgrammar-new.y"
    { (yyval.node) = link(pointer_, (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), 0); ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 292 "cgrammar-new.y"
    { (yyval.node) = link(param_types_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 293 "cgrammar-new.y"
    { (yyval.node) = link(param_types_ellipsis_, (yyvsp[(1) - (3)].node), 0); ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 297 "cgrammar-new.y"
    { (yyval.node) = link(param_declarations_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 298 "cgrammar-new.y"
    { (yyval.node) = (yyvsp[(1) - (3)].node); addchild((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 302 "cgrammar-new.y"
    { (yyval.node) = link(declarator_, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), 0); ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 303 "cgrammar-new.y"
    { (yyval.node) = link(absarg_, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), 0); ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 304 "cgrammar-new.y"
    { (yyval.node) = link(declarator_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 308 "cgrammar-new.y"
    { (yyval.node) = link(idents_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 309 "cgrammar-new.y"
    { (yyval.node) = (yyvsp[(1) - (3)].node); addchild((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 313 "cgrammar-new.y"
    { (yyval.node) = link(typespec_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 314 "cgrammar-new.y"
    { (yyval.node) = link(typespec_, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), 0); ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 318 "cgrammar-new.y"
    { (yyval.node) = link(abstract_declarator_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 319 "cgrammar-new.y"
    { (yyval.node) = link(abstract_declarator_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 320 "cgrammar-new.y"
    { (yyval.node) = link(abstract_declarator_, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), 0); ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 324 "cgrammar-new.y"
    { (yyval.node) = link(abstract_declarator_, (yyvsp[(2) - (3)].node), 0); ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 325 "cgrammar-new.y"
    { (yyval.node) = link(constexp_, 0); ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 326 "cgrammar-new.y"
    { (yyval.node) = link(constexp_, (yyvsp[(2) - (3)].node), 0); ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 327 "cgrammar-new.y"
    { (yyval.node) = link(absarray_, (yyvsp[(1) - (3)].node), 0); ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 328 "cgrammar-new.y"
    { (yyval.node) = link(absarray_, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node), 0); ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 329 "cgrammar-new.y"
    { (yyval.node) = link(absfunc_, 0); ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 330 "cgrammar-new.y"
    { (yyval.node) = link(absfunc_, (yyvsp[(2) - (3)].node), 0); ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 331 "cgrammar-new.y"
    { (yyval.node) = link(absfunc_, (yyvsp[(1) - (3)].node), 0); ;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 332 "cgrammar-new.y"
    { (yyval.node) = link(absfunc_, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node), 0); ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 336 "cgrammar-new.y"
    { (yyval.node) = link(assign_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 337 "cgrammar-new.y"
    { (yyval.node) = link(Init_, (yyvsp[(2) - (3)].node), 0); ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 338 "cgrammar-new.y"
    { (yyval.node) = link(Init_comma_, (yyvsp[(2) - (4)].node), 0); ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 342 "cgrammar-new.y"
    { (yyval.node) = link(init_s_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 343 "cgrammar-new.y"
    { (yyval.node) = (yyvsp[(1) - (3)].node); addchild((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 347 "cgrammar-new.y"
    { (yyval.node) = link(labeledstmt_, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0); ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 348 "cgrammar-new.y"
    { (yyval.node) = link(case_, (yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node), 0); ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 349 "cgrammar-new.y"
    { (yyval.node) = link(default_, (yyvsp[(3) - (3)].node), 0); ;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 351 "cgrammar-new.y"
    { (yyval.node) = link(block_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 352 "cgrammar-new.y"
    { (yyval.node) = link(empty_stmt_, 0); ;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 353 "cgrammar-new.y"
    { (yyval.node) = link(exp_, (yyvsp[(1) - (2)].node), 0); ;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 355 "cgrammar-new.y"
    { (yyval.node) = link(if_, (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node), 0); ;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 356 "cgrammar-new.y"
    { (yyval.node) = link(ifelse_, (yyvsp[(3) - (7)].node), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node), 0); ;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 357 "cgrammar-new.y"
    { (yyval.node) = link(switch_, (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node), 0);;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 359 "cgrammar-new.y"
    { (yyval.node) = link(while_, (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node), 0); ;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 360 "cgrammar-new.y"
    { (yyval.node) = link(do_, (yyvsp[(2) - (7)].node), (yyvsp[(5) - (7)].node), 0); ;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 361 "cgrammar-new.y"
    { (yyval.node) = link(for_, (yyvsp[(3) - (9)].node), (yyvsp[(5) - (9)].node), (yyvsp[(7) - (9)].node), (yyvsp[(9) - (9)].node), 0); ;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 363 "cgrammar-new.y"
    { (yyval.node) = link(goto_, (yyvsp[(2) - (3)].node), 0); ;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 364 "cgrammar-new.y"
    { (yyval.node) = link(continue_, 0); ;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 365 "cgrammar-new.y"
    { (yyval.node) = link(break_, 0); ;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 366 "cgrammar-new.y"
    { (yyval.node) = link(return_, 0); ;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 367 "cgrammar-new.y"
    { (yyval.node) = link(return_exp_, (yyvsp[(2) - (3)].node), 0); ;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 371 "cgrammar-new.y"
    { (yyval.node) = link(no_stmt_, 0); ;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 372 "cgrammar-new.y"
    { (yyval.node) = link(exp1_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 376 "cgrammar-new.y"
    { (yyval.node) = link(no_stmt_, 0); ;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 377 "cgrammar-new.y"
    { (yyval.node) = link(exp2_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 381 "cgrammar-new.y"
    { (yyval.node) = link(no_stmt_, 0); ;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 382 "cgrammar-new.y"
    { (yyval.node) = link(exp3_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 386 "cgrammar-new.y"
    { (yyval.node) = link(compound_stmt_, 0); ;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 387 "cgrammar-new.y"
    { (yyval.node) = link(compound_stmt_, (yyvsp[(2) - (3)].node), 0); ;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 388 "cgrammar-new.y"
    { (yyval.node) = link(compound_stmt_, (yyvsp[(2) - (3)].node), 0); ;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 389 "cgrammar-new.y"
    { (yyval.node) = link(compound_stmt_, (yyvsp[(2) - (4)].node), (yyvsp[(3) - (4)].node), 0); ;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 393 "cgrammar-new.y"
    { (yyval.node) = link(declarations_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 394 "cgrammar-new.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); addchild((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); ;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 398 "cgrammar-new.y"
    { (yyval.node) = link(statements_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 399 "cgrammar-new.y"
    {(yyval.node) = (yyvsp[(1) - (2)].node); addchild((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); ;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 403 "cgrammar-new.y"
    { (yyval.node) = link(goal_, (yyvsp[(1) - (1)].node), 0); parse_tree = (yyval.node); root = (yyval.node)->node_index; ;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 404 "cgrammar-new.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); addchild((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); parse_tree = (yyval.node); root = (yyval.node)->node_index; ;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 408 "cgrammar-new.y"
    { (yyval.node) = link(extdef_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 409 "cgrammar-new.y"
    { (yyval.node) = link(extdef_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 413 "cgrammar-new.y"
    { (yyval.node) = link(funcdef_, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), 0); ;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 417 "cgrammar-new.y"
    { (yyval.node) = link(funcdecl_, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), 0); ;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 418 "cgrammar-new.y"
    { (yyval.node) = link(funcdecl_, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), 0); ;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 419 "cgrammar-new.y"
    { (yyval.node) = link(funcdecl_, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), 0); ;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 420 "cgrammar-new.y"
    { (yyval.node) = link(funcdecl_, (yyvsp[(1) - (1)].node), 0); ;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 424 "cgrammar-new.y"
    { (yyval.node) = link(funcbody_, (yyvsp[(1) - (1)].node), 0); ;}
    break;



/* Line 1455 of yacc.c  */
#line 3373 "cgrammar-new.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 427 "cgrammar-new.y"

#include <stdio.h>

extern char yytext[];
extern int column;

Node * link(int tid, Node * rExp, ... )
{
	Node * node1;
	Node * node2;
	va_list exps;
  Node * parent_node = new_node();
  
	parent_node->id = tid; 
	parent_node->line = yylineno;

	if( rExp == NULL ) return parent_node;

	va_start(exps,rExp);
	node1 = rExp;  //第一个子节点
	parent_node->child = node1->node_index; 
	node1->parent = parent_node->node_index;

	node2=va_arg(exps,Node *);

	while(node2!=NULL){
		node1->next = node2->node_index; 
		node2->prev = node1->node_index;

		node1 = node2; 
		node2=va_arg(exps,Node *);
	}

	va_end( exps ); 
  
  return parent_node;
  
}


