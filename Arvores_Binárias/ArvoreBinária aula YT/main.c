#include <stdio.h>
#include <stdlib.h>
#include "arv.h"



/*void inserir_esquerda(No *no, int valor){
    if (no->esquerdo == NULL)
    {
        No* novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        no->esquerdo = novo;
    }
    else{
        if(valor < no->esquerdo->conteudo){
            inserir_esquerda(no->esquerdo, valor);
        }

        else{
            inserir_direita(no->esquerdo, valor);
        }
    }
    
}
void inserir_direita(No* no, int valor){
    if (no->direito == NULL)
    {
        No* novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        no->direito = novo;
    }
    else{
        if(valor > no->direito->conteudo){
            inserir_direita(no->direito, valor);
        }
        else{
            inserir_esquerda(no->direito, valor);
        }
    }
}

void inserir_arv(arv_b *arvore, int valor){
    if (arvore->raiz == NULL)
    {
        No* novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        arvore->raiz = novo;
    }
    else{
        if(valor < arvore->raiz->conteudo){
            inserir_esquerda(arvore->raiz, valor);
        }
        else{
            inserir_direita(arvore->raiz, valor);
        }
        
    }
}*/
No* inserir_nova_versao(No* raiz, int v){
    if(raiz == NULL){
        No* novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        return novo;
    }
    else{
        if (raiz->conteudo > valor)
        {
            raiz->esquerdo = inserir_nova_versao(raiz->esquerdo, valor);
            return raiz;
        }
        if(valor > raiz->conteudo){
            raiz->direito = inserir_nova_versao(raiz->direito, valor);
            return raiz;        
        }
        
    }
}

void imprimir(No *raiz){
    if (raiz != NULL)
    {
        printf("%d ", raiz->conteudo);
        imprimir(raiz->esquerdo);
        imprimir(raiz->direito);
    }
    
}

int main(){
    int op, valor;
    arv_b arvore;
    arvore.raiz = NULL;

    do
    {
        printf("\n0-sair\n1-inserir\n2-imprimir\n");
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            break;
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            arvore.raiz = inserir_nova_versao(arvore.raiz, valor);
            break;
        case 2:
            imprimir(arvore.raiz);
            break;
        default:
            printf("Invalido\n");
            break;
        }

    } while (op != 0);
}