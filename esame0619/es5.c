#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int calcolanum(FILE *file);
int media(int *numeri);

int main(){
    FILE *file = fopen("es5.txt", "r");
    int numeri[10];
    int i = 0;
    while(feof(file) == 0){
        numeri[i] = calcolanum(file);
        i++;
    }
    int *numerii = malloc(sizeof(int)*i);
    
    int mediaa = media(numeri);
    printf("%d", mediaa);
}

int calcolanum(FILE *file){
    char numeri[10][10] = {"zero","uno","due","tre","quattro","cinque","sei","sette","otto","nove"};
    char  numero[10];
    char risultato[10];
    int posizione = 0;
    fscanf(file, "%s", numero);
    while(strcmp(numero, "***") != 0){
        for(int i = 0; i < 10; i++){
            if (strcmp(numeri[i], numero) == 0){
                risultato[posizione] =i + '0';
                posizione++;
            }
        }
        fscanf(file, "%s", numero);
    }
    
    int risultato1 = atoi(risultato);
    return risultato1;
}

int media(int *numeri){
    int len = sizeof(numeri);
    int somma = 0;
    for(int i = 0; i < len; i++){
        somma += numeri[i];
    }
    int media = somma/len;
    return media;
}







    
