#include "arvore.h"

struct arvore{
    Aluno* aluno;
    Arv* esq;
    Arv* dir;
};

//Cria uma árvore vazia
Arv* arv_criavazia (void){
    return NULL;
}

//cria uma árvore com a informação do nó raiz c, e com subárvore esquerda e e subárvore direita d
Arv* arv_cria (Aluno* c, Arv* e, Arv* d){
    Arv* a = malloc(sizeof(struct arvore));
    a->aluno = c;
    a->esq = e;
    a->dir = d;
    return a;
}

//libera o espaço de memória ocupado pela árvore a
Arv* arv_libera (Arv* a){
    if(arv_vazia(a)) return NULL;
    else{
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);
    }
    return NULL;
}

//retorna true se a árvore estiver vazia e false caso contrário
int arv_vazia (Arv* a){
    return (a ==  NULL);
}

//indica a ocorrência (1) ou não (0) do aluno (pela chave de busca mat)
int arv_pertence (Arv* a, int mat){
    if(arv_vazia(a)) return 0;
    else{
        if(retornaMatriculaAluno(a->aluno) == mat) return 1;
        else{
            int pertence = arv_pertence(a->esq, mat);
            if(pertence) return 1;
            else{
                return arv_pertence(a->dir, mat);
            }
        }
    }
}

//imprime as informações dos nós da árvore
void arv_imprime (Arv* a){
    if(arv_vazia(a)){
        printf("< >");
    }
    else{
        printf("<");
        imprimeAlunoNome(a->aluno);
        arv_imprime(a->dir);
        arv_imprime(a->esq);
        printf(" >");
    }
}

//retorna a mãe/pai de um dado no que contém o aluno com a matrícula mat
Arv* arv_pai (Arv* a, int mat){
    Arv* pai;
    if(arv_vazia(a)){
        return NULL;
    }
    else{
        if((!arv_vazia(a->dir) && retornaMatriculaAluno(a->dir->aluno) == mat) || (!arv_vazia(a->esq) && retornaMatriculaAluno(a->esq->aluno) == mat)){
            return a;
        }
        else{
            pai = arv_pai(a->esq, mat);
            if(pai != NULL){
                return pai;
            }
            else return arv_pai(a->dir, mat);
        }
    }
}

//retorna a quantidade de folhas de uma arvore binaria
int folhas(Arv* a) {
    if (arv_vazia(a)) return 0;
    else if (a->esq == NULL && a->dir == NULL) return 1;
    else return folhas(a->esq) + folhas(a->dir);
}

//retorna o numero de ocorrencias de um dado aluno na árvore
int ocorrencias (Arv* a, int mat){
    if(arv_vazia(a)) return 0;
    else{
        if(retornaMatriculaAluno(a->aluno) == mat){
            return 1 + ocorrencias(a->esq, mat) + ocorrencias(a->dir, mat);
        }
        else return ocorrencias(a->esq, mat) + ocorrencias(a->dir, mat);
    }
}

static int max2 (int a, int b){
    return (a > b) ? a : b;
}

//retorna a altura da árvore a
int altura(Arv* a){
    if (arv_vazia(a)) return -1;
    else{
        return 1 + max2 (altura (a->esq), altura (a->dir));
    }
}
