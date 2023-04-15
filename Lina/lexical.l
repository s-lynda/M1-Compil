%{
int nb_ligne=1;
int col=0;
%}
lettre [a-zA-Z]
commentaire \#.*"\n"
chiffre [0-9]
chiffre1 [1-9]
IDF ({lettre}({lettre}|{chiffre}|\_)*)
cst {chiffre}+
INT [-+]?{chiffre}+
FLOAT [+-]({chiffre}+"."{chiffre}+)|({chiffre}+"."{chiffre}+)
CHAR ['][^'][']
BOOL "true"|"false"
%%
import   {col += yyleng;printf("import \n");}
as   { col += yyleng;printf("as \n");}
"numpy" { col += yyleng; printf("numpy \n"); }
matplotlib   {col += yyleng;printf("matplotlib \n");}
'for' {col += yyleng; printf("for\n");}
"in range" { col += yyleng; printf("Mot cle in range\n");}
'in' {col += yyleng;printf("in \n");}
'if' {col += yyleng;printf ("If:");}
'else' {col += yyleng;printf ("else \n " );}
'while' {col += yyleng;printf("While boucle \n" );}
'int' {col += yyleng;printf("int \n");}
{BOOL} { col += yyleng;printf("Constante bool\n"); }
{IDF} {col += yyleng; printf ("IDF \n");}
{INT} { col += yyleng; printf("Constante entiere: %s\n", yytext);}
{FLOAT} {col += yyleng;  printf("Constante flottante: %s\n", yytext);}
{CHAR} {col += yyleng; printf("Constante char\n");}
"("  {   col += yyleng;printf("par_ouver reconnu \n");}
")"  {   col += yyleng;printf( "par_ferm reconnu \n");}
"["  {   col += yyleng;printf("[ ouv \n"); }
"]"  {   col += yyleng;printf("] fer \n"); }
";"  {   col += yyleng;printf("  pvg \n");}
"+"  {   col += yyleng;printf("  plus \n");}
"-"  {   col += yyleng;printf("moins\n"); }
"%"  {   col += yyleng;printf("modulo \n");}
"*"  {   col += yyleng;printf("multi   \n");}               
""   {   col += yyleng;printf(" reconnu \n");}
"'"  {   col += yyleng;printf("' reconnu \n"); }
":"  {   col += yyleng;printf(": reconnu \n");}
"="  {   col += yyleng;printf("Aff \n");}     
"\\/" {   col += yyleng;printf("devision\n");}
">"	 {   col += yyleng;printf("sup \n");}
"<"	 {   col += yyleng;printf("inferieur \n"); }
"<=" {   col += yyleng;printf("infer_egal \n");	}
">=" {   col += yyleng;printf("super_egale \n"); }
"!=" {   col += yyleng;printf("different \n"); }
"==" {   col += yyleng;printf("egale \n"); }
"."  {   col += yyleng;printf("point \n"); }
","  {   col += yyleng;printf("virgule \n"); }
'and' {   col += yyleng;printf("and \n");}
'or' {   col += yyleng;printf("or \n");}
'not' {   col += yyleng;printf("not \n");}
'float' {   col += yyleng;printf("float \n");}
'bool' {   col += yyleng;printf("bool \n");}
'char' {   col += yyleng;printf("char \n");}

{commentaire} {col++;}
[ \t] {col++;}
\n {nb_ligne++;}
.    col += yyleng;printf("erreur lexicale à la ligne %d et colonne \n",nb_ligne,col) ;
%%
int main () 
{
yylex() ; 
return 0; 
}
