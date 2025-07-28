// arvore.c
//
// Criado por Thais Gomes Brandao no dia 27/07/2025
//

#include "arvore.h"

struct arvore{
    char* palavra;
    Arvore* dir;
    Arvore* esq;
};

Arvore* criaArvoreVazia(){
    return NULL;
}

Arvore* criaArvore(char* palavra, Arvore* esq, Arvore* dir){
    Arvore* arv = malloc(sizeof(struct arvore));
    arv->palavra = strdup(palavra);
    arv->dir = dir;
    arv->esq = esq;
    return arv;
}

int comparaPalavras(char* palavra, Arvore* arv){
    return strcmp(palavra, arv->palavra);
}

int estaVaziaArvore(Arvore* arv){
    return (arv == NULL);
}

Arvore* inserePalavraArvore(Arvore* arv, char* palavra){
    if(estaVaziaArvore(arv)){
        arv = criaArvore(palavra, NULL, NULL);
    }
    else if(comparaPalavras(palavra, arv) < 0) arv->esq = inserePalavraArvore(arv->esq, palavra);
    else if(comparaPalavras(palavra, arv) >= 0) arv->dir = inserePalavraArvore(arv->dir, palavra);
    return arv;
}

void imprimeArvore(Arvore* arv){
    if(!estaVaziaArvore(arv)){
        imprimeArvore(arv->esq);
        printf("\n%s\n", arv->palavra);
        imprimeArvore(arv->dir);
    }
}

int qtdTotaldePalavras(Arvore* arv){
    if(estaVaziaArvore(arv)) return 0;
    else{
        int total = 1 + qtdTotaldePalavras(arv->esq) + qtdTotaldePalavras(arv->dir);
        return total;
    }
}

int ocorrenciasPalavraArvore(Arvore* arv, char* palavra){
    if(estaVaziaArvore(arv)) return 0;
    else{
        if(!comparaPalavras(palavra, arv)){
            return 1 + ocorrenciasPalavraArvore(arv->esq, palavra) + ocorrenciasPalavraArvore(arv->dir, palavra);
        }
        else return ocorrenciasPalavraArvore(arv->esq, palavra) + ocorrenciasPalavraArvore(arv->dir, palavra);
    }
}

int existePalavraArvore(Arvore* arv, char* palavra){
    if(estaVaziaArvore(arv)) return 0;
    else{
        if(!comparaPalavras(palavra, arv)) return 1;
        else{
            int esq = existePalavraArvore(arv->esq, palavra);
            if(esq) return 1;
            else return existePalavraArvore(arv->dir, palavra);
        }
    }
}

void ocorrenciaPalavrasDistintasArvore(Arvore* arv, Arvore** visitada, int* totalPalavras){
    if(estaVaziaArvore(arv)) return;
    else{
        if(!existePalavraArvore(*visitada, arv->palavra)){
            *visitada = inserePalavraArvore(*visitada, arv->palavra);
        }
        else *totalPalavras = *totalPalavras - 1;

        ocorrenciaPalavrasDistintasArvore(arv->esq, visitada, totalPalavras);
        ocorrenciaPalavrasDistintasArvore(arv->dir, visitada, totalPalavras);
    }
}

void palavraMaisFrequenteArvore(Arvore* arv, Arvore** visitada, int* frequencia, char** palavra){
    if(estaVaziaArvore(arv)) return;
    else{
        if(!existePalavraArvore(*visitada, arv->palavra)){
            *visitada = inserePalavraArvore(*visitada, arv->palavra);

            int repeticoes = ocorrenciasPalavraArvore(arv, arv->palavra);
            if(repeticoes > *frequencia){
                *frequencia = repeticoes;
                *palavra = arv->palavra;
            }
        }

        palavraMaisFrequenteArvore(arv->esq, visitada, frequencia, palavra);
        palavraMaisFrequenteArvore(arv->dir, visitada, frequencia, palavra);
    }
}


Arvore* liberaArvore(Arvore* arv){
    if(estaVaziaArvore(arv)) return NULL;
    else{
        arv->esq = liberaArvore(arv->esq);
        arv->dir = liberaArvore(arv->dir);
        free(arv->palavra);
        free(arv);
    }
    return arv;
}


void preencheVetorPalavras(Arvore* arv, Arvore** visitada, Palavra** vetor, int tamanho, int* posicao){
    if(estaVaziaArvore(arv)) return;
    else{
        if(!existePalavraArvore(*visitada, arv->palavra)){
            *visitada = inserePalavraArvore(*visitada, arv->palavra);
            if(*posicao < tamanho){
                vetor[*posicao] = criaPalavra(arv->palavra, ocorrenciasPalavraArvore(arv, arv->palavra));
                (*posicao)++;
            }
        }

        preencheVetorPalavras(arv->esq, visitada, vetor, tamanho, posicao);
        preencheVetorPalavras(arv->dir, visitada, vetor, tamanho, posicao);
    }
}