%{
#include "syntax.tab.h"
#include <String.h>
#include <stdio.h>
    /* Définition en langage C*/
extern int  nb_ligne;
extern int Col;
extern YYSTYPE yylval;

%}
/* Définition des regex*/
letter [a-zA-Z]
letter_Maj [A-Z]
Number [0-9]
Number1 [1-9]
/* Les types de variables */
/* Int & float ( les valeurs négatives sont entre parenthèse)*/
int  {Number1}{Number}*|0|"\("[+-]{Number1}+"\)"
float  ({Number1}|0)*"."{Number}*|"\("[+-]({Number1}|0)*"."{Number}*"\)"
char {letter}
bool [true false]
/* Identificateur */
IDF {letter_Maj}({letter}|{Number})*
/* Constante */
cst {Number}+
/*Comment */
comment \#.*"\n"
%%
"import" {return mc_import;Col=Col+strlen(yytext);}
"as" {return mc_as;Col=Col+strlen(yytext);}
"numpy" {return mc_numpy;Col=Col+strlen(yytext);}
"cv2" {return mc_cv2;Col=Col+strlen(yytext);}
"PIL" {return mc_pil;Col=Col+strlen(yytext);}
Image {return mc_Img;Col=Col+strlen(yytext);}
ImageDrax { return mc_imgDraw;Col=Col+strlen(yytext); }
asarray {return mc_npf1;Col=Col+strlen(yytext);}
array {return mc_npf2;Col=Col+strlen(yytext);}
copy {return mc_npf3;Col=Col+strlen(yytext);}
save {return mc_pilf3;Col=Col+strlen(yytext);}
fromarray {return mc_pilf2;Col=Col+strlen(yytext);}
open { return mc_pilf1; Col=Col+strlen(yytext);}
imread {return mc_cv2f1;Col=Col+strlen(yytext);}
imwrite {return mc_cv2f2;Col=Col+strlen(yytext);}
from {return mc_from;Col=Col+strlen(yytext); }
{IDF} {return idf;}
{cst} {return cst;}
"+" { return plus;Col=Col+strlen(yytext);  }
"-" { return minus;Col=Col+strlen(yytext);  }
"*" {return mul;Col=Col+strlen(yytext);  }
"/" {return division;Col=Col+strlen(yytext);  }
"and" {return mc_and;Col=Col+strlen(yytext);  }
"or" {return mc_OR;Col=Col+strlen(yytext);  }
"not" {return mc_not;Col=Col+strlen(yytext);  }
">"	{return sup;Col=Col+strlen(yytext);  }
"<"	{return inf;Col=Col+strlen(yytext);  }
"<=" {return infOuEg;Col=Col+strlen(yytext);  }
">=" {return SupOuEg;Col=Col+strlen(yytext);  }
"!=" {return diff;Col=Col+strlen(yytext);  }
"==" {return egale;Col=Col+strlen(yytext);  }
"=" { return mc_aff;Col=Col+strlen(yytext);  }
"\'" {return mc_app;Col=Col+strlen(yytext);  }
"(" {return par_O;Col=Col+strlen(yytext);  }
")" {return par_F;Col=Col+strlen(yytext);  }
"if" {return mc_if;Col=Col+strlen(yytext);  }
"else" {return mc_else;Col=Col+strlen(yytext);  }
"for" {return mc_for;Col=Col+strlen(yytext);  }
"in" {return mc_in;Col=Col+strlen(yytext);  }
range {return mc_range;Col=Col+strlen(yytext);  }
"," {return vrg;Col=Col+strlen(yytext);  }
":" {return mc_2p;Col=Col+strlen(yytext);  }
"while" {return mc_while;Col=Col+strlen(yytext);  }
"[" {return acc_O;Col=Col+strlen(yytext);  }
"]" { return acc_F;Col=Col+strlen(yytext);  }
"int" {return mc_int;Col=Col+strlen(yytext);  }
"float" {return mc_float;Col=Col+strlen(yytext);  }
"bool" {return mc_bool;Col=Col+strlen(yytext);  }
"char" {return mc_char;Col=Col+strlen(yytext);  }
{comment} {nb_ligne++;}
[ \t ] { Col = Col + strlen(yytext); }


. printf("Erreur lexicale ligne %d colonne %d sur l'entite %s\n",nb_ligne,Col,yytext);

%%
// int main () 
// {
// yylex() ; 
// return 0; 
// }