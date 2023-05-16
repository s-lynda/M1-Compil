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
"import" {Col=Col+yyleng;return mc_import;}
"as" {Col=Col+strlen(yytext);return mc_as;}
"numpy" {return mc_numpy;Col=Col+yyleng;}
"PIL" {return mc_pil;Col=Col+yyleng;}
"Image" {return mc_Img;Col=Col+yyleng;}
"open" {return mc_pilf1;Col=Col+yyleng;}
"asarray" {return mc_npf1;Col=Col+yyleng;}
"save" {return mc_pilf3;Col=Col+yyleng;}
"fromarray" { return mc_pilf2;Col=Col+yyleng;}
"from" {return mc_from;Col=Col+yyleng;}
"range" { return mc_range;Col=Col+yyleng;}
"in" {return mc_in;Col=Col+yyleng;}
"Int" {yylval.str=strdup(yytext); return mc_Int;Col=Col+yyleng;}
"float" {yylval.str=strdup(yytext);return mc_float;Col=Col+yyleng;}
"bool" {yylval.str=strdup(yytext); return mc_bool;Col=Col+yyleng;}
"char" {yylval.str=strdup(yytext); return mc_char;Col=Col+yyleng;}
{IDF} {
       if(yyleng<=8)
       {
        yylval.str=strdup(yytext); 
        return idf;
       }
      else {
        Col = Col +yyleng;
        printf ("Erreur lexicale Ligne %d colonne %d , IDF %s trop long   \n", nb_ligne,Col, yytext);
      }
      }
{Int} { 
        yylval.entier=atoi(yytext); 
        if((yylval.entier>(-32767)) && (yylval.entier<32767))
        {  
          return cst_int;
        }
        else {
            Col=Col+yyleng;
            printf ("Erreur lexicale: depassement de la taille des entiers a la Ligne %d et a la colonne %d  \n",nb_ligne,Col);
            
        }
       }
{float} {yylval.reel=atof(yytext); return cst_reel;Col=Col+yyleng;}
{char} {yylval.car=strdup(yytext); return cst_char;Col=Col+yyleng;}
{bool} {yylval.str=strdup(yytext); return cst_bool;Col=Col+yyleng;}
"=" { return mc_aff;Col=Col+yyleng;}
"+" { return plus; Col=Col+yyleng;}
"-" { return minus; Col=Col+yyleng;}
"*" {return mul; Col=Col+yyleng; }
"/" {return division;Col=Col+yyleng;}
"and" {return mc_and; Col=Col+yyleng; }
"or" {return mc_OR; Col=Col+yyleng; }
"not" {return mc_not; Col=Col+yyleng; }
">"	{return sup; Col=Col+yyleng; }
"<"	{return inf; Col=Col+yyleng; }
"<=" {return infOuEg; Col=Col+yyleng; }
">=" {return SupOuEg; Col=Col+yyleng; }
"!=" {return diff; Col=Col+yyleng; }
"==" {return egale; Col=Col+yyleng; }
"\'" {return mc_app;  Col=Col+yyleng;}
"(" {return par_O; Col=Col+yyleng; }
")" {return par_F; Col=Col+yyleng; }
"if" {return mc_if;Col=Col+yyleng;  }
"else" {return mc_else; Col=Col+yyleng; }
"for" {return mc_for;Col=Col+yyleng;  }
"," {return vrg; Col=Col+yyleng; }
":" {return mc_2p; Col=Col+yyleng; }
"while" {return mc_while;Col=Col+yyleng;}
"[" {return croch_O;Col=Col+yyleng;}
"]" { return croch_F;Col=Col+yyleng;}
"\"" { return guillemets;Col=Col+yyleng;}
"    " {return tabulation;Col=Col+4;}
{comment} {Col++;}
[ \t] {Col++;}
\n {return sautdligne; nb_ligne++;}
. printf("Erreur lexicale ligne %d colonne %d sur l'entite %s\n",nb_ligne,Col,yytext);

%%
