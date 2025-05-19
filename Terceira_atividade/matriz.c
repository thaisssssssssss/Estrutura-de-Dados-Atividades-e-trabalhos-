#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

//Tipo matriz (tipo opaco)
//Estrutura interna do tipo deve ser definida na implementacao do TAD
typedef struct matriz Matriz;

struct matriz{
    int** matrix;
    int rows;
    int cols;
};

/*Inicializa uma matriz de nlinhas e ncolunas
 * inputs: nlinhas (no de linhas) e ncolunas (no de colunas)
 * output: ponteiro para a matriz inicializada
 * pre-condicao: nlinhas e ncolunas diferentes de 0
 * pos-condicao: matriz de retorno existe e contem nlinhas e ncolunas
 */
Matriz* inicializaMatriz (int nlinhas, int ncolunas){
    Matriz *mat = malloc(sizeof(struct matriz));
    mat->matrix = malloc(nlinhas * sizeof(int*));
    if(mat == NULL){
        printf("erro ao alocar");
        exit(1);
    }

    int i;
    for(i = 0; i < nlinhas; i++){
        mat->matrix[i] = malloc(ncolunas * sizeof(int));
    }

    mat->cols = ncolunas;
    mat->rows = nlinhas;
    return mat;
}

/*Modifica o elemento [linha][coluna] da matriz mat
 * inputs: a matriz, a linha, a coluna, e o novo elemento
 * output: nenhum
 * pre-condicao: matriz mat existe, linha e coluna sao validos na matriz
 * pos-condicao: elemento [linha][coluna] da matriz modificado
 */
void modificaElemento (Matriz* mat, int linha, int coluna, int elem){
    mat->matrix[linha][coluna] = elem;    
}

/*Retorna o elemento mat[linha][coluna]
 * inputs: a matriz, a linha e a coluna
 * output: elemento mat[linha][coluna]
 * pre-condicao: matriz mat existe, linha e coluna sao validos na matriz
 * pos-condicao: mat nao eh modificada
 */
int recuperaElemento(Matriz* mat, int linha, int coluna){
    return mat->matrix[linha][coluna];    
}

/*Retorna o numero de colunas da matriz mat
 * inputs: a matriz
 * output: o numero de colunas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat nao eh modificada
 */
int recuperaNColunas (Matriz* mat){
    return mat->cols;
}

/*Retorna o numero de linhas da matriz mat
 * inputs: a matriz
 * output: o numero de linhas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat nao eh modificada
 */
int recuperaNLinhas (Matriz* mat){
    return mat->rows;
}

/*Retorna a matriz transposta de mat
 * inputs: a matriz
 * output: a matriz transposta
 * pre-condicao: matriz mat existe
 * pos-condicao: mat nao eh modificada e matriz transposta existe
 */
Matriz* transposta (Matriz* mat){
    if(mat == NULL){
        printf("matriz nao existe");
        exit(1);
    }

    int cols = recuperaNLinhas(mat);
    int rows = recuperaNColunas(mat); 
    int r, c;

    Matriz* trp = inicializaMatriz(rows, cols);

    for(r = 0; r < rows; r++){
        for(c = 0; c < cols; c++){
            trp->matrix[r][c] = mat->matrix[c][r];
        }
    }

    return trp;
}

/*Retorna a matriz multiplicacao entre mat1 e mat2
 * inputs: as matrizes mat1 e mat2
 * output: a matriz multiplicacao
 * pre-condicao: matrizes mat1 e mat2 existem, e o numero de colunas de mat1 correponde ao numero de linhas de mat2
 * pos-condicao: mat1 e mat2 nao sao modificadas e a matriz multiplicacao existe
 */
Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
    int r, c, k;
    int cols1 = recuperaNColunas(mat1);
    int rows1 = recuperaNLinhas(mat1); 
    int cols2 = recuperaNColunas(mat2);
    int rows2 = recuperaNLinhas(mat2); 

    if(cols1 != rows2){
        printf("nao eh possivel multiplicar as matrizes");
        return NULL;
    }

    Matriz* mult = inicializaMatriz(rows1, cols2);

    for(r = 0; r < rows1; r++){
        for(c = 0; c < cols2; c++){
            mult->matrix[r][c] = 0;
            for(k = 0; k < cols1; k++){
                mult->matrix[r][c] += mat1->matrix[r][k] * mat2->matrix[k][c];
            }
        }
    }
    
    return mult;
}

/*Imprime a matriz completa
 * inputs: matriz mat
 * output: nenhum
 * pre-condicao: matriz mat existe
 * pos-condicao: nenhuma
 */
void imprimeMatriz(Matriz* mat){
    int r, c, rows = recuperaNLinhas(mat);
    for(r = 0; r < rows; r++){
        imprimeLinha(mat, r);
        printf("\n");
    }
    printf("\n");
}

/*Imprime apenas uma linha da matriz
 * inputs: matriz mat e o indice da linha
 * output: nenhum
 * pre-condicao: matriz mat existe e indice eh valido na matriz
 * pos-condicao: nenhuma
 */
void imprimeLinha (Matriz* mat, int indice){
    int c, cols = recuperaNColunas(mat);
    for(c = 0; c < cols; c++){
        printf(" %d", mat->matrix[indice][c]);
    }
}

/*Libera toda a memoria alocada para a matriz
 * inputs: matriz mat
 * output: nenhum
 * pre-condicao: matriz mat existe
 * pos-condicao: memoria ocupada por linhas e colunas liberada!
 */
void destroiMatriz (Matriz* mat){
    int cols = recuperaNColunas(mat);
    int rows = recuperaNLinhas(mat); 
    int r;
    if(mat != NULL){
        if(mat->matrix != NULL){
            for(r = 0; r < rows; r++){
                if(mat->matrix[r] != NULL) free(mat->matrix[r]);
            }
            free(mat->matrix);
        }
        free(mat);
    }
}

