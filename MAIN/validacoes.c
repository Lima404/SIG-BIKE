#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "validacoes.h"



int validar_cpf(char cpf []){
    
    //http://pog-carlos.blogspot.com/2011/11/validacao-de-cpf-em-c-usando-vetor.html

    int icpf[12];  
    int i,somador=0,digito1,result1,result2,digito2,valor;  
    
    
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
        return 1;
        }  

    return 0;  
}  


int validar_bissexto(int aa){
    
    //https://www.guj.com.br/t/ano-bissexto-linguagem-c/5696/13//
    
  if ((aa % 4 == 0) && (aa % 100 != 0)) {
    return 1;
  } else if (aa % 400 == 0) {
    return 1;
  } else {
    return 0;
  }
}


int validar_data(int dd, int mm, int aa){
  int maiorDia;
  if (aa < 0 || mm < 1 || mm > 12)
    return 0;
  if (mm == 2) {
    if (validar_bissexto(aa)) 
      maiorDia = 29;
    else
      maiorDia = 28;
  } else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
    maiorDia = 30;
  } else
    maiorDia = 31;
  if (dd < 1 || dd > maiorDia)
    return 0;
  return 1;
}

int validar_letra(char c) {

  //https://github.com/rauan-meirelles/Projeto-ParkingMod---DCT1106/blob/master/utilidade.c

  if (c >= 'A' && c <= 'Z') {
    return 1;
  } else if (c >= 'a' && c <= 'z') {
    return 1;
  } else {
    return 0;
  }
}

int validar_nome(char nome []) {

  //https://github.com/rauan-meirelles/Projeto-ParkingMod---DCT1106/blob/master/utilidade.c

  for (int i=0; nome[i]!='\0'; i++) {
    if (!validar_letra(nome[i])) {
      return 0;
    }
  }
	return 1;
}


int validar_tamanho_string(char lista[]){
    int cont;

    for(int i=0; lista[i] != '\n'; i++){
        cont++;

    }
        return cont;

}
