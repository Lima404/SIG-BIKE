#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>

char menu_vendas(void){
    char op;

    system("clear||cls");
    setlocale(LC_ALL,"");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///            Projeto Locadora de bicicletas e patins elétricos            ///\n");
    printf("///              Developed by @lima_g99 @erick_bzrs - 2022.2                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("/// = = = = = = = = = = = = = = Menu de Vendas = = = = = = = = = = = = = = =///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastro de Vendas:                                       ///\n");
    printf("///            2. Lista de Vendas:                                          ///\n");
    printf("///            3. Deletar Vendas:                                           ///\n");
    printf("///            4. Editar Vendas:                                            ///\n");
    printf("///            0. Voltar:                                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha por onde você quer navegar:                          ///\n");
    scanf("%c", &op);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t<<< ... Aguarde ... >>>\n");
    sleep(1);
    return op;
}