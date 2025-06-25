#ifndef Lista_h
#define Lista_h


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gato.h"
#include "cachorro.h"


#define GATO 1
#define CACHORRO 2

typedef struct lista Lista;

/// @brief inicializa uma lista heterogenea, apontando prim e ult para NULL
/// @return lista atualizada e vazia
Lista* incializaLista();

/// @brief insere um item na ultima posicao da lista
/// @param l lista a ter elemento inserido
/// @param animal animal a ser inserido
/// @param tipo cachorro ou gato
void insereItemLista(Lista* l, void* animal, int tipo);

/// @brief imprime todos os animais de uma lista, lista deve existir
/// @param l lista a ser impressa
void imprimeLista(Lista* l);

/// @brief libera toda a lista, lista deve existir
/// @param l lista a ser liberada
void liberaLista(Lista* l);

/// @brief retorna quantidade de animais de mesma especie em uma lista
/// @param l lista a ser percorrida 
/// @param tipo cachorro ou gato
/// @return inteiro com a quantidade de animais de determinada especie
int retornaQtdPorTipo(Lista* l, int tipo);

/// @brief compara se dois animais sao de mesma especie e caso sejam, compara se tem mesmo nome, ou seja, sao o mesmo animal
/// @param animal1 animal a ser comparado
/// @param animal2 outro animal a ser comparado
/// @param tipo1 especie do primeiro animal
/// @param tipo2 especie do segundo animal
/// @return 1 se sao iguais, 0 caso contrario
int comparacao(void* animal1, void* animal2, int tipo1, int tipo2);

/// @brief confere se um animal esta na lista, lista e animal devem existir
/// @param l lista a ser percorrida
/// @param animal animal a ser comparado
/// @param tipo cachorro ou gato
/// @return 1 caso estaja na lista, 0 caso contrario
int confereItemNaLista(Lista* l, void* animal, int tipo);

/// @brief retira um animal da lista, lista e animal devem existir
/// @param l lista a ser percorrida
/// @param animal animal a ser retirado
/// @param tipo cachorro ou gato
void retiraItemLista(Lista* l, void* animal, int tipo);

#endif