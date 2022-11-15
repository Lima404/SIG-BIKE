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

    char nome [81];
    char cpf [12];
    char telefone [21];
    char endereco [41];
    int dd, mm, aa;
    char status;
    
};

// PONTEIROS DECLARADOS

void gravaCliente(Cadastro*);
void exibeCliente(Cadastro* cliente);
void preencheCliente(void);
void buscaCliente(void);
void listaCliente(void);
void apagaCliente(void);
void editaCliente(void);


