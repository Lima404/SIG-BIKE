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

        /*case '2':
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
            break;*/

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


            printf(" | Digite o código do veiculo que você quer alugar: ");
            scanf("%6[^\n]", cadaaluguel->cod);
            getchar();


            printf(" | Digite o preço do aluguel: ");
            scanf("%9[^\n]", cadaaluguel->preco);
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
  printf("Nome: %s\n", cadaaluguel->cod);
  printf("Preço: %s\n", cadaaluguel->preco);
  printf("dia do aluguel: %d\n", cadaaluguel->dd);
  printf("mês do aluguel: %d\n", cadaaluguel->mm);
  printf("ano do aluguel: %d\n", cadaaluguel->aa);
  printf("Status: %c\n", cadaaluguel->status);
  printf("\n");
}  

/*CadastroAluguel* apagaAluguel( ){
    
    CadastroAluguel* cadaluguel;
    cadaluguel =(CadastroAluguel*) malloc(sizeof(CadastroAluguel));

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
    printf("=================Menu Aluguel - Apagar===============\n");
    printf("===                                               ===\n");

    do{

        printf(" | Digite seu CPF, (só numeros): ");
        scanf("%s", apaaluguel->cpf); 
        getchar();

    }while (!validar_cpf(apaaluguel->cpf));

    printf("=== Usuário foi deletado com sucesso!!            ===\n");
    printf("===                                               ===\n");
    printf("===                                               ===\n");
    printf(" Press ENTER to exit...\n");
    getchar();
    
    return apaaluguel;

}*/

char menu_editar_aluguel(void){
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
    printf("================Menu Aluguel - Editar================\n");
    printf("===                                               ===\n");
    printf("===              1.Editar Nome:                   ===\n");
    printf("===              2.Editar CPF:                    ===\n");
    printf("===              3.Editar Telefone:               ===\n");
    printf("===              4.Editar Código:                 ===\n");
    printf("===              5.Editar Endereço:               ===\n");
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
