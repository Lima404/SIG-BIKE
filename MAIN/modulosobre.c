#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "modulosobre.h"
#include "validacoes.h"

char menu_sobre(void)
{
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
    printf("===== SISTEMAS DE BICICLETAS E PATINS ELÉTRICOS =====\n");
    printf("==================== Menu Sobre =====================\n");
    printf("===                                               ===\n");
    printf("==                                                 ==\n");
    printf("== Trabalho referente a disciplina de programação  ==\n");
    printf("== da Universidade Federal do Rio Grande do Norte. ==\n");
    printf("==                                                 ==\n");
    printf("== SIG-BIKE é um sistema de aluguel de bicicletas  ==\n");
    printf("== e também de patins elétricos. Monitoramento de  ==\n");
    printf("== clientes, veículos e aluguéis.                  ==\n");
    printf("==                                                 ==\n");
    printf("==    Componentes: Erick Bezerra & Gabriel Lima    ==\n");
    printf("==                                                 ==\n");
    printf("==                                                 ==\n");
    printf("===       0. Para voltar ao menu principal        ===\n");
    printf("=====================================================\n");
    scanf("%c", &op);
    getchar();
    printf("\t\t\t ... Aguarde ... \n");
    sleep(1);
    return op;
}