#include <stdio.h>

int main(int argc, char const *argv[]) {

    int a = 0;
    int b = 0;
    int soma = 0;

    printf ("Digite A \n");
    scanf ("%d", &a);
    printf ("Digite B: \n");
    scanf ("%d", &b);

    soma = a + b;

    printf("A soma é %d\n",soma);

    return 0;

}