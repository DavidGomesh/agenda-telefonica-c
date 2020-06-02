#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _MAX 7

typedef struct tipo_contato{
    char nome[31], sobrenome[51], telefone[16], endereco[101];
    int idade;
}Contato;

// SUGESTÕES DE ALTERAÇÃO:
// - (ok) Mover menu para uma função
// - (ok) Melhorar a inicialização
// - (ok) Mover cadastrar para uma função
// - (ok) Mover localizar para uma função
// - (ok) Mover listar todos para uma função
// - (ok) Mover alterar para uma função
// - (ok) Mover excluir para uma função
// - (ok) Facilitar alteração do tamanho da agenda
// - (ok) Criar uma função especialista em localizar contatos
// - (ok) Criar uma função especialista em exibir contatos
// - Criar uma função especialista em alterar contatos
// - Criar uma função especialista em remover contatos
// - Adicionar funcionalidade de ligar para algum contato e guardar no histórico

int mostrarMenuPrincipal();
void inicializarAgenda(Contato *agenda);
void cadastrarContato(Contato *agenda);
void localizarContato(Contato *agenda);
void listarTodosContatos(Contato *agenda);
void alterarContato(Contato *agenda);
void excluirContato(Contato *agenda);

int localizarContatoAtual(Contato agenda[], char nome[]);
void exibirContatoAtual(Contato contato);

int main(){
    int opcao;
    Contato agenda[_MAX];
    // Inicialização da agenda
    inicializarAgenda(agenda);

    do{
        opcao = mostrarMenuPrincipal();

        switch(opcao){
            case 1:
                cadastrarContato(agenda);
                break;

            case 2:
                localizarContato(agenda);
                break;

            case 3:
                listarTodosContatos(agenda);
                break;

            case 4:
                alterarContato(agenda);
                break;

            case 5:
                excluirContato(agenda);
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

int mostrarMenuPrincipal(){
    int opcao;
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
    return opcao;
}

void inicializarAgenda(Contato *agenda){
    for(int i=0; i<_MAX; i++){
        strcpy(agenda[i].nome, ""); //strcpy(destino, origem): vai copiar uma string na outra 
        strcpy(agenda[i].sobrenome, "");
        agenda[i].idade = -1;
        strcpy(agenda[i].telefone, "");
        strcpy(agenda[i].endereco, "");
    }
}

void cadastrarContato(Contato *agenda){
    int i;
    system("cls");
    printf("======CADASTRAR=====\n");                
    for(i=0; i<_MAX; i++){
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
}

void localizarContato(Contato *agenda){
    char nome[31];
    system("cls");
    printf("======LOCALIZAR=====\n");
    printf("Informe o nome: ");
    fgets(nome, 31, stdin);

    for(int i=0; i<5; i++){
        if(strcmp(nome, agenda[i].nome)==0){
            printf("======CONTATO=====\n");
            exibirContatoAtual(agenda[i]);
            printf("==================\n\n");
        }
    }
}

void listarTodosContatos(Contato *agenda){
    system("cls");
    printf("======LISTAR TODOS=====\n\n");

    for(int i=0; i<_MAX; i++){
        if(strcmp(agenda[i].nome, "")!=0){
            printf("=========CONTATO=======\n");
            exibirContatoAtual(agenda[i]);
            printf("=======================\n\n");
        }
    }
}

void alterarContato(Contato *agenda){
    int opcao;
    char nome[31];
    system("cls");
    printf("======ALTERAR=====\n");
    printf("Informe um nome: ");
    fgets(nome, 31, stdin);

    for(int i=0; i<_MAX; i++){
        if(strcmp(agenda[i].nome, nome)==0){
            do{
                system("cls");
                printf("======ALTERAR=====\n");

                exibirContatoAtual(agenda[i]);

                printf("\nO que voce deseja alterar?\n");
                printf("1 - Nome\n");
                printf("2 - Sobrenome\n");
                printf("3 - Idade\n");
                printf("4 - Telefone\n");
                printf("5 - Endereco\n");
                printf("0 - Voltar\n");
                printf("OPCAO: ");
                scanf("%i", &opcao);
                setbuf(stdin, NULL);

                switch (opcao){
                    case 1:
                        printf("Novo Nome: ");
                        fgets(agenda[i].nome, 31, stdin);
                        printf("Alterado com sucesso!\n");
                        break;

                    case 2:
                        printf("Novo Sobrenome: ");
                        fgets(agenda[i].sobrenome, 51, stdin);
                        printf("Alterado com sucesso!\n");
                        break;

                    case 3:
                        printf("Nova Idade: ");
                        scanf("%i", &agenda[i].idade);
                        printf("Alterado com sucesso!\n");
                        break;

                    case 4:
                        printf("Novo Telefone: ");
                        fgets(agenda[i].telefone, 16, stdin);
                        printf("Alterado com sucesso!\n");
                        break;

                    case 5:
                        printf("Novo Endereco: ");
                        fgets(agenda[i].endereco, 101, stdin);
                        printf("Alterado com sucesso!\n");
                        break;

                    case 0:
                        break;

                    default:
                        printf("Opcao invalida!\n");
                }

            }while(opcao!=0);
        }
    }
}

void excluirContato(Contato *agenda){
    int opcao;
    char nome[31];
    system("cls");
    printf("======EXCLUIR=====\n");
    printf("Informe um nome: ");
    fgets(nome, 31, stdin);

    int i = localizarContatoAtual(agenda, nome);
    if(i==-1){
        printf("Contato nao encontrado!\n\n");
        return;
    }
    exibirContatoAtual(agenda[i]);
    printf("\nVoce deseja excluir esse contato?\n");
    printf("1 - SIM\t\t2 - NAO\n");
    printf("OPCAO: ");
    scanf("%i", &opcao);

    switch (opcao){
        case 1:
            strcpy(agenda[i].nome, "");
            strcpy(agenda[i].sobrenome, "");
            agenda[i].idade = -1;
            strcpy(agenda[i].telefone, "");
            strcpy(agenda[i].endereco, "");
            printf("Excluido com sucesso!\n");
            break;

        case 2:
            break;
        
        default:
            printf("Opcao invalida!\n");
            break;
    }
}

int localizarContatoAtual(Contato agenda[], char nome[]){
    for(int i=0; i<_MAX; i++){
        if(strcmp(agenda[i].nome, nome)==0){
            return i;
        }
    }
    
    return -1;
}

void exibirContatoAtual(Contato contato){
    printf("Nome: %s", contato.nome);
    printf("Sobrenome: %s", contato.sobrenome);
    printf("Idade: %i\n", contato.idade);
    printf("Telefone: %s", contato.telefone);
    printf("Endereco: %s", contato.endereco);
}