void menu_nav_veiculo(void);
char menu_veiculo(void);
//void menu_cadastro_veiculo(void);
char menu_lista_veiculo(void);
//void menu_apagar_veiculo(void);
char menu_editar_veiculo(void);
void menu_veiculo_manutencao(void);
char menu_lista_agendamento(void);
void menu_cadastro_veiculo(void);


typedef struct cadastroveiculo CadastroVeiculo;
struct cadastroveiculo{

    char tipo [21];
    char marca[21];
    char desc [101];
    char cod [7];
    char preco [21];
    char status;
    
};

// PONTEIROS DECLARADOS
CadastroVeiculo* preencheVeiculo(void);
void gravaVeiculo(CadastroVeiculo*);
CadastroVeiculo* buscaVeiculo(void);
void exibeVeiculo(CadastroVeiculo* cadveiculo);
void apagaVeiculo(CadastroVeiculo* cadveiculo);
void editaVeiculo(void);
void listaVeiculo(void);

