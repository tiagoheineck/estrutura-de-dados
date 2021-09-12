#include <stdlib.h>
#include <stdio.h>
#include "Arvore.h"

struct arvno
{
    char info;
    ArvNo* esq;
    ArvNo* dir;
};

struct arv
{
    ArvNo* raiz;
};

ArvNo *arv_criano(char c, ArvNo *esq, ArvNo *dir)
{
    ArvNo* p = (ArvNo*)malloc(sizeof(ArvNo));
    p->info = c;
    p->esq = esq;
    p->dir = dir;
    return p;
}

Arv *arv_cria(ArvNo* r)
{
    Arv* a = (Arv *)malloc(sizeof(Arv));
    a->raiz = r;
    return a;
}

Arv *abb_cria(void)
{
    Arv* a = (Arv *)malloc(sizeof(Arv));
    a->raiz = NULL;
    return a;
}

static void imprime(ArvNo* r)
{
    if (r != NULL)
    {
        printf("% c ", r->info);
        imprime(r->esq);
        imprime(r->dir);
    }
}

static void imprime2(ArvNo* r)
{
    /* Em relação a árvore, para árvore binária de busca a ordem de percurso é invertida para explorar a propriedade de ordenação */
    if (r != NULL)
    {
        imprime2(r->esq);
        printf("% c ", r->info);
        imprime2(r->dir);
    }
}

void abb_imprime(Arv* a)
{
    return imprime2(a->raiz);
}

void arv_imprime(Arv* a)
{
    imprime(a->raiz);
}

static void libera(ArvNo* r)
{
    if (r != NULL)
    {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

void arv_libera(Arv* a)
{
    libera(a->raiz);
    free(a);
}

static int pertence(ArvNo* r, char c)
{
    if (r == NULL)
        return 0;
    else
        return c ==
                   r->info ||
               pertence(r->esq, c) ||
               pertence(r->dir, c);
}

int arv_pertence(Arv* a, char c)
{
    return pertence(a->raiz, c);
}

static ArvNo* busca(ArvNo* r, char c)
{
    if (r == NULL)
        return NULL;
    else if (c == r->info)
        return r;
    else
    {
        ArvNo* p = busca(r->esq, c);
        if (p != NULL)
            return p;
        else
            return busca(r->dir, c);
    }
}

ArvNo* arv_busca(Arv* a, char c)
{
    return busca(a->raiz, c);
}

/* Essa busca é exclusiva para árvore binária de busca */
static ArvNo* busca2(ArvNo* r, int v)
{
    if (r == NULL)
        return NULL;
    else if (r->info > v)
        return busca2(r->esq, v);
    else if (r->info < v)
        return busca2(r->dir, v);
    else
        return r;
}

ArvNo* abb_busca(Arv* a, int v)
{
    return busca2(a->raiz, v);
}

/* exclusivo para uso de árvore binária de busca */
static ArvNo* insere(ArvNo* r, int v)
{
    if (r == NULL)
    {
        r = (ArvNo*)malloc(sizeof(ArvNo));
        r->info = v;
        r->esq = r->dir = NULL;
    }
    else if (v < r->info)
        r->esq = insere(r->esq, v);
    else
        r->dir = insere(r->dir, v);
    return r;
}

void abb_insere(Arv* a, int v)
{
    a->raiz = insere(a->raiz, v);
}

static ArvNo* retira(ArvNo* r, int v)
{
    if (r == NULL)
        return NULL;
    else if (r->info > v)
        r->esq = retira(r->esq, v);
    else if (r->info < v)
        r->dir = retira(r->dir, v);
    else
    {
        if (r->esq == NULL && r->dir == NULL)
        {
            free(r);
            r = NULL;
        }
        else if (r->esq == NULL)
        {
            ArvNo* t = r;
            r = r->dir;
            free(t);
        }
        else if (r->dir == NULL)
        {
            ArvNo* t = r;
            r = r->esq;
            free(t);
        }
        else
        {
            ArvNo* f = r->esq;
            while (f->dir != NULL)
            {
                f = f->dir;
            }
            r->info = f->info;
            f->info = v;
            r->esq = retira(r->esq, v);
        }
    }
    return r;
}

void abb_retira(Arv* a, int v)
{
    a->raiz = retira(a->raiz, v);
}

static int max2(int a, int b)
{
    return (a > b) ? a : b;
}

static int altura(ArvNo* r)
{
    if (r == NULL)
        return -1;
    else
        return 1 + max2(altura(r->esq), altura(r->dir));
}

int arv_altura(Arv* a)
{
    return altura(a->raiz);
}

int main()
{
    Arv* a = arv_cria(
        arv_criano('a',
                   arv_criano('b',
                              NULL,
                              arv_criano('d', NULL, NULL)),

                   arv_criano('c',
                              arv_criano('e', NULL, NULL), arv_criano('f', NULL, NULL))));

    arv_imprime(a);
    int altura_de_a = arv_altura(a);
    printf("\n A altura da árvore é %i \n", altura_de_a);

    return 0;
}