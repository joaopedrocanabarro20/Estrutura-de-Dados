#include "stdlib.h"
#include "stdio.h"
#include "grafo.h"

void imprime_tab (Grafo * grafo, int vertice);
void imprime_tab_aux(Grafo *grafo, int v1, int v2, int prof, int tab);


void imprime_tab_aux(Grafo *grafo, int v1, int v2, int prof, int tab){
    int i;

    for (i = 0; i < tab; i++){
        printf(" ");
    }

    if (v2 != -1)
    {
        int custo = grafo_busca_aresta(grafo, v2, v1);
        printf("%d -- %d (%d)\n", v2, v1, custo);
    }

    if (prof == 3){
        return;
    }

    int qtd = grafo_qtd_vertices(grafo);

    for(i = 0; i < qtd; i++){
        if (grafo_busca_aresta(grafo, v1, i) != -1){
            imprime_tab_aux(grafo, i, v1, prof + 1, tab + 1);
        }
    }
}
void imprime_tab (Grafo * grafo, int vertice)
{
    if (grafo == NULL) {
        return;
    }

    imprime_tab_aux(grafo, vertice, -1, 0, 0);    
}

void encontra_mais_popular(Grafo *grafo)
{
    if (grafo == NULL){
        return;
    }

    int qtd = grafo_qtd_vertices(grafo);
    int mais_popular = -1;
    int maior_popularidade = 0;

    for (int v = 0; v < qtd; v++){
        int cont = 0;
        int *entradas = grafo_busca_vertices_entrada(grafo, v, &cont);

        int popularidade = 0;

        for (int i = 0; i < cont; i++){
            popularidade += grafo_busca_aresta(grafo, entradas[i], v);
        }

        free(entradas);

        if (mais_popular == -1 || popularidade > maior_popularidade){
            maior_popularidade = popularidade;
            mais_popular = v;
        }
    }

    if (mais_popular != -1){
        printf("Pessoa mais popular: vertice %d com %d pontos\n", mais_popular, maior_popularidade);
    }
}


int main()
{
   Grafo * grafo = grafo_cria();

   grafo_insere_aresta(grafo, 1, 2, 1);
   grafo_insere_aresta(grafo, 1, 3, 1);
   grafo_insere_aresta(grafo, 1, 4, 1);

   grafo_insere_aresta(grafo, 2, 3, 1);
   grafo_insere_aresta(grafo, 2, 4, 1);
   grafo_insere_aresta(grafo, 3, 4, 1);

   grafo_insere_aresta(grafo, 4, 8, 10);

   grafo_imprime_tab(grafo, 1);

   //imprime_tab(grafo, 1);

    int cont = 0;
    int vertice = 1;
    int * vertices = grafo_busca_vertices_saida(grafo, vertice, &cont);
    int i;
    printf("Os vertices de saida do vertice %d sao:\n", vertice );
    for (i=0;i<cont;i++){
        printf("%d\n", vertices[i]);

    }


   encontra_mais_popular(grafo);

   grafo_libera(grafo);

   return 0;
}
