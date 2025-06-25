//
// criado por Thais Brandao
//
// dia 28 de marco de 2025
//

#include "lista.h"

struct listaDpl {
    tProduto* prod;
    ListaDpl* prox;
    ListaDpl* ant;
};


/**Cria uma lista vazia
 * inputs: nao ha
 * output: lista vazia = NULL
 * pre-condicao: nenhuma
 * pos-condicao: lista deve ser igual a NULL
 */
ListaDpl* criaLista(){
    return NULL;
}


/**Insere elemento no inicio da lista
 * inputs: lista e elemento
 * output: lista atualizada
 * pre-condicao: lista l e elemento devem existir
 * pos-condicao: lista deve existir e ser diferente de NULL
 */
ListaDpl* insereElementoListaInicio(ListaDpl* l, tProduto* prod){
    ListaDpl* nova = malloc(sizeof(struct listaDpl));
    nova->prod = prod;
    nova->prox = l;
    nova->ant = NULL;
    if(l != NULL) l->ant = nova;    //se o l passado nao for o primeira da lista, ento ele eh null e o ponteiro que aponta pra anterior nao existe, caso contrario, o l->ant aponta pra nova 

    return nova;
}



/**Busca elemento na lista
 * inputs: lista e codigo do elemento
 * output: lista buscada ou NULL caso nao seja encontrada
 * pre-condicao: lista l deve existir
 * pos-condicao: retorna um ponteiro para a posicao desejada na lista 
 */
static ListaDpl* buscaElementoLista(ListaDpl* l, int codigo){
    ListaDpl* p;
    for(p = l; p != NULL; p = p->prox){
        if(comparaCodigo(p->prod, codigo)) return p;
    }

    return NULL;
}



/**Retira elemento da lista
 * inputs: lista e codigo do elemento
 * output: lista atualizada
 * pre-condicao: lista l deve existir
 * pos-condicao: libera a posicao da lista desejada e retorna lista atualizada
 */
ListaDpl* retiraElementoLista(ListaDpl* l, int codigo){
    ListaDpl* p = buscaElementoLista(l, codigo);

    //casos

    if(p == NULL) return l; //nao esta na lista

    if(p == l){  //primeiro elemento
        l = l->prox;  
    }
    else{
        p->ant->prox = p->prox;
    }

    if(p->prox != NULL){  //ultimo da lista
        p->prox->ant = p->ant;
    }

    liberaProduto(p->prod);
    free(p);
    return l;
}


/**Imprime elemento da lista
 * inputs: lista e codigo do elemento
 * output: nao ha
 * pre-condicao: lista l deve existir
 * pos-condicao: nao ha
 */
void imprimeElementoPorCodigo(ListaDpl* l, int codigo){
    ListaDpl* p = buscaElementoLista(l, codigo);
    if(p != NULL) imprimeProduto(p->prod);
}


/**Imprime a lista
 * inputs: lista l
 * output: nao ha
 * pre-condicao: lista l deve existir
 * pos-condicao: nao ha
 */
void imprimeLista(ListaDpl* l){
    ListaDpl* aux;
    for(aux = l; aux != NULL; aux = aux->prox){
        imprimeProduto(aux->prod);
    }
}


/**Libera a lista
 * inputs: lista l
 * output: nao ha
 * pre-condicao: lista l deve existir
 * pos-condicao: lista deve ter sido totalmente liberada da memoria
 */
void liberaLista(ListaDpl* l){
    ListaDpl* temp = l;
    ListaDpl* next;
     
    while(temp != NULL){
        next = temp;
        temp = temp->prox;
        liberaProduto(next->prod);
        free(next);
    }
}