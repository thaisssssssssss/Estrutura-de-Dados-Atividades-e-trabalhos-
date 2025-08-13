#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arv_exp.h"

/*Tipo que define a arvore(tipo opaco)
  Estrutura interna do tipo deve ser definida na implementação do TAD. */
struct arv{
    int operando;
    char operador;
    Arv* esq;
    Arv* dir;
};

/*Cria uma arvore vazia, ou seja, retorna NULL
* inputs: nenhum
* output: NULL
*/
Arv* CriaVazia(void){
    return NULL;
}

/*cria um nó raiz de operador dados o operador e as duas sub-árvores, a da esquerda e a da direita
* inputs: o operador, as sub-arvores da esquerda e da direita
* output: o endereço do nó raiz criado
*/
Arv* CriaOperador(char c, Arv* esq, Arv* dir){
    Arv* a = malloc(sizeof(struct arv));
    a->operador = c;
    a->esq = esq;
    a->dir = dir;
    return a;
}

/*cria um nó operando dado o valor do no (como o operando é um nó folha, as sub-arvores da esquerda e da direita são nulas
* inputs: o operando
* output: o endereço do nó raiz criado
*/
Arv* CriaOperando(int valor){
    Arv* a = malloc(sizeof(struct arv));
    a->operando = valor;
    a->esq = NULL;
    a->dir = NULL;
    return a;
}

/*Imprime a árvore em notação InOrder (esq, raiz, direita)
* inputs: o endereço da raiz da árvore
* output: nenhum
*/
void Imprime(Arv* arv){
    if(arv == NULL);
    else{
        Imprime(arv->esq);
        if(arv->esq == NULL && arv->dir == NULL) printf(" %d ", arv->operando);
        else printf(" %c ", arv->operador);
        Imprime(arv->dir);
    }
}

/* Libera memória alocada pela estrutura da árvore
as sub-árvores devem ser liberadas antes de se liberar o nó raiz
* inputs: o endereço da raiz da árvore
* output: uma árvore vazia, representada por NULL
*/
Arv* Libera (Arv* arv){
    if(arv == NULL) return NULL;
    else{
        Libera(arv->esq);
        Libera(arv->dir);
        free(arv);
        arv = NULL;
    }
    return arv;
}


/* Retorna o valor correspondente à avaliação da expressão representada na árvore
* inputs: o endereço da raiz da árvore
* output: o valor da expressão
*/
float Avalia(Arv* arv){
    if(arv == NULL) return 0;
    else if(arv->esq == NULL && arv->dir == NULL) return (float)arv->operando;
    else{
        int esq = Avalia(arv->esq);
        int dir = Avalia(arv->dir);

        if(arv->operador == '+') return esq + dir;
        else if(arv->operador == '-') return esq - dir;
        if(arv->operador == '*') return esq * dir;
        if(arv->operador == '/') return esq / dir;
    }
}


/* Retorna o número de folhas da árvore
* inputs: o endereço da raiz da árvore
* output: o número de folhas
*/
int Folhas(Arv* arv){
    if(arv == NULL) return 0;
    else if(arv->dir == NULL && arv->esq == NULL) return 1;
    else{
        int esq = Folhas(arv->esq);
        int dir = Folhas(arv->dir);
        return esq + dir;
    }
}

/* Retorna a altura da árvore
* inputs: o endereço da raiz da árvore
* output: a altura da árvore
*/
int Altura(Arv* arv){
    if(arv == NULL) return -1;
    else{
        int esq = Altura(arv->esq);
        int dir = Altura(arv->dir);

        if(esq > dir) return esq + 1;
        else return dir + 1;
    }
}


