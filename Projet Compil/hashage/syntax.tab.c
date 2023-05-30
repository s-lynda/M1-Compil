
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
#line 1 "syntax.y"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"pile.h"
//#include "opt.h"
#include "quadruplets.h"
#define MAX 1000
#define MAX_SIZE 1000
#define HASH_SIZE 40

// #ifndef SYMBOL_TABLE_H
// #define SYMBOL_TABLE_H
// int doubleDeclaration(char idf[]);
// void modifier_type(char idf[], char type[]);
// void set_val_string(char idf[], char type[]);
// void inserer(char entite[], char code[], char type[], float val, char val_string[], int y) ;
// void initialisation();
// void afficher();
// void SetVal(char entite[], float z);
// char* get_type(char idf[]);
// #endif

#define MAX_SIZE 1000
extern int nb_ligne;
float tmp;
int yyparse(); 
int yylex();
int yyerror(char *s);
int Col=1;
char sauvidf[10];  // save type  ( BOOLEAN , CHAR FLOAT INTEGER ) , pour màj de type idf 
char sauvval[10];
char sauvindex[4];
char quad1[10]; 
char quad2[10];
int qc = 0;
float op1,op2; // gerer les exp_arthimetique pour maj de idf et test conditions 
char* chartype;
int quadindex1 ,quadindex2;


/* Line 189 of yacc.c  */
#line 115 "syntax.tab.c"

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
     mc_import = 258,
     mc_as = 259,
     mc_numpy = 260,
     mc_pil = 261,
     mc_Img = 262,
     mc_npf1 = 263,
     mc_npf3 = 264,
     mc_pilf3 = 265,
     mc_pilf2 = 266,
     mc_pilf1 = 267,
     mc_cv2f1 = 268,
     mc_cv2f2 = 269,
     mc_from = 270,
     mc_range = 271,
     mc_in = 272,
     idf = 273,
     cst_int = 274,
     cst_reel = 275,
     cst_char = 276,
     cst_bool = 277,
     mc_Int = 278,
     mc_float = 279,
     mc_bool = 280,
     mc_char = 281,
     mc_aff = 282,
     plus = 283,
     minus = 284,
     mul = 285,
     division = 286,
     mc_and = 287,
     mc_OR = 288,
     mc_not = 289,
     sup = 290,
     inf = 291,
     infOuEg = 292,
     SupOuEg = 293,
     diff = 294,
     egale = 295,
     par_O = 296,
     par_F = 297,
     mc_if = 298,
     mc_else = 299,
     mc_for = 300,
     vrg = 301,
     mc_2p = 302,
     mc_while = 303,
     croch_O = 304,
     croch_F = 305,
     tabulation = 306,
     guillemets = 307,
     sautdligne = 308,
     point = 309
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 41 "syntax.y"

        int entier;
        char* str;
        float reel;



/* Line 214 of yacc.c  */
#line 213 "syntax.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 225 "syntax.tab.c"

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
#define YYFINAL  45
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   174

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNRULES -- Number of states.  */
#define YYNSTATES  164

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     9,    12,    15,    16,    19,    21,
      24,    29,    34,    36,    38,    41,    45,    47,    53,    57,
      58,    60,    62,    64,    66,    68,    70,    72,    74,    76,
      78,    83,    88,    90,    98,   106,   115,   121,   125,   130,
     134,   138,   142,   146,   149,   153,   155,   157,   159,   161,
     163,   167,   171,   175,   179,   183,   187,   195,   197,   199,
     201,   205,   208,   211,   217,   224,   227,   233,   236,   242,
     246,   252,   255
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      56,     0,    -1,    60,    56,    -1,    65,    56,    -1,    58,
      56,    -1,    57,    56,    -1,    -1,    53,    57,    -1,    53,
      -1,     3,    59,    -1,     3,    59,     4,    18,    -1,    15,
       6,     3,     7,    -1,     5,    -1,     6,    -1,    61,    57,
      -1,    64,    18,    63,    -1,    62,    -1,    64,    18,    49,
      19,    50,    -1,    46,    18,    63,    -1,    -1,    23,    -1,
      24,    -1,    25,    -1,    26,    -1,    66,    -1,    76,    -1,
      79,    -1,    82,    -1,    86,    -1,    69,    -1,    18,    27,
      21,    57,    -1,    18,    27,    22,    57,    -1,    67,    -1,
      18,    27,     7,    54,    12,    68,    57,    -1,    18,    27,
      18,    54,     8,    68,    57,    -1,     7,    54,    11,    68,
      54,    10,    68,    57,    -1,    41,    52,    18,    52,    42,
      -1,    41,    18,    42,    -1,    18,    27,    70,    57,    -1,
      70,    28,    70,    -1,    70,    29,    70,    -1,    70,    30,
      70,    -1,    70,    31,    70,    -1,    29,    70,    -1,    41,
      70,    41,    -1,    18,    -1,    19,    -1,    20,    -1,    73,
      -1,    72,    -1,    70,    40,    70,    -1,    70,    39,    70,
      -1,    70,    36,    70,    -1,    70,    37,    70,    -1,    70,
      35,    70,    -1,    70,    38,    70,    -1,    41,    72,    42,
      74,    41,    72,    42,    -1,    32,    -1,    34,    -1,    33,
      -1,    51,    65,    75,    -1,    51,    65,    -1,    77,    75,
      -1,    78,    75,    44,    47,    57,    -1,    43,    41,    71,
      42,    47,    57,    -1,    80,    75,    -1,    81,    71,    42,
      47,    57,    -1,    48,    41,    -1,    83,    42,    47,    57,
      75,    -1,    84,    46,    70,    -1,    85,    17,    16,    41,
      70,    -1,    45,    18,    -1,    85,    47,    57,    75,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    71,    71,    72,    73,    74,    76,    80,    81,    83,
      84,    85,    88,    89,    92,    95,   106,   110,   118,   122,
     125,   126,   127,   128,   132,   133,   134,   135,   136,   139,
     140,   161,   178,   181,   182,   183,   185,   186,   189,   215,
     222,   228,   233,   245,   250,   252,   259,   260,   264,   265,
     267,   272,   277,   284,   288,   293,   300,   303,   304,   305,
     309,   310,   314,   322,   328,   337,   345,   353,   361,   370,
     382,   393,   410
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "mc_import", "mc_as", "mc_numpy",
  "mc_pil", "mc_Img", "mc_npf1", "mc_npf3", "mc_pilf3", "mc_pilf2",
  "mc_pilf1", "mc_cv2f1", "mc_cv2f2", "mc_from", "mc_range", "mc_in",
  "idf", "cst_int", "cst_reel", "cst_char", "cst_bool", "mc_Int",
  "mc_float", "mc_bool", "mc_char", "mc_aff", "plus", "minus", "mul",
  "division", "mc_and", "mc_OR", "mc_not", "sup", "inf", "infOuEg",
  "SupOuEg", "diff", "egale", "par_O", "par_F", "mc_if", "mc_else",
  "mc_for", "vrg", "mc_2p", "mc_while", "croch_O", "croch_F", "tabulation",
  "guillemets", "sautdligne", "point", "$accept", "S", "SAUT", "LIB",
  "LIBRARY", "List_Dec", "DEC", "TAB_DEC", "LIST_VAR", "TYPE", "INST",
  "AFFECT", "AFF_SPECIAL", "PATH", "AFFECT_ARITHM", "EXP_ARRITH", "COND",
  "EXP_COMPAR", "EXP_LOGIQUE", "OP_LOG", "BLOC_INST", "IF_ELSE", "B", "A",
  "WHILE", "BB", "AA", "FOR_RANGE", "CCC", "BBB", "AAA", "FOR_IN", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    56,    56,    56,    56,    57,    57,    58,
      58,    58,    59,    59,    60,    61,    61,    62,    63,    63,
      64,    64,    64,    64,    65,    65,    65,    65,    65,    66,
      66,    66,    66,    67,    67,    67,    68,    68,    69,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    71,    71,
      72,    72,    72,    72,    72,    72,    73,    74,    74,    74,
      75,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     0,     2,     1,     2,
       4,     4,     1,     1,     2,     3,     1,     5,     3,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     1,     7,     7,     8,     5,     3,     4,     3,
       3,     3,     3,     2,     3,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     7,     1,     1,     1,
       3,     2,     2,     5,     6,     2,     5,     2,     5,     3,
       5,     2,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     0,     0,     0,    20,    21,    22,    23,     0,
       0,     0,     8,     0,     6,     6,     6,     0,    16,     0,
       6,    24,    32,    29,    25,     0,     0,    26,     0,     0,
      27,     0,     0,     0,    28,    12,    13,     9,     0,     0,
       0,     0,    71,    67,     7,     1,     5,     4,     2,    14,
      19,     3,     0,    62,     0,    65,    45,    46,    47,     0,
       0,     0,     0,    49,    48,     0,     0,     0,     0,     0,
       0,     0,     0,    45,     0,     0,     0,     0,     0,     0,
       0,    15,    61,     0,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
       0,     0,    10,     0,     0,    11,     0,     0,    30,    31,
       0,    38,     0,    19,     0,    60,     0,    44,     0,    39,
      40,    41,    42,    54,    52,    53,    55,    51,    50,     0,
       0,     0,    72,     0,     0,     0,     0,     0,     0,    18,
      17,    63,    57,    59,    58,     0,    66,    68,    70,    37,
       0,     0,     0,     0,    64,     0,     0,     0,    33,    34,
       0,    36,    35,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    14,    15,    37,    16,    17,    18,    81,    19,
      20,    21,    22,   104,    23,    61,    62,    63,    64,   145,
      53,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -116
static const yytype_int16 yypact[] =
{
       5,    46,   -40,    12,     8,  -116,  -116,  -116,  -116,    13,
      19,    23,   -10,    40,     5,     5,     5,   -10,  -116,    28,
       5,  -116,  -116,  -116,  -116,    31,    31,  -116,    31,    65,
    -116,    45,    47,   -13,  -116,  -116,  -116,    91,    85,    95,
      70,    65,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,
     -33,  -116,    -1,  -116,    56,  -116,  -116,  -116,  -116,    83,
      83,   120,    66,  -116,  -116,    60,    83,    93,   -10,    96,
      72,   108,    62,    64,   -10,   -10,    83,    -4,    77,   107,
     119,  -116,    31,    97,     2,    92,   100,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    99,   -10,    50,
      98,    31,  -116,   -11,    89,  -116,   140,   145,  -116,  -116,
     106,  -116,   114,   116,   104,  -116,   -10,  -116,    27,     2,
       2,  -116,  -116,    50,    50,    50,    50,    50,    50,   -10,
      31,    83,  -116,   121,   146,   155,    72,    72,   -10,  -116,
    -116,  -116,  -116,  -116,  -116,   125,  -116,  -116,    50,  -116,
     115,    72,   -10,   -10,  -116,    83,   126,   -10,  -116,  -116,
     127,  -116,  -116,  -116
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,    -5,   -12,  -116,  -116,  -116,  -116,  -116,    57,  -116,
     122,  -116,  -116,  -115,  -116,   -21,   130,   -58,  -116,  -116,
     -25,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,
    -116,  -116
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      44,    54,    86,    55,    67,    49,     2,   133,     1,    46,
      47,    48,     2,    79,    38,    51,    80,     4,    39,    77,
       3,   152,   153,     4,    87,    88,    89,    90,     5,     6,
       7,     8,    89,    90,    68,    40,   157,    42,    84,    85,
      45,   134,     9,    12,    10,    99,    50,    11,     9,    12,
      10,    35,    36,    11,    41,   110,   101,   115,    12,   142,
     143,   144,   108,   109,    43,   111,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   132,    72,    87,    88,
      89,    90,    52,    56,    57,    58,   130,    65,    73,    57,
      58,    74,    75,    66,    59,    69,    70,   160,    71,    59,
      83,    56,    57,    58,   141,   147,    60,    98,    97,   100,
     148,    76,    59,   103,   102,   105,   106,   146,   107,   112,
      87,    88,    89,    90,    76,   113,   154,    91,    92,    93,
      94,    95,    96,   117,    87,    88,    89,    90,   114,   131,
     158,   159,   118,   135,   116,   162,   129,   117,    87,    88,
      89,    90,   136,   137,   140,    91,    92,    93,    94,    95,
      96,   138,    79,   149,   150,   151,   155,   156,   161,   163,
     139,    78,     0,     0,    82
};

static const yytype_int16 yycheck[] =
{
      12,    26,    60,    28,    17,    17,     7,    18,     3,    14,
      15,    16,     7,    46,    54,    20,    49,    18,     6,    40,
      15,   136,   137,    18,    28,    29,    30,    31,    23,    24,
      25,    26,    30,    31,    47,    27,   151,    18,    59,    60,
       0,    52,    43,    53,    45,    66,    18,    48,    43,    53,
      45,     5,     6,    48,    41,    76,    68,    82,    53,    32,
      33,    34,    74,    75,    41,    77,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,   101,     7,    28,    29,
      30,    31,    51,    18,    19,    20,    98,    42,    18,    19,
      20,    21,    22,    46,    29,     4,    11,   155,     3,    29,
      44,    18,    19,    20,   116,   130,    41,    47,    42,    16,
     131,    41,    29,    41,    18,     7,    54,   129,    54,    42,
      28,    29,    30,    31,    41,    18,   138,    35,    36,    37,
      38,    39,    40,    41,    28,    29,    30,    31,    19,    41,
     152,   153,    42,    54,    47,   157,    47,    41,    28,    29,
      30,    31,    12,     8,    50,    35,    36,    37,    38,    39,
      40,    47,    46,    42,    18,    10,    41,    52,    42,    42,
     113,    41,    -1,    -1,    52
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     7,    15,    18,    23,    24,    25,    26,    43,
      45,    48,    53,    56,    57,    58,    60,    61,    62,    64,
      65,    66,    67,    69,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,     5,     6,    59,    54,     6,
      27,    41,    18,    41,    57,     0,    56,    56,    56,    57,
      18,    56,    51,    75,    75,    75,    18,    19,    20,    29,
      41,    70,    71,    72,    73,    42,    46,    17,    47,     4,
      11,     3,     7,    18,    21,    22,    41,    70,    71,    46,
      49,    63,    65,    44,    70,    70,    72,    28,    29,    30,
      31,    35,    36,    37,    38,    39,    40,    42,    47,    70,
      16,    57,    18,    41,    68,     7,    54,    54,    57,    57,
      70,    57,    42,    18,    19,    75,    47,    41,    42,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    47,
      57,    41,    75,    18,    52,    54,    12,     8,    47,    63,
      50,    57,    32,    33,    34,    74,    57,    75,    70,    42,
      18,    10,    68,    68,    57,    41,    52,    68,    57,    57,
      72,    42,    57,    42
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
        case 6:

/* Line 1455 of yacc.c  */
#line 76 "syntax.y"
    {printf("syntaxe correcte"); 
    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 95 "syntax.y"
    {                      
                        // Mettre à jour le type dans la structure element
                        if (doubleDeclaration((yyvsp[(2) - (3)].str))!=0)
                        {inserer((yyvsp[(2) - (3)].str),"IDF",sauvidf, 0, "", 0);}
                        else {
                                printf("\n =====> Erreur a la ligne %d et colonne %d : idf deja declarer", nb_ligne, Col);
                        }

                        ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 111 "syntax.y"
    {   if (doubleDeclaration((yyvsp[(2) - (5)].str))!=0)
                        {inserer((yyvsp[(2) - (5)].str),"IDF",sauvidf, 0, "", 0);}
                        else {
                                printf("\n =====> Erreur a la ligne %d et colonne %d : idf deja declarer", nb_ligne, Col);
                        };}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 119 "syntax.y"
    { 
                        if (doubleDeclaration((yyvsp[(2) - (3)].str))==0){ modifier_type((yyvsp[(2) - (3)].str),sauvidf); }
                        else{{printf("\n=======> Errreur symantique a la ligne %d , DOUBLE DECLARATION  de idf %s\n",nb_ligne,Col,(yyvsp[(2) - (3)].str));}};}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 125 "syntax.y"
    {strcpy(sauvidf,"INTEGER");;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 126 "syntax.y"
    {strcpy(sauvidf,"FLOAT");;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 127 "syntax.y"
    {strcpy(sauvidf,"BOOLEAN");;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 128 "syntax.y"
    {strcpy(sauvidf,"CHAR");;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 141 "syntax.y"
    {if (doubleDeclaration((yyvsp[(1) - (4)].str))==0) {
        // verifier compatibilite de type 
        chartype=get_type((yyvsp[(1) - (4)].str));
        if (strcmp(chartype,"CHAR")!=0){
             printf("\n =====> Erreur a la ligne %d et colonne %d : idf %s  incompatibilite de type ", nb_ligne, Col,(yyvsp[(1) - (4)].str));

        }
        else{   // deja declarer je maj valchar
               set_val_string((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));
                quadruplet("=",(yyvsp[(3) - (4)].str),"",(yyvsp[(1) - (4)].str));
        }
        }
        else{
            // pas declarer je l'insere
            inserer((yyvsp[(1) - (4)].str),"IDF","CHAR", 0, (yyvsp[(3) - (4)].str), 0);
            quadruplet("=",(yyvsp[(3) - (4)].str),"",(yyvsp[(1) - (4)].str));

        };}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 162 "syntax.y"
    {if (doubleDeclaration((yyvsp[(1) - (4)].str))==0) {
        // verifier compatibilite de type 
        chartype=get_type((yyvsp[(1) - (4)].str));
        if (strcmp(chartype,"BOOL")!=0){
             printf("\n =====> Erreur a la ligne %d et colonne %d : idf %s  incompatibilite de type ", nb_ligne, Col,(yyvsp[(1) - (4)].str));

        }
        else{   // deja declarer je maj valchar
               set_val_string((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));
        }
        }
        else{
            // pas declarer je l'insere
            inserer((yyvsp[(1) - (4)].str),"IDF","BOOL", 0, (yyvsp[(3) - (4)].str), 0);

        };}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 190 "syntax.y"
    {        tmp=Depiler();
         chartype=get_type((yyvsp[(1) - (4)].str));
         if(strcmp(chartype,"CHAR")==0){
               printf("    >>>>>>> Erreur semantique ligne %d colonne %d INCOMPATIBILITE DE TYPE , idf %s est un caractere , ne peut pas recevoir une valeure numerique \n",nb_ligne,Col,(yyvsp[(1) - (4)].str));}
         else{
               if(strcmp(chartype,"BOOLEAN")==0){
               printf("    >>>>>>> Erreur semantique ligne %d colonne %d INCOMPATIBILITE DE TYPE , idf %s est un BOOLEAN , ne peut pas recevoir une valeure numerique \n",nb_ligne,Col,(yyvsp[(1) - (4)].str));}
               else {
                SetVal((yyvsp[(1) - (4)].str),tmp);
                ajout_quad_affect_val((yyvsp[(1) - (4)].str),&tmp);
                if(Is_int(&tmp)==1)
               {
                  printf("\n its an int ");
                  modifier_type((yyvsp[(1) - (4)].str),"INTEGER");
                  
               }else{
                  printf("its a float");
                  modifier_type((yyvsp[(1) - (4)].str),"FLOAT");
                  }
             }
};}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 216 "syntax.y"
    {
            op2=Depiler();op1=Depiler(); tmp = op1+op2; Empiler(tmp);

            ajout_quad_opbinaire('+',&op1,&op2);
            
         ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 223 "syntax.y"
    {
            op2=Depiler();op1=Depiler(); tmp = op1-op2; Empiler(tmp);
            ajout_quad_opbinaire('-',&op1,&op2);

          ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 229 "syntax.y"
    {
            op2=Depiler();op1=Depiler(); tmp = op1*op2; Empiler(tmp);
            ajout_quad_opbinaire('*',&op1,&op2);
          ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 234 "syntax.y"
    {        
             op2=Depiler();op1=Depiler();
             if(op2==0){
		printf ("> Erreur semantique ligne %d colonne %d DIVISION PAR 0 \n",nb_ligne,Col);
			     }else{

                tmp = op1/op2; Empiler(tmp);
                ajout_quad_opbinaire('/',&op1,&op2);

      
           };}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 246 "syntax.y"
    {
            op1=Depiler();tmp= -op1; Empiler(tmp);
            ajout_quad_opunaire(&op1);
            ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 254 "syntax.y"
    { if (doubleDeclaration((yyvsp[(1) - (1)].str))!=0){ 
            {printf("\n=======> Errreur symantique a la ligne %d colonne %d , operand %s non declare\n",nb_ligne,Col,(yyvsp[(1) - (1)].str));}}
            else{
            get_val_float((yyvsp[(1) - (1)].str),&tmp);
            Empiler(tmp);};}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 259 "syntax.y"
    {Empiler((yyvsp[(1) - (1)].entier));;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 260 "syntax.y"
    { Empiler((yyvsp[(1) - (1)].reel));;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 268 "syntax.y"
    {
		strcpy(quad1,"BNZ");
		op2=Depiler();op1=Depiler(); tmp=(op1 == op2); Empiler(tmp);
	   ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 273 "syntax.y"
    {
	   strcpy(quad1,"BZ");
		op2=Depiler();op1=Depiler(); tmp=(op1 != op2); Empiler(tmp);
	   ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 278 "syntax.y"
    {
		{
		strcpy(quad1,"BGE");
		op2=Depiler();op1=Depiler(); tmp=(op1 < op2); Empiler(tmp);
	   }
	   ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 285 "syntax.y"
    {strcpy(quad1,"BG");
		op2=Depiler();op1=Depiler(); tmp=(op1 <= op2); Empiler(tmp);
		;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 289 "syntax.y"
    {
		strcpy(quad1,"BLE");
		op2=Depiler();op1=Depiler(); tmp=(op1 > op2); Empiler(tmp);
	   ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 293 "syntax.y"
    {
		strcpy(quad1,"BL");
		op2=Depiler();op1=Depiler(); tmp=(op1 >= op2); Empiler(tmp);
		
	   ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 315 "syntax.y"
    {
		sprintf(sauvindex,"%d",qc);
		maj_quad(quadindex2,1,sauvindex);

;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 323 "syntax.y"
    {       quadindex2=qc;
	quadruplet("BR","","","");
	sprintf(sauvindex,"%d",qc);
	maj_quad(quadindex1,1,sauvindex);;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 329 "syntax.y"
    {
   tmp=Depiler();
	ajout_quad_affect_val("tmp_cond",&tmp);
	quadindex1=qc;
	quadruplet(quad1 ,"","","tmp_cond");
;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 338 "syntax.y"
    {
	sprintf(sauvindex,"%d",quadindex1);
	quadruplet("BR",sauvindex,"","");
	sprintf(sauvindex,"%d",qc);
	maj_quad(quadindex2,1,sauvindex);
;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 346 "syntax.y"
    {
	tmp=Depiler();
	ajout_quad_affect_val("tmp_cond",&tmp);
	quadindex2=qc;
	quadruplet(quad1 ,"","","tmp_cond");
;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 354 "syntax.y"
    {
	quadindex1 = qc;
	
;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 362 "syntax.y"
    {
	inc_val_idf(sauvidf);
   quadruplet("+",sauvidf,"1",sauvidf);
	sprintf(quad2,"%d",quadindex1);
	quadruplet("BR",quad2,"","");
	sprintf(quad2,"%d",qc);
	maj_quad(quadindex1,1,quad2);
;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 370 "syntax.y"
    {
	op2=Depiler();
	if(Is_int(&op2)==0){
		printf("\n=======> Errreur symantique a la ligne %d colonne %d ,  %f n'est pas INT \n",nb_ligne,Col,tmp); return 1;

	}else{

		quadindex1=qc;
		quadruplet("BG","","","tmp_cond");
	}
;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 383 "syntax.y"
    {
	    op1=Depiler();
	    if(Is_int(&op1)==0)
       {
		    printf("\n=======> Errreur symantique a la ligne %d colonne %d ,  %f n'est pas INT \n",nb_ligne,Col,tmp);return 1;

	}else{
		SetVal(sauvidf,tmp);
	}
;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 394 "syntax.y"
    {
	if(doubleDeclaration((yyvsp[(2) - (2)].str))!=0){
		inserer((yyvsp[(2) - (2)].str),"IDF","INTEGER", 0, "", 0);

		}
      else{
		chartype=get_type((yyvsp[(2) - (2)].str));
		if(strcmp(chartype,"INTEGER")==0){
			strcpy(sauvidf,(yyvsp[(2) - (2)].str));

		}else{
			printf("\n > Errreur symantique a la ligne %d colonne %d , idf %s n'est pas INT \n",nb_ligne,Col,(yyvsp[(2) - (2)].str));return 1;
	   }
      }
;}
    break;



/* Line 1455 of yacc.c  */
#line 1990 "syntax.tab.c"
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
#line 412 "syntax.y"
        
int main()
{ 
   initialisation();
   yyparse(); 
   afficher_qdr();
   //optimisation();
   afficher();  
  
   
}
int yywrap()

{}
int yyerror(char *msg)
{
  printf("\n > Erreur Syntaxique  \n au niveau la ligne %d et a la colonne %d \n", nb_ligne,Col);
   return 1;

}

