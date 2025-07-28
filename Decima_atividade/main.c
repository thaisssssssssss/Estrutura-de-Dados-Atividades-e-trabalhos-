#include "arvore.h"

int main(){
    Arvore* a = criaArvoreVazia();

    a = inserePalavraArvore(a, "dado");
    a = inserePalavraArvore(a, "espaguete");
    a = inserePalavraArvore(a, "bola");
    a = inserePalavraArvore(a, "vassoura");
    a = inserePalavraArvore(a, "amor");
    a = inserePalavraArvore(a, "amavel");
    a = inserePalavraArvore(a, "tesouro");
    a = inserePalavraArvore(a, "dado");
    a = inserePalavraArvore(a, "espaguete");
    a = inserePalavraArvore(a, "bola");
    a = inserePalavraArvore(a, "vassoura");
    a = inserePalavraArvore(a, "amor");
    a = inserePalavraArvore(a, "tesouro");
    a = inserePalavraArvore(a, "thais");
    a = inserePalavraArvore(a, "amavel");
    a = inserePalavraArvore(a, "amavel");
    a = inserePalavraArvore(a, "lindo");
    a = inserePalavraArvore(a, "abacaxi");
    a = inserePalavraArvore(a, "dado");
    a = inserePalavraArvore(a, "espaguete");
    a = inserePalavraArvore(a, "bola");
    a = inserePalavraArvore(a, "vassoura");
    a = inserePalavraArvore(a, "amor");
    a = inserePalavraArvore(a, "amavel");
    a = inserePalavraArvore(a, "tesouro");
    a = inserePalavraArvore(a, "thais");
    a = inserePalavraArvore(a, "queijo");
    a = inserePalavraArvore(a, "lampada");
    a = inserePalavraArvore(a, "lindo");
    a = inserePalavraArvore(a, "dinheiro");
    a = inserePalavraArvore(a, "dinheiro");
    a = inserePalavraArvore(a, "dinheiro");
    a = inserePalavraArvore(a, "dinheiro");
    a = inserePalavraArvore(a, "dinheiro");
    a = inserePalavraArvore(a, "dinheiro");

    //imprimeArvore(a);

    //Qtd de palavras totais
    printf("\nQuantidade total de palavras: %d\n", qtdTotaldePalavras(a));

    // //LiberaArvore
    // liberaArvore(a);

    //Ocorrencias de determinada palavra
    char palavra[] = "cachorro";
    int ocorrencia = ocorrenciasPalavraArvore(a, palavra);
    printf("\nQuantidade de ocorrencias da palavra %s: %d\n", palavra, ocorrenciasPalavraArvore(a, palavra));

    //Existencia de determinada palavra
    int existe = existePalavraArvore(a, palavra);
    if(existe) printf("\nExiste a palavra %s na arvore\n", palavra);
    else printf("\nNao existe a palavra %s na arvore\n", palavra);


    // //LiberaArvore
    // liberaArvore(a);

    //Ocorrencia de palavras distintas
    Arvore** visitada = malloc(sizeof(struct arvore*));
    *visitada = criaArvoreVazia();
    int* tamanho = malloc(sizeof(int));
    *tamanho = qtdTotaldePalavras(a);
    ocorrenciaPalavrasDistintasArvore(a, visitada, tamanho);
    printf("\nQuantidade de ocorrencias de palavras distintas: %d\n", *tamanho);

    // //LiberaArvore
    // liberaArvore(a);
    liberaArvore(*visitada);
    free(visitada);
    free(tamanho);


    //Palavra mais frequente
    Arvore** visitada2 = malloc(sizeof(struct arvore*));
    *visitada2 = criaArvoreVazia();
    int* frequencia = malloc(sizeof(int));
    *frequencia = 0;
    char** palavra2 = malloc(sizeof(char*));
    palavraMaisFrequenteArvore(a, visitada2, frequencia, palavra2);
    printf("\nA palavra mais frequente eh: %s, com %d ocorrencias\n", *palavra2, *frequencia);

     //LiberaArvore
    //liberaArvore(a);
    liberaArvore(*visitada2);
    free(visitada2);
    free(frequencia);
    free(palavra2);



    //Cria Vetor de palavras
    
    int* posicao = malloc(sizeof(int));
    *posicao = 0;

    Arvore** visitada4 = malloc(sizeof(struct arvore*));
    *visitada4 = criaArvoreVazia();
    tamanho = malloc(sizeof(int));
    *tamanho = qtdTotaldePalavras(a);
    ocorrenciaPalavrasDistintasArvore(a, visitada4, tamanho);
    printf("\nQuantidade de ocorrencias de palavras distintas: %d\n", *tamanho);


    Arvore** visitada3 = malloc(sizeof(struct arvore*));
    *visitada3 = criaArvoreVazia();
    Palavra** vetor = criaVetorPalavras(*tamanho);
    preencheVetorPalavras(a, visitada3, vetor, *tamanho, posicao);
    //imprimeVetorPalavras(vetor, *posicao);

    vetor = ordenaVetorPalavras(vetor, *tamanho);
    imprimeVetorPalavras(vetor, *posicao);


    liberaVetorPalavras(vetor, *tamanho);

    liberaArvore(*visitada4);
    free(visitada4);
    liberaArvore(*visitada3);
    free(visitada3);
    free(tamanho);
    free(posicao);
    

    liberaArvore(a);

}