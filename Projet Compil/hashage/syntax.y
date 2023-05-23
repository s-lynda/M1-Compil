%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000
#define MAX_SIZE 1000
#define HASH_SIZE 40
/*#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
int doubleDeclaration(char idf[]);
void modifier_type(char idf[], char type[]);
void initialisation();
void afficher();

#endif*/
#define MAX_SIZE 1000


extern int nb_ligne;
int yyparse();
int yylex();
int yyerror(char *s);
int Col=1;
char sauvidf[10];  // save type  ( BOOLEAN , CHAR FLOAT INTEGER ) , pour màj de type idf 
char sauvval[10];
%}
%union {
        int entier;
        char* str;
        float reel;
}    
%token  mc_import mc_as mc_numpy  mc_pil mc_Img
        mc_npf1   mc_npf3 mc_pilf3  mc_pilf2 mc_pilf1 mc_cv2f1
        mc_cv2f2 mc_from mc_range mc_in 
        <str>idf 
        <entier>cst_int 
        <reel>cst_reel 
        <str>cst_char 
        <str>cst_bool 
        <str>mc_Int  
        <str>mc_float 
        <str>mc_bool 
        <str>mc_char
        mc_aff plus minus mul division
        mc_and  mc_OR mc_not sup inf infOuEg SupOuEg  diff egale 
        par_O  par_F mc_if mc_else mc_for vrg  mc_2p  mc_while
        croch_O  croch_F tabulation guillemets sautdligne

/* Associativité et priorités des opérateurs */
%left sup SupOuEg egale diff infOuEg inf  /*associé de gauche */
%left plus minus  /*associé de gauche */
%left mul division /*associé de gauche */
%right idf sautdligne /*associé de gauche */
%right tabulation
%start S
%%
S: List_Dec S 
   | INST S 
   | LIB S
   | SAUT S
   | 
    {printf("syntaxe correcte"); 
    } 
;
/* Declaration */
SAUT : sautdligne SAUT 
      |sautdligne
;
LIB:  mc_import LIBRARY 
      | mc_import LIBRARY mc_as idf 
      | mc_from mc_pil mc_import mc_Img

;
LIBRARY: mc_numpy
       |mc_pil
;

List_Dec : DEC SAUT 
;
// declaration du genre : type = idf 
DEC: TYPE idf LIST_VAR {                      
                        // Mettre à jour le type dans la structure element
                        inserer($2,"IDF",sauvidf, 0, "", 0);
                        /*modifier_type("Xn","lina");*/
                        afficher_table_separators() ;
                        afficher_table_idf();
                        printf("CEST BON \n");

                        }
                       

     |TAB_DEC 
;

// un tableau est reconnue comme type table , pas d'allocation d'espace 
TAB_DEC: TYPE idf croch_O cst_int croch_F 
;

LIST_VAR: vrg idf LIST_VAR 
        | 
;

TYPE:        mc_Int {strcpy(sauvidf,"INTEGER");}
            | mc_float {strcpy(sauvidf,"FLOAT");}
            | mc_bool {strcpy(sauvidf,"BOOLEAN");}
            | mc_char {strcpy(sauvidf,"CHAR");}

;
/* instruction */
INST : AFFECT
      | IF_ELSE
      | WHILE 
      |FOR_RANGE
      
;

AFFECT :AFFECT_ARITHM 
        | idf mc_aff cst_char SAUT            
        | idf mc_aff cst_bool SAUT
        |AFF_SPECIAL 
;

/*a revoir pour les idf */
AFF_SPECIAL: idf mc_aff mc_Img'.'mc_pilf1 PATH SAUT
           | idf mc_aff idf'.'mc_npf1 par_O idf par_F PATH par_O SAUT
           |idf mc_aff mc_pilf1'.'mc_pilf1 par_O idf par_F'.'mc_pilf3 par_O PATH par_F SAUT
           |idf mc_aff mc_pilf1'.'mc_pilf2 par_O idf par_F'.'mc_pilf3 par_O PATH par_F SAUT
;

PATH: idf 
     |guillemets idf guillemets
     ;

AFFECT_ARITHM : idf mc_aff EXP_ARRITH  SAUT
   
;

EXP_ARRITH:EXP_ARRITH plus EXP_ARRITH     
           |EXP_ARRITH division EXP_ARRITH 
           |minus EXP_ARRITH
           |par_O EXP_ARRITH par_O
           |idf    {
                 char* typevall = get_type($1);
                printf("this is type %s pour %s\n", typevall, $1);
                modifier_type($1,"CHAR");
               printf("im here\n");
               char* typeval = get_type($1);
                printf("this is type %s pour %s\n", typeval, $1);
   if (strcmp(typeval, "FLOAT") == 0) {
      printf("Riguel");
   }    }  
           |cst_int
     	  |cst_reel 
;

BLOC_INST : tabulation INST BLOC_INST 
          | tabulation INST 
;

// Instruction IF ELSE
IF_ELSE :  B BLOC_INST 
; 

B : A BLOC_INST mc_else mc_2p SAUT
; 
A : mc_if par_O COND par_F mc_2p SAUT
;
COND : EXP_LOGIQUE
      |EXP_COMPAR
;
EXP_COMPAR:EXP_ARRITH egale EXP_ARRITH
	   |EXP_ARRITH diff EXP_ARRITH
	   |EXP_ARRITH inf EXP_ARRITH
	   |EXP_ARRITH infOuEg EXP_ARRITH
	   |EXP_ARRITH sup EXP_ARRITH
           |EXP_ARRITH SupOuEg EXP_ARRITH
;
EXP_LOGIQUE: par_O EXP_COMPAR par_F OP_LOG par_O EXP_COMPAR par_F
;

OP_LOG : mc_and
	| mc_not
        | mc_OR
;
WHILE : BB BLOC_INST ;
BB: AA COND par_F mc_2p SAUT
;
AA : mc_while par_O
;

FOR_RANGE :CCC par_F mc_2p SAUT BLOC_INST
;
CCC: BBB vrg EXP_ARRITH 
;
BBB : AAA mc_in mc_range par_O EXP_ARRITH
     |AAA mc_in  par_O EXP_ARRITH
;
AAA : mc_for idf
;  

%%        
int main()
{ 
   
 
   initialisation();
 
// afficher_table_idf();
  yyparse();   
  //afficher_table_separators() ;
  afficher_table_idf();
   
   
}
 yywrap()

{}
int yyerror(char *msg)
{
  printf("\n   =====> Erreur Syntaxique  \n au niveau la ligne %d et a la colonne %d \n", nb_ligne,Col);
   return 1;

}