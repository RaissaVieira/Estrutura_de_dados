#ifndef CONJUNTO_H
#define CONJUNTO_H

typedef struct conjunto Conjunto;

// Definicao das funcoes

Conjunto * create_conjunto(int v); 
Conjunto * uniao(Conjunto **l1, Conjunto **l2);
Conjunto * criar_conj_vazio(); 
int inserir(Conjunto **l1, int v);
int remover(Conjunto **l1, int v); 
Conjunto * interseccao(Conjunto **l1, Conjunto **l2); 
Conjunto * diferenca(Conjunto **l1, Conjunto **l2); 
int pertence(Conjunto *l1, int v); 
int menor(Conjunto *l1); 
int maior(Conjunto *l1); 
int iguais(Conjunto *l1, Conjunto *l2); 
int size(Conjunto *l1); 
int conj_vazio(Conjunto *l1); 
void print(Conjunto *l1);

#endif