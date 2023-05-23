/****************CREATION DE LA TABLE DES SYMBOLES ******************/
/***Step 1: Definition des structures de données ***/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TS_MS.h"

typedef struct elem {
    char* nom;
    char* type;
    char* val_string;
    char* code;
    struct elem* svt;
    float valeur ;
}elem;

elem* tess[100];


extern char sav[20];




/***Step 5 L'affichage du contenue de la table des symboles ***/



void initialisation ()
{
    int i;
    for ( i = 0; i < 100 ; i++)
    {
            tess[i]=NULL;
    }
    initialisation1();
    
}

int fhach (char* e)
{
    int i=0, count=0;
    while (e[i]!='\0')
    {
        count+=e[i]*i*(10*(i+1));
        i++;
    }
    return (count%100);
    
}
int hash(char *name){
    int lenght=strlen(name);
    int hash_value=0;
    int i=0;
    for( i; i<lenght; i++){
      hash_value+= name[i];
      hash_value=(hash_value * name[i])% 100;
    }
return hash_value;
}
int rechercher2(char *name){
    int index = hash(name);
    elem *tmp = tess[index];
    while (tmp!=NULL && strcmp(tmp->nom,name)!=0)
    {
        tmp=tmp->svt;
    }
	if(tmp==NULL) {return 0;} // 0 si n'existe pas 
	else{
		return 1; // 1 si existe
	}
     
}
void inserer(char * NomEntite ,char* code ,char* type,float z,char* val_string,int y)
{
	int k= rechercher2(NomEntite);
	if(k==0){

    int index = hash(NomEntite);
    elem * p;
    p= (elem*) malloc( sizeof(elem));
    p->nom=NomEntite;
    p->code=code;	
    p->type=type;
    p->valeur = z;
    p->val_string =val_string;
    if (tess[index]==NULL) {p->svt=NULL; tess[index]=p;} // case vide donc insertion en premier  
    else {p->svt=tess[index]; tess[index]=p;}
	}

}



char* GetType(char* entite){
    elem* p= (elem*) malloc( sizeof(elem));
  if (rechercher2(entite)==1)
  {
   int index = hash(entite);
   p=tess[index];
   if (!strcmp(p->nom,entite)){ 
      
         return p->type;
       }else {
       p= p->svt; 
          while (p!=NULL && strcmp(p->nom,entite)) p=p->svt; 
      return p->type;
    }
}
}

int GetValeur(char* entite){
    elem* p= (elem*) malloc( sizeof(elem));
  if (rechercher2(entite)==1)
  {
   int index = hash(entite);
   p=tess[index];
   if (!strcmp(p->nom,entite)){ 
      
         return p->valeur;
       }else {
       p= p->svt; 
          while (p!=NULL && strcmp(p->nom,entite)) p=p->svt; 
      return p->valeur;
    }
}
}





void SetVal(char* entite, float z){
  elem* p= (elem*) malloc( sizeof(elem));
  if (rechercher2(entite)==1)
  {
   int index = hash(entite);
   p=tess[index];
   p->valeur = z; 
    }
}

void Settype(char* entite, char* z){
  elem* p= (elem*) malloc( sizeof(elem));
  if (rechercher2(entite)==1)
  {
   int index = hash(entite);
   p=tess[index];
   p->type = z; 
    }
}


void printList(elem* l);
void countSpaces(char s[8]) {
    int i;
    for (i = strlen(s); i < 8; i++) {
        s[i] = ' ';
    }
    s[8] = '\0';
}
char* switchType(int type){

	switch (type)
	{
	case 1:
         return "INTEGER ";
		break;
	
		case 2:
         return "FLOAT   ";

		break;

    case 3:
         return "IDF     ";

		break;

    case 4:
         return "STRUCT  ";

		break;
	}
	return "NON INIT";
}
void printHachTable(){
    int i;
    printf("__________________________________________________________________________________________________________________ \n");
    printf("------------------------------------------------TABLE DES IDF----------------------------------------------------- \n");
    printf("__________________________________________________________________________________________________________________ \n");


    printf("          IDF          |      CodeEntite     |         Type           |      code     |        valeur       |\n");      
    printf("__________________________________________________________________________________________________________________ \n");


    for ( i = 0; i <100; i++)
    {
        if (tess[i]!=NULL)
        { 
            char str[15];
            for ( tess[i] ; tess[i]!=NULL; tess[i]=tess[i]->svt)
            {  
                strcpy(str,tess[i]->nom); countSpaces(str);
                printf("  %-10s           |",str);
             
                printf("  %-10s            |",tess[i]->type);
                printf("  %-10s                 |",tess[i]->code);
                printf("  %f           |\n",tess[i]->valeur);
                printf("__________________________________________________________________________________________________________________ \n");
            }
        //printList(tess[i]);
        }
    }
}




