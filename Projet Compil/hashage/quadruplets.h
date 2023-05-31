#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct quad {
    char* opr;
    char* op1;
    char* op2;
    char* res;
    struct quad* next;
} quad;

struct quadTab
{
	char* opr;
	char* op1;
	char* op2;
	char* res;
};

quad* head = NULL; // Pointeur vers la tête de la liste chaînée
extern int qc; // Compteur de quadruplets

void quadruplet(char opr[], char op1[], char op2[], char res[]) {
    quad* new_quad = (quad*)malloc(sizeof(quad));
    new_quad->opr = strdup(opr);
    new_quad->op1 = strdup(op1);
    new_quad->op2 = strdup(op2);
    new_quad->res = strdup(res);
    new_quad->next = NULL;

    if (head == NULL) {
        head = new_quad;
    } else {
        quad* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_quad;
    }

    qc++;
}

void maj_quad(int num_quad, int colon_quad, char val[]) {
    quad* current = head;
    int i = 0;
    while (current != NULL && i < num_quad) {
        current = current->next;
        i++;
    }

    if (current != NULL) {
        switch (colon_quad) {
            case 0: {
                free(current->opr);
                current->opr = strdup(val);
                break;
            }
            case 1: {
                free(current->op1);
                current->op1 = strdup(val);
                break;
            }
            case 2: {
                free(current->op2);
                current->op2 = strdup(val);
                break;
            }
            case 3: {
                free(current->res);
                current->res = strdup(val);
                break;
            }
        }
    }
}

void afficher_qdr() {
    printf("\n\n*********************Les Quadruplets***********************\n");

    int i = 0;
    quad* current = head;
    while (current != NULL) {
        printf("\n %d - ( %s  ,  %s  ,  %s  ,  %s )", i, current->opr, current->op1, current->op2, current->res);
        printf("\n--------------------------------------------------------\n");
        current = current->next;
        i++;
    }
}

char ope1[12];
char ope2[12];

void ajout_quad_opbinaire(char op, float* opa, float* opb) {
    sprintf(ope1, "%f", *opa);
    sprintf(ope2, "%f", *opb);
    switch (op) {
        case '+': quadruplet("+", ope1, ope2, "<tmporaire>"); break;
        case '-': quadruplet("-", ope1, ope2, "<tmporaire>"); break;
        case '*': quadruplet("*", ope1, ope2, "<tmporaire>"); break;
        case '/': quadruplet("+", ope1, ope2, "<tmporaire>"); break;
    }
}

void ajout_quad_opbinaireIDF(char op, char opa[], float* opb) {
    
    sprintf(ope2, "%f", *opb);
    switch (op) {
        case '+': quadruplet("+", opa, ope2, "<tmporaire>"); break;
        case '-': quadruplet("-", opa, ope2, "<tmporaire>"); break;
        case '*': quadruplet("*", opa, ope2, "<tmporaire>"); break;
        case '/': quadruplet("+", opa, ope2, "<tmporaire>"); break;
    }
}
void ajout_quad_opunaire(float* opb) {
    sprintf(ope2, "%f", *opb);
    quadruplet("-", "0", ope2, "<temporaire>");
}

void ajout_quad_affect_val(char entite[], float* val) {
    sprintf(ope1, "%f", *val);
    quadruplet("=", ope1, "", entite);
}

void ajout_quad_affect_idf(char entite[], char val[]) {
   
    quadruplet("=", val, "", entite);
}

void free_quad_list() {
    quad* current = head;
    while (current != NULL) {
        quad* temp = current;
        current = current->next;
        free(temp->opr);
        free(temp->op1);
        free(temp->op2);
        free(temp->res);
        free(temp);
    }
    head = NULL;
    qc = 0;
}


struct quadTab* convertToArray(quad* quadList) {
    // Determine the size of the linked list
    int size = 0;
    quad* currentQuad = quadList;
    while (currentQuad != NULL) {
        size++;
        currentQuad = currentQuad->next;
    }

    // Allocate memory for the array
    struct quadTab* array = malloc(size * sizeof(struct quadTab));
    if (array == NULL) {
        // Error handling for memory allocation failure
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }

    // Traverse the linked list and copy the values to the array
    currentQuad = quadList;
    for (int i = 0; i < size; i++) {
        array[i].opr = strdup(currentQuad->opr);
        array[i].op1 = strdup(currentQuad->op1);
        array[i].op2 = strdup(currentQuad->op2);
        array[i].res = strdup(currentQuad->res);
        currentQuad = currentQuad->next;
    }
     return array;
    }
