#ifndef lista_h
#define lista_h

#define CACHORRO 2
#define GATO 3

#include "gato.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cachorro.h"

typedef struct lista Lista;

/// @brief inicializa uma lista
/// pos-condicao lista deve estar inicializada e seus componentes apontando pra NULL
/// @return a lista inicializada
Lista* inicializaLista();

/// @brief adiciona um animal a lista
/// @param l 
/// @param animal 
/// @param especie 
/// pre-condicao lista deve existir
/// pos-condicao animal deve ser adicionado a lista
/// @return lista atualizada
Lista* adicionaAnimalLista(Lista* l, void* animal, int especie);

/// @brief imprime a lista
/// @param l 
/// pre-condicao lista deve existir
void imprimeLista(Lista* l);

/// @brief retorna a qtd de animais de determinada especie
/// @param l 
/// @param especie 
/// pre-condicao lista deve existir
/// pos-condicao retorna qtd de animais
/// @return inteiro com a quantidade de especies
int returnQtdPorEspecie(Lista* l, int especie);

/// @brief libera a lista
/// @param l 
/// pre-condicao lista deve existir
/// pos-condicao lista deve ser liberada da memoria
void liberaLista(Lista* l);

/// @brief verifica se um animal esta na lista errada
/// @param l 
/// @param animal 
/// @param especie 
/// @param agressividade 
/// pre-condicao lista deve existir
/// pos-condicao retorna 1 caso o animal esteja na lista errada e 0 caso contrario
/// @return um inteiro
int confereAnimalEstaNaListaErrada(Lista* l, void* animal, int especie, int agressividade);

/// @brief retira determinado animal da lista
/// @param l 
/// @param animal 
/// @param especie 
/// pre-condicao lista deve existir
/// pos-condicao animal deve ser retirado da lista
/// @return lista atualizada
Lista* retiraAnimalLista(Lista* l, void* animal, int especie);

#endif