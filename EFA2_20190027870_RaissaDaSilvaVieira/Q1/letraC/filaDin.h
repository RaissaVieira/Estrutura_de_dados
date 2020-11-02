#ifndef FILA
#define FILA

typedef struct f Fila;

Fila* create_fila ();
void fila_insert (Fila* fila, float valor);
int fila_remove (Fila* fila);
int fila_empty (Fila* fila);
void libera_fila (Fila* fila);
int fila_size(Fila* fila);
void print_fila(Fila* fila);

#endif