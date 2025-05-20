#include <stdio.h>
#include "aluno.h"
#include "lista.h"
#include <stdlib.h>

int main(){
    Aluno* aluno = criaAluno();
    Aluno* aluno2 = criaAluno();
    Aluno* aluno3 = criaAluno();

    leDadosAluno(aluno);
    leDadosAluno(aluno2);
    leDadosAluno(aluno3);
    
    Lista* lista = criaLista();
    insereAluno(lista, aluno);
    insereAluno(lista, aluno2);
    insereAluno(lista, aluno3);

    imprimeLista(lista);

    int matricula;
    printf("Digite a matricula desejada");
    scanf("%d", &matricula);
    Aluno* aux = retiraAluno(lista, matricula);
    imprimeAluno(aux);

    liberaAluno(aux);
    liberaLista(lista);
    //imprimeAluno(aluno);
    //liberaAluno(aluno);
    return 0;
}