#ifndef pilhaDupla_h
#define pilhaDupla_h

#define MaxTam 100

typedef int TipoItem;

typedef struct {
    int Topo, Base;
} IndicePilha;

typedef struct {
    TipoItem* Item[MaxTam];
    IndicePilha Pilha1, Pilha2;
} TipoPilhaDupla;

TipoPilhaDupla* inicializaPilhaDupla();
TipoItem insereValorPilha1(TipoPilhaDupla* p, TipoItem valor);
TipoItem insereValorPilha2(TipoPilhaDupla* p, TipoItem valor);
TipoItem confereOverflow(TipoPilhaDupla* p);
void liberaPilhaDupla(TipoPilhaDupla* p);
void imprimePilhaDupla(TipoPilhaDupla* p);

#endif