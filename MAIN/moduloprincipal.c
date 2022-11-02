#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "moduloadministracao.h"
#include "modulocliente.h"
#include "moduloaluguel.h"
#include "modulosobre.h"
#include "moduloveiculo.h"


char tela_inicial (void);

int main (void)
{
    char esc;
    do {
        esc = tela_inicial();
        switch (esc) {
        case '1':
            menu_nav_cliente();
            break;
        case '2':
            menu_nav_veiculo();
            break; 
        case '3':
            menu_nav_aluguel();
            break; 
        case '4':
            menu_nav_adm();
            break;
        case '5':
            menu_sobre();
            break;
        default:
            printf ("Programa Finalizado! \n");
            break;
    }

    } while(esc != '0');

    return 0 ;
}


char tela_inicial(void){
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
    printf("====================Menu Principal===================\n");
    printf("===                                               ===\n");
    printf("===               1.Menu Usuário:                 ===\n");
    printf("===               2.Menu Veículos:                ===\n");
    printf("===               3.Menu Aluguel:                 ===\n");
    printf("===               4.Menu Administração:           ===\n");
    printf("===               5.Menu Sobre:                   ===\n");
    printf("===               0.Sair                          ===\n");
    printf("===                                               ===\n");
    printf("=====================================================\n");
    scanf("%c", &op);
    getchar();
    printf("\t\t\t ... Aguarde ...\n");
    sleep(1);
    return op;

}