#include "palavra.h"
#include "hash.h"

int main(){
    Hash* tabela = criaHash();

    Palavra* thais = criaPalavra("thais");
    Palavra* katia = criaPalavra("katia");
    Palavra* manu = criaPalavra("manu");
    Palavra* coly = criaPalavra("coly");
    Palavra* pedro = criaPalavra("pedro");
    Palavra* nico = criaPalavra("nico");
    Palavra* laura = criaPalavra("laura");

    insereHash(tabela, thais, funcaoPalavra, trataColisao);
    insereHash(tabela, katia, funcaoPalavra, trataColisao);
    insereHash(tabela, manu, funcaoPalavra, trataColisao);
    insereHash(tabela, coly, funcaoPalavra, trataColisao);
    insereHash(tabela, thais, funcaoPalavra, trataColisao);
    insereHash(tabela, thais, funcaoPalavra, trataColisao);
    insereHash(tabela, thais, funcaoPalavra, trataColisao);
    insereHash(tabela, laura, funcaoPalavra, trataColisao);
    insereHash(tabela, nico, funcaoPalavra, trataColisao);
    insereHash(tabela, pedro, funcaoPalavra, trataColisao);

    
    imprimeHash(tabela, imprimePalavra);
    
    
    printf("Palavra mais frequente: \n");
    Palavra* maisFrequente = retornaItem(tabela, retornaPalavraMaisFrequente);
    imprimePalavraUnica(maisFrequente);
    
    int qtdPalavras = quantidadeItensTabela(tabela, quantidadePalavras);
    printf("A tabela tem %d palavras\n", qtdPalavras);

    Palavra** vetorPalavra = retornaItem(tabela, retornaVetorPalavras);
    printf("Vetor antes de ordenado\n");
    imprimeVetorPalavras(vetorPalavra, qtdPalavras);
    ordenaVetorPalavras(vetorPalavra, qtdPalavras);
    printf("Vetor pos ordenacao\n");
    imprimeVetorPalavras(vetorPalavra, qtdPalavras);

    liberVetorPalavras(vetorPalavra, qtdPalavras);
    free(vetorPalavra);

    liberaHash(tabela, liberaPalavra);
}