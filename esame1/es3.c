#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
    int valore;
    struct nodo *next;
} nodo;

void crealista(int *array, nodo *lista , int lunghezza);
void stampalista(nodo *lista);
void controllasottosequenze(nodo *lista, int valore);

int main(){
    nodo *lista = (nodo*) malloc(sizeof(nodo));
    int arr[] = {1,4,7,2,5,32};
    crealista( arr, lista,6);
    stampalista(lista);
    controllasottosequenze(lista, 8);
}

void crealista(int *array, nodo *lista, int lunghezza){
    nodo *temp = lista;
    for(int i = 0; i < lunghezza -1; i++){
        nodo *nuovonodo = malloc(sizeof(nodo));
        temp->valore = array[i];
        temp->next = nuovonodo;
        temp = nuovonodo; 
    }
    temp->valore = array[5];
    temp->next = NULL;

}
void stampalista(nodo *lista){
    while (lista != NULL){
        printf("%d  ", lista->valore);
        lista = lista->next;
    }
}

void controllasottosequenze(nodo *lista, int valore){
    nodo *temp = lista;
    nodo *temp2;
    int sommavalori = 0;
    while( temp != NULL){
        if (temp->valore < valore){
            sommavalori += temp->valore;
            temp2 = temp;
            while (sommavalori < valore){
                printf("%d, ", temp2->valore);
                temp2 = temp2->next;
                sommavalori += temp2->valore;
            } 
        }
        printf("\n");
        sommavalori = 0;
        temp = temp->next;
    }
}





