#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supermercado.h"
#include "item.h"

typedef struct Supermercado tSupermercado;

tSupermercado* criaMercado(){
    tSupermercado *mercado = malloc(sizeof(struct Supermercado));
    mercado->valorTotalEstoque = 0;

    printf("Insira o nome do mercado:\n");
    mercado->nome = leLinha();

    return mercado;
}

tSupermercado* criaFiliaisMercado(tSupermercado* mercado){
    int i;
    printf("Insira a qtd de filiais:\n");
    scanf("%d", &mercado->qtdfiliais);

    mercado->filiais = malloc(sizeof(struct Filial*) * mercado->qtdfiliais);

    for(i = 0; i < mercado->qtdfiliais; i++){
        mercado->filiais[i] = criaFilial();
        mercado->valorTotalEstoque += retornaValorEstoqueFilial(mercado->filiais[i]);
    }

    return mercado;
}

void imprimeMercado(tSupermercado* mercado){
    int i;
    printf("\n%s, Estoque Total: %d\n", mercado->nome, mercado->valorTotalEstoque);
    for(i = 0; i < mercado->qtdfiliais; i++){
        imprimeFilial(mercado->filiais[i]);
    }
}

void liberaMercado(tSupermercado* mercado){
    if(mercado != NULL){
        if(mercado->filiais != NULL){
            int i;
            for(i = 0; i < mercado->qtdfiliais; i++){
                liberaFilial(mercado->filiais[i]);
            }
            free(mercado->filiais);
        }
        free(mercado->nome);
        free(mercado);
    }
}

// tItem* procuraProduto(tSupermercado* mercado, int operacao){
//     if(operacao == 1){
//         int i;
//         printf("Insira o nome do produto:\n");
//         char* nomeProduto = leLinha();

//         for(i = 0; i < mercado->qtdfiliais; i++){
//             tItem* item = procuraProdutoFiliais(mercado->filiais[i], nomeProduto);
//             if(item != NULL){
//                 free(nomeProduto);
//                 return item;
//             }
//         }
//         free(nomeProduto);
//         return NULL;
//     }
// }