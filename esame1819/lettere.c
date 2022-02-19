#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct{
        char valore;
        int contatore;
        } lettera;

int main(){
    FILE *fp = fopen("lettere.txt", "r");
    char alfabeto[] = "qwertyuiopasdfghjklzxcvbnm";
    lettera alfabetostr[26];
    for(int i = 0; i < 26; i++){
        alfabetostr[i].valore = alfabeto[i];
        alfabetostr[i].contatore = 0;
    }
    while(feof(fp) == 0){
        char lettera;
        fscanf(fp, "%c",&lettera); 
        for(int i = 0; i < 26; i++){
            if(lettera == alfabetostr[i].valore){
                (alfabetostr[i].contatore)++;
            }
        }
    }
    for(int i = 0; i < 26; i++){
        printf("%c %d \n", alfabetostr[i].valore, alfabetostr[i].contatore);
    }
}

        



