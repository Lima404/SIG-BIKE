void menu_nav_aluguel(void);
char menu_aluguel(void);

typedef struct cadastroaluguel CadastroAluguel;
struct cadastroaluguel{

    char cpf [12];
    char cod[7];
    char data[10];
    char preco[10];
    char status;
    int devolucao[3];

};


// PONTEIROS DECLARADOS
CadastroAluguel* preencheAluguel(void);
void gravaAluguel(CadastroAluguel*);
CadastroAluguel* buscaAluguel(void);
void exibeAluguel(CadastroAluguel* cadaaluguel);
void exibedata(CadastroAluguel* cadaaluguel);
void listadata(void);
void listaAluguel(void);
void apagaAluguel(CadastroAluguel*);
void editaAluguel(CadastroAluguel*);
char* get_nome_cliente(char*);
char* get_nome_veiculo(char*);
char* verDiaMesAno(void);