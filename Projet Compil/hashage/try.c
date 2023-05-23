#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Structure pour le noeud de la table de hachage
typedef struct Node {
    char* key;
    int value;
    struct Node* next;
} Node;

// Structure pour la table de hachage
typedef struct HashTable {
    Node** buckets;
} HashTable;

// Fonction de hachage simple pour générer un index de tableau à partir de la clé
unsigned int hash(const char* key) {
    unsigned int hash_value = 0;
    unsigned int i = 0;
    while (key[i] != '\0') {
        hash_value += key[i];
        i++;
    }
    return hash_value % TABLE_SIZE;
}

// Fonction pour créer un nouveau noeud
Node* createNode(const char* key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Fonction pour initialiser la table de hachage
HashTable* createHashTable() {
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    hashTable->buckets = (Node**)calloc(TABLE_SIZE, sizeof(Node*));
    return hashTable;
}

// Fonction pour insérer une clé et une valeur dans la table de hachage
void insert(HashTable* hashTable, const char* key, int value) {
    unsigned int index = hash(key);

    Node* newNode = createNode(key, value);

    if (hashTable->buckets[index] == NULL) {
        // Si le bucket est vide, insérez simplement le nouveau nœud
        hashTable->buckets[index] = newNode;
    } else {
        // Si le bucket n'est pas vide, ajoutez le nouveau nœud à la fin de la liste chaînée
        Node* currentNode = hashTable->buckets[index];
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

// Fonction pour récupérer la valeur associée à une clé
int get(HashTable* hashTable, const char* key) {
    unsigned int index = hash(key);

    Node* currentNode = hashTable->buckets[index];
    while (currentNode != NULL) {
        if (strcmp(currentNode->key, key) == 0) {
            return currentNode->value;
        }
        currentNode = currentNode->next;
    }

    return -1;  // Valeur par défaut si la clé n'est pas trouvée
}

// Fonction pour libérer la mémoire allouée par la table de hachage
void freeHashTable(HashTable* hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* currentNode = hashTable->buckets[i];
        while (currentNode != NULL) {
            Node* nextNode = currentNode->next;
            free(currentNode->key);
            free(currentNode);
            currentNode = nextNode;
        }
    }
    free(hashTable->buckets);
    free(hashTable);
}
void printHashTable(HashTable* hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Bucket %d: ", i);
        Node* currentNode = hashTable->buckets[i];
        while (currentNode != NULL) {
            printf("(%s, %d) ", currentNode->key, currentNode->value);
            currentNode = currentNode->next;
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    HashTable* hashTable = createHashTable();

    // Generate random key-value pairs and populate the hash table
    for (int i = 0; i <10; i++) {
        char key[10];
        sprintf(key, "clé%d", i);
        int value = rand() % 100;
        insert(hashTable, key, value);
    }

    printf("Initial hash table:\n");
    printHashTable(hashTable);
    printf("\n");

    // Modify a specific value
    const char* keyToModify = "clé3";
    int newValue = 50;
    unsigned int index = hash(keyToModify);

    Node* currentNode = hashTable->buckets[index];
    while (currentNode != NULL) {
        if (strcmp(currentNode->key, keyToModify) == 0) {
            currentNode->value = newValue;
            break;
        }
        currentNode = currentNode->next;
    }

    printf("Updated hash table:\n");
    printHashTable(hashTable);

    freeHashTable(hashTable);

    return 0;
}