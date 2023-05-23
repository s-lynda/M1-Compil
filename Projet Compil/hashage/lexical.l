%{
#include <String.h>
#include <stdio.h>
#include "TS_hash.h"
#include "syntax.tab.h"
    /* Définition en langage C*/
// extern int Col;
int nb_ligne=1;
extern YYSTYPE yylval;
extern int  Col;

char tmps_signed_numbers[20];
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
import {inserer_keywords(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext);return mc_import;}
as {inserer_keywords(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext); return mc_as;}
numpy {inserer_keywords(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext); return mc_numpy;}
PIL {inserer_keywords(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext);return mc_pil;}
Image {inserer_keywords(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext);return mc_Img;}
open {inserer_keywords(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext);return mc_pilf1;}
asarray {inserer_keywords(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext); return mc_npf1;}
save {inserer_keywords(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext);return mc_pilf3;}
fromarray {inserer_keywords(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext); return mc_pilf2;}
from {inserer_keywords(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext);return mc_from;}
range {inserer_keywords(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext); return mc_range;}
in {inserer_keywords(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext);return mc_in;}
Int {inserer_keywords(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext); yylval.str=strdup(yytext); Col=Col+strlen(yytext);return mc_Int; }
"float" {inserer_keywords(yytext);yylval.str=strdup(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext);return mc_float;}
"bool" {inserer_keywords(yytext);yylval.str=strdup(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext); Col=Col+strlen(yytext); return mc_bool;}
"char" {inserer_keywords(yytext);yylval.str=strdup(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext); Col=Col+strlen(yytext);return mc_char;}
"and" {inserer_keywords(yytext);Col=Col+strlen(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);return mc_and;  }
"or" {inserer_keywords(yytext);Col=Col+strlen(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext); return mc_OR;  }
"not" {inserer_keywords(yytext);Col=Col+strlen(yytext); printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext); return mc_not;  }
"if" {inserer_keywords(yytext);Col=Col+strlen(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext); return mc_if;  }
"else" {inserer_keywords(yytext);Col=Col+strlen(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext); return mc_else;  }
"for" {inserer_keywords(yytext);Col=Col+strlen(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext); return mc_for;  }
"while" {inserer_keywords(yytext);Col=Col+strlen(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext); return mc_while;}
{IDF} {   
			       Col= Col+ strlen (yytext); 
                   if (yyleng<=8) {   
			                        printf("Ligne %d IDF reconnu %s \n" ,nb_ligne, yytext ); 
                                    yylval.str=strdup(yytext);									
									return idf;
							      }
                    else printf ("Erreur lexicale Ligne %d colonne %d , IDF %s trop long   \n", nb_ligne, Col,yytext);
 }
{UnsignedInt} { yylval.entier=atoi(yytext); 
                       Col = Col + strlen(yytext);
                       if(yylval.entier>32767 || yylval.entier<(-32768)){
						     printf ("Erreur lexicale: depassement de la taille des entiers  a la Ligne %d et a la colonne %d \n", nb_ligne, Col);
					   }
					   else {
						     inserer (yytext,"Cst_entier","INTEGER",atoi(yytext),"", 0);
						     printf("Ligne %d integer reconnu %s \n" ,nb_ligne, yytext );   return cst_int; 
					   }
	}
{SignedInt} { 		  
					   yylval.entier=atoi(tmps_signed_numbers); 
                       Col = Col + strlen(yytext);
                       if(yylval.entier>32767 || yylval.entier<(-32768)){
						     printf ("Erreur lexicale: depassement de la taille des entiers  a la Ligne %d et a la colonne %d \n", nb_ligne, Col);
					   }
					   else {
						    
						     printf("Ligne %d  signed integer reconnu %s \n" ,nb_ligne, yytext );   return cst_int; 
					   }
	}	
{UnsignedFloat} { inserer(yytext,"cst_reel","FLOAT",atof(yytext),"",0); yylval.reel=atof(yytext);printf("Ligne %d  float reconnu %s \n" ,nb_ligne, yytext );  Col = Col + strlen(yytext); return cst_reel;}
{SignedFloat}  { 
				yylval.entier=atoi(tmps_signed_numbers); 				
				yylval.reel=atof(tmps_signed_numbers); printf("Ligne %d  signed float reconnu %s \n" ,nb_ligne, yytext ); 
				Col = Col + strlen(yytext); return cst_reel;}
{char}  { inserer (yytext,"cst_char","CHAR",0,yytext, 0); yylval.str=strdup(yytext); printf("Ligne %d char reconnu %s \n" ,nb_ligne, yytext );  Col = Col + strlen(yytext); return cst_char;}
{bool} {inserer(yytext,"cst_bool","BOOLEAN",0,yytext, 0);yylval.str=strdup(yytext); printf("ligne %d : boolean reconnu %s \n",nb_ligne,yytext);Col=Col+strlen(yytext); return cst_bool; }
"=" {inserer_separators(yytext);Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); yylval.str=strdup(yytext);return mc_aff;}
"+" {inserer_separators(yytext);Col=Col+strlen(yytext); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); yylval.str=strdup(yytext);return plus; }
"-" { inserer_separators(yytext);Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); yylval.str=strdup(yytext); return minus; }
"*" {inserer_separators(yytext);Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); yylval.str=strdup(yytext);return mul;  }
"/" {inserer_separators(yytext);Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );return division;}
">"	{inserer_separators(yytext);Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); return sup;  }
"<"	{inserer_separators(yytext);Col=Col+strlen(yytext); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );return inf;  }
"<=" {inserer_separators(yytext);Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );return infOuEg;  }
">=" {inserer_separators(yytext);Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); return SupOuEg;  }
"!=" {inserer_separators(yytext);Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );return diff;  }
"==" {inserer_separators(yytext);Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); return egale;  }
"(" {inserer_separators(yytext);Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );return par_O;  }
")" {inserer_separators(yytext);Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); return par_F;  }
"," {inserer_separators(yytext);Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );return vrg;  }
":" {inserer_separators(yytext);Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); return mc_2p;  }
"[" {inserer_separators(yytext);Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); return croch_O;}
"]" {inserer_separators(yytext);Col=Col+strlen(yytext); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );return croch_F;}
{comment} {nb_ligne++;}
[ \t ] { Col = Col + strlen(yytext);}
"    " {Col = Col + 4; return tabulation;}
\n { nb_ligne++;Col = 1; return sautdligne;}
. printf("Erreur lexicale ligne %d colonne %d sur l'entite %s\n",nb_ligne,Col,yytext);
%%
