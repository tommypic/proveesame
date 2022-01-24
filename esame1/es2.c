#include <stdio.h>
#include <string.h>

int contanumeri(char * stringa, int posizione);

int main(){
    char stringa[] = "caca4ci56l";
    printf("%d \n ", contanumeri(stringa, 0));
}

int contanumeri(char * stringa, int posizione){
    if (stringa[posizione] == '\0'){
        return 0;
    }
    for( int i = 0; i != 10; i++){
        if (stringa[posizione] == (char)i + '0'){
            return 1 + contanumeri(stringa, posizione + 1);
        }
    }        
    return contanumeri(stringa, posizione + 1);
}

