// As constantes são declaradas no começo do programa com 
// # define NOME valor

# include <stdio.h>

# define FATOR 1.8

int main (void )
{
    float c;
    float f;
    printf("Digite os graus em Celsius \n");
    scanf("%f", &c);
    f = FATOR * c + 32;
    printf("Isso quer dizer que são %f Fahrenheit \n",f);
    return 0;
}