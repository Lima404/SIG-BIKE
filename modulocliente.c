#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include "modulocliente.h"
//char cadastro_usuario(void);
//har lista_usuario(void);
//char apagar_usuario(void);
//char editar_usuario(void);

char menu_usuario(void){
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
    printf("/// = = = = = = = = = = = = = = Menu de Usuário = = = = = = = = = = = = = = ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastro de Usuário:                                      ///\n");
    printf("///            2. Lista de Usuários:                                        ///\n");
    printf("///            3. Apagar Usuários:                                          ///\n");
    printf("///            4. Editar Usuários:                                          ///\n");
    printf("///            0. Voltar:                                                   ///\n");
    printf("///                                                                         ///\n");
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