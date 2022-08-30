<<<<<<< Updated upstream
#include<stdio.h>
    
=======
#include <stdio.h>
///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///     Projeto Sistema de de aluguel de patins elétricos e bicicletas      ///
///         Developed by @lima_g23 / @erick_bzrs -- since Mar, 2022         ///
///////////////////////////////////////////////////////////////////////////////


//////
////// funções
//////

char tela_inicial (void);
void menu_usuario(void);
void menu_veiculos (void);
void menu_estoque (void);
void menu_aluguel (void);
void menu_vendas (void);
void menu_sobre (void);
void menu_adm (void);



//////
////// Programa principal
//////

int main(void){
    char opcao;

    do {
        opcao = tela_inicial();
        switch (opcao){
        case '1': menu_aluguel();
            break;
        
        case '2': menu_veiculos();
            break;
        
        case '3': menu_estoque();
            break;

        case '4': menu_aluguel();
            break;

        case '5': menu_vendas();
            break;

        case '6': menu_sobre();
            break;

        case '7': menu_adm();
            break;
        }
    }   while (opcao != "0");
        return 0
;}


/// crud tela inicial

char tela_inicial(void){
    char op;

    system("clear||cls");
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
>>>>>>> Stashed changes
