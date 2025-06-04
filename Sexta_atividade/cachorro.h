#ifndef cachorro_h
#define cachorro_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BRAVO 0
#define MANSO 1

typedef struct cachorro Cachorro;

Cachorro* inicCachorro(char* nome, int agressividade);
void liberaCachorro(Cachorro* c);
int retornaAgressividadeCachorro(Cachorro* c);
void imprimeCachorro(Cachorro* c);
void atribuiNivelAgressividadeCachorro(Cachorro* c, int agressividade);

#endif