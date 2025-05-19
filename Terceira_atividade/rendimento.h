//
//  rendimento.h
//  TADRendimentoEscolar
//
//  Created by Thais Gomes Brandão on 19/05/20.
//  Copyright © 2025 Thais Gomes Brandão. All rights reserved.
//


#ifndef rendimento_h
#define rendimento_h

#include "matriz.h"

//Tipo rendimento (tipo opaco)
typedef struct rendimento Rendimento;


/*Inicializa um struct rendimento e seus componentes
 * inputs: nenhum
 * output: ponteiro para o rendimento inicializado
 * pre-condicao: nao ha
 * pos-condicao: struct rendimento incializada e preenchida
 */
Rendimento* inicializaRendimento();

/*Recebe os valores de cada posicao da matriz
 * inputs: numero de linhas (nlinhas), de colunas (ncolunas) e a matriz inicializada
 * output: ponteiro para a matriz preenchida
 * pre-condicao: a matriz deve existir e estar inicializada
 * pos-condicao: a matriz deve estar preenchida
 */
Matriz* recebeRendimentos (int nlinhas, int ncolunas, Matriz* mat);

/*Preenche uma posicao da matriz com o rendimento do aluno em ingles
 * inputs: linha a ser preenchida (row), coluna a ser preenchida (col) e a matriz inicializada
 * output: nao ha
 * pre-condicao: a matriz deve existir e estar inicializada
 * pos-condicao: a posicao definida da matriz deve estar preenchida
 */
void recebeRendimentoIngles(int row, int col, Matriz* mat);

/*Preenche uma posicao da matriz com o rendimento do aluno em matematica
 * inputs: linha a ser preenchida (row), coluna a ser preenchida (col) e a matriz inicializada
 * output: nao ha
 * pre-condicao: a matriz deve existir e estar inicializada
 * pos-condicao: a posicao definida da matriz deve estar preenchida
 */
void recebeRendimentoMatematica(int row, int col, Matriz* mat);

/*Preenche uma posicao da matriz com o rendimento do aluno em programacao
 * inputs: linha a ser preenchida (row), coluna a ser preenchida (col) e a matriz inicializada
 * output: nao ha
 * pre-condicao: a matriz deve existir e estar inicializada
 * pos-condicao: a posicao definida da matriz deve estar preenchida
 */
void recebeRendimentoProgramacao(int row, int col, Matriz* mat);

/*Imprime a matriz de rendimento
 * inputs: struct rendimento
 * output: nao ha
 * pre-condicao: o rend deve existir e a matriz deve existir, estar inicializada e preenchida
 * pos-condicao: a matriz de rendimento deve ser impressa
 */
void imprimeRendimento(Rendimento* rend);

/*Libera toda a memoria alocada para o rendimento
 * inputs: rendimento rend
 * output: nenhum
 * pre-condicao: rendimento rend existe
 * pos-condicao: memoria liberada!
 */
void destroiRendimento (Rendimento* rend);

#endif