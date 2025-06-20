//
//  pedido.h
//  Prova1ED
//
//  Created by Patricia Dockhorn Costa on 02/10/19.
//  Copyright © 2019 Patricia Dockhorn Costa. All rights reserved.
//

/* TAD Pedido. Um Pedido consiste de uma lista de Produtos!!!! */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

/* Define o tipo TPedido (tipo opaco). Estrutura interna deste tipo eh definida na implementacao do TAD.
 * Trata-se da sentinela da lista e deve conter as seguintes informacoes:
 * Dono do pedido (char*) e os campos prim e ult da sentinela
 */
typedef struct pedido TPedido;

typedef struct celula Celula;

struct celula{
    TProduto* produto;
    Celula* prox;
};

struct pedido{
    char* nome;
    Celula* prim;
    Celula* ult;
};


/*----------------------------------------------------------------------
 * Inicializa o pedido de um cliente (ou seja, a sentinela!)
 * inputs: nome do dono do pedido
 * output: Pedido inicializado
 * pre-condicao: nome devidamente alocado
 * pos-condicao: Pedido inicializado contendo o nome como informado
 *---------------------------------------------------------------------- */
TPedido* InicPedido (char* dono){
    TPedido* pedido = malloc(sizeof(struct pedido));
    pedido->nome = strdup(dono);
    pedido->prim = NULL;
    pedido->ult = NULL;
    return pedido;
}

/*----------------------------------------------------------------------
 * Inclui um produto no pedido de um cliente (ou seja, a sentinela!). Inserir ao FINAL!
 * Lembrando que um produto nao pode ser inserido mais de uma vez no pedido! Neste caso, exiba a mensagem "Produto já existe no pedido\n"
 * inputs: o pedido e o produto a ser inserido
 * output: nada
 * pre-condicao: pedido e produto foram devidamente inicializados
 * pos-condicao: produto inserido no pedido OU lista inalterada (caso o produto ja esteja na lista)
 *----------------------------------------------------------------------*/
void IncluiProdutoPedido (TPedido* pedido, TProduto* prod){
    Celula* aux;
    int jaTem = 0;
    for(aux = pedido->prim; aux != NULL; aux = aux->prox){
        if(strcmp(RetornaNome(aux->produto), RetornaNome(prod)) == 0) jaTem = 1;
    }

    if(jaTem) printf("Produto já existe no pedido\n");
    else{
        Celula* nova = malloc(sizeof(struct celula));
        nova->produto = prod;
        nova->prox = NULL;

        if(pedido->prim == NULL && pedido->ult == NULL){
            pedido->prim = nova;
            pedido->ult = nova;
        }
        else{
            pedido->ult->prox = nova;
            pedido->ult = nova;
        }
    }
}

/*----------------------------------------------------------------------
 * Imprime todos os dados de um pedido (o dono seguido de todos os produtos e ingredientes)
 * Caso o pedido seja novo e nao tenha ainda produtos, exibir a mensagem "Nao ha produtos neste pedido!\n"
 * inputs: o pedido
 * output: nada
 * pre-condicao: pedido devidamente inicializado
 * pos-condicao: funcao nao alterad os dados do pedido
 *----------------------------------------------------------------------*/
void ImprimePedido (TPedido* pedido){
    printf("\n nome: %s\n", pedido->nome);
    Celula* aux;
    for(aux = pedido->prim; aux != NULL; aux = aux->prox){
        ImprimeIngredientes(aux->produto);
    }
}

/*----------------------------------------------------------------------
 * Retira a unica ocorrência do produto (caso ele exista na lista).
 * Importante!!! Esta funcao nao libera o produto! Apenas o retira do pedido!
 * inputs: o pedido e, o produto a ser retirado
 * output: nada
 * pre-condicao: pedido e produto devidamente inicializados
 * pos-condicao: pedido nao contem o produto
 *----------------------------------------------------------------------*/
void RetiraProdutoPedido (TPedido* pedido, char* prod){
    Celula* p = pedido->prim;
    Celula* ant;

    while(1){
        if(p == NULL || strcmp(RetornaNome(p->produto), prod) == 0) break;
        ant = p;
        p = p->prox;
    }

    //vazio
    if(p == NULL) return;

    //unico
    if(p == pedido->prim && p == pedido->ult){
        pedido->prim = NULL;
        pedido->ult = NULL;
        free(p);
        return;
    }

    //primeiro
    if(p == pedido->prim){
        pedido->prim = p->prox;
        free(p);
        return;
    }

    //ultimo
    if(p == pedido->ult){
        ant->prox = NULL;
        pedido->ult = ant;
        free(p);
        return;
    }

    ant->prox = p->prox;
    free(p);

}

//A função envia pedido verifica se há restrição calórica ou restrição alimentar
//Se estiver tudo ok, retira o pedido da lista (libera o pedido, porém não libera o produto) e retorna 1
//Se não estiver ok, a lista permanece a mesma e a função retorna zero

/*----------------------------------------------------------------------
 * Primeiramente, verifica se há restrição calórica ou restrição alimentar, de acordo com os parametros
 **** Para a restricao calorica, deve-se somar as calorias de todos o produtos do pedido! Caso o numero de calorias do pedido ultrapasse a restricao, exiba a mensagem : "Pedido não Enviado! Pedido tem mais calorias do que a restricao, tente retirar algum produto!"
 ****** Para a restricao alimentar, deve-se verificar se algum produto contem como ingrediente a restricao especificada. Caso algum produto contenha o ingrediente indicado, exiba a mensagem: nPedido não Enviado! Restricao alimentar no produto: %s\n
* Se estiver tudo certo (ou seja respeitando-se as restricoes), destroi o pedido da pessoa, porém não libera os produtos) e retorna 1
 * inputs: o pedido e as restricoes calorica e alimentar
 * output: 0 (problema em algumas das restricoes). 1 (pedido enviado)
 * pre-condicao: pedido devidamente inicializado e strings validas
 * pos-condicao: se houver problema com as restricoes, o pedido deve ficar inalterado. se estiver tudo ok com as restricoes, deve destruir o pedido, porem os produtos nao devem ser liberados (pois podem estar em outros pedidos, de outras pessoas).
 *----------------------------------------------------------------------*/
int EnviaPedido (TPedido* pedido, int restricao_calorica, char* restricao_alimentar){
    int somaCalorias = 0, restricao = 0;
    Celula* aux;
    for(aux = pedido->prim; aux != NULL; aux = aux->prox){
        somaCalorias += Calorias(aux->produto);
        restricao = VerificaIngrediente(aux->produto, restricao_alimentar);
        if(restricao) break;
    }

    if(restricao_calorica >= somaCalorias && !restricao){
        Celula* atual = pedido->prim;
        Celula* seguinte;

        while(atual != NULL){
            seguinte = atual->prox;
            free(atual);
            atual = seguinte;
        }
        free(pedido->nome);
        free(pedido);

        return 1;
    }
    else if(restricao){
        printf("\nPedido não Enviado! Restricao alimentar no produto: %s\n", restricao_alimentar);
        return 0;
    }
    else if(restricao_calorica < somaCalorias){
        printf("\nPedido não Enviado! Pedido tem mais calorias do que a restricao, tente retirar algum produto!\n");
        return 0;
    }
}


