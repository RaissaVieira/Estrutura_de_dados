#include <stdio.h>

int main (){

    int num, fatorial=1;

    printf("Digite um numero: ");
    scanf("%i", &num);

    printf("%i! = ", num);

    for (int i = num; i > 0; i--)
    {
        fatorial *= i;

        if(i == 1){
            printf("%i = ", i);
        }else{
            printf("%i X ", i);
        }
    }
    
    printf("%i\n",fatorial);

    return 0;
}