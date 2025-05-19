//
//  cliente.c
//
//  Created by Thais Gomes on 14/05/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "rendimento.h"

int main(){
    Rendimento* rend = inicializaRendimento();
    imprimeRendimento(rend);
    destroiRendimento(rend);
    // int rows, cols, r, c, element;
    // printf("digite o numero de linhas e colunas da primeira matriz:");
    // scanf("%d %d", &rows, &cols);
    // Matriz* mat1 = inicializaMatriz(rows, cols);

    // //Adiciona conteudo na matriz original
    // for(r = 0; r < rows; r++){
    //     for(c = 0; c < cols; c++){
    //         scanf("%d", &element);
    //         modificaElemento(mat1, r, c, element);
    //     }
    // }

    // printf("digite o numero de linhas e colunas da segunda matriz:");
    // scanf("%d %d", &rows, &cols);
    // Matriz* mat2 = inicializaMatriz(rows, cols);

    // for(r = 0; r < rows; r++){
    //     for(c = 0; c < cols; c++){
    //         scanf("%d", &element);
    //         modificaElemento(mat2, r, c, element);
    //     }
    // }

    // imprimeMatriz(mat1);
    // imprimeMatriz(mat2);
    
    
    // //Retorna a matriz transposta da matriz dada
    // Matriz* trp1 = transposta(mat1);
    // imprimeMatriz(trp1);

    // Matriz* trp2 = transposta(mat2);
    // imprimeMatriz(trp2);

    // //Multiplica as matrizes
    // Matriz* mult = multiplicacao(mat1, mat2);
    // imprimeMatriz(mult);


    // destroiMatriz(mat1);
    // destroiMatriz(mat2);
    // destroiMatriz(trp1);
    // destroiMatriz(trp2);
    // destroiMatriz(mult);

    return 0;
}