%{
    /* Définition en langage C*/
int nb_ligne=1;
int col=0;
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
import {return mc_import;}
as {return mc_as;}
numpy {return mc_numpy;}
cv2 {return mc_cv2;}
PIL {return mc_pil;}
Image {return mc_Img;}
ImageDrax { return mc_imgDraw; }
asarray {return mc_npf1;}
array {return mc_npf2;}
copy {return mc_npf3;}
save {return mc_pilf3;}
fromarray {return mc_pilf2;}
open { return mc_pilf1; }
imread {return mc_cv2f1;}
imwrite {return mc_cv2f2;}
from {return mc_from;}
{IDF} {return idf;}
{cst} {return cst;}
"+" { return plus;}
"-" { return minus;}
"*" {return mul;}
"/" {return div;}
"and" {return mc_and;}
"or" {return mc_OR;}
"not" {return mc_not;}
">"	{return sup;}
"<"	{return inf;}
"<=" {return infOuEg;}
">=" {return SupOuEg;}
"!=" {return diff;}
"==" {return egale;}
"=" { return mc_aff;}
"\'" {return mc_app;}
"(" {return par_O;}
")" {return par_F;}
"if" {return mc_if;}
"else" {return mc_else;}
"for" {return mc_for;}
"in" {return mc_in;}
range {return mc_range;}
"," {return vrg;}
":" {return mc_2p;}
"while" {return mc_while;}
"[" {return acc_O;}
"]" { return acc_F;}
"int" {return mc_int;}
"float" {return mc_float;}
"bool" {return mc_bool;}
"char" {return mc_char;}
{comment} {nb_ligne++;}
[ \t] {col++;}
\n {nb_ligne++;}
. printf("erreur lexicale à la ligne %d \n",nb_ligne) ;
%%
int main () 
{
yylex() ; 
return 0; 
}