// 
// lista.h
// 
// Created by Thais Gomes on 19/05/2025.
// 

#ifndef lista_h
#define lista_h

#include "produto.h"

typedef struct lista Lista;

/**Cria lista simplesmente encadeada
 * inputs: nenhum
 * output: lista incializada
 * pre-condicao: nao ha
 * pos-condicao: lista deve estar incializada
 */
Lista* criaLista();

/**Insere um produto especifico no fim da lista
 * inputs: lista e produto
 * output: nao ha
 * pre-condicao: lista e produto devem existir
 * pos-condicao: produto inserido na lista
 */
void insereProdutoLista(Lista* l, tProduto* prod);

/**Confere se o produto com o mesmo codigo do parametro esta na lista
 * inputs: lista e codigo do produto
 * output: 1 caso o produto esteja na lista, 0 caso contario
 * pre-condicao: lista deve existir
 * pos-condicao: lista nao eh modificada
 */
int confereTemProdutoLista(Lista* l, int codigo);

/**Retira um produto da lista
 * inputs: lista e codigo do produto
 * output: produto ou NULL caso nao esteja na lista
 * pre-condicao: lista deve existir
 * pos-condicao: produto eh retirado da lista e a celula que o alojava e liberada
 */
tProduto* retiraProdutoLista(Lista* l, int codigo);

/**Imprime lista
 * inputs: lista 
 * output: nenhum
 * pre-condicao: lista deve existir
 * pos-condicao: lista nao eh modificada
 */
void imprimeLista(Lista* l);

/**Libera a lista
 * inputs: lista
 * output: nenhum
 * pre-condicao: lista deve existir
 * pos-condicao: lista eh liberada
 */
void liberaLista(Lista* l);

#endif