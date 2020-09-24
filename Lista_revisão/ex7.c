#include <stdio.h>

int main (){

    int num1, num2, total=0;

    printf("Digite o valor inicial: ");
    scanf("%i", &num1);
    printf("Digite o valor final: ");
    scanf("%i", &num2);

    for (int i = num1; i <= num2; i++)
    {
       total += i; 
    }

    printf("%i\n",total);

    return 0;
}