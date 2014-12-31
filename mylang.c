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
#line 99 "y.tab.c"

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
/* Tokens.  */
#define IDENT 258
#define NUM 259
#define PROGRAM 260
#define IS 261
#define BEGINS 262
#define END 263
#define TYPE 264
#define ARRAY 265
#define OF 266
#define CLASS 267
#define EXTENDS 268
#define FUNCTION 269
#define RETURN 270
#define ASSIGN 271
#define PRINT 272
#define FOREACH 273
#define IN 274
#define DO 275
#define REPEAT 276
#define UNTIL 277
#define WHILE 278
#define IF 279
#define THEN 280
#define ELSE 281
#define ELIF 282
#define OR 283
#define AND 284
#define EQUAL 285
#define LEQA 286
#define SEQA 287
#define YES 288
#define NO 289
#define VAR 290
#define INTEGER 291
#define BOOLEAN 292




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 29 "mylang.y"

	char* str;
	int integer;
	struct Node *node;



/* Line 293 of yacc.c  */
#line 217 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 229 "y.tab.c"

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
#define YYLAST   182

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNRULES -- Number of states.  */
#define YYNSTATES  187

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
      33,    35,    39,    41,    44,    46,    50,    51,    53,    55,
      57,    59,    65,    66,    70,    71,    74,    77,    78,    81,
      83,    87,    88,    90,    92,    96,   101,   103,   105,   107,
     111,   113,   117,   121,   125,   129,   133,   135,   137,   139,
     141,   143,   145,   147,   151,   153,   157,   159,   163,   168,
     169,   172,   173,   176,   185,   192,   198,   207,   211,   216,
     220,   235,   245,   257,   266,   268,   270,   272,   274,   276,
     278,   280,   282,   284,   287,   289,   290,   293,   295
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,     5,     3,    43,    44,    93,     6,    64,
       7,    94,     8,    -1,    33,    -1,    34,    -1,    73,    -1,
      54,    -1,    70,    -1,    45,    73,    46,    -1,    45,    73,
      46,    56,    -1,     3,    -1,     3,    47,     3,    -1,    57,
      -1,    57,    56,    -1,    58,    -1,    58,    48,    59,    -1,
      -1,    59,    -1,    36,    -1,    37,    -1,     3,    -1,    35,
       3,     6,    61,    49,    -1,    -1,    15,    61,    49,    -1,
      -1,    62,    64,    -1,    64,    63,    -1,    -1,    88,    66,
      -1,    55,    -1,    55,    48,    67,    -1,    -1,    67,    -1,
       3,    -1,     3,    47,     3,    -1,    69,    43,    68,    44,
      -1,     4,    -1,    58,    -1,    70,    -1,    43,    55,    44,
      -1,    71,    -1,    72,    40,    71,    -1,    72,    41,    71,
      -1,    72,    42,    71,    -1,    73,    38,    72,    -1,    73,
      39,    72,    -1,    72,    -1,    30,    -1,    50,    -1,    51,
      -1,    32,    -1,    31,    -1,    55,    -1,    55,    74,    55,
      -1,    75,    -1,    75,    29,    76,    -1,    76,    -1,    76,
      28,    77,    -1,    27,    77,    25,    94,    -1,    -1,    78,
      79,    -1,    -1,    26,    94,    -1,    24,    77,    25,    94,
      79,    80,     8,    24,    -1,    23,    77,    20,    94,     8,
      23,    -1,    21,    94,    22,    77,    49,    -1,    18,     3,
      19,    58,    20,    94,     8,    18,    -1,    17,    55,    49,
      -1,    58,    16,    55,    49,    -1,    15,    55,    49,    -1,
      14,     3,    43,    60,    44,    65,     6,    64,     7,    94,
       8,    14,     3,    49,    -1,     9,     3,     6,    12,    64,
      66,     8,    12,    49,    -1,     9,     3,     6,    12,    13,
       3,    64,    66,     8,    12,    49,    -1,     9,     3,     6,
      10,    11,     4,    61,    49,    -1,    88,    -1,    89,    -1,
      90,    -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,
      87,    -1,    86,    -1,    70,    49,    -1,    85,    -1,    -1,
      91,    93,    -1,    92,    -1,    92,    94,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    42,    42,    54,    55,    57,    58,    59,    65,    66,
      68,    72,    78,    79,    81,    82,    89,    90,    92,    93,
      94,    96,   103,   104,   110,   111,   116,   118,   119,   121,
     122,   128,   129,   131,   132,   139,   142,   143,   144,   145,
     148,   149,   151,   153,   156,   158,   160,   162,   163,   164,
     165,   166,   168,   169,   172,   173,   176,   177,   180,   184,
     185,   187,   188,   191,   195,   199,   203,   208,   211,   214,
     217,   231,   237,   246,   253,   254,   255,   258,   259,   260,
     261,   262,   263,   264,   265,   267,   268,   270,   271
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
  "'>'", "$accept", "program", "boolean", "exp", "indices", "svar", "var",
  "nevar", "variables", "type", "argument", "retype", "arguments",
  "funcheader", "methods", "nevalues", "values", "fname", "fcall",
  "primary", "term", "final", "coperator", "bprimary", "bterm",
  "bexpressions", "elif", "elifs", "else", "if", "while", "repeat",
  "foreach", "print", "assignment", "return", "function", "class", "array",
  "declar", "sentence", "declarblock", "block", 0
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
      57,    57,    58,    58,    59,    59,    60,    60,    61,    61,
      61,    62,    63,    63,    64,    64,    65,    66,    66,    67,
      67,    68,    68,    69,    69,    70,    71,    71,    71,    71,
      72,    72,    72,    72,    73,    73,    73,    74,    74,    74,
      74,    74,    75,    75,    76,    76,    77,    77,    78,    79,
      79,    80,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    89,    90,    91,    91,    91,    92,    92,    92,
      92,    92,    92,    92,    92,    93,    93,    94,    94
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    10,     1,     1,     1,     1,     1,     3,     4,
       1,     3,     1,     2,     1,     3,     0,     1,     1,     1,
       1,     5,     0,     3,     0,     2,     2,     0,     2,     1,
       3,     0,     1,     1,     3,     4,     1,     1,     1,     3,
       1,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     3,     4,     0,
       2,     0,     2,     8,     6,     5,     8,     3,     4,     3,
      14,     9,    11,     8,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     0,     2,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,    85,     0,     0,    74,
      75,    76,    85,     0,     0,     0,    86,    24,     0,    16,
       0,    24,     0,     0,    24,    10,    12,    14,    17,     0,
       0,    25,     0,     0,     0,    27,     0,     0,    13,     0,
      24,     0,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    77,    78,    79,    80,    84,    82,    81,    87,
       0,     0,    24,     0,    27,    11,    36,     0,    37,    38,
      40,    46,     0,    15,    22,     0,    20,    18,    19,     0,
       0,     3,     4,     6,     0,     7,     5,     0,     0,     0,
      52,    54,    56,     0,     0,     0,    31,    83,    88,     2,
       0,    27,     0,    28,     0,     0,     0,     0,     0,     0,
       8,     0,    26,    24,    21,    11,    69,    67,     0,     0,
      47,    51,    50,    48,    49,     0,     0,     0,     0,     0,
       0,    29,    32,     0,    73,     0,     0,    39,    41,    42,
      43,    44,    45,     9,     0,     0,     0,     0,    53,    55,
      57,     0,    59,    68,     0,    35,     0,    71,    23,     0,
       0,    65,     0,     0,    59,    61,    30,     0,     0,     0,
      64,     0,    60,     0,     0,    72,     0,     0,     0,    62,
       0,     0,    66,    58,    63,     0,    70
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    83,    90,    38,    26,    68,    28,    29,    79,
      21,   112,    22,    75,    63,   132,   133,    50,    85,    70,
      71,    86,   125,    91,    92,    93,   164,   165,   174,    52,
      53,    54,    55,    56,    57,    58,    64,    10,    11,    12,
      59,    13,    60
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -60
static const yytype_int16 yypact[] =
{
      17,    41,    71,    29,   -60,    36,    12,    70,    78,   -60,
     -60,   -60,    12,    76,    77,    45,   -60,    49,    43,    86,
      87,    49,    85,    83,     1,    48,    55,    53,   -60,    58,
      97,   -60,    90,   100,   103,    98,   112,    14,   -60,    86,
      49,     2,    11,     8,     8,   115,    90,     8,     8,   105,
      79,    75,   -60,   -60,   -60,   -60,   -60,   -60,   -60,    90,
     111,     2,    49,   117,    98,   -60,   -60,     8,   -60,   -60,
     -60,     6,   -14,   -60,   116,   120,   -60,   -60,   -60,    84,
     124,   -60,   -60,   -60,    88,    25,    -4,    89,   113,   114,
      -1,   110,   106,   123,   119,     8,     8,   -60,   -60,   -60,
      96,    98,   134,   -60,   104,    14,    14,    14,    14,    14,
      55,     2,   -60,    49,   -60,   107,   -60,   -60,    86,     8,
     -60,   -60,   -60,   -60,   -60,     8,     8,     8,    90,    90,
     102,   101,   -60,   108,   -60,   145,   109,   -60,   -60,   -60,
     -60,     6,     6,   -60,   118,   148,   136,   121,   -60,   -60,
     -60,   149,   133,   -60,     8,   -60,   150,   -60,   -60,    90,
      90,   -60,   138,     8,   133,   137,   -60,   122,   156,   157,
     -60,   141,   -60,    90,   160,   -60,   155,   154,    90,   -60,
     151,   170,   -60,   -60,   -60,   125,   -60
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -60,   -60,   -60,   -34,    66,   -60,   -19,   139,   -60,   -59,
     -60,   -60,   -17,   -60,   -45,    23,   -60,   -60,   -31,   -37,
     -49,   142,   -60,   -60,    54,   -40,   -60,    18,   -60,   -60,
     -60,   -60,   -60,   -60,   -60,   -60,    31,   -60,   -60,   -60,
     -60,   169,   -43
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -39
static const yytype_int16 yytable[] =
{
      27,    51,   100,    89,    31,    76,    69,    35,    94,    84,
      87,    42,    66,    49,    34,    51,    98,    42,    66,   103,
      27,     7,     1,    74,   108,   109,     8,    49,    51,   120,
     121,   122,   110,   104,   108,   109,    20,     9,    77,    78,
      49,    81,    82,     9,     3,   101,   105,   106,   107,   123,
     124,    67,   144,    23,   -33,    24,   135,    67,    80,   141,
     142,   130,   131,   -38,   -38,   -38,   -38,   -38,   138,   139,
     140,     4,     5,    14,    69,    69,    69,    69,    69,   147,
       6,    15,    17,    18,    20,   151,   152,   150,    19,    25,
      30,   148,    32,    42,    33,    36,   145,    51,    51,   146,
      37,    39,    40,    41,    61,    43,    62,    44,    45,    49,
      49,    46,     8,    47,    48,    65,   168,   169,    88,    99,
     131,    95,    96,   171,    97,   102,   113,   115,    51,    51,
     179,   111,   118,   114,   127,   183,   119,   116,   117,   126,
      49,    49,    51,   128,   129,   134,   136,    51,   137,   154,
     -34,   153,   155,   156,    49,   159,   160,   162,   157,    49,
     163,   170,   167,   173,   176,   177,   178,   158,   180,   181,
     161,   175,   182,   185,   186,   184,   143,   166,    73,    72,
     149,    16,   172
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-60))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
{
      19,    32,    61,    46,    21,     3,    37,    24,    48,    43,
      44,     3,     4,    32,    13,    46,    59,     3,     4,    64,
      39,     9,     5,    40,    38,    39,    14,    46,    59,    30,
      31,    32,    46,    67,    38,    39,    35,     6,    36,    37,
      59,    33,    34,    12,     3,    62,    40,    41,    42,    50,
      51,    43,   111,    10,    43,    12,   101,    43,    47,   108,
     109,    95,    96,    38,    39,    40,    41,    42,   105,   106,
     107,     0,    43,     3,   105,   106,   107,   108,   109,   119,
      44,     3,     6,     6,    35,   128,   129,   127,    43,     3,
       3,   125,     7,     3,    11,    47,   113,   128,   129,   118,
      45,    48,    44,     6,     4,    15,     3,    17,    18,   128,
     129,    21,    14,    23,    24,     3,   159,   160,     3,     8,
     154,    16,    43,   163,    49,     8,     6,     3,   159,   160,
     173,    15,    19,    49,    28,   178,    22,    49,    49,    29,
     159,   160,   173,    20,    25,    49,    12,   178,    44,    48,
      43,    49,    44,     8,   173,     7,    20,     8,    49,   178,
      27,    23,    12,    26,     8,     8,    25,    49,     8,    14,
      49,    49,    18,     3,    49,    24,   110,   154,    39,    37,
     126,    12,   164
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    53,     3,     0,    43,    44,     9,    14,    88,
      89,    90,    91,    93,     3,     3,    93,     6,     6,    43,
      35,    62,    64,    10,    12,     3,    57,    58,    59,    60,
       3,    64,     7,    11,    13,    64,    47,    45,    56,    48,
      44,     6,     3,    15,    17,    18,    21,    23,    24,    58,
      69,    70,    81,    82,    83,    84,    85,    86,    87,    92,
      94,     4,     3,    66,    88,     3,     4,    43,    58,    70,
      71,    72,    73,    59,    64,    65,     3,    36,    37,    61,
      47,    33,    34,    54,    55,    70,    73,    55,     3,    94,
      55,    75,    76,    77,    77,    16,    43,    49,    94,     8,
      61,    64,     8,    66,    55,    40,    41,    42,    38,    39,
      46,    15,    63,     6,    49,     3,    49,    49,    19,    22,
      30,    31,    32,    50,    51,    74,    29,    28,    20,    25,
      55,    55,    67,    68,    49,    66,    12,    44,    71,    71,
      71,    72,    72,    56,    61,    64,    58,    77,    55,    76,
      77,    94,    94,    49,    48,    44,     8,    49,    49,     7,
      20,    49,     8,    27,    78,    79,    67,    12,    94,    94,
      23,    77,    79,    26,    80,    49,     8,     8,    25,    94,
       8,    14,    18,    94,    24,     3,    49
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
    {
						(yyval.node)=noden("svar");
						push((yyval.node),nodes((yyvsp[(1) - (1)].str),"IDENT"));
					}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 72 "mylang.y"
    {	(yyval.node)=noden("svar");
									push((yyval.node),nodes((yyvsp[(1) - (3)].str),"IDENT"));
									push((yyval.node),nodes(".","DOT"));
									push((yyval.node),nodes((yyvsp[(3) - (3)].str),"IDENT"));
								}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 78 "mylang.y"
    {(yyval.node)=noden("var");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 79 "mylang.y"
    {(yyval.node)=noden("var");push((yyval.node),(yyvsp[(1) - (2)].node));push((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 81 "mylang.y"
    {(yyval.node)=noden("nevar");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 82 "mylang.y"
    {
								(yyval.node)=noden("nevar");
								push((yyval.node),(yyvsp[(1) - (3)].node));
								push((yyval.node),nodes(",","DOT"));
								push((yyval.node),(yyvsp[(3) - (3)].node));
							}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 89 "mylang.y"
    {(yyval.node)=noden("variables");push((yyval.node),nodes("","EMPTY"));}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 90 "mylang.y"
    {(yyval.node)=noden("variables");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 92 "mylang.y"
    {(yyval.node)=noden("type");push((yyval.node),noden("INTEGER"));}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 93 "mylang.y"
    {(yyval.node)=noden("type");push((yyval.node),noden("BOOLEAN"));}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 94 "mylang.y"
    {(yyval.node)=noden("type");push((yyval.node),nodes((yyvsp[(1) - (1)].str),"IDENT")); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 96 "mylang.y"
    {
				(yyval.node)=noden("argument");
				push((yyval.node),noden("VAR"));
				push((yyval.node),nodes((yyvsp[(2) - (5)].str),"IDENT"));
				push((yyval.node),noden("IS"));
				push((yyval.node),(yyvsp[(4) - (5)].node));}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 103 "mylang.y"
    {(yyval.node)=noden("retype");push((yyval.node),nodes("","EMPTY"));}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 104 "mylang.y"
    {
				(yyval.node)=noden("retype");
				push((yyval.node),noden("RETURN"));
				push((yyval.node),(yyvsp[(2) - (3)].node));
				}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 110 "mylang.y"
    {(yyval.node)=noden("arguments");push((yyval.node),nodes("","EMPTY"));}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 111 "mylang.y"
    {
				(yyval.node)=noden("arguments");
				push((yyval.node),(yyvsp[(1) - (2)].node));
				push((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 116 "mylang.y"
    {(yyval.node)=noden("funcheader");push((yyval.node),(yyvsp[(1) - (2)].node));push((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 118 "mylang.y"
    {(yyval.node)=noden("methods");push((yyval.node),nodes("","EMPTY"));}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 119 "mylang.y"
    {(yyval.node)=noden("methods");push((yyval.node),(yyvsp[(1) - (2)].node));push((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 121 "mylang.y"
    {(yyval.node)=noden("nevalues");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 122 "mylang.y"
    {
				(yyval.node)=noden("nevalues");
				push((yyval.node),(yyvsp[(1) - (3)].node));
				push((yyval.node),nodes(",","DOT"));
				push((yyval.node),(yyvsp[(3) - (3)].node));}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 128 "mylang.y"
    {(yyval.node)=noden("values");push((yyval.node),nodes("","EMPTY"));}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 129 "mylang.y"
    {(yyval.node)=noden("nevalues");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 131 "mylang.y"
    {(yyval.node)=noden("fname");push((yyval.node),nodes((yyvsp[(1) - (1)].str),"IDENT"));}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 132 "mylang.y"
    {
				(yyval.node)=noden("fname");
				push((yyval.node),nodes((yyvsp[(1) - (3)].str),"IDENT"));
				push((yyval.node),nodes(".","DOT"));
				push((yyval.node),nodes((yyvsp[(3) - (3)].str),"IDENT"));
			}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 139 "mylang.y"
    {(yyval.node)=noden("fcall");push((yyval.node),(yyvsp[(1) - (4)].node));
			/*	push($$,noden("("));*/push((yyval.node),(yyvsp[(3) - (4)].node));/*push($$,noden(")"));*/}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 142 "mylang.y"
    {(yyval.node)=noden("primary");push((yyval.node),nodei((yyvsp[(1) - (1)].integer),"NUM"));}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 143 "mylang.y"
    {(yyval.node)=noden("primary");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 144 "mylang.y"
    {(yyval.node)=noden("primary");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 145 "mylang.y"
    {(yyval.node)=noden("primary");/*push($$,noden("("));*/
				push((yyval.node),(yyvsp[(2) - (3)].node));/*push($$,noden(")"));*/}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 148 "mylang.y"
    {(yyval.node)=noden("term");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 149 "mylang.y"
    {(yyval.node)=noden("term");
				push((yyval.node),(yyvsp[(1) - (3)].node));push((yyval.node),nodes("*","OP"));push((yyval.node),(yyvsp[(3) - (3)].node));}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 151 "mylang.y"
    {(yyval.node)=noden("term");
				push((yyval.node),(yyvsp[(1) - (3)].node));push((yyval.node),nodes("/","OP"));push((yyval.node),(yyvsp[(3) - (3)].node));}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 153 "mylang.y"
    {(yyval.node)=noden("term");	
				push((yyval.node),(yyvsp[(1) - (3)].node));push((yyval.node),nodes("%","OP"));push((yyval.node),(yyvsp[(3) - (3)].node));}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 156 "mylang.y"
    {(yyval.node)=noden("final");
				push((yyval.node),(yyvsp[(1) - (3)].node));push((yyval.node),nodes("+","OP"));push((yyval.node),(yyvsp[(3) - (3)].node));}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 158 "mylang.y"
    {(yyval.node)=noden("final");
				push((yyval.node),(yyvsp[(1) - (3)].node));push((yyval.node),nodes("-","OP"));push((yyval.node),(yyvsp[(3) - (3)].node));}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 160 "mylang.y"
    {(yyval.node)=noden("final");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 162 "mylang.y"
    {(yyval.node)=noden("compare_op");push((yyval.node),nodes("==","COP"));}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 163 "mylang.y"
    {(yyval.node)=noden("compare_op");push((yyval.node),nodes("less","COP"));}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 164 "mylang.y"
    {(yyval.node)=noden("compare_op");push((yyval.node),nodes("large","COP"));}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 165 "mylang.y"
    {(yyval.node)=noden("compare_op");push((yyval.node),nodes("large_equal","COP"));}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 166 "mylang.y"
    {(yyval.node)=noden("compare_op");push((yyval.node),nodes("less_equal","COP"));}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 168 "mylang.y"
    {(yyval.node)=noden("bprimary");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 169 "mylang.y"
    {(yyval.node)=noden("bprimary");push((yyval.node),(yyvsp[(1) - (3)].node)); 
				push((yyval.node),(yyvsp[(2) - (3)].node));push((yyval.node),(yyvsp[(3) - (3)].node));}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 172 "mylang.y"
    {(yyval.node)=noden("bterm");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 173 "mylang.y"
    {(yyval.node)=noden("bterm");
				push((yyval.node),(yyvsp[(1) - (3)].node));push((yyval.node),noden("AND"));push((yyval.node),(yyvsp[(3) - (3)].node));}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 176 "mylang.y"
    {(yyval.node)=noden("bexpressions");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 177 "mylang.y"
    {(yyval.node)=noden("bexpressions");
				push((yyval.node),(yyvsp[(1) - (3)].node));push((yyval.node),noden("OR"));push((yyval.node),(yyvsp[(3) - (3)].node));}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 180 "mylang.y"
    {
				(yyval.node)=noden("elif");push((yyval.node),noden("ELIF"));push((yyval.node),(yyvsp[(2) - (4)].node));
				push((yyval.node),noden("THEN"));}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 184 "mylang.y"
    {(yyval.node)=noden("elifs");push((yyval.node),nodes("","EMPTY"));}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 185 "mylang.y"
    {(yyval.node)=noden("eifs");push((yyval.node),(yyvsp[(1) - (2)].node));push((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 187 "mylang.y"
    {(yyval.node)=noden("else");push((yyval.node),nodes("","EMPTY"));}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 188 "mylang.y"
    {(yyval.node)=noden("else");
				push((yyval.node),noden("ELSE"));push((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 191 "mylang.y"
    {(yyval.node)=noden("if");
				push((yyval.node),noden("IF"));push((yyval.node),(yyvsp[(2) - (8)].node));push((yyval.node),noden("THEN"));
				push((yyval.node),(yyvsp[(4) - (8)].node));push((yyval.node),(yyvsp[(5) - (8)].node));push((yyval.node),(yyvsp[(6) - (8)].node));push((yyval.node),noden("END_IF"));}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 195 "mylang.y"
    {(yyval.node)=noden("while");
				push((yyval.node),noden("WHILE"));push((yyval.node),(yyvsp[(2) - (6)].node));push((yyval.node),noden("DO"));
				push((yyval.node),(yyvsp[(4) - (6)].node));push((yyval.node),noden("END_WHILE"));}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 199 "mylang.y"
    {(yyval.node)=noden("repeat");
				push((yyval.node),noden("REPEAT"));push((yyval.node),(yyvsp[(2) - (5)].node));
				push((yyval.node),noden("UNTIL"));push((yyval.node),(yyvsp[(4) - (5)].node));}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 203 "mylang.y"
    {(yyval.node)=noden("foreach");
				push((yyval.node),noden("FOREACH"));push((yyval.node),nodes((yyvsp[(2) - (8)].str),"IDENT"));
				push((yyval.node),noden("IN"));push((yyval.node),(yyvsp[(4) - (8)].node));push((yyval.node),noden("DO"));
				push((yyval.node),(yyvsp[(6) - (8)].node));push((yyval.node),noden("END_FOREACH"));}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 208 "mylang.y"
    {(yyval.node)=noden("print");push((yyval.node),noden("PRINT"));
				push((yyval.node),(yyvsp[(2) - (3)].node));}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 211 "mylang.y"
    {(yyval.node)=noden("assignment");push((yyval.node),(yyvsp[(1) - (4)].node));
					push((yyval.node),nodes(":=","ASSIGN"));push((yyval.node),(yyvsp[(3) - (4)].node));}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 214 "mylang.y"
    {(yyval.node)=noden("return");push((yyval.node),noden("RETURN"));
				push((yyval.node),(yyvsp[(2) - (3)].node));}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 217 "mylang.y"
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

  case 71:

/* Line 1806 of yacc.c  */
#line 231 "mylang.y"
    {
				(yyval.node)=noden("class");
				push((yyval.node),noden("TYPE"));
				push((yyval.node),nodes((yyvsp[(2) - (9)].str),"IDENT"));
				push((yyval.node),noden("IS_CLASS"));
				push((yyval.node),(yyvsp[(5) - (9)].node));push((yyval.node),(yyvsp[(6) - (9)].node));push((yyval.node),noden("END_CLASS"));}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 238 "mylang.y"
    {
				(yyval.node)=noden("class");
				push((yyval.node),noden("TYPE"));
				push((yyval.node),nodes((yyvsp[(2) - (11)].str),"IDENT"));
				push((yyval.node),noden("IS_CLASS_EXTENDS"));
				push((yyval.node),nodes((yyvsp[(6) - (11)].str),"IDENT"));
				push((yyval.node),(yyvsp[(7) - (11)].node));push((yyval.node),(yyvsp[(8) - (11)].node));push((yyval.node),noden("END_CLASS"));}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 246 "mylang.y"
    {(yyval.node)=noden("array");
				push((yyval.node),noden("TYPE"));
				push((yyval.node),nodes((yyvsp[(2) - (8)].str),"IDENT"));
				push((yyval.node),noden("IS_ARRAY_OF"));
				push((yyval.node),nodei((yyvsp[(6) - (8)].integer),"NUM"));
				push((yyval.node),(yyvsp[(7) - (8)].node));}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 253 "mylang.y"
    {(yyval.node)=noden("declar");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 254 "mylang.y"
    {(yyval.node)=noden("declar");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 255 "mylang.y"
    {(yyval.node)=noden("declar");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 258 "mylang.y"
    {(yyval.node)=noden("sentence");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 259 "mylang.y"
    {(yyval.node)=noden("sentence");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 260 "mylang.y"
    {(yyval.node)=noden("sentence");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 261 "mylang.y"
    {(yyval.node)=noden("sentence");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 262 "mylang.y"
    {(yyval.node)=noden("sentence");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 263 "mylang.y"
    {(yyval.node)=noden("sentence");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 264 "mylang.y"
    {(yyval.node)=noden("sentence");push((yyval.node),(yyvsp[(1) - (2)].node));}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 265 "mylang.y"
    {(yyval.node)=noden("sentence");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 267 "mylang.y"
    {(yyval.node)=noden("declarblock");push((yyval.node),nodes("","EMPTY"));}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 268 "mylang.y"
    {(yyval.node)=noden("declarblock");push((yyval.node),(yyvsp[(1) - (2)].node));push((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 270 "mylang.y"
    {(yyval.node)=noden("block");push((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 271 "mylang.y"
    {(yyval.node)=noden("block");push((yyval.node),(yyvsp[(1) - (2)].node));push((yyval.node),(yyvsp[(2) - (2)].node));}
    break;



/* Line 1806 of yacc.c  */
#line 2322 "y.tab.c"
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
#line 273 "mylang.y"


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

