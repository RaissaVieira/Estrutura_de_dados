#ifndef ARVORE
#define ARVORE

typedef struct arvno ArvNo;
typedef struct arv Arv;

ArvNo *arv_criano(int c, ArvNo *esq, ArvNo *dir);
Arv *arv_cria(ArvNo *r);
int pares (Arv* a);
void contador_par(ArvNo *r, int* count);
int folhas(Arv *a);
void contador_filhos(ArvNo *r, int *count);
int um_filho (Arv* a);
void contador_filhosUnico(ArvNo *r, int *count);

#endif