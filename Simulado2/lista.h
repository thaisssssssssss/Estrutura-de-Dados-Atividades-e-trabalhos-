//
//
// Criado por Thais Gomes no dia 23/06/2025
//
//

#ifndef lista_h
#define lista_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ComidaNaoVegana.h"
#include "ComidaVegana.h"

#define VEGANA 1
#define NVEG 0

typedef struct lista Lista;


/// @brief cria uma lista heterogenea
/// @return lista inicializada
Lista* criaLista();

/// @brief insere uma comida no final da lista
/// @param l lista a ser incrementada
/// @param comida comida a ser adicionada
/// @param tipo vegana ou nao
void insereComidaLista(Lista* l, void* comida, int tipo);

/// @brief imprime todas as comidas da lista, diferenciando se sao ou nao veganas
/// @param l lista a ser impressa
void imprimeLista(Lista* l);

/// @brief retorna o tamanho de uma lista
/// @param l lista que tera seu tamanho retornada
/// @return inteiro com o comprimento da lista
int retornaTamanhoLista(Lista* l);

/// @brief retorna o valor total dos alimentos de uma lista diferenciando se sao ou nao veganas
/// @param l lista a ser analisada
/// @return float com o valor total da lista
float retornaValorTotalLista(Lista* l);

/// @brief libera a lista
/// @param l lista a ser liberada
void liberaLista(Lista* l);

/// @brief confere se uma comida esta na lista, comparando os nomes
/// @param l lista a ser analisada
/// @param comida comida a ser comparada
/// @param tipo vegana ou nao
/// @return 1 caso esteja na lista, 0 caso contrario
int confereComidaEstaNaLista(Lista* l, void* comida, int tipo);

/// @brief retira um alimento da lista
/// @param l lista a ser percorrida
/// @param comida comida a ser comparada
/// @param tipo vegana ou nao
void retiraComidaDaLista(Lista* l, void* comida, int tipo);

/// @brief compara o nome de duas comidas, diferenciando se sao ou nao veganas 
/// @param comida1 
/// @param comida2 
/// @param tipo vegana ou nao
/// @return 1 caso sejam iguais, 0 caso contrario
int comparaNomeComida(void* comida1, void* comida2, int tipo);

#endif