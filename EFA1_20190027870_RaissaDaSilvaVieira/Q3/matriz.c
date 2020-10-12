#include <stdlib.h>
#include <stdio.h>
#include "matriz.h"

typedef struct elemento {
    float v;
    int col;
    struct elemento* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct MATRIZ {
    PONT* a_linhas; // Ponteiro para as linhas da matriz 
    int n_linhas;
    int n_colunas;
} MATRIZ;

/*
    OBS:
        AS FUNCOES QUE SOLICITAM AO USUARIO A LINHA E A COLUNA COMO PARAMETRO A SER ENVIADO
        FORAM ADPTADAS PARA QUE OS VALORES ENVIADOS SEJAM OS CORRESPONDENTES E NAO UM A MAIS
        COMO OCORRE COM OS INDICES DAS MATRIZES.

        POR ISSO EM ALGUNS LUGARES VAI ESTA PRESENTE EXPRESSOES COMO:
            lin-1
            col-1
            ...
*/

MATRIZ * cria_matriz(int n_linhas, int n_colunas){
    //Inicializacao da matriz com os valores enviados

    MATRIZ *mat = (MATRIZ*) malloc(sizeof(MATRIZ));
    mat->a_linhas = (PONT*) malloc(n_linhas*sizeof(PONT));

    if(mat){
        mat->n_linhas = n_linhas;
        mat->n_colunas = n_colunas;
        for (int i=0; i < n_linhas; i++) // Pecorre todas as linhas para inicializa-las com valor NULL
            mat->a_linhas[i] = NULL;
    }

    return mat;
}

void libera_matriz(MATRIZ * mat){
    free(mat); // Libera a matriz
}

int atribui_elemento(MATRIZ * mat, int lin, int col, float v){
    if (lin-1<0 || lin-1 >= mat->n_linhas || col-1<0 || col-1 >= mat->n_colunas) // Verifica se os valores repassados corresponde ao tamanho da matriz criada
        return 0;

    PONT ant = NULL;
    PONT atual = mat->a_linhas[lin-1]; // Seleciona a linha correspondente a enviada como parametro

    while (atual != NULL && atual->col < col-1) { // Pecorre os elementos ate o valor da coluna correspondente ser igual ao do parametro enviado
        ant = atual;
        atual = atual->prox;
    }

    if (atual != NULL && atual->col == col-1) { // Entra nesse if se o elemento onde quer add for diferente de NULL
        // Tratamento para valor igual a 0 que nao precisa ser alocado na memoria
        if (v == 0) { 
            if (ant==NULL)
                mat->a_linhas[lin-1] = atual->prox;
            else 
                ant->prox = atual->prox;

            free(atual); // Libera o espaco do elemento
        }
        else // Se o valor de v nao for 0, faz a atribuicao
            atual->v = v;
    }

    else if (v != 0) {
        PONT novo = (PONT) malloc(sizeof(ELEMENTO)); // Armazena espaco pro novo elemento
        
        // Atribui os valores as variaveis correspondentes
        novo->col = col-1;
        novo->v = v;
        novo->prox = atual;

        // Adiciona o elemento dependendo do valor do anterior a posicao desejada
        if (ant == NULL) 
            mat->a_linhas[lin-1] = novo;

        else 
            ant->prox = novo;
    }
    return 1; // Retorna 1 pra dizer que foi add
}

float acessar_elemento(MATRIZ* mat, int lin, int col) {
    if (lin-1 < 0 || lin-1 >= mat->n_linhas || col-1 < 0 || col-1 >= mat->n_colunas) // Se o valor que foi repassado para a linha ou coluna nao corresponder a matriz retorna 0
        return 0;

    PONT atual = mat->a_linhas[lin-1]; // Seleciona a linha correspondente a enviada como parametro

    while (atual != NULL && atual->col < col-1) // Pecorre os elementos ate a coluna ser igual ao do paramento enviado
        atual = atual->prox;
    
    if (atual !=NULL && atual->col == col-1) // Verifica se eh o elemento que quer acessar 
        return atual->v; // Retorna o valor do elemento
    
    return 0;
}

int remover_elemento(MATRIZ * mat, int lin, int col){
    if (lin-1 < 0 || lin-1 >= mat->n_linhas || col-1 < 0 || col-1 >= mat->n_colunas) // Se o valor que foi repassado para a linha ou coluna nao corresponder a matriz retorna 0
        return 0;

    PONT atual = mat->a_linhas[lin-1]; // Seleciona a linha correspondente a enviada como parametro

    while (atual != NULL && atual->col < col-1) // Pecorre os elementos ate a coluna ser igual ao do paramento enviado
        atual = atual->prox;
    
    if (atual != NULL && atual->col == col-1) // Verifica se eh o elemento que quer excluir 
    {
        free(atual); // Libera o espaco de memoria do mesmo
        return 1;
    }
    
    return 0;
}

void print_matriz(MATRIZ * mat){
    int total_linhas = mat->n_linhas;
	int total_colunas = mat->n_colunas;
		
    for(int i = 0; i < total_linhas; i++) // Pecorre todas as linhas
	{
		for(int j = 0; j < total_colunas; j++) // Pecorre todas as colunas da linha correspondente
		{
			printf("%.2f  ", acessar_elemento(mat,i+1,j+1)); // Mostra o valor naquela posicao
		}
			printf("\n");
	}
}

