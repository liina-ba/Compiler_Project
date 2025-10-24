
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
#line 1 "synta.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Fonctions.h"
#include "synta.tab.h"

int yylex();
void yyerror(const char *message);

int nb_ligne = 1;  
char TypeEnregistrer[20];
char valeur[20] = "";
char idfType[20] = "";
char type[10] = "";
char constante[20] = "";
int isOperateur = 0;
int priorite = 0;


/* Line 189 of yacc.c  */
#line 95 "synta.tab.c"

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
     mc_var_global = 258,
     mc_declaration = 259,
     mc_instruction = 260,
     mc_integer = 261,
     mc_float = 262,
     mc_char = 263,
     mc_const = 264,
     mc_for = 265,
     mc_if = 266,
     mc_else = 267,
     mc_main = 268,
     mc_read = 269,
     mc_write = 270,
     cst = 271,
     cstF = 272,
     chaine_ecrire = 273,
     aco_ov = 274,
     aco_fr = 275,
     cr_ov = 276,
     cr_fr = 277,
     par_ouv = 278,
     par_fer = 279,
     vrg = 280,
     idf = 281,
     increment = 282,
     decrement = 283,
     inf = 284,
     sup = 285,
     inf_egl = 286,
     sup_egl = 287,
     diff = 288,
     egl = 289,
     afc = 290,
     addition = 291,
     soustraction = 292,
     multip = 293,
     division = 294,
     et = 295,
     ou = 296,
     non = 297,
     dp = 298,
     dpo = 299,
     erreur = 300,
     pvg = 301
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 22 "synta.y"

    int entier;
    char* string;
    float reel;



/* Line 214 of yacc.c  */
#line 185 "synta.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 197 "synta.tab.c"

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   133

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNRULES -- Number of states.  */
#define YYNSTATES  138

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

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
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    16,    19,    20,    24,    27,    28,    30,
      32,    34,    38,    42,    49,    51,    53,    55,    59,    61,
      66,    73,    76,    77,    79,    81,    83,    85,    93,   105,
     109,   113,   117,   121,   125,   129,   132,   136,   140,   145,
     159,   161,   163,   169,   177,   183,   187,   189,   193,   197,
     201,   205,   207,   209,   211,   213,   215,   217,   219,   221
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,     3,    19,    49,    20,     4,    19,    51,
      20,     5,    19,    59,    20,    -1,    50,    49,    -1,    -1,
      56,    57,    46,    -1,    52,    51,    -1,    -1,    53,    -1,
      54,    -1,    55,    -1,    56,    57,    46,    -1,    56,    58,
      46,    -1,     9,    56,    26,    35,    72,    46,    -1,     6,
      -1,     7,    -1,     8,    -1,    26,    25,    57,    -1,    26,
      -1,    26,    21,     6,    22,    -1,    26,    21,     6,    22,
      25,    58,    -1,    60,    59,    -1,    -1,    63,    -1,    64,
      -1,    65,    -1,    61,    -1,    11,    23,    62,    24,    19,
      59,    20,    -1,    11,    23,    62,    24,    19,    59,    20,
      12,    19,    59,    20,    -1,    26,    29,    26,    -1,    26,
      30,    26,    -1,    26,    31,    26,    -1,    26,    32,    26,
      -1,    26,    34,    26,    -1,    26,    33,    26,    -1,    42,
      62,    -1,    62,    40,    62,    -1,    62,    41,    62,    -1,
      26,    35,    69,    46,    -1,    10,    23,    26,    35,    70,
      43,    70,    43,    70,    24,    19,    59,    20,    -1,    66,
      -1,    67,    -1,    14,    23,    26,    24,    46,    -1,    15,
      23,    18,    25,    68,    24,    46,    -1,    15,    23,    18,
      24,    46,    -1,    26,    25,    68,    -1,    26,    -1,    69,
      36,    69,    -1,    69,    37,    69,    -1,    69,    38,    69,
      -1,    69,    39,    69,    -1,    71,    -1,    16,    -1,    17,
      -1,    26,    -1,    26,    -1,    72,    -1,    16,    -1,    17,
      -1,    18,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    58,    58,    68,    71,    75,    82,    85,    89,    90,
      91,    95,   102,   109,   130,   131,   132,   136,   145,   157,
     173,   192,   200,   204,   205,   206,   207,   211,   232,   257,
     278,   291,   304,   317,   330,   343,   355,   369,   387,   418,
     474,   475,   479,   485,   488,   494,   498,   504,   516,   528,
     540,   557,   563,   566,   569,   579,   582,   589,   598,   607
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "mc_var_global", "mc_declaration",
  "mc_instruction", "mc_integer", "mc_float", "mc_char", "mc_const",
  "mc_for", "mc_if", "mc_else", "mc_main", "mc_read", "mc_write", "cst",
  "cstF", "chaine_ecrire", "aco_ov", "aco_fr", "cr_ov", "cr_fr", "par_ouv",
  "par_fer", "vrg", "idf", "increment", "decrement", "inf", "sup",
  "inf_egl", "sup_egl", "diff", "egl", "afc", "addition", "soustraction",
  "multip", "division", "et", "ou", "non", "dp", "dpo", "erreur", "pvg",
  "$accept", "PROGRAM", "GLOBAL_DECLS", "GLOBAL_DEC", "DECLS", "DEC",
  "DEC_VAR", "DEC_TAB", "DEC_CONST", "TYPE", "LISTE_IDF", "LISTE_IDF_TAB",
  "INSTRUCTIONS", "INSTRUCTION", "CONDITIONAL", "CONDITION", "ASSIGNMENT",
  "LOOP", "IO", "inst_lire", "inst_ecrire", "LISTE_IDF_ECRITURE", "EXP",
  "EXPP", "IDF_CST", "CONSTANTE", 0
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
     295,   296,   297,   298,   299,   300,   301
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    51,    51,    52,    52,
      52,    53,    54,    55,    56,    56,    56,    57,    57,    58,
      58,    59,    59,    60,    60,    60,    60,    61,    61,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    63,    64,
      65,    65,    66,    67,    67,    68,    68,    69,    69,    69,
      69,    69,    70,    70,    70,    71,    71,    72,    72,    72
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    12,     2,     0,     3,     2,     0,     1,     1,
       1,     3,     3,     6,     1,     1,     1,     3,     1,     4,
       6,     2,     0,     1,     1,     1,     1,     7,    11,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     4,    13,
       1,     1,     5,     7,     5,     3,     1,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     4,     1,    14,    15,    16,     0,     4,
       0,     0,     3,    18,     0,     0,     0,     5,     7,    17,
       0,     0,     7,     8,     9,    10,     0,     0,     0,     6,
      18,     0,     0,     0,     0,     0,    11,    12,     0,    22,
       0,    57,    58,    59,     0,     0,     0,     0,     0,     0,
       0,    22,    26,    23,    24,    25,    40,    41,    19,    13,
       0,     0,     0,     0,     0,     2,    21,     0,     0,     0,
       0,     0,     0,     0,    55,     0,    51,    56,     0,    20,
       0,     0,     0,     0,     0,     0,     0,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,    52,
      53,    54,     0,    29,    30,    31,    32,    34,    33,    22,
      36,    37,    42,    44,    46,     0,    47,    48,    49,    50,
       0,     0,     0,     0,     0,    27,    45,    43,     0,     0,
       0,    22,     0,     0,    22,    28,     0,    39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     8,     9,    21,    22,    23,    24,    25,    10,
      14,    32,    50,    51,    52,    71,    53,    54,    55,    56,
      57,   115,    75,   102,    76,    77
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -117
static const yytype_int8 yypact[] =
{
       0,    -2,    36,    46,  -117,  -117,  -117,  -117,    43,    46,
      40,    63,  -117,    44,    22,    51,    40,  -117,    25,  -117,
      46,    52,    25,  -117,  -117,  -117,    45,    47,    69,  -117,
     -16,    29,    30,    42,    59,    73,  -117,  -117,    39,    -4,
      60,  -117,  -117,  -117,    38,    58,    62,    64,    65,    54,
      66,    -4,  -117,  -117,  -117,  -117,  -117,  -117,    67,  -117,
      68,   -18,    70,    72,     9,  -117,  -117,    71,    56,    13,
     -18,   -22,    74,    35,  -117,   -23,  -117,  -117,    78,  -117,
      12,    75,    76,    77,    79,    80,    81,    21,    85,   -18,
     -18,    49,    82,    83,     9,     9,     9,     9,  -117,  -117,
    -117,  -117,    50,  -117,  -117,  -117,  -117,  -117,  -117,    -4,
    -117,    84,  -117,  -117,    86,    88,    26,    26,  -117,  -117,
      12,    90,    83,    87,    57,    96,  -117,  -117,    12,    94,
      91,    -4,    95,    97,    -4,  -117,    98,  -117
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -117,  -117,   107,  -117,    99,  -117,  -117,  -117,  -117,    19,
      14,    53,   -51,  -117,  -117,   -69,  -117,  -117,  -117,  -117,
    -117,    -3,   -46,  -116,  -117,    89
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      66,    87,    88,     1,   124,    35,    45,    46,    69,    16,
      47,    48,   130,    94,    95,    96,    97,     3,    89,    90,
     110,   111,    49,    98,    70,    41,    42,    43,    99,   100,
      19,     5,     6,     7,    20,    74,     4,    26,   101,    27,
      31,    26,    81,    82,    83,    84,    85,    86,   116,   117,
     118,   119,     5,     6,     7,    41,    42,    43,   121,    92,
      93,    89,    90,    11,    96,    97,    13,    15,    17,    16,
      18,    30,    28,    33,    34,    36,    37,    38,    39,    40,
     133,    60,    58,   136,    59,    61,    65,    62,    63,    64,
      73,    80,    67,   120,    68,   112,    72,    78,    91,    35,
     128,   103,   104,   105,   109,   106,   107,   108,   129,   114,
     125,   122,   123,   131,   134,   132,    12,   135,   137,   126,
      79,    29,     0,     0,    89,     0,     0,    44,   113,     0,
       0,     0,     0,   127
};

static const yytype_int16 yycheck[] =
{
      51,    70,    24,     3,   120,    21,    10,    11,    26,    25,
      14,    15,   128,    36,    37,    38,    39,    19,    40,    41,
      89,    90,    26,    46,    42,    16,    17,    18,    16,    17,
      16,     6,     7,     8,     9,    26,     0,    18,    26,    20,
      26,    22,    29,    30,    31,    32,    33,    34,    94,    95,
      96,    97,     6,     7,     8,    16,    17,    18,   109,    24,
      25,    40,    41,    20,    38,    39,    26,     4,    46,    25,
      19,    26,    20,    26,     5,    46,    46,    35,    19,     6,
     131,    23,    22,   134,    46,    23,    20,    23,    23,    35,
      18,    35,    25,    43,    26,    46,    26,    26,    24,    21,
      43,    26,    26,    26,    19,    26,    26,    26,    12,    26,
      20,    25,    24,    19,    19,    24,     9,    20,    20,   122,
      67,    22,    -1,    -1,    40,    -1,    -1,    38,    46,    -1,
      -1,    -1,    -1,    46
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    48,    19,     0,     6,     7,     8,    49,    50,
      56,    20,    49,    26,    57,     4,    25,    46,    19,    57,
       9,    51,    52,    53,    54,    55,    56,    56,    20,    51,
      26,    57,    58,    26,     5,    21,    46,    46,    35,    19,
       6,    16,    17,    18,    72,    10,    11,    14,    15,    26,
      59,    60,    61,    63,    64,    65,    66,    67,    22,    46,
      23,    23,    23,    23,    35,    20,    59,    25,    26,    26,
      42,    62,    26,    18,    26,    69,    71,    72,    26,    58,
      35,    29,    30,    31,    32,    33,    34,    62,    24,    40,
      41,    24,    24,    25,    36,    37,    38,    39,    46,    16,
      17,    26,    70,    26,    26,    26,    26,    26,    26,    19,
      62,    62,    46,    46,    26,    68,    69,    69,    69,    69,
      43,    59,    25,    24,    70,    20,    68,    46,    43,    12,
      70,    19,    24,    59,    19,    20,    59,    20
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
#line 61 "synta.y"
    {
        printf("Programme syntaxiquement correct.\n");
        YYACCEPT;
    ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 69 "synta.y"
    { (yyval.string) = strdup(""); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 71 "synta.y"
    { (yyval.string) = strdup(""); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 76 "synta.y"
    {
        (yyval.string) = strdup(""); 
    ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 83 "synta.y"
    { (yyval.string) = strdup(""); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 85 "synta.y"
    { (yyval.string) = strdup(""); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 89 "synta.y"
    { (yyval.string) = strdup(""); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 90 "synta.y"
    { (yyval.string) = strdup(""); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 91 "synta.y"
    { (yyval.string) = strdup(""); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 96 "synta.y"
    {
        (yyval.string) = strdup(""); 
    ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 103 "synta.y"
    {
        (yyval.string) = strdup(""); 
    ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 110 "synta.y"
    {
        if (DoubleDeclaration((yyvsp[(3) - (6)].string)) == 0) {
            insererType((yyvsp[(3) - (6)].string), TypeEnregistrer);  
            isConstante((yyvsp[(3) - (6)].string));                  
            
            if (verifierType(TypeEnregistrer, type) == 0) {  
                insererValeur((yyvsp[(3) - (6)].string), valeur);  
                CompatibiliteType((yyvsp[(3) - (6)].string), type, valeur, nb_ligne);  
                strcpy(valeur, " ");
            } else {
                printf("Erreur semantique: type incoherent pour la constante %s a la ligne %d.\n", (yyvsp[(3) - (6)].string), nb_ligne);
            }
        } else {
            printf("Erreur semantique: double declaration de %s a la ligne %d.\n", (yyvsp[(3) - (6)].string), nb_ligne);
        }
        (yyval.string) = strdup(""); 
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 130 "synta.y"
    { strcpy(TypeEnregistrer, (yyvsp[(1) - (1)].string)); (yyval.string) = strdup((yyvsp[(1) - (1)].string)); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 131 "synta.y"
    { strcpy(TypeEnregistrer, (yyvsp[(1) - (1)].string)); (yyval.string) = strdup((yyvsp[(1) - (1)].string)); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 132 "synta.y"
    { strcpy(TypeEnregistrer, (yyvsp[(1) - (1)].string)); (yyval.string) = strdup((yyvsp[(1) - (1)].string)); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 137 "synta.y"
    {
        if (DoubleDeclaration((yyvsp[(1) - (3)].string)) == 0) {
            insererType((yyvsp[(1) - (3)].string), TypeEnregistrer);
        } else {
            printf("Erreur semantique: double declaration de %s a la ligne %d.\n", (yyvsp[(1) - (3)].string), nb_ligne);
        }
        (yyval.string) = strdup((yyvsp[(1) - (3)].string)); 
    ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 146 "synta.y"
    {
        if (DoubleDeclaration((yyvsp[(1) - (1)].string)) == 0) {
            insererType((yyvsp[(1) - (1)].string), TypeEnregistrer);
        } else {
            printf("Erreur semantique: double declaration de %s a la ligne %d.\n", (yyvsp[(1) - (1)].string), nb_ligne);
        }
        (yyval.string) = strdup((yyvsp[(1) - (1)].string)); 
    ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 158 "synta.y"
    { 
        if (DoubleDeclaration((yyvsp[(1) - (4)].string)) == 0) {
            int size = atoi((yyvsp[(3) - (4)].string));
            if (size <= 0) {
                printf("Erreur semantique: la taille du tableau %s doit être un entier positif à la ligne %d.\n", (yyvsp[(1) - (4)].string), nb_ligne);
            } else {
                char sizeStr[10];                // Déclare une chaîne pour stocker la taille
                sprintf(sizeStr, "%d", size);   // Convertit l'entier size en chaîne
                inserer((yyvsp[(1) - (4)].string), sizeStr);  // Insérer le tableau avec sa taille
            }
        } else {
            printf("Erreur semantique: double déclaration de %s à la ligne %d.\n", (yyvsp[(1) - (4)].string), nb_ligne);
        }
        (yyval.string) = strdup((yyvsp[(1) - (4)].string)); 
    ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 174 "synta.y"
    { 
        if (DoubleDeclaration((yyvsp[(1) - (6)].string)) == 0) {
            int size = atoi((yyvsp[(3) - (6)].string));
            if (size <= 0) {
                printf("Erreur semantique: la taille du tableau %s doit être un entier positif à la ligne %d.\n", (yyvsp[(1) - (6)].string), nb_ligne);
            } else {
                char sizeStr[10];                // Déclare une chaîne pour stocker la taille
                sprintf(sizeStr, "%d", size);   // Convertit l'entier size en chaîne
                inserer((yyvsp[(1) - (6)].string), sizeStr);  // Insérer le tableau avec sa taille
            }
        } else {
            printf("Erreur semantique: double déclaration de %s à la ligne %d.\n", (yyvsp[(1) - (6)].string), nb_ligne);
        }
        (yyval.string) = strdup((yyvsp[(1) - (6)].string));
    ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 193 "synta.y"
    {
        // Concaténation des instructions
        char temp[1000];
        sprintf(temp, "%s;%s", (yyvsp[(1) - (2)].string), (yyvsp[(2) - (2)].string));  // Séparer les instructions par un délimiteur ";"
        (yyval.string) = strdup(temp);
    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 200 "synta.y"
    { (yyval.string) = strdup(""); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 204 "synta.y"
    { (yyval.string) = strdup(""); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 205 "synta.y"
    { (yyval.string) = strdup(""); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 206 "synta.y"
    { (yyval.string) = strdup(""); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 207 "synta.y"
    { (yyval.string) = strdup(""); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 211 "synta.y"
    {
    char labelFalse[20], labelEnd[20];
    genererLabel(labelFalse);
    genererLabel(labelEnd);

    // Quadruplet pour tester la condition
    ajouterQuad("IF", (yyvsp[(3) - (7)].string), labelFalse, "");

    // Instructions du bloc IF
  
    // Saut à la fin du bloc
    ajouterQuad("GOTO", "", "", labelEnd);

    // Étiquette pour le bloc ELSE
    ajouterEtiquette(labelFalse);

    // Étiquette de fin
    ajouterEtiquette(labelEnd);
;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 232 "synta.y"
    {
    char labelFalse[20], labelEnd[20];
    genererLabel(labelFalse);
    genererLabel(labelEnd);

    // Quadruplet pour tester la condition
    ajouterQuad("IF", (yyvsp[(3) - (11)].string), labelFalse, "");

  
    // Saut à la fin
    ajouterQuad("GOTO", "", "", labelEnd);

    // Étiquette pour ELSE
    ajouterEtiquette(labelFalse);

     
    // Étiquette de fin
    ajouterEtiquette(labelEnd);
;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 257 "synta.y"
    {
    const char* leftValue = rechercheValeur((yyvsp[(1) - (3)].string));
    const char* rightValue = rechercheValeur((yyvsp[(3) - (3)].string));

    if (leftValue == NULL || rightValue == NULL) {
        printf("Erreur : Variable non déclarée.\n");
        (yyval.string) = 0; // Faux
    } else {
        char temp[20];
        genererTemp(temp);

        // Quadruplet pour la condition
        ajouterQuad("<", (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string), temp);

        // Résultat de la condition
        (yyval.string) = strdup(temp);
        printf("Condition vérifiée : %s < %s.\n", (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string));
    }
;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 278 "synta.y"
    { 
        const char* leftValue = rechercheValeur((yyvsp[(1) - (3)].string));
        const char* rightValue = rechercheValeur((yyvsp[(3) - (3)].string));

        if (leftValue == NULL || rightValue == NULL) {
            printf("Erreur semantique: Une des variables %s ou %s n'est pas declaree à la ligne %d.\n", (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string), nb_ligne);
        } else if (atof(leftValue) > atof(rightValue)) {
            printf("Condition verifiee: %s > %s.\n", (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string));
        } else {
            printf("Condition non verifiee: %s <= %s.\n", (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string));
        }
        (yyval.string) = strdup(""); 
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 291 "synta.y"
    { 
        const char* leftValue = rechercheValeur((yyvsp[(1) - (3)].string));
        const char* rightValue = rechercheValeur((yyvsp[(3) - (3)].string));

        if (leftValue == NULL || rightValue == NULL) {
            printf("Erreur semantique: Une des variables %s ou %s n'est pas declaree à la ligne %d.\n", (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string), nb_ligne);
        } else if (atof(leftValue) <= atof(rightValue)) {
            printf("Condition verifiee: %s <= %s.\n", (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string));
        } else {
            printf("Condition non verifiee: %s > %s.\n", (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string));
        }
        (yyval.string) = strdup(""); 
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 304 "synta.y"
    { 
        const char* leftValue = rechercheValeur((yyvsp[(1) - (3)].string));
        const char* rightValue = rechercheValeur((yyvsp[(3) - (3)].string));

        if (leftValue == NULL || rightValue == NULL) {
            printf("Erreur semantique: Une des variables %s ou %s n'est pas declaree à la ligne %d.\n", (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string), nb_ligne);
        } else if (atof(leftValue) >= atof(rightValue)) {
            printf("Condition verifiee: %s >= %s.\n", (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string));
        } else {
            printf("Condition non verifiee: %s < %s.\n", (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string));
        }
        (yyval.string) = strdup(""); 
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 317 "synta.y"
    { 
        const char* leftValue = rechercheValeur((yyvsp[(1) - (3)].string));
        const char* rightValue = rechercheValeur((yyvsp[(3) - (3)].string));

        if (leftValue == NULL || rightValue == NULL) {
            printf("Erreur semantique: Une des variables %s ou %s n'est pas declaree à la ligne %d.\n", (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string), nb_ligne);
        } else if (strcmp(leftValue, rightValue) == 0) {
            printf("Condition verifiee: %s == %s.\n", (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string));
        } else {
            printf("Condition non verifiee: %s != %s.\n", (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string));
        }
        (yyval.string) = strdup(""); 
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 330 "synta.y"
    { 
        const char* leftValue = rechercheValeur((yyvsp[(1) - (3)].string));
        const char* rightValue = rechercheValeur((yyvsp[(3) - (3)].string));

        if (leftValue == NULL || rightValue == NULL) {
            printf("Erreur semantique: Une des variables %s ou %s n'est pas declaree à la ligne %d.\n", (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string), nb_ligne);
        } else if (strcmp(leftValue, rightValue) != 0) {
            printf("Condition verifiee: %s != %s.\n", (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string));
        } else {
            printf("Condition non verifiee: %s == %s.\n", (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string));
        }
        (yyval.string) = strdup(""); 
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 343 "synta.y"
    { 
        const char* conditionValue = evaluateCondition((yyvsp[(2) - (2)].string));

        if (conditionValue == NULL) {
            printf("Erreur semantique: Condition non valide à la ligne %d.\n", nb_ligne);
        } else if (!atoi(conditionValue)) {
            printf("Condition verifiee: NON %s.\n", (yyvsp[(2) - (2)].string));
        } else {
            printf("Condition non verifiee: %s.\n", (yyvsp[(2) - (2)].string));
        }
        (yyval.string) = strdup(""); 
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 355 "synta.y"
    {
    char temp1[20], temp2[20], tempResult[20];
    genererTemp(temp1);
    genererTemp(temp2);
    genererTemp(tempResult);

    // Quadruplets pour les deux conditions
    ajouterQuad("AND", (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string), tempResult);

    // Résultat global
    (yyval.string) = strdup(tempResult);
    printf("Condition combinée (ET) : %s ET %s.\n", (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string));
;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 369 "synta.y"
    { 
        const char* leftCondition = evaluateCondition((yyvsp[(1) - (3)].string));
        const char* rightCondition = evaluateCondition((yyvsp[(3) - (3)].string));

        if (leftCondition == NULL || rightCondition == NULL) {
            printf("Erreur semantique: Conditions non valides à la ligne %d.\n", nb_ligne);
        } else if (atoi(leftCondition) || atoi(rightCondition)) {
            printf("Condition verifiee: %s OU %s.\n", (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string));
        } else {
            printf("Condition non verifiee: %s ET %s.\n", (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string));
        }
        (yyval.string) = strdup(""); 
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 388 "synta.y"
    {
        const char* varType = rechercheEssai((yyvsp[(1) - (4)].string))->TypeEntite;

        if (varType == NULL) {
            printf("Erreur semantique: La variable %s n'est pas declaree a la ligne %d.\n", (yyvsp[(1) - (4)].string), nb_ligne);
        } else if (strcmp(varType, "FLOAT") == 0) {
            // Directly assign the float value
            insererValeur((yyvsp[(1) - (4)].string), (yyvsp[(3) - (4)].string));
        } else if (strcmp(varType, "INTEGER") == 0) {
            // Format and insert as integer
            int intValue = atoi((yyvsp[(3) - (4)].string));
            char buffer[20];
            sprintf(buffer, "%d", intValue);
            insererValeur((yyvsp[(1) - (4)].string), buffer);
        } else if (strcmp(varType, "CHAR") == 0) {
            // Direct assignment for CHAR type
            insererValeur((yyvsp[(1) - (4)].string), (yyvsp[(3) - (4)].string));
        } else {
            printf("Erreur semantique: Type inconnu pour %s.\n", (yyvsp[(1) - (4)].string));
        }

        // Ajout du quadruplet pour l'affectation
        // Le quadruplet aura la forme (operande1 = operande2) où operande1 est la variable et operande2 est la valeur assignée
        ajouterQuad("=", (yyvsp[(3) - (4)].string), "", (yyvsp[(1) - (4)].string));

        (yyval.string) = strdup((yyvsp[(3) - (4)].string)); 
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 419 "synta.y"
    {
        char loopVar[20];
        strcpy(loopVar, (yyvsp[(3) - (13)].string));  
       
        int start = atoi((yyvsp[(5) - (13)].string));   // Starting value
        int step = atoi((yyvsp[(7) - (13)].string));    // Step value
        int limit = atoi((yyvsp[(9) - (13)].string));   // Limit value
        
        char buffer[20];  // Buffer pour la conversion des entiers
        int lastValue = start;

        sprintf(buffer, "%d", start);  
        inserer(loopVar, buffer);  // Insérer la variable de boucle dans la table des symboles
        insererValeur(loopVar, buffer);  // Mettre à jour la valeur de la variable de boucle dans la table des symboles

        char loopLabel[20];
        genererLabel(loopLabel);
        ajouterQuad("LABEL", loopLabel, "", "");

        // Générer une étiquette pour la fin de la boucle
        char endLabel[20];
        genererLabel(endLabel);  // Générez une étiquette unique pour la fin

        // Exécuter la boucle FOR
        for (int i = start; i <= limit; i += step) {
            lastValue = i;   
            sprintf(buffer, "%d", i);
            insererValeur(loopVar, buffer);  // Mettre à jour la valeur de loopVar dans la table des symboles

            // Vérification conditionnelle et instruction de saut (fin de boucle)
            ajouterQuad("IF", loopVar, ">", endLabel);  // Si loopVar > limit, sauter à endLabel

            int currentSum = atoi(rechercheValeur(loopVar));
            currentSum += i;
            sprintf(buffer, "%d", currentSum);
            ajouterQuad("=", buffer, "", loopVar);  // Mettre à jour "Sum"

            // Ajouter un quadruplet pour le saut à l'étiquette de fin de boucle
            ajouterQuad("GOTO", "", "", loopLabel);  // Retourner au début de la boucle
        }

        // Ajouter un quadruplet pour l'étiquette de fin de boucle
        ajouterQuad("LABEL", endLabel, "", "");  // Fin de la boucle

        // Insérer la valeur finale de loopVar dans la table des symboles
        sprintf(buffer, "%d", limit);  // La valeur finale de loopVar est égale à limit
        insererValeur(loopVar, buffer);  // Insérer la valeur finale de loopVar dans la table des symboles

        (yyval.string) = strdup("");  // Retourner une valeur vide pour la consistance du parser
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 479 "synta.y"
    {
        if(traitementLire((yyvsp[(5) - (5)].string))==-1){
            printf("erreur semantique dans la ligne %d la variable %s est mal lu\n",nb_ligne,(yyvsp[(3) - (5)].string));}
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 485 "synta.y"
    { 
        if(traitementEcrire((yyvsp[(3) - (7)].string))==-1){
            printf("erreur semantique dans la ligne %d la variable est mal ecrite\n",nb_ligne);};}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 488 "synta.y"
    { 
        if(traitementEcrire((yyvsp[(3) - (5)].string))==-1){
            printf("erreur semantique dans la ligne %d la variable est mal ecrite\n",nb_ligne);};}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 494 "synta.y"
    {
        if(typeEnregistrer((yyvsp[(1) - (3)].string))==-1){
            printf("erreur semantique dans la ligne %d la variable %s est non declare\n",nb_ligne,(yyvsp[(1) - (3)].string));}
        else{ajouterElement((yyvsp[(1) - (3)].string));};}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 498 "synta.y"
    {
        if(typeEnregistrer((yyvsp[(1) - (1)].string))==-1){
            printf("erreur semantique dans la ligne %d la variable %s est non declare\n",nb_ligne,(yyvsp[(1) - (1)].string));}
        else{ajouterElement((yyvsp[(1) - (1)].string));};}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 504 "synta.y"
    { 
        float left = atof((yyvsp[(1) - (3)].string)); 
        float right = atof((yyvsp[(3) - (3)].string)); 
        float result = left + right;

        // Ajout du quadruplet pour l'addition
        char resultStr[20];
        sprintf(resultStr, "%.2f", result);  // Formater le résultat comme float
        ajouterQuad("+", (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string), resultStr);

        (yyval.string) = strdup(resultStr);
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 516 "synta.y"
    { 
        float left = atof((yyvsp[(1) - (3)].string)); 
        float right = atof((yyvsp[(3) - (3)].string)); 
        float result = left - right;

        // Ajout du quadruplet pour la soustraction
        char resultStr[20];
        sprintf(resultStr, "%.2f", result);
        ajouterQuad("-", (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string), resultStr);

        (yyval.string) = strdup(resultStr);
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 528 "synta.y"
    { 
        float left = atof((yyvsp[(1) - (3)].string)); 
        float right = atof((yyvsp[(3) - (3)].string)); 
        float result = left * right;

        // Ajout du quadruplet pour la multiplication
        char resultStr[20];
        sprintf(resultStr, "%.2f", result);
        ajouterQuad("*", (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string), resultStr);

        (yyval.string) = strdup(resultStr);
    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 540 "synta.y"
    { 
        float left = atof((yyvsp[(1) - (3)].string)); 
        float right = atof((yyvsp[(3) - (3)].string)); 
        if (right == 0) {
            yyerror("Division by zero!");
            (yyval.string) = strdup("0.0");
        } else {
            float result = left / right; 
            char resultStr[20];
            sprintf(resultStr, "%.2f", result);

            // Ajout du quadruplet pour la division
            ajouterQuad("/", (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string), resultStr);

            (yyval.string) = strdup(resultStr);
        }
    ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 557 "synta.y"
    { 
        (yyval.string) = strdup((yyvsp[(1) - (1)].string)); 
    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 563 "synta.y"
    { 
        (yyval.string) = strdup((yyvsp[(1) - (1)].string)); 
    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 566 "synta.y"
    { 
        (yyval.string) = strdup((yyvsp[(1) - (1)].string)); 
    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 569 "synta.y"
    { 
        (yyval.string) = strdup(rechercheValeur((yyvsp[(1) - (1)].string))); 
    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 579 "synta.y"
    { 
        (yyval.string) = strdup(rechercheValeur((yyvsp[(1) - (1)].string))); 
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 582 "synta.y"
    { 
        (yyval.string) = strdup((yyvsp[(1) - (1)].string)); 
    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 589 "synta.y"
    {
        if (isOperateur == 0) {
            strcpy(valeur, (yyvsp[(1) - (1)].string));
            strcpy(type, "INTEGER"); // Assign type as INTEGER
            ajouterElementAffec((yyvsp[(1) - (1)].string));
        } else {
            ajouterElementAffec((yyvsp[(1) - (1)].string));
        }
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 598 "synta.y"
    {
        if (isOperateur == 0) {
            strcpy(valeur, (yyvsp[(1) - (1)].string));
            strcpy(type, "FLOAT"); // Assign type as FLOAT
            ajouterElementAffec((yyvsp[(1) - (1)].string));
        } else {
            ajouterElementAffec((yyvsp[(1) - (1)].string));
        }
    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 607 "synta.y"
    {
        if (isOperateur == 0) {
            strcpy(valeur, (yyvsp[(1) - (1)].string));
            strcpy(type, "CHAR"); // Assign type as CHAR
            ajouterElementAffec((yyvsp[(1) - (1)].string));
        } else {
            ajouterElementAffec((yyvsp[(1) - (1)].string));
        }
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 2290 "synta.tab.c"
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
#line 618 "synta.y"


int main() {
    yyparse();
    afficher();
    afficherQuads();
    return 0;
}

void yyerror(const char *message) {
    printf("Erreur syntaxique a la ligne %d: %s\n", nb_ligne, message);
}
