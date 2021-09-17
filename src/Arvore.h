typedef struct arv Arv;
typedef struct arv3 Arv3;
typedef struct arvno ArvNo;
typedef struct arv3no Arv3No;

Arv* arv_cria(ArvNo* raiz);

Arv3* arv3_cria(Arv3No* raiz);

ArvNo* arv_criano(char c, ArvNo* e, ArvNo* d);

Arv3No* arv3_criano(char c, Arv3No* e, Arv3No* m, Arv3No* d);

void arv_libera(Arv* a);

void arv_imprime(Arv* a);

int arv_pertence(Arv* a, char c);

ArvNo* arv_busca(Arv* a, char c);
