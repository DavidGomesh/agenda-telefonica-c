#include <stdio.h>

int main(){
    FILE *arquivo;
    arquivo = fopen("bancodedados.txt", "w");
    fprintf(arquivo, "Julio Evencio é bonito!");
    fclose(arquivo);
}