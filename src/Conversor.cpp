# include <stdio.h>

int main (void )
{
    float c;
    float f;
    printf("Digite os graus em Celsius \n");
    scanf("%f", &c);
    f = 1.8 * c + 32;
    printf("Isso quer dizer que são %f Fahrenheit \n",f);
    return 0;
}