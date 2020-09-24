#include <stdio.h>

int main (){
   float raio, area;

   printf("Valor do raio do circulo: ");
   scanf("%e", &raio);

   area = 3.14*raio*raio;

   printf("A area do circulo e: %.2f\n", area);

   return 0;
}