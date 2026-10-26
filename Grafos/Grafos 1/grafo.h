typedef struct grafo Grafo;

/*fun��es para cria��o/remo��o de um grafo*/
Grafo * grafo_cria ();
void grafo_libera (Grafo * grafo);

/*fun��es para manipula��o dos v�rtices de um grafo*/
int grafo_qtd_vertices (Grafo * grafo);
int * grafo_busca_vertices_saida(Grafo * grafo, int vertice, int * cont);
int * grafo_busca_vertices_entrada(Grafo * grafo, int vertice, int * cont);

/*fun��es para manipula��o das arestas do grafo*/
void grafo_insere_aresta (Grafo * grafo, int vertice1, int vertice2, int custo);
int grafo_busca_aresta(Grafo * grafo, int vertice1, int vertice2);

/*fun��o para impress�o tabulada a partir de um v�rtice*/
void grafo_imprime_tab (Grafo * grafo, int vertice);

void encontra_mais_popular (Grafo * grafo);