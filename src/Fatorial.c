#include <stdio.h>

int fatorial(int n)
{

    int fat = 1;
    if (n == 0) return fat;
    else 
        while (n>0) {
            fat = fat * n;
            n--;
        }
    return fat;
}

int fatorial_recursivo(int n)
{
    if (n == 0) return 1;
    else return n*fatorial_recursivo(n-1);
}

void main()
{

    int a = fatorial(5);
    printf("O resultado é %i \n", a);

    int b = fatorial_recursivo(5);
    printf("O resultado recursivo é %i \n", b);

}