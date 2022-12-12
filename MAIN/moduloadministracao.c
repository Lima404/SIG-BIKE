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



// NAVEGAÇÃO PRINCIPAL

void menu_nav_adm(void)
{   char esc = ' ';
    do {
        esc = menu_adm();
        switch (esc) {
        case '1':
            nav_relatorio_cliente();
            break;

        case '2':
            nav_relatorio_veiculo();
            break;

        case '3':
            // nav_relatorio_aluguel();
            break;

        default:
            printf("Opcao Invalida\n");
            break;
        }

    } while(esc != '0');
}


char menu_adm(void)
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
    printf("======SISTEMAS DE BICICLETAS E PATINS ELÉTRICOS======\n");
    printf("==================Menu Administração=================\n");
    printf("===                                               ===\n");
    printf("===              1.Relatorios Cliente:            ===\n");
    printf("===              2.Relatorios Veiculo:            ===\n");
    printf("===              3.Relatorios Aluguel:            ===\n");
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



// NAVEGAÇÃO CLIENTE



void nav_relatorio_cliente(void){
    NoCliente* lista;
    char esc = ' ';
    do {
        esc = menu_relatorios_cliente();
        switch (esc){
            case '1':
                R_lista_cliente();
                break;

            case '2':
                lista = R_cliente_alfa();
                exibe_alfa(lista);
                break;

            case '3':
                //R_cliente_nasc();
                break;

            case '4':
                //R_cliente_status();
                break;

            default:
            printf("Opcao Invalida\n");
            break;
        }
    } while(esc != '0');
}



// NAVEGAÇÃO VEICULO



void nav_relatorio_veiculo(void){
    char esc = ' ';
    do {
        esc = menu_relatorio_veiculo();
        switch (esc){
            case '1':
            R_lista_veiculo();
            break;

            case '2':
            veiculo_tipo();
            break;
        }
    } while(esc != '0');
}


// NAVEGAÇÃO ALUGUEL

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
    printf("===== SISTEMAS DE BICICLETAS E PATINS ELÉTRICOS =====\n");
    printf("========= Menu Cliente - Relatorios Clientes ========\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("===     1. Lista cliente(recente) e quantidade:   ===\n");
    printf("===     2. Lista de clientes ordem alfabetica:    ===\n");
    printf("===     3. Lista de clientes data de nascimento:  ===\n");
    printf("===     4. Lista de clientes status:              ===\n");
    printf("===     0.Voltar                                  ===\n");
    printf("===                                               ===\n");
    printf(" Qual opção você deseja:\n");
    scanf("%c", &esc);
    getchar();
    printf("\t\t\t ... Aguarde ...\n");
    return esc;
}

void R_lista_cliente(void)
{
    int cont = 0;
    FILE *fp;
    Cadastro *cad;
    cad = (Cadastro *)malloc(sizeof(Cadastro));
    fp = fopen("cliente.dat", "rb");

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
                exibeCliente(cad);
                cont++;
            }
        }
    }

    if (cont > 0)
    {
        printf("\nVocê possui %d cliente(s) cadastrados!\n", cont);
    }

    else
    {
        printf("\nVocê não possui cliente(s) cadastrados!");
    }
    getchar();
    getchar();
    fclose(fp);
    free(cad);
}


NoCliente* R_cliente_alfa(void)
{
    FILE* fp;
    Cadastro* cad;
    NoCliente* novoUsuario;
    NoCliente* lista;

    lista = NULL;
    fp = fopen("cliente.dat", "rb");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        return 0;
    }

    cad = (Cadastro*) malloc(sizeof(Cadastro));
    while(fread(cad, sizeof(Cadastro), 1, fp)) 
    {        
        if (cad->status == '1') 
        {
            novoUsuario = (NoCliente*) malloc(sizeof(NoCliente));
            strcpy(novoUsuario->nome, cad->nome);
            strcpy(novoUsuario->cpf, cad->cpf);
            strcpy(novoUsuario->telefone, cad->telefone);
            strcpy(novoUsuario->endereco, cad->endereco);
            novoUsuario->dd = cad->dd;
            novoUsuario->mm = cad->mm;
            novoUsuario->aa = cad->aa;
            novoUsuario->status = cad->status;

            if (lista == NULL)
            {
                lista = novoUsuario;
                novoUsuario->prox = NULL;
            }
            else if (strcmp(novoUsuario->nome, lista->nome) < 0)
            {
                novoUsuario->prox = lista;
                lista = novoUsuario;
            }
            else
            {
                NoCliente* anter = lista;
                NoCliente* atual = lista->prox;
                while ((atual != NULL) && strcmp(atual->nome, novoUsuario->nome) < 0)
                {
                    anter = atual;
                    atual = atual->prox;
                }
                anter->prox = novoUsuario;
                novoUsuario->prox = atual;
            }           
        }
    }
    fclose(fp);
    free(cad);
    return lista;
}


void exibe_alfa(NoCliente* cliente) 
{
    while (cliente != NULL)
    {
        printf("CPF: %s\n", cliente->cpf);
        printf("Nome: %s\n", cliente->nome);
        printf("telefone: %s\n", cliente->telefone);
        printf("endereco: %s\n", cliente->endereco);
        printf("Nascimento(dia): %d\n", cliente->dd);
        printf("Nascimento(mes): %d\n", cliente->mm);
        printf("Nascimento(ano): %d\n", cliente->aa);
        printf("Status: %c\n", cliente->status);
        printf("\n");
        getchar();
        cliente = cliente->prox;
    }
    
  
}  



char menu_relatorio_veiculo(void)
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
    printf("===== SISTEMAS DE BICICLETAS E PATINS ELÉTRICOS =====\n");
    printf("========= Menu Veiculo -Relatorios Veículos =========\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("===     1. Lista veículo(recente) e quantidade:   ===\n");
    printf("===     2. Lista de veiculo tipo bike:            ===\n");
    printf("===     3. Lista de veiculo tipo patins:          ===\n");
    printf("===     0. Voltar                                 ===\n");
    printf("===                                               ===\n");
    printf(" Qual opção você deseja:\n");
    scanf("%c", &esc);
    getchar();
    return esc;
}

void R_lista_veiculo(void)
{
    int cont = 0;
    FILE *fp;
    CadastroVeiculo *cadaveiculo;
    cadaveiculo = (CadastroVeiculo *)malloc(sizeof(CadastroVeiculo));
    fp = fopen("veiculo.dat", "rt");

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
                exibeVeiculo(cadaveiculo);
                cont++;
            }
        }
    }

    if (cont > 0)
    {
        printf("\nVocê possui %d cliente(s) cadastrados!\n", cont);
    }

    else
    {
        printf("\nVocê não possui cliente(s) cadastrados!");
    }
    getchar();
    getchar();
    fclose(fp);
    free(cadaveiculo);
}

void veiculo_tipo(void)
{
    
}
