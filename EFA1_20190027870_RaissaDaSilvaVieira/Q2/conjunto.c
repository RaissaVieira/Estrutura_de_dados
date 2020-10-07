#include <stdlib.h>
#include <stdio.h>
#include "conjunto.h"

struct conjunto{
    int valor;
    struct conjunto* prox;
};

Conjunto * create_conjunto(int v){
    Conjunto * l = (Conjunto*) malloc(sizeof(Conjunto));
    if (l)
    {
        l->valor = v;
        l->prox = NULL;
    }
}

Conjunto * uniao(Conjunto *l1, Conjunto *l2){
    Conjunto* l;
    Conjunto* p;   /* variável auxiliar para percorrer a lista */
    Conjunto* q;   /* variável auxiliar para criar a nova lista */

        if (l1 == NULL) 
        return l2;

        l = l1;

        p = l1;   
          do   
          { 
             q = p; 
             p = p->prox;
          } 
          while(p != NULL);

        q->prox = l2;

        print(q);

        return l1;  
}

Conjunto * criar_conj_vazio(){
    Conjunto * l = (Conjunto*) malloc(sizeof(Conjunto));
    if (l)
    {
        l->valor = 0;
        l->prox = NULL;
    }

    return l;
}

int inserir(Conjunto **l1, int i, int v){
    if(conj_vazio(*l1)){
        Conjunto * aux = create_conjunto(v);
        if(aux){
            *l1 = aux;
            return 1;
        }
    }

    Conjunto * aux1 = create_conjunto(v);
    if (aux1)
    {
        int count = 0;
        Conjunto * conj = *l1;

        while (conj->prox != NULL)
        {
            if(count == i){
                aux1->prox = conj;
                conj = aux1;

                return 1;
            }

            count++;
            conj = conj->prox;

        }
        conj->prox = aux1;
        return 1;         
    }

    return 0;    
}

int remover(Conjunto **l1, int v){
    Conjunto * ante = NULL;
    Conjunto * aux = *l1;
    int found = 0;

    while (aux != NULL)
    {
        if (aux->valor == v)
        {
            found = 1;
            break;
        }
        ante = aux;
        aux = aux->prox;
    }
    
    if(found){
        if (ante == NULL)
        {
            *l1 = aux->prox;
            free(aux);
            return 1;
        }

        ante->prox = aux->prox;
        free(aux);
        return 1;        
    }

    return 0;
}

Conjunto * interseccao(Conjunto *l1, Conjunto *l2){
    Conjunto* c = criar_conj_vazio();
    Conjunto* aux= criar_conj_vazio();
    if(c){
        if(pertence(l2,l1->valor)){
                c = l1;
                aux = c;
        }

        while(l1->prox != NULL){
            if(pertence(l2,l1->valor)){
                c = l1;
            }
            l1=l1->prox;
        }

        c->prox = NULL;
        
        return c; 
    }else{
        printf("\nNão alocado espaço de memória\n");
        return criar_conj_vazio();
    }
}

Conjunto * diferenca(Conjunto *l1, Conjunto *l2){
    Conjunto * l = (Conjunto*) malloc(sizeof(Conjunto));
    if (l)
    {
        while (l1 != NULL)
        {
            if(!pertence(l2, l1->valor))
                l = l1;

            l1 = l1->prox;
            l = l->prox;
        }
    }

    return l;
}

int pertence(Conjunto *l1, int v){
    if (conj_vazio(l1))
        return 0;
    
    while (l1 != NULL)
    {
        if (l1->valor == v) 
            return 1;
        
        l1 = l1->prox;   
    }

    return 0;
}

int menor(Conjunto *l1){
    int menor = maior(l1);

    while (l1 != NULL)
    {
        if(l1->valor < menor)
            menor = l1->valor;

        l1 = l1->prox;
    }

    return menor;
}

int maior(Conjunto *l1){
    int maior = 0;

    while (l1 != NULL)
    {
        if(l1->valor > maior)
            maior = l1->valor;

        l1 = l1->prox;
    }

    return maior;    
}

int iguais(Conjunto *l1, Conjunto *l2){
    int tam = size(interseccao(l1, l2));

    if(tam == size(l1))
        return 1;
    
    return 0;
}

int size(Conjunto *l1){ // Verifica tamanho do conjunto
    int counter = 0;

    while (l1 != NULL)
    {
        counter++; 
        l1 = l1->prox;

    }
    
    return counter;    
}

int conj_vazio(Conjunto *l){
    return (l == NULL);
}

void print(Conjunto *l1){
    while (l1 != NULL)
    {
        printf("%i ", l1->valor);
        l1 = l1->prox;
    }
    
}