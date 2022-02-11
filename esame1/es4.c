#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void contorllaparola(char matrice[][8],int righe, int colonne, char *lista);

int main(){
    char lista[] = "ciao";
    char matrice[50][8];
    FILE *file = fopen("es4.txt","r");
    for(int i = 0; feof(file) == 0; i++){
        char riga[50];
        fgets(riga, 50, file);
        strcpy(matrice[i], riga);
    }
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            printf("%c", matrice[i][j]);
        }
    }


    contorllaparola(matrice, 3,8, lista);
}

void contorllaparola(char matrice[][8],int righe, int colonne, char *lista){
    //cotrollo sulle righe
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne - strlen(lista);j++){
            if (strcmp(&matrice[i][j], lista) == 0){
                printf("%s", matrice[i]);
            }
        }
    }
}
    

