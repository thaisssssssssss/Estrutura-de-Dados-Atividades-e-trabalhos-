#include <stdio.h>
#include "produto.h"
#include "lista.h"
#include "testelista.h"
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
        adicionaElementoListaFim(lista, prod1);

    }

    printf("Digite a quantidade de produtos que deseja procurar:\n");
    scanf("%d", &qtdProd);

    for(i = 0; i < qtdProd; i++){
        int codigo;
        printf("Digite o codigo do produto:\n");
        scanf("%d", &codigo);

        tProduto* p = retiraElementoLista(lista, codigo);

        if(p != NULL){
            imprimeProduto(p);
            liberaProduto(p);
        }
    }

    imprimeLista(lista);
    liberaLista(lista);
}