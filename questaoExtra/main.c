#include "lista.h"


int main(){
    Lista* l = inicializaLista();

    Aluno* a = inicializaAluno("Thais", 1234);
    Aluno* b = inicializaAluno("Nicoly", 1111);
    Aluno* c = inicializaAluno("Manuela", 3245);
    Aluno* d = inicializaAluno("Pedro", 2000);
    Aluno* e = inicializaAluno("Laura", 5007);
    Aluno* f = inicializaAluno("Nicolas", 1000);
    Aluno* g = inicializaAluno("Katia", 6543);
    Aluno* h = inicializaAluno("Samara", 4444);
    Aluno* i = inicializaAluno("Neto", 9876);


    insereOrdenadoNaLista(l, a);
    insereOrdenadoNaLista(l, b);
    insereOrdenadoNaLista(l, c);
    insereOrdenadoNaLista(l, d);
    insereOrdenadoNaLista(l, e);
    insereOrdenadoNaLista(l, f);
    insereOrdenadoNaLista(l, g);
    insereOrdenadoNaLista(l, h);
    insereOrdenadoNaLista(l, i);

    imprimeLista(l);
    liberaLista(l);
}