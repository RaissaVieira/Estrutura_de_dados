#include <stdio.h>
#include "matriz.h"

int main(){

    MATRIZ *m = cria_matriz(2,2);

    printf("%i\n", atribui_elemento(m,1,1,2));
    printf("%i\n", atribui_elemento(m,0,1,5));


    printf("%.f\n", acessar_elemento(m,2,2));
    printf("%.f\n", acessar_elemento(m,1,2));


    return 0;
}