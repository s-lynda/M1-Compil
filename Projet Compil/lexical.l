%{
#include <String.h>
#include <stcdio.h>
#include "TS.h"
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
import {rechercher(yytext,"Mot cle","",0,"", 1);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext);return mc_import;}
as {rechercher(yytext,"Mot cle","",0,"", 1);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext); return mc_as;}
numpy {rechercher(yytext,"Mot cle","",0,"", 1);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext); return mc_numpy;}
PIL {rechercher(yytext,"Mot cle","",0,"", 1);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext);return mc_pil;}
Image {rechercher(yytext,"Mot cle","",0,"", 1);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext);return mc_Img;}
open {rechercher(yytext,"Mot cle","",0,"", 1);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext);return mc_pilf1;}
asarray {rechercher(yytext,"Mot cle","",0,"", 1);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext); return mc_npf1;}
save {rechercher(yytext,"Mot cle","",0,"", 1);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext);return mc_pilf3;}
fromarray {rechercher(yytext,"Mot cle","",0,"", 1);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext); return mc_pilf2;}
from {rechercher(yytext,"Mot cle","",0,"", 1);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext);return mc_from;}
range {printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext); return mc_range;}
in {rechercher(yytext,"Mot cle","",0,"", 1);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext);return mc_in;}
Int {rechercher(yytext,"Mot cle","",0,"", 1);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext); yylval.str=strdup(yytext); Col=Col+strlen(yytext);return mc_Int; }
"float" {rechercher(yytext,"Mot cle","",0,"", 1);yylval.str=strdup(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);Col=Col+strlen(yytext);return mc_float;}
"bool" {rechercher(yytext,"Mot cle","",0,"", 1);yylval.str=strdup(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext); Col=Col+strlen(yytext); return mc_bool;}
"char" {rechercher(yytext,"Mot cle","",0,"", 1);yylval.str=strdup(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext); Col=Col+strlen(yytext);return mc_char;}
"and" {rechercher(yytext,"Mot cle","",0,"", 1);Col=Col+strlen(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);return mc_and;  }
"or" {rechercher(yytext,"Mot cle","",0,"", 1);Col=Col+strlen(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext); return mc_OR;  }
"not" {rechercher(yytext,"Mot cle","",0,"", 1);Col=Col+strlen(yytext); printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext); return mc_not;  }
"if" {rechercher(yytext,"Mot cle","",0,"", 1);Col=Col+strlen(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext); return mc_if;  }
"else" {rechercher(yytext,"Mot cle","",0,"", 1);Col=Col+strlen(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext); return mc_else;  }
"for" {rechercher(yytext,"Mot cle","",0,"", 1);Col=Col+strlen(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext); return mc_for;  }
"while" {rechercher(yytext,"Mot cle","",0,"", 1);Col=Col+strlen(yytext);printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext); return mc_while;}
{IDF} {   
			       Col= Col+ strlen (yytext); 
                   if (yyleng<=8) {   
				                    rechercher (yytext,"IDF ","",0,"", 0);
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
						     rechercher (yytext,"Cst_entier","INTEGER",atoi(yytext),"", 0);
						     printf("Ligne %d integer reconnu %s \n" ,nb_ligne, yytext );   return cst_int; 
					   }
	}
{SignedInt} { 		   strcpy(tmps_signed_numbers, substring(yytext,1,strlen(yytext)-1));
					   yylval.entier=atoi(tmps_signed_numbers); 
                       Col = Col + strlen(yytext);
                       if(yylval.entier>32767 || yylval.entier<(-32768)){
						     printf ("Erreur lexicale: depassement de la taille des entiers  a la Ligne %d et a la colonne %d \n", nb_ligne, Col);
					   }
					   else {
						     rechercher (tmps_signed_numbers,"Cst entier ","INTEGER",atoi(tmps_signed_numbers),"", 0);
						     printf("Ligne %d  signed integer reconnu %s \n" ,nb_ligne, yytext );   return cst_int; 
					   }
	}	
{UnsignedFloat} { rechercher (yytext,"cst_reel","FLOAT",atof(yytext),"",0); yylval.reel=atof(yytext);printf("Ligne %d  float reconnu %s \n" ,nb_ligne, yytext );  Col = Col + strlen(yytext); return cst_reel;}

{SignedFloat}  { strcpy(tmps_signed_numbers, substring(yytext,1,strlen(yytext)-1));
					   yylval.entier=atoi(tmps_signed_numbers); 

				
				rechercher (tmps_signed_numbers,"Cst reel ","FLOAT",atof(tmps_signed_numbers),"",0);
				yylval.reel=atof(tmps_signed_numbers); printf("Ligne %d  signed float reconnu %s \n" ,nb_ligne, yytext ); 
				Col = Col + strlen(yytext); return cst_reel;}


{char}  { rechercher (yytext,"cst_char","CHAR",0,yytext, 0); yylval.str=strdup(yytext); printf("Ligne %d char reconnu %s \n" ,nb_ligne, yytext );  Col = Col + strlen(yytext); return cst_char;}
{bool} {rechercher(yytext,"cst_bool","BOOLEAN",0,yytext, 0);yylval.str=strdup(yytext); printf("ligne %d : boolean reconnu %s \n",nb_ligne,yytext);Col=Col+strlen(yytext); return cst_bool; }
"=" {   rechercher (yytext,"Separateur","",0,"", 2);Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); yylval.str=strdup(yytext);return mc_aff;}
"+" {  rechercher (yytext,"Separateur","",0,"", 2);Col=Col+strlen(yytext); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); yylval.str=strdup(yytext);return plus; }
"-" {   rechercher (yytext,"Separateur","",0,"", 2);Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); yylval.str=strdup(yytext); return minus; }
"*" {  rechercher (yytext,"Separateur","",0,"", 2);Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); yylval.str=strdup(yytext);return mul;  }
"/" {  rechercher (yytext,"Separateur","",0,"", 2);Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );return division;}
">"	{  rechercher (yytext,"Separateur","",0,"", 2);Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); return sup;  }
"<"	{  rechercher (yytext,"Separateur","",0,"", 2);Col=Col+strlen(yytext); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );return inf;  }
"<=" {  rechercher (yytext,"Separateur","",0,"", 2);Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );return infOuEg;  }
">=" {  rechercher (yytext,"Separateur","",0,"", 2);Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); return SupOuEg;  }
"!=" {  rechercher (yytext,"Separateur","",0,"", 2);Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );return diff;  }
"==" {  rechercher (yytext,"Separateur","",0,"", 2);Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); return egale;  }
"(" {  rechercher (yytext,"Separateur","",0,"", 2);Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );return par_O;  }
")" {  rechercher (yytext,"Separateur","",0,"", 2);Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); return par_F;  }
"," {  rechercher (yytext,"Separateur","",0,"", 2);Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );return vrg;  }
":" {  rechercher (yytext,"Separateur","",0,"", 2);Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); return mc_2p;  }
"[" { rechercher (yytext,"Separateur","",0,"", 2);Col=Col+strlen(yytext);printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); return croch_O;}
"]" {  rechercher (yytext,"Separateur","",0,"", 2);Col=Col+strlen(yytext); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );return croch_F;}
{comment} {nb_ligne++;}
[ \t ] { Col = Col + strlen(yytext);}
"    " {Col = Col + 4; return tabulation;}

\n { nb_ligne++;Col = 1; return sautdligne;}
. printf("Erreur lexicale ligne %d colonne %d sur l'entite %s\n",nb_ligne,Col,yytext);
%%
