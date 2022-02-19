#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
    int dato;
    struct nodo *next;
}nodo;

void aggiunginodo(nodo **lista, int valore);
void stampalista(nodo *lista);
int lunghezza(nodo *lista);
void bubblesort(nodo *lista);
int sommalista(nodo *lista, int sommatoria);
void eliminanodo(nodo **lista, int nodoelim);
void eliminaval(nodo **lista, int valore);

int main(){
    nodo *lista = NULL;
    int array[] = {1,2,1,1,2,3,4,7,2,7,7};
    int lunghezza = sizeof(array)/ sizeof(array[0]);
    for(int i = 0; i < lunghezza; i++){
        aggiunginodo(&lista, array[i]);
    }
    stampalista(lista);
    eliminaval(&lista, 3);
    printf("\n\n");
    stampalista(lista);

}


void aggiunginodo(nodo **lista, int valore){
    nodo *nuovonodo = (nodo*) malloc(sizeof(nodo));
    nuovonodo->dato = valore;
    nuovonodo->next = NULL;
    if (*lista == NULL){
        *lista = nuovonodo;
    }
    else{
        nodo *temp = *lista;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = nuovonodo;
    }
}

void stampalista(nodo *lista){
    while (lista != NULL){
        printf("%d \n", lista->dato);
        lista = lista->next;
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
    nodo *tempsucc;
    for (int i = 0; i < len -1; i++){
        temp = lista;
        tempsucc = lista->next;
        for (int j = 0; j < len - i -1; j++){
            if (temp->dato < tempsucc->dato){
                int dato = temp->dato;
                temp->dato = tempsucc->dato;
                tempsucc->dato = dato;
            }
            temp = temp->next;
            tempsucc = tempsucc->next;
        }
    }
}

int sommalista(nodo *lista, int sommatoria){
    nodo *temp = lista;
    int sommasuccess = 0;
    sommatoria += temp->dato;
    while(temp != NULL){
        sommasuccess += temp->dato;
        temp = temp->next;
    }
    lista->dato = sommasuccess;
    if(lista->next == NULL){
        return sommatoria;
    }
    else{
        return sommalista(lista->next, sommatoria);
    }
}

void eliminanodo(nodo **lista, int nodoelim){
    nodo *temp = *lista;
    if ((*lista)->dato == nodoelim){
        *lista = (*lista)->next;
        free(temp);
    }
    else{

        while (temp->next->dato != nodoelim){
            temp = temp->next;
        }
        nodo *nodoelima = temp->next;
        temp->next = temp->next->next;
        free(nodoelima);
    }
}




void eliminaval(nodo **lista, int valore){
    nodo *temp = *lista;
    nodo *temp2;
    int ripetizioni = 0;
    while(temp != NULL){
        temp2 = temp;
        while(temp2 != NULL){
            if (temp2->dato == temp->dato){
                ripetizioni++;
            }
            temp2 = temp2->next;
        }
        if (ripetizioni > valore){
            int valorelimi = temp->dato;
            for(int i = 0; i < ripetizioni; i++){
                eliminanodo(lista, valorelimi);
            }
            temp = *lista;
            ripetizioni = 0;
        }
        else{
            ripetizioni = 0;
            temp = temp->next;
        }
    }
}

                
            








    

    


    

