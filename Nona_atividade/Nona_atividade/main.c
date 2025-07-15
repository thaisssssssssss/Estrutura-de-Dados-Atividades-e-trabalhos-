#include "arvore.h"
#include "aluno.h"


int main(){
    Aluno* mari = inicializaAluno("Marina", 111);
    Aluno* hugo = inicializaAluno("Hugo", 222);
    Aluno* joao = inicializaAluno("Joao", 333);
    Aluno* thais = inicializaAluno("Thais", 444);
    Aluno* pedro = inicializaAluno("Pedro", 555);
    Aluno* nicoly = inicializaAluno("Nicoly", 222);
    Aluno* manu = inicializaAluno("Manuela", 222);

    Arv* MarinaRaiz = arv_criavazia();
    Arv* HugoNo = arv_criavazia();
    Arv* JoaoNo = arv_criavazia();
    Arv* ThaisNo = arv_criavazia();
    Arv* PedroNo = arv_criavazia();
    Arv* NicolyNo = arv_criavazia();
    Arv* ManuelaNo = arv_criavazia();

    ManuelaNo = arv_cria(manu, NULL, NULL);
    NicolyNo = arv_cria(nicoly, NULL, NULL);
    PedroNo = arv_cria(pedro, NULL, ManuelaNo);
    ThaisNo = arv_cria(thais, NicolyNo, NULL);
    JoaoNo = arv_cria(joao, ThaisNo, PedroNo);
    HugoNo = arv_cria(hugo, NULL, NULL);
    MarinaRaiz = arv_cria(mari, HugoNo, JoaoNo);

    int mat = 444;
    Arv* pai = arv_pai(MarinaRaiz, mat);
    arv_imprime(pai);
    printf("\n");

    mat = 111;
    int pertence = arv_pertence(MarinaRaiz, mat);
    if(pertence) printf("\nAluno de matricula %d pertence a arvore\n", mat);
    else printf("\nAluno de matricula %d nao pertence a arvore\n", mat);

    int comprimento = altura(MarinaRaiz);
    printf("\nAltura da arvore: %d\n", comprimento);

    mat = 222;
    int repeticoes = ocorrencias(MarinaRaiz, mat);
    printf("\nNumero de ocorrencias da matricula %d: %d\n", mat, repeticoes);

    int fim = folhas(MarinaRaiz);
    printf("\nQuantidade de nos folhas: %d\n", fim);

    arv_imprime(MarinaRaiz);
    printf("\n");
    arv_libera(MarinaRaiz);

    liberaAluno(mari);
    liberaAluno(hugo);
    liberaAluno(joao);
    liberaAluno(thais);
    liberaAluno(pedro);
    liberaAluno(manu);
    liberaAluno(nicoly);
}