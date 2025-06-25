//
//
// Criado por Thais Gomes no dia 23/06/2025
//
//

#include "lista.h"

typedef struct celula Celula;

struct celula{
    void* comida;
    int tipo;
    Celula* ant;
    Celula* prox;
};

struct lista{
    Celula* prim;
    Celula* ult;
    int tamanho;
};


Lista* criaLista(){
    Lista* l = malloc(sizeof(struct lista));
    l->prim = NULL;
    l->ult = NULL;
    l->tamanho = 0;
    return l;
}

void insereComidaLista(Lista* l, void* comida, int tipo){
    Celula* nova = malloc(sizeof(struct celula));
    nova->comida = comida;
    nova->tipo = tipo;
    nova->ant = NULL;
    nova->prox = NULL;

    if(l->prim == NULL && l->ult == NULL){
        l->prim = nova;
        l->ult = nova;
        l->tamanho++;
        return;
    }

    l->ult->prox = nova;
    nova->ant = l->ult;
    l->ult = nova;
    l->tamanho++;
}

void imprimeLista(Lista* l){
    Celula* aux;
    for(aux = l->prim; aux != NULL; aux = aux->prox){
        if(aux->tipo == VEGANA) imprimeComidaVegana(aux->comida);
        else imprimeComidaNaoVegana(aux->comida);
    }
}

int retornaTamanhoLista(Lista* l){
    return l->tamanho;
}

float retornaValorTotalLista(Lista* l){
    float valor = 0;
    Celula* aux;
    for(aux = l->prim; aux != NULL; aux = aux->prox){
        if(aux->tipo == VEGANA){
            valor += 30;
        }
        else{
            valor += retornaValorComidaNaoVegana(aux->comida);
        }
    }
    return valor;
}

void liberaLista(Lista* l){
    Celula* atual = l->prim;
    Celula* seguinte;

    while(atual != NULL){
        seguinte = atual->prox;
        free(atual);
        atual = seguinte;
    }
    free(l);
}

int confereComidaEstaNaLista(Lista* l, void* comida, int tipo){
    Celula* aux;
    for(aux = l->prim; aux != NULL; aux = aux->prox){
        if(aux->tipo == tipo){
            if(comparaNomeComida(aux->comida, comida, tipo)) return 1;
        }
    }
    return 0;
}

int comparaNomeComida(void* comida1, void* comida2, int tipo){
    if(tipo == VEGANA){
        return(strcmp(retornaNomeComidaVegana(comida1), retornaNomeComidaVegana(comida2)) == 0);
    }
    else if(tipo == NVEG){
        return(strcmp(retornaNomeComidaVegana(comida1), retornaNomeComidaVegana(comida2)) == 0);       
    }   
}

void retiraComidaDaLista(Lista* l, void* comida, int tipo){
    Celula* aux = l->prim;

    while(aux != NULL){
        if(aux->tipo == tipo){
            if(comparaNomeComida(aux->comida, comida, tipo)) break;
        }
        aux = aux->prox;
    }

    //nao esta na lista
    if(aux == NULL) return;

    //unica 
    if(aux == l->prim && aux == l->ult){
        l->prim = NULL;
        l->ult = NULL;
        l->tamanho--;
        free(aux);
        return;
    }

    //primeira
    if(aux == l->prim){
        aux->prox->ant = NULL;
        l->prim = aux->prox;
        l->tamanho--;
        free(aux);
        return;
    }

    //ultima
    if(aux == l->ult){
        aux->ant->prox = NULL;
        l->ult = aux->ant;
        l->tamanho--;
        free(aux);
        return;
    }

    aux->prox->ant = aux->ant;
    aux->ant->prox = aux->prox;
    l->tamanho--;
    free(aux);
}