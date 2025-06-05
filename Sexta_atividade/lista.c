#include "lista.h"

typedef struct celula Celula;

struct celula{
    void* animal;
    int especie;
    Celula* ant;
    Celula* prox;
};

struct lista{
    Celula* prim;
    Celula* ult;
};

Lista* inicializaLista(){
    Lista* lista = malloc(sizeof(struct lista));
    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

Lista* adicionaCachorroLista(Lista* l, Cachorro* c){
    Celula* nova = malloc(sizeof(struct celula));
    nova->animal = c;
    nova->especie = CACHORRO;
    nova->ant = NULL;
    nova->prox = NULL;

    if(l->prim == NULL && l->ult == NULL){
        l->prim = nova;
        l->ult = nova;
    }
    else{
        nova->ant = l->ult;
        l->ult->prox = nova;
        l->ult = nova;
    }
    return l;
}

Lista* adicionaGatoLista(Lista* l, Gato* g){
    Celula* nova = malloc(sizeof(struct celula));
    nova->animal = g;
    nova->especie = GATO;
    nova->ant = NULL;
    nova->prox = NULL;

    if(l->prim == NULL && l->ult == NULL){
        l->prim = nova;
        l->ult = nova;
    }
    else{
        nova->ant = l->ult;
        l->ult->prox = nova;
        l->ult = nova;
    }
    return l;
}

void imprimeLista(Lista* l){
    Celula* aux;
    for(aux = l->prim; aux != NULL; aux = aux->prox){
        if(aux->especie == CACHORRO) imprimeCachorro(aux->animal);
        else imprimeGato(aux->animal);
    }
}

int returnQtdGatos(Lista* l){
    Celula* aux;
    int qtd = 0;
    for(aux = l->prim; aux != NULL; aux = aux->prox){
        if(aux->especie == GATO) qtd++;
    }
    return qtd;
}

int returnQtdCachorros(Lista* l){
    Celula* aux;
    int qtd = 0;
    for(aux = l->prim; aux != NULL; aux = aux->prox){
        if(aux->especie == CACHORRO) qtd++;
    }
    return qtd;
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

int confereAnimalEstaNaListaErrada(Lista* l, void* animal, int especie, int agressividade){
    if(especie == GATO){
        Celula* aux;
        for(aux = l->prim; aux != NULL; aux = aux->prox){
            if(aux->especie == GATO){
                if(comparaNomeGato(animal, aux->animal)){
                    if(retornaAgressividadeGato(aux->animal) == agressividade) return 1;
                }
            }
        }
        return 0;
    }
    else if(especie == CACHORRO){
        Celula* aux;
        for(aux = l->prim; aux != NULL; aux = aux->prox){
            if(aux->especie == CACHORRO){
                if(comparaNomeCachorro(animal, aux->animal)){
                    if(retornaAgressividadeCachorro(aux->animal) == agressividade) return 1;
                }
            }
        }
        return 0;
    }
}

Lista* retiraAnimalLista(Lista* l, void* animal, int especie){
    Celula* aux = l->prim;
    if(especie == GATO){
        while(aux != NULL){
            if(aux->especie == especie && comparaNomeGato(animal, aux->animal)) break;
            aux = aux->prox;
        }
    }
    else if(especie == CACHORRO){
        while(aux != NULL){
            if(aux->especie == especie && comparaNomeCachorro(animal, aux->animal)) break;
            aux = aux->prox;
        }
    }
       
    if(aux == l->prim){ //primeiro da lista
        aux->ant = NULL;
        l->prim = aux->prox;
        free(aux);
        return l;
    }

    if(aux == l->ult){ //ultimo da lista
        aux->prox = NULL;
        l->ult = aux->ant;
        free(aux);
        return l;
    }
    
    if(aux != NULL){
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
        free(aux);
        return l;
    }

}

// Lista* retiraAnimalLista(Lista* l, void* animal, int especie) {
//     Celula* aux = l->prim;

//     while (aux != NULL) {
//         if (aux->especie == especie) {
//             if ((especie == GATO && comparaNomeGato(animal, aux->animal)) ||
//                 (especie == CACHORRO && comparaNomeCachorro(animal, aux->animal))) {
//                 break;
//             }
//         }
//         aux = aux->prox;
//     }

//     if (aux == NULL) return l; // animal não encontrado

//     if (aux == l->prim) { // primeiro da lista
//         aux->ant = NULL;
//         l->prim = aux->prox;  
//         free(aux);
//         return l;
//     }
//     else if (aux == l->ult) { // último da lista
//         aux->prox = NULL;
//         l->ult = aux->ant;
//         free(aux);
//         return l;
//     }
//     else { // meio da lista
//         aux->ant->prox = aux->prox;
//         aux->prox->ant = aux->ant;
//         free(aux);
//         return l;
//     }

// }
