#ifndef PILHA
#define PILHA

typedef struct p Pilha;

Pilha* create_pilha();
void pilha_push(Pilha* pilha, float v);
float pilha_pop(Pilha* pilha);
int pilha_empty(Pilha* pilha);
void libera_pilha(Pilha* pilha);
int pilha_size(Pilha* pilha);
void pilha_print(Pilha* pilha);

#endif