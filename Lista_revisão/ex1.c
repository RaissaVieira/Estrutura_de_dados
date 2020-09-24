#include <stdio.h>

int main (){
    float refri = 1.5, pizza = 3.0, taxa = 0.1, total;
    int qRef, qPiz, qPes;

    printf("Quantidade de refrigerante: ");
    scanf("%d", &qRef);
    printf("Quantidade de pizza: ");
    scanf("%d", &qPiz);
    printf("Quantidade de pessoas na mesa: ");
    scanf("%d", &qPes);

    total = qPiz*pizza + qRef*refri;

    printf("Total = %.2f \nTotal com taxa = %.2f \nDivisao pelo grupo = %.2f\n", total, (total+total*taxa), (total+total*taxa)/qPes);

    return 0;
}