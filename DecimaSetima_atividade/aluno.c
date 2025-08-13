#include "aluno.h"

struct aluno{
    char* nome;
    int p;
    int f;
    Aluno* prox;
};

Aluno* criaAluno(char* nome, int f, int p){
    Aluno* a = malloc(sizeof(struct aluno));
    a->nome = strdup(nome);
    a->f = f;
    a->p = p;
    a->prox = NULL;

    return a;
}

int funcao(Aluno* a){
    int i, somador = 0;
    for(i = 0; a->nome[i]; i++){
        somador += a->nome[i];
    }
    return somador;
}

void imprimeAluno(Aluno* a, FILE* saida){
    while(a){
        fprintf(saida, "%s %dP %dF\n", a->nome, a->p, a->f);
        a = a->prox;
    }
}

void imprimeAlunoUnico(Aluno* a, FILE* saida){
    fprintf(saida, "%s %dP %dF\n", a->nome, a->p, a->f);
}

void liberaAluno(Aluno* a){
    Aluno* seguinte;

    while(a){
        seguinte = a->prox;

        free(a->nome);
        free(a);
        a = seguinte;
    }
}

int comparaAlunos(Aluno* a1, Aluno* a2){
    return (strcmp(a1->nome, a2->nome));
}

void incrementaFrequencia(Aluno* a1, Aluno* a2){
    a1->f += a2->f;
    a1->p += a2->p;
}

Aluno* trataColisao(Aluno* lista, Aluno* novo){
    Aluno* aux = lista;
    while(aux){
        if(!comparaAlunos(aux, novo)){
            incrementaFrequencia(aux, novo);
            liberaAluno(novo);
            return lista;
        }

        if(aux->prox == NULL){
            aux->prox = novo;
            return lista;
        }
        aux = aux->prox;
    }
}

int quantidadeAlunos(Aluno* a){
    int qtd = 0;
    while(a){
        qtd++;
        a = a->prox;
    }
    return qtd;
}

int preencheVetor(Aluno** vetor, Aluno* lista, int posicao){
    while(lista){
        vetor[posicao] = lista;
        posicao++;
        lista = lista->prox;
    }
    return posicao;
}

void imprimeVetor(Aluno** vetor, int tamanho, FILE* saida){
    int i;
    for(i = 0; i < tamanho; i++){
        imprimeAlunoUnico(vetor[i], saida);
    }
}

int compara(const void* a, const void* b){
    Aluno* a1 = *(Aluno**)a;
    Aluno* a2 = *(Aluno**)b;

    return strcmp(a1->nome, a2->nome);
}

void ordenaVetor(Aluno** vetor, int tamanho){
    qsort(vetor, tamanho, sizeof(struct aluno*), compara);
}