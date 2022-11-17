#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "moduloveiculo.h"
#include "validacoes.h"

void menu_nav_veiculo(void)
{
    CadastroVeiculo* cadveiculo;
    char esc = ' ';
    do {
        esc = menu_veiculo();
        switch (esc) {
        case '1':
            cadveiculo = preencheVeiculo();
            gravaVeiculo(cadveiculo);
            free(cadveiculo);
            break;

        case '2':
            cadveiculo = buscaVeiculo();
            exibeVeiculo(cadveiculo);
            getchar();
            free(cadveiculo);
            break; 

        case '3':
            cadveiculo = buscaVeiculo();
            apagaVeiculo(cadveiculo);
            free(cadveiculo);
            break;

        case '4':
            menu_editar_veiculo();
            break;

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

CadastroVeiculo* preencheVeiculo( ){
    
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
    

    // tipo
    do{

    printf(" | Digite o tipo do veículo(PATINS ou BIKE): ");
    scanf("%20[^\n]", cadaveiculo->tipo);
    getchar();

    } while (!validar_nome(cadaveiculo->tipo));

    // Marca

    do{

    printf(" | Digite a marca do veículo: ");
    scanf("%20[^\n]", cadaveiculo->marca); 
    getchar();

    }while (!validar_nome(cadaveiculo->marca));

// Descrição


    printf(" | Digite uma descrição sobre o veículo: ");   
    scanf("%100[^\n]", cadaveiculo->desc);
    getchar();


// CÓDIGO DE RASTREIO

    printf(" | Digite um código pra registrar o veículo(6 números): ");
    scanf("%s", cadaveiculo->cod);
    getchar();

// PREÇO


    printf(" | Digite o preço em reais(APENAS NÚMEROS): ");
    scanf("%20[^\n]", cadaveiculo->preco);
    getchar();


    cadaveiculo->status = '1';
    return cadaveiculo;

    printf("=== O Veículo foi cadastrado no sistema!!         ===\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf(" Press ENTER to exit...\n");
    getchar();
}

// Gravação em arquivo

void gravaVeiculo(CadastroVeiculo* cadaveiculo){
    FILE* fp;
    fp = fopen("veiculo.dat", "ab");
    if (fp == NULL){
        printf("Ops, Ocorreu um erro na abertura!/n");
        printf("Não é possivel continuar esse programa... /n");
        exit(1);
    }
    fwrite(cadaveiculo, sizeof(CadastroVeiculo), 1, fp);
    fclose(fp);
}

// EXIBE VEICULO

void exibeVeiculo(CadastroVeiculo* cadveiculo){
    printf("Tipo do veiculo: %s\n", cadveiculo->tipo);
    printf("Marca do veiculo: %s\n", cadveiculo->marca);
    printf("Descrição do veiculo: %s\n", cadveiculo->desc);
    printf("Código do veiculo: %s\n", cadveiculo->cod);
    printf("Preço do veiculo: %s\n", cadveiculo->preco);
    printf("Status: %c\n", cadveiculo->status);
    printf("\n");
    system("Pause");
}


// BUSCA VEICULO

CadastroVeiculo* buscaVeiculo() {
    FILE *fp;
    CadastroVeiculo* cadaveiculo;
    char cod[7];
    system("clear||cls");
    printf("\n\n");
    printf("=====================================================\n");
    printf("-----------------------------------------------------\n");
    printf("░██████╗██╗░██████╗░░░░░░░██████╗░██╗██╗░░██╗███████╗\n");
    printf("██╔════╝██║██╔════╝░░░░░░░██╔══██╗██║██║░██╔╝██╔════╝\n");
    printf("╚█████╗░██║██║░░██╗░█████╗██████╦╝██║█████═╝░█████╗░░\n");
    printf("░╚═══██╗██║██║░░╚██╗╚════╝██╔══██╗██║██╔═██╗░██╔══╝░░\n");
    printf("██████╔╝██║╚██████╔╝░░░░░░██████╦╝██║██║░╚██╗███████╗\n");
    printf("╚═════╝░╚═╝░╚═════╝░░░░░░░╚═════╝░╚═╝╚═╝░░╚═╝╚══════╝\n");
    printf("-----------------------------------------------------\n");
    printf("======SISTEMAS DE BICICLETAS E PATINS ELÉTRICOS======\n");
    printf("================Menu Veiculo - Buscar================\n");
    printf("        Informe o número o código do veiculo:          ");
    scanf(" %[0-9]", cod);
    getchar();
    cadaveiculo = (CadastroVeiculo*)malloc(sizeof(CadastroVeiculo));
    fp = fopen("veiculo.dat", "rb");

    if (fp == NULL)
    {
        printf("Ocorreu um erxro na abertura do arquivo, não é possivel continuar o programa");
        exit(1);
    }

    while (!feof(fp))
    { // Busca até o final do arquivo
        fread(cadaveiculo, sizeof(CadastroVeiculo), 1, fp);
        if (strcmp(cadaveiculo->cod, cod) == 0 && (cadaveiculo->status != 'x'))
        { /*Verifica se o código é igual e o status*/
            fclose(fp);
            return cadaveiculo;
        }
    }

    fclose(fp);
    return NULL;
}

void apagaCliente(CadastroVeiculo* cadveiculo) {
  FILE* fp;
  CadastroVeiculo* veiculo;
  int achou;
  char resp;
  fp = fopen("cliente.dat", "r+b");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  cliente = (Cadastro*) malloc(sizeof(Cadastro));
  achou = 0;
  while((!achou) && (fread(cliente, sizeof(Cadastro), 1, fp))) {
    if ((strcmp(cliente->cpf, user->cpf) == 0) && (cliente->status == '1')) {
     achou = 1;
   }
  }
  
  if (achou) {
    exibeCliente(cliente);
    printf("Deseja realmente apagar cliente do sistema (s/n)? ");
    scanf("%c\n", &resp);
    if (resp == 's' || resp == 'S') {
      cliente->status = '0';
      fseek(fp, (-1)*sizeof(Cadastro), SEEK_CUR);
      fwrite(cliente, sizeof(Cadastro), 1, fp);
      printf("\nCliente excluído com sucesso!!!\n");
      sleep(3);
     } else {
       printf("\nOk, os dados não foram alterados\n");
     }
  } else {
    printf("O Cliente %s não foi encontrado...\n", user->cpf);
  }
  getchar();
  getchar();
  getchar();
  getchar();
  getchar();
  free(cliente);
  fclose(fp);
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
