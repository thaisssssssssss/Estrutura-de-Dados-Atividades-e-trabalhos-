#include "palavra.h"

struct palavra{
    int frequencia;
    char* palavra;
    Palavra* prox;
};

Palavra* criaPalavra(char* palavra){
    Palavra* p = malloc(sizeof(struct palavra));
    p->palavra = strdup(palavra);
    p->frequencia = 1;
    p->prox = NULL;

    return p;
}

Palavra* fazCasting(void* palavra){
    Palavra* p = (Palavra*)palavra;
    return p;
}

int funcaoPalavra(void* palavra, int tamanho){
    Palavra* p = fazCasting(palavra);

    int i, soma = 0;
    for(i = 0; p->palavra[i]; i++){
        soma += p->palavra[i];
    }

    return soma % tamanho;
}

int comparaPalavras(Palavra* palavra1, Palavra* palavra2){
    return strcmp(palavra1->palavra, palavra2->palavra);
}

void incrementaFrequenciaPalavra(Palavra* palavra){
    palavra->frequencia++;
}

void* trataColisao(void* palavra1, void* palavra2){
    Palavra* lista = fazCasting(palavra1);
    Palavra* nova = fazCasting(palavra2);
    Palavra* aux = lista;
    
    while(aux){
        if(!comparaPalavras(aux, nova)){
            incrementaFrequenciaPalavra(aux);
            liberaPalavra(nova);
            return lista;
        }

        //caso nao tenha nenhuma palavra igual, insere no final da lista
        if(aux->prox == NULL){
            aux->prox = nova;
            return lista;
        }
        aux = aux->prox;
    }
    return lista;
}

void imprimePalavra(void* palavra){
    Palavra* p = fazCasting(palavra);
    Palavra* aux;

    for(aux = palavra; aux != NULL; aux = aux->prox){
        printf("%s %d\n", aux->palavra, aux->frequencia);
    }
}

void imprimePalavraUnica(Palavra* p){
    printf("%s %d\n", p->palavra, p->frequencia);
}

void liberaPalavra(void* palavra){
    Palavra* p = fazCasting(palavra);
    Palavra* seguinte;

    if(p == NULL) return;

    while(p){
        seguinte = p->prox;

        free(p->palavra);
        free(p);

        p = seguinte;
    }
}

int quantidadePalavras(void* palavra){
    Palavra* p = fazCasting(palavra);
    int contador = 0;

    while(p){
        contador++;
        p = p->prox;
    }
    return contador;
}

int quantidadePalavrasTotais(void* palavra){
    Palavra* p = fazCasting(palavra);
    int contador = 0;

    while(p){
        contador += retornaFrequencia(p);
        p = p->prox;
    }
    return contador;
}

char* retornaPalavra(Palavra* palavra){
    return palavra->palavra;
}

int retornaFrequencia(Palavra* palavra){
    return palavra->frequencia;
}

Palavra* maisFrequenteLista(void* palavra){
    Palavra* lista = fazCasting(palavra);
    int frequencia = 0, aux;
    Palavra* maisFrequente;

    while(lista){
        aux = retornaFrequencia(lista);
        if(aux > frequencia){
            frequencia = aux;
            maisFrequente = lista;
        }
        lista = lista->prox;
    }
    return maisFrequente;
}

void* retornaPalavraMaisFrequente(void* vet, int tamanho){
    Palavra** vetor = (Palavra**)vet;
    Palavra* maisFrequente;
    Palavra* aux;

    int i, frequencia = 0;

    for(i = 0; i < tamanho; i++){
        if(vetor[i]){
            aux = maisFrequenteLista(vetor[i]);
            if(retornaFrequencia(aux) > frequencia){
                frequencia = retornaFrequencia(aux);
                maisFrequente = aux;
            }
        }
    }
    return maisFrequente;
}

int preencheVetor(void* palavra, Palavra** vetor, int posicao){
    Palavra* p = fazCasting(palavra);
    while(p){
        vetor[posicao] = p;
        posicao++;
        p = p->prox;
    }
    return posicao;
}

void* retornaVetorPalavras(void* vet, int tamanho){
    Palavra** vetor = (Palavra**)vet;
    Palavra* aux;

    int i, qtdPalavras = 0;

    for(i = 0; i < tamanho; i++){
        if(vetor[i]) qtdPalavras += quantidadePalavras(vetor[i]);
    }

    Palavra** vetorPalavras = malloc(sizeof(struct palavra*) * qtdPalavras);

    int posicao = 0;
    for(i = 0; i < tamanho; i++){
        posicao = preencheVetor(vetor[i], vetorPalavras, posicao);
    }

    return vetorPalavras;
}

void imprimeVetorPalavras(Palavra** vetor, int tamanho){
    int i;
    for(i = 0; i < tamanho; i++){
        imprimePalavraUnica(vetor[i]);
    }
}

int compara(const void* a, const void* b){
    Palavra* p1 = *(Palavra**)a;
    Palavra* p2 = *(Palavra**)b;

    if(retornaFrequencia(p2) == retornaFrequencia(p1)) return comparaPalavras(p1, p2);
    else return (retornaFrequencia(p1) - retornaFrequencia(p2));
}

void ordenaVetorPalavras(Palavra** vetor, int tamanho){
    qsort(vetor, tamanho, sizeof(struct palavra*), compara);
}