#ifndef ARV_H
#define ARV_H

typedef struct no{
    int conteudo;
    struct no *esquerdo;
    struct no *direito;
}No;

typedef struct{
    No *raiz;
}arv_b;

void inserir_direita(No* no, int valor);
void inserir_esquerda(No *no, int valor);
void inserir_arv(arv_b *arvore, int valor);
void imprimir(No *raiz);
No* inserir_nova_versao(No* raiz, int v);

#endif