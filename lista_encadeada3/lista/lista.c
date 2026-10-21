#include <stdlib.h>
#include <stdio.h>

#include "lista.h"

struct no {
   int info;
   struct no* ant;
   struct no* prox;
};

void lst_cria(No ** inicio){
   *inicio = NULL;
}

/* fun��o busca: busca um elemento na lista */
No* lst_busca (No* inicio, int v)
{
   No* p = inicio;
   while(p!=NULL) {
       if (p->info == v)
          return p;
       p=p->prox;
   }

   return NULL;	/* n�o achou o elemento */
}
void lst_insere_final(No** inicio, int v){
   No* novo = (No*)malloc(sizeof(No));
   No* p = *inicio;
   novo->info = v;
   if (*inicio != NULL)
   {
      (*inicio)->ant = novo;
   }
   while (p->prox != NULL)
   {
      p=p->prox;
   }
   novo->prox = NULL;
   novo->ant = p;
   p->prox=novo;
}
void lst_imprime (No * inicio){
   No* p = inicio;
   while (p != NULL)
   {
      printf("%d\n", p->info);
      p=p->prox;
   }
}
void lst_imprime_para_tras (No * inicio){
   if(inicio == NULL)
      return;
   
   No* p = inicio;
   
   while (p->prox != NULL)
   {
      p = p->prox;
   }
   while (p != NULL)
   {
      printf("%d\n", p->info);
      p=p->ant;
   }
}
void lst_insere (No** inicio, int v)
{
   No* novo = (No*) malloc(sizeof(No));
   novo->info = v;
   novo->prox = *inicio;
   novo->ant = NULL;
   if (*inicio != NULL)
      (*inicio)->ant = novo;
   *inicio = novo;
}





/* fun��o retira: remove elemento da lista */
void lst_retira (No** inicio, int v)
{
   No* p = lst_busca(*inicio,v);
   if (p == NULL)
      return ;                             /* n�o achou o elemento: */

   /* retira elemento do encadeamento */
   if (*inicio == p)		/* testa se � o primeiro elemento */
      *inicio = p->prox;
   else
      p->ant->prox = p->prox;

   if (p->prox != NULL) 	/* testa se � o �ltimo elemento */
      p->prox->ant = p->ant;
   free(p);
}


