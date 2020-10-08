#include <stdlib.h>
#include <stdio.h>
#include "conjunto.h"

struct conjunto{
    int valor;
    struct conjunto* prox;
};

Conjunto * create_elemento(int v){
    //Criacao do elemento a ser add, com o valor = v (parametro recebido)

    Conjunto * l = (Conjunto*) malloc(sizeof(Conjunto));
    if (l)
    {
        l->valor = v;
        l->prox = NULL;
    }
}

Conjunto * criar_conj_vazio(){
    // A criacao do conjunto vazio ocorre quando ele eh igual a NULL

    Conjunto * l = (Conjunto*) malloc(sizeof(Conjunto));
    if (l)
    {
        l = NULL; // Atribuicao ao conjunto
    }

    return l;
}

int inserir(Conjunto **l1, int v){
    /*
        A insercao do elemento em um conjunto so ocorre se ele nao pertencer ao conjunto,
        uma vez que nao pode existir elementos repetidos.  

        No caso, dessa funcao a insercao ocorre no inicio.  
    */


    Conjunto * aux = create_elemento(v); // Criacao do elemento a ser add

    if(pertence(*l1,v)) // Verifica se o elemento ja existe no conjunto e retorna 0, porque nao eh add
        return 0;
    
    if(aux) 
    {
        aux->prox = *l1; // Valor prox do elemento criado recebe o conjunto que ja existia
        *l1 = aux; // aux entao eh add no inicio

        return 1; // Retorna 1 como sucesso
    }

    return 0;
}

int remover(Conjunto **l1, int v){
    Conjunto * ante = NULL;
    Conjunto * aux = *l1;
    int found = 0;

    while (aux != NULL) // Pecorre o conjunto aux a fim de procurar o valor que deseja remover
    {
        if (aux->valor == v) // Se for encontrado a variavel found = 1 
        {
            found = 1;
            break;
        }

        ante = aux;
        aux = aux->prox; 
    }
    
    if(found){ // Se o valor foi encontrado, entra nessa condicao
        if (ante == NULL) // Se entrar aqui, eh porque o valor escolhido eh o primeiro elemento
        {
            *l1 = aux->prox; // O conjunto deve receber o prox como valor de inicio
            free(aux); // Libera a memoria do valor escolhido
            return 1;
        }

        ante->prox = aux->prox; // O elemento posterior ao escolhido para remocao passa a ser o prox do antecessor 
        free(aux); // Libera a memoria do valor escolhido
        return 1;        
    }

    return 0; // retorna 0 se o elemento nao foi encontrado
}

Conjunto * uniao(Conjunto **l1, Conjunto **l2){

    Conjunto * C = criar_conj_vazio(); // Criacao do conjunto vazio que sera retornado 

    Conjunto * aux1 = *l1; // Criacao da copia do conjunto l1
    Conjunto * aux2 = *l2; // Criacao da copia do conjunto l2


    while (aux1 != NULL) //Pecorre o conjunto aux1 
    {
        inserir(&C, aux1->valor); // Insere o valor em C

        aux1 = aux1->prox;
        
    }

    while (aux2 != NULL) //Pecorre o conjunto aux2 
    {
        inserir(&C, aux2->valor); // Insere o valor em C

        aux2 = aux2->prox;
    }

    /* 
        OBS: Na funcao inserir() ja existe um mecanismo que vizualiza se o 
        valor ja pertence ao conjunto, portanto o tramento em relacao a isso eh feito na funcao.
    */
    
    return C; // Retorna C      

}

Conjunto * interseccao(Conjunto **l1, Conjunto **l2){
    Conjunto * C = criar_conj_vazio(); // Criacao do conjunto vazio que sera retornado

    Conjunto * aux1 = *l1; // Criacao da copia do conjunto l1
    Conjunto * aux2 = *l2; // Criacao da copia do conjunto l2

    /*
        Para que nao pecorra muitos elementos desnecessarios, vizualiza o tamanho 
        e assim pega o de menor valor.
    */

    if (size(*l1) <= size(*l2)) // Se l1 for menor ou igual que l2
    {
        while (aux1 != NULL) // Pecorre o conjunto
        {
            if (pertence(aux2, aux1->valor)) // Se pertencer a ambos add em C
            {
                inserir(&C, aux1->valor);
            }

            aux1 = aux1->prox;
            
        }

        return C;        
    }
    else // Se l1 for menor que l2
    {
        while (aux2 != NULL) // Pecorre o conjunto
        {
            if (pertence(aux1, aux2->valor)) // Se pertencer a ambos, add em C
            {
                inserir(&C, aux2->valor);
            }

            aux2 = aux2->prox;
        }
        
        return C;    
    }
      
}

Conjunto * diferenca(Conjunto **l1, Conjunto **l2){
    /*
        A funcao diferenca deve pecorrer o primeiro conjunto e analisar quais 
        elementos nao pertencem ao segundo.
    */

    Conjunto * C = criar_conj_vazio(); // Criacao do conjunto vazio que sera retornado

    Conjunto * aux1 = *l1; // Criacao da copia do conjunto l1
    Conjunto * aux2 = *l2; // Criacao da copia do conjunto l2

    while (aux1 != NULL) // Pecorre o conjunto
    {
        if (!pertence(aux2, aux1->valor)) // Se nao pertencer ao segundo, add em C
        {
            inserir(&C, aux1->valor);
        }

        aux1 = aux1->prox;
        
    }

    return C; // Retorna C    
}

int pertence(Conjunto *l1, int v){
    if (conj_vazio(l1)) // Se l1 for vazio retorna 0
        return 0;
    
    while (l1 != NULL) // Pecorre o conjunto
    {
        if (l1->valor == v) // Se o elemento pertence ao conjunto, retorna 1 (verdadeiro)
            return 1;
        
        l1 = l1->prox;   
    }

    return 0;
}

int menor(Conjunto *l1){
    int menor = maior(l1); // Inicia o valor de menor com o maior valor do conjunto

    while (l1 != NULL) // Pecorre o conjunto
    {
        if(l1->valor < menor) // Se o valor correspondente for menor, ele eh atribuido a variavel
            menor = l1->valor;

        l1 = l1->prox;
    }

    return menor; // Ao final de pecorrer o conjunto todo, retornar o menor valor
}

int maior(Conjunto *l1){
    int maior = menor(l1); // Inicia o valor de maior com o menor valor do conjunto

    while (l1 != NULL) // Pecorre o conjunto
    {
        if(l1->valor > maior) // Se o valor correspondente for maior, ele eh atribuido a variavel
            maior = l1->valor;

        l1 = l1->prox;
    }

    return maior; // Ao final de pecorrer o conjunto todo, retornar o maior valor
}

int iguais(Conjunto *l1, Conjunto *l2){
    /*
        Verifica se o valor da interseccao entre os dois conjuntos eh igual.
        Se for, quer dizer que os valores estao presentes nos dois conjuntos.
    */

    if(size(interseccao(&l1, &l2)) == size(l1) && size(interseccao(&l1, &l2)) == size(l2))
        return 1;
    
    return 0;
}

int size(Conjunto *l1){ // Verifica tamanho do conjunto
    int counter = 0;

    while (l1 != NULL) // Pecorre o conjunto e incrementa o contador
    {
        counter++; 
        l1 = l1->prox;

    }
    
    return counter; // Retorna o total de elementos
}

int conj_vazio(Conjunto *l){
    return (l == NULL); // Se o conjunto l eh vazio retorna 1
}

void print(Conjunto *l1){
    while (l1 != NULL) // Pecorre todo o conjunto e mostra os elementos
    {
        printf("%i ", l1->valor);
        l1 = l1->prox;
    }
}