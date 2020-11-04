#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash2.h"

struct pessoa
{
    long int cpf;
    char nome[50];
    int idade;
    char sexo[10];
};

struct hash {
    int n; // numero de elementos inseridos
    int dim; // dimensao da tabela
    Pessoa** p;
};

static int hash (long int cpf, Hash* tabela)
{
    return ((tabela->dim - 2) - cpf % (tabela->dim - 2)); // criacao do hash
}

Pessoa* create_pessoa(long int cpf, char *nome, int idade, char *sexo)
{
    /* 
        Metodo para a criacao de uma pessoa a partir dos dados enviados como 
        parametros
    */

    Pessoa* pessoa = (Pessoa*) malloc(sizeof(Pessoa));

    if (pessoa)
    {
        pessoa->cpf = cpf;
        strcpy(pessoa->nome, nome);
        pessoa->idade = idade;
        strcpy(pessoa->sexo, sexo);
    }

    return pessoa;    
}

Hash* create_hash()
{
    /* 
        Criacao do Hashmap
    */

    Hash* tabela = (Hash*) malloc(sizeof(Hash));
    
    if(tabela)
    {
        tabela->n = 0; // inicia o numero de elementos com 0
        tabela->dim = 3; // denomina uma dimensao inicial qualquer
        tabela->p = (Pessoa**) malloc(tabela->dim*sizeof(Pessoa*));
        for (int i=0; i < tabela->dim; i++){
            tabela->p[i] = NULL; // pecorre a tabela e incia todas as pessoas com NULL
        }
    }
    
    return tabela;
}

static void redimensiona (Hash* tabela)
{
    /* 
        Funcao que ira ser chamada quando a capacidade de cadastro 
        for totalmente ocupada 
    */

    int dim = tabela->dim; // armazena a dimensao da tabela
    Pessoa** ant = tabela->p; // armazena todas as pessoas inseridas na tabela
    
    // Redimensiona a tabela e reinicia a quantidade de elementos com 0
    tabela->n = 0;
    tabela->dim *= 1.765;
    tabela->p = (Pessoa**) malloc(tabela->dim * sizeof(Pessoa*)); 

    for (int i=0; i < tabela->dim; ++i)
        tabela->p[i] = NULL; // pecorre a tabela e incia todas as pessoas com NULL

    for (int i=0; i < dim; ++i)  
    {
        /* 
            varre o array "ant" com as pessoas cadastradas e 
            inserem-as na tabela com a dimensao atualizada  
        */

        if (ant[i]) 
            insert_hash(tabela, ant[i]);
    }

    free(ant); // apaga o array com os dados anteriores
}

Pessoa* insert_hash(Hash* tabela, Pessoa* pessoa)
{
    /*
        Adicao de elementos na tabela
    */

    if (tabela->n > 0.75* tabela->dim) // verfica se a dimensao da tabela para
        redimensiona(tabela);          // redimensionar caso seja necessario

    int h = hash(pessoa->cpf, tabela); // chama a funcao de criacao do hash 

    while(tabela->p[h] != NULL)
    {
        // busca a primeira posição livre a partir do índice mapeado
        h = (h+1) % tabela->dim; 
    }

    tabela->p[h] = pessoa; // adiciona a pessoa
    tabela->n++; // incrementa na quantidade de elementos

    return pessoa;
}

void printfnome(Pessoa* pessoa)
{
    /*
        Funcao para imprimir os dados da pessoa
    */

    printf("Nome: %s\n", pessoa->nome);
    printf("CPF: %ld\n", pessoa->cpf);
    printf("Idade: %i\n", pessoa->idade);
    printf("Sexo: %s\n", pessoa->sexo);
}

Pessoa* search_hash(Hash* tabela, long int cpf){

    /* 
        Busca o elemento na tabela 
    */

    int h = hash(cpf, tabela); // calcula o hash

    while (tabela->p[h] != NULL) { // Pecorre a tabela a fim de encontrar o elemento
                                   // correspondente
        if (tabela->p[h]->cpf == cpf)
            return tabela->p[h]; // retorna se encontrar
        
        h = (h+1) % tabela->dim;
    }

    return NULL; // retorna NULL caso nao encontre
}

int remove_hash(Hash* tabela, long int cpf)
{
    /*
        Remocao de elemento a partir do cpf
    */

    int h = hash(cpf, tabela); // calcula o hash

    while (tabela->p[h] != NULL) {
        /* 
            Pecorre a tabela a fim de encontrar o elemento
            correspondente 
        */

        if (tabela->p[h]->cpf == cpf) // se encontrar, libera o elemento e retorna 1
        {
            free(tabela->p[h]);
            return 1;
        }
        
        h = (h+1) % tabela->dim;
    }

    return 0; // retorna 0 caso nao encontre
}