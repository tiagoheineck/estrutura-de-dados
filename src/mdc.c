#include <stdio.h>

int calculaMDC (int a, int b) {
    if (a%b==0){
        return b;
    }else{
        return calculaMDC(b,(a%b));
    }
}

int main (void)
{
    int a,b,c;
    printf("Digite a, b e c :");
    scanf("%i%i%i",&a,&b,&c);
    printf("\n%i",calculaMDC(calculaMDC(a,b),c));

}