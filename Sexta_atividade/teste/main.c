//
//  Este é o testador3.c, testa TODAS as funcionalidades
//  Pode valer até 10 pontos.
//
//
//  Created by Patricia Dockhorn Costa on 19/06/22.
//


#include <stdio.h>
#include "listaNova.h"
#include "cachorro.h"


int main(int argc, const char * argv[]) {

    //cadastra uns cachorrinhos e gatinhos
    //nome e nível de agressividade
    Lista* l = criaLista();

    Cachorro* iris = inicCachorro("Iris", BRAVO);
    l = adicionaItemLista(l, iris);
    Cachorro* bob = inicCachorro("Bob", MANSO);
    l = adicionaItemLista(l, bob);
    Cachorro* baby = inicCachorro("Baby", MANSO);
    l = adicionaItemLista(l, baby);
    Cachorro* ana = inicCachorro("Ana", BRAVO);

    imprimeLista(l);
    l = removeItemLista(l, baby); 
    imprimeLista(l);

    liberaLista(l);

    liberaCachorro(iris);
    liberaCachorro(bob);
    liberaCachorro(baby);
    liberaCachorro(ana);

    return 0;
}
