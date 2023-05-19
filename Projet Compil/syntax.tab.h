/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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

#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
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
     sautdligne = 308
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 14 "syntax.y"

        int entier;
        char* str;
        float reel;


/* Line 2058 of yacc.c  */
#line 117 "syntax.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */
