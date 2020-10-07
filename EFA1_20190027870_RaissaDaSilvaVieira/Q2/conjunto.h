#ifndef CONJUNTO_H
#define CONJUNTO_H

typedef struct conjunto Conjunto;

Conjunto * create_conjunto(int v); //OK
Conjunto * uniao(Conjunto *l1, Conjunto *l2);
Conjunto * criar_conj_vazio(); //OK
int inserir(Conjunto **l1, int i, int v);
int remover(Conjunto **l1, int v); //OK
Conjunto * interseccao(Conjunto *l1, Conjunto *l2);
Conjunto * diferenca(Conjunto *l1, Conjunto *l2);
int pertence(Conjunto *l1, int v); //OK
int menor(Conjunto *l1); //OK
int maior(Conjunto *l1); //OK
int iguais(Conjunto *l1, Conjunto *l2);
int size(Conjunto *l1); //OK
int conj_vazio(Conjunto *l1); //OK
void print(Conjunto *l1); //OK

#endif