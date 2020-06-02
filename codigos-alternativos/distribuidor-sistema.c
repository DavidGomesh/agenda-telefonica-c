#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gerarNumeroAleatorio();
int numeroRepetido(int num, int *listaNum);

int main(){
    int num, numDev[5]={0,0,0,0,0};
    srand(time(NULL));
    for(int i=0; i<5; i++){
        num = gerarNumeroAleatorio();
        while(numeroRepetido(num, numDev) == 1){
            num = gerarNumeroAleatorio();
        }
        numDev[i]=num;
    }

    for(int i=0; i<5; i++){
        printf("%i\n", numDev[i]);
    }
    return 0;
}

int gerarNumeroAleatorio(){
    int numAleatorio;
    numAleatorio = 1 + rand() % 5;
    return numAleatorio;
}

int numeroRepetido(int num, int *listaNum){
    for(int i=0; i<5; i++){
        if(listaNum[i]==num){
            return 1;
        }
    }
    return 0;
}