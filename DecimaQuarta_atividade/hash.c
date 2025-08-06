#include "hash.h"

struct hash{
    int n;
    int dim;
    Palavra** vetor;   
};

Hash* criaHash(){
    Hash* tabela = malloc(sizeof(struct hash));
    tabela->n = 0;
    tabela->dim = 7;

    tabela->vetor = malloc(sizeof(struct palavra*) * tabela->dim);

    int i;
    for(i = 0; i < tabela->dim; i++){
        tabela->vetor[i] = NULL;
    }

    return tabela;
}


static int hash(Hash* tabela, char* palavra){
    int i, somador = 0;
    for(i = 0; palavra[i]; i++){
        somador += palavra[i];
    }

    return (somador % tabela->dim);
}


void insereHash(Hash* tabela, Palavra* palavra){
    if(tabela->n > 0.75 * tabela->dim) redimensionaHash(tabela);

    int h = hash(tabela, retornaCharPalavra(palavra));
    printf("valor de h = %d\n", h);
    //TRATAMENTO DE COLISAO ADICIONANDO AO LADO
    // while(tabela->vetor[h] != NULL){
    //     //soma mais 1 (modularizado)
    //     h = (h + 1) % tabela->dim;
    // }

    if(tabela->vetor[h] == NULL){
        //printf("ta Null\n");
        tabela->vetor[h] = palavra;
        tabela->n++;
    }
    else{
        tabela->vetor[h] = adicionaPalavraLista(tabela->vetor[h], palavra);
    }
}


static void redimensionaHash(Hash* tabela){
    //guarda as informacoes da tabela a ser modificada
    int dimensaoAnt = tabela->dim;
    Palavra** vetorAnt = tabela->vetor;

    //coloca as novas dimensoes
    tabela->n = 0;
    tabela->dim = dimensaoAnt * 1.947; //evita multiplos

    //aloca mais espaco para o vetor
    tabela->vetor = malloc(sizeof(struct palavra*) * tabela->dim);


    int i;
    for(i = 0; i < tabela->dim; i++){
        //coloca NULL em todas as posicoes da tabela
        tabela->vetor[i] = NULL;

        //coloca os itens que estavam na tabela antiga na nova tabela
        if(vetorAnt[i] != NULL) insereHash(tabela, vetorAnt[i]);
    }
    
    //libera o vetor usado como auxiliar
    free(vetorAnt);
}

void imprimeHash(Hash* tabela){
    int i;
    for(i = 0; i < tabela->dim; i++){
        if(tabela->vetor[i] != NULL) imprimePalavra(tabela->vetor[i]);
    }
}

void liberaHash(Hash* tabela){
    int i;
    for(i = 0; i < tabela->dim; i++){
        liberaPalavra(tabela->vetor[i]);
    }
    free(tabela->vetor);
    free(tabela);
}