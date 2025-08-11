#include "palavra.h"
#include "hash.h"
#include "vetor.h"

int main(){

    Palavra* a = criaPalavra("thais");
    Palavra* b = criaPalavra("thais");
    Palavra* c = criaPalavra("ca");
    Palavra* d = criaPalavra("cb");
    Palavra* e = criaPalavra("marina");
    Palavra* f = criaPalavra("katia");
    Palavra* g = criaPalavra("sarah");

    Hash* tabela = criaHash();
    insereHash(tabela, a);
    insereHash(tabela, b);
    insereHash(tabela, c);
    insereHash(tabela, d);
    insereHash(tabela, e);
    insereHash(tabela, f);
    insereHash(tabela, g);

    Palavra* maisFrequente = retornaPalavraMaisFrequente(tabela);
    printf("Palavra mais frequente: \n");
    imprimePalavra(maisFrequente);

    Vetor* vetor = criaVetorPalavras(tabela);
    preencheVetor(vetor, tabela);


    imprimeHash(tabela);
    liberaHash(tabela);


}