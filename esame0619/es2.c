#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
    int valore;
    struct nodo *next;
}nodo;

typedef struct nodo2{
    int valore;
    int frequenza;
    struct nodo2 *next;
}nodo2;

void stampalista(nodo *lista);
void stampalista2(nodo2 *lista);
void aggiungival(nodo **lista, int valore);
void aggiungival2(nodo2 **lista, int valore, int frequenza);
int lunghezza(nodo *lista);
void bubblesort(nodo *lista);
nodo2 *nuoval(nodo *lista);

int main(){
    nodo *lista = NULL;
    int array[] = {2,0,3,2,0,3,121,18,0};
    for(int i; i < sizeof(array)/sizeof(array[0]); i++){
       aggiungival(&lista, array[i]);
    }
    stampalista(lista);
    bubblesort(lista);
    printf("\n\n");
    stampalista(lista);
    nodo2 *lista2 = nuoval(lista);
    stampalista2(lista2);


}

void stampalista(nodo *lista){
    while(lista != NULL){
        printf("%d\n", lista->valore);
        lista = lista->next;
    }
}

void stampalista2(nodo2 *lista){
    printf("valore  |frequenza \n");
    while(lista != NULL){
        printf("%d       |%d\n", lista->valore, lista->frequenza);
        lista = lista->next;
    }
}

void aggiungival(nodo **lista, int valore){
    nodo *nuovonodo = (nodo *) malloc(sizeof(nodo));
    nuovonodo->valore = valore;
    nuovonodo->next = NULL;
    nodo *temp = *lista;
    if (temp == NULL){
        *lista = nuovonodo;
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = nuovonodo;
    }
}

void aggiungival2(nodo2 **lista, int valore, int frequenza){
    nodo2 *nuovonodo = (nodo2*)malloc(sizeof(nodo2));
    nuovonodo->next = NULL;
    nuovonodo->frequenza = frequenza;
    nuovonodo->valore = valore;
    if(*lista == NULL){
        *lista = nuovonodo;
    }
    else{
        nodo2 *temp = *lista;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = nuovonodo;
    }
}


int lunghezza(nodo *lista){
    int len;
    while(lista != NULL){
        len++;
        lista = lista->next;
    }
    return len;
}

void bubblesort(nodo *lista){
    int len = lunghezza(lista);
    nodo *temp;
    nodo *temp2;
    for(int i = 0; i < len -1; i++){
        temp = lista;
        temp2 = temp->next;
        for( int j = 0; j < len - i - 1; j++){
            if (temp->valore > temp2->valore){
                int nuovo = temp->valore;
                temp->valore = temp2->valore;
                temp2->valore = nuovo;
            }
            temp = temp->next;
            temp2 = temp2->next;
        }
    }
}

        
nodo2 *nuoval(nodo *lista){
    nodo2 *nuovalista = NULL;
    nodo *temp = lista;
    int ripetizioni = 1;
    while(temp != NULL){
        while(temp->next != NULL && temp->valore == temp->next->valore){
            ripetizioni++;
            temp = temp->next;
        }
        aggiungival2(&nuovalista, temp->valore, ripetizioni);
        ripetizioni = 1;
        temp = temp->next;
    }
    return nuovalista;
}


        


    






