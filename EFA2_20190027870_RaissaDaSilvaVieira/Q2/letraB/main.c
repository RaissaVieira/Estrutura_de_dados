#include <stdio.h>
#include "hash2.h"

int main(){

    Hash* tabela = create_hash();

    Pessoa *pessoa1 = create_pessoa(12883424462, "Raissa", 19, "feminino");
    Pessoa *pessoa2 = create_pessoa(92345678910, "Diego", 19, "masculino");
    Pessoa *pessoa3 = create_pessoa(12877424462, "Larissa", 24, "feminino");
    Pessoa *pessoa4 = create_pessoa(74587911562, "Francisco", 48, "masculino");
    Pessoa *pessoa5 = create_pessoa(87591207490, "Maria", 40, "feminino");

    // Inserindo elementos

    insert_hash(tabela, pessoa1);
    insert_hash(tabela, pessoa2);
    insert_hash(tabela, pessoa3);
    insert_hash(tabela, pessoa4);
    insert_hash(tabela, pessoa5);

    // Pesquisa pessoa pelo cpf

    Pessoa *teste;

    teste = search_hash(tabela, 12883424462);
    if (teste != NULL)
    {
        printfnome(teste);
    }
    else
    {
        printf("CPF nao encontrado\n");
    }
    teste = search_hash(tabela, 92345678910);
    if (teste != NULL)
    {
        printfnome(teste);
    }
    else
    {
        printf("CPF nao encontrado\n");
    }
    teste = search_hash(tabela, 12883428862);
    if (teste != NULL)
    {
        printfnome(teste);
    }
    else
    {
        printf("CPF nao encontrado\n");
    }

    // testando remocao

    printf("%s", remove_hash(tabela, 12883424462) ? "Removido\n" : "CPF nao encontrado\n");

    teste = search_hash(tabela, 12883424462);
    if (teste != NULL)
    {
        printfnome(teste);
    }
    else
    {
        printf("CPF nao encontrado\n");
    }

    printf("%s", remove_hash(tabela, 12883424463) ? "Removido\n" : "CPF nao encontrado\n");
    
    return 0;
}