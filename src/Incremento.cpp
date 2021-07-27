# include <stdio.h>

int main (void)
{
    int a, x;
    a = 2;
    x = a++;
    printf("Atribuindo com a++ o x é %d e a é %d \n", x, a);    
    x = ++a;
    printf("Atribuindo com ++a o x é %d e a é %d \n", x,a);
    return 0;
}