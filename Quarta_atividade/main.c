#include <stdio.h>
#include "produto.h"
#include "lista.h"
#include <stdlib.h>
#include <string.h>

char* lerLinha(){
    char temp[100];
    scanf(" %99[^\n]", temp);
    char* str = strdup(temp);
    return str;
}

int main(){
    int qtdProd, i;
    scanf("%d", &qtdProd);

    Lista* lista = criaLista();
    
    for(i = 0; i < qtdProd; i++){
        char* nome;
        int valor, codigo;
        
        printf("Insira o nome do produto:\n");
        nome = lerLinha();
        
        printf("Insira o valor do produto:\n");
        scanf("%d", &valor);
        
        printf("Insira o codigo do produto:\n");
        scanf("%d", &codigo);
    
        tProduto* prod1 = criaProduto(nome, valor, codigo);
        insereProdutoLista(lista, prod1);

    }


    liberaLista(lista);
    //tProduto* p = retiraProdutoLista(lista, 1234);
    //imprimeProduto(p);
    //imprimeLista(lista);
}