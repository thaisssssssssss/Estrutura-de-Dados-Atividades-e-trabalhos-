//
//
// Criado por Thais Gomes no dia 23/06/2025
//
//



#include <stdio.h>
#include "ComidaNaoVegana.h"
#include "ComidaVegana.h"
#include "lista.h"
#include "Pedido.h"

//2 listas
//1 lista comidas > 500 calorias (calóricos)
//1 lista comidas <=500 calorias (magros)
/*Tipo que define um pedido (tipo opaco)
 *Um pedido deve ter os seguintes atributos:
 * * Numero do pedido
 * * Uma lista de comidas (veganas e nao veganas) com calorias > 500 (alimentos calóricos)
 * * Uma lista de comidas (veganas e nao veganas) com calorias <=500 (alimentos magros)
 * */
typedef struct pedido Pedido;

struct pedido{
    int numero;
    Lista* caloricos;
    Lista* magros;
};

/* Cria um pedido, ainda vazio, com duas listas de alimentos, vazias
* inputs: numero do pedido.
* output: pedido alocado e vazia, com listas de alimentos ainda vazias
* pre-condicao: nao tem
* pos-condicao: pedido alocado e vazio, com listas de alimentos criadas e vazias
 */
Pedido* inicPedido (int numero){
    Pedido* p = malloc(sizeof(struct pedido));
    p->caloricos = criaLista();
    p->magros = criaLista();
    p->numero = numero;
    return p;
}

/* Insere uma comida vegana em uma das listas de alimentos, dependendo do seu nível de caloria
* inputs: referência para a um pedido e a referência para o alimento
* output: nenhum
* pre-condicao: pedido alocado e alimento alocado
* pos-condicao: pedido contém o alimento em uma de suas listas, dependendo do nível de calorias do alimento  */
void insereComidaVegana (Pedido* pedido, ComidaVegana* food){
    if(retornaCaloriasComidaVegana(food) <= 500){
        insereComidaLista(pedido->magros, food, VEGANA);
    }
    else{
        insereComidaLista(pedido->caloricos, food, VEGANA);
    }
}


/* Insere uma comida não vegana em uma das listas de alimentos, dependendo do seu nível de caloria
* inputs: referência para a um pedido e a referência para o alimento
* output: nenhum
* pre-condicao: pedido alocado e alimento alocado
* pos-condicao: pedido contém o alimento em uma de suas listas, dependendo do nível de calorias do alimento  */
void insereComidaNaoVegana (Pedido* pedido, ComidaNaoVegana* food){
    if(retornaCaloriasComidaNaoVegana(food) <= 500){
        insereComidaLista(pedido->magros, food, NVEG);
    }
    else{
        insereComidaLista(pedido->caloricos, food, NVEG);
    }
}

//retorna o numero do pedido
int retornaNumeroPedido(Pedido* pedido){
    return pedido->numero;
}

/* Essa função atualiza a situação de uma comida nao vegana no pedido. Caso o alimento esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para o pedido e a referência para o alimento
* output: nenhum
* pre-condicao: pedido alocado e alimento alocado
* pos-condicao: alimento deve estar na lista correta, de acordo com seu nível de calorias */
void atualizaSituacaoComidaNaoVegana(Pedido* pedido, ComidaNaoVegana* food){
    if(retornaCaloriasComidaNaoVegana(food) > 500){
        if(confereComidaEstaNaLista(pedido->magros, food, NVEG)){
            retiraComidaDaLista(pedido->magros, food, NVEG);
            insereComidaLista(pedido->caloricos, food, NVEG);
        }
    }
    else{
        if(confereComidaEstaNaLista(pedido->caloricos, food, NVEG)){
            retiraComidaDaLista(pedido->caloricos, food, NVEG);
            insereComidaLista(pedido->magros, food, NVEG);
        }
    }
}

/* Essa função atualiza a situação de uma comida vegana no pedido. Caso o alimento esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para o pedido e a referência para o alimento
* output: nenhum
* pre-condicao: pedido alocado e alimento alocado
* pos-condicao: alimento deve estar na lista correta, de acordo com seu nível de calorias */
void atualizaSituacaoComidaVegana(Pedido* pedido, ComidaVegana* food){
    if(retornaCaloriasComidaVegana(food) > 500){
        if(confereComidaEstaNaLista(pedido->magros, food, VEGANA)){
            retiraComidaDaLista(pedido->magros, food, VEGANA);
            insereComidaLista(pedido->caloricos, food, VEGANA);
        }
    }
    else{
        if(confereComidaEstaNaLista(pedido->caloricos, food, VEGANA)){
            retiraComidaDaLista(pedido->caloricos, food, VEGANA);
            insereComidaLista(pedido->magros, food, VEGANA);
        }
    }
}


//Imprime os dados do pedido, seguindo o formato a seguir
/*Imprimindo Detalhes do Pedido número: 123
  Valor total do Pedido: 135.90

 Lista de Itens de Baixa Caloria: 1
 Nome comida nao vegana: Picanha, valor: 90.50, calorias: 300

 Lista de Itens de Alta Caloria: 2
 Nome comida vegana: Empadao, calorias: 600
 Nome comida nao vegana: Sorvete de Creme, valor: 15.40, calorias: 600
*/
void imprimePedido (Pedido* pedido){
    printf("\nImprimindo Detalhes do Pedido número: %d\n", retornaNumeroPedido(pedido));
    printf("\nValor total do Pedido: %.2f\n", calculaValorPedido(pedido));

    printf("\nLista de Itens de Baixa Caloria: %d", retornaTamanhoLista(pedido->magros));
    imprimeLista(pedido->magros);

    printf("\nLista de Itens de Alta Caloria: %d", retornaTamanhoLista(pedido->caloricos));
    imprimeLista(pedido->caloricos);
}

//comida vegana tem o valor fixo de 30 reais
float calculaValorPedido (Pedido* pedido){
    float valorListaCalorica = retornaValorTotalLista(pedido->caloricos);
    float valorListaMagros = retornaValorTotalLista(pedido->magros);
    return (float)valorListaCalorica + (float)valorListaMagros;
}

/* Libera toda a memória alocada
* inputs: referencia para o pedido
* output: não tem
* pre-condicao: pedido alocado
* pos-condicao: Toda a memória liberada, a não ser alimentos, que são responsabilidade do cliente. */
void liberaPedido (Pedido* pedido){
    if(pedido != NULL){
        liberaLista(pedido->magros);
        liberaLista(pedido->caloricos);
        free(pedido);
    }
}

