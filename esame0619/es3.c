#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int controllaidentica(int matrice[3][3], int posizione);

int main(){
    int matrice[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    if (controllaidentica(matrice, 0)){
        printf("matrice idendica");
    }
}


int controllaidentica(int matrice[3][3], int posizione){
    int dimensione = sizeof(matrice[0])/sizeof(matrice[0][0]);
    if (posizione == dimensione-1){
        return 1;
    }
    for(int i = 0; i < dimensione; i++){
        if(i == posizione && matrice[posizione][i] != 1){
            return 0;
        }
        if(i != posizione && matrice[posizione][i] != 0){
            return 0;
        }
    }
    return controllaidentica(matrice, posizione +1);
}



