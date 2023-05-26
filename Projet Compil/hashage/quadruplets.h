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

void ajout_quad_opunaire(float* opb) {
    sprintf(ope2, "%f", *opb);
    quadruplet("-", "0", ope2, "<temporaire>");
}

void ajout_quad_affect_val(char entite[], float* val) {
    sprintf(ope1, "%f", *val);
    quadruplet("=", ope1, "", entite);
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

