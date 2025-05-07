#include <stdio.h>
#include <stdlib.h>
#include "supermercado.h"

typedef struct Supermercado tSupermercado;

char* leLinha(){
    char temp[100];
    scanf(" %99[^\n]", temp);
    char* str = strdup(temp);
    return str;
}

tSupermercado* criaMercado(){
    tSupermercado *mercado = malloc(sizeof(struct Supermercado*));
    mercado->valorTotalEstoque = 0;

    printf("Insira o nome do mercado:\n");
    mercado->nome = leLinha();

    return mercado;
}

tSupermercado* criaFiliaisMercado(tSupermercado* mercado){
    int i;
    printf("Insira a qtd de filiais:\n");
    scanf("%d", &mercado->qtdfiliais);

    mercado->filiais = malloc(sizeof(struct Filial**) * qtdFiliais);

    for(i = 0; i < qtdFiliais; i++){
        mercado->filiais[i] = criaFilial();
    }

    return mercado;
}

void imprimeMercado(tSupermercado* mercado){
    int i;
    printf("%s, Estoque Total: %d", mercado->nome, mercado->valorTotalEstoque);
    for(i = 0; i < mercado->qtdfiliais; i++){
        imprimeFiliais(mercado->filiais[i]);
    }
}

void liberaMercado(tSupermercado* mercado){
    if(mercado != NULL){
        if(mercado->filiais != NULL){
            int i;
            for(i = 0; i < mercado->qtdfiliais; i++){
                liberaFiliais(mercado->filiais[i]);
            }
        }
        free(mercado->nome);
        free(mercado);
    }
}