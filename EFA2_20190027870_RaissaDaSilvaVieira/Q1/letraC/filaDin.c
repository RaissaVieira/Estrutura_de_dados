#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "filaDin.h"

struct f {
    int n; // numero de elementos da fila
    int ini; // indice do topo da fila
    int dim; // dimensao do vetor, que pode variar
    float * vet; // vetor dos elementos
};

Fila* create_fila ()
{
    Fila* fila = (Fila*) malloc( sizeof(Fila));

    if(fila){
        fila->dim = 5; // denomina uma dimensao inicial qualquer
        fila->vet = (float*) malloc(fila->dim*sizeof(float));
        fila->n = 0; // inicia a fila com 0 elementos
        fila->ini = 0; // escolha da posicao inicial
    }

    return fila; // retorna a fila
}

void fila_insert (Fila* fila, float valor)
{
    /*
        Adicao de elementos na fila, 
        na próxima posição livre do vetor, indicada por fim
    */

    int fim;

    if (fila->n == fila->dim) { 

        /* 
            Verifica se a quantidade de elementos existentes na fila eh do tamanho da
            dimensao, se for, deve alocar mais espaco de memoria 
        */

        fila->dim *= 2; // dimensao eh dobrada
        fila->vet = (float *) realloc(fila->vet, fila-> dim*sizeof(float)); // realoca o espaco na memoria

        if (fila->ini != 0) 

            /* 
                Se o valor da posicao do primeiro elemento for diferente de 0, usa-se o memmove que
                copia os valores de n bytes do local apontado pela origem para o bloco de memória apontado pelo destino. 

                void * memmove (void * destino, const void * fonte, size_t n);
            */
    
            memmove(&fila->vet[fila->dim - fila->ini], &fila->vet[fila->ini], (fila->n - fila->ini)*sizeof(float));
    }

    fim = (fila->ini + fila->n) % fila->dim;  
    fila->vet[fim] = valor; // insere o valor na ultima posicao
    fila->n++; // incrementa em 1 a quantidade de elementos da lista
}

int fila_remove (Fila* fila)
{
    /*
        Remocao de elementos do topo
    */

    if(fila_empty(fila))
        return 0; // se a fila eh vazia retorna 0
    
    fila->ini = (fila->ini + 1) % fila->dim; // remocao do primeiro elemento da fila
    fila->n--; // decrementa na quantidade de elementos da fila
    
    return 1; // retorna 1 se o elemento foi removido
}

int fila_empty (Fila* fila)
{
    /* 
        Verifica se a fila esta vazia
        
        retorna 0 se estiver ocupada
        retorna 1 se estiver vazia
    */
    return (fila->n == 0);
}

void libera_fila (Fila* fila)
{
    /*
        Libera o espaco de memoria alocado
    */ 

    free(fila-> vet);
    free(fila);
}

int fila_size(Fila* fila)
{
    /*
        Retorna a quantidade de elementos da fila
    */

    return fila->n;
}

void print_fila(Fila* fila)
{
    /*
        Imprime os elementos da fila
    */

    for (int i=0; i<fila->n; i++)
        printf("%.2f ", fila->vet[(fila->ini+i)% fila->dim]);
}
