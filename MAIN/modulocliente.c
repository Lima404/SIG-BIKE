#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "modulocliente.h"

void menuprincipalcliente(char esc)
{
    do {
        esc = menu_usuario();
        switch (esc) {
        case '1':
            cadastro_usuario();
            break;
        case '2':
            lista_usuario();
            break; 
        case '3':
            apagar_usuario();
            break;
        case '4':
            editar_usuario();
            break;
        case '5':
            procurar_usuario();
            break;
        default:
            printf ("Opção Inválida\n");
            break;
    }

    } while(esc != '0');
}


char menu_usuario(void){
    char op;

    system("clear||cls");
    printf("\n");
    printf("=====================================================\n");
    printf("=====================================================\n");
    printf("-----------------------------------------------------\n");
    printf("░██████╗██╗░██████╗░░░░░░░██████╗░██╗██╗░░██╗███████╗\n");
    printf("██╔════╝██║██╔════╝░░░░░░░██╔══██╗██║██║░██╔╝██╔════╝\n");
    printf("╚█████╗░██║██║░░██╗░█████╗██████╦╝██║█████═╝░█████╗░░\n");
    printf("░╚═══██╗██║██║░░╚██╗╚════╝██╔══██╗██║██╔═██╗░██╔══╝░░\n");
    printf("██████╔╝██║╚██████╔╝░░░░░░██████╦╝██║██║░╚██╗███████╗\n");
    printf("╚═════╝░╚═╝░╚═════╝░░░░░░░╚═════╝░╚═╝╚═╝░░╚═╝╚══════╝\n");
    printf("-----------------------------------------------------\n");
    printf("=====================================================\n");
    printf("======SISTEMAS DE BICICLETAS E PATINS ELÉTRICOS======\n");
    printf("=====================Menu Cliente====================\n");
    printf("===                                               ===\n");
    printf("===              1.Cadastro Usuário:              ===\n");
    printf("===              2.Lista de Usuários:             ===\n");
    printf("===              3.Apagar Usuários:               ===\n");
    printf("===              4.Editar Usuários:               ===\n");
    printf("===              5.Procurar Usuário:              ===\n");
    printf("===              0.Voltar                         ===\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("=====================================================\n");
    scanf("%c", &op);
    getchar();
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("=====================================================\n");
    printf("\t\t\t ... Aguarde ...\n");
    sleep(1);
    return op;

}


void cadastro_usuario(void){
    
    char nome [20];
    char CPF [11];
    char Telefone [20];
    char data_de_nascimento[20];
    char Endereco [40];

    system("clear||cls");
    printf("\n");
    printf("=====================================================\n");
    printf("=====================================================\n");
    printf("-----------------------------------------------------\n");
    printf("░██████╗██╗░██████╗░░░░░░░██████╗░██╗██╗░░██╗███████╗\n");
    printf("██╔════╝██║██╔════╝░░░░░░░██╔══██╗██║██║░██╔╝██╔════╝\n");
    printf("╚█████╗░██║██║░░██╗░█████╗██████╦╝██║█████═╝░█████╗░░\n");
    printf("░╚═══██╗██║██║░░╚██╗╚════╝██╔══██╗██║██╔═██╗░██╔══╝░░\n");
    printf("██████╔╝██║╚██████╔╝░░░░░░██████╦╝██║██║░╚██╗███████╗\n");
    printf("╚═════╝░╚═╝░╚═════╝░░░░░░░╚═════╝░╚═╝╚═╝░░╚═╝╚══════╝\n");
    printf("-----------------------------------------------------\n");
    printf("-----------------------------------------------------\n");
    printf("=====================================================\n");
    printf("=====================================================\n");
    printf("======SISTEMAS DE BICICLETAS E PATINS ELÉTRICOS======\n");
    printf("================Menu Cadastro de Cliente=============\n");
    printf("===                                               ===\n");
    printf(" | Digite seu nome: \n");
    scanf("%[A-Z a-z]", nome);
    getchar();
    printf(" | Digite seu CPF: \n");
    scanf("%[0-9.,..,-]", CPF); 
    getchar();
    printf(" | Digite seu Telefone: \n");   
    scanf("%[0-9.,-.,(.,).,/]", Telefone);
    getchar();
    printf(" | Digite sua data de nascimento: \n");
    scanf("%[0-9.,/]", data_de_nascimento);
    getchar();
    printf(" | Digite seu endereço: \n");
    scanf("%[A-Z., 0-9.,]", Endereco);
    getchar();
    printf("=== Usuário foi cadastrado no sistema!!           ===\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf(" Press ENTER to exit...");
    getchar();
}

void lista_usuario(void){

    system("clear||cls");
    printf("\n");
    printf("=====================================================\n");
    printf("=====================================================\n");
    printf("-----------------------------------------------------\n");
    printf("░██████╗██╗░██████╗░░░░░░░██████╗░██╗██╗░░██╗███████╗\n");
    printf("██╔════╝██║██╔════╝░░░░░░░██╔══██╗██║██║░██╔╝██╔════╝\n");
    printf("╚█████╗░██║██║░░██╗░█████╗██████╦╝██║█████═╝░█████╗░░\n");
    printf("░╚═══██╗██║██║░░╚██╗╚════╝██╔══██╗██║██╔═██╗░██╔══╝░░\n");
    printf("██████╔╝██║╚██████╔╝░░░░░░██████╦╝██║██║░╚██╗███████╗\n");
    printf("╚═════╝░╚═╝░╚═════╝░░░░░░░╚═════╝░╚═╝╚═╝░░╚═╝╚══════╝\n");
    printf("-----------------------------------------------------\n");
    printf("=====================================================\n");
    printf("=====================================================\n");
    printf("======SISTEMAS DE BICICLETAS E PATINS ELÉTRICOS======\n");
    printf("===================Lista de Clientes=================\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("===        Clientes cadastrados no sistema        ===\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf(" Press ENTER to exit...");
    getchar();
}

void apagar_usuario(void){

    char nome [20];
    char CPF [11];

    system("clear||cls");
    printf("\n");
    printf("=====================================================\n");
    printf("=====================================================\n");
    printf("-----------------------------------------------------\n");
    printf("░██████╗██╗░██████╗░░░░░░░██████╗░██╗██╗░░██╗███████╗\n");
    printf("██╔════╝██║██╔════╝░░░░░░░██╔══██╗██║██║░██╔╝██╔════╝\n");
    printf("╚█████╗░██║██║░░██╗░█████╗██████╦╝██║█████═╝░█████╗░░\n");
    printf("░╚═══██╗██║██║░░╚██╗╚════╝██╔══██╗██║██╔═██╗░██╔══╝░░\n");
    printf("██████╔╝██║╚██████╔╝░░░░░░██████╦╝██║██║░╚██╗███████╗\n");
    printf("╚═════╝░╚═╝░╚═════╝░░░░░░░╚═════╝░╚═╝╚═╝░░╚═╝╚══════╝\n");
    printf("-----------------------------------------------------\n");
    printf("=====================================================\n");
    printf("=====================================================\n");
    printf("======SISTEMAS DE BICICLETAS E PATINS ELÉTRICOS======\n");
    printf("==================Menu Apagar Cliente================\n");
    printf("===                                               ===\n");
    printf(" | Digite seu nome: ");
    scanf("%[A-Z a-z]", nome);
    getchar(); 
    printf(" | Digite seu CPF: ");
    scanf("%[0-9.,..,-]", CPF); 
    getchar();
    printf("=== Usuário foi deletado com sucesso!!            ===\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf(" Press ENTER to exit...");
    getchar();
}

char editar_usuario(void){

    char op;

    system("clear||cls");
    printf("\n");
    printf("=====================================================\n");
    printf("-----------------------------------------------------\n");
    printf("░██████╗██╗░██████╗░░░░░░░██████╗░██╗██╗░░██╗███████╗\n");
    printf("██╔════╝██║██╔════╝░░░░░░░██╔══██╗██║██║░██╔╝██╔════╝\n");
    printf("╚█████╗░██║██║░░██╗░█████╗██████╦╝██║█████═╝░█████╗░░\n");
    printf("░╚═══██╗██║██║░░╚██╗╚════╝██╔══██╗██║██╔═██╗░██╔══╝░░\n");
    printf("██████╔╝██║╚██████╔╝░░░░░░██████╦╝██║██║░╚██╗███████╗\n");
    printf("╚═════╝░╚═╝░╚═════╝░░░░░░░╚═════╝░╚═╝╚═╝░░╚═╝╚══════╝\n");
    printf("-----------------------------------------------------\n");
    printf("=====================================================\n");
    printf("=====================================================\n");
    printf("======SISTEMAS DE BICICLETAS E PATINS ELÉTRICOS======\n");
    printf("=================Menu Editar Cliente=================\n");
    printf("===                                               ===\n");
    printf("===              1.Editar Nome:                   ===\n");
    printf("===              2.Editar CPF:                    ===\n");
    printf("===              3.Editar E-mail:                 ===\n");
    printf("===              4.Editar Data de Nascimento:     ===\n");
    printf("===              0.Voltar                         ===\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("=====================================================\n");
    scanf("%c", &op);
    getchar();
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("=====================================================\n");
    printf("\t\t\t ... Aguarde ... \n");
    sleep(1);
    return op;
}
