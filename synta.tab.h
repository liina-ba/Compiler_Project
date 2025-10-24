
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 22 "synta.y"

    int entier;
    char* string;
    float reel;



/* Line 1676 of yacc.c  */
#line 106 "synta.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


