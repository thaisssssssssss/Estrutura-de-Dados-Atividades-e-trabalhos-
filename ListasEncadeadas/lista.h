//
//  lista.h
//
//  Created by Thais Gomes on 19/05/2025.
//

#ifndef lista_h
#define lista_h

#include "aluno.h"

typedef struct lista Lista;
typedef struct celula Celula;

Lista* criaLista();
void liberaLista(Lista* lista);
void insereAluno(Lista* lista, Aluno* aluno);
Aluno* retiraAluno(Lista* lista, int  matricula);
void imprimeLista(Lista* lista);


#endif