#include <stdio.h>

int main(){
    int carro1, tempo_carro1;
    int carro2, tempo_carro2;
    
    int vencedor, perdedor;

    if(tempo_carro1 > tempo_carro2){
        vencedor = carro1;
        perdedor = carro2;
    }
    else{
        vencedor = carro2;
        perdedor = carro1;
    }
}