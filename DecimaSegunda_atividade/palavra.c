// palavra.c
//
// Criado por Thais Gomes Brandao no dia 27/07/2025
//

#include "palavra.h"

struct palavra{
    char* string;
    int frequencia;
};

Palavra* criaPalavra(char* string, int frequencia){
    Palavra* palavra = malloc(sizeof(struct palavra));
    palavra->string = strdup(string);
    palavra->frequencia = frequencia;
    return palavra;
}

Palavra** criaVetorPalavras(int tamanho){
    Palavra** vetor = malloc(sizeof(struct palavra*) * tamanho);
    return vetor;
}

void liberaVetorPalavras(Palavra** palavra, int tamanho){
    int i;
    for(i = 0; i < tamanho; i++){
        if(palavra[i] != NULL){
            free(palavra[i]->string);
            free(palavra[i]);
        }
    }
    free(palavra);
}

void imprimeVetorPalavras(Palavra** palavra, int tamanho, FILE* arquivo){
    int i;
    for(i = 0; i < tamanho; i++){
        fprintf(arquivo, "%s %d\n", palavra[i]->string, palavra[i]->frequencia);
    }
}

static int compare(const void * a, const void * b){
    Palavra* pa = *(Palavra**)a;
    Palavra* pb = *(Palavra**)b;

    if(pa->frequencia == pb->frequencia) return strcmp(pa->string, pb->string);
    else return pa->frequencia - pb->frequencia;
}

Palavra** ordenaVetorPalavras(Palavra** palavra, int tamanho){
    qsort(palavra, tamanho, sizeof(struct palavra*), compare);
    return palavra;
}

