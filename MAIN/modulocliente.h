void menu_nav_cliente(void);
char menu_cliente(void);
char menu_lista_cliente(void);
char menu_procurar_cliente(void);


//  CADASTRO CLIENTE

typedef struct cadastro Cadastro;
struct cadastro{

    char nome [81];
    char cpf [12];
    char telefone [21];
    char endereco [141];
    int dd, mm, aa;
    char status;
};

// PONTEIROS DECLARADOS

Cadastro* preencheCliente(void);
void gravaCliente(Cadastro*);
Cadastro* buscaCliente (void);
void exibeCliente(Cadastro* user);
void listaCliente(void);
void apagaCliente(Cadastro* user);
void editaCliente(Cadastro* user);
int valida_cliente(char* user);
