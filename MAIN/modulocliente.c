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
            exibeCliente(user);
            free(user);
            break; 
        case '3':
            excluir = apagarCliente(excluir);
            free(excluir);
            break;
        case '4':
            menu_editar_cliente();
            break;
        case '5':
            menu_procurar_cliente();
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
    printf("===              2.Lista de Clientes:             ===\n");
    printf("===              3.Apagar Cliente:                ===\n");
    printf("===              4.Alterar Cliente:               ===\n");
    printf("===              5.Procurar Cliente:              ===\n");
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
    
        printf(" Digite seu CPF(APENAS NUMEROS): ");
        scanf("%s", cad->cpf);
        getchar();
        
    } while (!validar_cpf(cad->cpf));

//telefone

        printf(" Digite seu telefone: ");   
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

/*void exibeCliente(Cadastro* cliente){
    

    char situacao[20];
    if((cliente == NULL) || (cliente->status == 'x')) {
        printf("Usuário inexistente");
    } else {
    printf("=====================================================\n");
    printf("======SISTEMAS DE BICICLETAS E PATINS ELÉTRICOS======\n");
    printf("================Menu Cliente - Listar================\n");
    printf(" | =============================================== | \n");
    printf(" | Nome: %s\n", cliente->nome);    
    printf(" | CPF: %s\n", cliente->cpf);
    printf(" | Telefone: %s\n", cliente->telefone);
    printf(" | Endereço: %s\n", cliente->endereco);
    printf(" | Dia de nascimento: %d\n", cliente->dd); 
    printf(" | Mês de nascimento: %d\n", cliente->mm); 
    printf(" | Ano de nascimento: %d\n", cliente->aa); 
    printf(" |                                                 | \n");
    printf(" | ================================================| \n");
    system("Pause");
    system(cls | clear);

    } 
    printf("Status: %s\n", situacao);
}*/

void exibeCliente(Cadastro* cl){
	char escolha;
	if ((cl == NULL) || (cl->status == 'x')) {
		printf("\n= = = Cliente Inexistente = = =\n");
		printf("1- Voltar");
		int valid;
		do{
			scanf("%c", &escolha);
			getchar();
			int esc= validarEscolhas(escolha);
			if (esc==0){
				if (escolha=='1'){
					menu_cliente();
				}else{
					valid=1;
				}
			}
		}while(valid==1);
	}else{
		printf("\n");
		printf("||  Nome: %s\n", cl->nome);
		printf("||  cpf: %s\n", cl->cpf);
		printf("||  Telefone: %s\n", cl->telefone);
		printf("||  Endereço: %s\n", cl->endereco);
	}
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

char  menu_procurar_cliente(void){

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
    printf("======SISTEMAS DE BICICLETAS E PATINS ELÉTRICOS======\n");
    printf("================Menu Cliente - Buscar================\n");
    printf("===                                               ===\n");
    printf("===           1.Buscar cliente pelo CPF:          ===\n");
    printf("===           0. Voltar:                          ===\n");
    printf("=====================================================\n");
    scanf("%c", &esc);
    getchar();
    printf("\t\t\t ... Aguarde ...\n");
    sleep(1);

    return esc;
}

