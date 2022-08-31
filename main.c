#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>

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
char menu_vendas (void);
char menu_adm (void);
char menu_sobre (void);



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

///////////////////////////////////////////////////////////////////////////

// Funções para menu aluguel:

//char cadastro_aluguel(void);
//char lista_aluguel(void);
//char lista_alugados(void);
//char lista_atrazados(void);

//////
////// Navegação principal:
//////

int main(void){
    setlocale(LC_ALL,"");
    char inicio;
    char usuario;
    char veiculos;
    char estoque;
    char aluguel;
    char vendas;
    char adm;
    char sobre;

    inicio = tela_inicial();
    switch (inicio)
    {
        case '1': menu_usuario();
            break;
        
        case '2': menu_veiculos();
            break;
        
        case '3': menu_estoque();
            break;
        
        case '4': menu_aluguel();
            break;

        case '5': menu_vendas();
            break;
        
        case '6': menu_adm();
            break;
        
        case '7': menu_sobre();
            break;

        case '0':
            printf('fim do programa\n');
            break;

        default:
            printf('Você inseriu uma opção invalida, por favor insira uma opção válida!');
            break;
    }
    
    usuario = menu_usuario();
    switch (usuario)
    {
        case '1': //cadastro_usuario();
            break;
        
        case '2': //lista_usuario();
            break;
        
        case '3': //apagar_usuario();
            break;

        case '4': //editar_usuario();
            break;
    
        case '0': tela_inicial();
            break;
            
        default:
            printf('Você inseriu uma opção invalida, por favor insira uma opção válida!');
            break;
    }

    veiculos = menu_veiculos();
    switch (veiculos)
    {
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
    
        case '0': tela_inicial();
            break;
            
        default:
            printf('Você inseriu uma opção invalida, por favor insira uma opção válida!');
            break;
    }

    estoque = menu_estoque();
    switch (estoque)
    {
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

        case '0': tela_inicial();
            break;
            
        default:
            printf('Você inseriu uma opção invalida, por favor insira uma opção válida!');
            break;
    }

    aluguel = menu_aluguel();
    switch (aluguel)
    {
        case '1': //cadastro_aluguel();
            break;
        
        case '2': //lista_aluguel();
            break;

        case '3': //lista_alugados();
            break;

        case '4': //lista_atrazados():
            break;


        case '0': tela_inicial();
            break;
            
        default:
            printf('Você inseriu uma opção invalida, por favor insira uma opção válida!');
            break;
    }

    vendas = menu_vendas();
    switch (vendas)
    {
        case '1': //cadastro_vendas();
            break;
        
        case '2': //listar_vendas();
            break;
        
        case '3': //apagar_vendas();
            break;

        case '4': //editar_vendas();
            break;
    
        case '0': tela_inicial();
            break;
            
        default:
            printf('Você inseriu uma opção invalida, por favor insira uma opção válida!');
            break;
    }
    
    adm = menu_adm();
    switch (adm)
    {
        case '1': //fluxo_de_caixa();
            break;
        
        case '2': //manutencao();
            break;
        
        case '3': //gastos_da_empresa();
            break;
    
        case '0': tela_inicial();
            break;
            
        default:
            printf('Você inseriu uma opção invalida, por favor insira uma opção válida!');
            break;
    }
    
    sobre = menu_sobre();
    switch (sobre)
    {   
        case '1':
            printf('vai dar certo!');
        
    
        case '0': tela_inicial();
            break;
            
        default:
            printf('Você inseriu uma opção invalida, por favor insira uma opção válida!');
            break;
    }
      
}

/// menu tela inicial:

char tela_inicial(void){
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


/// CRUD MENU USUÁRIO:

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

/// crud menu veiculos:

char menu_veiculos(void){
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


/// Crud menu estoque:

char menu_estoque(void){
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
    printf("/// = = = = = = = = = = = = = = Menu de Usuário = = = = = = = = = = = = = = ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastro de Vendas:                                       ///\n");
    printf("///            2. Lista de Vendas:                                          ///\n");
    printf("///            3. Apagar Vendas:                                            ///\n");
    printf("///            4. Editar Vendas:                                            ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha por onde você quer navegar:                                                         ///\n");
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

char menu_adm(void){
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
    printf("///            1. Cadastro de Vendas:                                       ///\n");
    printf("///            2. Lista de Vendas:                                          ///\n");
    printf("///            3. Apagar Vendas:                                            ///\n");
    printf("///            4. Editar Vendas:                                            ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha por onde você quer navegar:                                                         ///\n");
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