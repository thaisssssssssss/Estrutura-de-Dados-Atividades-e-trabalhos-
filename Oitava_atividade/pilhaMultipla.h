#ifndef PILHAMULTIPLA_H
#define PILHAMULTIPLA_H

typedef struct IndicePilha IndicePilha;
typedef struct TipoPilhaMultipla TipoPilhaMultipla;
typedef int TipoItem;

TipoPilhaMultipla* inicializaPilhaMultipla();
int empilha(TipoPilhaMultipla* p, int indice, TipoItem* item);
TipoItem* desempilha(TipoPilhaMultipla* p, int indice);
int vazia(TipoPilhaMultipla* p, int indice);
void liberaPilhaMultipla(TipoPilhaMultipla* p);

#endif
