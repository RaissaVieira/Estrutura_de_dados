#include <stdio.h>
#include "filaLista.h"

int main(){

    Fila* fila = create_fila(); // criacao da fila

    // Verifica se a fila esta vazia

    printf("%s\n", fila_empty(fila) ? "fila vazia" : "fila ocupada");
    
    // Adicionando elementos na fila

    fila_insert(fila, 55);
    fila_insert(fila, 27);
    fila_insert(fila, 8);
    fila_insert(fila, 2);
    fila_insert(fila, 39);
    fila_insert(fila, 5);
    fila_insert(fila, 71);
    fila_insert(fila, 40);

    // Imprimindo a fila
    printf("\n");
    printf("Imprimindo fila apos adicao de elementos: \n");
    print_fila(fila);
    printf("\n");

    // Removendo elemento

    fila_remove(fila);
    fila_remove(fila);
    fila_remove(fila);

    // Imprimindo a fila
    printf("\n");
    printf("Imprimindo fila apos remocao de elementos: \n");
    print_fila(fila);
    printf("\n");

    // Tamanho da fila
    printf("\n");
    printf("Tamanho da fila: %d \n", fila_size(fila));

    // Libera fila 

    libera_fila(fila);

    return 0;
}