#ifndef ARVORE
#define ARVORE

typedef struct arvno ArvNo;
typedef struct arv Arv;

ArvNo *arv_criano(int c, ArvNo *esq, ArvNo *dir);
Arv *arv_cria();
static ArvNo *insere(ArvNo *r, int v);
void abb_insere(Arv *a, int v);
void busca(ArvNo *r, int x, int* count);
int nfolhas_maiores (Arv*a, int x);
void somatorio(ArvNo *r, int x, int y, int* total);
int soma_xy (Arv*a, int x, int y);
int nivel (Arv*a, int x);

#endif