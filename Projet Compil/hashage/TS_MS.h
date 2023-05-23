/****************CREATION DE LA TABLE DES SYMBOLES ******************/
/***Step 1: Definition des structures de données ***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
#define MAX_SIZE 1000
#define HASH_SIZE 40

// Structure for keyword and separator entries
typedef struct elt {
   char name[20];
   int state;
   struct elt* next;
} elt;


// Hash tables for keywords and separators
elt* tabs[HASH_SIZE];
elt* tabm[HASH_SIZE];

int cpt, cpts, cptm;

// Hash function for keywords and separators
int hash_function_keywords(char* key) {
   int hash = 0;
   int i = 0;

   while (key[i] != '\0') {
      hash += key[i];
      i++;
   }

   return hash % HASH_SIZE;
}

void initialisation1() {
   int i;


   for (i = 0; i < HASH_SIZE; i++) {
      tabs[i] = NULL;
      tabm[i] = NULL;
   }

   cpt = 0;
   cpts = 0;
   cptm = 0;
}


void inserer_keywords(char entite[]) {
   elt* new_entry = malloc(sizeof(elt));
   strcpy(new_entry->name, entite);
   new_entry->state = 1;

   int hash = hash_function_keywords(entite);

   // Check if the entry already exists
   elt* entry = tabs[hash];
   while (entry != NULL) {
      if (strcmp(entry->name, entite) == 0) {
         // Entry already exists, free the new entry and return
         free(new_entry);
         return;
      }
      entry = entry->next;
   }

   // Insert the new entry at the beginning of the linked list
   new_entry->next = tabs[hash];
   tabs[hash] = new_entry;

   cpts++;
}

// Insertion into the separator table
void inserer_separators(char entite[]) {
   elt* new_entry = malloc(sizeof(elt));
   strcpy(new_entry->name, entite);
   new_entry->state = 1;
   int hash = hash_function_keywords(entite);

   // Check if the entry already exists
   elt* entry = tabm[hash];
   while (entry != NULL) {
      if (strcmp(entry->name, entite) == 0) {
         // Entry already exists, update the type
         free(new_entry);
         return;
      }
      entry = entry->next;
   }

   // Insert the new entry at the beginning of the linked list
   new_entry->next = tabm[hash];
   tabm[hash] = new_entry;

   cptm++;
}

// Affichage de la table des mots-clés
void afficher_table_keywords() {
   printf("Table des mots-cles :\n");
   printf("---------------------\n");
   printf("|    Nom    |   Type  |\n");
   printf("---------------------\n");

   for (int i = 0; i < MAX; i++) {
      elt* entry = tabs[i];
      while (entry != NULL) {
         printf("| %-9s | %-6s |\n", entry->name, "mot cle");
         entry = entry->next;
      }
   }

   printf("---------------------\n");
}
// Affichage de la table des séparateurs
void afficher_table_separators() {
   printf("Table des séparateurs :\n");
   printf("------------------------\n");
   printf("|    Nom    |   Type  |\n");
   printf("------------------------\n");

   for (int i = 0; i < HASH_SIZE; i++) {
      elt* entry = tabm[i];
      while (entry != NULL) {
         printf("| %-9s | %-9s |\n", entry->name, "Separateur");
         entry = entry->next;
      }
   }

   printf("------------------------\n");
}
