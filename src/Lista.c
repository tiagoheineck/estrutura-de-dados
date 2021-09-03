#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;
typedef struct listano ListaNo;

struct lista {
    ListaNo* prim;
};

struct listano {
    int info;
    ListaNo* prox;
};

Lista* lst_cria(void)
{
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->prim = NULL;
    return l;
}

void lst_insere (Lista* l, int v)
{
    ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo));
    novo->info = v;
    novo->prox = l->prim;
    l->prim = novo;
}

void lst_imprime (Lista* l)
{
    for (ListaNo* p=l->prim; p!= NULL; p=p->prox)
        printf("info = %d \n", p->info);
}

int main (void)
{
    Lista* l = lst_cria();
    lst_insere(l, 23);
    lst_insere(l, 28);
    lst_insere(l, 45);
    lst_imprime(l);
    return 0;
}
