%{
#include <String.h>
#include <stdio.h>
#include "syntax.tab.h"
    /* Définition en langage C*/
// extern int Col;
int nb_ligne=1;
extern YYSTYPE yylval;
extern int  Col;
%}
/* Définition des regex*/
letter [a-zA-Z]
letter_Maj [A-Z]
Number [0-9]
Number1 [1-9]
/* Les types de variables */
/* Int & float ( les valeurs négatives sont entre parenthèse)*/
SignedInt  "\("[+-]{Number1}+"\)"
SignedFloat "\("[+-]({Number1}{Number}*|0)"."{Number}+"\)"

UnsignedInt {Number1}{Number}*|0
UnsignedFloat ({Number1}{Number}*|0)"."{Number}+
/*float  (({Number1}{Number}*|0)"."{Number}+)|("\("[+-]({Number1}{Number}*|0)"."{Number}+"\)")*/
char \'[^']\'
bool true|false
/* Identificateur */
IDF {letter_Maj}({letter}|{Number})*
/*Commentaire */
comment \#.*"\n"
%%
import {printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext);return mc_import;}
as {printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext); return mc_as;}
numpy {printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext); return mc_numpy;}
PIL {printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext);return mc_pil;}
Image {printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext);return mc_Img;}
open {printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext);return mc_pilf1;}
asarray {printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext); return mc_npf1;}
save {printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext);return mc_pilf3;}
fromarray {printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext); return mc_pilf2;}
from {printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext);return mc_from;}
range {printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext); return mc_range;}
in {printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext);return mc_in;}
Int {printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext); yylval.str=strdup(yytext); Col=Col+strlen(yytext);return mc_Int; }
"float" {yylval.str=strdup(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext);return mc_float;}
"bool" {yylval.str=strdup(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext); Col=Col+strlen(yytext); return mc_bool;}
"char" {yylval.str=strdup(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext); Col=Col+strlen(yytext);return mc_char;}
"and" {Col=Col+strlen(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);return mc_and;  }
"or" {Col=Col+strlen(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext); return mc_OR;  }
"not" {Col=Col+strlen(yytext); printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext); return mc_not;  }
"if" {Col=Col+strlen(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext); return mc_if;  }
"else" {Col=Col+strlen(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext); return mc_else;  }
"for" {Col=Col+strlen(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext); return mc_for;  }
"while" {Col=Col+strlen(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext); return mc_while;}
{IDF} {
        Col=Col+strlen(yytext);
       if(yyleng<=8)
       {
        yylval.str=strdup(yytext); 
        printf ("ligne %d : IDF  reconnue est %s \n", nb_ligne,yytext);
        return idf;
       }
      else {
        printf ("Erreur lexicale Ligne %d colonne %d , IDF %s trop long   \n", nb_ligne,Col, yytext);
      }
      }
{UnsignedInt} { yylval.entier=atoi(yytext); 
                Col = Col + strlen(yytext);
                if(yylval.entier>32767 || yylval.entier<(-32768))
                {
						     printf ("Erreur lexicale: depassement de la taille des entiers  a la Ligne %d et a la colonne %d \n", nb_ligne, Col);
					      }
					      else 
                {
						     printf("Ligne %d integer reconnu %s \n" ,nb_ligne, yytext );   
                 return cst_int; 
                }
}
{SignedInt} { yylval.entier=atoi(yytext); 
              Col = Col + strlen(yytext);
               if(yylval.entier>32767 || yylval.entier<(-32768))
               {
						     printf ("Erreur lexicale: depassement de la taille des entiers  a la Ligne %d et a la colonne %d \n", nb_ligne, Col);
					      }
					   else 
             {
						     printf("Ligne %d  signed integer reconnu %s \n" ,nb_ligne, yytext );   
                 return cst_int; 
					   }
}	
{UnsignedFloat} { 
                 yylval.reel=atof(yytext);
                 printf("Ligne %d  float reconnu %s \n" ,nb_ligne, yytext ); 
                  Col = Col + strlen(yytext); return cst_reel;
                }
{SignedFloat} { 
				        yylval.reel=atof(yytext); 
                printf("Ligne %d  signed float reconnu %s \n" ,nb_ligne, yytext ); 
				        Col = Col + strlen(yytext); return cst_reel;
              }
{char} {yylval.str=strdup(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext); return cst_char;}
{bool} {yylval.str=strdup(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext); Col=Col+strlen(yytext); return cst_bool;}
"=" { Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );return mc_aff;}
"+" { Col=Col+strlen(yytext); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );return plus; }
"-" { Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); return minus; }
"*" {Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );return mul;  }
"/" {Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );return division;}
">"	{Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); return sup;  }
"<"	{Col=Col+strlen(yytext); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );return inf;  }
"<=" {Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );return infOuEg;  }
">=" {Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); return SupOuEg;  }
"!=" {Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );return diff;  }
"==" {Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); return egale;  }
"(" {Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );return par_O;  }
")" {Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); return par_F;  }
"," {Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );return vrg;  }
":" {Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); return mc_2p;  }
"[" {Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); return croch_O;}
"]" { Col=Col+strlen(yytext); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );return croch_F;}
{comment} {nb_ligne++;}
[ \t ] { Col = Col + strlen(yytext);}
"    " {Col = Col + 4; return tabulation;}

\n { nb_ligne++;Col = 1; return sautdligne;}
. printf("Erreur lexicale ligne %d colonne %d sur l'entite %s\n",nb_ligne,Col,yytext);
%%
