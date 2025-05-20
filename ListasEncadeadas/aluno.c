//
//  aluno.h
//
//  Created by Thais Gomes on 19/05/2025.
//

#include <stdio.h>
#include "aluno.h"
#include <stdlib.h>
#include <string.h>

struct aluno{
    char* nome;
    int matricula;
};


char* leLinha(){
    char temp[100];
    scanf(" %99[^\n]", temp);
    char* str = strdup(temp);
    return str;
}

/*Inicializa uma struct aluno
 * inputs: nao ha
 * output: struct aluno incializada
 * pre-condicao: nenhuma
 * pos-condicao: retorna uma struct aluno inicializada
 */
Aluno* criaAluno(){
    Aluno* a = malloc(sizeof(struct aluno));
    if(a == NULL){
        printf("Erro ao alocar memoria");
    }

    return a;
}

/*Le os dados dos alunos
 * inputs: struct aluno inicializada
 * output: nao ha 
 * pre-condicao: struct aluno deve existir
 * pos-condicao: retorna uma struct aluno preenchida
 */
void leDadosAluno(Aluno* aluno){
    printf("Digite o nome do aluno:");
    aluno->nome = leLinha();
    
    printf("Digite a matricula do aluno:");
    scanf("%d", &aluno->matricula);
}

/*Imprime os dados dos alunos
 * inputs: struct aluno inicializada e preenchida
 * output: nao ha 
 * pre-condicao: struct aluno deve existir e estar preenchida
 * pos-condicao: imprime na tela as informacoes da struct
 */
void imprimeAluno(Aluno* aluno){
    printf("Nome: %s\n", aluno->nome);
    printf("Matricula: %d\n", aluno->matricula);
}

int retornaMatricula(Aluno* aluno){
    return aluno->matricula;
}


/*Libera a struct aluno
 * inputs: struct aluno 
 * output: nao ha 
 * pre-condicao: struct aluno deve existir
 * pos-condicao: struct aluno liberada
 */
void liberaAluno(Aluno* aluno){
    if(aluno != NULL){
        if(aluno->nome != NULL) free(aluno->nome);
        free(aluno);
    }
}

