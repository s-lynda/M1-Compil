%{
#include "syntax.tab.h"
#include <String.h>
#include <stdio.h>
    /* Définition en langage C*/
// extern int Col;
extern int  nb_ligne;
extern YYSTYPE yylval;

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
/* Constante */
cst {Number1}{Number}+|0
/*Commentaire */
comment \#.*"\n"
%%
"import" {return mc_import;}
"as" {return mc_as;}
"numpy" {return mc_numpy;}
"PIL" {return mc_pil;}
"Image" {return mc_Img;}
"open" { return mc_pilf1;}
"asarray" {return mc_npf1;}
"save" {return mc_pilf3;}
"fromarray" {return mc_pilf2;}
"from" {return mc_from;}
"range" {return mc_range;}
"in" {return mc_in;}
"Int" {yylval.str=strdup(yytext); return mc_Int;}
"float" {yylval.str=strdup(yytext); return mc_float;}
"bool" {yylval.str=strdup(yytext); return mc_bool;}
"char" {yylval.str=strdup(yytext); return mc_char;}
{IDF} {if(yyleng<=8)
      {
        yylval.str=strdup(yytext); 
        return idf;
      }
      else {
        printf ("Erreur lexicale Ligne %d colonne , IDF %s trop long   \n", nb_ligne, yytext);
      }
      }
{Int} { 
        yylval.entier=atoi(yytext); 
        if(yylval.entier<32767 || yylval.entier>(-32767))
        {  return cst_int;
        }
        else {
            printf ("Erreur lexicale: depassement de la taille des entiers a la Ligne %d et a la colonne  \n", nb_ligne);
        }
       }
{float} {yylval.reel=atof(yytext); return cst_reel;}
{char} {yylval.car=strdup(yytext); return cst_char;}
{bool} {yylval.str=strdup(yytext); return cst_bool;}
{cst} {yylval.entier=atoi(yytext); return cst;}
"=" { return mc_aff;}
"+" { return plus; }
"-" { return minus;}
"*" {return mul;  }
"/" {return division;}
"and" {return mc_and;  }
"or" {return mc_OR;  }
"not" {return mc_not;  }
">"	{return sup;  }
"<"	{return inf;  }
"<=" {return infOuEg;  }
">=" {return SupOuEg;  }
"!=" {return diff;  }
"==" {return egale;  }
"\'" {return mc_app;  }
"(" {return par_O;  }
")" {return par_F;  }
"if" {return mc_if;  }
"else" {return mc_else;  }
"for" {return mc_for;  }
"," {return vrg;  }
":" {return mc_2p;  }
"while" {return mc_while;}
"[" {return croch_O;}
"]" { return croch_F;}
"\"" { return guillemets;}
"    " {return tabulation;}
{comment} {nb_ligne++;}
[ \t] 
'\n' {nb_ligne++; return sautdligne;}

. printf("Erreur lexicale ligne %d colonne sur l'entite %s\n",nb_ligne,yytext);

%%
