#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "moduloaluguel.h"
#include "validacoes.h"
#include "modulocliente.h"
#include "moduloveiculo.h"

void menu_nav_aluguel(void)
{   
    CadastroAluguel* cadaluguel;
    char esc = ' ';
    do {
        esc = menu_aluguel();
        switch (esc) {
        case '1':
            cadaluguel = preencheAluguel();
            gravaAluguel(cadaluguel);
            free(cadaluguel);
            break;

        case '2':
            cadaluguel = buscaAluguel();
            exibeAluguel(cadaluguel);
            free(cadaluguel);
            break;
        
        case '3':
            listaAluguel();
            break;

        case '4':
            cadaluguel = buscaAluguel();
            apagaAluguel(cadaluguel);
            free(cadaluguel);
            break;

        case '5':
            cadaluguel = buscaAluguel();
            editaAluguel(cadaluguel);
            free(cadaluguel);
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
    printf("===              2.Procurar Aluguel:              ===\n");
    printf("===              3.Listar Aluguel:                ===\n");
    printf("===              4.Apagar Aluguel:                ===\n");
    printf("===              5.Alterar Aluguel:               ===\n");
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

CadastroAluguel* preencheAluguel( ){

    Cadastro* cliente;
    CadastroVeiculo* veiculo;
    CadastroAluguel* cadaaluguel;
    cliente = (Cadastro*) malloc(sizeof(Cadastro));
    veiculo = (CadastroVeiculo*) malloc(sizeof(CadastroVeiculo));
    cadaaluguel = (CadastroAluguel*) malloc(sizeof(CadastroAluguel));

    cliente = buscaCliente();
    exibeCliente(cliente);
    getchar();
    veiculo = buscaVeiculo();
    exibeVeiculo(veiculo);
    getchar();
    free(cliente);
    free(veiculo);

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


            printf(" | Digite o código do veículo que você quer alugar: ");
            scanf(" %9[^\n]", cadaaluguel->cod);
            getchar();


            printf(" | Digite a mensalidade do aluguel: ");
            scanf(" %9[^\n]", cadaaluguel->preco);
            getchar();


        do {

            printf(" Digite o dia do aluguel: ");
            scanf("%d", &cadaaluguel->dd);
            getchar();
            printf(" Digite o mês do aluguel: ");
            scanf("%d", &cadaaluguel->mm);
            getchar();
            printf(" Digite o ano do aluguel: ");
            scanf("%d", &cadaaluguel->aa);
            getchar();
        
        } while(!validar_data(cadaaluguel->dd, cadaaluguel->mm, cadaaluguel->aa));


    cadaaluguel->status = '1';
    return cadaaluguel;

    printf("=== Aluguel foi cadastrado no sistema!!           ===\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf(" Press ENTER to exit...");
    getchar();
}

// Gravar em arquivo
void gravaAluguel(CadastroAluguel* cadaaluguel){
    FILE* fp;
    fp = fopen("aluguel.dat", "ab");
    if (fp ==  NULL){
        printf("Ops, Ocorreu um erro na abertura!/n");
        printf("Não é possivel continuar esse programa... /n");
        exit(1);
    }
    fwrite(cadaaluguel, sizeof(CadastroAluguel), 1, fp);
    fclose(fp);
}

// EXIBE ALUGUEL

void exibeAluguel(CadastroAluguel* cadaaluguel) {
  printf("CPF: %s\n", cadaaluguel->cpf);
  printf("cod: %s\n", cadaaluguel->cod);
  printf("Preço: %s\n", cadaaluguel->preco);
  printf("dia do aluguel: %d\n", cadaaluguel->dd);
  printf("mês do aluguel: %d\n", cadaaluguel->mm);
  printf("ano do aluguel: %d\n", cadaaluguel->aa);
  printf("Status: %c\n", cadaaluguel->status);
  printf("\n");
}  

void apagaAluguel(CadastroAluguel* cadaluguel) {
  FILE* fp;
  CadastroAluguel* cadaaluguel;
  int achou;
  char resp;
  fp = fopen("aluguel.dat", "r+b");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  cadaaluguel = (CadastroAluguel*) malloc(sizeof(CadastroAluguel));
  achou = 0;
  while((!achou) && (fread(cadaaluguel, sizeof(CadastroAluguel), 1, fp))) {
    if ((strcmp(cadaaluguel->cpf, cadaaluguel->cpf) == 0) && (cadaaluguel->status == '1')) {
     achou = 1;
   }
  }
  
  if (achou) {
    exibeAluguel(cadaaluguel);
    printf("Digite 's' duas vezes para apagar o aluguel(s/n)? ");
    scanf("%c\n", &resp);
    if (resp == 's' || resp == 'S') {
      cadaaluguel->status = '0';
      fseek(fp, (-1)*sizeof(CadastroAluguel), SEEK_CUR);
      fwrite(cadaaluguel, sizeof(CadastroAluguel), 1, fp);
      printf("\nAluguel excluído com sucesso!!!\n");
      sleep(3);
     } else {
       printf("\nOk, os dados não foram alterados\n");
     }
  } else {
    printf("O Aluguel %s não foi encontrado...\n", cadaaluguel->cpf);
  }
  getchar();
  getchar();
  free(cadaaluguel);
  fclose(fp);
}


void listaAluguel() {
  FILE* fp;
  CadastroAluguel* cadaaluguel;
  fp = fopen("aluguel.dat", "rb");
  if (fp == NULL) {
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
    printf("================Menu Cliente - Listar================\n");

  cadaaluguel = (CadastroAluguel*) malloc(sizeof(CadastroAluguel));
  while (fread(cadaaluguel, sizeof(CadastroAluguel), 1, fp))
  { // Busca até o final do arquivo
      exibeAluguel(cadaaluguel);
  }
  fclose(fp);
  getchar();
  getchar();
  free(cadaaluguel);
}

CadastroAluguel* buscaAluguel() {

    FILE *fp;
    CadastroAluguel* cadaaluguel;
    char cpf[12];
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
    printf("============Menu Cliente - Buscar Aluguel============\n");
    printf("       Informe o número do seu cpf por gentileza:      ");
    scanf(" %[0-9]", cpf);
    getchar();
    cadaaluguel = (CadastroAluguel*)malloc(sizeof(CadastroAluguel));
    fp = fopen("aluguel.dat", "rb");

    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar o programa");
        exit(1);
    }

    while (!feof(fp))
    { // Busca até o final do arquivo
        fread(cadaaluguel, sizeof(CadastroAluguel), 1, fp);
        if (strcmp(cadaaluguel->cpf, cpf) == 0 && (cadaaluguel->status != 'x'))
        { /*Verifica se o código é igual e o status*/
            fclose(fp);
            return cadaaluguel;
        }
    }

    fclose(fp);
    printf(" Press ENTER to exit...\n");
    getchar();
    return NULL;
}

void editaAluguel(CadastroAluguel* cadaaluguel) {

  FILE* fp;
  char resp;
  char procurado[15];
  fp = fopen("aluguel.dat", "r+b");
  if (cadaaluguel != NULL) {
    exibeAluguel(cadaaluguel);
    getchar();
    printf("Deseja realmente editar este aluguel (s/n)? ");
    scanf("%c", &resp);
    if (resp == 's' || resp == 'S') {


            printf(" | Insira o código do novo veículo: ");
            scanf("%6[^\n]", cadaaluguel->cod);
            getchar();


            printf(" | Digite a mensalidade do novo veículo: ");
            scanf("%9[^\n]", cadaaluguel->preco);
            getchar();


        do {

            printf(" Digite o novo dia do aluguel: ");
            scanf("%d", &cadaaluguel->dd);
            getchar();
            printf(" Digite o novo mês do aluguel: ");
            scanf("%d", &cadaaluguel->mm);
            getchar();
            printf(" Digite o novo ano do aluguel: ");
            scanf("%d", &cadaaluguel->aa);
            getchar();
        
        } while(!validar_data(cadaaluguel->dd, cadaaluguel->mm, cadaaluguel->aa));



      cadaaluguel->status = '1';

      fseek(fp, (-1)*sizeof(CadastroAluguel), SEEK_CUR);
      fwrite(cadaaluguel, sizeof(CadastroAluguel), 1, fp);
      getchar();
      printf("\nAluguel editado com sucesso!!!\n");

    } else {
      printf("\nOk, os dados não foram alterados\n");
    }

  } else 
  {
    printf("O Aluguel %s não foi encontrado...\n", procurado);
  }

  free(cadaaluguel);
  fclose(fp);
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