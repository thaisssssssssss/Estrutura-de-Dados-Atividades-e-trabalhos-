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
    char* nome;
    int valor, codigo;
    
    printf("Insira o nome do produto:\n");
    nome = lerLinha();
    
    printf("Insira o valor do produto:\n");
    scanf("%d", &valor);
    
    printf("Insira o codigo do produto:\n");
    scanf("%d", &codigo);

    tProduto* prod1 = criaProduto(nome, valor, codigo);


    Lista* lista = criaLista();
    insereProdutoLista(lista, prod1);
    //tProduto* p = retiraProdutoLista(lista, 1234);
    liberaLista(lista);
    //imprimeProduto(p);
    //imprimeLista(lista);
}