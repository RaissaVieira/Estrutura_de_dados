#include <stdlib.h>
#include <stdio.h>
#include "arvBiBus.h"

int main()
{

    Arv *a = arv_cria();

    abb_insere(a, 6);
    abb_insere(a, 2);
    abb_insere(a, 8);
    abb_insere(a, 1);
    abb_insere(a, 4);
    abb_insere(a, 3);

    printf("Quantidade de nos folhar com valores maiores: %i\n", nfolhas_maiores(a, 1));
    printf("somatorio dos valores entre x e y: %i\n", soma_xy(a, 8, 1)); // x deve ser maior que y
    printf("Nivel do no do elemento x: %i\n", nivel(a, 4));
}