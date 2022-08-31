#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>


char tela_inicial(void){
    char op;

    system("clear||cls");
    setlocale(LC_ALL,"");
    printf("\n");
    printf("===============================================================================\n");
    printf("===============================================================================\n");
    printf("=============    Universidade Federal do Rio Grande do Norte    ===============\n");
    printf("=============       Centro de Ensino Superior do Seridó         ===============\n");
    printf("=============        Disciplina DCT1106 -- Programação          ===============\n");
    printf("=============  Projeto Locadora de bicicletas e patins elétricos===============\n");
    printf("=============    Developed by @lima_g99 @erick_bzrs - 2022.2    ===============\n");
    printf("~~~                                                                         ~~~\n");
    printf("===============================================================================\n");
    printf("/// = = = = Sistema de Aluguel de bicicletas e patinetes elétricos = = = =  ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Menu Usuário:                                             ///\n");
    printf("///            2. Menu Veicúlos:                                            ///\n");
    printf("///            3. Menu Estoque:                                             ///\n");
    printf("///            4. Menu Aluguel:                                             ///\n");
    printf("///            5. Menu Vendas:                                              ///\n");
    printf("///            6. Menu Administração:                                       ///\n");
    printf("///            7. Menu Sobre:                                               ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///            Escolha por onde você quer navegar:                          ///\n");
    scanf("%c", &op);
    getchar();
    printf("===============================================================================\n");
    printf("===============================================================================\n");
    printf("===============================================================================\n");
    printf("\n");
    printf("\t\t\t<<< ... Aguarde ... >>>\n");
    sleep(1);
    return op;
}