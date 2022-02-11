#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valore;
    struct nodo *next;
}nodo;


void stampalista( nodo *lista);
void aggiungivalore(nodo **lista, int valore);
void scambianodi(nodo *nodo1, nodo *nodo2);
void bubblesort(nodo *lista, int lunghezza);


int main(){
    int array[] = {3,4,2,7,4,8,9,10,1};
    int lunghezza = sizeof(array)/sizeof(array[0]);
    nodo *lista = NULL;
    for (int i = 0; i < lunghezza; i++){
        aggiungivalore(&lista, array[i]);
    }
    stampalista(lista);
    bubblesort(lista, lunghezza);
    printf("\n");
    stampalista(lista);
}

void stampalista(nodo *lista){
    while( lista != NULL){
        printf("%d\n", lista->valore);
        lista = lista->next;
    }
}

void aggiungivalore(nodo **lista, int valore){
    nodo *nuovonodo = (nodo*) malloc(sizeof(nodo));
    nodo *ultimonodo = *lista;
    nuovonodo->valore = valore;
    nuovonodo->next = NULL;
    if (*lista == NULL){
        *lista = nuovonodo;
    }
    else{
        while(ultimonodo->next != NULL){
            ultimonodo = ultimonodo->next;
        }
        ultimonodo->next = nuovonodo;
    }

}

void scambianodi(nodo *nodo1, nodo *nodo2){
    int temp = nodo1->valore;
    nodo1->valore = nodo2->valore;
    nodo2->valore = temp;
}

void bubblesort(nodo *lista, int lunghezza){
    nodo *nodo1, *nodo2;
    for( int i = 0; i < lunghezza -1 ; i++){
        nodo1 = lista;
        nodo2 = lista->next;
        for(int j = 0; j < lunghezza -i -1 ; j++){
            if (nodo1->valore > nodo2->valore){
                scambianodi(nodo1, nodo2);    
            }
            nodo1 = nodo1->next;
            nodo2 = nodo2->next;
        }
    }
}



                
                
            






    

