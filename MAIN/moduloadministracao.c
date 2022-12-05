#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "moduloadministracao.h"
#include "modulocliente.h"
#include "moduloveiculo.h"
#include "moduloaluguel.h"
#include "validacoes.h"

void menu_nav_adm(void)
{   char esc = ' ';
    do {
        esc = menu_adm();
        switch (esc) {
        case '1':
            menu_gastos_da_empresa();
            break;

        case '2':
            menu_fluxo_caixa();
            break;

        case '3':
            nav_relatiorio_cliente();
            break;

        case '4':
            nav_relatorio_veiculo();
            break;

        case '5':
            nav_relatorio_aluguel();
            break;
            
        default:
            printf("Opcao Invalida\n");
            break;
        }

    } while(esc != '0');
}

void nav_relatiorio_cliente(void){
    char esc = ' ';
    do {
        esc = menu_relatorios_cliente();
        switch (esc){
            case '1':
            R_lista_cliente();
            break;

            case '2':
            break;

            case '3':
            break;

            case '4':
            break;

            default:
            printf("Opcao Invalida\n");
            break;
        }
    } while(esc != '0');
}

void nav_relatorio_veiculo(void){
    char esc = ' ';
    do {
        esc = menu_relatorio_veiculo();
        switch (esc){
            case '1':
            R_lista_veiculo();
            break;
        }
    } while(esc != '0');
}

char menu_adm(void){
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
    printf("==================Menu Administração=================\n");
    printf("===                                               ===\n");
    printf("===              1.Gastos da Empresa:             ===\n");
    printf("===              2.Fluxo de Caixa:                ===\n");
    printf("===              3.Relatorios:                    ===\n");
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

char menu_gastos_da_empresa(void){
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
    printf("================Menu Gastos da Empresa===============\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("===           1.Mostrar Gastos da Empresa:        ===\n");
    printf("===           0.Voltar                            ===\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("=====================================================\n");
    scanf("%c", &op);
    getchar();
    printf("\t\t\t ... Aguarde ...\n");
    sleep(1);
    return op;
}

char menu_fluxo_caixa(void){
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
    printf("==================Menu Fluxo de Caixa================\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("===           1.Mostrar Fluxo de Caixa:           ===\n");
    printf("===           0.Voltar                            ===\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("=====================================================\n");
    scanf("%c", &op);
    getchar();
    printf("\t\t\t ... Aguarde ...\n");
    sleep(1);
    return op;
}

char menu_relatorios_cliente(void)
{
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
    printf("===============Menu Cliente -Relatorios==============\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("===     1. Lista todos os clientes:               ===\n");
    printf("===     2. Lista de clientes ordem alfabetica:    ===\n");
    printf("===     3. Lista de clientes data de nascimento:  ===\n");
    printf("===     4. Lista de clientes status:              ===\n");
    printf("===     0.Voltar                                  ===\n");
    printf("===                                               ===\n");
    printf(" Press ENTER to exit...\n");
    scanf("%c", &esc);
    getchar();

    return esc;
}

void R_lista_cliente(void)
{
    int cont = 0;
    FILE *fp;
    Cadastro *cad;
    cad = (Cadastro *)malloc(sizeof(Cadastro));
    fp = fopen("cliente.dat", "rt");

    if (fp == NULL)
    {
        printf("\nNão foi possível abrir o arquivo.\n");
    }

    else
    {
        while (fread(cad, sizeof(Cadastro), 1, fp))
        {
            if (cad->status != 'x')
            {
                exibe_cliente(cad);
                cont++;
            }
        }
    }

    if (cont > 0)
    {
        printf("\nVocê possúi %d cliente(s) cadastrados!\n", cont);
    }

    else
    {
        printf("\nVocê não possui cliente(s) cadastrados!");
    }

    espera();
    fclose(fp);
    free(cad);
}


char menu_relatorio_veiculo(void){
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
    printf("===============Menu Veiculo -Relatorios==============\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("===     1. Lista todos os Veiculos:               ===\n");
    printf("===     2. Lista de veiculo tipo bike:            ===\n");
    printf("===     3. Lista de veiculo tipo patins:          ===\n");
    printf("===     0.Voltar                                  ===\n");
    printf("===                                               ===\n");
    printf(" Press ENTER to exit...\n");
    scanf("%c", &esc);
    getchar();

    return esc;
}

void R_lista_veiculo(void){
    int cont = 0;
    FILE *fp;
    CadastroVeiculo *cadaveiculo;
    cadaveiculo = (CadastroVeiculo *)malloc(sizeof(CadastroVeiculo));
    fp = fopen("cliente.dat", "rt");

    if (fp == NULL)
    {
        printf("\nNão foi possível abrir o arquivo.\n");
    }

    else
    {
        while (fread(cadaveiculo, sizeof(CadastroVeiculo), 1, fp))
        {
            if (cadaveiculo->status != 'x')
            {
                exibe_cliente(cadaveiculo);
                cont++;
            }
        }
    }

    if (cont > 0)
    {
        printf("\nVocê possúi %d cliente(s) cadastrados!\n", cont);
    }

    else
    {
        printf("\nVocê não possui cliente(s) cadastrados!");
    }

    espera();
    fclose(fp);
    free(cadaveiculo);
}