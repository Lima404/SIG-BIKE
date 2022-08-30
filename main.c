#include <stdio.h>

/// Funções
char tela_inicial (void);
void menu_usuario(void);
void menu_veiculos (void);
void menu_estoque (void);
void menu_aluguel (void);
void menu_vendas (void);
void menu_sobre (void);


/// Navegação principal
int main(void){
    char opcao;

    do {
        opcao = tela_inicial();
        switch (opcao){
        case '1': menu_aluguel();
            break;
        
        case '2': menu_veiculos();
            break;
        
        case '3': menu_estoque();
            break;

        case '4': menu_aluguel();
            break;

        case '5': menu_vendas();
            break;

        case '6': menu_sobre();
            break;
        }
    }   while (opcao != "0");

        return 0
}