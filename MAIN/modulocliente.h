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

    char nome [21];
    char cpf [12];
    char telefone [21];
    char endereco [41];
    int dd, mm, aa;
    char status;
    
};

// PONTEIROS DECLARADOS

Cadastro* preencheCliente(void);
void gravaCliente(Cadastro*);


// APAGAR CLIENTE

typedef struct apagar Apagar;
struct apagar{
    char cpf [11];
};

Apagar* apagarCliente( );

// Cadastro* cadastroCliente( );
Cadastro* cadastroCliente( );

