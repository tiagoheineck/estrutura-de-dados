#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*  Rodar com -w para evitar os warnings gerem parada gcc -o build/Ponteiro src/Ponteiro.c -w */

void muitasoperacoes(int a, int b, int *p, int *q) //note que essa função recebe dois valores e dois ponteiros
{
	*p = a + b;
	*q = a * b;
}

int main(int argc, char *argv[])
{

	setlocale(LC_ALL, "Portuguese");
	//uma variável reserva espaço em memória quando declaramos ela
	int a, b; // nesse caso são reservado 4 bytes

	int size = sizeof(a);

	printf("A variável a tem um tamanho de %i bytes \n", size);

	printf("O endereço de memóra da variável a é %i \n", &a);

	int *p; // aqui estamos declarando uma variável ponteiro

	a = 5;
	p = a; // isso aqui gera um Warning pelo compilador

	printf("Agora imprimiremos p que é %i \n", p);

	p = &a; // o correto seria armazenar o endereço de a na nossa variável ponteiro

	// isso imprime o valor de p e o ednereço de memória de a
	// convertidos em inteiro
	printf("Esse valor é de p %i e esse o endereço de memória de a %i \n", p, &a);
	printf("Esse é o endereço de memória real de p %p e esse o endereço de memória real de a %p \n", p, &a);
	printf("Se quiser imprimir o valor de p tem que usar %i \n", *p);
	printf("Veja que os valores são exatamente iguais \n");

	*p = 2;

	printf("Agora imprimiremos a depois de atribuir 2 para nossa variável ponteiro, e a passa a ser %i \n", a);

	/* Agora vamos brincar um pouco com funções */
	muitasoperacoes(5, 7, &a, &b);
	printf("O valor de a é %i e o valor de b é %i \n", a, b);

	return 0;
}
