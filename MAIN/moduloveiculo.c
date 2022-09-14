#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "moduloveiculo.h"

void menuprincipalveiculo(char esc)
{
    do {
        esc = menu_veiculo();
        switch (esc) {
        case '1':
            cadastro_veiculo();
            break;
        case '2':
            lista_veiculo();
            break; 
        case '3':
            apagar_veiculo();
            break;
        case '4':
            editar_veiculo();
            break;
        case '5':
            agendar_manutencao();
            break;
        case '6':
            lista_manutencao();
            break;
        case '7':
            lista_agendamento();
            break;
        default:
            printf ("Opção Inválida\n");
            break;
    }

    } while(esc != '0');
}

char menu_veiculo(void){
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
    printf("=====================================================\n");
    printf("======SISTEMAS DE BICICLETAS E PATINS ELÉTRICOS======\n");
    printf("=====================Menu Veículo====================\n");
    printf("===                                               ===\n");
    printf("===              1.Cadastro Veículo               ===\n");
    printf("===              2.Lista de Veículos              ===\n");
    printf("===              3.Apagar Veículo                 ===\n");
    printf("===              4.Editar Veículo                 ===\n");
    printf("===              5.Agendar Manutenção:            ===\n");
    printf("===              6.Lista de Manutenção:           ===\n");
    printf("===              7.Lista de Agendamentos:         ===\n");
    printf("===              0.Voltar                         ===\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("=====================================================\n");
    scanf("%c", &op);
    getchar();
    printf("\t\t\t ... Aguarde ... \n");
    sleep(1);
    return op;

}

void menu_cadastro_veiculo(void){
    
    char tipo [20];
    char marca [20];
    char desc [200];
    char cod[20];
    char preco [20];

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
    printf("================Menu Veiculo - Cadastro==============\n");
    printf("===                                               ===\n");
    printf("===         Tipo da Bike:                         ===\n");
    printf("===         1. Bicicleta:                         ===\n");
    printf("===         2. Patins Elétricos:                  ===\n");
    printf("===                                               ===\n");
    printf("=====================================================\n");
    printf("=====================================================\n");
    
    printf(" | Digite seu nome: \n");
    scanf("%[A-Z a-z]", tipo);
    getchar();
    printf(" | Digite seu CPF: \n");
    scanf("%[A-Z a-z]", marca); 
    getchar();
    printf(" | Digite seu Telefone: \n");   
    scanf("%[A-Z a-z]", desc);
    getchar();
    printf(" | Digite sua data de nascimento: \n");
    scanf("%[0-9.,/]", cod);
    getchar();
    printf(" | Digite seu endereco: \n");
    scanf("%[R., $., 0-9.,]", preco);
    getchar();
    printf("=== Usuario foi cadastrado no sistema!!           ===\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf(" Press ENTER to exit...");
    getchar();
}
