#include "gato.h"

struct gato{
    char* nome;
    int agressividade;
};


Gato* inicGato(char* nome, int agressividade){
    Gato* g = malloc(sizeof(struct gato));
    g->nome = strdup(nome);
    g->agressividade = agressividade;
    return g;
}

void liberaGato(Gato* gato){
    if(gato != NULL){
        if(gato->nome != NULL) free(gato->nome);
        free(gato);
    }
}

int retornaAgressividadeGato(Gato* g){
    return g->agressividade;
}

void imprimeGato(Gato* g){
    printf("Nome gato: %s\n", g->nome);
}

void atribuiNivelAgressividadeGato(Gato* g, int agressividade){
    g->agressividade = agressividade;
}

int comparaNomeGato(Gato* g1, Gato* g2){
    return (strcmp(g1->nome, g2->nome) == 0);
}

