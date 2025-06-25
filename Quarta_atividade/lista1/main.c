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
    printf("Digite a quantidade de produto:");
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

    // int codigo;
    // printf("Digite o codigo do produto:\n");
    // scanf("%d", &codigo);

    // //funcao extra
    // if(confereTemProdutoLista(lista, codigo)){
    //     tProduto* p = retiraProdutoLista(lista, codigo);
    //     imprimeProduto(p);
    //     liberaProduto(p);
    // }
    // else printf("Produto nao esta na lista\n");

    printf("Digite a quantidade de produtos que deseja procurar:\n");
    scanf("%d", &qtdProd);

    for(i = 0; i < qtdProd; i++){
        int codigo;
        printf("Digite o codigo do produto:\n");
        scanf("%d", &codigo);

        tProduto* p = retiraProdutoLista(lista, codigo);

        if(p != NULL){
            imprimeProduto(p);
            liberaProduto(p);
        }
        else printf("codigo invalido\n");
    }

    //imprimeLista(lista);
    liberaLista(lista);
}