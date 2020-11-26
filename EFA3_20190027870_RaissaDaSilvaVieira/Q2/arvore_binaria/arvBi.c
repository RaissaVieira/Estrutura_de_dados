#include <stdio.h>
#include <stdlib.h>
#include "arvBi.h"

struct arvno
{
    int info;
    ArvNo *esq;
    ArvNo *dir;
};

struct arv
{
    ArvNo *raiz;
};

ArvNo *arv_criano(int c, ArvNo *esq, ArvNo *dir)
{

    ArvNo *p = (ArvNo *)malloc(sizeof(ArvNo));

    if (p)
    {
        p->info = c;
        p->esq = esq;
        p->dir = dir;
    }

    return p;
}

Arv *arv_cria(ArvNo *r)
{

    Arv *a = (Arv *)malloc(sizeof(Arv));

    if (a)
        a->raiz = r;

    return a;
}

void contador_par(ArvNo *r, int *count)
{
    if (r != NULL)
    {
        if(r->info%2 == 0)
            *count = *count + 1;
        contador_par(r->esq,count);
        contador_par(r->dir,count);
    }
}

int pares(Arv *a)
{
    int count = 0;
    contador_par(a->raiz, &count);

    return count;
}

void contador_filhos(ArvNo *r, int *count)
{
    if (r != NULL)
    {
        if(r->esq == NULL && r->dir == NULL)
            *count = *count + 1;
        contador_filhos(r->esq,count);
        contador_filhos(r->dir,count);
    }
}

int folhas(Arv *a)
{
    int count = 0;
    contador_filhos(a->raiz, &count);

    return count;
}

void contador_filhosUnico(ArvNo *r, int *count)
{
    if (r != NULL)
    {
        if((r->esq == NULL && r->dir != NULL) || (r->esq != NULL && r->dir == NULL))
        {
            *count = *count + 1;
        }    
            
        contador_filhosUnico(r->esq,count);
        contador_filhosUnico(r->dir,count);
    }
}

int um_filho(Arv *a)
{
    int count = 0;
    contador_filhosUnico(a->raiz, &count);

    return count;
}