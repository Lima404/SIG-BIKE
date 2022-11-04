#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "moduloveiculo.h"
#include "validacoes.h"

void menu_nav_veiculo(void)
{
    ApagarVeiculo* apaveiculo;
    CadastroVeiculo* cadveiculo;
    char esc = ' ';
    do {
        esc = menu_veiculo();
        switch (esc) {
        case '1':
            cadveiculo = cadastroVeiculo();
            break;
        case '2':
            menu_lista_veiculo();
            break; 
        case '3':
            apaveiculo = apagarVeiculo();
            break;
        case '4':
            menu_editar_veiculo();
            break;
        /* case '5':
            menu_nav_estoque();
            break;
         case '7':
            menu_veiculo_manutencao();
            break;
        case '8':
            menu_lista_agendamento();
            break;
        case '9':
            menu_lista_agendamento();
            break; */
        default:
            printf ("Opção Inválida\n");
            break;
        
        }
    } while(esc != '0');
}

char menu_veiculo(void){
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
    printf("=====================Menu Veículo====================\n");
    printf("===                                               ===\n");
    printf("===              1.Cadastro Veículo               ===\n");
    printf("===              2.Lista de Veículos              ===\n");
    printf("===              3.Apagar Veículo                 ===\n");
    printf("===              4.Editar Veículo                 ===\n");
 /* printf("===              5.Menu Estoque:                  ===\n");
    printf("===              6.Agendar Manutenção:            ===\n");
    printf("===              7.Lista de Manutenção:           ===\n");
    printf("===              8.Lista de Agendamentos:         ===\n"); */
    printf("===              0.Voltar                         ===\n");
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

CadastroVeiculo* cadastroVeiculo( ){
    
    CadastroVeiculo* cadaveiculo;
    cadaveiculo = (CadastroVeiculo*) malloc(sizeof(CadastroVeiculo));

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
    printf("================Menu Veículo - Cadastro==============\n");
    printf("===                                               ===\n");
    printf("===         Tipo de veículo:                      ===\n");
    printf("===         1. Bike:                              ===\n");
    printf("===         2. Patins Elétricos:                  ===\n");
    printf("===                                               ===\n");
    printf("=====================================================\n");
    printf("=====================================================\n");
    
    do{

    printf(" | Digite o tipo do veículo: ");
    scanf("%[A-Z a-z]", cadaveiculo->tipo);
    getchar();

    } while (cadaveiculo->tipo);

    do{

    printf(" | Digite a marca do veículo: ");
    scanf("%[A-Z a-z]", cadaveiculo->marca); 
    getchar();

    }while (cadaveiculo->marca);

    do{

    printf(" | Digite uma descrição sobre o veículo: ");   
    scanf("%[A-Z a-z]", cadaveiculo->desc);
    getchar();

    }while (cadaveiculo->desc);

    do{

    printf(" | Digite o código pra registrar o veículo: ");
    scanf("%[0-9]", cadaveiculo->cod);
    getchar();

    }while (cadaveiculo->cod);

    do{

    printf(" | Digite o preço: ");
    scanf("%[R., $ 0-9]", cadaveiculo->preco);
    getchar();

    }while (cadaveiculo->preco);

    printf("=== O Veículo foi cadastrado no sistema!!         ===\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf(" Press ENTER to exit...\n");
    getchar();

    return cadaveiculo;

}


char menu_lista_veiculo(void){

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
    printf("=================Menu Veículo - Listar===============\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("===     1.Listar veiculos cadastrados no sistema: ===\n");
    printf("===     0.Voltar                                  ===\n");
    printf("===                                               ===\n");
    printf(" Press ENTER to exit...\n");
    getchar();
    scanf("%c", &esc);
    return esc;
}

ApagarVeiculo* apagarVeiculo( ){

    ApagarVeiculo* apaveiculo;
    apaveiculo = (ApagarVeiculo*) malloc(sizeof(ApagarVeiculo));

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
    printf("=================Menu Veículo - Apagar===============\n");
    printf("===                                               ===\n");

    do {

    printf(" | Digite o código para encontrar o veículo: ");
    scanf("%[0-9.,/]", apaveiculo->cod); 
    getchar();

    }while (apaveiculo->cod);

    printf("=== O veículo foi deletado com sucesso!!          ===\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf(" Press ENTER to exit...\n");
    getchar();

    return apaveiculo;
}

char menu_editar_veiculo(void){

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
    printf("================Menu Veículo - Editar================\n");
    printf("===                                               ===\n");
    printf("===              1.Editar o Tipo:                 ===\n");
    printf("===              2.Editar a Marca:                ===\n");
    printf("===              3.Editar a Descrição:            ===\n");
    printf("===              4.Editar o Código:               ===\n");
    printf("===              5.Editar o Preço:                ===\n");
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


void menu_veiculo_manutencao(void){

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
    printf("-----------------------------------------------------\n");
    printf("=====================================================\n");
    printf("=====================================================\n");
    printf("======SISTEMAS DE BICICLETAS E PATINS ELÉTRICOS======\n");
    printf("==============Menu Veículo - Manutenção==============\n");
    printf("===                                               ===\n");
    printf("===         Tipos de Serviços:                    ===\n");
    printf("===         1. Limpeza:                           ===\n");
    printf("===         2. Troca de componente:               ===\n");
    printf("===         3. Montagem de Veículo:               ===\n");
    printf("===         4. Manutenção:                        ===\n");
    printf("===                                               ===\n");
    printf("=====================================================\n");
    printf("=====================================================\n");
    printf("=== Seu agendamento foi cadastrado no sistema!!   ===\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    scanf("%c", &esc);
    printf(" Press ENTER to exit...\n");
    getchar();
}

char menu_lista_agendamento(void){

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
    printf("========Menu Veículo - Lista de Agendamentos=========\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("===     1.Agendamentos cadastrados no sistema:    ===\n");
    printf("===     0.Voltar                                  ===\n");
    printf("===                                               ===\n");
    printf(" Press ENTER to exit...\n");
    scanf("%c", &esc);
    getchar();
    return esc;
}
