#include "stdlib.h"
#include "stdio.h"
#include "pilha.h"
#include "calc.h"

void imprime(Pilha* p1){
   int v;
   while (!pilha_vazia(p1))
   {
      v=pilha_pop(p1);
      printf("%d\n", v);  
   }
}
Pilha * invertePilha (Pilha * p){
   Pilha* nova = p;
   while (!pilha_vazia(p))
   {
      int v = pilha_pop(p);
      pilha_push(nova, v);
   }
   return nova;
}

int main (void)
{
   Pilha * p1 = pilha_cria();
   pilha_push(p1, 4);
   pilha_push(p1, 6);
   pilha_push(p1, 8);

   printf("\nimpressao da pilha 1");
   imprime(p1);

   //depois da impressao a pilha ficou vazia. Po isso os elementos serao empilhados novamente
   pilha_push(p1, 4);
   pilha_push(p1, 6);
   pilha_push(p1, 8);

   Pilha * p2 = invertePilha(p1);
   printf("\n\nimpressao da pilha invertida");
   imprime(p2);

   char equacao[] = "125+-";
   printf("\n\nCalculando resultado da equacao %s", equacao);
   Calc * calc = calc_cria();
   printf("\nResultado: %.0f",calc_calcula(calc, equacao));
   printf("\n");


   return 0;
}

