#include <stdio.h>

int main (){

    int num1, num2, i;

    printf("Digite o valor inicial: ");
    scanf("%i", &num1);
    printf("Digite o valor final: ");
    scanf("%i", &num2);

    // A
    /* i = num1;
    while (i <= num2)
    {
        printf("%i ",i);

        i++;
    } */

    // B
    /* i = num1;
    do
    {
        printf("%i ",i);

        i++;

    } while (i <= num2); */

    // C

    for (int i = num1; i <= num2; i++)
    {
        printf("%i ",i);
    }
    
    return 0;
}