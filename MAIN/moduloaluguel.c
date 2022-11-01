#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "moduloaluguel.h"
#include "validacoes.h"

void menu_nav_aluguel(void)
{   
    CadastroAluguel* cadaluguel;
    ApagarAluguel* apaexcluir;
    char esc = ' ';
    do {
        esc = menu_aluguel();
        switch (esc) {
        case '1':
            cadaluguel = cadastroAluguel(cadaluguel);
            break;
        case '2':
            apaexcluir = apagarAluguel(apaexcluir);
            break; 
        case '3':
            menu_editar_aluguel();
            break;
        case '4':
            menu_lista_disp();
            break;
        case '5':
            menu_lista_indisp();
            break;
        case '6':
            menu_lista_atrasados();
            break;
        default:
            printf ("Opção Inválida\n");
            break;
        }
    } while(esc != '0');
}

char menu_aluguel(void){
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
    printf("=====================Menu Aluguel====================\n");
    printf("===                                               ===\n");
    printf("===              1.Cadastro Aluguel:              ===\n");
    printf("===              2.Apagar Aluguel:                ===\n");
    printf("===              3.Editar Aluguel:                ===\n");
    printf("===              4.Lista de Veiculos disponiveis: ===\n");
    printf("===              5.Lista de veiculos alugados:    ===\n");  
    printf("===              6.Lista de Alugueis atrasado:    ===\n");
    printf("===              0.Voltar                         ===\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("=====================================================\n");
    scanf("%c", &op);
    getchar();
    printf("\t\t\t ... Aguarde ...\n");
    sleep(1);
    return op;
}

CadastroAluguel* cadastroAluguel( ){

    CadastroAluguel* cadaaluguel;
    cadaaluguel = (CadastroAluguel*) malloc(sizeof(CadastroAluguel));

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
    printf("================Menu Aluguel - Cadastro==============\n");
    printf("===                                               ===\n");
    

    do{

        printf("Digite seu CPF: ");
        scanf("%s", cadaaluguel->cpf);
        getchar();

    } while (!validar_cpf(cadaaluguel->cpf));

    do{

        printf(" | Digite o código do veiculo: \n");
        scanf("%s", cadaaluguel->cod);
        getchar();

    } while(cadaaluguel->cod);

    printf("=== Aluguel foi cadastrado no sistema!!           ===\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf(" Press ENTER to exit...");
    getchar();

    return cadaaluguel;

}

ApagarAluguel* apagarAluguel( ){
    
    ApagarAluguel* apaaluguel;
    apaaluguel =(ApagarAluguel*) malloc(sizeof(ApagarAluguel));

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
    printf("=================Menu Aluguel - Apagar===============\n");
    printf("===                                               ===\n");

    do{

        printf(" | Digite seu CPF, (só numeros): ");
        scanf("%s", apaaluguel->cpf); 
        getchar();

    }while (!validar_cpf(apaaluguel->cpf));

    printf("=== Usuário foi deletado com sucesso!!            ===\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf(" Press ENTER to exit...\n");
    getchar();
    
    return apaaluguel;

}

char menu_editar_aluguel(void){
    char esc;

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
    printf("================Menu Aluguel - Editar================\n");
    printf("===                                               ===\n");
    printf("===              1.Editar Nome:                   ===\n");
    printf("===              2.Editar CPF:                    ===\n");
    printf("===              3.Editar Telefone:               ===\n");
    printf("===              4.Editar Código:                 ===\n");
    printf("===              5.Editar Endereço:               ===\n");
    printf("===              0.Voltar                         ===\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("=====================================================\n");
    scanf("%c", &esc);
    getchar();
    printf("\t\t\t ... Aguarde ... \n");
    sleep(1);
    return esc;

}

char menu_lista_disp(void){

    char esc;
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
    printf("=================Menu Aluguel - Lista================\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("===     1.Listar Alugueis disponiveis:            ===\n");
    printf("===     0.Voltar                                  ===\n");
    printf("===                                               ===\n");
    printf("... Press ENTER to exit...\n");
    scanf("%c",&esc);
    getchar();
    return esc;
}

char menu_lista_indisp(void){

    char esc;
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
    printf("=================Menu Aluguel - Lista================\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("===     1.Listar Alugueis indisponiveis:          ===\n");
    printf("===     0.Voltar                                  ===\n");
    printf("===                                               ===\n");
    printf("... Press ENTER to exit...\n");
    scanf("%c",&esc);
    getchar();
    return esc;
}



char menu_lista_atrasados(void){

    char esc;
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
    printf("=================Menu Aluguel - Lista================\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("===     1.Listar Alugueis Atrazados no sistema:   ===\n");
    printf("===     0.Voltar                                  ===\n");
    printf("===                                               ===\n");
    printf("... Press ENTER to exit...\n");
    scanf("%c",&esc);
    getchar();
    return esc;
}