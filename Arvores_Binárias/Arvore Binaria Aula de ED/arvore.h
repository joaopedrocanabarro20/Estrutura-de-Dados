/*tipos exportados*/
typedef struct no No;

typedef struct arvore Arvore;

Arvore * arv_cria ();
No * arv_cria_no (int v);

int arv_vazia (Arvore * arvore);
int arv_no_vazio (No * no);

No * arv_busca_raiz (Arvore * arvore);
void arv_seta_raiz (Arvore * arvore, No * raiz);
void arv_imprime_tab (No* pai, char * lado);
void arv_insere (No* pai, No* filho, int dir);
void imprime_tab (No* pai, char * lado);
void arv_imprime (No* pai);
int arv_busca_valor (No * no);
No* arv_busca_filho (No * no, int dir);
void arv_insere_final (No* pai, No* filho, int dir);
