#include "abbgen.h"

int main(){
    Aluno* thais = criaAluno("Thais", 22222, 9);
    Aluno* marina = criaAluno("Marina", 22222, 9);
    Aluno* hugo = criaAluno("Hugo", 22222, 9);
    Aluno* joao = criaAluno("Joao", 22222, 9);

    Arvore* raiz = criaArvoreVazia();
    raiz = insereOrdenado(raiz, thais, comparaPorNome);
    raiz = insereOrdenado(raiz, marina, comparaPorNome);
    raiz = insereOrdenado(raiz, hugo, comparaPorNome);
    raiz = insereOrdenado(raiz, joao, comparaPorNome);

    imprimeArvore(raiz, imprimeAluno);
    raiz = liberaArvore(raiz, liberaAluno);

}