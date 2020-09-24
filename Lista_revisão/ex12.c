#include <stdio.h>
#include <stdlib.h>

void inverso(int num[], int tam){

    int inverso[tam];
    int j = 0;

    for (int i = tam-1; i >= 0; i++)
    {
        inverso[i] = num[j];
        j++;
        printf("%i", inverso[i]);
    }
    
    /* for (int i = 0; i < tam; i++)
    {
        printf("%i", inverso[i]);
    } */
    
}

int main(){

    int num[5], retorno;

    for (int i = 0; i < 5; i++)
    {
        printf("Digite um valor: ");
        scanf("%i", &num[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%i", num[i]);
    }

    inverso(num, 5);
    
    return 0;
}