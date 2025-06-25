#include <stdio.h>

int main(){
    int a, b, qtd = 0, mediaA2 = 0, qtdA2 = 0, mediaA3 = 0, qtdA3 = 0, mediaA4 = 0, qtdA4 = 0, mediaA1 = 0, qtdA1 = 0;
    int i;
    for(i = 0; i < 399; i++){
        scanf("%d %d", &a, &b);
        printf("%d %d\n", a, b);

        if(a == 2){
            mediaA2 += b;
            qtdA2++;
        } 
        else if(a == 3){
            mediaA3 += b;
            qtdA3++;
        }  
        else if(a == 4){
            mediaA4 += b;
            qtdA4++;
        }  
        else if(a == 1){
            mediaA1 += b;
            qtdA1++;
        }  
        else qtd++;
    }

    printf("media (estudam 1 hora) %.2f e qtd %d\n", (float)mediaA1 / (float)qtdA1, qtdA1);
    printf("media (estudam 2 horas) %.2f e qtd %d\n", (float)mediaA2 / (float)qtdA2, qtdA2);
    printf("media (estudam 3 horas) %.2f e qtd %d\n", (float)mediaA3 / (float)qtdA3, qtdA3);
    printf("media (estudam 4 horas) %.2f e qtd %d\n", (float)mediaA4 / (float)qtdA4, qtdA4);

}