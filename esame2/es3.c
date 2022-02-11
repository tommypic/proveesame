#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct targa{
        char valore[6];
        struct targa *next;
        } targa;

void controllapermessi(targa *accessi, targa *permessi);
void inseriscielemento(char *stringa, targa *lista);
void stampalista( targa *lista);

int main(){
    targa *accessi = (targa*) malloc(sizeof(targa));
    targa *permessi = (targa*) malloc(sizeof(targa));

    targa *temp = accessi;
    strcpy(temp->valore, "cio445");
    char targhe[][20] = {"cdl239", "cln345","fmv285", "cfg307"};
    for (int i = 0 ; i < 4; i++){
        targa *nodo = (targa*) malloc(sizeof(targa));
        strcpy(nodo->valore, targhe[i]);
        temp->next = nodo;
        if (i == 3){
            nodo->next = NULL;
        }
        else{
            temp = nodo;
        }
    }
    printf("\n\n");


    targa *temp1 = permessi;
    strcpy(temp1->valore, "cio445");
    char targhe1[][20] = {"cdl239", "cfg307"};
    for (int i = 0 ; i < 2; i++){
        targa *nodo = (targa*) malloc(sizeof(targa));
        strcpy(nodo->valore, targhe1[i]);
        temp1->next = nodo;
        if (i == 1){
            nodo->next = NULL;
        }
        else{
            temp1 = nodo;
        }
    }


    printf("\n\n");

    char nuovatarga[] = "chg937";
    inseriscielemento(nuovatarga, accessi);
    printf("lista accessi\n");
    stampalista(accessi);
    printf(" \n\nlista permessi \n");
    stampalista(permessi);
    printf("\n\n");

    controllapermessi(accessi, permessi);
}

void stampalista( targa *lista){
    targa *temp = lista;
    while(temp != NULL){
        printf("%s\n", temp->valore);
        temp = temp->next;
    }
}

void inseriscielemento(char *stringa, targa *lista){
    targa *temp = lista;
    targa *nuovoelemento = (targa*)malloc(sizeof(targa));
    while (temp->next != NULL){
        temp = temp->next;
        }
    temp->next = nuovoelemento;
    strcpy(nuovoelemento->valore, stringa);
    nuovoelemento->next = NULL;
}

void controllapermessi(targa *accessi, targa *permessi){
    targa *temp = accessi;
    targa *temp1 = permessi;
    int flag = 0;
    printf("TARGA   |PERMESSO\n");
    while (temp != NULL){
        printf("%s  |", temp->valore);
        while (temp1 != NULL){
            if (strcmp(temp1->valore, temp->valore) == 0 ){
                flag = 1;
            }
            temp1 = temp1->next;
        }
        if (flag){
            printf("con permesso \n");
        }
        else{
            printf("senza permesso \n");
        }
        temp = temp->next;
        temp1 = permessi;
        flag = 0;
    }
}









