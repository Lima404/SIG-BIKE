#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "validacoes.h"



int validar_cpf(void){
    
    //http://pog-carlos.blogspot.com/2011/11/validacao-de-cpf-em-c-usando-vetor.html

    char cpf[12];  
    int icpf[12];  
    int i,somador=0,digito1,result1,result2,digito2,valor;  
    
    printf("Digite o cpf: ");  
    scanf(" %s",cpf);  
    
    //Efetua a conversao de array de char para um array de int.  
    for(i=0;i<11;i++){  
    icpf[i]=cpf[i]-48;
    }  
    
    //PRIMEIRO DIGITO.  
    
    for(i=0;i<9;i++){  
    somador+=icpf[i]*(10-i);  
    }  
    
    result1=somador%11;  
    
    if( (result1==0) || (result1==1) ){  
    digito1=0;  
    }  
    
    else{  
    digito1 = 11-result1;  
    }  
    
    //SEGUNDO DIGITO.  
    
    somador=0;  
    
    for(i=0;i<10;i++){  
    somador+=icpf[i]*(11-i);  
    }  
    
    valor=(somador/11)*11;  
    result2=somador-valor;  
    
    if( (result2==0) || (result2==1) ){  
    digito2=0;  
    }  
    
    else{  
    digito2=11-result2;  
    }  
    
    //RESULTADOS DA VALIDACÃO
    
    if((digito1==icpf[9]) && (digito2==icpf[10])){  
        printf("\nCPF VALIDADO.\n");  
        }  
    else{  
        printf("Problema com os digitos.\n");  
    }  
    return 0;  
}  


int validar_data(void){
    
    //https://www.guj.com.br/t/ano-bissexto-linguagem-c/5696/13//
    
    int dia, mes, ano;
    int ultimo_dia[] = {-1,31,28,31,30,31,30,31,31,30,31,30,31};

    for(;;) {
        printf ("Digite a data no formato dd/mm/yyyy \n");

        scanf("%d/%d/%d",&dia,&mes,&ano);
                
        if(dia<=0||mes<1||mes>12||ano<=0){	
            printf("Data invalida\n");
            continue;
        }
        

        if(ano%4==0 && (ano%400==0 || ano%100!=0))
            ultimo_dia[2]=29;					
        else
            ultimo_dia[2]=28;


        if(dia>ultimo_dia[mes])
            printf("Data invalida\n");
        else 
            break;
    }

 return 0;
}


void validar_string(void){

 }

 void validar_inteiro(void){
    
}

int tamanho_string(char lista[]){
    int cont;

    for(int i=0; lista[i]; != '\n'; i++){
        cont++;

    }
        return cont;
}