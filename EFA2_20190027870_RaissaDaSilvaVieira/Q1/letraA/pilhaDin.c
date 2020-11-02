#include <stdio.h>
#include <stdlib.h>
#include "pilhaDin.h"

struct p {
    int n; // quantidade de elementos
    int dim; // dimensao do vetor, que pode variar
    float * vet; // vetor dos elementos
};

Pilha* create_pilha()
{
    /* 
        Criacao da pilha
    */

    Pilha* pilha = (Pilha*) malloc(sizeof (Pilha));

    if(pilha)
    {
        pilha->dim = 5; // denomina uma dimensao inicial qualquer
        pilha->vet = (float *) malloc(pilha->dim*sizeof(float));
        pilha->n = 0; // inicia a pilha com 0 elementos
    }

    return pilha; // retorna a pilha
}

void pilha_push(Pilha* pilha, float v) 
{
    /*
        Adicao de elementos na pilha
    */

    if (pilha->n == pilha-> dim) { 

        /* 
            Verifica se a quantidade de elementos existentes na pilha eh do tamanho da
            dimensao, se for deve alocar mais espaco de memoria 
        */

        pilha->dim *= 2; // dimensao eh dobrada
        pilha->vet = (float *) realloc(pilha->vet, pilha-> dim*sizeof (float)); // armazena o espaco na memoria
    }

    pilha-> vet[pilha->n++] = v; // insersao do elemento na proxima prosicao livre
                                 // apos a insersao incrementa-se o numero de elementos
}

float pilha_pop(Pilha* pilha)
{
    /*
        Remocao de elementos do topo
    */

    float v = pilha->vet[--pilha->n]; // decrementa o numero de elementos antes de acessar o vetor

    return v; // retorna o valor de inicio da pilha apos a remocao
}

int pilha_empty(Pilha* pilha)
{
    /* 
        Verifica se a pilha esta vazia
        
        retorna 0 se estiver ocupada
        retorna 1 se estiver vazia
    */
    
    return (pilha->n == 0);
}

void libera_pilha(Pilha* pilha)
{
    /*
        Libera o espaco de memoria alocado
    */

    free(pilha->vet);
    free(pilha);
}

int pilha_size(Pilha* pilha)
{
    /*
        Retorna a quantidade de elementos da pilha
    */
    return pilha->n;
}

void pilha_print (Pilha* pilha)
{
    /*
        Imprime os elementos da pilha
    */

    for (int i=pilha->n-1; i>=0; i--)
        printf("%.2f ",pilha->vet[i]);
}