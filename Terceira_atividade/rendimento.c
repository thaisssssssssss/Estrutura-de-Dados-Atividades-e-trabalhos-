//
//  rendimento.h
//  TADRendimentoEscolar
//
//  Created by Thais Gomes Brandão on 19/05/20.
//  Copyright © 2025 Thais Gomes Brandão. All rights reserved.
//


#include <stdio.h>
#include "matriz.h"
#include <stdlib.h>
#include "rendimento.h"

#define ING 0
#define MAT 1
#define PROG 2

//Tipo rendimento (tipo opaco)
typedef struct rendimento Rendimento;


struct rendimento{
    Matriz *mat;
};

/*Inicializa um struct rendimento e seus componentes
 * inputs: nenhum
 * output: ponteiro para o rendimento inicializado
 * pre-condicao: nao ha
 * pos-condicao: struct rendimento incializada e preenchida
 */
Rendimento* inicializaRendimento(){
    Rendimento* rend = malloc(sizeof(struct rendimento));

    int rows, cols;
    printf("digite o numero de linhas e colunas da primeira matriz de rendimento:");
    scanf("%d %d", &rows, &cols);

    rend->mat = inicializaMatriz(rows, cols);
    rend->mat = recebeRendimentos(rows, cols, rend->mat);
    return rend;
}

/*Recebe os valores de cada posicao da matriz
 * inputs: numero de linhas (nlinhas), de colunas (ncolunas) e a matriz inicializada
 * output: ponteiro para a matriz preenchida
 * pre-condicao: a matriz deve existir e estar inicializada
 * pos-condicao: a matriz deve estar preenchida
 */
Matriz* recebeRendimentos (int nlinhas, int ncolunas, Matriz* mat){
    int r, c;
    for(r = 0; r < nlinhas; r++){
        for(c = 0; c < ncolunas; c++){

            if(c == ING){
                recebeRendimentoIngles(r, c, mat);
            }
            else if(c == MAT){
                recebeRendimentoMatematica(r, c, mat);
            }
            else if(c == PROG){
                recebeRendimentoProgramacao(r, c, mat);
            }
            
        }
    }

    return mat;
}

/*Preenche uma posicao da matriz com o rendimento do aluno em ingles
 * inputs: linha a ser preenchida (row), coluna a ser preenchida (col) e a matriz inicializada
 * output: nao ha
 * pre-condicao: a matriz deve existir e estar inicializada
 * pos-condicao: a posicao definida da matriz deve estar preenchida
 */
void recebeRendimentoIngles(int row, int col, Matriz* mat){
    int element;
    printf("digite o rendimento do aluno %d em ingles", row);
    scanf("%d", &element);
    modificaElemento(mat, row, col, element);
}

/*Preenche uma posicao da matriz com o rendimento do aluno em matematica
 * inputs: linha a ser preenchida (row), coluna a ser preenchida (col) e a matriz inicializada
 * output: nao ha
 * pre-condicao: a matriz deve existir e estar inicializada
 * pos-condicao: a posicao definida da matriz deve estar preenchida
 */
void recebeRendimentoMatematica(int row, int col, Matriz* mat){
    int element;
    printf("digite o rendimento do aluno %d em matematica", row);
    scanf("%d", &element);
    modificaElemento(mat, row, col, element);
}

/*Preenche uma posicao da matriz com o rendimento do aluno em programacao
 * inputs: linha a ser preenchida (row), coluna a ser preenchida (col) e a matriz inicializada
 * output: nao ha
 * pre-condicao: a matriz deve existir e estar inicializada
 * pos-condicao: a posicao definida da matriz deve estar preenchida
 */
void recebeRendimentoProgramacao(int row, int col, Matriz* mat){
    int element;
    printf("digite o rendimento do aluno %d em programacao", row);
    scanf("%d", &element);
    modificaElemento(mat, row, col, element);
}

/*Imprime a matriz de rendimento
 * inputs: struct rendimento
 * output: nao ha
 * pre-condicao: o rend deve existir e a matriz deve existir, estar inicializada e preenchida
 * pos-condicao: a matriz de rendimento deve ser impressa
 */
void imprimeRendimento(Rendimento* rend){
    imprimeMatriz(rend->mat);
}

/*Libera toda a memoria alocada para o rendimento
 * inputs: rendimento rend
 * output: nenhum
 * pre-condicao: rendimento rend existe
 * pos-condicao: memoria liberada!
 */
void destroiRendimento (Rendimento* rend){
    if(rend != NULL){
        destroiMatriz(rend->mat);
        free(rend);
    }
}
