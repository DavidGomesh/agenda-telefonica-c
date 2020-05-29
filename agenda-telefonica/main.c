#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    typedef struct tipo_contato{
        char nome[31], sobrenome[51], telefone[16], endereco[101];
        int idade;
    }Contato;

    int opcao, i;
    Contato agenda[5];

    char nome[31];

    // Inicialização da agenda
    for(i=0; i<5; i++){
        strcpy(agenda[i].nome, ""); //strcpy(destino, origem): vai copiar uma string na outra 
    }

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
        setbuf(stdin, NULL);

        switch(opcao){
            case 1:
                system("cls");
                printf("======CADASTRAR=====\n");                
                for(i=0; i<5; i++){
                    if(strcmp(agenda[i].nome, "")==0){ //strcmp(string1, string2) compara a string1 com a string 2
                        break;
                    }
                }

                printf("Nome: ");
                fgets(agenda[i].nome, 31, stdin);

                printf("Sobrenome: ");
                fgets(agenda[i].sobrenome, 51, stdin);

                printf("Idade: ");
                scanf("%i", &agenda[i].idade);
                setbuf(stdin, NULL);

                printf("Telefone: ");
                fgets(agenda[i].telefone, 16, stdin);

                printf("Endereco: ");
                fgets(agenda[i].endereco, 101, stdin);

                break;

            case 2:
                system("cls");
                printf("======LOCALIZAR=====\n\n");
                printf("Informe o nome: ");
                fgets(nome, 31, stdin);

                for(i=0; i<5; i++){
                    if(strcmp(nome, agenda[i].nome)==0){
                        printf("======CONTATO=====\n");
                        printf("Nome: %s", agenda[i].nome);
                        printf("Sobrenome: %s", agenda[i].sobrenome);
                        printf("Idade: %i\n", agenda[i].idade);
                        printf("Telefone: %s", agenda[i].telefone);
                        printf("Endereco: %s", agenda[i].endereco);
                        printf("==================\n\n");
                    }
                }
                break;

            case 3:
                system("cls");
                printf("======LISTAR TODOS=====\n\n");

                for(i=0; i<5; i++){
                    if(strcmp(agenda[i].nome, "")!=0){
                        printf("=========CONTATO=======\n");
                        printf("Nome: %s", agenda[i].nome);
                        printf("Sobrenome: %s", agenda[i].sobrenome);
                        printf("Idade: %i\n", agenda[i].idade);
                        printf("Telefone: %s", agenda[i].telefone);
                        printf("Endereco: %s", agenda[i].endereco);
                        printf("=======================\n\n");
                    }
                }
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
