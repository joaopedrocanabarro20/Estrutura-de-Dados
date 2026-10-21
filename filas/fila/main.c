#include "stdlib.h"
#include "stdio.h"
#include "fila.h"

Fila * separaPares (Fila * f){
   Fila* nova = fila_cria();
   Fila* pares = fila_cria();
   while (!fila_vazia(f))
   {
      int n = fila_retira(f);
      if (n%2 == 0)
      {
         fila_insere(pares, n);
      }
      fila_insere(nova, n);
   }
   while (!fila_vazia(nova))
   {
      fila_insere(f, fila_retira(nova));
   }
   fila_libera(nova);
   return pares;
}
void imprime (Fila * f){
   while (!fila_vazia(f))
   {
      printf("%d\n", fila_retira(f));
   }
}
void imprime2 (Fila * f){
   Fila* nova = fila_cria();
   while (!fila_vazia(f))
   {
      int v = fila_retira(f);
      printf("%d\n", v);
      fila_insere(nova, v);
   }
   while (!fila_vazia(nova))
   {
      int t = fila_retira(nova);
      fila_insere(f, t); 
   }
   fila_libera(nova);
}

int main (void)
{

   Fila * f = fila_cria();
   fila_insere(f, 10);
   fila_insere(f, 15);
   fila_insere(f, 20);


   int tam = fila_tamanho(f);
   printf("\nTamanho da lista: %d", tam);

   printf("\nElementos");
   imprime2(f);

   printf("\n\nElementos pares");
   Fila * f2 = separaPares(f);
   imprime2(f2);
   return 0;
}

