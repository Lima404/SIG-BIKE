#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include "moduloestoque.h"

char menu_estoque(void){
    char op;

    system("clear||cls");
    setlocale(LC_ALL,"");
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
    printf("=====================Menu Estoque====================\n");
    printf("===                                               ===\n");
    printf("===              1.Cadastro de Item               ===\n");
    printf("===              2.Lista de Itens                 ===\n");
    printf("===              3.Apagar Item                    ===\n");
    printf("===              4.Editar Item                    ===\n");
    printf("===              5.Lista de Produtos em falta:    ===\n");
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