//
//  aluno.h
//
//  Created by Thais Gomes on 19/05/2025.
//

#ifndef aluno_h
#define aluno_h

typedef struct aluno Aluno;

/*Inicializa uma struct aluno
 * inputs: nao ha
 * output: struct aluno incializada
 * pre-condicao: nenhuma
 * pos-condicao: retorna uma struct aluno inicializada
 */
Aluno* criaAluno();

/*Le os dados dos alunos
 * inputs: struct aluno inicializada
 * output: nao ha 
 * pre-condicao: struct aluno deve existir
 * pos-condicao: retorna uma struct aluno preenchida
 */
void leDadosAluno(Aluno* aluno);

/*Imprime os dados dos alunos
 * inputs: struct aluno inicializada e preenchida
 * output: nao ha 
 * pre-condicao: struct aluno deve existir e estar preenchida
 * pos-condicao: imprime na tela as informacoes da struct
 */
void imprimeAluno(Aluno* aluno);

int retornaMatricula(Aluno* aluno);

/*Libera a struct aluno
 * inputs: struct aluno 
 * output: nao ha 
 * pre-condicao: struct aluno deve existir
 * pos-condicao: struct aluno liberada
 */
void liberaAluno(Aluno* aluno);

#endif