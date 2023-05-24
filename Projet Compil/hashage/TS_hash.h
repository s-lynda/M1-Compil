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
void inserer(char entite[], char code[], char type[], float val, char val_string[], int y) {
   element* new_entry = malloc(sizeof(element));
   strcpy(new_entry->name, entite);
   strcpy(new_entry->code, code);
   strcpy(new_entry->type, type);
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

// Insertion into the IDF and constant table
void inserer_sans_verify(char entite[], char code[], char type[], float val, char val_string[], int y) {
   element* new_entry = malloc(sizeof(element));
   strcpy(new_entry->name, entite);
   strcpy(new_entry->code, code);
   strcpy(new_entry->type, type);
   new_entry->val = val;
   strcpy(new_entry->valstring, val_string);
   new_entry->state = 1;

   int hash = hash_function(entite);
   tab[hash] = new_entry;


}
void insererS(char entite[], char code[], char type[], float val, char val_string[], int y) {
   int hash = hash_function(entite);

   // Recherche de l'entrée dans la table des symboles
   element* previous_entry = NULL;
   element* current_entry = tab[hash];
   while (current_entry != NULL) {
      if (strcmp(current_entry->name, entite) == 0) {
         // Entrée trouvée, suppression de l'ancienne valeur
         if (previous_entry != NULL) {
            previous_entry->next = current_entry->next;
         } else {
            tab[hash] = current_entry->next;
         }
         free(current_entry);
         break;
      }
      previous_entry = current_entry;
      current_entry = current_entry->next;
   }

   // Insertion de la nouvelle entrée
   element* new_entry = malloc(sizeof(element));
   strcpy(new_entry->name, entite);
   strcpy(new_entry->code, code);
   strcpy(new_entry->type, type);
   new_entry->val = val;
   strcpy(new_entry->valstring, val_string);
   new_entry->state = 1;

   // Insérer la nouvelle entrée au début de la liste chaînée
   new_entry->next = tab[hash];
   tab[hash] = new_entry;

   cpt++;
}

void insererM(char entite[], char code[], char type[], float val, char val_string[], int y) {
   int hash = hash_function(entite);

   // Recherche de l'entrée dans la table des symboles
   element* entry = tab[hash];
   while (entry != NULL) {
      if (strcmp(entry->name, entite) == 0) {
         // Entrée trouvée, mise à jour du type
         strcpy(entry->type, type);
         return;
      }
      entry = entry->next;
   }

   // Si l'entrée n'existe pas, elle est insérée dans la table des symboles
   element* new_entry = malloc(sizeof(element));
   strcpy(new_entry->name, entite);
   strcpy(new_entry->code, code);
   strcpy(new_entry->type, type);
   new_entry->val = val;
   strcpy(new_entry->valstring, val_string);
   new_entry->state = 1;

   // Insérer la nouvelle entrée au début de la liste chaînée
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
   printf("-------------------------------------------------------------\n");
   printf("|    Nom    |   Code      |  Type    |  Val  |  Val_String  |\n");
   printf("-------------------------------------------------------------\n");

   for (int i = 0; i < MAX_SIZE; i++) {
      element* entry = tab[i];
      while (entry != NULL) {
         printf("| %-10s | %-11s | %-8s | %-5.2f | %-12s |\n", entry->name, entry->code, entry->type, entry->val, entry->valstring);
         entry = entry->next;
      }
   }

   printf("-----------------------------------------\n");
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





