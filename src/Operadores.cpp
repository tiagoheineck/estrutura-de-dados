# include <stdio.h>

int main (void) {
    int a, b;
    int c = 30;
    int d = c + 4;

    a = (c < 20) || (d > c);
    b = (c < 20) && (d > c);

    if (a == 1) {
        printf("a é verdadeiro \n");
    }
    else {
        printf("a é falso \n");
    }


    if (b == 0) {
        printf("b é falso \n");
    }
    else {
        printf("b é verdadeiro");
    }
}