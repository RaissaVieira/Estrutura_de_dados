#include <stdlib.h>
#include <stdio.h>
#include "matriz.h"

struct matriz{
    int lin;
    int col;
    float * v;
};

Matriz * cria_matriz(int nl, int nc){
    Matriz *mat = (Matriz*) malloc(sizeof (Matriz));

    if(mat){
        mat->lin = nl;
        mat->col = nc;
        mat->v = (float*) malloc (nl*nc*sizeof(float));
    }

    return mat;
}

void libera_matriz(Matriz * mat){
    free(mat);
}

int acessa_matriz(Matriz * mat, int i, int j){
    int aux;

    aux = (i) * mat->col + (j);

    return mat->v[aux];
}

int atribui_matriz(Matriz * mat, int i, int j, float  v){
    int aux;

    aux = (i) * mat->col + (j);

    mat->v[aux] = v;

    return 1;
}

int nlinhas(Matriz * mat){
    return mat->lin;
}

int ncolunas(Matriz *mat){
    return mat->col;
}
