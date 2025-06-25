//
//
// Criado por Thais Gomes no dia 25/06/2025
//
//


#include "lista.h"

typedef struct celula Celula;

struct celula{
    Aluno* aluno;
    Celula* prox;
    Celula* ant;
};

struct lista{
    Celula* prim;
    Celula* ult;
};


Lista* inicializaLista(){
    Lista* l = malloc(sizeof(struct lista));
    l->prim = NULL;
    l->ult = NULL;
    return l;
}

void insereOrdenadoNaLista(Lista* l, Aluno* a){
    Celula* nova = malloc(sizeof(struct celula));
    nova->aluno = a;
    nova->prox = NULL;
    nova->ant = NULL;

    if(l->prim == NULL && l->ult == NULL){
        l->prim = nova;
        l->ult = nova;
        return;
    }

    Celula* aux;
    for(aux = l->prim; aux != NULL; aux = aux->prox){
        if(retornaMatriculaAluno(aux->aluno) > retornaMatriculaAluno(nova->aluno)){
            // printf("sim\n");
            // break;

            if(aux == l->prim){
                nova->prox = l->prim;
                l->prim->ant = nova;
                l->prim = nova;
                return;
            }

            nova->ant = aux->ant;
            nova->prox = aux;
            aux->ant->prox = nova;
            aux->ant = nova;
            return;
        }
    }

    //se nao for menor que nenhum adiciona no final
    nova->ant = l->ult;
    l->ult->prox = nova;
    l->ult = nova;

}

void imprimeLista(Lista* l){
    Celula* aux;
    for(aux = l->prim; aux != NULL; aux = aux->prox){
        imprimeAluno(aux->aluno);
    }
}

void liberaLista(Lista* l){
    Celula* atual = l->prim;
    Celula* seguinte;

    while(atual != NULL){
        seguinte = atual->prox;
        liberaAluno(atual->aluno);
        free(atual);
        atual = seguinte;
    }
    free(l);
}

