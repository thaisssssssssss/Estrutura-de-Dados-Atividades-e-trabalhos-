#include "palavra.h"
#include "vetor.h"

struct vetor{
    Palavra** vetor;
    int inicio; 
    int tamanho;
};

Vetor* criaVetor(int tamanho){
    Vetor* vetor = malloc(sizeof(struct vetor));
    vetor->vetor = malloc(sizeof(struct palavra*) * tamanho);
    vetor->tamanho = tamanho;
    vetor->inicio = 0;
    return vetor;
}

void colocaPalavraVetor(Vetor* vetor, Palavra* palavra){
    if(vetor->tamanho > vetor->inicio){
        vetor->vetor[vetor->inicio] = palavra;
        vetor->inicio++;
    }
}