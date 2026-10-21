#include "stdlib.h"
#include "stdio.h"
#include "arvore.h"



void imprime_asc(No * no){
    if (no==NULL)
        return;

    imprime_asc(arv_busca_filho(no,0));
    printf("%d, ",arv_busca_valor(no) );
    imprime_asc(arv_busca_filho(no,1));

}


int calcula_altura(No * no){
    No* p = no;
    if (no == NULL)
    {
        return 0;
    }
    int esq = calcula_altura(arv_busca_filho(no, 0));
    int dir = calcula_altura(arv_busca_filho(no, 1));

    if (esq > dir) {
        return esq + 1;
    }
    else {
        return dir + 1;
    }
}

int balanceada(No * no)
{
    if(no == NULL){
        return 1;
    }
    int dif = calcula_altura(arv_busca_filho(no, 0)) - calcula_altura(arv_busca_filho(no, 1));

    if (dif > 1 || dif < -1)
    {
        return 1;
    }

    return balanceada(arv_busca_filho(no, 0)) &&
           balanceada(arv_busca_filho(no, 1));
}



int quant_maiores(No * no, int v)
{
    if (no == NULL) {
        return 0;
    }
    int cont = 0;
    if (arv_busca_valor(no) > v)
    {
        cont++;
    }
    
    cont+=quant_maiores(arv_busca_filho(no, 0), v);
    cont+=quant_maiores(arv_busca_filho(no, 1), v);

    return cont;
}

void preenche_vetor(No *no, int v, int *vetor, int *pos)
{
    if (no == NULL) {
        return;
    }

    if (arv_busca_valor(no) > v) {
        vetor[*pos] = arv_busca_valor(no);
        (*pos)++;
    }

    preenche_vetor(arv_busca_filho(no, 0), v, vetor, pos);
    preenche_vetor(arv_busca_filho(no, 1), v, vetor, pos);
}
int gera_vetor_maiores(No * no, int v, int ** vetor){
    int qtd = quant_maiores(no , v);
    if (no == NULL)
    {
        return 0;
    }
    if (qtd == 0)
    {
        *vetor = NULL;
        return 0;
    }
    *vetor = malloc((sizeof(int))*qtd);
    int pos = 0;
    preenche_vetor(no, v, *vetor, &pos);    

    return qtd;
}




int main()
{

   printf("\n\n******************* TESTE 1 ******************************");
   Arvore * arv = arv_cria();

   arv_insere_no(arv, 1);
   arv_insere_no(arv, 2);
   arv_insere_no(arv, 3);
   arv_insere_no(arv, 4);
   arv_insere_no(arv, 5);
   arv_insere_no(arv, 6);
   arv_insere_no(arv, 7);

   printf("\n");
   int bal = balanceada(arv_busca_raiz(arv));
   if (bal)
        printf("\nBalanceada");
    else printf("\nNao Balanceada");


   printf("\n\n******************* TESTE 2 ******************************");
   Arvore * arv1 = arv_cria();

   arv_insere_no(arv1, 4);
   arv_insere_no(arv1, 6);
   arv_insere_no(arv1, 2);
   arv_insere_no(arv1, 5);
   arv_insere_no(arv1, 1);
   arv_insere_no(arv1, 7);
   arv_insere_no(arv1, 3);

   printf("\n");
    bal = balanceada(arv_busca_raiz(arv1));
   if (bal)
        printf("\nBalanceada");
    else printf("\nNao Balanceada");


   int * vetor;
   int tam = gera_vetor_maiores(arv_busca_raiz(arv1), 3, &vetor);

   printf("\n\nvetor gerado: ");
   int x;
   for(x=0;x<tam;x++){
       printf("%d ", vetor[x]);
   }
   printf("\n");


   return 0;
}
