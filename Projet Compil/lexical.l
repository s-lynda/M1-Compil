%{
#include "syntax.tab.h"
#include <String.h>
#include <stdio.h>
    /* Définition en langage C*/
// extern int Col;
int nb_ligne=1;
extern YYSTYPE yylval;
extern int  Col;
%}
/* Définition des regex*/
letter_min [a-z]
letter_Maj [A-Z]
Number [0-9]
Number1 [1-9]
/* Les types de variables */
/* Int & float ( les valeurs négatives sont entre parenthèse)*/
Int  {Number1}{Number}*|0|"\("[+-]{Number1}+"\)"
float  (({Number1}{Number}*|0)"."{Number}+)|("\("[+-]({Number1}{Number}*|0)"."{Number}+"\)")
char [.|\n]
bool true|false
/* Identificateur */
IDF {letter_Maj}({letter_min}|{Number})*
/*Commentaire */
comment \#.*"\n"
%%
import {Col=Col+strlen(yytext);return mc_import;}
as {Col=Col+strlen(yytext); return mc_as;}
numpy {Col=Col+strlen(yytext); return mc_numpy;}
PIL {Col=Col+strlen(yytext);return mc_pil;}
Image {Col=Col+strlen(yytext);return mc_Img;}
open {Col=Col+strlen(yytext);return mc_pilf1;}
asarray {Col=Col+strlen(yytext); return mc_npf1;}
save {Col=Col+strlen(yytext);return mc_pilf3;}
fromarray {Col=Col+strlen(yytext); return mc_pilf2;}
from {Col=Col+strlen(yytext);return mc_from;}
range {Col=Col+strlen(yytext); return mc_range;}
in {Col=Col+strlen(yytext);return mc_in;}
Int {yylval.str=strdup(yytext); Col=Col+strlen(yytext);return mc_Int; }
{IDF} {
        Col=Col+strlen(yytext);
       if(yyleng<=8)
       {
        yylval.str=strdup(yytext); 
        return idf;
       }
      else {
        printf ("Erreur lexicale Ligne %d colonne %d , IDF %s trop long   \n", nb_ligne,Col, yytext);
      }
      }
{Int} { 
        Col=Col+strlen(yytext);
        yylval.entier=atoi(yytext); 
        if((yylval.entier>(-32767)) && (yylval.entier<32767))
        {  
          return cst_int;
        }
        else {
            printf ("Erreur lexicale: depassement de la taille des entiers a la Ligne %d et a la colonne %d  \n",nb_ligne,Col);
            
        }
       }
{float} {yylval.reel=atof(yytext);Col=Col+strlen(yytext); return cst_reel;}
{char} {yylval.car=strdup(yytext);Col=Col+strlen(yytext); return cst_char;}
{bool} {yylval.str=strdup(yytext); Col=Col+strlen(yytext); return cst_bool;}
"float" {yylval.str=strdup(yytext);Col=Col+strlen(yytext);return mc_float;}
"bool" {yylval.str=strdup(yytext);Col=Col+strlen(yytext); return mc_bool;}
"char" {yylval.str=strdup(yytext); Col=Col+strlen(yytext);return mc_char;}
"=" { Col=Col+strlen(yytext); return mc_aff;}
"+" { Col=Col+strlen(yytext); return plus; }
"-" { Col=Col+strlen(yytext);return minus; }
"*" {Col=Col+strlen(yytext); return mul;  }
"/" {Col=Col+strlen(yytext);return division;}
"and" {Col=Col+strlen(yytext);return mc_and;  }
"or" {Col=Col+strlen(yytext);return mc_OR;  }
"not" {Col=Col+strlen(yytext); return mc_not;  }
">"	{Col=Col+strlen(yytext); return sup;  }
"<"	{Col=Col+strlen(yytext); return inf;  }
"<=" {Col=Col+strlen(yytext);return infOuEg;  }
">=" {Col=Col+strlen(yytext); return SupOuEg;  }
"!=" {Col=Col+strlen(yytext);return diff;  }
"==" {Col=Col+strlen(yytext); return egale;  }
"\'" {Col=Col+strlen(yytext);return mc_app;  }
"(" {Col=Col+strlen(yytext); return par_O;  }
")" {Col=Col+strlen(yytext); return par_F;  }
"if" {Col=Col+strlen(yytext); return mc_if;  }
"else" {Col=Col+strlen(yytext); return mc_else;  }
"for" {Col=Col+strlen(yytext); return mc_for;  }
"," {Col=Col+strlen(yytext);return vrg;  }
":" {Col=Col+strlen(yytext); return mc_2p;  }
"while" {Col=Col+strlen(yytext); return mc_while;}
"[" {Col=Col+strlen(yytext); return croch_O;}
"]" { Col=Col+strlen(yytext); return croch_F;}
"\"" { Col=Col+strlen(yytext); return guillemets;}
"    " {Col=Col+strlen(yytext); return tabulation;Col=Col+4;}
{comment} {nb_ligne++;}
[ \t] {Col++;}
\n { nb_ligne++; Col = 1; return sautdligne;}
. printf("Erreur lexicale ligne %d colonne %d sur l'entite %s\n",nb_ligne,Col,yytext);

%%
