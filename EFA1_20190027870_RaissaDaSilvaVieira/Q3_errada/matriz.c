#include <stdlib.h>
#include <stdio.h>
#include "matriz.h"

typedef struct LINHA {
    int col;
    int lin;
    float  v;
    struct LINHA * prox; 
} LINHA;

typedef LINHA* PONT;

typedef struct{
    PONT* a_linhas; //Ponteiro para as listas ligadas
    int n_linhas;
    int n_colunas;
}MATRIZ_ESPARSA;

MATRIZ_ESPARSA * cria_MATRIZ_ESPARSA(int n_linhas, int n_colunas){
    MATRIZ_ESPARSA *mat = (MATRIZ_ESPARSA*) malloc(sizeof(MATRIZ_ESPARSA));
    mat->a_linhas = (LINHA*) malloc(sizeof(LINHA));

    if(mat){
        mat->n_linhas = n_linhas;
        mat->n_colunas = n_colunas;
        for (int i=0; i < n_linhas; i++) 
            mat->a_linhas[i] = NULL;
    }

    return mat;
}

void libera_MATRIZ_ESPARSA(MATRIZ_ESPARSA * mat){
    free(mat);
}

float acessa_MATRIZ_ESPARSA(MATRIZ_ESPARSA * mat, int lin, int col){
    LINHA* x = mat->n_linhas;

    while (x->prox != NULL){
        if(x->lin == lin & x->col == col){
            return x->v;
        }
        x = x->prox;
    }
}

int atribui_elemento(MATRIZ_ESPARSA * mat, int lin, int col, float v){
    if (lin<0 || lin >= mat->n_linhas || col<0 || col >= mat->n_colunas) 
        return 0;

    PONT ant = NULL;
    PONT atual = mat->a_linhas[lin];

    while (atual != NULL && atual->col < col) {
        ant = atual;
        atual = atual->prox;
    }

    if (atual != NULL && atual->col == col) {
        if (v == 0) {
            if (ant==NULL) 
                mat->a_linhas[lin] = atual->prox;
            else 
                ant->prox = atual->prox;
            free(atual);
        }
        else 
            atual->v = v;
    }

    else if (v != 0) {
        PONT novo = (PONT) malloc(sizeof(LINHA));
        
        novo->col = col;
        novo->v = v;
        novo->prox = atual;

        if (ant == NULL) 
            mat->a_linhas[lin] = novo;

        else 
            ant->prox = novo;
    }
    return 1;
}

int remover_elemento(MATRIZ_ESPARSA * mat, int i, int j){
    //mat->v[i*mat->col+j] = 0;
}

void exibir_MATRIZ_ESPARSA(MATRIZ_ESPARSA * mat){

}