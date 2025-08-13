#include "hash.h"
#include "aluno.h"
#include <ctype.h>

#define NPAL 100

//exemplo de função que lê uma palavra
int le_palavra( FILE *fp, char *s ){
    int i = 0;
    int c;
    while ((c = fgetc( fp )) != EOF){
        if (isalpha(c))
        break;
    }
    if (c == EOF)
        return 0;
    else
        s[i++] = c;
        while (i<NPAL-1 && (c = fgetc(fp))!= EOF && isalpha(c))
            s[i++] = c;
        
            s[i] = '\0';
    
        return 1;
}


int main(){
    FILE* fp;
    fp = fopen ("entrada.txt", "rt");
    if (fp == NULL){
        printf ("Erro na abertura do arquivo!\n");
        exit(1);
    }

    Hash* tabela = criaHash();
    Aluno* a;

    int qtdArquivos;
    fscanf(fp, "%*c %d", &qtdArquivos);

    char palavra[NPAL];
    while(le_palavra(fp, palavra)){
        //printf("%s ", palavra);
        a = criaAluno(palavra, 0, 0);
        insereHash(tabela, a);
    }

    int i;
    char caminho[64];
    for(i = 0; i < qtdArquivos; i++){
        snprintf(caminho, sizeof(caminho), "entrada%d.txt", i + 1);

        printf("%s\n", caminho);
        FILE* entradas = fopen(caminho, "rt");

        while(le_palavra(entradas, palavra)){
            char frequencia;
            fscanf(entradas, "%c", &frequencia);

            if(frequencia == 'P') a = criaAluno(palavra, 0, 1);
            else if(frequencia == 'F') a = criaAluno(palavra, 1, 0);

            insereHash(tabela, a);
        }

        fclose(entradas);
    }

    fclose(fp);

    int qtdAlunos = quantidadeItensHash(tabela);
    printf("%d qtd\n", qtdAlunos);
    Aluno** vetor = retornaVetor(tabela);
    ordenaVetor(vetor, qtdAlunos);
    
    
    FILE* saida = fopen("saida.txt", "w");
    
    imprimeHash(tabela, saida);
    liberaHash(tabela);
    fprintf(saida, "\n");
    imprimeVetor(vetor, qtdAlunos, saida);
    free(vetor);

    fclose(saida);
    return 0;
}