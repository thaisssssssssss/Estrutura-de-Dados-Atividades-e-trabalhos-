//
//  cachorro.h
//  
//
//  Created by Thais Brandao Dockhorn on 04/06/25.
//

#ifndef gato_h
#define gato_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BRAVO 0
#define MANSO 1

typedef struct gato Gato;

/// @brief funcao que inicializa o tipo gato
/// @param nome 
/// @param agressividade 
/// pre-condicao nome e agressividade devem ser passados por parametro
/// pos-condicao tipo gato deve estar inicializado
/// @return retorna um tipo gato inicializado
Gato* inicGato(char* nome, int agressividade);

/// @brief libera o tipo gato
/// @param c 
/// pre-condicao tipo gato deve existir
/// pos-condicao tipo gato deve ser liberado da memoria
void liberaGato(Gato* gato);

/// @brief funcao que recebe um tipo gato como parametro e retorna sua agressividade
/// @param c 
/// pre-condicao tipo gato deve existir
/// pos-condicao retorno de um inteiro
/// @return um inteiro representando a agressividade do gato
int retornaAgressividadeGato(Gato* g);

/// @brief imprime um tipo gato
/// @param c 
/// pre-condicao tipo gato deve existir
void imprimeGato(Gato* g);

/// @brief atribui um novo nivel de agressividade a um tipo gato
/// @param c 
/// @param agressividade 
/// pre-condicao tipo gato deve existir
/// pos-condicao nivel de agressividade deve ser alterado
void atribuiNivelAgressividadeGato(Gato* g, int agressividade);

/// @brief compara duas strings contendo nome de gatos
/// @param c1 
/// @param c2 
/// pre-condicao tipo gato deve existir
/// pos-condicao retorno de um inteiro
/// @return 1 caso sejam iguais, 0 caso contrario
int comparaNomeGato(Gato* g1, Gato* g2);

#endif