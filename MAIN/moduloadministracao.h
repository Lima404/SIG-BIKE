void menu_nav_adm(void);
char menu_adm(void);


typedef struct aCliente NoCliente;
struct aCliente{

    char nome [81];
    char cpf [12];
    char telefone [21];
    char endereco [141];
    int dd, mm, aa;
    char status;
    NoCliente* prox;
};

// USUÁRIO
char menu_relatorios_cliente(void);
void nav_relatorio_cliente(void);
void R_lista_cliente(void);
NoCliente* R_cliente_alfa(void);
void exibe_alfa(NoCliente*);

// VEICULO
char menu_relatorio_veiculo(void);
void nav_relatorio_veiculo(void);
void R_lista_veiculo(void);
void veiculo_tipo(void);

