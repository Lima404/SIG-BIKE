#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
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
            getchar();
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

char menu_aluguel(void)
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
    printf("===== SISTEMAS DE BICICLETAS E PATINS ELÉTRICOS =====\n");
    printf("==================== Menu Aluguel ===================\n");
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

CadastroAluguel* preencheAluguel( )
{
    CadastroAluguel* cadaaluguel;
    cadaaluguel = (CadastroAluguel*) malloc(sizeof(CadastroAluguel));
    char* nome_cliente;
    char* nome_veiculo;
    char* data;
    char devolucao[20];
    char cpf[12];

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
    printf("===== SISTEMAS DE BICICLETAS E PATINS ELÉTRICOS =====\n");
    printf("=============== Menu Aluguel - Cadastro =============\n");
    printf("===                                               ===\n");

// busca nome cliente


    do{

      printf("Digite seu CPF: ");
      scanf("%s", cadaaluguel->cpf);
      getchar();

    } while (!validar_cpf(cadaaluguel->cpf));


   nome_cliente = get_nome_cliente(cadaaluguel->cpf);
  if (nome_cliente != NULL) 
  {
     printf("Nome do cliente: %s\n", nome_cliente);
     free(nome_cliente);
   } else {
     printf("Ops, usuário não encontrado");
     return NULL;
   }


// busca marca veiculo

    printf(" | Digite o código do veículo que você quer alugar: ");
    scanf(" %6[^\n]", cadaaluguel->cod);
    getchar();

    nome_veiculo = get_nome_veiculo(cadaaluguel->cod);
  if (nome_veiculo != NULL) 
  {
     printf("Nome do veiculo: %s\n", nome_veiculo);
     free(nome_veiculo);
   } else {
     printf("Ops, usuário não encontrado");
     return NULL;
   }


    printf(" | Digite a mensalidade do aluguel: ");
    scanf(" %9[^\n]", cadaaluguel->preco);
    getchar();

    do{

    printf(" | Digite quantos meses você quer alugar: ");
    scanf(" %9[^\n]", devolucao);
    getchar();

    }while(!validarNumInteiro(devolucao));

    strcpy(cpf, cadaaluguel->cpf);

    data = verDiaMesAno();
    strcpy(cadaaluguel->data, data);
    printf(" | Data do aluguel: ");
    calculadata(data, devolucao, cadaaluguel->devolucao);
    printf("\n | Data de retorno: %d/%d/%d\n", cadaaluguel->devolucao[0], cadaaluguel->devolucao[1], cadaaluguel->devolucao[2]);
    
    free(data);
    //free(cadaaluguel);

    cadaaluguel->status = '1';
    

    printf("\n=== Aluguel foi cadastrado no sistema!!           ===\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf(" Press ENTER to exit...");
    getchar();

    return cadaaluguel;

}

// Gravar em arquivo
void gravaAluguel(CadastroAluguel* cadaaluguel)
{
    FILE* fp;
    fp = fopen("aluguel.dat", "ab");
      if (fp ==  NULL){
        printf("Ops, Ocorreu um erro na abertura!/n");
        printf("Não é possível continuar esse programa... /n");
        exit(1);
    }
    fwrite(cadaaluguel, sizeof(CadastroAluguel), 1, fp);
    fclose(fp);
    free(cadaaluguel);
}

// EXIBE ALUGUEL

void exibeAluguel(CadastroAluguel* cadaaluguel)
{

  printf("CPF: %s\n", cadaaluguel->cpf);
  printf("Cod: %s\n", cadaaluguel->cod);
  printf("Preço da mensalidade: %s\n", cadaaluguel->preco);
  printf("Data de devolucao; %d/%d/%d\n", cadaaluguel->devolucao[0], cadaaluguel->devolucao[1], cadaaluguel->devolucao[2]);
  printf("Data do aluguel: %s\n", cadaaluguel->data);
  printf("Status: %c\n", cadaaluguel->status);
  printf("\n");

}  

void apagaAluguel(CadastroAluguel* cadaluguel) 
{
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


void listaAluguel() 
{
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
    printf("===== SISTEMAS DE BICICLETAS E PATINS ELÉTRICOS =====\n");
    printf("=============== Menu Aluguel - Listar ===============\n");

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

CadastroAluguel* buscaAluguel() 
{

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
    printf("===== SISTEMAS DE BICICLETAS E PATINS ELÉTRICOS =====\n");
    printf("=========== Menu Aluguel - Buscar Aluguel ===========\n");
    printf("       Informe o número do seu cpf por gentileza:      ");
    scanf(" %[0-9]", cpf);
    getchar();
    cadaaluguel = (CadastroAluguel*)malloc(sizeof(CadastroAluguel));
    fp = fopen("aluguel.dat", "rb");

    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo, não é possível continuar o programa");
        exit(1);
    }

    while (!feof(fp))
    { // Busca até o final do arquivo
        fread(cadaaluguel, sizeof(CadastroAluguel), 1, fp);
        printf(">>> valor lido: %s\n", cadaaluguel->cpf);
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

void editaAluguel(CadastroAluguel* cadaaluguel) 
{

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

// char busca nome cliente


char* get_nome_cliente(char* cpf) 
{

  Cadastro* cad;
  FILE* fp;
  char* nome;

  nome = (char*) malloc(81*sizeof(char));

  cad = (Cadastro*)malloc(sizeof(Cadastro));
  fp = fopen("cliente.dat", "rb");

    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar o programa");
        exit(1);
    }

    while (!feof(fp))
    { // Busca até o final do arquivo
        fread(cad, sizeof(Cadastro), 1, fp);
        if (strcmp(cad->cpf, cpf) == 0 && (cad->status != 'x'))
        { /*Verifica se o código é igual e o status*/
            fclose(fp);
            strcpy(nome, cad->nome);
            free(cad);
            return nome;
        }
    }

    fclose(fp);
    free(cad);
    return NULL;

}


// char busca marca veiculo


char* get_nome_veiculo(char* cod) 
{

  CadastroVeiculo* cadaveiculo;
  FILE* fp;
  char* marca;

  marca = (char*) malloc(81*sizeof(char));

  cadaveiculo = (CadastroVeiculo*)malloc(sizeof(CadastroVeiculo));
  fp = fopen("veiculo.dat", "rb");

    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar o programa");
        exit(1);
    }

    while (!feof(fp))
    { // Busca até o final do arquivo
        fread(cadaveiculo, sizeof(CadastroVeiculo), 1, fp);
        if (strcmp(cadaveiculo->cod, cod) == 0 && (cadaveiculo->status != 'x'))
        { /*Verifica se o código é igual e o status*/
            fclose(fp);
            strcpy(marca, cadaveiculo->marca);
            free(cadaveiculo);
            return marca;
        }
    }

    fclose(fp);
    free(cadaveiculo);
    return NULL;

}


char menu_lista_disp(void)
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

char* verDiaMesAno(void) {

    char* data = (char*) malloc(20 * sizeof(char));

    time_t tempo = time(NULL);

    struct tm* t = localtime(&tempo);

    strftime(data, 50, "%d%m%y", t);

    // dia, mes, ano

    return data;

}

void calculadata(char* data, char* meses, int* structdata) //DAYANNE NOS AJUDOU
{
  int data_aux[3] = { };
  char* dia = dividPal(data,0,1);
  char* ano = dividPal(data,4,5);
  char* mes = dividPal(data,2,3);

  int diaint = atoi(dia);
  printf("%d",diaint);
  printf("/");
  int mesint = atoi(mes);
  printf("%d",mesint);
  printf("/");
  int anoint = atoi(ano) + 2000;
  printf("%d",anoint);
  getchar();

  int calcula = diaDoAno(diaint, mesint, anoint);
  
  int calculo = 0;

  int mesesint = atoi(meses);
  calculo = mesesint * 30;
  calculo = calcula + calculo;
  diaParaData(calculo, anoint, data_aux);

  structdata[0] = data_aux[0];
  structdata[1] = data_aux[1];
  structdata[2] = data_aux[2];
}
