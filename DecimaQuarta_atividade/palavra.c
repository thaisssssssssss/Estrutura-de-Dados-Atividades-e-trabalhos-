#include "palavra.h"

struct palavra{
    char* palavra;
    int frequencia;
    Palavra* prox;
};

Palavra* criaPalavra(char* palavra){
    Palavra* p = malloc(sizeof(struct palavra));
    p->palavra = strdup(palavra);
    p->frequencia = 1;
    p->prox = NULL;
    return p;
}

// Palavra* adicionaPalavraFila(Palavra* fila, Palavra* adicionada){

// }

char* retornaCharPalavra(Palavra* palavra){
    return palavra->palavra;
}

int retornaFrequencia(Palavra* palavra){
    return palavra->frequencia;
}

void imprimePalavraLista(Palavra* palavra){
    Palavra* aux = palavra;
    printf("Lista inicio: (\n");
    while(aux != NULL){
        printf("%s : %d\n", aux->palavra, aux->frequencia);
        aux = aux->prox;
    }
    printf(")\n");
}

void imprimePalavra(Palavra* palavra){
    printf("%s : %d\n", palavra->palavra, palavra->frequencia);
}

int comparaPalavras(Palavra* p1, Palavra* p2){
    return (strcmp(p1->palavra, p2->palavra));
}

Palavra* adicionaPalavraLista(Palavra* prim, Palavra* adicionada){
    Palavra* aux = prim;

    while(aux != NULL){
        //caso seja igual a uma palavra ja na lista
        if(!comparaPalavras(aux, adicionada)){
            aux->frequencia++;
            liberaPalavra(adicionada);
            return prim;
        }
        aux = aux->prox;
    }

    aux = prim;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = adicionada;
    return prim;
}

void liberaPalavra(Palavra* palavra){
    Palavra* atual = palavra;
    Palavra* seguinte;

    while(atual != NULL){
        seguinte = atual->prox;

        free(atual->palavra);
        free(atual);

        atual = seguinte;
    }
    //free(palavra);
}

Palavra* PalavraMaisFrequente(Palavra* palavra){
    Palavra* aux = palavra;
    Palavra* nova = NULL;
    int frequencia = 0;

    while(aux != NULL){
        if(aux->frequencia > frequencia){
            frequencia = aux->frequencia;
            nova = aux;
        }
        aux = aux->prox;
    }


    return nova;

}

int retornaTamanhoLista(Palavra* palavra){
    Palavra* aux = palavra;
    int tamanho = 0;
    while(aux){
        tamanho++;
        aux = aux->prox;
    }
    return tamanho;
}

void preencheVetorPalavras(Vetor* vetor, Palavra* palavra){
    Palavra* aux = palavra;
    while(aux){
        colocaPalavraVetor(vetor, palavra);
        aux = aux->prox;
    }
}