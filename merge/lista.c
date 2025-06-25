#include "lista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*TipoItem Aluno (tipo opaco)
 Estrutura interna do tipo deve ser definida na implementacao do TAD. Devem ser definidos campos:
 - nome (string)
 - matricula (int) */
//typedef struct aluno TAluno;

struct aluno{
    char* nome;
    int matricula;
};

/*Tipo que define a lista (tipo opaco)
 Estrutura interna do tipo deve ser definida na implementacao do TAD.
 Usar lista COM Sentinela */
typedef struct celula Celula;

struct celula{
    TAluno* aluno;
    Celula* prox;
};

struct lista{
    Celula* prim;
    Celula* ult;
};

/*Inicializa o sentinela de uma lista
 * inputs: nenhum
 * output: Sentinela inicializado (lista vazia)
 * pre-condicao: nenhuma
 * pos-condicao: sentinela da lista de retorno existe e os campos primeiro e ultimo apontam para NULL */
TLista* CriaLista(){
    TLista* l = malloc(sizeof(struct lista));
    l->prim = NULL;
    l->ult = NULL;
    return l;
}

/*Inicializa um TipoItem aluno
 * inputs: o nome e a matricula do aluno
 * output: um ponteiro para o tipo TAluno criado
 * pre-condicao: nome e matricula validos
 * pos-condicao: tipo TAluno criado, com os campos nome e matricula COPIADOS */
TAluno* InicializaAluno(char* nome, int matricula){
    TAluno* a = malloc(sizeof(struct aluno));
    a->nome = strdup(nome);
    a->matricula = matricula;
    return a;
}

/*Insere um aluno na primeira posicao da lista de alunos
 * inputs: aluno a ser inserido na lista (do tipo TAluno) e a lista
 * output: nenhum
 * pre-condicao: aluno n�o NULL e lista n�o NULL (mas, a lista pode estar vazia)
 * pos-condicao: lista contem o aluno inserido na primeira posicao */
void InsereAluno (TLista* lista, TAluno* aluno){
    Celula* nova = malloc(sizeof(struct celula));
    nova->aluno = aluno;
    nova->prox = NULL;

    if(lista->prim == NULL && lista->ult == NULL){
        lista->prim = nova;
        lista->ult = nova;
        return;
    }
    else{
        nova->prox = lista->prim;
        lista->prim = nova;
        return;
    }
}

/*Retira a primeira ocorrencia de um aluno de matricula mat da lista de alunos
 * inputs: a lista e a matricula do aluno a ser retirado da lista
 * output: o aluno (do tipo TAluno) retirado da lista ou NULL, se o aluno nao se encontrar na lista
 * pre-condicao: lista nao eh NULL (mas pode estar vazia)
 * pos-condicao: lista nao contem a primeira ocorrencia do aluno de matricula mat */
TAluno* Retira (TLista* lista, int mat){
    Celula* p = lista->prim;
    Celula* ant;

    while(p != NULL){
        if(p->aluno->matricula == mat) break;
        ant = p;
        p = p->prox;
    }

    //nao existe
    if(p == NULL){
        return NULL;
    }

    //unico
    if(p == lista->prim && p == lista->ult){
        TAluno* a = p->aluno;
        lista->prim = NULL;
        lista->ult = NULL;
        free(p);
        return a;
    }

    //primeiro
    if(p == lista->prim){
        TAluno* a = p->aluno;
        lista->prim = p->prox;
        free(p);
        return a;
    }

    //ultimo
    if(p == lista->ult){
        TAluno* a = p->aluno;
        ant->prox = NULL;
        lista->ult = ant;
        free(p);
        return a;
    }

    //caso geral
    TAluno* a = p->aluno;
    ant->prox = p->prox;
    free(p);
    return a;

}

/* Retira as repeticoes na lista. Ou seja, deixa apenas uma referencia para cada aluno na lista
 * inputs: a lista
 * output: nenhum
 * pre-condicao: lista nao eh NULL (mas pode estar vazia)
 * pos-condicao: lista nao contem repeticoes de alunos - APENAS UMA OCORRENCIA DE CADA ALUNO */
void RetiraRepetidos (TLista* lista){
    Celula* aux1 = lista->prim;
    Celula* aux2 = lista->prim;

    for(aux1 = lista->prim; aux1 != NULL; aux1 = aux1->prox){
        for(aux2 = aux1->prox; aux2 != NULL; aux2 = aux2->prox){
        
            if(aux1->aluno->matricula == aux2->aluno->matricula){
                TAluno* a = Retira(lista, aux1->aluno->matricula);
                aux1 = lista->prim;
            }

        }
    }
}


static void InsereAlunoFim(TLista* lista, TAluno* aluno){
    Celula* nova = malloc(sizeof(struct celula));
    nova->aluno = aluno;
    nova->prox = NULL;

    if(lista->prim == NULL && lista->ult == NULL){
        lista->prim = nova;
        lista->ult = nova;
        return;
    }

    lista->ult->prox = nova;
    lista->ult = nova;
}


/* Intercala os alunos das turmas 1 e 2 em uma nova lista. Por exemplo, se a turma 1 tiver (a1->a2->a3) e a turma 2 tiver (b1->b2->b3->b4->b5), a funcao deve retornar uma nova lista formada pelos elementos (a1->b1->a2->b2->a3->b3->b4->b5). Se uma das  listas tiver mais elementos que a outra, os elementos excedentes s�o transferidos na mesma ordem para a nova lista. As listas originais devem ficar vazias (com sentila prim e ult apontando para NULL).
 * inputs: duas listas n�o nulas (por�m, podem estar vazias)
 * output: uma nova lista com os elementos intercalados
 * pre-condicao: listas turma1 e turma2 nao sao NULL (mas podem estar vazias)
 * pos-condicao: lista retornada contem os elementos intercalados. As listas de entrada vazias (apenas com sentinela). */
TLista* Merge (TLista* turma1, TLista* turma2){
    TLista* merge = CriaLista();

    Celula* aux1 = turma1->prim;
    Celula* aux2 = turma2->prim;
    Celula* seguinte1;
    Celula* seguinte2;
    

    while(aux1 != NULL || aux2 != NULL){
        if(aux1 != NULL){
            seguinte1 = aux1->prox;
            TAluno* a = Retira(turma1, aux1->aluno->matricula);
            InsereAlunoFim(merge, a);
            aux1 = seguinte1;
        }

        if(aux2 != NULL){
            seguinte2 = aux2->prox;
            TAluno* b = Retira(turma2, aux2->aluno->matricula);
            InsereAlunoFim(merge, b);
            aux2 = seguinte2;
        }
        
    }

    return merge;
}

/* Libera a memoria alocada para o aluno
 * inputs: o aluno do tipo TAluno*
 * output: nenhum
 * pre-condicao: aluno n�o NULL
 * pos-condicao: toda a memoria alocada para o aluno foi liberada (inclusive para o nome) */
void LiberaAluno (TAluno* aluno){
    if(aluno != NULL){
        if(aluno->nome != NULL) free(aluno->nome);
        free(aluno);
    }
}

/*Imprime os dados de todos os alunos da lista
 * inputs: a lista de alunos
 * output: nenhum
 * pre-condicao: lista nao eh NULL (mas, pode estar vazia)
 * pos-condicao: dados dos alunos impressos na saida padrao */
void Imprime (TLista* lista){
    Celula* aux;
    for(aux = lista->prim; aux != NULL; aux = aux->prox){
        printf("Nome aluno: %s\n", aux->aluno->nome);
        printf("Matricula aluno: %d\n\n", aux->aluno->matricula);
    }
}

/*Libera toda a memoria alocada para a lista (lembre-se de tambem liberar a memoria para o aluno)
 * inputs: a lista encadeada de alunos
 * output: nenhum
 * pre-condicao: lista nao eh NULL (mas pode estar vazia)
 * pos-condicao: toda memoria alocada eh liberada (use valgrind!) */
void LiberaLista (TLista* lista){
    Celula* atual = lista->prim;
    Celula* seguinte;

    while(atual != NULL){
        seguinte = atual->prox;
        LiberaAluno(atual->aluno);
        free(atual);
        atual = seguinte;
    }
    free(lista);
}



