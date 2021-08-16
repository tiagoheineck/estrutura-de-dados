#include <stdio.h>

int potencia_de_2(int n)
{

    int k, pot = 1;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        for (k = 1; k <= n; k++)
        {
            pot = pot * 2;
        }
    }
    return pot;
}

int potencia_de_2_recursiva(int n)
{
    if (n == 0) return 1;
    else return 2 * potencia_de_2_recursiva(n-1);
}

void main()
{

    int a = potencia_de_2(2);
    printf("O resultado é %i \n", a);

    int b = potencia_de_2_recursiva(2);
    printf("O resultado recursivo é %i \n", b);

}