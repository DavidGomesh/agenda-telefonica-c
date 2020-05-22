#include <stdio.h>

int main(){
    int opcao;

    do{
        printf("=======AGENDA=======\n");
        printf("1 - Cadastrar\n");
        printf("2 - Localizar\n");
        printf("3 - Listar Todos\n");
        printf("4 - Alterar\n");
        printf("5 - Excluir\n");
        printf("0 - Sair\n");
        printf("OPCAO: ");
        scanf("%i", &opcao);

        switch(opcao){
            case 1:
                printf("CADASTAR\n");
                break;
            case 2:
                printf("LOCALIZAR\n");
                break;
            case 3:
                printf("LISTAR TODOS\n");
                break;
            case 4:
                printf("ALTERAR\n");
                break;
            case 5:
                printf("EXCLUIR\n");
                break;
            case 0:
                printf("Obrigado por usar nosso programa!\n");
                break;
            default:
                printf("Opcao invalida!\n");

        }
        system("pause");
        system("cls");
    }while(opcao!=0);

    return 0;
}
