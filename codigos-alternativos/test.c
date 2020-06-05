#include <stdio.h>

int main(){
    FILE *arquivo = fopen("bancodedados.txt", "r");
    char texto[50];
    fgets(texto, 50, arquivo);
    printf("%s\n", texto);
}