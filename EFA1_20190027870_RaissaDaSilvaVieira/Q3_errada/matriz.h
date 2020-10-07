#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct MATRIZ_ESPARSA MATRIZ_ESPARSA;

MATRIZ_ESPARSA * cria_MATRIZ_ESPARSA(int n_linhas, int n_colunas);
void libera_MATRIZ_ESPARSA(MATRIZ_ESPARSA * mat);
float acessa_MATRIZ_ESPARSA(MATRIZ_ESPARSA * mat, int lin, int col);
int atribui_elemento(MATRIZ_ESPARSA * mat, int lin, int col, float v);
int remover_elemento(MATRIZ_ESPARSA * mat, int i, int j);
void exibir_MATRIZ_ESPARSA(MATRIZ_ESPARSA * mat);

#endif