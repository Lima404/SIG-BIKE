#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "modulosobre.h"

char menu_sobre(void){
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
    printf("=====================Menu Sobre======================\n");
    printf("===                                               ===\n");
    printf("== Nossa opinião no estudo na criação desse sistema =\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("===       0. Para voltar ao menu principal        ===\n");
    printf("=====================================================\n");
    scanf("%c", &op);
    getchar();
    printf("\t\t\t ... Aguarde ... \n");
    sleep(1);
    return op;
}