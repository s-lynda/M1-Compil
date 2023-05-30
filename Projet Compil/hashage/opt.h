#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "TS_hash.h"
#include "quadruplets.h"

void freeQuad(quad* q)
{
    free(q->opr);
    free(q->op1);
    free(q->op2);
    free(q->res);
    free(q);
}
void removeUnusedQuads()
{
    quad* current = head;
    quad* previous = NULL;
    while (current != NULL)
    {
        if (strcmp(current->opr, "") == 0)
        {
            if (previous == NULL)
            {
                head = current->next;
                freeQuad(current);
                current = head;
            }
            else
            {
                previous->next = current->next;
                freeQuad(current);
                current = previous->next;
            }
            qc--;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }
}

void chekPropCopie(quad* q)
{
    quad* current = q;
    while (current != NULL)
    {
        if (current->opr[0] == '=')
        {
            quad* innerCurrent = current->next;
            while (innerCurrent != NULL)
            {
                if (strcmp(current->op1, innerCurrent->res) == 0 || strcmp(current->res, innerCurrent->res) == 0)
                    break;
                if (innerCurrent->opr[0] == '+' || innerCurrent->opr[0] == '*' || innerCurrent->opr[0] == '-' || innerCurrent->opr[0] == '/' || innerCurrent->opr[0] == '^')
                {
                    if (strcmp(current->res, innerCurrent->op1) == 0)
                    {
                        innerCurrent->op1 = strdup(current->op1);
                        freeQuad(current);
                        current->opr = strdup("");
                        current->op1 = strdup("");
                        current->op2 = strdup("");
                        current->res = strdup("");
                    }
                    else if (strcmp(current->res, innerCurrent->op2) == 0)
                    {
                        innerCurrent->op2 = strdup(current->op1);
                        freeQuad(current);
                        current->opr = strdup("");
                        current->op1 = strdup("");
                        current->op2 = strdup("");
                        current->res = strdup("");
                    }
                }
                innerCurrent = innerCurrent->next;
            }
        }
        current = current->next;
    }
}

void checkX2(quad* q)
{
    quad* current = q;
    while (current != NULL)
    {
        if (current->opr[0] == '*')
        {
            if (current->op1[0] == '2')
            {
                current->opr = strdup("+");
                current->op1 = strdup(current->op2);
                current->op2 = strdup(current->op2);
            }
            else if (current->op2[0] == '2')
            {
                current->opr = strdup("+");
                current->op1 = strdup(current->op1);
                current->op2 = strdup(current->op1);
            }
        }
        current = current->next;
    }
}



void optimisation()
{
    checkX2(head);
    //checkPow(head);
   // checkVarUse(listesymbol, head);
    chekPropCopie(head);
    removeUnusedQuads();
}

/*


void checkPow(quad* q)
{
    quad* current = q;
    while (current != NULL)
    {
        if (current->opr[0] == '^')
        {
            if (current->op1[0] == '2')
            {
                current->opr = strdup("*");
                current->op1 = strdup(current->op2);
                current->op2 = strdup(current->op2);
            }
            else if (current->op2[0] == '2')
            {
                current->opr = strdup("*");
                current->op1 = strdup(current->op1);
                current->op2 = strdup(current->op1);
            }
        }
        current = current->next;
    }
}

void checkVarUse(TS_hash ls, quad* q)
{
    int bol = 0;
    int i = 0;
    for (i = 0; i < 7; i++)
    {
        if ((ls[i]).svt != NULL)
        {
            ts p = (ls[i]).svt;
            for (p; p != NULL; p = p->svt)
            {
                bol = 0;
                int k = 0;
                quad* current = q;
                while (current != NULL)
                {
                    if (strcmp(current->op1, p->nom) == 0 || strcmp(current->op2, p->nom) == 0 || strcmp(current->res, p->nom) == 0)
                    {
                        bol = 1;
                        break;
                    }
                    current = current->next;
                }
                if (bol == 0)
                {
                    printf("!!! Warning : IDF ( %s ) declared but not used\n", p->nom);
                }
            }
        }
    }
}

void chekPropCopie(quad* q)
{
    quad* current = q;
    while (current != NULL)
    {
        if (current->opr[0] == '=')
        {
            quad* innerCurrent = current->next;
            while (innerCurrent != NULL)
            {
                if (strcmp(current->op1, innerCurrent->res) == 0 || strcmp(current->res, innerCurrent->res) == 0)
                    break;
                if (innerCurrent->opr[0] == '+' || innerCurrent->opr[0] == '*' || innerCurrent->opr[0] == '-' || innerCurrent->opr[0] == '/' || innerCurrent->opr[0] == '^')
                {
                    if (strcmp(current->res, innerCurrent->op1) == 0)
                    {
                        innerCurrent->op1 = strdup(current->op1);
                        freeQuad(current);
                        current->opr = strdup("");
                        current->op1 = strdup("");
                        current->op2 = strdup("");
                        current->res = strdup("");
                    }
                    else if (strcmp(current->res, innerCurrent->op2) == 0)
                    {
                        innerCurrent->op2 = strdup(current->op1);
                        freeQuad(current);
                        current->opr = strdup("");
                        current->op1 = strdup("");
                        current->op2 = strdup("");
                        current->res = strdup("");
                    }
                }
                innerCurrent = innerCurrent->next;
            }
        }
        current = current->next;
    }
}
*/