#include <stdio.h>
#include "filaDin.h"

int main(){

    Fila* fila = create_fila(); // criacao da fila

    // Verifica se a fila esta vazia

    printf("%s\n", fila_empty(fila) ? "fila vazia" : "fila ocupada");
    
    // Adicionando elementos na fila

    fila_insert(fila, 5);
    fila_insert(fila, 7);
    fila_insert(fila, 18);
    fila_insert(fila, 12);
    fila_insert(fila, 9);
    fila_insert(fila, 52);
    fila_insert(fila, 78);
    fila_insert(fila, 21);

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