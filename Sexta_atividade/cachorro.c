#include "cachorro.h"

struct cachorro{
    char* nome;
    int agressividade;
};


Cachorro* inicCachorro(char* nome, int agressividade){
    Cachorro* c = malloc(sizeof(struct cachorro));
    c->nome = strdup(nome);
    c->agressividade = agressividade;
    return c;
}

void liberaCachorro(Cachorro* c){
    if(c != NULL){
        if(c->nome != NULL) free(c->nome);
        free(c);
    }
}

int retornaAgressividadeCachorro(Cachorro* c){
    return c->agressividade;
}

void imprimeCachorro(Cachorro* c){
    printf("Nome cachorro: %s\n", c->nome);
}

void atribuiNivelAgressividadeCachorro(Cachorro* c, int agressividade){
    c->agressividade = agressividade;
}
