#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
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
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("=====================================================\n");
    printf("\t\t\t ... Aguarde ... \n");
    sleep(1);
    return op;

}


void cadastro_veiculo(void){
    
    char marca [20];
    char codigo [11];
    char tipo [20];
    char descricao[300];
    char aluguel [20];

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
    printf("=============== Menu Cadastro de Veiculos ===========\n");
    printf("===                                               ===\n");
    printf(" | Digite a marca do veiculo: ");
    scanf("%[A-Z a-z]", marca);
    getchar();
    printf(" | Digite código para o veiculo: ");
    scanf("%[0-9.,..,-]", codigo); 
    getchar();
    printf(" | Digite o tipo do veiculo: ");   
    scanf("%[A-Z a-z]", tipo);
    getchar();
    printf(" | De uma descrição sobre o veiculo: ");
    scanf("%[A-Z]", descricao);
    getchar();
    printf(" | Quanto será o aluguel do veiculo: ");
    scanf("%[A-Z a-z, 0-9, $, , , . ,]", aluguel);
    getchar();
    printf("=== Usuário foi cadastrado no sistema!!           ===\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf(" Press ENTER to exit...");
    getchar();
}