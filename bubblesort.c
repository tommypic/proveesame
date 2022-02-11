#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valore;
    struct nodo *next;
}nodo;


int bubblesort(nodo *lista, int lunghezza);
void stampalista( nodo *lista);
void aggiungivalore(nodo *lista, int valore);


int main(){
    int array[] = {3,4,2,7,4,8,9,10,1};
    int lunghezza = sizeof(array)/sizeof(array[0]);
    nodo *lista = NULL;
    printf("cioa");
    for (int i = 0; i < lunghezza; i++){
        aggiungivalore(lista, array[i]);
    }
    stampalista(lista);
}

void stampalista(nodo *lista){
    while( lista != NULL){
        printf("%d\n", lista->valore);
        lista = lista->next;
    }
}

void aggiungivalore(nodo *lista, int valore){
    nodo *nuovonodo = (nodo*) malloc(sizeof(nodo));
    nuovonodo->valore = valore;
    nuovonodo->next = lista;
    lista = nuovonodo;
}








    

