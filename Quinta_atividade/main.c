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
    // liberaLista(lista);
    //tProduto* p = retiraProdutoLista(lista, 1234);
    //imprimeProduto(p);
    //imprimeLista(lista);


        int qtdProd, i;
        printf("Insira a qtd de produtos:\n");
        scanf("%d", &qtdProd);

        ListaDpl* lista = criaLista();
    
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
            lista = insereElementoListaInicio(lista, prod1);

        }
        
        int qtdRetiradas;
        printf("Insira a qtd de produtos que deseja retirar:\n");
        scanf("%d", &qtdRetiradas);
        
        for(i = 0; i < qtdRetiradas; i++){
            int codigo;
            printf("Insira o codigo do produto que deseja retirar:\n");
            scanf("%d", &codigo);
            lista = retiraElementoLista(lista, codigo);
        }
        
        //retiraElementoLista(lista, 1111);
        // imprimeElementoPorCodigo(lista, 1111);
        imprimeLista(lista);
        liberaLista(lista);
    }