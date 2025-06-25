#include <stdio.h>

int main(){
    int b, qtdU = 0, qtdR = 0, somaU = 0, somaR = 0, i;
    char a;
    for(i = 0; i < 399; i++){
        scanf("%*c[^A^T^0-9]");
        scanf("%c %d", &a, &b);
        //printf("%c %d\n", a, b);

        if(a == 'U'){
            qtdU++;
            somaU += b;
        }
        else if(a == 'R'){
            qtdR++;
            somaR += b;
        }
    }

    printf("qtd U: %d    qtd R: %d\n", qtdU, qtdR);
    printf(" soma U %d\n",  somaU);
    printf(" soma R %d\n",  somaR);

}