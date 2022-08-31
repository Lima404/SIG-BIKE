#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///     Projeto Sistema de de aluguel de patins elétricos e bicicletas      ///
///         Developed by @lima_g23 / @erick_bzrs -- since Mar, 2022         ///
///////////////////////////////////////////////////////////////////////////////
///                                 SEMANA 1                                ///
///////////////////////////////////////////////////////////////////////////////



////// funções:

char tela_inicial (void);
char menu_usuario(void);
char menu_veiculos (void);
char menu_estoque (void);
char menu_aluguel (void);
//char menu_vendas (void);
//char menu_sobre (void);
//char menu_adm (void);

/////////////////////////////////////////////////////////////////////////////

/// funções para menu usuario:


//char cadastro_usuario(void);
//char lista_usuario(void);
//char apagar_usuario(void);
//char editar_usuario(void);

////////////////////////////////////////////////////////////////////////////

/// Funções para menu Veiculos:

//char cadastro_veiculo(void);
//char lista_veiculo(void);
//char apagar_veiculo(void);
//char editar_veiculo(void);
//char manutencao(void);
//char lista_manutencao(void);

///////////////////////////////////////////////////////////////////////////

/// Funções para menu estoque:

//char cadastro_produto(void);
//char lista_produto(void);
//char editar_produto(void);
//char apagar_produto(void);
//char lista_falta(void);

//////
////// Navegação principal:
//////

int main(void){
    char opcao;

    do {
        opcao = tela_inicial();
        switch (opcao){
        case '1': menu_usuario();
            break;
        
        case '2': menu_veiculos();
            break;
        
        case '3': menu_estoque();
            break;

        case '4': menu_aluguel();
            break;

        case '5': //menu_vendas();
            break;

        case '6': //menu_sobre();
            break;

        case '7': //menu_adm();
            break;

        case "0":
            printf("fim do programa");
            break;

        default:
            printf("Opção invalida, Por favor, insira uma opção válida.");
        }
    }   
    
}


/// crud tela inicial:

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

/// Navegação Módulo usuário:

int main(void){
    char opcao;

    do {
        opcao = menu_usuario();
        switch (opcao){
        case '1': //cadastro_usuario();
            break;
        
        case '2': //lista_usuario();
            break;
        
        case '3': //apagar_usuario();
            break;

        case '4': //editar_usuario();
            break;

        case "0":
            tela_inicial()
            break;
        }
    }   
    
}

/// CRUD MENU USUÁRIO:

char menu_usuario(void){
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
    printf("/// = = = = = = = = = = = = = = Menu de Usuário = = = = = = = = = = = = = = ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastro de Usuário:                                      ///\n");
    printf("///            2. Lista de Usuários:                                        ///\n");
    printf("///            3. Apagar Usuários:                                          ///\n");
    printf("///            4. Editar Usuários:                                          ///\n");
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


/// Navegação Módulo Veiculos

int main(void){
    char opcao;

    do {
        opcao = menu_veiculos();
        switch (opcao){
        case '1': //cadastro_veiculo();
            break;
        
        case '2': //lista_veiculo();
            break;
        
        case '3': //apagar_veiculo();
            break;

        case '4': //editar_veiculo();
            break;

        case '5': //manutencao();
            break;

        case '6': //lista_manutencao();
            break;

        case "0":
            tela_inicial()
            break;
        }
    }   
}


/// crud menu veiculos:

char menu_veiculos(void){
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
    printf("/// = = = = = = = = = = = = = = Menu de Veiculo = = = = = = = = = = = = = = ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastro de Veiculos:                                     ///\n");
    printf("///            2. Lista de Veiculos:                                        ///\n");
    printf("///            3. Apagar veiculo:                                           ///\n");
    printf("///            4. Editar lista de Veiculo:                                  ///\n");
    printf("///            5. Agendar Manutenção de Veiculo:                            ///\n");
    printf("///            6. Lista de manutenção:                                      ///\n");
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

/// Navegação Módulo Estoque:

int main(void){
    char opcao;

    do {
        opcao = menu_estoque();
        switch (opcao){
        case '1': //cadastro_produto();
            break;
        
        case '2': //lista_produto();
            break;
        
        case '3': //editar_produto();
            break;

        case '4': //apagar_produto();
            break;

        case '5': //lista_falta();
            break;

        case "0":
            tela_inicial()
            break;
        }
    }   
}

/// Crud menu estoque:

char menu_estoque(void){
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
    printf("/// = = = = = = = = = = = = = = Menu de Estoque = = = = = = = = = = = = = = ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastro de Produto:                                      ///\n");
    printf("///            2. Lista de Produto:                                         ///\n");
    printf("///            3. Editar Produto:                                           ///\n");
    printf("///            4. Apagar Produto:                                           ///\n");
    printf("///            5. Lista de Produtos em falta:                               ///\n");
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

// Crud menu Aluguel:

char menu_aluguel(void){
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
    printf("/// = = = = = = = = = = = = = = Menu de Estoque = = = = = = = = = = = = = = ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastro novo Aluguel:                                    ///\n");
    printf("///            2. Lista de Veiculos Disponiveis:                            ///\n");
    printf("///            3. Lista de veiculos alugados:                               ///\n");
    printf("///            4. Lista de alugueis atrazados:                              ///\n");
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