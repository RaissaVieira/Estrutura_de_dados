#include <stdio.h>
#include <stdlib.h>

int main(){

    int tam, tam2;

    printf("Tamanho da matriz: (linhas)");
    scanf("%i", &tam);
    printf("por: (colunas)");
    scanf("%i", &tam2);

    int num[tam][tam2];

    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam2; j++)
        {
            printf("Digite um valor: ");
            scanf("%i", &num[i][j]);
        }
    }

    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam2; j++)
        {
            printf("%i ", num[i][j]);

            if(j == (tam2-1)){
                printf("\n");
            }
        }
    }

    return 0;
}