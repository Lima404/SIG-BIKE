#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "validacoes.h"



int validar_cpf(char cpf []){
    
    //http://pog-carlos.blogspot.com/2011/11/validacao-de-cpf-em-c-usando-vetor.html

    int icpf[15];  
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
  
  } else if (c == ' '){
    return 1;
  
  } else if (c == ','){
    return 1;

  } else if(c == '.'){
    return 1;

  } else if(c == '~'){
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

int validarEscolhas(char esc){
    char numeros[8]={'0','1','2','3','4','5','6'};

    int escolha;

    for(int x=0; x<=7 ; x++){
        if(esc == numeros[x]){
            escolha=1;
            break;
        } 
    }

    if (escolha==1){
        return 0;
    }else{
        return 1;
    } 
    }

int validarNumInteiro(char *numero) {        //DAY
    int i = 0;

    while (numero[i] != '\0') {
        if ((numero[i] >= '0') && (numero[i] <= '9')) {
            i = i + 1;

        }

        else {
            return 0;

        }

    }

    return 1;

}

int diaDoAno(int dia , int mes, int ano) 
{
    int diaDoAno = 0;
    int diasDoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int i = 0; i < mes - 1; i++) {

        if (mes == 1) {
        return dia;

        }
    
        else if (mes == 2) {
        diaDoAno = dia + 31;

        }

        else {
            diaDoAno = diaDoAno + diasDoMes[i];

        }


    }

    diaDoAno = diaDoAno + dia;

    if ((mes == 2) && validar_bissexto(ano)) {
        diaDoAno = diaDoAno + 1;

    }

    return diaDoAno;

}

char* dividPal(char *pal, int del1, int del2) {
    int tam = del2 - del1;
    int aux = 0;

    char* palavra = (char*) malloc((tam + 1)* sizeof(char));

    palavra[0] = pal[del1];

    for (int i = del1; i <= del2; i++) {
        
        palavra[aux] = pal[i];

        aux = aux + 1;

    }

    palavra[tam + 1] = '\0';

    return palavra;

}

// char inversa(int dia) 
// {
    
//     int diaDoAno = 0;
//     int diasDoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//     for (int i = 0; i < mes - 1; i++) {

//         if (mes == 1) {
//         return dia;

//         }
    
//         else if (mes == 2) {
//         diaDoAno = dia + 31;

//         }

//         else {
//             diaDoAno = diaDoAno + diasDoMes[i];

//         }


//     }

//     diaDoAno = diaDoAno + dia;

//     if ((mes == 2) && validar_bissexto(ano)) {
//         diaDoAno = diaDoAno + 1;

//     }

//     return diaDoAno;

// }