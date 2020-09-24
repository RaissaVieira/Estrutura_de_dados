#include <stdio.h>
#include <math.h>

int main() {

    int x,cont,resto;
    double raiz;
    
    scanf("%d", &x);

    resto = 0;
    raiz = sqrt(x);
    for (cont = 2; cont < raiz; cont++){
        if (x % cont == 0)
            resto += 1;

    }
    if (resto == 0)
        printf("Prime\n");
    else
        printf("Not Prime\n");
   
    return 0;
}