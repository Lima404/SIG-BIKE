#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "validacoes.h"



/*void validar_cpf(void){
    int cpf[11],i,p,d1,d2;
    for(i=1;i<=11;i++){
        printf("Digite o CPF:");
        scanf("%d",&cpf[i]);
    }
    for(i=1;i<9;i++){
        p+=cpf[i]*(11-i);
    }
    d1=p%11;
    if(d1<2){
        d1=0;
    }
    else{
        d1=11-d1;
    }
    p=0;
    for(i=1;i<9;i++){
        p+=cpf[i]*(12-i);
    }
    d2=(p+(d1*2))%11;
    if(d2<2){
        d2=0;
    }
    else{
        d2=d2-11;
    }
    if(cpf[10]==d1&&cpf[11]==d2){
        printf("CPF Valido\n");
    }
    else{
        printf("CPF Invalido");
    }
}//

//void validar_ano_bissexto(void){
    int dia, mes, ano;
    int ultimo_dia[] = {-1,31,28,31,30,31,30,31,31,30,31,30,31};

    for(;;) {
	printf ("Digite a data no formato dd/mm/yyyy \n");

	scanf("%d/%d/%d",&dia,&mes,&ano);

	 testa coisas obvias: dia/ano negativo,mes invalido 			
	if(dia<=0||mes<1||mes>12||ano<=0){	
		printf("Data invalida\n");
		continue;
	}
	
	 atualiza o ultimo dia do mes se bissexto
	if(ano%4==0 && (ano%400==0 || ano%100!=0))
		ultimo_dia[2]=29;					
	else
		ultimo_dia[2]=28;

	 verifica se o dia eh maior que o ultimo dia do ano
	if(dia>ultimo_dia[mes])
		printf("Data invalida\n");
	else 
		break;
}

 return 0;
}//

//https://www.guj.com.br/t/ano-bissexto-linguagem-c/5696/13//*/