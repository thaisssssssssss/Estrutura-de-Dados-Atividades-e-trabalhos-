// testador.c
//
// Criado por Thais Gomes Brandao no dia 27/07/2025
//

#include "arvore.h"
#include "palavra.h"

int main(){
    Arvore* arvore = criaArvoreVazia();


    FILE* fp = fopen("entrada.txt", "r");
    if(!fp){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }


    char palavra[100];
    while (fscanf(fp, "%s", palavra) == 1) {
        //printf("Palavra lida: %s\n", palavra);
        arvore = inserePalavraArvore(arvore, palavra);
    }

    fclose(fp);



    Arvore** visitada = malloc(sizeof(struct arvore*));
    *visitada = criaArvoreVazia();

    // calcula o total de palavras distintas
    int* tamanho = malloc(sizeof(int));
    *tamanho = qtdTotaldePalavras(arvore);
    ocorrenciaPalavrasDistintasArvore(arvore, visitada, tamanho);


    // libera a memoria da arvore visitada para reutiliza-la
    liberaArvore(*visitada);
    // "limpa" a arvore vazia
    *visitada = criaArvoreVazia();
    

    int* posicao = malloc(sizeof(int));
    *posicao = 0;

    // preenche e ordena o vetor com as palavras 
    Palavra** vetor = criaVetorPalavras(*tamanho);
    preencheVetorPalavras(arvore, visitada, vetor, *tamanho, posicao);
    vetor = ordenaVetorPalavras(vetor, *tamanho);




    // libera a memoria da arvore visitada para reutiliza-la
    liberaArvore(*visitada);
    // "limpa" a arvore vazia
    *visitada = criaArvoreVazia();

    // encontra a palavra mais frequente
    *visitada = criaArvoreVazia();
    int* frequencia = malloc(sizeof(int));
    *frequencia = 0;
    char** palavra2 = malloc(sizeof(char*));
    palavraMaisFrequenteArvore(arvore, visitada, frequencia, palavra2);




    // grava no arquivo de saida
    FILE* fc = fopen("saida.txt", "w");
    imprimeVetorPalavras(vetor, *posicao, fc);
    fprintf(fc, "------------------------\n");
    fprintf(fc, "%d palavras distintas encontradas\n", *posicao);
    *tamanho = qtdTotaldePalavras(arvore);
    fprintf(fc, "%d palavras no total\n", *tamanho);
    fprintf(fc, "%s é a palavra de maior frequência (%d)", *palavra2, *frequencia);
    fclose(fc);




    // libera toda a memoria alocada
    liberaVetorPalavras(vetor, *posicao);
    liberaArvore(*visitada);
    free(visitada);
    free(tamanho);
    free(posicao);
    free(frequencia);
    free(palavra2);
    liberaArvore(arvore);

    return 0;
}