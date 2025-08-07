#include "aluno.h"
#include "arvore.h"

int main(){
    Arvore* raiz = criaArvoreVazia();

    FILE* saida = fopen("saida.txt", "w");
    
    FILE* entrada = fopen("entrada.txt", "r");

    int qtdArquivos;
    fscanf(entrada, "%*c %d", &qtdArquivos);
    //fprintf(saida, "Qtd arquivos: %d\n", qtdArquivos);

    char nome[100];
    char frequencia;
    while(fscanf(entrada, "%s", nome) == 1){
        Aluno* aluno = criaAluno(nome);
        raiz = insereOrdenadoArvore(raiz, aluno, comparaNomeAluno);
        //fprintf(saida, "%s\n", nome);
    }

    fclose(entrada);

    int i;
    for(i = 1; i <= qtdArquivos; i++){
        char* arquivo = strdup("entrada");
        char num[2];
        num[0] = i + '0';
        num[1] = '\0';
        strcat(arquivo, num);
        strcat(arquivo, ".txt\0");
        printf("%s\n", arquivo);

        FILE* aulas = fopen(arquivo, "r");

        char nome2[100];

        while(fscanf(aulas, "%s %c", nome, &frequencia) == 2){
            Aluno* aux = criaAluno(nome);
            if(frequencia == 'P') atualizaItemArvore(raiz, aux, comparaNomeAluno, incrementaPresencas);
            else atualizaItemArvore(raiz, aux, comparaNomeAluno, incrementaFaltas);
            liberaAluno(aux);
            //printf("%s %c\n", nome, frequencia);
        }

        fclose(aulas);


        free(arquivo);
    }

    imprimeArvore(raiz, imprimeAluno, saida);
    liberaArvore(raiz, liberaAluno);

    fclose(saida);

}