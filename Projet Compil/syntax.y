%{
#include <stdio.h>
int  nb_ligne=1;
int Col=0;
int yyparse();
int yylex();
int yyerror(char*s);
int semcol, semligne;
%}
%token mc_import mc_as mc_numpy mc_cv2 mc_pil mc_Img mc_imgDraw mc_pilf1
        mc_npf1 mc_pilf2 mc_pilf3 mc_npf2 mc_npf3 mc_cv2f1 mc_cv2f2 plus
        minus mul division mc_and idf cst mc_OR mc_not sup inf infOuEg SupOuEg
        diff egale  mc_aff mc_app par_O par_F mc_if mc_else mc_for mc_in
        mc_range vrg mc_2p mc_while acc_O acc_F mc_int mc_float mc_bool 
        mc_char mc_from cst_car cst_bool  tabulation

      
%start S
%%
S:LIB 
    {
    printf("\nSyntaxe Correcte ..."); 
    }
;
// Déclaration des librairies 

LIB: mc_import lib_name LIB
     | mc_import lib_name mc_as idf LIB
     | mc_from lib_name mc_import Mod_name LIB
     | mc_import lib_name 
     | mc_import lib_name mc_as idf
     | mc_from lib_name mc_import Mod_name 
;
lib_name: mc_numpy
        |mc_pil
        | mc_cv2
        ;
Mod_name:|mc_imgDraw
        |mc_Img
        | mc_Img vrg mc_imgDraw
        | mc_imgDraw vrg mc_Img
        ; 
// Body <-> Suite d'instructions

// Instrs:

// ;              
%%        
main()
{ 
     yyparse();
}
yywrap()
{
   return 1;
}
// int yyerror(char *msg)
// {
//   printf("\n   =====> Erreur Syntaxique  \n au niveau la ligne %d et a la colonne %d \n", semligne,semcol);
//    return 1;
// }