#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100000

void bubbleSort(int* vet, int tam);
void printFunction(int* vet, int tam);
int compare(const void * a, const void * b);

int main(){
    time_t tempo = time(NULL);
    time(&tempo);

    int vet[TAM];
    int i;
    for(i = 0; i < TAM; i++){
        vet[i] = rand() % 100;
    }

    printf("%s\n", ctime(&tempo));

    //printFunction(vet, TAM);
    //bubbleSort(vet, TAM);
    
    
    qsort(vet, TAM, sizeof(int), compare);
    printFunction(vet, TAM);

    time_t tempo2 = time(NULL);
    time(&tempo2);
    printf("%s\n", ctime(&tempo2));
    printf("Diferenca: %.1lf\n", difftime(tempo2, tempo));
}

int compare(const void * a, const void * b){
    return (*(int*)a > *(int*)b);
}

void printFunction(int* vet, int tam){
    int i;
    for(i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }
}

void bubbleSort(int* vet, int tam){
    int i, j;
    int aux;
    for(i = 0; i < tam; i++){
        for(j = i; j < tam; j++){
            if(vet[i] > vet[j]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}
