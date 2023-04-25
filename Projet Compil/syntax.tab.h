
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
     mc_import = 258,
     mc_as = 259,
     mc_numpy = 260,
     mc_cv2 = 261,
     mc_pil = 262,
     mc_Img = 263,
     mc_imgDraw = 264,
     mc_pilf1 = 265,
     mc_npf1 = 266,
     mc_pilf2 = 267,
     mc_pilf3 = 268,
     mc_npf2 = 269,
     mc_npf3 = 270,
     mc_cv2f1 = 271,
     mc_cv2f2 = 272,
     plus = 273,
     minus = 274,
     mul = 275,
     division = 276,
     mc_and = 277,
     idf = 278,
     cst = 279,
     mc_OR = 280,
     mc_not = 281,
     sup = 282,
     inf = 283,
     infOuEg = 284,
     SupOuEg = 285,
     diff = 286,
     egale = 287,
     mc_aff = 288,
     mc_app = 289,
     par_O = 290,
     par_F = 291,
     mc_if = 292,
     mc_else = 293,
     mc_for = 294,
     mc_in = 295,
     mc_range = 296,
     vrg = 297,
     mc_2p = 298,
     mc_while = 299,
     acc_O = 300,
     acc_F = 301,
     mc_int = 302,
     mc_float = 303,
     mc_bool = 304,
     mc_char = 305,
     mc_from = 306,
     cst_car = 307,
     cst_bool = 308,
     tabulation = 309
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


