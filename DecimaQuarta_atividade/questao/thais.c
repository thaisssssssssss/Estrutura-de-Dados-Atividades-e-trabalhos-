#include "palavra.h"
#include "hash.h"

int main(int argc, char *argv[]){

    if(argc <= 1){
        printf("Erro, caminho dos arquivos nao informado!\n");
        exit(1);
    }

    char* caminho;
    caminho = strdup(argv[1]);

    
    FILE* entrada = fopen(caminho, "r");
    Hash* tabela = criaHash();

    char palavra[100];
    while(fscanf(entrada, "%s", palavra) == 1){
        Palavra* p = criaPalavra(palavra);
        insereHash(tabela, p, funcaoPalavra, trataColisao);
    }
    
    fclose(entrada);

    free(caminho);
    int qtdPalavras = quantidadeItensTabela(tabela, quantidadePalavras);
    int qtdPalavrasTotal = quantidadeItensTabela(tabela, quantidadePalavrasTotais);

    Palavra** vetorPalavra = retornaItem(tabela, retornaVetorPalavras);
    ordenaVetorPalavras(vetorPalavra, qtdPalavras);
    imprimeVetorPalavras(vetorPalavra, qtdPalavras);
        
    printf("------------------------\n");
    printf("%d palavras distintas encontradas\n", qtdPalavras);
    printf("%d palavras no total\n", qtdPalavrasTotal);

    Palavra* maisFrequente = retornaItem(tabela, retornaPalavraMaisFrequente);
    printf("%s é a palavra de maior frequência (%d)\n", retornaPalavra(maisFrequente), retornaFrequencia(maisFrequente));
    
    free(vetorPalavra);
    liberaHash(tabela, liberaPalavra);

    return 0;
}