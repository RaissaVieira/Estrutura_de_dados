#include <stdlib.h>
#include <stdio.h>
#include "matriz.h"

typedef struct tempNo {
    float v;
    int col;
    struct tempNo* prox;
} NO;

typedef NO* PONT;

typedef struct {
    PONT* a_linhas;
    int n_linhas;
    int n_colunas;
} MATRIZ;

MATRIZ * cria_matriz(int n_linhas, int n_colunas){
    MATRIZ *mat = (MATRIZ*) malloc(sizeof(MATRIZ));
    mat->a_linhas = (PONT*) malloc(n_linhas*sizeof(PONT));

    if(mat){
        mat->n_linhas = n_linhas;
        mat->n_colunas = n_colunas;
        for (int i=0; i < n_linhas; i++) 
            mat->a_linhas[i] = NULL;
    }

    return mat;
}

void libera_matriz(MATRIZ * mat){
    free(mat);
}

int atribui_matriz(MATRIZ * mat, int lin, int col, float v){
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
        PONT novo = (PONT) malloc(sizeof(NO));
        
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

float ValorMatriz(MATRIZ* mat, int lin, int col) {
    if (lin<0 || lin>=mat->n_linhas || col<0 || col >= mat->n_colunas) 
        return 0;

    PONT atual = mat->a_linhas[lin];

    while (atual != NULL && atual->col < col)
        atual = atual->prox;
    
    if (atual !=NULL && atual->col == col)
        return atual->v;
    
    return 0;
}
