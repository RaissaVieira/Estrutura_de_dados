#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct elemento ELEMENTO;
typedef struct MATRIZ MATRIZ;

MATRIZ * cria_matriz(int n_linhas, int n_colunas);
void libera_matriz(MATRIZ * mat);
float acessar_elemento(MATRIZ * mat, int lin, int col);
int atribui_elemento(MATRIZ * mat, int lin, int col, float v);
int remover_elemento(MATRIZ * mat, int lin, int col);
void print_matriz(MATRIZ * mat);

#endif