#pragma once

typedef struct pilha Pilha;

Pilha* create_pilha();
void pilha_push(Pilha* p, float v);
float pilha_pop(Pilha* p);
int pilha_empty(Pilha* p);
void libera_pilha(Pilha* p);
int pilha_size(Pilha* p);