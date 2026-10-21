#include "stdlib.h"
#include "stdio.h"
#include "arvore.h"



void imprime_asc(No * no){
    if(no == NULL){
        return;
    }
    imprime_asc(arv_busca_filho(no, 0));
    printf("%d", arv_busca_valor(no));
    imprime_asc(arv_busca_filho(no, 1));
}   
void imprime_desc(No * no){
    if(no == NULL){
        return;
    }
    imprime_desc(arv_busca_filho(no, 1));
    printf("%d", arv_busca_valor(no));
    imprime_desc(arv_busca_filho(no, 0));
}
int calcula_diferenca(No * no)
{
    if (no == NULL || arv_no_vazio(no))
        return -1;

    No * menor = no;
    No * maior = no;

    while (arv_busca_filho(menor, 0) != NULL)
        menor = arv_busca_filho(menor, 0);

    while (arv_busca_filho(maior, 1) != NULL)
        maior = arv_busca_filho(maior, 1);

    return arv_busca_valor(maior) - arv_busca_valor(menor);
}



void imprime_tab (No* no, char * lado)
{
   static int tab = 0;

   if (no==NULL) return;

   int x;
   for(x=0;x<tab;x++)
       printf("   ");
   printf("%d (%s)\n", arv_busca_valor(no), lado);

   tab+=1;
   imprime_tab(arv_busca_filho(no,0), "ESQ");
   imprime_tab(arv_busca_filho(no,1), "DIR");
   tab-=1;
}


int main()
{
   Arvore * arv = arv_cria();

   arv_insere_no(arv, 10);
   arv_insere_no(arv, 50);
   arv_insere_no(arv, 40);
   arv_insere_no(arv, 20);
   arv_insere_no(arv, 60);

   printf("\n Impressao \n");
   imprime_tab(arv_busca_raiz(arv), "RAIZ");

   printf("\n");
   int valor = 50;
   No * resp = arv_busca_no(arv_busca_raiz(arv), valor);
   if (resp!=NULL)
        printf("No encontrado: %d", valor);
    else printf("No nao encontrado: %d ", valor);


   printf("\n");
   int diff = calcula_diferenca(arv_busca_raiz(arv));
   if (diff!=-1)
        printf("\nDiferenca do maior para o menor e de %d unidades", diff);

   printf("\n\n lista ascendente de valores:");
   imprime_asc(arv_busca_raiz(arv));

   printf("\n\n lista descendente de valores:");
   imprime_desc(arv_busca_raiz(arv));

   return 0;
}
