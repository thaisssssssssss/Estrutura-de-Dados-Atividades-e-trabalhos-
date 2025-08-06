#include "palavra.h"
#include "hash.h"

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

    imprimeHash(tabela);
    liberaHash(tabela);
}