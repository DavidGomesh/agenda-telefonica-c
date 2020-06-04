#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _MAX 7

typedef struct tipo_contato{
    char nome[31], sobrenome[51], telefone[16], endereco[101];
    int idade;
}Contato;

// SUGESTOES DE ALTERACAO:
// - (ok) Mover menu para uma funcao
// - (ok) Melhorar a inicializacao
// - (ok) Mover cadastrar para uma funcao
// - (ok) Mover localizar para uma funcao
// - (ok) Mover listar todos para uma funcao
// - (ok) Mover alterar para uma funcao
// - (ok) Mover excluir para uma funcao
// - (ok) Facilitar alteracao do tamanho da agenda
// - (ok) Criar funcao especialista em buscar um local vazio
// - (ok) Criar uma funcao especialista em localizar contatos
// - (ok) Criar uma funcao especialista em exibir contatos
// - (NOPE) Criar uma funcao especialista em alterar contatos
// - (ok) Criar uma funcao especialista em remover contatos
// - Adicionar funcionalidade de ligar para algum contato e guardar no historico

int mostrarMenuPrincipal();

void inserirDadosTeste(Contato *agenda);

void inicializarAgenda(Contato *agenda);

void cadastrarContato(Contato *agenda);
void localizarContato(Contato *agenda);
void listarTodosContatos(Contato *agenda);
void alterarContato(Contato *agenda);
void excluirContato(Contato *agenda);

int localizarIndiceVazioAgenda(Contato agenda[]);
int localizarIndiceContato(Contato agenda[], char nome[], int inicio);
void exibirContato(Contato contato);
void removerContato(Contato *contato);

int main(){
    int opcao;
    Contato agenda[_MAX];
    inicializarAgenda(agenda);
    inserirDadosTeste(agenda);

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
        removerContato(&agenda[i]);
    }
}

void cadastrarContato(Contato *agenda){
    system("cls");

    int i = localizarIndiceVazioAgenda(agenda);

    printf("======CADASTRAR=====\n");

    if(i == -1){
        printf("Agenda cheia!\n");
        return;
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
    system("cls");
    char nome[31];
    int i, inicio=0, opcao;

    printf("======LOCALIZAR=====\n");
    printf("Informe o nome: ");
    fgets(nome, 31, stdin);

    do{
        i = localizarIndiceContato(agenda, nome, inicio);
        do{
            system("cls");
            printf("======LOCALIZAR=====\n");
            printf("Nome pesquisado: %s", nome);

            if(i==-1){
                printf("\nNenhum contato encontrado!\n");
                return;
            }

            printf("======CONTATO=====\n");
            exibirContato(agenda[i]);
            printf("==================\n\n");
            printf("9 - Proximo\n");
            printf("0 - Voltar\n");
            printf("\nOPCAO: ");
            scanf("%i", &opcao);

            switch(opcao){
                case 9:
                    inicio=i+1;
                    break;

                case 0:
                    break;

                default:
                    printf("Opcao invalida!\n");
                    system("pause");
                    break;
            }
        }while(opcao!=9&&opcao!=0);

    }while(opcao!=0);
}

void listarTodosContatos(Contato *agenda){
    system("cls");
    printf("======LISTAR TODOS=====\n\n");

    for(int i=0; i<_MAX; i++){
        if(strcmp(agenda[i].nome, "")!=0){
            printf("=========CONTATO=======\n");
            exibirContato(agenda[i]);
            printf("=======================\n\n");
        }
    }
}

void alterarContato(Contato *agenda){
    system("cls");
    int i, inicio=0, opcao;
    char nome[31];

    printf("======ALTERAR=====\n");
    printf("Informe um nome: ");
    fgets(nome, 31, stdin);

    do{
        i = localizarIndiceContato(agenda, nome, inicio);
        do{
            system("cls");
            printf("======ALTERAR=====\n");
            printf("Nome pesquisado: %s", nome);

            if(i == -1){
                printf("\nNenhum contato encontrado!\n");
                return;
            }

            printf("======CONTATO=====\n");
            exibirContato(agenda[i]);

            printf("\nO que voce deseja alterar?\n");
            printf("1 - Nome\n");
            printf("2 - Sobrenome\n");
            printf("3 - Idade\n");
            printf("4 - Telefone\n");
            printf("5 - Endereco\n\n");
            printf("9 - Proximo\n");
            printf("0 - Voltar\n");
            printf("\nOPCAO: ");
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

                case 9:
                    inicio = i+1;
                    break;
                
                case 0:
                    break;

                default:
                    printf("Opcao invalida!\n");
            }

        }while((opcao<0||opcao>5)&&opcao!=9);
    }while(opcao!=0);
}

void excluirContato(Contato *agenda){
    system("cls");
    char nome[31];
    int i, inicio=0, opcao;

    printf("======EXCLUIR=====\n");
    printf("Informe um nome: ");
    fgets(nome, 31, stdin);

    do{
        i = localizarIndiceContato(agenda, nome, inicio);

        do{
            system("cls");
            printf("======EXCLUIR=====\n");
            printf("Nome pesquisado: %s", nome);

            if(i==-1){
                printf("\nNenhum contato encontrado!\n");
                return;
            }

            printf("======CONTATO=====\n");
            exibirContato(agenda[i]);

            printf("\nVoce deseja excluir esse contato?\n");
            printf("1 - SIM\n");
            printf("9 - Nao, proximo\n\n");
            printf("0 - Voltar\n");
            printf("\nOPCAO: ");
            scanf("%i", &opcao);

            switch (opcao){
                case 1:
                    removerContato(&agenda[i]);
                    printf("Excluido com sucesso!\n");
                    break;

                case 9:
                    inicio=i+1;
                    break;

                case 0:
                    break;

                default:
                    printf("Opcao invalida!\n");
                    system("pause");
                    break;
            }
        }while((opcao != 1 && opcao != 9)&&opcao!=0);
    }while(opcao!=0&&opcao!=1);
}

int localizarIndiceVazioAgenda(Contato *agenda){
    for(int i=0; i<_MAX; i++){
        if(strcmp(agenda[i].nome, "")==0){
            return i;
        }
    }
    return -1;
}

int localizarIndiceContato(Contato agenda[], char nome[], int inicio){
    for(int i=inicio; i<_MAX; i++){
        if(strcmp(agenda[i].nome, nome)==0){
            return i;
        }
    }
    return -1;
}

void exibirContato(Contato contato){
    printf("Nome: %s", contato.nome);
    printf("Sobrenome: %s", contato.sobrenome);
    printf("Idade: %i\n", contato.idade);
    printf("Telefone: %s", contato.telefone);
    printf("Endereco: %s", contato.endereco);
}

void removerContato(Contato *contato){
    strcpy(contato->nome, "");
    strcpy(contato->sobrenome, "");
    contato->idade = -1;
    strcpy(contato->telefone, "");
    strcpy(contato->endereco, "");
}

void inserirDadosTeste(Contato *agenda){
    strcpy(agenda[0].nome, "David\n\0");
    strcpy(agenda[0].sobrenome, "Gomesh\n\0");
    agenda[0].idade = 19;
    strcpy(agenda[0].telefone, "987654321\n\0");
    strcpy(agenda[0].endereco, "Cohab\n\0");

    strcpy(agenda[1].nome, "Paulo\n\0");
    strcpy(agenda[1].sobrenome, "Roberto\n\0");
    agenda[1].idade = 19;
    strcpy(agenda[1].telefone, "987654322\n\0");
    strcpy(agenda[1].endereco, "Monte Castelo\n\0");

    strcpy(agenda[2].nome, "Julio\n\0");
    strcpy(agenda[2].sobrenome, "Evencio\n\0");
    agenda[2].idade = 19;
    strcpy(agenda[2].telefone, "987654323\n\0");
    strcpy(agenda[2].endereco, "Em algum lugar\n\0");

    strcpy(agenda[3].nome, "Willinielsen\n\0");
    strcpy(agenda[3].sobrenome, "Jackieline\n\0");
    agenda[3].idade = 19;
    strcpy(agenda[3].telefone, "987654324\n\0");
    strcpy(agenda[3].endereco, "Em outro lugar\n\0");

    strcpy(agenda[4].nome, "David\n\0");
    strcpy(agenda[4].sobrenome, "Alysson\n\0");
    agenda[4].idade = 19;
    strcpy(agenda[4].telefone, "987654325\n\0");
    strcpy(agenda[4].endereco, "Angelim\n\0");
}