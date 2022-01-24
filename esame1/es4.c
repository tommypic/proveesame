#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void contorllaparola(char matrice[][8],int righe, int colonne, char *lista);

int main(){
    char matrice[3][8] = {"ciao","acacca","ckakak"};
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 8; j++){
            printf("%c", matrice[i][j]); 
        }
        printf("\n");
    }
    char lista[] = "cacca";
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
    

