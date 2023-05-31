/****************CREATION DE LA TABLE DES SYMBOLES ******************/
/***Step 1: Definition des structures de données ***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TS_MS.h"
#define MAX 1000
#define MAX_SIZE 1000
#define HASH_SIZE 40

// Structure for IDF and constant entries
typedef struct element {
   int state;
   char name[20];
   char code[20];
   char type[20];
   char nature[20];
   float val;
   struct element* next;
   char valstring[10]; // for storing CHAR and BOOL values
} element;

// Hash table for IDF and constant entries
element* tab[MAX_SIZE];
int cpt, cpts, cptm;

// Hash function for IDF and constant entries
int hash_function(char* key) {
   int hash = 0;
   int i = 0;

   while (key[i] != '\0') {
      hash += key[i];
      i++;
   }

   return hash % MAX_SIZE;
}

/***Step 2: Initialisation de l'état des cases des tables des symboles***/
/*0: la case est libre    1: la case est occupée*/

void initialisation() {
   int i;

   // Initialize state to 0 in all tables
   for (i = 0; i < MAX_SIZE; i++) {
      tab[i] = NULL;
   }
   initialisation1();
   cpt = 0;
   cpts = 0;
   cptm = 0;
}

/***Step 4: Insertion des entités lexicales dans les tables des symboles ***/

// Insertion into the IDF and constant table
void inserer(char entite[], char code[], char type[], float val, char val_string[], int y,char nature[]) {
   element* new_entry = malloc(sizeof(element));
   strcpy(new_entry->name, entite);
   strcpy(new_entry->code, code);
   strcpy(new_entry->type, type);
   strcpy(new_entry->nature, nature);
   new_entry->val = val;
   strcpy(new_entry->valstring, val_string);
   new_entry->state = 1;

   int hash = hash_function(entite);

   // Check if the entry already exists
   element* entry = tab[hash];
   while (entry != NULL) {
      if (strcmp(entry->name, entite) == 0) {
         // Entry already exists, update the values
         strcpy(entry->code, code);
         strcpy(entry->type, type);
         strcpy(entry->nature, nature);
         entry->val = val;
         strcpy(entry->valstring, val_string);
         free(new_entry);
         return;
      }
      entry = entry->next;
   }

   // Insert the new entry at the beginning of the linked list
   new_entry->next = tab[hash];
   tab[hash] = new_entry;

   cpt++;
}
void free_hash_table() {
   // Free the IDF and constant table
   for (int i = 0; i < MAX_SIZE; i++) {
      element* entry = tab[i];
      while (entry != NULL) {
         element* next = entry->next;
         free(entry);
         entry = next;
      }
   }

   // Free the keyword table
   for (int i = 0; i < HASH_SIZE; i++) {
      elt* entry_kw = tabs[i];
      while (entry_kw != NULL) {
         elt* next_kw = entry_kw->next;
         free(entry_kw);
         entry_kw = next_kw;
      }
   }

   // Free the separator table
   for (int i = 0; i < HASH_SIZE; i++) {
      elt* entry_sep = tabm[i];
      while (entry_sep != NULL) {
         elt* next_sep = entry_sep->next;
         free(entry_sep);
         entry_sep = next_sep;
      }
   }
}

/***Step 5: Recherche d'une entité dans les tables des symboles ***/
int rechercher(char entite[], char code[], char type[]) {
   int hash = hash_function(entite);

   // Search in the IDF and constant table
   element* entry = tab[hash];
   while (entry != NULL) {
      if (strcmp(entry->name, entite) == 0) {
         // Entry found, update the values
         strcpy(code, entry->code);
         strcpy(type, entry->type);
         return 1;
      }
      entry = entry->next;
   }

   // Search in the keyword table
   hash = hash_function_keywords(entite);
   elt* entry_kw = tabs[hash];
   while (entry_kw != NULL) {
      if (strcmp(entry_kw->name, entite) == 0) {
         // Entry found, update the type
         strcpy(code, "");
         return 1;
      }
      entry_kw = entry_kw->next;
   }

   // Search in the separator table
   hash = hash_function_keywords(entite);
   elt* entry_sep = tabm[hash];
   while (entry_sep != NULL) {
      if (strcmp(entry_sep->name, entite) == 0) {
         // Entry found, update the type
         strcpy(code, "");
         return 1;
      }
      entry_sep = entry_sep->next;
   }

   return 0;
}

void afficher_table_idf1() {
   for (int i = 0; i < MAX_SIZE; i++) {
      element* entry = tab[i];
      while (entry != NULL) {
         printf("Name: %s, Type: %s, Value: %f\n", entry->name, entry->type, entry->val);
         entry = entry->next;
      }
   }
}

// Affichage de la table des IDF et des constantes
void afficher_table_idf() {
   printf("Table des IDF et des constantes :\n");
   printf("------------------------------------------------------------------------\n");
   printf("|    Nom     |   Code      |   Type    |  Val  |  Val_String  |   Nature   |\n");
   printf("------------------------------------------------------------------------\n");

   for (int i = 0; i < MAX_SIZE; i++) {
      element* entry = tab[i];
      while (entry != NULL) {
         printf("| %-10s | %-11s | %-9s | %-5.2f | %-12s | %-11s |\n", entry->name, entry->code, entry->type, entry->val, entry->valstring, entry->nature);
         entry = entry->next;
      }
   }

   printf("------------------------------------------------------------------------\n");
}


void afficher() {
   // Afficher les tables des symboles
   afficher_table_separators();
   afficher_table_idf();
   afficher_table_keywords();
   //free_hash_table() ;
}

// Verifier si un idf est deja declarer en verifiant son type
int doubleDeclaration(char idf[]) {
   int hash = hash_function(idf);

   // Search in the IDF and constant table
   element* entry = tab[hash];
   while (entry != NULL) {
      if (strcmp(entry->name, idf) == 0) {
         // Entry found, return 0 to indicate double declaration   
            return 0;
         
      }
      entry = entry->next;
   }

   // Entry not found, return 1 to indicate no double declaration
   return 1;
}

char* get_type(char idf[]) {
   int hash = hash_function(idf);

   // Search in the IDF and constant table
   element* entry = tab[hash];
   while (entry != NULL) {
      if (strcmp(entry->name, idf) == 0) {
         // Entry found, return the type
         return entry->type;
      }
      entry = entry->next;
   }

   // Entry not found, return NULL
   return NULL;
}

void get_val_float(char idf[],float *ttmp) {
   int hash = hash_function(idf);

   // Search for the entry in the IDF and constant table
   element* entry = tab[hash];
   while (entry != NULL) {
      if (strcmp(entry->name, idf) == 0) {
         // Entry found, return the float value
          *ttmp=entry->val;
      }
      entry = entry->next;
   }

   // Entry not found, return a default value or handle the case appropriately
   // For example, you can return 0.0 or throw an error.
   }


void modifier_type(char idf[], char new_type[]) {
   int hash = hash_function(idf);

   // Recherche de l'entrée dans la table des symboles
   element* entry = tab[hash];
   while (entry != NULL) {
      if (strcmp(entry->name, idf) == 0) {
         // Entrée trouvée, mise à jour du type
         strcpy(entry->type, new_type);
         printf("modificatio bien effectuer\n");
         return;
      }
      entry = entry->next;
   }

   // Si l'entrée n'est pas trouvée, vous pouvez choisir de générer une erreur ou d'ignorer la modification
   // Selon vos besoins, vous pouvez ajouter ici une logique supplémentaire
   // par exemple : printf("Erreur : L'entrée '%s' n'a pas été trouvée dans la table des symboles.\n", idf);
}



void set_val_string(char idf[], char new_val_string[]) {
   int hash = hash_function(idf);

   // Search for the entry in the IDF and constant table
   element* entry = tab[hash];
   while (entry != NULL) {
      if (strcmp(entry->name, idf) == 0) {
         // Entry found, update the value string
         strcpy(entry->valstring, new_val_string);
         return;
      }
      entry = entry->next;
   }
}




void SetVal(char entite[], float z) {
   int hash = hash_function(entite);

   // Search for the entry in the IDF and constant table
   element* entry = tab[hash];
   while (entry != NULL) {
      if (strcmp(entry->name, entite) == 0) {
         // Entry found, update the value
         entry->val = z;
         return;
      }
      entry = entry->next;
   }
}

 int Is_int(float *N)
{
    int X = *N;

    float temp2 = *N - X;
    if (temp2 != 0) {
        return 0;
    }
    return 1;
}

void inc_val_idf (char entite[]){
	float old;
	get_val_float(entite,&old);
	old++;
	SetVal(entite,old);
}

/*

void createAssembler(int qc, struct quad *liste)
{
	
	FILE *filePointer;
	filePointer = fopen("assembly.asm", "w");
	
    //Vérification que le fichier a été bien créé
	if(filePointer == NULL) 
    {
      printf("Error creating file\n");
	}
	
	fprintf(filePointer,"TITLE Programme.asm : \n"); //donner un nom au programme
	fprintf(filePointer,"Pile segment stack ; \n");  
	// fprintf(filePointer,"dw 100 dup(?) \n"); // car on a la structure tableau ( non itisitialisée DW -> Duplicate Word et un mot c un octet )
	fprintf(filePointer,"Pile ends \n"); // dans notre cas pas de segment de pile 


    // Segment de données ou l'etiquette est DATA
	fprintf(filePointer,"DATA segment \n");
	for(int i=0;i<673;i++)
	{
      entite * ptr=TableHachage[i].tete;
      while(ptr!=NULL)
        {
			if(strcmp(ptr->nature,"Variable")==0)
            {
				if(strcmp(ptr->type,"INTEGER")==0)
                    {fprintf(filePointer,"%s DD ?\n",ptr->name);
                    }
				if(strcmp(ptr->type,"FLOAT")==0)
                    {fprintf(filePointer,"%s DW ?\n",ptr->name);}
			}
            // else
            // {
			// 	// if(strcmp(ptr->nature,"Tableau")==0)
            //     // {
			// 	// 	if(strcmp(ptr->type,"INTEGER")==0)
            //     //     {fprintf(filePointer,"%s DD %d DUP ?\n",ptr->name, ptr->taille);
            //     //     }
			// 	// 	if(strcmp(ptr->type,"FLOAT")==0)
            //     //     {
            //     //         fprintf(filePointer,"%s DW %d DUP ?\n",ptr->name, ptr->taille);
            //     //     }
			// 	// }
			// }
			
            ptr=ptr->svt;
		}

	}

	fprintf(filePointer,"temp DD 2000 ?\n");
	fprintf(filePointer,"DATA ends\n");

    // Code Segment  etiquette par CODE
	fprintf(filePointer,"CODE segment\n");
	fprintf(filePointer,"ASSUME CS:CODE, DS:DATA\n");
	fprintf(filePointer,"MAIN :\n");
	fprintf(filePointer,"MOV AX,DATA\n");
	fprintf(filePointer,"MOV DS,AX\n");
	for(int i=0;i<qc;i++){
		fprintf(filePointer,"etiquette%d: \n",i);
		if(strcmp(liste->opr,"+")==0)
        {
			if((liste->op1[0]=='T')&&(liste->op2[0]=='T'))
            {
				fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->op1, liste[i]->op1+1, strlen(liste[i]->op1)));
				fprintf(filePointer,"MOV BX,temp[SI]\n");
				fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->op2, liste[i]->op2+1, strlen(liste[i]->op2)));
				fprintf(filePointer,"MOV AX,temp[SI]\n");
				fprintf(filePointer,"ADD AX,BX\n");
				fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->res, liste[i]->res+1, strlen(liste[i]->res)));
				fprintf(filePointer,"MOV temp[SI], AX\n");
			}
			else{
				if(liste[i]->op1[0]=='T'){
					fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->op1, liste[i]->op1+1, strlen(liste[i]->op1)));
					fprintf(filePointer,"MOV AX,temp[SI]\n");
					fprintf(filePointer,"MOV BX, %s\n",liste[i]->op2);
					fprintf(filePointer,"ADD AX,BX\n");
					fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->res, liste[i]->res+1, strlen(liste[i]->res)));
					fprintf(filePointer,"MOV temp[SI], AX\n");
				}
				if(liste[i]->op2[0]=='T'){
					fprintf(filePointer,"MOV AX, %s\n",liste[i]->op1);
					fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->op2, liste[i]->op2+1, strlen(liste[i]->op2)));
					fprintf(filePointer,"MOV BX,temp[SI]\n");
					fprintf(filePointer,"ADD AX,BX\n");
					fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->res, liste[i]->res+1, strlen(liste[i]->res)));
					fprintf(filePointer,"MOV temp[SI], AX\n");
				}
				else{
					if(strcmp(liste[i]->op1,liste[i]->res)==0){
						fprintf(filePointer,"MOV BX, %s\n",liste[i]->op1);
						fprintf(filePointer,"MOV AX, %s\n",liste[i]->op2);
						fprintf(filePointer,"ADD BX, AX \n");
						fprintf(filePointer,"MOV %s, BX\n",liste[i]->op1);
					}else{
						fprintf(filePointer,"MOV BX, %s\n",liste[i]->op1);
						fprintf(filePointer,"MOV AX, %s\n",liste[i]->op2);
						fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->res, liste[i]->res+1, strlen(liste[i]->res)));
						fprintf(filePointer,"ADD BX, AX \n");
						fprintf(filePointer,"MOV temp[SI], BX\n");
					}
					
				}
			}

	}
		if(strcmp(liste[i]->opr,"-")==0){
			if((liste[i]->op1[0]=='T')&&(liste[i]->op2[0]=='T')){
				fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->op1, liste[i]->op1+1, strlen(liste[i]->op1)));
				fprintf(filePointer,"MOV BX,temp[SI]\n");
				fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->op2, liste[i]->op2+1, strlen(liste[i]->op2)));
				fprintf(filePointer,"MOV AX,temp[SI]\n");
				fprintf(filePointer,"SUB AX,BX\n");
				fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->res, liste[i]->res+1, strlen(liste[i]->res)));
				fprintf(filePointer,"MOV temp[SI], AX\n");
			}
			else{
				if(liste[i]->op1[0]=='T'){
					fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->op1, liste[i]->op1+1, strlen(liste[i]->op1)));
					fprintf(filePointer,"MOV AX,temp[SI]\n");
					fprintf(filePointer,"MOV BX, %s\n",liste[i]->op2);
					fprintf(filePointer,"SUB AX,BX\n");
					fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->res, liste[i]->res+1, strlen(liste[i]->res)));
					fprintf(filePointer,"MOV temp[SI], AX\n");
				}
				if(liste[i]->op2[0]=='T'){
					fprintf(filePointer,"MOV AX, %s\n",liste[i]->op1);
					fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->op2, liste[i]->op2+1, strlen(liste[i]->op2)));
					fprintf(filePointer,"MOV BX,temp[SI]\n");
					fprintf(filePointer,"SUB AX,BX\n");
					fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->res, liste[i]->res+1, strlen(liste[i]->res)));
					fprintf(filePointer,"MOV temp[SI], AX\n");
				}
				else{
					fprintf(filePointer,"MOV BX, %s\n",liste[i]->op1);
					fprintf(filePointer,"MOV AX, %s\n",liste[i]->op2);
					fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->res, liste[i]->res+1, strlen(liste[i]->res)));
					fprintf(filePointer,"SUB BX, AX \n");
					fprintf(filePointer,"MOV temp[SI], BX\n");
				}
			}

	}
	if(strcmp(liste[i]->opr,"*")==0){
			if((liste[i]->op1[0]=='T')&&(liste[i]->op2[0]=='T')){
				fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->op1, liste[i]->op1+1, strlen(liste[i]->op1)));
				fprintf(filePointer,"MOV BX,temp[SI]\n");
				fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->op2, liste[i]->op2+1, strlen(liste[i]->op2)));
				fprintf(filePointer,"MOV AX,temp[SI]\n");
				fprintf(filePointer,"MUL BX\n");
				fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->res, liste[i]->res+1, strlen(liste[i]->res)));
				fprintf(filePointer,"MOV temp[SI], AX\n");
			}
			else{
				if(liste[i].op1[0]=='T'){
					fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->op1, liste[i]->op1+1, strlen(liste[i]->op1)));
					fprintf(filePointer,"MOV AX,temp[SI]\n");
					fprintf(filePointer,"MOV BX, %s\n",liste[i]->op2);
					fprintf(filePointer,"MUL BX\n");
					fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->res, liste[i]->res+1, strlen(liste[i]->res)));
					fprintf(filePointer,"MOV temp[SI], AX\n");
				}
				if(liste[i]->op2[0]=='T'){
					fprintf(filePointer,"MOV AX, %s\n",liste[i]->op1);
					fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->op2, liste[i]->op2+1, strlen(liste[i]->op2)));
					fprintf(filePointer,"MOV BX,temp[SI]\n");
					fprintf(filePointer,"MUL BX\n");
					fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->res, liste[i]->res+1, strlen(liste[i]->res)));
					fprintf(filePointer,"MOV temp[SI], AX\n");
				}
				else{
					fprintf(filePointer,"MOV BX, %s\n",liste[i]->op1);
					fprintf(filePointer,"MOV AX, %s\n",liste[i]->op2);
					fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->res, liste[i]->res+1, strlen(liste[i]->res)));
					fprintf(filePointer,"MUL BX \n");
					fprintf(filePointer,"MOV temp[SI], AX\n");
				}
			}

	}
	if(strcmp(liste[i]->opr,"/")==0){
			if((liste[i]->op1[0]=='T')&&(liste[i]->op2[0]=='T')){
				fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->op1, liste[i]->op1+1, strlen(liste[i]->op1)));
				fprintf(filePointer,"MOV AX,temp[SI]\n");
				fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->op2, liste[i]->op2+1, strlen(liste[i]->op2)));
				fprintf(filePointer,"MOV BX,temp[SI]\n");
				fprintf(filePointer,"DIV BX\n");
				fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->res, liste[i]->res+1, strlen(liste[i]->res)));
				fprintf(filePointer,"MOV temp[SI], AX\n");
			}
			else{
				if(liste[i]->op1[0]=='T'){
					fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->op1, liste[i]->op1+1, strlen(liste[i]->op1)));
					fprintf(filePointer,"MOV BX,temp[SI]\n");
					fprintf(filePointer,"MOV AX, %s\n",liste[i]->op2);
					fprintf(filePointer,"DIV BX\n");
					fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->res, liste[i]->res+1, strlen(liste[i]->res)));
					fprintf(filePointer,"MOV temp[SI], AX\n");
				}
				if(liste[i]->op2[0]=='T'){
					fprintf(filePointer,"MOV BX, %s\n",liste[i]->op1);
					fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->op2, liste[i]->op2+1, strlen(liste[i]->op2)));
					fprintf(filePointer,"MOV AX,temp[SI]\n");
					fprintf(filePointer,"DIV BX\n");
					fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->res, liste[i]->res+1, strlen(liste[i]->res)));
					fprintf(filePointer,"MOV temp[SI], AX\n");
				}
				else{
					fprintf(filePointer,"MOV AX, %s\n",liste[i]->op1);
					fprintf(filePointer,"MOV BX, %s\n",liste[i]->op2);
					fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->res, liste[i]->res+1, strlen(liste[i]->res)));
					fprintf(filePointer,"DIV BX \n");
					fprintf(filePointer,"MOV temp[SI], AX\n");
				}
			}

	}
	if(strcmp(liste[i]->opr,"BR")==0){
		if(atoi(liste[i]->op1) <= (qc-1)){
			fprintf(filePointer,"JMP etiquette%s\n",liste[i].op1);
		}else{
			fprintf(filePointer,"JMP FIN \n");
		}
	}
	if(strcmp(liste[i]->opr,"BG")==0){
		if(atoi(liste[i]->op1) <= (qc-1)){
			fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->op2, liste[i]->op2+1, strlen(liste[i]->op2)));
			fprintf(filePointer,"MOV CX,temp[SI]\n");
			fprintf(filePointer,"CMP CX, 0\n");
			fprintf(filePointer,"JG etiquette%s\n",liste[i]->op1);
		}else{
			fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->op2, liste[i]->op2+1, strlen(liste[i]->op2)));
			fprintf(filePointer,"MOV CX,temp[SI]\n");
			fprintf(filePointer,"CMP CX, 0\n");
			fprintf(filePointer,"JG FIN\n");
		}
			
	}
	if(strcmp(liste[i]->opr,"BGE")==0){
		if(atoi(liste[i]->op1) <= (qc-1)){
			fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->op2, liste[i]->op2+1, strlen(liste[i]->op2)));
			fprintf(filePointer,"MOV CX,temp[SI]\n");
			fprintf(filePointer,"CMP CX, 0\n");
			fprintf(filePointer,"JGE etiquette%s\n",liste[i].op1);
		}else{
			fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->op2, liste[i]->op2+1, strlen(liste[i]->op2)));
			fprintf(filePointer,"MOV CX,temp[SI]\n");
			fprintf(filePointer,"CMP CX, 0\n");
			fprintf(filePointer,"JGE FIN \n");
		}
	}
	if(strcmp(liste[i]->opr,"BL")==0){
		if(atoi(liste[i]->op1) <= (qc-1)){
			fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->op2, liste[i]->op2+1, strlen(liste[i]->op2)));
			fprintf(filePointer,"MOV CX,temp[SI]\n");
			fprintf(filePointer,"CMP CX, 0\n");
			fprintf(filePointer,"JL etiquette%s\n",liste[i].op1);
		}else{
			fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->op2, liste[i]->op2+1, strlen(liste[i]->op2)));
			fprintf(filePointer,"MOV CX,temp[SI]\n");
			fprintf(filePointer,"CMP CX, 0\n");
			fprintf(filePointer,"JL FIN \n");
		}

	}
	if(strcmp(liste[i]->opr,"BLE")==0){
		if(atoi(liste[i]->op1) <= (qc-1)){
			fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->op2, liste[i]->op2+1, strlen(liste[i]->op2)));
			fprintf(filePointer,"MOV CX,temp[SI]\n");
			fprintf(filePointer,"CMP CX, 0\n");
			fprintf(filePointer,"JLE etiquette%s\n",liste[i]->op1);
		}else{
			fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->op2, liste[i]->op2+1, strlen(liste[i]->op2)));
			fprintf(filePointer,"MOV CX,temp[SI]\n");
			fprintf(filePointer,"CMP CX, 0\n");
			fprintf(filePointer,"JLE FIN \n");
		}
	}
	if(strcmp(liste[i].opr,"BZ")==0){
		if(atoi(liste[i].op1) <= (qc-1)){
			fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->op2, liste[i]->op2+1, strlen(liste[i]->op2)));
			fprintf(filePointer,"MOV CX,temp[SI]\n");
			fprintf(filePointer,"CMP CX, 0\n");
			fprintf(filePointer,"JE etiquette%s\n",liste[i].op1);
		}else{
			fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->op2, liste[i]->op2+1, strlen(liste[i]->op2)));
			fprintf(filePointer,"MOV CX,temp[SI]\n");
			fprintf(filePointer,"CMP CX, 0\n");
			fprintf(filePointer,"JE FIN \n");
		}
	}
	if(strcmp(liste[i]->opr,"BNZ")==0){
		if(atoi(liste[i]->op1) <= (qc-1)){
			fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->op2, liste[i]->op2+1, strlen(liste[i]->op2)));
			fprintf(filePointer,"MOV CX,temp[SI]\n");
			fprintf(filePointer,"CMP CX, 0\n");
			fprintf(filePointer,"JNE etiquette%s\n",liste[i].op1);
		}else{
			fprintf(filePointer,"MOV SI, %s\n",memmove(liste[i]->op2, liste[i]->op2+1, strlen(liste[i]->op2)));
			fprintf(filePointer,"MOV CX,temp[SI]\n");
			fprintf(filePointer,"CMP CX, 0\n");
			fprintf(filePointer,"JNE FIN \n");
		}
	}
	if(strcmp(liste[i]->opr,"=")==0){
		if(liste[i]->res[0]=='T'){
			if(liste[i]->op1[0]=='T'){
				fprintf(filePointer,"MOV SI, %s \n",memmove(liste[i].op1, liste[i].op1+1, strlen(liste[i]->op1)));
				fprintf(filePointer,"MOV BX, temp[SI]\n");
				fprintf(filePointer,"MOV SI, %s \n",memmove(liste[i]->res, liste[i]->res+1, strlen(liste[i]->res)));
				fprintf(filePointer,"MOV temp[SI], BX\n");
			}
			else{
				fprintf(filePointer,"MOV BX, %s \n",liste[i]->op1);
				fprintf(filePointer,"MOV SI, %s \n",memmove(liste[i]->res, liste[i]->res+1, strlen(liste[i]->res)));
				fprintf(filePointer,"MOV temp[SI], BX\n");
			}			
		}else{
			if(liste[i]->op1[0]=='T'){
				fprintf(filePointer,"MOV SI, %s \n",memmove(liste[i]->op1, liste[i]->op1+1, strlen(liste[i]->op1)));
				fprintf(filePointer,"MOV BX, temp[SI]\n");
				fprintf(filePointer,"MOV %s, BX\n",liste[i]->res);
			}
			else{
				fprintf(filePointer,"MOV BX, %s \n",liste[i]->op1);
				fprintf(filePointer,"MOV %s, BX\n",liste[i]->res);
			}
		}
	}
}
	fprintf(filePointer,"FIN:\n");
	fprintf(filePointer,"MOV AH,4CH\n");
	fprintf(filePointer,"INT 21h\n");
	fprintf(filePointer,"CODE ends\n");
	fprintf(filePointer,"END MAIN\n");
	fclose(filePointer);
}

*/