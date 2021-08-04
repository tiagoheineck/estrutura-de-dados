#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

Pessoa* cria_pessoa(char *nome,struct tm data_nascimento) 
{
    Pessoa* p = (Pessoa*) malloc (sizeof(Pessoa));
    if (p == NULL) {
        printf ("Memória insuficiente\n");
        exit(1);
    }
    p->nome = nome;    
    p->data_nascimento = data_nascimento;
    return p;
}

int calcula_idade(Pessoa* pessoa)
{    
    time_t hoje = time(0);     
    time_t convertido = mktime(&pessoa->data_nascimento);              
    printf("Hoje é %d e convertido deu %d anos \n", hoje, convertido);
    int seconds = difftime(hoje,convertido) / 86400;
    return floor(seconds);
}

char* inverte_nome(Pessoa* pessoa)
{    
    int length = strlen(pessoa->nome) ;
    char* invertido = pessoa->nome;
    int c, i, j;

    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        c = invertido[i];
        invertido[i] = invertido[j];
        invertido[j] = c;
    }

    return invertido;
}