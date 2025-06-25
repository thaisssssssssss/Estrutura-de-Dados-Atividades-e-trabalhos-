//
//
// Criado por Thais Gomes Brandao no dia 24/06/2025
//
//

#include "BanhoTosa.h"
#include "Lista.h"


/*Tipo que define a loja de banho e tosa (tipo opaco)
 *Cada loja deve ter os seguintes atributos:
 * * Nome da loja
 * * Uma lista de animais (gatos e cachorros) agressivos
 * * Uma lista de animais (gatos e cachorros) mansos
 * */

struct banhotosa{
    char* nome;
    Lista* agressivos;
    Lista* mansos;
};

/* Cria uma loja de banho e tosa, ainda vazia, com duas listas de animais vazias
* inputs: nome da loja (char*). Esta função deve alocar dinamicamente o nome da loja.
* output: loja alocada e vazia, com listas de animais ainda vazias
* pre-condicao: nao tem
* pos-condicao: loja alocada e vazia, com listas de animais criadas e vazias  */
BanhoTosa* inicBanhoTosa(char* nome){
    BanhoTosa* bt = malloc(sizeof(struct banhotosa));
    bt->nome = strdup(nome);
    bt->mansos = incializaLista();
    bt->agressivos = incializaLista();
    return bt;
}

/* Insere o cachorro em uma das listas de animais, dependendo do seu nível de agressividade
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: loja contém o animal e uma de suas listas, dependendo do nível de agressividade do animal  */
void cadastraCachorro(BanhoTosa* loja, Cachorro* dog){
    if(retornaAgressividadeCachorro(dog) == BRAVO) insereItemLista(loja->agressivos, dog, CACHORRO);
    else insereItemLista(loja->mansos, dog, CACHORRO);
}

/* Insere o cachorro em uma das listas de animais, dependendo do seu nível de agressividade
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: loja contém o animal e uma de suas listas, dependendo do nível de agressividade do animal  */
void cadastraGato(BanhoTosa* loja, Gato* cat){
    if(retornaAgressividadeGato(cat) == BRAVO) insereItemLista(loja->agressivos, cat, GATO);
    else insereItemLista(loja->mansos, cat, GATO);
}


/* Essa função atualiza a situação de um gato na loja. Caso ele esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: animal deve estar na lista correta, de acordo com seu nível de agressividade */
void atualizaSituacaoGato(BanhoTosa* loja, Gato* cat){
    if(retornaAgressividadeGato(cat) == BRAVO){
        if(confereItemNaLista(loja->mansos, cat, GATO));
        retiraItemLista(loja->mansos, cat, GATO);
        insereItemLista(loja->agressivos, cat, GATO);
    }
    else if(retornaAgressividadeGato(cat) == MANSO){
        if(confereItemNaLista(loja->agressivos, cat, GATO));
        retiraItemLista(loja->agressivos, cat, GATO);
        insereItemLista(loja->mansos, cat, GATO);
    }
}

/* Essa função atualiza a situação de um cachorro na loja. Caso ele esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: animal deve estar na lista correta, de acordo com seu nível de agressividade */
void atualizaSituacaoCachorro(BanhoTosa* loja, Cachorro* dog){
    if(retornaAgressividadeCachorro(dog) == BRAVO){
        if(confereItemNaLista(loja->mansos, dog, CACHORRO));
        retiraItemLista(loja->mansos, dog, CACHORRO);
        insereItemLista(loja->agressivos, dog, CACHORRO);
    }
    else if(retornaAgressividadeCachorro(dog) == MANSO){
        if(confereItemNaLista(loja->agressivos, dog, CACHORRO));
        retiraItemLista(loja->agressivos, dog, CACHORRO);
        insereItemLista(loja->mansos, dog, CACHORRO);
    }
}


/* Imprime os dados da Loja (nome, e conteúdo das listas)
* inputs: referencia para a loja
* output: nenhum
* pre-condicao: loja alocada
* pos-condicao: nenhuma alteração feita nos conteúdos das estruturas de dados */
void imprimeBanhoTosa(BanhoTosa* loja){
    printf("\nLoja: %s\n", loja->nome);
    printf("\nAnimais mansos:\n");
    imprimeLista(loja->mansos);
    printf("\nAnimais agressivos:\n");
    imprimeLista(loja->agressivos);
}


/* Calcula o valor que a loja vai receber caso todos os animais tomem banho.
 Valor Gato: 30 reais, Valor Cachorro: 40 reais. Caso o animal seja agressivo, é cobrado uma taxa extra de 5 reais.
* inputs: referencia para a loja
* output: valor da receita
* pre-condicao: loja alocada
* pos-condicao: nenhuma alteração feita nos conteúdos das estruturas de dados */
float calculaReceita(BanhoTosa* loja){
    int cachorrosAgressivos = retornaQtdPorTipo(loja->agressivos, CACHORRO);
    int cachorrosMansos = retornaQtdPorTipo(loja->mansos, CACHORRO);
    int gatosAgressivos = retornaQtdPorTipo(loja->agressivos, GATO);
    int gatosMansos = retornaQtdPorTipo(loja->mansos, GATO);

    float lucro = (float)(cachorrosAgressivos * 45) + (float)(cachorrosMansos * 40) + (float)(gatosAgressivos * 35) + (float)(gatosMansos * 30);
    return lucro;
}


/* Libera toda a memória alocada
* inputs: referencia para a loja
* output: não tem
* pre-condicao: loja alocada
* pos-condicao: Toda a memória liberada, a não ser gatos e cachorros, que são responsabilidade do cliente. */
void liberaBanhoTosa(BanhoTosa* loja){
    if(loja != NULL){
        free(loja->nome);
        liberaLista(loja->mansos);
        liberaLista(loja->agressivos);
        free(loja);
    }
}

