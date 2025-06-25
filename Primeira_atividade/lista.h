//
// criado por Thais Brandao
//
// dia 28 de marco de 2025
//
#ifndef lista_h
#define lista_h
#include "produto.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct listaDpl ListaDpl;

/**Cria uma lista vazia
 * inputs: nao ha
 * output: lista vazia = NULL
 * pre-condicao: nenhuma
 * pos-condicao: lista deve ser igual a NULL
 */
ListaDpl* criaLista();

/**Insere elemento no inicio da lista
 * inputs: lista e elemento
 * output: lista atualizada
 * pre-condicao: lista l e elemento devem existir
 * pos-condicao: lista deve existir e ser diferente de NULL
 */
ListaDpl* insereElementoListaInicio(ListaDpl* l, tProduto* prod);

/**Retira elemento da lista
 * inputs: lista e codigo do elemento
 * output: lista atualizada
 * pre-condicao: lista l deve existir
 * pos-condicao: libera a posicao da lista desejada e retorna lista atualizada
 */
ListaDpl* retiraElementoLista(ListaDpl* l, int codigo);

/**Imprime elemento da lista
 * inputs: lista e codigo do elemento
 * output: nao ha
 * pre-condicao: lista l deve existir
 * pos-condicao: nao ha
 */
void imprimeElementoPorCodigo(ListaDpl* l, int codigo);

/**Imprime a lista
 * inputs: lista l
 * output: nao ha
 * pre-condicao: lista l deve existir
 * pos-condicao: nao ha
 */
void imprimeLista(ListaDpl* l);

/**Libera a lista
 * inputs: lista l
 * output: nao ha
 * pre-condicao: lista l deve existir
 * pos-condicao: lista deve ter sido totalmente liberada da memoria
 */
void liberaLista(ListaDpl* l);

#endif