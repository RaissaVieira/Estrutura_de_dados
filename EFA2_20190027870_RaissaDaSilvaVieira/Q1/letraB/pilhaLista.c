#include <stdio.h>
#include <stdlib.h>
#include "pilhaLista.h"

struct listano {
    float valor;
    ListaNo* prox;
};

struct p{
    ListaNo* prim;
};

Pilha* create_pilha()
{
    /* 
        Criacao da pilha
    */

    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));

    if(pilha)
        pilha->prim = NULL; // inicializa a pillha como vazia

    return pilha;
}

void pilha_push(Pilha* pilha, float v)
{
    /*
        Adicao de elementos na pilha
    */

    ListaNo* elemento = (ListaNo*) malloc(sizeof(ListaNo)); // alocacao de memoria do elemento a ser add

    if(elemento){
        elemento->valor = v; // recebe o valor enviado como parametro
        elemento->prox = pilha->prim; // recebe como valor de proximo o atual topo da pilha
        pilha->prim = elemento; // Topo recebe elemento criado
    }
}

float pilha_pop(Pilha* pilha)
{
    /*
        Remocao de elementos do topo
    */

    ListaNo* remover = pilha->prim; // cria-se uma variavel para armazenar o elemento para remover
    float v = remover->valor; // armazena o valor dele em uma variavel
    pilha->prim = remover->prox; // o topo recebe o proximo elemento do que sera removido
    free(remover); // libera o espaco do elemento removido

    return v; // retorna o valor do elemento removido
}

int pilha_empty(Pilha* pilha)
{
     /* 
        Verifica se a pilha esta vazia
        
        retorna 0 se estiver ocupada
        retorna 1 se estiver vazia
    */

   return (pilha->prim == NULL );
}

void libera_pilha(Pilha* pilha)
{
    /*
        Libera o espaco de memoria alocado
    */

    ListaNo* primeiro = pilha->prim; // recebe o valor do topo

    while (primeiro != NULL) { // Enquanto o topo for diferente de NULL pecorre a lista
        ListaNo* elemento = primeiro->prox; // recebe o valor do prox antes de liberar a memoria
        free(primeiro); // libera o espaco alocado para o elemento
        primeiro = elemento;
    }

    free(pilha); // libera a memoria da pilha
}

int pilha_size(Pilha* pilha)
{
    int counter = 0;

    ListaNo* elemento=pilha->prim;

    while (elemento != NULL) // Pecorre o conjunto e incrementa o contador
    {
        counter++; 
        elemento=elemento->prox;
    }
    
    return counter; // Retorna o total de elementos
}

void pilha_print(Pilha* pilha)
{
    for (ListaNo* elemento=pilha->prim; elemento != NULL; elemento=elemento->prox)
        printf("%.2f ",elemento->valor);
}

