#include <stdio.h>
#include <string.h>
#include "pessoa.h"

int main (void)
{
    char nome[200];    
    struct tm nascimento;    
    int ano, mes, dia;

    printf("Digite seu nome: ");
    scanf("%199[^\n]", &nome);

    printf("\n Digite a data de nascimento: formato dd/mm/YYYY: ");
    scanf("%d/%d/%d",  &dia, &mes, &ano);        

    nascimento.tm_year = ano - 1900;
    nascimento.tm_mday = dia;
    nascimento.tm_mon = mes - 1;

    Pessoa* pessoa = cria_pessoa(nome,nascimento);            

    int idade = calcula_idade(pessoa);
    
    char *nome_reverso = inverte_nome(pessoa);

    printf("Nossa, o %s tem %i!",nome_reverso,idade);    
    

    return 0;
}