#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct Produto tProduto;

struct Produto{
    char* nome;
    int valor;
    int codigo;
};

/**Cria um produto com os parametros passados
 * inputs: nome, valor e codigo do produto
 * output: produto criado
 * pre-condicao: parametros passados
 * pos-condicao: produto deve ser inicializado
 */
tProduto* criaProduto(char* nome, int valor, int codigo);

/**Imprime produto
 * inputs: produto
 * output: nenhum
 * pre-condicao: produto deve existir
 * pos-condicao: produto nao eh modificado
 */
void imprimeProduto(tProduto* prod);

/**Compara o codigo do produto com um codigo passado como parametro
 * inputs: produto e codigo
 * output: 1 caso sejam iguais, 0 caso contario
 * pre-condicao: produto deve existir
 * pos-condicao: produto nao eh modificado
 */
int comparaCodigo(tProduto* prod, int codigo);

/**Libera produto
 * inputs: produto
 * output: nenhum
 * pre-condicao: produto deve existir
 * pos-condicao: produto eh liberado
 */
void liberaProduto(tProduto* prod);

#endif