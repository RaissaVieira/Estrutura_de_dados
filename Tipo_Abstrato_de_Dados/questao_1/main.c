#include <stdio.h>
#include "matriz.h"

int main(){

    Matriz *m = cria_matriz(2,2);

    printf("%i", atribui_matriz(m,1,1,2));
    printf("%i", acessa_matriz(m,1,1));
    printf("%i", nlinhas(m));
    printf("%i", ncolunas(m));

    return 0;
}


