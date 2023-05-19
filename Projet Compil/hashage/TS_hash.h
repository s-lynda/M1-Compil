/****************CREATION DE LA TABLE DES SYMBOLES ******************/
/***Step 1: Definition des structures de données ***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

// Structure for keyword and separator entries
typedef struct elt {
   char name[20];
   int state;
   struct elt* next;
} elt;

// Hash table for IDF and constant entries
element* tab[MAX_SIZE];

// Hash tables for keywords and separators
elt* tabs[HASH_SIZE];
elt* tabm[HASH_SIZE];

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


/***Step 2: Initialisation de l'état des cases des tables des symboles***/
/*0: la case est libre    1: la case est occupée*/

void initialisation() {
   int i;

   // Initialize state to 0 in all tables
   for (i = 0; i < MAX_SIZE; i++) {
      tab[i] = NULL;
   }

   for (i = 0; i < HASH_SIZE; i++) {
      tabs[i] = NULL;
      tabm[i] = NULL;
   }

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



/***Step 5: Recherche d'une entité dans les tables des symboles ***/
int rechercher(char entite[], char code[], char type[])
{
   int hash = hash_function(entite);

   // Search in the IDF and constant table
   element* entry = tab[hash];
   while (entry != NULL)
   {
      if (strcmp(entry->name, entite) == 0)
      {
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
   while (entry_kw != NULL)
   {
      if (strcmp(entry_kw->name, entite) == 0)
      {
         // Entry found, update the type
        
         strcpy(code, "");
         return 1;
      }
      entry_kw = entry_kw->next;
   }

   // Search in the separator table
   hash = hash_function_keywords(entite);
   elt* entry_sep = tabm[hash];
   while (entry_sep != NULL)
   {
      if (strcmp(entry_sep->name, entite) == 0)
      {
         // Entry found, update the type
       
         strcpy(code, "");
         return 1;
      }
      entry_sep = entry_sep->next;
   }

   return 0;
}

// Affichage de la table des IDF et des constantes
void afficher_table_idf()
{
   printf("Table des IDF et des constantes :\n");
   printf("------------------------------\n");
   printf("|    Nom    |   Code   |  Type  |\n");
   printf("------------------------------\n");

   for (int i = 0; i < MAX; i++)
   {
      element* entry = tab[i];
      while (entry != NULL)
      {
         printf("| %-9s | %-8s | %-6s |\n", entry->name, entry->code, entry->type);
         entry = entry->next;
      }
   }

   printf("------------------------------\n");
}

// Affichage de la table des mots-clés
void afficher_table_keywords()
{
   printf("Table des mots-clés :\n");
   printf("---------------------\n");
   printf("|    Nom    |   Type  |\n");
   printf("---------------------\n");

   for (int i = 0; i < MAX; i++)
   {
      elt* entry = tabs[i];
      while (entry != NULL)
      {
         printf("| %-9s | %-6s |\n", entry->name, "mot cle");
         entry = entry->next;
      }
   }

   printf("---------------------\n");
}


// Affichage de la table des séparateurs
void afficher_table_separators()
{
   printf("Table des séparateurs :\n");
   printf("------------------------\n");
   printf("|    Nom    |   Type  |\n");
   printf("------------------------\n");

   for (int i = 0; i < HASH_SIZE; i++)
   {
      elt* entry = tabm[i];
      while (entry != NULL)
      {
         printf("| %-9s | %-9s |\n", entry->name, "Separateur");
         entry = entry->next;
      }
   }

   printf("------------------------\n");
}


void afficher()
{
// Afficher les tables des symboles
afficher_table_idf();
afficher_table_separators();
afficher_table_keywords();
}