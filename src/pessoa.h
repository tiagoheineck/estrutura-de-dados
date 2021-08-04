#include <time.h>

typedef struct pessoa Pessoa;

struct pessoa {
    char *nome;        
    struct tm  data_nascimento;    
};

Pessoa* cria_pessoa(char *nome,struct tm data_nascimento);

int calcula_idade(Pessoa* pessoa);

char* inverte_nome(Pessoa* pessoa);