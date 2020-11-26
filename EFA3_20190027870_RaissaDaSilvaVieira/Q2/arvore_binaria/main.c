#include <stdlib.h>
#include <stdio.h>
#include "arvBi.h"

int main()
{

    Arv *a = arv_cria(
                arv_criano(1,
                        arv_criano(2,
                                    NULL,
                                    arv_criano(4, NULL, NULL)
                        ),
                        arv_criano(3,
                                    arv_criano(8, NULL, NULL), arv_criano(6, NULL, NULL)
                        )

                )
            );

    printf("Quantidade de valores pares: %i\n",pares(a));
    printf("Quantidade de folhas: %i\n",folhas(a));
    printf("Quantidade de nos com filho unico: %i\n",um_filho(a));
}