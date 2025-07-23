#include "arvore.h"

int main(){
    Aluno* mari = inicializaAluno("Marina", 111);
    Aluno* hugo = inicializaAluno("Hugo", 222);
    Aluno* joao = inicializaAluno("Joao", 333);
    Aluno* thais = inicializaAluno("Thais", 444);
    Aluno* pedro = inicializaAluno("Pedro", 555);
    Aluno* nicoly = inicializaAluno("Nicoly", 121);
    Aluno* manu = inicializaAluno("Manuela", 321);

    Arvore* a = criaArvoreVazia();

    a = insereAlunoArvore(a, mari);
    a = insereAlunoArvore(a, hugo);
    a = insereAlunoArvore(a, joao);
    a = insereAlunoArvore(a, thais);
    a = insereAlunoArvore(a, pedro);
    a = insereAlunoArvore(a, nicoly);
    a = insereAlunoArvore(a, manu);

    imprimeArvore(a);

    printf("Busca:\n\n");
    Aluno* busca = buscaAlunoArvore(a, 333);
    imprimeAluno(busca);
}