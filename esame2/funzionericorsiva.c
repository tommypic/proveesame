#include <stdio.h>
#include <string.h>

int contanegativi(int array[], int val, int posizione, int numeronegativi);
int contanumer(int val1, int val2, int numero, int somma);

int main(){
    int array[] = {1,2,3,-3,-5,4,-6,3};
    printf("%d  %d", contanegativi(array, 3, 8,0), contanumer(5,10,0,0));
}


int contanegativi(int array[], int val, int posizione, int numeronegativi){
    if (array[posizione] == '\0'){
        if (numeronegativi > val){
            return 1;
        }
        else{
            return 0;
        }
    }
    if (array[posizione] < 0){
        return contanegativi(array, val, posizione - 1, numeronegativi +1);
    }
    else{
        return contanegativi(array, val, posizione - 1, numeronegativi );
    }
}


 int contanumer(int val1, int val2, int numero, int somma){
    int max;
    int min;

    if (val1 > val2 ){
        val1 = max;
        val2 = min;
    }
    if (val1 < val2){
        val1 = min;
        val2 = max;
    }
    if (numero == max - min){
        return somma;
    }
    if (numero != max - min){
        contanumer(val1, val2, numero +1, somma +(numero + min));
    }
 }
      
