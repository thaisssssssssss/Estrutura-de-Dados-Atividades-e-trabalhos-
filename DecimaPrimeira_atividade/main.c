// main.c
//
// Criado por Thais Gomes Brandao no dia 27/07/2025
//

#include "arvore.h"

int main(){
    Aluno* mari = inicializaAluno("Marina", 111);
    Aluno* hugo = inicializaAluno("Hugo", 222);
    Aluno* joao = inicializaAluno("Joao", 333);
    Aluno* thais = inicializaAluno("Thais", 325);
    Aluno* pedro = inicializaAluno("Pedro", 555);
    Aluno* nicoly = inicializaAluno("Nicoly", 121);
    Aluno* manu = inicializaAluno("Manuela", 321);
    Aluno* laura = inicializaAluno("Laura", 666);

    Arvore* a = criaArvoreVazia();

    a = insereAlunoArvore(a, mari);
    a = insereAlunoArvore(a, hugo);
    a = insereAlunoArvore(a, joao);
    a = insereAlunoArvore(a, thais);
    a = insereAlunoArvore(a, pedro);
    a = insereAlunoArvore(a, nicoly);
    a = insereAlunoArvore(a, manu);
    a = insereAlunoArvore(a, laura);

    imprimeArvore(a);

    printf("Busca:\n\n");
    Aluno* busca = buscaAlunoArvore(a, 333);
    imprimeAluno(busca);

    printf("Retira:\n\n");
    Arvore* retira = retiraAlunoArvore(a, 333);
    printf("\n\n");

    imprimeArvore(a);

    liberaArvore(a);

    liberaAluno(mari);
    liberaAluno(hugo);
    liberaAluno(joao);
    liberaAluno(thais);
    liberaAluno(pedro);
    liberaAluno(manu);
    liberaAluno(nicoly);
    liberaAluno(laura);
}