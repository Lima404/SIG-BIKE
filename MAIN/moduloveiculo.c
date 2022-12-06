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
            free(cadveiculo);
            break; 

        case '3':
            listaVeiculo();
            break;
        case '4':
            cadveiculo = buscaVeiculo();
            apagaVeiculo(cadveiculo);
            free(cadveiculo);
            break;

        case '5':
            cadveiculo = buscaVeiculo();
            editaVeiculo(cadveiculo);
            free(cadveiculo);
            break;

        default:
            printf ("Opção Inválida\n");
            break;
        
        }
    } while(esc != '0');
}

char menu_veiculo(void)
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
  printf("=====================Menu Veículo====================\n");
  printf("===                                               ===\n");
  printf("===              1.Cadastro Veículo               ===\n");
  printf("===              2.Buscar Veículo                 ===\n");
  printf("===              3.Listar Veículos                ===\n");
  printf("===              4.Apagar Veículo                 ===\n");
  printf("===              5.Alterar Veículo                ===\n");
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

CadastroVeiculo* preencheVeiculo(void)
{
    
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
  printf("===         Tipos de veículos:                    ===\n");
  printf("===          Bike                                 ===\n");
  printf("===          Patins Elétricos                     ===\n");
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

void gravaVeiculo(CadastroVeiculo* cadaveiculo)
{
    FILE* fp;
    fp = fopen("veiculo.dat", "ab");
    if (fp == NULL)
    {
        printf("Ops, Ocorreu um erro na abertura!/n");
        printf("Não é possivel continuar esse programa... /n");
        exit(1);
    }
    fwrite(cadaveiculo, sizeof(CadastroVeiculo), 1, fp);
    fclose(fp);
}

// EXIBE VEICULO

void exibeVeiculo(CadastroVeiculo* cadveiculo)
{
    printf("Tipo do veiculo: %s\n", cadveiculo->tipo);
    printf("Marca do veiculo: %s\n", cadveiculo->marca);
    printf("Descrição do veiculo: %s\n", cadveiculo->desc);
    printf("Código do veiculo: %s\n", cadveiculo->cod);
    printf("Preço do veiculo: %s\n", cadveiculo->preco);
    printf("Status: %c\n", cadveiculo->status);
    printf("\n");
}

void listaVeiculo() 
{

  FILE* fp;
  CadastroVeiculo* cadveiculo;
  fp = fopen("veiculo.dat", "rb");
  if (fp == NULL) 
  {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
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
    printf("================Menu Veículo - Listar================\n");

  cadveiculo = (CadastroVeiculo*) malloc(sizeof(CadastroVeiculo));
  while (fread(cadveiculo, sizeof(CadastroVeiculo), 1, fp))
  { // Busca até o final do arquivo
      exibeVeiculo(cadveiculo);
  }
  fclose(fp);
  printf(" Press ENTER to exit...\n");
  getchar();
  free(cadveiculo);
}

// BUSCA VEICULO

CadastroVeiculo* buscaVeiculo() 
{

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
    printf(" Press ENTER to exit...\n");
    getchar();
    return NULL;
}

// APAGAR VEICULO

void apagaVeiculo(CadastroVeiculo* cadveiculo) 
{

  FILE* fp;
  CadastroVeiculo* veiculo;
  int achou;
  char resp;
  fp = fopen("veiculo.dat", "r+b");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  veiculo = (CadastroVeiculo*) malloc(sizeof(CadastroVeiculo));
  achou = 0;
  while((!achou) && (fread(veiculo, sizeof(CadastroVeiculo), 1, fp))) {
    if ((strcmp(veiculo->cod, cadveiculo->cod) == 0) && (veiculo->status == '1')) {
     achou = 1;
   }
  }
  
  if (achou) {
    exibeVeiculo(veiculo);
    printf("Digite 's' duas vezes para apagar o veículo(s/n)? ");
    scanf("%c\n", &resp);
    if (resp == 's' || resp == 'S') {
      veiculo->status = '0';
      fseek(fp, (-1)*sizeof(CadastroVeiculo), SEEK_CUR);
      fwrite(veiculo, sizeof(CadastroVeiculo), 1, fp);
      printf("\nVeiculo excluído com sucesso!!!\n");
      sleep(3);
     } else {
       printf("\nOk, os dados não foram alterados\n");
     }
  } else {
    printf("O veiculo %s não foi encontrado...\n", cadveiculo->cod);
  }

  getchar();
  getchar();
  free(veiculo);
  fclose(fp);
}

void editaVeiculo(CadastroVeiculo* cadveiculo) 
{

  FILE* fp;
  char resp;
  int achou = 0;

  CadastroVeiculo* aux_veiculo = (CadastroVeiculo*) malloc(sizeof(CadastroVeiculo));

  fp = fopen("veiculo.dat", "r+b");
  if (cadveiculo != NULL) {
    exibeVeiculo(cadveiculo);
    getchar();
    printf("Deseja realmente editar este veículo (s/n)? ");
    scanf("%c", &resp);
    getchar();
    if (resp == 's' || resp == 'S') {

      do{

      printf(" | Digite o novo tipo do veículo(PATINS ou BIKE): ");
      scanf("%20[^\n]", cadveiculo->tipo);
      getchar();

    } while (!validar_nome(cadveiculo->tipo));

    // Marca

      do{

      printf(" | Digite a nova marca do veículo: ");
      scanf("%20[^\n]", cadveiculo->marca); 
      getchar();

      } while (!validar_nome(cadveiculo->marca));

// Descrição

      printf(" | Digite uma nova descrição sobre o veículo: ");   
      scanf("%100[^\n]", cadveiculo->desc);
      getchar();

// CÓDIGO DE RASTREIO

      printf(" | Digite um novo código pra registrar o veículo(6 números): ");
      scanf("%s", cadveiculo->cod);
      getchar();

    // PREÇO

      printf(" | Digite o  novo preço em reais(APENAS NÚMEROS): ");
      scanf("%20[^\n]", cadveiculo->preco);
      getchar();

      while(!feof(fp) && achou == 0) 
      {
        fread(aux_veiculo, sizeof(CadastroVeiculo), 1, fp);

         if ((strcmp(aux_veiculo->cod, cadveiculo->cod) == 0) && (cadveiculo->status == '1')){
            achou = 1;

            fseek(fp, (-1)*sizeof(CadastroVeiculo), SEEK_CUR);

            fwrite(cadveiculo, sizeof(CadastroVeiculo), 1, fp);

         }
      }

      getchar();
      printf("\nVeículo editado com sucesso!!!\n");
      printf(" Press ENTER to exit...\n");
      getchar();

    } else {
      printf("\nOk, os dados não foram alterados\n");
    }


     }

  free(aux_veiculo);
  free(cadveiculo);
  fclose(fp);
}

