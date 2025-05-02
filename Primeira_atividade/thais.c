#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

void calc_esfera(float r, float* area, float *volume){
    *area = 4 * PI * r * r;
    *volume = (4 * PI * r * r * r) / 3;
}


int raizes(float a, float b, float c, float* x1, float* x2){
    float delta = 0;
    delta = pow(b, 2) - (4 * a * c);

    if(delta < 0) return 0; //nao existe raiz real

    *x1 = (-b + sqrt(delta)) / (2 * a);
    *x2 = (-b - sqrt(delta)) / (2 * a);

    return 1;
}


int pares(int n, int* vet){
    int i, par = 0;

    for(i = 0; i < n; i++){
        if(vet[i] % 2 == 0) par++;
    }

    return par;
}


void inverte(int n, int* vet){
    int i, j;
    for(i = 0; i < n/2; i++){
        j = vet[n - 1 - i];
        vet[n - 1 - i] = vet[i];
        vet[i] = j;
    }
}


double avalia(double* poli, int grau, double x){
    int i, j;
    double soma = 0;
    for(i = 0; i <= grau; i++){
        soma += pow(x, i) * poli[i];
    }
    return soma;
}


//NAO PRECISAVA ALOCAR MEMORIA PARA O NOVO VETOR, JA QUE EH UMA ESPECIE DE COPIA DO OUTRO
int** inverte2(int n, int* vet){
    int** vet2 = (int**) malloc(sizeof(int*) * n);
    int i, j;
    int *aux;
    for(i = 0; i < n; i++){
        vet2[i] = &vet[i]; // Apenas armazenando o endereço do elemento original
    }

    //ordena crescente
    for(i = 0; i < n; i++){
        for(j = i; j < n; j++){
            if(*vet2[i] > *vet2[j]){
                aux = vet2[i];
                vet2[i] = vet2[j];
                vet2[j] = aux;
            }
        }
    }
    return vet2;
}


int main(){

    //ponto 1 (area e volume esfera)

    float area, volume, raio;
    printf("Insira o raio da esfera: ");
    scanf("%f", &raio);
    calc_esfera(raio, &area, &volume);
    //area = volume;   atribui o valor numerico
    printf("A area e o volume da esfera de raio %.2f, sao, respectivamente, %.2f e %.2f.\n", raio, area, volume);



    //ponto 2 (calcular raizes de uma equacao)

    float a, b, c, x1, x2;
    int temRaiz = 0;
    printf("Insira os componentes da equacao: ");
    scanf("%f %f %f", &a, &b, &c);
    temRaiz = raizes(a, b, c, &x1, &x2);

    if(temRaiz) printf("As raizes da equacao, sao, respectivamente, %.2f e %.2f.\n", x1, x2);
    else printf("A equacao nao possui raizes\n");



    //ponto 3 (quantidade de pares em um vetor)

    int n, i, par;
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &n);

    int *vet = (int*) malloc(sizeof(int) * n);
    for(i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }

    par = pares(n, vet);
    printf("A quantidade de numeros pares no vetor eh: %d\n", par);
    free(vet);



    //ponto 4 (inverter as posicoes do vetor)

    printf("Insira o tamanho do vetor: \n");
    scanf("%d", &n);
    int *vet2 = (int*) malloc(sizeof(int) * n);
    for(i = 0; i < n; i++){
        scanf("%d", &vet2[i]);
    }
    inverte(n, vet2);
    printf("Vetor invertido:");
    for(i = 0; i < n; i++){
        printf(" %d", vet2[i]);
    }
    printf("\n");
    free(vet2);



    //ponto 5 (avaliacao de polinomios)
    
    //printf("Insira o tamanho do vetor: ");
    printf("Insira o grau do polinomio: ");

    scanf("%d", &n);
    double *poli = (double*) malloc(sizeof(double) * (n + 1));
    double x, result = 0;
    for(i = 0; i <= n; i++){
        scanf("%lf", &poli[i]);
    }
    printf("Insira o valor da variavel: ");
    scanf("%lf", &x);

    result = avalia(poli, n, x);
    printf("Resultado da avaliacao do polinomio: %.2f", result);

    free(poli);


    
    //desafio

    printf("Insira o tamanho do vetor: \n");
    scanf("%d", &n);
    int *vet3 = (int*) malloc(sizeof(int) * n);
    for(i = 0; i < n; i++){
        scanf("%d", &vet3[i]);
    }

    int **vet3_1 = inverte2(n, vet3);

    printf("Vetor ordenado:");
    for(i = 0; i < n; i++){
        printf(" %d", *vet3_1[i]);
    }
    printf("\n");
    printf("Vetor normal:");
    for(i = 0; i < n; i++){
        printf(" %d", vet3[i]);
    }
    printf("\n");
    free(vet3);
    free(vet3_1);
    //NAO LIBERA MEMORIA DE CADA ITEM DO VET3_1, PQ NAO ALOCOU
    
    return 0;
}