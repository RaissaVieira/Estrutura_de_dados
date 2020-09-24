#include <stdio.h>
#include <stdlib.h>

int main(){

    int tam;

    printf("Tamanho do vetor: ");
    scanf("%i", &tam);

    int num[tam];

    for (int i = 0; i < tam; i++)
    {
        printf("Digite um valor: ");
        scanf("%i", &num[i]);
    }

    for (int i = 0; i < tam; i++)
    {
        printf("%i ", num[i]);
    }
    
    return 0;
}