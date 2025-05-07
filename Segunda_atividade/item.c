#include <stdio.h>
#include <stdlib.h>
#include "item.h"

char* leLinha(){
    char temp[100];
    scanf(" %99[^\n]", temp);
    char* str = strdup(temp);
    return str;
}

tItem* criaFilial(){
    tItem *item = malloc(sizeof(struct Item*));

    item->produto = criaProduto();
    printf("Insira a qtd de itens:\n");
    scanf("%d", &item->qtd);
    
    return item;
}

void imprimeItem(tItem* item){
    printf("Item:");
    imprimeProduto(item->produto);
    printf("quantidade: %d", item->qtd);

}

void liberaItem(tItem* item){
    if(item != NULL){
        if(item->produto != NULL) liberaProduto(item->produto);
        free(item);
    }
}