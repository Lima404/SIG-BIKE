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
    Apagar* excluir;
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
            exibeCliente(user);
            free(user);
            break; 
        case '4':
            excluir = apagarCliente(excluir);
            free(excluir);
            break;            
        case '5':
            menu_editar_cliente();
            break;
        default:
            printf ("Opção Inválida\n");
            break;
    }

    } while(esc != '0');
}


char menu_cliente(void){
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
    printf("=====================Menu Cliente====================\n");
    printf("===                                               ===\n");
    printf("===              1.Cadastro Cliente:              ===\n");
    printf("===              2.Procurar Cliente:              ===\n");
    printf("===              3.Lista de Clientes:             ===\n");
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

Cadastro* preencheCliente(void){

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
    printf("======SISTEMAS DE BICICLETAS E PATINS ELÉTRICOS======\n");
    printf("================Menu Cliente - Cadastro==============\n");
    printf("===                                               ===\n");
    
//Nome

    do{
        printf(" Digite seu nome por favor: ");
        scanf("%80[^\n]", cad->nome);                            //executa tudo isso até que a condição da função seja satisfeita
        getchar();
        
    } while (!validar_nome(cad->nome));

//CPF

    do{
    
        printf(" Digite seu CPF(APENAS NUMEROS SEM ESPAÇO): ");
        scanf("%s", cad->cpf);
        getchar();
        
    } while (!validar_cpf(cad->cpf));

//telefone

        printf(" Digite seu telefone(XXXXX-XXXX): ");   
        scanf("%20[^\n]", cad->telefone);
        getchar();

//endereço

        printf(" Digite seu endereço: ");
        scanf("%40[^\n]", cad->endereco);
        getchar();

// Data de nascimento

    do {
        printf(" Digite o dia que você nasceu por favor: ");
        scanf("%d", &cad->dd);
        getchar();
        printf(" Digite o seu mês de nascimento: ");
        scanf("%d", &cad->mm);
        getchar();
        printf(" digite o seu ano de nascimento: ");
        scanf("%d", &cad->aa);
        getchar();
        
    } while(!validar_data(cad->dd, cad->mm, cad->aa));
    cad->status = 't';
    return cad;

    printf("=== Usuário foi cadastrado no sistema!            ===\n");
    printf("===                                               ===\n");
    getchar();
}



// Gravar em arquivo

void gravaCliente(Cadastro* cad){
    FILE* fp;
    fp = fopen("cliente.dat", "ab");
    if (fp ==  NULL){
        printf("Ops, Ocorreu um erro na abertura!/n");
        printf("Não é possivel continuar esse programa... /n");
        exit(1);
    }
    fwrite(cad, sizeof(Cadastro), 1, fp);
    fclose(fp);
}

//  LISTA DE CLIENTES

void exibeCliente(Cadastro* cliente) {
  printf("CPF: %s\n", cliente->cpf);
  printf("Nome: %s\n", cliente->nome);
  printf("telefone: %s\n", cliente->telefone);
  printf("endereco: %s\n", cliente->endereco);
  printf("Nascimento(dia): %d\n", cliente->dd);
  printf("Nascimento(mes): %d\n", cliente->mm);
  printf("Nascimento(ano): %d\n", cliente->aa);
  printf("Status: %c\n", cliente->status);
  printf("\n");
}   

//

Cadastro* buscaCliente(void) {
  FILE* fp;
  Cadastro* cliente;
  int achou;
  char procurado[15];
  fp = fopen("cliente.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
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
    printf("================Menu Cliente - Buscar================\n");
    printf("Informe o nome do cliente a ser buscado: ");
    
  scanf(" %14[^\n]", procurado);
  cliente = (Cadastro*) malloc(sizeof(Cadastro));
  achou = 0;
  
  while((!achou) && (fread(cliente, sizeof(Cadastro), 1, fp))) {
   if ((strcmp(cliente->cpf, procurado) == 0) && (cliente->status == '1')) {
     achou = 1;
   }
  }
  fclose(fp);
  if (achou) {
    exibeCliente(cliente);
  } else {
    printf("O Cliente %s não foi encontrado...\n", procurado);
  }
  free(cliente);
}

// APAGAR CLIENTE

Apagar* apagarCliente( ){

    Apagar* apa;
    apa = (Apagar*) malloc(sizeof(Apagar));
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
    printf("=================Menu Cliente - Apagar===============\n");
    printf("===                                               ===\n");

    do{
        printf(" Digite seu CPF por favor: ");
        scanf("%s", apa->cpf);
        getchar();
        
    } while (!validar_cpf(apa->cpf));

    printf("=== O usuário foi deletado com sucesso!!          ===\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf(" Press ENTER to exit...\n");
    scanf("%c", &esc);
    getchar();
    
    return apa;
}

char menu_editar_cliente(void){

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
    printf("================Menu Cliente - Editar================\n");
    printf("===                                               ===\n");
    printf("===              1.Editar Nome:                   ===\n");
    printf("===              2.Editar CPF:                    ===\n");
    printf("===              3.Editar E-mail:                 ===\n");
    printf("===              4.Editar Data de Nascimento:     ===\n");
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
