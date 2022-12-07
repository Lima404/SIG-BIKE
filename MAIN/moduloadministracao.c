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

void nav_relatorio_cliente(void){
    char esc = ' ';
    do {
        esc = menu_relatorios_cliente();
        switch (esc){
            case '1':
                R_lista_cliente();
                break;

            case '2':
                R_cliente_alfa();
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
    printf(" Que opção você deseja?\n");
    scanf("%c", &esc);
    getchar();
    printf("\t\t\t ... Aguarde ...\n");
    sleep(1);
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
        printf("\nVocê possúi %d cliente(s) cadastrados!\n", cont);
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


char R_cliente_alfa(void){
    FILE *fp;
	int i, tam;
	char linha[256];
	Cadastro* user;
	Cadastro* lista;

	printf("Integrando Arquivos e Listas Dinâmicas\n");	

	fp = fopen("cliente.dat","rb");
	if (fp == NULL){
		printf("Erro na abertura do arquivo\n!");
		exit(1);
	}

	// Montando a lista ordenada de palavras
	lista = NULL;
	while(fgets(linha,256,fp)){
		user = (Cadastro*) malloc(sizeof(Cadastro));
		tam = strlen(linha) + 1;
		user->cpf = (char*) malloc(tam*sizeof(char));
		strcpy(user->cpf, linha);
    if (lista == NULL) {
			lista = user;
      user->prox = NULL;
		} else if (strcmp(user->cpf,lista->cpf) < 0) {
      user->prox = lista;
      lista = user;
    } else {
      Cadastro* anter = lista;
      Cadastro* atual = lista->prox;
      while ((atual != NULL) && strcmp(atual->cpf,user->cpf) < 0) {
        anter = atual;
        atual = atual->prox;
      }
      anter->prox = user;
      user->prox = atual;
    }
	}
	fclose(fp);

	// Exibindo a lista de palavras
	printf("\nConteúdo do Arquivo em Ordem Alfabética\n");
	user = lista;
	i = 1;
	while (user != NULL) {
		printf("Cliente %d: %s", i, user->cpf);
		user = user->prox;
		i++;
	}

	// Limpando a memória
	user = lista;
	while (lista != NULL) {
		lista = lista->prox;
		free(user->cpf);
		free(user);
		user = lista;
	}
	
	return 0;
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
    printf("======SISTEMAS DE BICICLETAS E PATINS ELÉTRICOS======\n");
    printf("===============Menu Veiculo -Relatorios==============\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf("===     1. Lista todos os Veiculos:               ===\n");
    printf("===     2. Lista de veiculo tipo bike:            ===\n");
    printf("===     3. Lista de veiculo tipo patins:          ===\n");
    printf("===     0. Voltar                                 ===\n");
    printf("===                                               ===\n");
    printf(" Que opção você deseja?\n");
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
        printf("\nVocê possúi %d cliente(s) cadastrados!\n", cont);
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
