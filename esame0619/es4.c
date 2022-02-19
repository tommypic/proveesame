#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *calcolaoccorrenze(char *stringa, char *stringa1);

int main(){
    char stringa[] = "ment";
    char stringa1[] = "fondamentalmente";
    char *stringaaa = calcolaoccorrenze(stringa, stringa1);
    printf("%s", stringaaa);
}

char *calcolaoccorrenze(char *stringa, char *stringona){
    int len = strlen(stringa);
    int lunghezza = strlen(stringona);
    int occorenze = 0;
    char *risultato = (char *)malloc(sizeof(char)*lunghezza);
    for (int i = 0; i < lunghezza; i++){
        if (strncmp(stringa, &stringona[i], len) == 0){
            for(int j = 0; j < len; j++){
                risultato[i+j] = '+';
            }
            i += len - 1;
        }
        else{
            risultato[i] = stringona[i];
        }
    }
    return risultato;
}










