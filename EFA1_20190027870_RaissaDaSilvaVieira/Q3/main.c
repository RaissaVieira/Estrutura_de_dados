#include <stdio.h>
#include "matriz.h"

int main(){

    MATRIZ *matriz = cria_matriz(10,5); // Cria matriz com o total de 10 linhas e 5 colunas

    // Adicionando elemento a matriz 
    
    /* 
        A funcao adicionar foi adptada para a coluna e a linha que for enviada como paramento ser a
        correspondente na matriz. E nao ser uma a mais.  
    */

    printf("\n");
    printf("%s\n", atribui_elemento(matriz,3,1,8) ? "Adicionado" : "Linha ou coluna inexistente");
    printf("%s\n", atribui_elemento(matriz,5,2,5) ? "Adicionado" : "Linha ou coluna inexistente");
    printf("%s\n", atribui_elemento(matriz,10,3,7) ? "Adicionado" : "Linha ou coluna inexistente");
    printf("%s\n", atribui_elemento(matriz,8,4,3) ? "Adicionado" : "Linha ou coluna inexistente");
    printf("%s\n", atribui_elemento(matriz,13,1,6) ? "Adicionado" : "Linha ou coluna inexistente");

    // Exibir matriz

    printf("\n");
    print_matriz(matriz);

    // Acessar elemento

    printf("\n");
    printf("Elemento da posicao: %.2f\n", acessar_elemento(matriz,8,4));
    printf("Elemento da posicao: %.2f\n", acessar_elemento(matriz,10,4));
    printf("Elemento da posicao: %.2f\n", acessar_elemento(matriz,3,1));

    // Remover elemento

    printf("\n");
    printf("%s\n", remover_elemento(matriz,3,1) ? "Removido" : "Linha ou coluna inexistente");
    printf("%s\n", remover_elemento(matriz,10,3) ? "Removido" : "Linha ou coluna inexistente");
    printf("%s\n", remover_elemento(matriz,13,1) ? "Removido" : "Linha ou coluna inexistente");

    printf("\n");
    print_matriz(matriz);

    // Libera matriz

    libera_matriz(matriz);

    return 0;
}