#include "abbgen.h"

int main(){
    Arvore* raiz = criaArvoreVazia();

    FILE* entrada = fopen("entrada.txt", "r");

    char nome[100];
    int matricula;
    int cr;
    
    while(1){

        fscanf(entrada, "%*[^0-9]");
        int result = fscanf(entrada, "%d %s %d", &matricula, nome, &cr);

        if(result != 3) break;

        Aluno* a = criaAluno(nome, matricula, cr);
        //imprimeAluno(a);
        raiz = insereOrdenado(raiz, a, comparaPorNome);
    }

    fclose(entrada);

    FILE* saida = fopen("saida.txt", "w");

    imprimeArvore(raiz, imprimeAluno, saida);

    fclose(saida);

    return 0;
}