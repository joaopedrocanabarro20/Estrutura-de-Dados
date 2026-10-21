#include <stdio.h>
#include <stdlib.h>

struct aluno {
   int mat;
   char nome[81];
   char end[121];
   char tel[21];
};

typedef struct aluno Aluno;


void cria_aluno(Aluno** tab, int i){
   tab[i] = (Aluno*)malloc(sizeof(Aluno));
   if (tab[i] == NULL)
   {
      printf("Erro de alocacao de memoria!\n");
      exit(1);
   }
   
   printf("Entre com a matricula: ");
   scanf("%d", &tab[i]->mat);
   printf("Entre com o nome: ");
   scanf(" %[^\n]", tab[i]->nome);
   printf("Entre com o endereco: ");
   scanf(" %[^\n]", tab[i]->end);
   printf("Entre com o telefone: ");
   scanf(" %[^\n]", tab[i]->tel);
}
void inicializa (int n, Aluno** tab)
{
   int i;   
   for (i=0; i<n; i++)
      tab[i] = NULL;
}

void preenche (int n, Aluno** tab, int i)
{
   if (i<0 || i>=n) {
      printf("Indice fora do limite do vetor\n");
      exit(1);	/* aborta o programa */
   }

if (tab[i]==NULL)

    cria_aluno(tab, i);
}

void retira (int n, Aluno** tab, int i)
{
   if (i<0 || i>=n) {
      printf("Indice fora do limite do vetor\n");
      exit(1);	/* aborta o programa */
   }

   if (tab[i] != NULL){
      free(tab[i]);
      tab[i] = NULL;  /* indica que na posi��o n�o mais existe dado */
   }
}

void imprime (int n, Aluno** tab, int i)
{
   if (i<0 || i>=n) {
      printf("Indice fora do limite do vetor\n");
      exit(1);	/* aborta o programa */
   }

   if (tab[i] != NULL){
      printf("Matricula: %d\n", tab[i]->mat);
      printf("Nome: %s\n", tab[i]->nome);
      printf("Endereco: %s\n", tab[i]->end);
      printf("Telefone: %s\n", tab[i]->tel);
      printf("-----------------------------\n");
   }
}

void imprime_tudo (int n, Aluno** tab)
{
   int i;
   printf("-----------------------------\n");
   for (i=0; i<n; i++)
      imprime(n,tab,i);
}
void insereprimeira(int n, Aluno** tab, Aluno* al){
   if (tab[n-1]!=NULL)
   {
      free(tab[n-1]);
   }
   for (int i = n-1; i > 0; i--)
   {
      tab[i]=tab[i-1];
   }
   tab[0] = al; 
   
}


int main (void)
{
   Aluno* tab[10];
   inicializa(10,tab);
   preenche(10,tab,0);
   preenche(10,tab,1);
   preenche(10,tab,2);
   Aluno* aluno_novo = malloc(sizeof(Aluno));
   if (aluno_novo != NULL)
   {
      printf("Entre com a matricula:");
      scanf("%d", &aluno_novo->mat);
      printf("Entre com o nome:");
      scanf(" %[^\n]", aluno_novo->nome);
      printf("Entre com o endereco:");
      scanf(" %[^\n]", aluno_novo->end);
      printf("Entre com o telefone:");
      scanf(" %[^\n]", aluno_novo->tel);  
      insereprimeira(10, tab, aluno_novo);
   }
   
   imprime_tudo(10,tab);   
   retira(10,tab,0);
   retira(10,tab,1);
   retira(10,tab,2);
   return 0;
}


