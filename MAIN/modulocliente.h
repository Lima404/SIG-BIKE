void menu_nav_cliente(void);
char menu_cliente(void);
// void menu_cadastro_cliente(void);
char menu_lista_cliente(void);
// char menu_apagar_cliente(void);
char menu_editar_cliente(void);
char menu_procurar_cliente(void);

//  CADASTRO CLIENTE

typedef struct cadastro Cadastro;
struct cadastro{
    char nome [20];
    char cpf [11];
    char telefone [20];
    char endereco [40];
    int dd, mm, aa;
};

// APAGAR CLIENTE

typedef struct apagar Apagar;
struct apagar{
    char cpf [11];
};

Apagar* apagarCliente( );
Cadastro* cadastroCliente( );