#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void muitasoperacoes(int a, int b, int *p, int*q) //note que essa função recebe dois valores e dois ponteiros
{
	*p = a + b;
	*q = a * b;
}

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL, "Portuguese");
	//uma variável reserva espaço em memória quando declaramos ela
	int a, b; // nesse caso são reservado 4 bytes
	
	int size = sizeof(a);
	
	printf("A variável a tem um tamanho de %i bytes \n",size);
	
	printf("O endereço de memóra da variável a é %i \n", &a);
	
	int *p; // aqui estamos declarando uma variável ponteiro
	
	a = 5; 
	p = a; // isso aqui gera um Warning pelo compilador
	
	printf("Agora imprimiremos p que é %i \n",p);
	
	p = &a; // o correto seria armazenar o endereço de a na nossa variável ponteiro
	
	printf("Esse valor é de p %i e esse o endereço de memória de a %i \n",p, &a);
	printf("Veja que os valores são exatamente iguais \n");
	
	*p = 2;
	
	printf("Agora imprimiremos a depois de atribuir 2 para nossa variável ponteiro, e a passa a ser %i \n",a);
	
	/* Agora vamos brincar um pouco com funções */
	muitasoperacoes(5,7, &a, &b);
	printf("O valor de a é %i e o valor de b é %i",a,b);
	
	return 0;
}