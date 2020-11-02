#include <stdio.h>
#include "pilhaDin.h"

int main(){

    Pilha* pilha = create_pilha(); // criacao da pilha

    // Verifica se a pilha esta vazia

    printf("%s\n", pilha_empty(pilha) ? "Pilha vazia" : "Pilha ocupada");
    
    // Adicionando elementos na pilha

    pilha_push(pilha, 5);
    pilha_push(pilha, 7);
    pilha_push(pilha, 18);
    pilha_push(pilha, 12);
    pilha_push(pilha, 9);
    pilha_push(pilha, 52);
    pilha_push(pilha, 78);
    pilha_push(pilha, 21);

    // Imprimindo a pilha
    printf("\n");
    printf("Imprimindo pilha apos adicao de elementos: \n");
    pilha_print(pilha);
    printf("\n");

    // Removendo elemento

    pilha_pop(pilha);
    pilha_pop(pilha);
    pilha_pop(pilha);

    // Imprimindo a pilha
    printf("\n");
    printf("Imprimindo pilha apos remocao de elementos: \n");
    pilha_print(pilha);
    printf("\n");

    // Tamanho da pilha
    printf("\n");
    printf("Tamanho da pilha: %d \n", pilha_size(pilha));

    // Libera pilha 

    libera_pilha(pilha);

    return 0;
}