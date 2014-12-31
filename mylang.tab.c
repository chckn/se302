/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

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

/* Line 268 of yacc.c  */
#line 2 "mylang.y"

#include<stdio.h>
#include<string.h>
#include "mylang.h"
#include "mylang.tab.h"
#define new(T) ((T*)malloc(sizeof(T)))
	int yylex();
	void yyerror(char const *);
/*
	typedef struct Node Node;
	struct Node
	{
		int type;//0,1,2
		char *str;
		int integer;
		char *name;
		Node *first,*last;
		Node *next;
	};
*/
	void push(Node *ptr, Node *child);
	Node * nodes(const char* str,const char* name);
	Node * nodei(int i,const char* name);
	Node * noden(const char* name);
	static Node *head;


/* Line 268 of yacc.c  */
#line 99 "mylang.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
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
     IDENT = 258,
     NUM = 259,
     PROGRAM = 260,
     IS = 261,
     BEGINS = 262,
     END = 263,
     TYPE = 264,
     ARRAY = 265,
     OF = 266,
     CLASS = 267,
     EXTENDS = 268,
     FUNCTION = 269,
     RETURN = 270,
     ASSIGN = 271,
     PRINT = 272,
     FOREACH = 273,
     IN = 274,
     DO = 275,
     REPEAT = 276,
     UNTIL = 277,
     WHILE = 278,
     IF = 279,
     THEN = 280,
     ELSE = 281,
     ELIF = 282,
     OR = 283,
     AND = 284,
     EQUAL = 285,
     LEQA = 286,
     SEQA = 287,
     YES = 288,
     NO = 289,
     VAR = 290,
     INTEGER = 291,
     BOOLEAN = 292
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 29 "mylang.y"

	char* str;
	int integer;
	struct Node *node;



/* Line 293 of yacc.c  */
#line 180 "mylang.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 192 "mylang.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   190

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNRULES -- Number of states.  */
#define YYNSTATES  186

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    42,     2,     2,
      43,    44,    40,    38,    48,    39,    47,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    49,
      50,     2,    51,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    14,    16,    18,    20,    22,    24,    28,
      33,    35,    39,    42,    44,    48,    49,    51,    53,    55,
      57,    63,    64,    68,    69,    72,    75,    76,    79,    81,
      85,    86,    88,    90,    94,    99,   101,   103,   105,   109,
     111,   115,   119,   123,   127,   131,   133,   135,   137,   139,
     141,   143,   145,   149,   151,   155,   157,   161,   166,   167,
     170,   171,   174,   183,   190,   196,   205,   209,   214,   218,
     233,   243,   255,   264,   266,   268,   270,   272,   274,   276,
     278,   280,   282,   285,   287,   288,   291,   293
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,     5,     3,    43,    44,    92,     6,    63,
       7,    93,     8,    -1,    33,    -1,    34,    -1,    72,    -1,
      54,    -1,    69,    -1,    45,    72,    46,    -1,    45,    72,
      46,    56,    -1,     3,    -1,    57,    47,     3,    -1,    57,
      56,    -1,    57,    -1,    57,    48,    58,    -1,    -1,    58,
      -1,    36,    -1,    37,    -1,     3,    -1,    35,     3,     6,
      60,    49,    -1,    -1,    15,    60,    49,    -1,    -1,    61,
      63,    -1,    63,    62,    -1,    -1,    87,    65,    -1,    55,
      -1,    55,    48,    66,    -1,    -1,    66,    -1,     3,    -1,
      57,    47,     3,    -1,    68,    43,    67,    44,    -1,     4,
      -1,    57,    -1,    69,    -1,    43,    55,    44,    -1,    70,
      -1,    71,    40,    70,    -1,    71,    41,    70,    -1,    71,
      42,    70,    -1,    72,    38,    71,    -1,    72,    39,    71,
      -1,    71,    -1,    30,    -1,    50,    -1,    51,    -1,    32,
      -1,    31,    -1,    55,    -1,    55,    73,    55,    -1,    74,
      -1,    74,    29,    75,    -1,    75,    -1,    75,    28,    76,
      -1,    27,    76,    25,    93,    -1,    -1,    77,    78,    -1,
      -1,    26,    93,    -1,    24,    76,    25,    93,    78,    79,
       8,    24,    -1,    23,    76,    20,    93,     8,    23,    -1,
      21,    93,    22,    76,    49,    -1,    18,     3,    19,    57,
      20,    93,     8,    18,    -1,    17,    55,    49,    -1,    57,
      16,    55,    49,    -1,    15,    55,    49,    -1,    14,     3,
      43,    59,    44,    64,     6,    63,     7,    93,     8,    14,
       3,    49,    -1,     9,     3,     6,    12,    63,    65,     8,
      12,    49,    -1,     9,     3,     6,    12,    13,     3,    63,
      65,     8,    12,    49,    -1,     9,     3,     6,    10,    11,
       4,    60,    49,    -1,    87,    -1,    88,    -1,    89,    -1,
      80,    -1,    81,    -1,    82,    -1,    83,    -1,    86,    -1,
      85,    -1,    69,    49,    -1,    84,    -1,    -1,    90,    92,
      -1,    91,    -1,    91,    93,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    42,    42,    54,    55,    57,    58,    59,    65,    66,
      68,    69,    71,    73,    74,    81,    82,    84,    85,    86,
      88,    95,    96,   102,   103,   108,   110,   111,   113,   114,
     120,   121,   123,   124,   131,   134,   135,   136,   137,   140,
     141,   143,   145,   148,   150,   152,   154,   155,   156,   157,
     158,   160,   161,   164,   165,   168,   169,   172,   176,   177,
     179,   180,   183,   187,   191,   195,   200,   203,   206,   209,
     223,   229,   238,   245,   246,   247,   250,   251,   252,   253,
     254,   255,   256,   257,   259,   260,   262,   263
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENT", "NUM", "PROGRAM", "IS",
  "BEGINS", "END", "TYPE", "ARRAY", "OF", "CLASS", "EXTENDS", "FUNCTION",
  "RETURN", "ASSIGN", "PRINT", "FOREACH", "IN", "DO", "REPEAT", "UNTIL",
  "WHILE", "IF", "THEN", "ELSE", "ELIF", "OR", "AND", "EQUAL", "LEQA",
  "SEQA", "YES", "NO", "VAR", "INTEGER", "BOOLEAN", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'('", "')'", "'['", "']'", "'.'", "','", "';'", "'<'",
  "'>'", "$accept", "program", "boolean", "exp", "indices", "var", "nevar",
  "variables", "type", "argument", "retype", "arguments", "funcheader",
  "methods", "nevalues", "values", "fname", "fcall", "primary", "term",
  "final", "coperator", "bprimary", "bterm", "bexpressions", "elif",
  "elifs", "else", "if", "while", "repeat", "foreach", "print",
  "assignment", "return", "function", "class", "array", "declar",
  "sentence", "declarblock", "block", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,    43,    45,
      42,    47,    37,    40,    41,    91,    93,    46,    44,    59,
      60,    62
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    55,    55,    56,    56,
      57,    57,    57,    58,    58,    59,    59,    60,    60,    60,
      61,    62,    62,    63,    63,    64,    65,    65,    66,    66,
      67,    67,    68,    68,    69,    70,    70,    70,    70,    71,
      71,    71,    71,    72,    72,    72,    73,    73,    73,    73,
      73,    74,    74,    75,    75,    76,    76,    77,    78,    78,
      79,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    88,    89,    90,    90,    90,    91,    91,    91,    91,
      91,    91,    91,    91,    92,    92,    93,    93
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    10,     1,     1,     1,     1,     1,     3,     4,
       1,     3,     2,     1,     3,     0,     1,     1,     1,     1,
       5,     0,     3,     0,     2,     2,     0,     2,     1,     3,
       0,     1,     1,     3,     4,     1,     1,     1,     3,     1,
       3,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     1,     3,     4,     0,     2,
       0,     2,     8,     6,     5,     8,     3,     4,     3,    14,
       9,    11,     8,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     0,     2,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,    84,     0,     0,    73,
      74,    75,    84,     0,     0,     0,    85,    23,     0,    15,
       0,    23,     0,     0,    23,    10,    13,    16,     0,     0,
      24,     0,     0,     0,    26,     0,     0,     0,    12,    23,
       0,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    76,    77,    78,    79,    83,    81,    80,    86,     0,
       0,    23,     0,    26,    35,     0,    36,    37,    39,    45,
       0,    11,    14,    21,     0,    19,    17,    18,     0,     3,
       4,     6,     0,     7,     5,     0,     0,     0,    51,    53,
      55,     0,     0,     0,     0,    30,    82,    87,     2,     0,
      26,     0,    27,     0,     0,     0,     0,     0,     0,     8,
       0,    25,    23,    20,    68,    66,     0,     0,    46,    50,
      49,    47,    48,     0,     0,     0,     0,     0,     0,    11,
      28,    31,     0,    72,     0,     0,    38,    40,    41,    42,
      43,    44,     9,     0,     0,     0,     0,    52,    54,    56,
       0,    58,    67,     0,    34,     0,    70,    22,     0,     0,
      64,     0,     0,    58,    60,    29,     0,     0,     0,    63,
       0,    59,     0,     0,    71,     0,     0,     0,    61,     0,
       0,    65,    57,    62,     0,    69
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    81,    88,    38,    66,    27,    28,    78,    21,
     111,    22,    74,    62,   131,   132,    49,    83,    68,    69,
      84,   123,    89,    90,    91,   163,   164,   173,    51,    52,
      53,    54,    55,    56,    57,    63,    10,    11,    12,    58,
      13,    59
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -60
static const yytype_int16 yypact[] =
{
      19,    34,    57,    24,   -60,    30,    59,    67,    72,   -60,
     -60,   -60,    59,    78,    89,    53,   -60,    71,    15,   106,
     110,    71,   111,   108,    10,   -60,    40,   -60,    73,   114,
     -60,    48,   117,   119,   109,     5,   121,   106,   -60,    71,
       7,    82,    16,    16,   124,    48,    16,    16,    17,    86,
      83,   -60,   -60,   -60,   -60,   -60,   -60,   -60,    48,   126,
       7,    71,   127,   109,   -60,    16,    58,   -60,   -60,    60,
     -17,   -60,   -60,   122,   130,   -60,   -60,   -60,    92,   -60,
     -60,   -60,    93,    52,     8,    94,   128,   116,     4,   123,
     118,   125,   129,    16,   145,    16,   -60,   -60,   -60,   101,
     109,   139,   -60,   112,     5,     5,     5,     5,     5,   115,
       7,   -60,    71,   -60,   -60,   -60,   106,    16,   -60,   -60,
     -60,   -60,   -60,    16,    16,    16,    48,    48,   113,   120,
     107,   -60,   131,   -60,   149,   132,   -60,   -60,   -60,   -60,
      60,    60,   -60,   133,   152,    -5,   134,   -60,   -60,   -60,
     153,   137,   -60,    16,   -60,   154,   -60,   -60,    48,    48,
     -60,   142,    16,   137,   141,   -60,   135,   160,   161,   -60,
     146,   -60,    48,   162,   -60,   158,   155,    48,   -60,   150,
     173,   -60,   -60,   -60,   136,   -60
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -60,   -60,   -60,   -37,    68,   -19,   143,   -60,   -58,   -60,
     -60,    -8,   -60,   -59,    25,   -60,   -60,   -28,     6,   -47,
     144,   -60,   -60,    62,   -36,   -60,    27,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,   -60,    26,   -60,   -60,   -60,   -60,
     175,   -44
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -38
static const yytype_int16 yytable[] =
{
      26,    87,    99,    50,   102,    82,    85,    67,    41,    64,
      75,    92,    48,    30,    97,   159,    34,    50,    26,    41,
      64,   107,   108,    33,     1,    23,    48,    24,   103,   109,
      50,    73,     9,    93,   118,   119,   120,     3,     9,    48,
      35,   134,    36,    76,    77,    20,   107,   108,    65,    79,
      80,    41,   143,   100,   121,   122,   128,     4,   130,    65,
     140,   141,    35,    42,    94,    43,    44,     5,     7,    45,
      14,    46,    47,     8,     6,    15,    67,    67,    67,    67,
      67,   146,   150,   151,    17,    35,   147,    36,    37,   149,
     -37,   -37,   -37,   -37,   -37,    18,    19,   145,    50,    50,
     104,   105,   106,    35,   144,    94,    20,    48,    48,    25,
     137,   138,   139,    29,   167,   168,   130,    39,    31,    32,
      40,    60,    61,     8,    71,   -32,   170,    86,   178,    95,
      50,    50,    96,   182,    98,   101,   112,   110,   117,    48,
      48,   113,   114,   115,    50,   126,   125,   116,   129,    50,
     133,   135,   124,    48,   127,   153,   136,   155,    48,   158,
      35,   161,   152,   -33,   162,   169,   166,   172,   175,   176,
     179,   177,   180,   181,   183,   154,   184,   142,   165,    70,
      72,   156,   157,   160,   174,   185,   148,    16,     0,     0,
     171
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-60))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      19,    45,    60,    31,    63,    42,    43,    35,     3,     4,
       3,    47,    31,    21,    58,    20,    24,    45,    37,     3,
       4,    38,    39,    13,     5,    10,    45,    12,    65,    46,
      58,    39,     6,    16,    30,    31,    32,     3,    12,    58,
      45,   100,    47,    36,    37,    35,    38,    39,    43,    33,
      34,     3,   110,    61,    50,    51,    93,     0,    95,    43,
     107,   108,    45,    15,    47,    17,    18,    43,     9,    21,
       3,    23,    24,    14,    44,     3,   104,   105,   106,   107,
     108,   117,   126,   127,     6,    45,   123,    47,    48,   125,
      38,    39,    40,    41,    42,     6,    43,   116,   126,   127,
      40,    41,    42,    45,   112,    47,    35,   126,   127,     3,
     104,   105,   106,     3,   158,   159,   153,    44,     7,    11,
       6,     4,     3,    14,     3,    43,   162,     3,   172,    43,
     158,   159,    49,   177,     8,     8,     6,    15,    22,   158,
     159,    49,    49,    49,   172,    20,    28,    19,     3,   177,
      49,    12,    29,   172,    25,    48,    44,     8,   177,     7,
      45,     8,    49,    43,    27,    23,    12,    26,     8,     8,
       8,    25,    14,    18,    24,    44,     3,   109,   153,    35,
      37,    49,    49,    49,    49,    49,   124,    12,    -1,    -1,
     163
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    53,     3,     0,    43,    44,     9,    14,    87,
      88,    89,    90,    92,     3,     3,    92,     6,     6,    43,
      35,    61,    63,    10,    12,     3,    57,    58,    59,     3,
      63,     7,    11,    13,    63,    45,    47,    48,    56,    44,
       6,     3,    15,    17,    18,    21,    23,    24,    57,    68,
      69,    80,    81,    82,    83,    84,    85,    86,    91,    93,
       4,     3,    65,    87,     4,    43,    57,    69,    70,    71,
      72,     3,    58,    63,    64,     3,    36,    37,    60,    33,
      34,    54,    55,    69,    72,    55,     3,    93,    55,    74,
      75,    76,    76,    16,    47,    43,    49,    93,     8,    60,
      63,     8,    65,    55,    40,    41,    42,    38,    39,    46,
      15,    62,     6,    49,    49,    49,    19,    22,    30,    31,
      32,    50,    51,    73,    29,    28,    20,    25,    55,     3,
      55,    66,    67,    49,    65,    12,    44,    70,    70,    70,
      71,    71,    56,    60,    63,    57,    76,    55,    75,    76,
      93,    93,    49,    48,    44,     8,    49,    49,     7,    20,
      49,     8,    27,    77,    78,    66,    12,    93,    93,    23,
      76,    78,    26,    79,    49,     8,     8,    25,    93,     8,
      14,    18,    93,    24,     3,    49
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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


/*----------.
| yyparse.  |
`----------*/

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
  if (yypact_value_is_default (yyn))
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

/* Line 1806 of yacc.c  */
#line 42 "mylang.y"
    {
				(yyval.node)=noden("program");
				head=(yyval.node);	
				push((yyval.node),noden("PROGRAM"));
				push((yyval.node),nodes((yyvsp[(2) - (10)].str),"IDENT"));
				push((yyval.node),(yyvsp[(5) - (10)].node));
				push((yyval.node),noden("IS"));
				push((yyval.node),(yyvsp[(7) - (10)].node));
				push((yyval.node),noden("BEGIN"));
				push((yyval.node),(yyvsp[(9) - (10)].node));
				push((yyval.node),noden("END"));}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 54 "mylang.y"
    {(yyval.node)=noden("boolean");push((yyval.node),nodei(1,"BOOL"));}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 55 "mylang.y"
    {(yyval.node)=noden("boolean");push((yyval.node),nodei(0,"BOOL"));}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 57 "mylang.y"
    {(yyval.node)=noden("exp");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 58 "mylang.y"
    {(yyval.node)=noden("exp");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 59 "mylang.y"
    {(yyval.node)=noden("exp");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 65 "mylang.y"
    {(yyval.node)=noden("indices");push((yyval.node),(yyvsp[(2) - (3)].node));}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 66 "mylang.y"
    {(yyval.node)=noden("indices");push((yyval.node),(yyvsp[(2) - (4)].node));push((yyval.node),(yyvsp[(4) - (4)].node));}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 68 "mylang.y"
    {(yyval.node)=noden("var");push((yyval.node),nodes((yyvsp[(1) - (1)].str),"IDENT"));}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 69 "mylang.y"
    {(yyval.node)=noden("var");push((yyval.node),(yyvsp[(1) - (3)].node));push((yyval.node),nodes(".","DOT"));
							push((yyval.node),nodes((yyvsp[(3) - (3)].str),"IDENT"));}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 71 "mylang.y"
    {(yyval.node)=noden("var");push((yyval.node),(yyvsp[(1) - (2)].node));push((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 73 "mylang.y"
    {(yyval.node)=noden("nevar");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 74 "mylang.y"
    {
								(yyval.node)=noden("nevar");
								push((yyval.node),(yyvsp[(1) - (3)].node));
								push((yyval.node),nodes(",","DOT"));
								push((yyval.node),(yyvsp[(3) - (3)].node));
							}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 81 "mylang.y"
    {(yyval.node)=noden("variables");push((yyval.node),nodes("","EMPTY"));}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 82 "mylang.y"
    {(yyval.node)=noden("variables");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 84 "mylang.y"
    {(yyval.node)=noden("type");push((yyval.node),noden("INTEGER"));}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 85 "mylang.y"
    {(yyval.node)=noden("type");push((yyval.node),noden("BOOLEAN"));}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 86 "mylang.y"
    {(yyval.node)=noden("type");push((yyval.node),nodes((yyvsp[(1) - (1)].str),"IDENT")); }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 88 "mylang.y"
    {
				(yyval.node)=noden("argument");
				push((yyval.node),noden("VAR"));
				push((yyval.node),nodes((yyvsp[(2) - (5)].str),"IDENT"));
				push((yyval.node),noden("IS"));
				push((yyval.node),(yyvsp[(4) - (5)].node));}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 95 "mylang.y"
    {(yyval.node)=noden("retype");push((yyval.node),nodes("","EMPTY"));}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 96 "mylang.y"
    {
				(yyval.node)=noden("retype");
				push((yyval.node),noden("RETURN"));
				push((yyval.node),(yyvsp[(2) - (3)].node));
				}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 102 "mylang.y"
    {(yyval.node)=noden("arguments");push((yyval.node),nodes("","EMPTY"));}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 103 "mylang.y"
    {
				(yyval.node)=noden("arguments");
				push((yyval.node),(yyvsp[(1) - (2)].node));
				push((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 108 "mylang.y"
    {(yyval.node)=noden("funcheader");push((yyval.node),(yyvsp[(1) - (2)].node));push((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 110 "mylang.y"
    {(yyval.node)=noden("methods");push((yyval.node),nodes("","EMPTY"));}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 111 "mylang.y"
    {(yyval.node)=noden("methods");push((yyval.node),(yyvsp[(1) - (2)].node));push((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 113 "mylang.y"
    {(yyval.node)=noden("nevalues");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 114 "mylang.y"
    {
				(yyval.node)=noden("nevalues");
				push((yyval.node),(yyvsp[(1) - (3)].node));
				push((yyval.node),nodes(",","DOT"));
				push((yyval.node),(yyvsp[(3) - (3)].node));}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 120 "mylang.y"
    {(yyval.node)=noden("values");push((yyval.node),nodes("","EMPTY"));}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 121 "mylang.y"
    {(yyval.node)=noden("nevalues");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 123 "mylang.y"
    {(yyval.node)=noden("fname");push((yyval.node),nodes((yyvsp[(1) - (1)].str),"IDENT"));}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 124 "mylang.y"
    {
				(yyval.node)=noden("fname");
				push((yyval.node),(yyvsp[(1) - (3)].node));
				push((yyval.node),nodes(".","DOT"));
				push((yyval.node),nodes((yyvsp[(3) - (3)].str),"IDENT"));
			}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 131 "mylang.y"
    {(yyval.node)=noden("fcall");push((yyval.node),(yyvsp[(1) - (4)].node));
			/*	push($$,noden("("));*/push((yyval.node),(yyvsp[(3) - (4)].node));/*push($$,noden(")"));*/}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 134 "mylang.y"
    {(yyval.node)=noden("primary");push((yyval.node),nodei((yyvsp[(1) - (1)].integer),"NUM"));}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 135 "mylang.y"
    {(yyval.node)=noden("primary");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 136 "mylang.y"
    {(yyval.node)=noden("primary");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 137 "mylang.y"
    {(yyval.node)=noden("primary");/*push($$,noden("("));*/
				push((yyval.node),(yyvsp[(2) - (3)].node));/*push($$,noden(")"));*/}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 140 "mylang.y"
    {(yyval.node)=noden("term");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 141 "mylang.y"
    {(yyval.node)=noden("term");
				push((yyval.node),(yyvsp[(1) - (3)].node));push((yyval.node),nodes("*","OP"));push((yyval.node),(yyvsp[(3) - (3)].node));}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 143 "mylang.y"
    {(yyval.node)=noden("term");
				push((yyval.node),(yyvsp[(1) - (3)].node));push((yyval.node),nodes("/","OP"));push((yyval.node),(yyvsp[(3) - (3)].node));}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 145 "mylang.y"
    {(yyval.node)=noden("term");	
				push((yyval.node),(yyvsp[(1) - (3)].node));push((yyval.node),nodes("%","OP"));push((yyval.node),(yyvsp[(3) - (3)].node));}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 148 "mylang.y"
    {(yyval.node)=noden("final");
				push((yyval.node),(yyvsp[(1) - (3)].node));push((yyval.node),nodes("+","OP"));push((yyval.node),(yyvsp[(3) - (3)].node));}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 150 "mylang.y"
    {(yyval.node)=noden("final");
				push((yyval.node),(yyvsp[(1) - (3)].node));push((yyval.node),nodes("-","OP"));push((yyval.node),(yyvsp[(3) - (3)].node));}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 152 "mylang.y"
    {(yyval.node)=noden("final");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 154 "mylang.y"
    {(yyval.node)=noden("compare_op");push((yyval.node),nodes("==","COP"));}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 155 "mylang.y"
    {(yyval.node)=noden("compare_op");push((yyval.node),nodes("less","COP"));}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 156 "mylang.y"
    {(yyval.node)=noden("compare_op");push((yyval.node),nodes("large","COP"));}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 157 "mylang.y"
    {(yyval.node)=noden("compare_op");push((yyval.node),nodes("large_equal","COP"));}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 158 "mylang.y"
    {(yyval.node)=noden("compare_op");push((yyval.node),nodes("less_equal","COP"));}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 160 "mylang.y"
    {(yyval.node)=noden("bprimary");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 161 "mylang.y"
    {(yyval.node)=noden("bprimary");push((yyval.node),(yyvsp[(1) - (3)].node)); 
				push((yyval.node),(yyvsp[(2) - (3)].node));push((yyval.node),(yyvsp[(3) - (3)].node));}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 164 "mylang.y"
    {(yyval.node)=noden("bterm");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 165 "mylang.y"
    {(yyval.node)=noden("bterm");
				push((yyval.node),(yyvsp[(1) - (3)].node));push((yyval.node),noden("AND"));push((yyval.node),(yyvsp[(3) - (3)].node));}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 168 "mylang.y"
    {(yyval.node)=noden("bexpressions");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 169 "mylang.y"
    {(yyval.node)=noden("bexpressions");
				push((yyval.node),(yyvsp[(1) - (3)].node));push((yyval.node),noden("OR"));push((yyval.node),(yyvsp[(3) - (3)].node));}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 172 "mylang.y"
    {
				(yyval.node)=noden("elif");push((yyval.node),noden("ELIF"));push((yyval.node),(yyvsp[(2) - (4)].node));
				push((yyval.node),noden("THEN"));}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 176 "mylang.y"
    {(yyval.node)=noden("elifs");push((yyval.node),nodes("","EMPTY"));}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 177 "mylang.y"
    {(yyval.node)=noden("eifs");push((yyval.node),(yyvsp[(1) - (2)].node));push((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 179 "mylang.y"
    {(yyval.node)=noden("else");push((yyval.node),nodes("","EMPTY"));}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 180 "mylang.y"
    {(yyval.node)=noden("else");
				push((yyval.node),noden("ELSE"));push((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 183 "mylang.y"
    {(yyval.node)=noden("if");
				push((yyval.node),noden("IF"));push((yyval.node),(yyvsp[(2) - (8)].node));push((yyval.node),noden("THEN"));
				push((yyval.node),(yyvsp[(4) - (8)].node));push((yyval.node),(yyvsp[(5) - (8)].node));push((yyval.node),(yyvsp[(6) - (8)].node));push((yyval.node),noden("END_IF"));}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 187 "mylang.y"
    {(yyval.node)=noden("while");
				push((yyval.node),noden("WHILE"));push((yyval.node),(yyvsp[(2) - (6)].node));push((yyval.node),noden("DO"));
				push((yyval.node),(yyvsp[(4) - (6)].node));push((yyval.node),noden("END_WHILE"));}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 191 "mylang.y"
    {(yyval.node)=noden("repeat");
				push((yyval.node),noden("REPEAT"));push((yyval.node),(yyvsp[(2) - (5)].node));
				push((yyval.node),noden("UNTIL"));push((yyval.node),(yyvsp[(4) - (5)].node));}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 195 "mylang.y"
    {(yyval.node)=noden("foreach");
				push((yyval.node),noden("FOREACH"));push((yyval.node),nodes((yyvsp[(2) - (8)].str),"IDENT"));
				push((yyval.node),noden("IN"));push((yyval.node),(yyvsp[(4) - (8)].node));push((yyval.node),noden("DO"));
				push((yyval.node),(yyvsp[(6) - (8)].node));push((yyval.node),noden("END_FOREACH"));}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 200 "mylang.y"
    {(yyval.node)=noden("print");push((yyval.node),noden("PRINT"));
				push((yyval.node),(yyvsp[(2) - (3)].node));}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 203 "mylang.y"
    {(yyval.node)=noden("assignment");push((yyval.node),(yyvsp[(1) - (4)].node));
					push((yyval.node),nodes(":=","ASSIGN"));push((yyval.node),(yyvsp[(3) - (4)].node));}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 206 "mylang.y"
    {(yyval.node)=noden("return");push((yyval.node),noden("RETURN"));
				push((yyval.node),(yyvsp[(2) - (3)].node));}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 209 "mylang.y"
    {
				(yyval.node)=noden("function");
				push((yyval.node),noden("FUNCTION"));
				push((yyval.node),nodes((yyvsp[(2) - (14)].str),"IDENT"));
				push((yyval.node),(yyvsp[(4) - (14)].node));
				push((yyval.node),(yyvsp[(6) - (14)].node));
				push((yyval.node),noden("IS"));
				push((yyval.node),(yyvsp[(8) - (14)].node));
				push((yyval.node),noden("BEGIN"));
				push((yyval.node),(yyvsp[(10) - (14)].node));
				push((yyval.node),noden("END_FUNCTION"));
				push((yyval.node),nodes((yyvsp[(13) - (14)].str),"IDENT"));
			}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 223 "mylang.y"
    {
				(yyval.node)=noden("class");
				push((yyval.node),noden("TYPE"));
				push((yyval.node),nodes((yyvsp[(2) - (9)].str),"IDENT"));
				push((yyval.node),noden("IS_CLASS"));
				push((yyval.node),(yyvsp[(5) - (9)].node));push((yyval.node),(yyvsp[(6) - (9)].node));push((yyval.node),noden("END_CLASS"));}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 230 "mylang.y"
    {
				(yyval.node)=noden("class");
				push((yyval.node),noden("TYPE"));
				push((yyval.node),nodes((yyvsp[(2) - (11)].str),"IDENT"));
				push((yyval.node),noden("IS_CLASS_EXTENDS"));
				push((yyval.node),nodes((yyvsp[(6) - (11)].str),"IDENT"));
				push((yyval.node),(yyvsp[(7) - (11)].node));push((yyval.node),(yyvsp[(8) - (11)].node));push((yyval.node),noden("END_CLASS"));}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 238 "mylang.y"
    {(yyval.node)=noden("array");
				push((yyval.node),noden("TYPE"));
				push((yyval.node),nodes((yyvsp[(2) - (8)].str),"IDENT"));
				push((yyval.node),noden("IS_ARRAY_OF"));
				push((yyval.node),nodei((yyvsp[(6) - (8)].integer),"NUM"));
				push((yyval.node),(yyvsp[(7) - (8)].node));}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 245 "mylang.y"
    {(yyval.node)=noden("declar");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 246 "mylang.y"
    {(yyval.node)=noden("declar");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 247 "mylang.y"
    {(yyval.node)=noden("declar");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 250 "mylang.y"
    {(yyval.node)=noden("sentence");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 251 "mylang.y"
    {(yyval.node)=noden("sentence");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 252 "mylang.y"
    {(yyval.node)=noden("sentence");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 253 "mylang.y"
    {(yyval.node)=noden("sentence");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 254 "mylang.y"
    {(yyval.node)=noden("sentence");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 255 "mylang.y"
    {(yyval.node)=noden("sentence");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 256 "mylang.y"
    {(yyval.node)=noden("sentence");push((yyval.node),(yyvsp[(1) - (2)].node));}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 257 "mylang.y"
    {(yyval.node)=noden("sentence");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 259 "mylang.y"
    {(yyval.node)=noden("declarblock");push((yyval.node),nodes("","EMPTY"));}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 260 "mylang.y"
    {(yyval.node)=noden("declarblock");push((yyval.node),(yyvsp[(1) - (2)].node));push((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 262 "mylang.y"
    {(yyval.node)=noden("block");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 263 "mylang.y"
    {(yyval.node)=noden("block");push((yyval.node),(yyvsp[(1) - (2)].node));push((yyval.node),(yyvsp[(2) - (2)].node));}
    break;



/* Line 1806 of yacc.c  */
#line 2274 "mylang.tab.c"
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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



/* Line 2067 of yacc.c  */
#line 265 "mylang.y"


void yyerror (char const *s)
{
	      printf ("%s\n", s);
}
void push(Node * ptr,Node * child)
{
	if(ptr->first==NULL)
		ptr->first=ptr->last=child;
	else
	{
		ptr->last->next=child;
		ptr->last=child;
	}	
	
}
Node* nodes(const char *str,const char* name)
{
	Node* nd=new(Node);
	nd->type=1;
	nd->name=(char*)malloc(strlen(name));
	strcpy(nd->name,name);
	nd->str=(char*)malloc(strlen(str));
	strcpy(nd->str,str);
	nd->first=nd->last=nd->next=NULL;
	return nd;	
}
Node *nodei(int i,const char* name)
{

	Node* nd=new(Node);
	nd->type=2;
	nd->name=(char*)malloc(strlen(name));
	strcpy(nd->name,name);
	nd->integer=i;
	nd->first=nd->last=nd->next=NULL;
	return nd;	
}
Node *noden(const char *name)
{
	
	Node* nd=new(Node);
	nd->type=0;
	nd->name=(char*)malloc(strlen(name));
	strcpy(nd->name,name);
	nd->first=nd->last=nd->next=NULL;
	return nd;	
}
void print(Node* node,int tab)
{
	int i;
	Node* ptr;
	for(i=0;i<=tab;i++)
		printf(" ");
	printf("<%s>\n",node->name);
	if(node->type!=0)
	{
		for(i=0;i<=tab+1;i++)
			printf(" ");
		if(node->type==1)
			printf("%s\n",node->str);
		else
			printf("%d\n",node->integer);
		
	}
	for(ptr=node->first;ptr!=NULL;ptr=ptr->next)
	{
		print(ptr,tab+1);
	}
	for(i=0;i<=tab;i++)
		printf(" ");
	printf("</%s>\n",node->name);
}
void lexical()
{

	int token;
	while((token=yylex())>1)
	{
		switch(token)
		{
#define GOT_TOKEN(TAT) case TAT: printf(#TAT " "); break
  GOT_TOKEN(IDENT); GOT_TOKEN(NUM); GOT_TOKEN(PROGRAM); GOT_TOKEN(IS);
  GOT_TOKEN(BEGINS); GOT_TOKEN(END); GOT_TOKEN(TYPE); GOT_TOKEN(ARRAY); GOT_TOKEN(OF); GOT_TOKEN(CLASS); GOT_TOKEN(EXTENDS); GOT_TOKEN(FUNCTION);
  GOT_TOKEN(RETURN); GOT_TOKEN(ASSIGN); GOT_TOKEN(PRINT); GOT_TOKEN(FOREACH); GOT_TOKEN(IN); GOT_TOKEN(DO); GOT_TOKEN(REPEAT); GOT_TOKEN(UNTIL);
  GOT_TOKEN(WHILE); GOT_TOKEN(IF); GOT_TOKEN(THEN); GOT_TOKEN(ELSE); GOT_TOKEN(ELIF); GOT_TOKEN(OR); GOT_TOKEN(AND); GOT_TOKEN(EQUAL); GOT_TOKEN(LEQA);
  GOT_TOKEN(SEQA); GOT_TOKEN(YES); GOT_TOKEN(NO); GOT_TOKEN(VAR); GOT_TOKEN(INTEGER); GOT_TOKEN(BOOLEAN); 
			default:
printf("%c ", token);  
		}
	}
	if(token==1)
		printf("ERROR: Unexpected %s\n",yylval);
}
Node* syntax(int p)
{
//	yydebug=1;
				yyparse();
		
//	printf("%s\n","<?xml   version=\"1.0\"   encoding=\"utf-8\"?>");       	
				if(head!=NULL && p)
					print(head,0);
		if(head==NULL)
			return 0;
		else
			return head;
}

