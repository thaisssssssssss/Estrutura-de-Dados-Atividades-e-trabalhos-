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

void imprimePalavra(Palavra* palavra){
    Palavra* aux = palavra;
    printf("Lista inicio: (\n");
    while(aux != NULL){
        printf("%s : %d\n", aux->palavra, aux->frequencia);
        aux = aux->prox;
    }
    printf(")\n");
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
            return prim;
        }
        aux = aux->prox;
    }

    prim->prox = adicionada;
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