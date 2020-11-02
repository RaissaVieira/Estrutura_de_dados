#include <stdio.h>
#include <stdlib.h>
#include "filaLista.h"

struct elemento {
    float value;
    Elemento* prox;
};

struct f {
    Elemento* ini;
    Elemento* fim;  
};


Fila* create_fila ()
{
    /* 
        Criacao da pilha
    */

    Fila* fila = (Fila*) malloc( sizeof (Fila));

    if(fila){
        // inicializa o primeiro e o ultimo elemento com NULL

        fila-> ini = NULL; 
        fila-> fim = NULL;
    }

    return fila;
}

void fila_insert (Fila* fila, float valor)
{
    /*
        Adicao de elementos no fim da fila
    */

    Elemento* elemento = (Elemento*) malloc(sizeof (Elemento));

    if(elemento)
    {
        elemento->value = valor; 
        elemento->prox = NULL; 

        if (fila->fim != NULL) // verifica se a lista nao esta vazia
            fila->fim->prox = elemento; // prox elemento do fim da lista recebe o elemento criado

        else
        {
            // entra aqui se a fila estiver fazia

            // primeiro e ultimo elemento serao iguais

            fila->ini = elemento; // primeiro elemento recebe o elemento criado
        } 
            
        fila->fim = elemento; // ultimo elemento recebe o elemento criado
    }
}

int fila_remove (Fila* fila)
{
    /*
        Remocao de elementos do topo
    */

    Elemento* elemento = fila->ini;

    if (elemento)
    {
        fila->ini = elemento->prox; // elemento inicial recebe o proximo elemento

        if (fila->ini == NULL) // se a fila ficou vazia o ultimo elemento tambem deve ser NULL
            fila-> fim = NULL;

        free(elemento); // libera o elemento

        return 1; // retorna 1 se ocorreu tudo bem
    }
    
    return 0; // retorna 0 se deu erro
}

int fila_empty (Fila* fila)
{
    /* 
        Verifica se a pilha esta vazia
        
        retorna 0 se estiver ocupada
        retorna 1 se estiver vazia
    */

   return (fila->ini == NULL);
}

void libera_fila (Fila* fila)
{
    /*
        Libera o espaco de memoria alocado
    */

    Elemento* elemento = fila->ini;

    while (elemento!= NULL) { // Enquanto o topo for diferente de NULL pecorre a lista
        Elemento* aux = elemento->prox;
        free(elemento); // libera o espaco alocado para o elemento
        elemento = aux;
    }

    free(fila); // libera a memoria da pilha
}

int fila_size(Fila* fila)
{
    int counter = 0;

    Elemento* elemento = fila->ini;

    while (elemento != NULL) // Pecorre a pilha e incrementa o contador
    {
        counter++; 
        elemento=elemento->prox;
    }
    
    return counter;
}

void print_fila(Fila* fila)
{
    /*
        Imprime os elementos da fila
    */
   
    for (Elemento* elemento=fila->ini; elemento != NULL; elemento=elemento->prox)
        printf("%.2f ",elemento->value);
}
