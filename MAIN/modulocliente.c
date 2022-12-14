#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "modulocliente.h"
#include "validacoes.h"


void menu_nav_cliente(void)
{   
    Cadastro* user;
    char esc = ' ';
    do {
        esc = menu_cliente();
        switch (esc) {
        case '1':
            user = preencheCliente();
            gravaCliente(user);
            free(user);
            break;

        case '2':
            user = buscaCliente();
            exibeCliente(user);
            free(user);
            break;

        case '3':
            listaCliente();
            break;

        case '4':
            user = buscaCliente();
            apagaCliente(user);
            free(user);
            break;

        case '5':
            user = buscaCliente();
            editaCliente(user);
            free(user);
            break;

        default:
            printf ("Opção Inválida\n");
            break;
    }

    } while(esc != '0');
}

// menu cliente
char menu_cliente(void)
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
  printf("======SISTEMAS DE BICICLETAS E PATINS ELÉTRICOS======\n");
  printf("==================== Menu Cliente ===================\n");
  printf("===                                               ===\n");
  printf("===              1.Cadastro Cliente:              ===\n");
  printf("===              2.Procurar Cliente:              ===\n");
  printf("===              3.Listar Clientes:               ===\n");
  printf("===              4.Apagar Cliente:                ===\n");
  printf("===              5.Alterar Cliente:               ===\n");
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


// preenche cliente
Cadastro* preencheCliente(void)
{

  Cadastro* cad;
  cad = (Cadastro*) malloc(sizeof(Cadastro));
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
  printf("=============== Menu Cliente - Cadastro =============\n");
  printf("===                                               ===\n");
    
//Nome

    do{
      
        printf(" Digite seu nome: ");
        scanf("%80[^\n]", cad->nome);                            //executa tudo isso até que a condição da função seja satisfeita
        getchar();
        
    } while (!validar_nome(cad->nome));

//CPF

    do{
    
        printf(" Digite seu CPF(APENAS NÚMEROS): ");
        scanf("%s", cad->cpf);
        getchar();
        
    } while (!validar_cpf(cad->cpf) || !valida_cliente(cad->cpf));

//telefone

        printf(" Digite seu telefone(XXXXX-XXXX): ");   
        scanf("%20[^\n]", cad->telefone);
        getchar();

//endereço

        printf(" Digite seu endereço: ");
        scanf("%140[^\n]", cad->endereco);
        getchar();

// Data de nascimento

    do {

        printf(" Digite o seu dia de nascimento: ");
        scanf("%d", &cad->dd);
        getchar();
        printf(" Digite o seu mês de nascimento: ");
        scanf("%d", &cad->mm);
        getchar();
        printf(" Digite o seu ano de nascimento: ");
        scanf("%d", &cad->aa);
        getchar();
        
    } while(!validar_data(cad->dd, cad->mm, cad->aa));
    
    
    cad->status = '1';
    return cad;

    printf("=== Usuário foi cadastrado no sistema!            ===\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf(" Press ENTER to exit...\n");
    getchar();
}



// Gravar em arquivo

void gravaCliente(Cadastro* cad)
{
    FILE* fp;
    fp = fopen("cliente.dat", "ab");
    if (fp ==  NULL)
    {
        printf("Ops, Ocorreu um erro na abertura!/n");
        printf("Não é possível continuar esse programa... /n");
        exit(1);
    }
    fwrite(cad, sizeof(Cadastro), 1, fp);
    fclose(fp);
}

//  EXIBIR CLIENTES

void exibeCliente(Cadastro* cliente) 
{
  printf("CPF: %s\n", cliente->cpf);
  printf("Nome: %s\n", cliente->nome);
  printf("Telefone: %s\n", cliente->telefone);
  printf("Endereco: %s\n", cliente->endereco);
  printf("Nascimento(dia): %d\n", cliente->dd);
  printf("Nascimento(mes): %d\n", cliente->mm);
  printf("Nascimento(ano): %d\n", cliente->aa);
  printf("Status: %c\n", cliente->status);
  printf("\n");
}  

// Lista Clientes

void listaCliente() 
{
  
  FILE* fp;
  Cadastro* cliente;
  fp = fopen("cliente.dat", "rb");
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
    printf("===== SISTEMAS DE BICICLETAS E PATINS ELÉTRICOS =====\n");
    printf("=============== Menu Cliente - Listar ===============\n");

  cliente = (Cadastro*) malloc(sizeof(Cadastro));
  while (fread(cliente, sizeof(Cadastro), 1, fp))
  { // Busca até o final do arquivo
      exibeCliente(cliente);
  }

  fclose(fp);
  printf(" Press ENTER to exit...\n");
  getchar();
  free(cliente);
}

// Buscar cliente

Cadastro* buscaCliente() 
{

    FILE *fp;
    Cadastro* cad;
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
    printf("=========== Menu Cliente - Buscar Cliente ===========\n");
    printf("       Informe o número do seu cpf por gentileza:      ");
    scanf(" %[0-9]", cpf);
    getchar();
    cad = (Cadastro*)malloc(sizeof(Cadastro));
    fp = fopen("cliente.dat", "rb");

    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo, não é possível continuar o programa");
        exit(1);
    }

    while (!feof(fp))
    {                                      // Busca até o final do arquivo
        fread(cad, sizeof(Cadastro), 1, fp);
        if (strcmp(cad->cpf, cpf) == 0 && (cad->status != 'x'))
        {                                  /*Verifica se o código é igual e o status*/
            fclose(fp);
            return cad;
        }
    }

    fclose(fp);
    printf(" Press ENTER to exit...\n");
    getchar();
    return NULL;
}


// APAGAR CLIENTE

void apagaCliente(Cadastro* user) 
{

  FILE* fp;
  Cadastro* cliente;
  int achou;
  char resp;
  fp = fopen("cliente.dat", "r+b");
  if (fp == NULL) 
  {
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
  
  if (achou) 
  {
    exibeCliente(cliente);
    printf("Digite 's' duas vezes para apagar o cliente(s/n)? ");
    scanf("%c\n", &resp);
    if (resp == 's' || resp == 'S') 
    {
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
  free(cliente);
  fclose(fp);
}

// EDITAR CLIENTE
void editaCliente(Cadastro* cliente) 
{

  FILE* fp;
  char resp;
  int achou = 0;

  Cadastro* aux_cliente = (Cadastro*) malloc(sizeof(Cadastro));

  fp = fopen("cliente.dat", "r+b");
  if (cliente != NULL) 
  {
    exibeCliente(cliente);
    getchar();
    printf("Deseja realmente editar este cliente (s/n)? ");
    scanf("%c", &resp);
    getchar();
    if (resp == 's' || resp == 'S') {

        do {
          
        printf(" Digite seu novo nome: ");
        scanf("%80[^\n]", cliente->nome);                            //executa tudo isso até que a condição da função seja satisfeita
        getchar();
        
        } while (!validar_nome(cliente->nome));


        printf(" Digite seu novo telefone(XXXXX-XXXX): ");   
        scanf("%20[^\n]", cliente->telefone);
        getchar();


        printf(" Digite seu novo endereço: ");
        scanf("%40[^\n]", cliente->endereco);
        getchar();


        do {
          
        printf(" Digite o seu novo dia de nascimento: ");
        scanf("%d", &cliente->dd);
        getchar();
        printf(" Digite o seu novo mês de nascimento: ");
        scanf("%d", &cliente->mm);
        getchar();
        printf(" Digite o seu novo ano de nascimento: ");
        scanf("%d", &cliente->aa);
        getchar();

        } while(!validar_data(cliente->dd, cliente->mm,  cliente->aa));

        while(!feof(fp) && achou == 0) 
        {
          fread(aux_cliente, sizeof(Cadastro), 1, fp);

         if ((strcmp(aux_cliente->cpf, cliente->cpf) == 0) && (cliente->status == '1')){
            achou = 1;

            fseek(fp, (-1)*sizeof(Cadastro), SEEK_CUR);

            fwrite(cliente, sizeof(Cadastro), 1, fp);

         }
      }

      getchar();
      printf("\nCliente editado com sucesso!!!\n");
      printf(" Press ENTER to exit...\n");
      getchar();

    } else {
      printf("\nOk, os dados não foram alterados\n");
    }


     }

  free(aux_cliente);
  free(cliente);
  fclose(fp);
}

int valida_cliente(char* cpf)
{
    FILE *fp;
    Cadastro *cad;

    cad= (Cadastro *)malloc(sizeof(Cadastro));
    fp = fopen("cliente.dat", "r+b");

    if(fp == NULL){
        return 1;
    }
    
    while (!feof(fp))
    {
        fread(cad, sizeof(Cadastro), 1, fp);
        if (strcmp(cpf, cad->cpf) == 0 && (cad->status != 'x'))
        {
            printf("\n\tCPF já cadastrado, tente outro\n");
            fclose(fp);
            return 0;
        }
    }

    fclose(fp);
    return 1;
}