#include <stdio.h>

int main(){
    int b, qtd = 0, qtdT = 0, qtdB1 = 0, qtdB2 = 0, qtdB3 = 0, qtdB4 = 0, qtdB5 = 0, qtdA = 0, i;
    char a;
    for(i = 0; i < 399; i++){
        scanf("%*c[^A^T^0-9]");
        scanf("%c %d", &a, &b);
        //printf("%c %d\n", a, b);

        if(a == 'A'){
            qtdA++;

            if(b == 1){
                qtdB1++;
            }
            else  if(b == 2){
                qtdB2++;
            }
            else  if(b == 3){
                qtdB3++;
            }
            else  if(b == 4){
                qtdB4++;
            }
            else  if(b == 5){
                qtdB5++;
            }
        } 
        else{
            qtdT++;
        }
    }

    printf("qtd T: %d    qtd A: %d\n", qtdT, qtdA);
    printf(" (familia 1 hora)  qtd %d\n",  qtdB1);
    printf(" (familia 2 horas) qtd %d\n",  qtdB2);
    printf(" (familia 3 horas) qtd %d\n",  qtdB3);
    printf(" (familia 4 horas) qtd %d\n",  qtdB4);
    printf(" (familia 5 horas) qtd %d\n",  qtdB5);

}