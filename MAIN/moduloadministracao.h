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

typedef struct aAluguel NoAluguel;
struct aAluguel{

    char cpf [12];
    char cod[7];
    char data[10];
    char preco[10];
    char status;
    NoAluguel* prox;
    
};


typedef struct aVeiculo NoVeiculo;
struct aVeiculo{

    char tipo [21];
    char marca[21];
    char desc [101];
    char cod [7];
    char preco [21];
    char status;
    NoVeiculo* prox;
    
};

// USUÁRIO
char menu_relatorios_cliente(void);
void nav_relatorio_cliente(void);
void R_lista_cliente(void);
NoCliente* R_cliente_alfa(void);
void exibe_alfa(NoCliente*);

// VEICULO
char menu_relatorios_veiculo(void);
void nav_relatorio_veiculo(void);
void R_lista_veiculo(void);
//void veiculo_tipo(void);
NoVeiculo* R_veiculo_alfa(void);
void exibe_alfa_veiculo(NoVeiculo*);

//ALUGUEL
void nav_relatorio_aluguel(void);
void R_lista_aluguel(void);
char menu_relatorios_aluguel(void);
NoAluguel* R_aluguel_alfa(void);
void exibe_alfa_aluguel(NoAluguel*);
