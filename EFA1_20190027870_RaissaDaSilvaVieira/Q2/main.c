#include <stdio.h>
#include "conjunto.h"

int main(){

    Conjunto *conj1=NULL, *conj2 = criar_conj_vazio();
    Conjunto *conj3;

    printf("%i a\n", size(conj1));
    printf("%i a\n", conj_vazio(conj1));
    printf("%i a\n", inserir(&conj1,0,5));
    printf("%i a\n", inserir(&conj1,1,8));
    printf("%i a\n", inserir(&conj1,2,3));
    printf("%i a\n", inserir(&conj1,3,6));
    printf("%i a\n", inserir(&conj1,4,2));
    printf("%i a\n", inserir(&conj1,5,9));
    printf("%i a\n", inserir(&conj1,6,7));

    printf("%i a\n", inserir(&conj2,0,15));
    printf("%i a\n", inserir(&conj2,1,8));
    printf("%i a\n", inserir(&conj2,2,13));
    printf("%i a\n", inserir(&conj2,3,6));
    printf("%i a\n", inserir(&conj2,4,12));
    printf("%i a\n", inserir(&conj2,5,19));
    printf("%i a\n", inserir(&conj2,6,17));

    conj3 = interseccao(conj1, conj2);
    print(conj3);
    printf("%i\n", size(conj3));

    return 0;
}