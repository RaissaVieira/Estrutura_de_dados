#include <stdio.h>
#include <stdlib.h> //necessário para usar as funções malloc() e free()
//#include <curses.h>

void liberarMatriz (int **p, int N){
  for (int i = 0; i < N; i++)
  {
    free(p[i]);
  }
  free(p);
}

void inversa(int **p, int dim){
    for (int i = dim; i >= 0; i--){
    //p[i] = (int *) malloc(dim * sizeof(int)); 
    for (int j = dim; j >= 0; j--){
      printf("%d ", p[i][j]);
    }
    printf("\n");
  }
}

int main(void)
{
  int **p; //definindo o ponteiro p
  int i, dim, j;
  
  printf("Informe o numero de dimensao da matriz\n");
  scanf("%d", &dim);

  p = (int **) malloc(dim * sizeof(int *));
  //printf("%d", **p); //por desencargo printa saporra

  for (i = 0; i < dim; i++){
    p[i] = (int *) malloc(dim * sizeof(int)); 
    for (j = 0; j < dim; j++){
      scanf("%d", &p[i][j]);
    }
  }

  inversa(p, dim);
  liberarMatriz(p, dim);
  
  return 0;
}