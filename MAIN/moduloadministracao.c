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
            nav_relatorio_aluguel();
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

            default:
            printf("Opcao Invalida\n");
            break;
        }
    } while(esc != '0');
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
    printf("===== SISTEMAS DE BICICLETAS E PATINS ELÉTRICOS =====\n");
    printf("========= Menu Cliente - Relatorios Clientes ========\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("===     1. Lista cliente(recente) e quantidade:   ===\n");
    printf("===     2. Lista de clientes ordem alfabetica:    ===\n");
    printf("===     0. Voltar                                 ===\n");
    printf("===                                               ===\n");
    printf(" Qual opção você deseja:\n");
    scanf("%c", &esc);
    getchar();
    printf("\t\t\t ... Aguarde ...\n");
    return esc;
}

// NAVEGAÇÃO VEICULO


void nav_relatorio_veiculo(void){
    NoVeiculo* lista_veiculo;
    char esc = ' ';
    do {
        esc = menu_relatorios_veiculo();
        switch (esc){
            case '1':
            R_lista_veiculo();
                break;

            case '2':
            //veiculo_tipo();
                break;

            case '3':
            lista_veiculo = R_veiculo_alfa();
            exibe_alfa_veiculo(lista_veiculo);
                break;

            default:
            printf("Opcão Inválida\n");
            break;
        }
    } while(esc != '0');
}

char menu_relatorios_veiculo(void)
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
    printf("===     2. Lista de veiculo (tipo):               ===\n");
    printf("===     3. Lista veículos ordem alafabética:      ===\n");
    printf("===     0. Voltar                                 ===\n");
    printf("===                                               ===\n");
    printf(" Qual opção você deseja:\n");
    scanf("%c", &esc);
    getchar();
    return esc;
}

// NAVEGAÇÃO ALUGUEL

void nav_relatorio_aluguel(void){
    NoAluguel* lista_aluguel;
    char esc = ' ';
    do{
        esc = menu_relatorios_aluguel();
        switch (esc)
        {
        case '1' :
        R_lista_aluguel();
            break;
        case '2':
        lista_aluguel = R_aluguel_alfa();
        exibe_alfa_aluguel(lista_aluguel);
            break;

        default:
        printf("Opção inválida\n");
        break;
        }
    } while(esc != '0');
}


char menu_relatorios_aluguel(void)
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
    printf("========= Menu Aluguel - Relatorios Aluguéis ========\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("===     1. Lista Aluguel(recente) e quantidade:   ===\n");
    printf("===     2. Lista de aluguéis ordem alfabética:    ===\n");
    printf("===     3. Lista de aluguéis data devolução:      ===\n");
    printf("===     0. Voltar                                 ===\n");
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
    fclose(fp);
    free(cad);
}

void R_lista_aluguel(void)
{
    int cont = 0;
    FILE *fp;
    CadastroAluguel *cadaaluguel;
    cadaaluguel = (CadastroAluguel *)malloc(sizeof(CadastroAluguel));
    fp = fopen("aluguel.dat", "rb");

    if (fp == NULL)
    {
        printf("\nNão foi possível abrir o arquivo.\n");
    }

    else
    {
        while (fread(cadaaluguel, sizeof(CadastroAluguel), 1, fp))
        {
            if (cadaaluguel->status != 'x')
            {
                exibeAluguel(cadaaluguel);
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
    fclose(fp);
    free(cadaaluguel);
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
            novoUsuario->status = cad->status;
            novoUsuario->dd = cad->aa;
            novoUsuario->mm = cad->mm;
            novoUsuario->aa = cad->aa;

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

NoVeiculo* R_veiculo_alfa(void)
{
    FILE* fp;
    CadastroVeiculo* cadaveiculo;
    NoVeiculo* novoVeiculo;
    NoVeiculo* lista_veiculo;

    lista_veiculo = NULL;
    fp = fopen("veiculo.dat", "rb");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        return 0;
    }

    cadaveiculo = (CadastroVeiculo*) malloc(sizeof(CadastroVeiculo));
    while(fread(cadaveiculo, sizeof(CadastroVeiculo), 1, fp)) 
    {        
        if (cadaveiculo->status == '1') 
        {
            novoVeiculo = (NoVeiculo*) malloc(sizeof(NoVeiculo));
            strcpy(novoVeiculo->tipo, cadaveiculo->tipo);
            strcpy(novoVeiculo->marca, cadaveiculo->marca);
            strcpy(novoVeiculo->desc, cadaveiculo->desc);
            strcpy(novoVeiculo->cod, cadaveiculo->cod);
            strcpy(novoVeiculo->preco, cadaveiculo->preco);
            novoVeiculo->status = cadaveiculo->status;

            if (lista_veiculo == NULL)
            {
                lista_veiculo = novoVeiculo;
                novoVeiculo->prox = NULL;
            }
            else if (strcmp(novoVeiculo->marca, lista_veiculo->marca) < 0)
            {
                novoVeiculo->prox = lista_veiculo;
                lista_veiculo = novoVeiculo;
            }
            else
            {
                NoVeiculo* anter = lista_veiculo;
                NoVeiculo* atual = lista_veiculo->prox;
                while ((atual != NULL) && strcmp(atual->marca, novoVeiculo->marca) < 0)
                {
                    anter = atual;
                    atual = atual->prox;
                }
                anter->prox = novoVeiculo;
                novoVeiculo->prox = atual;
            }           
        }
    }
    fclose(fp);
    free(cadaveiculo);
    return lista_veiculo;
}

NoAluguel* R_aluguel_alfa(void)
{
    FILE* fp;
    CadastroAluguel* cadaaluguel;
    NoAluguel* novoAluguel;
    NoAluguel* lista_aluguel;

    lista_aluguel = NULL;
    fp = fopen("aluguel.dat", "rb");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        return 0;
    }

    cadaaluguel = (CadastroAluguel*) malloc(sizeof(CadastroAluguel));
    while(fread(cadaaluguel, sizeof(CadastroAluguel), 1, fp)) 
    {        
        if (cadaaluguel->status == '1') 
        {
            novoAluguel = (NoAluguel*) malloc(sizeof(NoAluguel));
            strcpy(novoAluguel->cpf, cadaaluguel->cpf);
            strcpy(novoAluguel->cod, cadaaluguel->cod);
            strcpy(novoAluguel->preco, cadaaluguel->preco);
            strcpy(novoAluguel->data, cadaaluguel->data);
            novoAluguel->status = cadaaluguel->status;

            if (lista_aluguel == NULL)
            {
                lista_aluguel = novoAluguel;
                novoAluguel->prox = NULL;
            }
            else if (strcmp(novoAluguel->preco, lista_aluguel->preco) < 0)
            {
                novoAluguel->prox = lista_aluguel;
                lista_aluguel = novoAluguel;
            }
            else
            {
                NoAluguel* anter = lista_aluguel;
                NoAluguel* atual = lista_aluguel->prox;
                while ((atual != NULL) && strcmp(atual->preco, novoAluguel->preco) < 0)
                {
                    anter = atual;
                    atual = atual->prox;
                }
                anter->prox = novoAluguel;
                novoAluguel->prox = atual;
            }           
        }
    }
    fclose(fp);
    free(cadaaluguel);
    return lista_aluguel;
}


void exibe_alfa_veiculo(NoVeiculo* cadveiculo) 
{
    while (cadveiculo != NULL)
    {
        printf("Tipo: %s\n", cadveiculo->tipo);
        printf("Marca: %s\n", cadveiculo->marca);
        printf("Descrição: %s\n", cadveiculo->desc);
        printf("Código: %s\n", cadveiculo->cod);
        printf("Preço: %s\n", cadveiculo->preco);
        printf("Status: %c\n", cadveiculo->status);
        printf("\n");
        getchar();
        cadveiculo = cadveiculo->prox;
    }
    
  
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

void exibe_alfa_aluguel(NoAluguel* cadaaluguel) 
{
    while (cadaaluguel != NULL)
    {
        printf("CPF do cliente com este aluguel: %s\n", cadaaluguel->cpf);
        printf("Código: %s\n", cadaaluguel->cod);
        printf("data: %s\n", cadaaluguel->data);
        printf("Preço: %s\n", cadaaluguel->preco);
        printf("Status: %c\n", cadaaluguel->status);
        printf("\n");
        getchar();
        cadaaluguel = cadaaluguel->prox;
    }
    
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
    fclose(fp);
    free(cadaveiculo);
}

