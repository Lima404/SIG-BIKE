void menu_nav_aluguel(void);
char menu_aluguel(void);
char menu_editar_aluguel(void);
char menu_lista_disp(void);
char menu_lista_indisp(void);
char menu_lista_atrasados(void);

typedef struct cadastroaluguel CadastroAluguel;
struct cadastroaluguel{

    char cpf [12];
    char cod[7];
    int dd, mm, aa;
    char preco[10];
    char status;
    
};


// PONTEIROS DECLARADOS

CadastroAluguel* preencheAluguel(void);
void gravaAluguel(CadastroAluguel*);
CadastroAluguel* buscaAluguel(void);
void exibeAluguel(CadastroAluguel* cadaaluguel);
void listaAluguel(void);
void apagaAluguel(CadastroAluguel* cadaaluguel);
void editaAluguel(CadastroAluguel* cadaaluguel);