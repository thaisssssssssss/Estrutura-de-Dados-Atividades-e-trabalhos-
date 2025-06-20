#ifndef produto_h
#define produto_h

#include <stdio.h>
#include <stdlib.h>

typedef struct produto TProduto;

TProduto* InicProd(char* nome, int calorias);
void InsereIngrediente(TProduto* prod, char* ingrediente);
int ComparaProdutos(TProduto* p1, char* nome);
int retornaCaloriasProduto(TProduto* prod);
void ImprimeProduto(TProduto* prod);
void DestroiProd(TProduto* prod);

#endif