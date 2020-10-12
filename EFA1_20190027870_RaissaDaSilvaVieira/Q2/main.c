#include <stdio.h>
#include "conjunto.h"

int main(){

    Conjunto *conj1 = criar_conj_vazio(); // Criando conjunto vazio
    Conjunto *conj2 = criar_conj_vazio(); // Criando conjunto vazio
    Conjunto *conj_uniao; 
    Conjunto *conj_interseccao;
    Conjunto *conj_diferenca;

    // Verificando se os conjuntos 1 e 2 sao vazios

    printf("%s\n", conj_vazio(conj1) ? "Conjunto vazio" : "Conjunto com elemento(s)");
    printf("%s\n", conj_vazio(conj2) ? "Conjunto vazio" : "Conjunto com elemento(s)");

    // Inserindo elementos no conjunto 1

    printf("\n");
    printf("%s\n", inserir(&conj1,8) ? "Valor inserido" : "Valor ja existe no conjunto");
    printf("%s\n", inserir(&conj1,-8) ? "Valor inserido" : "Valor ja existe no conjunto");
    printf("%s\n", inserir(&conj1,3) ? "Valor inserido" : "Valor ja existe no conjunto");
    printf("%s\n", inserir(&conj1,6) ? "Valor inserido" : "Valor ja existe no conjunto");
    printf("%s\n", inserir(&conj1,-2) ? "Valor inserido" : "Valor ja existe no conjunto");
    printf("%s\n", inserir(&conj1,9) ? "Valor inserido" : "Valor ja existe no conjunto");
    printf("%s\n", inserir(&conj1,7) ? "Valor inserido" : "Valor ja existe no conjunto");

    // Inserindo elementos no conjunto 2

    printf("\n");
    printf("%s\n", inserir(&conj2,8) ? "Valor inserido" : "Valor ja existe no conjunto");
    printf("%s\n", inserir(&conj2,8) ? "Valor inserido" : "Valor ja existe no conjunto");
    printf("%s\n", inserir(&conj2,11) ? "Valor inserido" : "Valor ja existe no conjunto");
    printf("%s\n", inserir(&conj2,6) ? "Valor inserido" : "Valor ja existe no conjunto");
    printf("%s\n", inserir(&conj2,-2) ? "Valor inserido" : "Valor ja existe no conjunto");
    printf("%s\n", inserir(&conj2,19) ? "Valor inserido" : "Valor ja existe no conjunto");
    printf("%s\n", inserir(&conj2,7) ? "Valor inserido" : "Valor ja existe no conjunto");
    printf("%s\n", inserir(&conj2,11) ? "Valor inserido" : "Valor ja existe no conjunto");
    printf("%s\n", inserir(&conj2,7) ? "Valor inserido" : "Valor ja existe no conjunto");

    // Printando conjuntos
    printf("\n");
    printf("Conjunto 1: ");
    print(conj1);
    printf("\nConjunto 2: ");
    print(conj2);
    printf("\n");

    // Uniao conjunto 1 e 2 

    printf("\n");
    conj_uniao = uniao(&conj1, &conj2); //chamada da funcao
    printf("Conjunto uniao: ");
    print(conj_uniao); //printando os elementos do conjunto retornado

    // Interseccao conjunto 1 e 2 

    printf("\n");
    conj_interseccao = interseccao(&conj1, &conj2); //chamada da funcao
    printf("Conjunto interseccao: ");
    print(conj_interseccao); //printando os elementos do conjunto retornado

    // Diferenca de conjunto 1 e 2

    printf("\n");
    conj_diferenca = diferenca(&conj1, &conj2); //chamada da funcao
    printf("Conjunto diferenca entre 1 e 2: ");
    print(conj_diferenca); //printando os elementos do conjunto retornado

    // Diferenca de conjunto 2 e 1

    printf("\n");
    conj_diferenca = diferenca(&conj2, &conj1); //chamada da funcao
    printf("Conjunto diferenca entre 2 e 1: ");
    print(conj_diferenca); //printando os elementos do conjunto retornado
    printf("\n");

    // Funcao pertence

    printf("\n");
    printf("%s\n", pertence(conj1, 5) ? "Pertence" : "Nao pertence");
    printf("%s\n", pertence(conj1, 8) ? "Pertence" : "Nao pertence");
    printf("%s\n", pertence(conj1, 9) ? "Pertence" : "Nao pertence");
    printf("%s\n", pertence(conj2, 5) ? "Pertence" : "Nao pertence");
    printf("%s\n", pertence(conj2, 1) ? "Pertence" : "Nao pertence");
    printf("%s\n", pertence(conj2, 4) ? "Pertence" : "Nao pertence");

    //Menor e maior
    
    printf("\n");
    printf("Maior valor do conjunto 1: %i\n", maior(conj1));
    printf("Menor valor do conjunto 1: %i\n", menor(conj1));
    printf("Maior valor do conjunto 2: %i\n", maior(conj2));
    printf("Menor valor do conjunto 2: %i\n", menor(conj2));

    // Funcao iguais

    printf("\n");
    printf("%s\n", iguais(conj1, conj2) ? "Os conjuntos sao iguais" : "Os conjuntos sao diferentes");

    // Tamanho dos conjuntos

    printf("\n");
    printf("Tamanho do conjunto 1: %i\n", size(conj1));
    printf("Tamanho do conjunto 2: %i\n", size(conj2));

    // Testando remocao

    printf("\n");
    printf("%s\n", remover(&conj1, 9) ? "Removido" : "Nao encontrado");
    printf("Tamanho do conjunto 1: %i\n", size(conj1));
    printf("%s\n", remover(&conj1, 20) ? "Removido" : "Nao encontrado");
    printf("Tamanho do conjunto 1: %i\n", size(conj1));
    printf("%s\n", remover(&conj2, 1) ? "Removido" : "Nao encontrado");
    printf("Tamanho do conjunto 2: %i\n", size(conj2));
    printf("%s\n", remover(&conj2, 14) ? "Removido" : "Nao encontrado");
    printf("Tamanho do conjunto 2: %i\n", size(conj2));

    return 0;
}