#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Supermercado tSupermercado;
typedef struct Produto tProduto;
typedef struct Item tItem;
typedef struct Estoque tEstoque;
typedef struct Filial tFilial;

char* leLinha();

struct Supermercado{
    char *nome;
    tFilial** filiais;
    int valorTotalEstoque;
    int qtdfiliais;
};

tSupermercado* criaMercado();
tSupermercado* criaFiliaisMercado(tSupermercado* mercado);
void imprimeMercado(tSupermercado* mercado);
void liberaMercado(tSupermercado* mercado);
tItem* procuraProduto(tSupermercado* mercado, int operacao);

struct Produto{
    char* nome;
    int valor;
};

char* lerLinha();
tProduto* criaProduto();
void imprimeProduto(tProduto* prod);
void liberaProduto(tProduto* prod);

struct Item{
    int qtd;
    tProduto* produto;
};

tItem* criaItem();
void imprimeItem(tItem* item);
void liberaItem(tItem* item);
int comparaProdutos(tItem* item, char* nomeProduto);

struct Estoque{
    int valor;
    tItem** itens;
    int qtdItens;
};

tEstoque* criaEstoque();
void imprimeEstoque(tEstoque* estoque);
void liberaEstoque(tEstoque* estoque);
int corfirmaTemProdutoEstoque(tEstoque* estoque, char* nomeProduto);
tItem* retornaItem(tEstoque* estoque, char* nomeProduto);


struct Filial{
    char *nome;
    tEstoque* estoque;
};

tFilial* criaFilial();
void imprimeFilial(tFilial* filial);
void liberaFilial(tFilial* filial);
tItem* procuraProdutoFiliais(tFilial* filial, char* nomeProduto);

int main(){
    tSupermercado *mercado = criaMercado();
    mercado = criaFiliaisMercado(mercado);
    imprimeMercado(mercado);
    liberaMercado(mercado);

    int operacao;

    printf("1-Procurar produto, qualquer filial\n2-Procurar produto, filial especifica\n");
    scanf("%d", &operacao);
    tItem* item = procuraProduto(mercado, operacao);
    if(item != NULL) imprimeItem(item);
    return 0;
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

    mercado->filiais = malloc(sizeof(struct Filial**) * mercado->qtdfiliais);

    for(i = 0; i < mercado->qtdfiliais; i++){
        mercado->filiais[i] = criaFilial();
    }

    return mercado;
}

void imprimeMercado(tSupermercado* mercado){
    int i;
    printf("%s, Estoque Total: %d", mercado->nome, mercado->valorTotalEstoque);
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
        }
        free(mercado->nome);
        free(mercado);
    }
}

tItem* procuraProduto(tSupermercado* mercado, int operacao){
    if(operacao == 1){
        int i;
        printf("Insira o nome do produto:\n");
        char* nomeProduto = leLinha();

        for(i = 0; i < mercado->qtdfiliais; i++){
            tItem* item = procuraProdutoFiliais(mercado->filiais[i], nomeProduto);
            if(item != NULL){
                free(nomeProduto);
                return item;
            }
        }
        free(nomeProduto);
        return NULL;
    }
}

char* leLinha(){
    char temp[100];
    scanf(" %99[^\n]", temp);
    char* str = strdup(temp);
    return str;
}

tProduto* criaProduto(){
    tProduto *produto = malloc(sizeof(struct Produto*));

    printf("Insira o nome do produto:\n");
    produto->nome = leLinha();

    printf("Insira o valor do produto:\n");
    scanf("%d", &produto->valor);

    return produto;
}

void imprimeProduto(tProduto* prod){
    printf("%s, valor unitario: %d", prod->nome, prod->valor);
}

void liberaProduto(tProduto* prod){
    if(prod != NULL) free(prod);
}

tItem* criaItem(){
    tItem *item = malloc(sizeof(struct Item*));

    item->produto = criaProduto();
    printf("Insira a qtd de itens:\n");
    scanf("%d", &item->qtd);
    
    return item;
}

void imprimeItem(tItem* item){
    printf("Item:");
    imprimeProduto(item->produto);
    printf("quantidade: %d\n", item->qtd);

}

void liberaItem(tItem* item){
    if(item != NULL){
        if(item->produto != NULL) liberaProduto(item->produto);
        free(item);
    }
}

int comparaProdutos(tItem* item, char* nomeProduto){
    if(strcmp(item->produto->nome, nomeProduto) == 0){
        return 1;
    }
    return 0;
}

tFilial* criaFilial(){
    tFilial *f = malloc(sizeof(struct Filial*));

    printf("Insira o nome da filial:\n");
    f->nome = leLinha();

    f->estoque = criaEstoque();

    return f;
}

void imprimeFilial(tFilial* filial){
    printf("Filial: %s\n", filial->nome);
    imprimeEstoque(filial->estoque);
}

void liberaFilial(tFilial* filial){
    if(filial != NULL){
        if(filial->estoque != NULL) liberaEstoque(filial->estoque);
        free(filial->nome);
        free(filial);
    }
}

tItem* procuraProdutoFiliais(tFilial* filial, char* nomeProduto){
    int temPrduto = corfirmaTemProdutoEstoque(filial->estoque, nomeProduto);
    if(temPrduto){
        printf("Produto encontrado na filial %s\n", filial->nome);
        tItem *item = retornaItem(filial->estoque, nomeProduto);
        return item;
    }
    return NULL;
}

tEstoque* criaEstoque(){
    tEstoque *estoque = malloc(sizeof(struct Estoque*));

    printf("Insira o valor do estoque:\n");
    scanf("%d", &estoque->valor);

    int i; 
    printf("Insira a qtd de itens no estoque\n");
    scanf("%d", &estoque->qtdItens);
    printf("\n(qtd itens %d)\n", estoque->qtdItens);
    estoque->itens = malloc(sizeof(struct Item**) * estoque->qtdItens);

    for(i = 0; i < estoque->qtdItens; i++){
        estoque->itens[i] = criaItem();
    }
    
    return estoque;
}

void imprimeEstoque(tEstoque* estoque){
    int i;
    printf("Estoque: %d", estoque->valor);
    for(i = 0; i < estoque->qtdItens; i++){
        imprimeItem(estoque->itens[i]);
    }
}

void liberaEstoque(tEstoque* estoque){
    if(estoque!= NULL){
        if(estoque->itens != NULL){
            int i;
            for(i = 0; i < estoque->qtdItens; i++){
                liberaItem(estoque->itens[i]);
            }
        }
        free(estoque);
    }
}

int corfirmaTemProdutoEstoque(tEstoque* estoque, char* nomeProduto){
    int i;
    printf("\n(qtd itens %d)\n", estoque->qtdItens);
    for(i = 0; i < estoque->qtdItens; i++){
        if(comparaProdutos(estoque->itens[i], nomeProduto)){
            printf("Produto encontrado no estoque:\n");
            //imprimeItem(estoque->itens[i]);
            return 1;
        }
    }
    return 0;
}

tItem* retornaItem(tEstoque* estoque, char* nomeProduto){
    int i;
    for(i = 0; i < estoque->qtdItens; i++){
        if(comparaProdutos(estoque->itens[i], nomeProduto)){
            return estoque->itens[i];
        }
    }
}
