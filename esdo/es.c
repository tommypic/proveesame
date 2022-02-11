#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *eliminaripetizioni(char *array);
int main(){
    FILE *sbaglilato = fopen("errori.txt", "r");
    FILE *giusto = fopen("giusto.txt", "w");
    char stringa[15];
    while (feof(sbaglilato) == 0){
        fscanf(sbaglilato, "%s", stringa);
        char *risultato = eliminaripetizioni(stringa);
        fprintf(giusto,"%s \n", risultato);
    }
    fclose(giusto);
    fclose(sbaglilato);
}

char *eliminaripetizioni(char *array){
    int lunghezza = strlen(array);
    char *risultato = malloc(sizeof(char)*15);
    for(int i = 0, j = 0; i < lunghezza; i++){
        if (array[i+1] != array [i+2] || array[i] != array[i+1] ){
            risultato[j] = array[i];
            j++;
        }
        else{
            int ripeti = 0;
            while(array[ripeti + i] == array[i]){
                ripeti++;
            }
            i += ripeti -3;
        }
    }
    return risultato;
}



        


        

