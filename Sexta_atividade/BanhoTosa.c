//
//  BanhoTosa.h
//  BanhoTosaED
//
//  Created by Patricia Dockhorn Costa on 19/06/22.
//


#include "BanhoTosa.h"

/*Tipo que define a loja de banho e tosa (tipo opaco)
 *Cada loja deve ter os seguintes atributos:
 * * Nome da loja
 * * Uma lista de animais (gatos e cachorros) agressivos
 * * Uma lista de animais (gatos e cachorros) mansos
 * */

struct banhotosa{
    char* nome;
    Lista* listaAgressivos;
    Lista* listaMansos;
};

/* Cria uma loja de banho e tosa, ainda vazia, com duas listas de animais vazias
* inputs: nome da loja (char*). Esta função deve alocar dinamicamente o nome da loja.
* output: loja alocada e vazia, com listas de animais ainda vazias
* pre-condicao: nao tem
* pos-condicao: loja alocada e vazia, com listas de animais criadas e vazias  */
BanhoTosa* inicBanhoTosa(char* nome){
    BanhoTosa* bt = malloc(sizeof(struct banhotosa));
    bt->nome = strdup(nome);
    bt->listaAgressivos = inicializaLista();
    bt->listaMansos = inicializaLista();
    return bt;
}

/* Insere o cachorro em uma das listas de animais, dependendo do seu nível de agressividade
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: loja contém o animal e uma de suas listas, dependendo do nível de agressividade do animal  */
void cadastraCachorro(BanhoTosa* loja, Cachorro* dog){
    if(retornaAgressividadeCachorro(dog) == BRAVO){
        loja->listaAgressivos = adicionaAnimalLista(loja->listaAgressivos, dog, CACHORRO);
    }
    else adicionaAnimalLista(loja->listaMansos, dog, CACHORRO);
}

/* Insere o cachorro em uma das listas de animais, dependendo do seu nível de agressividade
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: loja contém o animal e uma de suas listas, dependendo do nível de agressividade do animal  */
void cadastraGato(BanhoTosa* loja, Gato* cat){
    if(retornaAgressividadeGato(cat) == BRAVO){
        loja->listaAgressivos = adicionaAnimalLista(loja->listaAgressivos, cat, GATO);
    }
    else loja->listaMansos = adicionaAnimalLista(loja->listaMansos, cat, GATO);
}


/* Essa função atualiza a situação de um gato na loja. Caso ele esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: animal deve estar na lista correta, de acordo com seu nível de agressividade */
void atualizaSituacaoGato(BanhoTosa* loja, Gato* cat){
    if(retornaAgressividadeGato(cat) == BRAVO){
        int confere = confereAnimalEstaNaListaErrada(loja->listaMansos, cat, GATO, BRAVO);
        if(confere){
            loja->listaMansos = retiraAnimalLista(loja->listaMansos, cat, GATO);
            loja->listaAgressivos = adicionaAnimalLista(loja->listaAgressivos, cat, GATO);
        }
    }
    else {
        int confere = confereAnimalEstaNaListaErrada(loja->listaAgressivos, cat, GATO, MANSO); //confere se o gato esta na lista certa, se nao tiver, tira ele da lista e retorna 0
        if(confere){
            loja->listaAgressivos = retiraAnimalLista(loja->listaAgressivos, cat, GATO);
            loja->listaMansos = adicionaAnimalLista(loja->listaMansos, cat, GATO);
        }
    }
}

/* Essa função atualiza a situação de um cachorro na loja. Caso ele esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: animal deve estar na lista correta, de acordo com seu nível de agressividade */
void atualizaSituacaoCachorro(BanhoTosa* loja, Cachorro* dog){
    if(retornaAgressividadeCachorro(dog) == BRAVO){
        int confere = confereAnimalEstaNaListaErrada(loja->listaMansos, dog, CACHORRO, BRAVO);
        if(confere){
            loja->listaMansos = retiraAnimalLista(loja->listaMansos, dog, CACHORRO);
            loja->listaAgressivos = adicionaAnimalLista(loja->listaAgressivos, dog, CACHORRO);
        }
    }
    else {
        int confere = confereAnimalEstaNaListaErrada(loja->listaAgressivos, dog, CACHORRO, MANSO); //confere se o gato esta na lista certa, se nao tiver, tira ele da lista e retorna 0
        if(confere){
            loja->listaAgressivos = retiraAnimalLista(loja->listaAgressivos, dog, CACHORRO);
            loja->listaMansos = adicionaAnimalLista(loja->listaMansos, dog, CACHORRO);
        }
    }
}


/* Imprime os dados da Loja (nome, e conteúdo das listas)
* inputs: referencia para a loja
* output: nenhum
* pre-condicao: loja alocada
* pos-condicao: nenhuma alteração feita nos conteúdos das estruturas de dados */
void imprimeBanhoTosa(BanhoTosa* loja){
    printf("\nNome loja: %s\n\n", loja->nome);
    printf("Lista Mansos:\n");
    imprimeLista(loja->listaMansos);
    printf("\nLista Agressivos:\n");
    imprimeLista(loja->listaAgressivos);
}


/* Calcula o valor que a loja vai receber caso todos os animais tomem banho.
 Valor Gato: 30 reais, Valor Cachorro: 40 reais. Caso o animal seja agressivo, é cobrado uma taxa extra de 5 reais.
* inputs: referencia para a loja
* output: valor da receita
* pre-condicao: loja alocada
* pos-condicao: nenhuma alteração feita nos conteúdos das estruturas de dados */
float calculaReceita(BanhoTosa* loja){
    int cachorrosBravos = returnQtdPorEspecie(loja->listaAgressivos, CACHORRO);
    int cachorrosMansos = returnQtdPorEspecie(loja->listaMansos, CACHORRO);
    int gatosBravos = returnQtdPorEspecie(loja->listaAgressivos, GATO);
    int gatosMansos = returnQtdPorEspecie(loja->listaMansos, GATO);

    float valor = (float)((gatosMansos * 30) + (cachorrosMansos * 40)) + (float)((gatosBravos * 35) + (cachorrosBravos * 45));
    return valor;
}


/* Libera toda a memória alocada
* inputs: referencia para a loja
* output: não tem
* pre-condicao: loja alocada
* pos-condicao: Toda a memória liberada, a não ser gatos e cachorros, que são responsabilidade do cliente. */
void liberaBanhoTosa(BanhoTosa* loja){
    if(loja != NULL){
        if(loja->nome != NULL) free(loja->nome);
        liberaLista(loja->listaAgressivos);
        liberaLista(loja->listaMansos);
        free(loja);
    }
}

