#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "moduloadministracao.h"
#include "modulocliente.h"
#include "moduloestoque.h"
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
            menu_nav_estoque();
            break;
        case '4':
            menu_nav_aluguel();
            break; 
        case '5':
            menu_nav_adm();
            break;
        case '6':
            menu_sobre();
            break;
        default:
            printf ("Opcao invalida \n");
            break;
    }

    } while(esc != '0');

    return 0 ;
}

    // estoque = menu_estoque();
    // switch (estoque)
    // {
    //     case '1': //cadastro_produto();
    //         break;
        
    //     case '2': //lista_produto();
    //         break;
        
    //     case '3': //editar_produto();
    //         break;

    //     case '4': //apagar_produto();
    //         break;

    //     case '5': //lista_falta();
    //         break;

    //     case '0': tela_inicial();
    //         break;
            
    //     default:
    //         //printf('Você inseriu uma opção invalida, por favor insira uma opção válida!');
    //         break;
    // }

    // aluguel = menu_aluguel();
    // switch (aluguel)
    // {
    //     case '1': //cadastro_aluguel();
    //         break;
        
    //     case '2': //lista_aluguel();
    //         break;

    //     case '3': //editar_aluguel();
    //         break;

    //     case '4': //excluir_aluguel():
    //         break;


    //     case '0': tela_inicial();
    //         break;
            
    //     default:
    //         //printf('Você inseriu uma opção invalida, por favor insira uma opção válida!');
    //         break;
    // }

    // vendas = menu_vendas();
    // switch (vendas)
    // {
    //     case '1': //cadastro_vendas();
    //         break;
        
    //     case '2': //listar_vendas();
    //         break;
        
    //     case '3': //apagar_vendas();
    //         break;

    //     case '4': //editar_vendas();
    //         break;
    
    //     case '0': tela_inicial();
    //         break;
            
    //     default:
    //         //printf('Você inseriu uma opção invalida, por favor insira uma opção válida!');
    //         break;
    // }
    
    // adm = menu_adm();
    // switch (adm)
    // {
    //     case '1': //fluxo_de_caixa();
    //         break;
        
    //     case '2': //gastos_da_empresa();
    //         break;
    
    //     case '0': tela_inicial();
    //         break;
            
    //     default:
    //         //printf('Você inseriu uma opção invalida, por favor insira uma opção válida!');
    //         break;
    // }
    
    // sobre = menu_sobre();
    // switch (sobre)
    // {   
    //     case '1':
    //         //printf('vai dar certo!');
        
    
    //     case '0': tela_inicial();
    //         break;
            
    //     default:
    //         //printf('Você inseriu uma opção invalida, por favor insira uma opção válida!');
    //         break;
    // }*/
      


/// menu tela inicial:

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
    printf("===               2.Menu Veicúlos:                ===\n");
    printf("===               3.Menu Estoque:                 ===\n");
    printf("===               4.Menu Aluguel:                 ===\n");
    printf("===               5.Menu Vendas:                  ===\n");
    printf("===               6.Menu Administração:           ===\n");
    printf("===               7.Menu Sobre:                   ===\n");
    printf("===               0.Sair                          ===\n");
    printf("===                                               ===\n");
    printf("=====================================================\n");
    scanf("%c", &op);
    getchar();
    printf("\t\t\t ... Aguarde ...\n");
    sleep(1);
    return op;

}