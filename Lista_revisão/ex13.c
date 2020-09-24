#include <stdio.h>

int main(){

    int num[5] = {1,3,6,5,8};
    int maior=0, menor=1000;

    for (int i = 0; i < 5; i++)
    {
        if(num[i] > maior){
            maior = num[i];
        }
        if(num[i] < menor){
            menor = num[i];
        }  
    }

    printf("Maior = %i  Menor = %i", maior, menor);    

    return 0;
}