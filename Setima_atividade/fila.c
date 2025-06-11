//
// Criado por Thais Gomes 
//
// Dia 11/06/2025
//


#include "fila.h"

typedef struct celula Celula;

struct celula{
    Amostra* amostra;
    Celula* ant;
    Celula* prox;
};

struct fila{
    Celula* prim;
    Celula* ult;
};


Fila* criaFila(){
    Fila* fila = malloc(sizeof(struct fila));

    fila->prim = NULL;
    fila->ult = NULL;
    return fila;
}


void adicionaAmostraFilaSemPrioridade(Fila* fila, Amostra* amostra){    //adiciona no final
    Celula* nova = malloc(sizeof(struct celula));
    nova->amostra = amostra;
    nova->prox = NULL;
    nova->ant = NULL;

    if(fila->prim == NULL && fila->ult == NULL){
        fila->prim = nova;
        fila->ult = nova;
    }
    else{
        nova->ant = fila->ult;
        fila->ult->prox = nova;
        fila->ult = nova;
    }
}


void adicionaAmostraFilaComPrioridade(Fila* fila, Amostra* amostra){    //adiciona no inicio
    Celula* nova = malloc(sizeof(struct celula));
    nova->amostra = amostra;
    nova->prox = NULL;
    nova->ant = NULL;

    if(fila->prim == NULL && fila->ult == NULL){
        fila->prim = nova;
        fila->ult = nova;
    }
    else{
        nova->prox = fila->prim;
        fila->prim->ant = nova;
        fila->prim = nova;
    }
}


Amostra* retiraAmostraFila(Fila* fila){
    if(fila->prim != NULL){
        return fila->prim->amostra;
    }
    else return NULL;
}

void liberaCelulaFila(Fila* fila){
    if(fila->prim != NULL){
        Celula* aux = fila->prim;
        fila->prim = fila->prim->prox;
        free(aux);
    }
}

void liberaFila(Fila* fila){
    Celula* atual = fila->prim;
    Celula* seguinte;

    while(atual != NULL){
        seguinte = atual->prox;
        liberaAmostra(atual->amostra);
        free(atual);
        atual = seguinte;
    }
    free(fila);
}


void imprimeFila(Fila* fila){
    Celula* aux;
    for(aux = fila->prim; aux != NULL; aux = aux->prox){
        imprimeAmostra(aux->amostra);
    }
}


// void organizaFilas(Fila* naoProcessados, Fila* positivo, Fila* negativo, int limite){
//     Celula* atual = naoProcessados->prim;
//     Celula* seguinte;

//     while(atual != NULL){
//         seguinte = atual->prox;
        
//         if(retornaCargaViral(atual->amostra) >= limite){
//             registraResultado(atual->amostra, 1);
//             if(retornaIdade(atual->amostra) >= 60){
//                 adicionaAmostraFilaComPrioridade(positivo, atual->amostra);
//             }
//             else{
//                 adicionaAmostraFilaSemPrioridade(positivo, atual->amostra);
//             }
//         }
//         else{
//             registraResultado(atual->amostra, 0);
//             if(retornaIdade(atual->amostra) >= 60){
//                 adicionaAmostraFilaComPrioridade(negativo, atual->amostra);
//             }
//             else{
//                 adicionaAmostraFilaSemPrioridade(negativo, atual->amostra);
//             }
//         }

//         free(atual);
//         atual = seguinte;
//     }
// }
