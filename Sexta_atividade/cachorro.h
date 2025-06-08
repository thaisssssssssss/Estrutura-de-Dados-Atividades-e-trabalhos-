//
//  cachorro.h
//  
//
//  Created by Thais Brandao Dockhorn on 04/06/25.
//

#ifndef cachorro_h
#define cachorro_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BRAVO 0
#define MANSO 1

typedef struct cachorro Cachorro;

/// @brief funcao que inicializa o tipo cachorro
/// @param nome 
/// @param agressividade 
/// pre-condicao nome e agressividade devem ser passados por parametro
/// pos-condicao tipo cachorro deve estar inicializado
/// @return retorna um tipo cachorro inicializado
Cachorro* inicCachorro(char* nome, int agressividade);

/// @brief libera o tipo cachorro
/// @param c 
/// pre-condicao tipo cachorro deve existir
/// pos-condicao tipo cachorro deve ser liberado da memoria
void liberaCachorro(Cachorro* c);

/// @brief funcao que recebe um tipo cachorro como parametro e retorna sua agressividade
/// @param c 
/// pre-condicao tipo cachorro deve existir
/// pos-condicao retorno de um inteiro
/// @return um inteiro representando a agressividade do cachorro
int retornaAgressividadeCachorro(Cachorro* c);

/// @brief imprime um tipo cachorro
/// @param c 
/// pre-condicao tipo cachorro deve existir
void imprimeCachorro(Cachorro* c);

/// @brief atribui um novo nivel de agressividade a um tipo cachorro
/// @param c 
/// @param agressividade 
/// pre-condicao tipo cachorro deve existir
/// pos-condicao nivel de agressividade deve ser alterado
void atribuiNivelAgressividadeCachorro(Cachorro* c, int agressividade);

/// @brief compara duas strings contendo nome de cachorros
/// @param c1 
/// @param c2 
/// pre-condicao tipo cachorro deve existir
/// pos-condicao retorno de um inteiro
/// @return 1 caso sejam iguais, 0 caso contrario
int comparaNomeCachorro(Cachorro* c1, Cachorro* c2);

#endif