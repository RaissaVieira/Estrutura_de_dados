#include <stdio.h>
#include <stdlib.h>
#include "arvBiBus.h"

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

Arv *arv_cria()
{

    Arv *a = (Arv *)malloc(sizeof(Arv));

    if (a)
        a->raiz = NULL;

    return a;
}

static ArvNo *insere(ArvNo *r, int v)
{
    if (r == NULL)
    {
        r = (ArvNo *)malloc(sizeof(ArvNo));
        r->info = v;
        r->esq = r->dir = NULL;
    }

    else if (v < r->info)
        r->esq = insere(r->esq, v);
    else
        r->dir = insere(r->dir, v);

    return r;
}

void abb_insere(Arv *a, int v)
{
    a->raiz = insere(a->raiz, v);
}

void busca(ArvNo *r, int x, int *count)
{
    if (r != NULL)
    {
        busca(r->esq, x, count);
        if ((r->info > x) && (r->esq == NULL && r->dir == NULL))
            *count = *count + 1;
        busca(r->dir, x, count);
    }
}

int nfolhas_maiores(Arv *a, int x)
{
    int count = 0;
    busca(a->raiz, x, &count);
    return count;
}

void somatorio(ArvNo *r, int x, int y, int *total)
{
    if (r != NULL)
    {
        somatorio(r->esq, x, y, total);
        if (r->info > y && r->info < x)
            *total = *total + r->info;
        somatorio(r->dir, x, y, total);
    }
}

int soma_xy(Arv *a, int x, int y)
{
    int total = 0;
    somatorio(a->raiz, x, y, &total);
    return total;
}

int nivel_no(ArvNo *r, int x)
{
    int he, hd;
    if (r->info == x) 
        return 0;

    else if (r-> info > x) 
        return he = nivel_no(r->esq, x) + 1;

    else if (r-> info < x) 
        return hd = (nivel_no(r->dir, x) + 1);

}

int nivel(Arv *a, int x)
{
    return nivel_no(a->raiz, x);
}