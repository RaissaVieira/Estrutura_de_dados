#include <stdio.h>
#include <math.h>

float delta(int a, int b, int c){

    float valorD;

    valorD = b*b - 4*a*c;

    return valorD;
}

void raizes(float valorD, int b, int a){
    float r1, r2;

    r1 = (-b + sqrt(valorD))/(2*a);

    r2 = (-b - sqrt(valorD))/(2*a);

    printf("r1 = %.2f r2 = %.2f", r1, r2);
}

int main (){

    int a, b, c;
    float valorD;

    printf("Valor de a: ");
    scanf("%d", &a);
    printf("Valor de b: ");
    scanf("%d", &b);
    printf("Valor de c: ");
    scanf("%d", &c);
    
    valorD = delta(a,b,c);
    raizes(valorD, b, a);

    return 0;
}