#include <stdio.h>
#include "matriz.h"

int main(){

    MATRIZ_ESPARSA *m = cria_MATRIZ_ESPARSA(2,2);

    printf("%i", atribui_elemento(m,1,1,2));
    //printf("%f", acessa_MATRIZ_ESPARSA(m,1,1));

    return 0;
}


