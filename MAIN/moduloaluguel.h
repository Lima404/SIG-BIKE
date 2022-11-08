void menu_nav_aluguel(void);

char menu_aluguel(void);

char menu_editar_aluguel(void);

char menu_lista_disp(void);

char menu_lista_indisp(void);

char menu_lista_atrasados(void);

typedef struct cadastroaluguel CadastroAluguel;
struct cadastroaluguel{
    char cpf [11];
    char cod[10];
    char status;
};

// PONTEIROS DECLARADOS
CadastroAluguel* preencheAluguel(void);
void gravaAluguel(CadastroAluguel*);


typedef struct apagaraluguel ApagarAluguel;
struct apagaraluguel{
    char cpf [11];
};

ApagarAluguel* apagarAluguel( );
CadastroAluguel* cadastroAluguel( );