#include <stdio.h>
#include <stdlib.h>

#define LIN 3
#define COL 3

/* Thiago Inocêncio */

struct no {
  int linha;
  int coluna;
  struct no * prox;
};

typedef struct no No;

struct fila {
  No *inicio;
  No *fim;
  int tamanho;
};

typedef struct fila  Fila;

void insereFila (int linha, int coluna, Fila *f);
No *removeFila (Fila *f);
void imprimeFila (Fila *f);
int resolveLabirinto (int labirinto[LIN][COL], int m, int n);
Fila * initFila();
int foraLabirinto(int m , int n);
int posicaoLivre(int labirinto[LIN][COL], int m, int n);


void insereFila(int linha, int coluna, Fila *f) {
    No * temp = malloc(sizeof(No));

    temp->linha = linha;
    temp->coluna = coluna;
    temp->prox = NULL;

    f->tamanho = f->tamanho + 1;

    if(f->inicio == NULL) {
        f->inicio = temp;
        f->fim = temp;
        return;
    }

    f->fim->prox = temp;
    f->fim = temp;
}

No *removeFila(Fila *f) {
    No * temp;

    f->tamanho = f->tamanho - 1;

    if(f->inicio != NULL) {

        temp = f->inicio;
        f->inicio = f->inicio->prox;
        return temp;
    }

    return NULL;
}

void imprimeFila (Fila *f) {
  No * aux = f->inicio;

  while(aux != NULL) {
     printf("(%d, %d)" , aux->linha, aux->coluna);
     aux = aux->prox;
     if(aux != NULL) printf(" -> ");
  }

}

int foraLabirinto(int m , int n) {
    if(m >= LIN || n >= COL || m < 0 || n < 0) return 1;
      else return 0;
}

int posicaoLivre(int labirinto[LIN][COL], int m, int n) {
   if(labirinto[m][n] == 0) return 1;
     else return 0;
}


int encontrarCaminho(int labirinto[LIN][COL], int m, int n, Fila *f) {

   if(foraLabirinto(m,n)) return 0;
   if(posicaoLivre(labirinto, m, n)) labirinto[m][n] = -1;
     else return 0;

   if(m==0 && n==0) {
        insereFila(m, n, f);
        return 1;
   }

   if(encontrarCaminho(labirinto, m+1, n, f)) {
      insereFila(m, n, f);
      return 1;
   }


   if(encontrarCaminho(labirinto, m, n-1, f)) {
      insereFila(m, n, f);
      return 1;
   }

   if(encontrarCaminho(labirinto, m-1, n, f)) {
      insereFila(m, n, f);
      return 1;
   }

   if(encontrarCaminho(labirinto, m, n+1, f)) {
      insereFila(m, n, f);
      return 1;
   }


   return 0;
}

Fila * initFila() {

 Fila * temp = malloc(sizeof(Fila));
 temp->fim = NULL;
 temp->inicio = NULL;
 temp->tamanho = 0;

 return temp;
}


int resolveLabirinto (int labirinto[LIN][COL], int m, int n) {

    int existeCaminho = 0;
    Fila * f = initFila();

    existeCaminho = encontrarCaminho(labirinto, m-1, n-1, f);

    if(existeCaminho) {
        printf("Labirinto (%dx%d)\n", LIN, COL);
        printf("Distancia da casa inicial a casa final: %d\nCaminho percorrido:\n" , f->tamanho-1);
        imprimeFila(f);
    } else printf("Nao existe caminho");

    printf("\n");

    return 0;

}

int main()
{
    int m, n;
    int labirinto[3][3] = {{0, 1, 1}, {0, 0, 0}, {1, 0, 0}};

    m = 3;
    n = 3;
    resolveLabirinto(labirinto, m, n);

    m = 4;
    n = 4;
    
    /* TROCAR OS VALORES DE LIN E COL PARA REALIZAR CADA UM DOS TESTES COMENTADOS ABAIXO DE ACORDO COM O VALOR DE m e n (LIN=m, COL=n).
	resolveLabirinto (labirinto2, m, n);

    m = 5;
    n = 6;
    resolveLabirinto (labirinto3, m, n);

    m = 6;
    n = 9;
    resolveLabirinto (labirinto4, m, n);*/

    return 0;
}
