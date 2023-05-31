%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"pile.h"
#include "opt.h"
//#include "quadruplets.h"
#define MAX 1000
#define MAX_SIZE 1000
#define HASH_SIZE 40

#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
int doubleDeclaration(char idf[]);
void modifier_type(char idf[], char type[]);
void set_val_string(char idf[], char type[]);
void inserer(char entite[], char code[], char type[], float val, char val_string[], int y,char nature[]) ;
void initialisation();
void afficher();
void SetVal(char entite[], float z);
char* get_type(char idf[]);
#endif

#define MAX_SIZE 1000
extern int nb_ligne;
float tmp,valfloat;
int yyparse(); 
int yylex();
int yyerror(char *s);
int Col=1;
char sauvidf[10];  // save type  ( BOOLEAN , CHAR FLOAT INTEGER ) , pour màj de type idf 
char sauvval[10];
char sauvidfqud[10];
char sauvindex[4];
char quad1[10]; 
char quad2[10];
int qc = 0;
int its_idf=0;
float op1,op2; // gerer les exp_arthimetique pour maj de idf et test conditions 
char* chartype;
int quadindex1 ,quadindex2;
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
        croch_O  croch_F tabulation guillemets sautdligne point

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
                        if (doubleDeclaration($2)!=0)
                        {inserer($2,"IDF",sauvidf, 0, "", 0,"VARIABLE");}
                        else {
                                printf("\n =====> Erreur a la ligne %d et colonne %d : idf deja declarer", nb_ligne, Col);
                        }

                        }
                       

     |TAB_DEC 
;

// un tableau est reconnue comme type table , pas d'allocation d'espace 
TAB_DEC: TYPE idf croch_O cst_int croch_F {
                  if($4<=0){
                  printf("    >>>>>>> Erreur semantique ligne %d colonne %d La taille du tableau doit etre superieure a 0  \n",nb_ligne,Col);}
                  else{
                  if(doubleDeclaration($2)!=0){
                  inserer($2,"IDF",sauvidf, 0, "", 0,"TABLEAU");
                  }else {printf("    >>>>>>> Erreur semantique ligne %d colonne %d ,DOUBLE DECLARATION de idf %s  \n",nb_ligne,Col,$2);}   
                  
                  }};
;
LIST_VAR: vrg idf LIST_VAR
{ 
    if (doubleDeclaration($2) != 0) {
      inserer($2,"IDF",sauvidf, 0, "", 0,"VARIABLE");
    }
    else {
        printf("\n=======> Erreur sémantique à la ligne %d, DOUBLE DECLARATION de idf %s\n", nb_ligne, Col, $2);
    }
}
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
      |FOR_IN
;

AFFECT :AFFECT_ARITHM 
        | idf mc_aff cst_char SAUT  
        {if (doubleDeclaration($1)==0) {
        // verifier compatibilite de type 
        chartype=get_type($1);
        if (strcmp(chartype,"CHAR")!=0){
             printf("\n =====> Erreur a la ligne %d et colonne %d : idf %s  incompatibilite de type ", nb_ligne, Col,$1);

        }
        else{   // deja declarer je maj valchar
               set_val_string($1,$3);
                quadruplet("=",$3,"",$1);
        }
        }
        else{
            // pas declarer je l'insere
            inserer($1,"IDF","CHAR", 0, $3, 0,"VARIABLE");
            quadruplet("=",$3,"",$1);

        }} 

        // ask linda what is bool exactly          
        | idf mc_aff cst_bool SAUT
           {if (doubleDeclaration($1)==0) {
        // verifier compatibilite de type 
        chartype=get_type($1);
        if (strcmp(chartype,"BOOL")!=0){
             printf("\n =====> Erreur a la ligne %d et colonne %d : idf %s  incompatibilite de type ", nb_ligne, Col,$1);

        }
        else{   // deja declarer je maj valchar
               set_val_string($1,$3);
        }
        }
        else{
            // pas declarer je l'insere
            inserer($1,"IDF","BOOL", 0, $3, 0,"VARIABLE");

        }}   
        |AFF_SPECIAL 
;

AFF_SPECIAL: idf mc_aff mc_Img point mc_pilf1 PATH SAUT
           | idf mc_aff idf point mc_npf1 PATH SAUT
           |mc_Img point mc_pilf2 PATH point mc_pilf3 PATH SAUT
;
PATH: par_O guillemets idf guillemets par_F
        | par_O idf par_F
     ;

AFFECT_ARITHM : idf mc_aff EXP_ARRITH  SAUT 
{        tmp=Depiler();
         chartype=get_type($1);
         if(strcmp(chartype,"CHAR")==0){
               printf("    >>>>>>> Erreur semantique ligne %d colonne %d INCOMPATIBILITE DE TYPE , idf %s est un caractere , ne peut pas recevoir une valeure numerique \n",nb_ligne,Col,$1);}
         else{
               if(strcmp(chartype,"BOOLEAN")==0){
               printf("    >>>>>>> Erreur semantique ligne %d colonne %d INCOMPATIBILITE DE TYPE , idf %s est un BOOLEAN , ne peut pas recevoir une valeure numerique \n",nb_ligne,Col,$1);}
               else {
                if(its_idf==1) 
                {
                  ajout_quad_affect_idf($1,sauvidfqud);
                  SetVal($1,tmp);
                  its_idf=0;
                } 
                else {
                SetVal($1,tmp);
                ajout_quad_affect_val($1,&tmp);
                if(Is_int(&tmp)==1)
               {
                  printf("\n its an int ");
                  modifier_type($1,"INTEGER");
                  
               }else{
                  printf("its a float");
                  modifier_type($1,"FLOAT");
                  }}
             }
}}




EXP_ARRITH:EXP_ARRITH plus EXP_ARRITH     
       { if (its_idf==1){

            op2=Depiler();op1=Depiler();
            tmp = op1+op2; Empiler(tmp);
            get_val_float(sauvidfqud,&valfloat);
            if (valfloat== op1){
            ajout_quad_opbinaireIDF('+',sauvidfqud,&op2); 
            }
            else{
                ajout_quad_opbinaireIDF('+',sauvidfqud,&op1); 
            }

           
          }
          else {
            op2=Depiler();op1=Depiler(); tmp = op1+op2; Empiler(tmp);
            ajout_quad_opbinaire('+',&op1,&op2);}
          } 
	      |EXP_ARRITH minus EXP_ARRITH   
          { if (its_idf==1){

            op2=Depiler();op1=Depiler();
            tmp = op1-op2; Empiler(tmp);
            get_val_float(sauvidfqud,&valfloat);
            if (valfloat== op1){
            ajout_quad_opbinaireIDF('-',sauvidfqud,&op2); 
            }
            else{
                ajout_quad_opbinaireIDF('-',sauvidfqud,&op1); 
            }

           
          }
          else {
            op2=Depiler();op1=Depiler(); tmp = op1*op2; Empiler(tmp);
            ajout_quad_opbinaire('-',&op1,&op2);}
          } 
	      |EXP_ARRITH mul EXP_ARRITH 
          { if (its_idf==1){

            op2=Depiler();op1=Depiler();
            tmp = op1*op2; Empiler(tmp);
            get_val_float(sauvidfqud,&valfloat);
            if (valfloat== op1){
            ajout_quad_opbinaireIDF('*',sauvidfqud,&op2); 
            }
            else{
                ajout_quad_opbinaireIDF('*',sauvidfqud,&op1); 
            }

           
          }
          else {
            op2=Depiler();op1=Depiler(); tmp = op1*op2; Empiler(tmp);
            ajout_quad_opbinaire('*',&op1,&op2);}
          } 
          |EXP_ARRITH division EXP_ARRITH 
            {        
             op2=Depiler();op1=Depiler();
             if(op2==0){
	       	printf ("> Erreur semantique ligne %d colonne %d DIVISION PAR 0 \n",nb_ligne,Col);
			     }else{

                { if (its_idf==1){

            op2=Depiler();op1=Depiler();
            tmp = op1/op2; Empiler(tmp);
            get_val_float(sauvidfqud,&valfloat);
            if (valfloat== op1){
            ajout_quad_opbinaireIDF('/',sauvidfqud,&op2); 
            }
            else{
                ajout_quad_opbinaireIDF('/',sauvidfqud,&op1); 
            }

           
          }
          else {
            op2=Depiler();op1=Depiler(); tmp = op1/op2; Empiler(tmp);
            ajout_quad_opbinaire('/',&op1,&op2);}
          } 

      
           }}
           |minus EXP_ARRITH
           {
            op1=Depiler();tmp= -op1; Empiler(tmp);
            ajout_quad_opunaire(&op1);
            }
           |par_O EXP_ARRITH par_O

           |idf             
            // idf1 = idf2 , on doit tester si idf2 existeait deja !        
            { if (doubleDeclaration($1)!=0){ 
            {printf("\n=======> Errreur symantique a la ligne %d colonne %d , operand %s non declare\n",nb_ligne,Col,$1);}}
            else{
            get_val_float($1,&tmp);
            its_idf=1;
            Empiler(tmp);
            strcpy(sauvidfqud,$1);
            }} 
           |cst_int {Empiler($1);}
     	     |cst_reel { Empiler($1);}
;

/* ---Condition---*/
COND : EXP_LOGIQUE
      |EXP_COMPAR
;
EXP_COMPAR: EXP_ARRITH egale EXP_ARRITH
	   {
		strcpy(quad1,"BNZ");
		op2=Depiler();op1=Depiler(); tmp=(op1 == op2); Empiler(tmp);
	   }
	   |EXP_ARRITH diff EXP_ARRITH
	   {
	   strcpy(quad1,"BZ");
		op2=Depiler();op1=Depiler(); tmp=(op1 != op2); Empiler(tmp);
	   }
	   |EXP_ARRITH inf EXP_ARRITH
	   {
		{
		strcpy(quad1,"BGE");
		op2=Depiler();op1=Depiler(); tmp=(op1 < op2); Empiler(tmp);
	   }
	   }
	   |EXP_ARRITH infOuEg EXP_ARRITH
	   {strcpy(quad1,"BG");
		op2=Depiler();op1=Depiler(); tmp=(op1 <= op2); Empiler(tmp);
		}
	   |EXP_ARRITH sup EXP_ARRITH
	   {
		strcpy(quad1,"BLE");
		op2=Depiler();op1=Depiler(); tmp=(op1 > op2); Empiler(tmp);
	   }
	   |EXP_ARRITH SupOuEg EXP_ARRITH {
		strcpy(quad1,"BL");
		op2=Depiler();op1=Depiler(); tmp=(op1 >= op2); Empiler(tmp);
		
	   }
;

EXP_LOGIQUE: par_O EXP_COMPAR par_F OP_LOG par_O EXP_COMPAR par_F
;

OP_LOG : mc_and
	     | mc_not
        | mc_OR
;

/*------ Instruction -------*/
BLOC_INST : tabulation INST BLOC_INST 
          | tabulation INST 
;

// Instruction IF ELSE
IF_ELSE :  B BLOC_INST 
{
		sprintf(sauvindex,"%d",qc);
		maj_quad(quadindex2,1,sauvindex);

}
; 

B : A BLOC_INST mc_else mc_2p SAUT
{       quadindex2=qc;
	quadruplet("BR","","","");
	sprintf(sauvindex,"%d",qc);
	maj_quad(quadindex1,1,sauvindex);}
; 
A : mc_if par_O COND par_F mc_2p SAUT
 {
   tmp=Depiler();
	ajout_quad_affect_val("tmp_cond",&tmp);
	quadindex1=qc;
	quadruplet(quad1 ,"","","tmp_cond");
}
;
/* ---While Instruction ---*/
WHILE : BB BLOC_INST
{
	sprintf(sauvindex,"%d",quadindex1);
	quadruplet("BR",sauvindex,"","");
	sprintf(sauvindex,"%d",qc);
	maj_quad(quadindex2,1,sauvindex);
};
 
BB: AA COND par_F mc_2p SAUT
{
	tmp=Depiler();
	ajout_quad_affect_val("tmp_cond",&tmp);
	quadindex2=qc;
	quadruplet(quad1 ,"","","tmp_cond");
};

AA : mc_while par_O
{
	quadindex1 = qc;
	
}
;
/* ---FOR_V1---*/

FOR_RANGE :CCC par_F mc_2p SAUT BLOC_INST
{
	inc_val_idf(sauvidf);
   quadruplet("+",sauvidf,"1",sauvidf);
	sprintf(quad2,"%d",quadindex1);
	quadruplet("BR",quad2,"","");
	sprintf(quad2,"%d",qc);
	maj_quad(quadindex1,1,quad2);
};
CCC: BBB vrg EXP_ARRITH  {
	op2=Depiler();
	if(Is_int(&op2)==0){
		printf("\n=======> Errreur symantique a la ligne %d colonne %d ,  %f n'est pas INT \n",nb_ligne,Col,tmp); return 1;

	}else{

		quadindex1=qc;
		quadruplet("BG","","","tmp_cond");
	}
};

BBB : AAA mc_in mc_range par_O EXP_ARRITH 
   {
	    op1=Depiler();
	    if(Is_int(&op1)==0)
       {
		    printf("\n=======> Errreur symantique a la ligne %d colonne %d ,  %f n'est pas INT \n",nb_ligne,Col,tmp);return 1;

	}else{
		SetVal(sauvidf,tmp);
	}
};
AAA : mc_for idf
{
	if(doubleDeclaration($2)!=0){
		inserer($2,"IDF","INTEGER", 0, "", 0,"VARIABLE");

		}
      else{
		chartype=get_type($2);
		if(strcmp(chartype,"INTEGER")==0){
			strcpy(sauvidf,$2);

		}else{
			printf("\n > Errreur symantique a la ligne %d colonne %d , idf %s n'est pas INT \n",nb_ligne,Col,$2);return 1;
	   }
      }
};
/*--For version 2*/
FOR_IN: AAA mc_2p SAUT BLOC_INST
;
%%        
int main()
{  
   initialisation();
   yyparse(); 
   afficher_qdr();
   optimisation();
   afficher_qdr();
   struct quadTab* array = convertToArray(head);
   createAssembler(qc,array);
   afficher();  
  
   
}
int yywrap()

{}
int yyerror(char *msg)
{
  printf("\n > Erreur Syntaxique  \n au niveau la ligne %d et a la colonne %d \n", nb_ligne,Col);
   return 1;

}
