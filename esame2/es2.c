#include <stdio.h>
#include <string.h>

void stamparicorsiva( char *stringa, int lunghezza);

int main(){
    char stringa[] = "cioa";
    stamparicorsiva(stringa, 4);
}

void stamparicorsiva(char *stringa, int lunghezza){
    if (lunghezza >= 0 ){
        printf("%c", stringa[lunghezza -1]);
        stamparicorsiva(stringa, lunghezza - 1);
        }
}




