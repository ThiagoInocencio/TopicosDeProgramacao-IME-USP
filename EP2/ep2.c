#include <stdio.h>
#include <stdlib.h>

/*
 * Nome: Thiago de Jesus Inoc�ncio
 */

typedef struct pessoa Pessoa;

struct pessoa {
  int posicao;
  Pessoa *prox;
};

Pessoa *inicio;

void insereLista(int x);
void removeLista(Pessoa *p);
void imprimeLista();
void resolveJosephus(int n, int m);
Pessoa * buscaPessoa(int m, Pessoa *pessoa);

void insereLista(int x) {

    Pessoa *novaPessoa;
    Pessoa *aux;
    novaPessoa = malloc(sizeof(Pessoa));
    novaPessoa->posicao = x;

    if(inicio == NULL) {
        inicio = novaPessoa;
        novaPessoa->prox = inicio;
    } else {
       aux = inicio;

       while(aux->prox != inicio)
         aux = aux->prox;

       aux->prox = novaPessoa;
       novaPessoa->prox = inicio;
    }
}

void imprimelista() {
    Pessoa *aux;
    aux = inicio;

    if(inicio == NULL) return;
    do {
       printf("%d " , aux->posicao);
       aux = aux->prox;
    } while(aux != inicio);
}

void removeLista(Pessoa *p) {
    Pessoa *aux;

    if(inicio == NULL) return;

    if(inicio->prox == inicio) {
        free(inicio->prox);
        inicio = NULL;
    } else {
        aux = p->prox->prox;
        printf("%d " , p->prox->posicao);
        free(p->prox);
        if(p->prox == inicio) inicio = aux;
        p->prox = aux;
    }
}

Pessoa * buscaPessoa(int m, Pessoa *pessoa) {
    Pessoa *aux = pessoa;

    if(inicio == NULL) return NULL;

    while(m > 1) {
      aux = aux->prox;
      m--;
    }

    return aux;
}

void resolveJosephus(int n, int m) {

    Pessoa *pessoa = inicio;
    Pessoa *aux = inicio;

    printf("Numero dos homens que foram mortos: ");

    while(inicio->prox != inicio) {
      aux = buscaPessoa(m, pessoa);
      if(aux->prox == pessoa) aux = aux->prox;
      pessoa = aux->prox->prox;
      removeLista(aux);
    }

    printf("\nO homem sobrevivente estava na posicao: %d \n" , inicio->posicao);

}

int main()
{

    int i = 0;
    inicio = NULL;

    /* Inserindo os homens de 1 a 4 na lista */
    for(i=1;i<=4;i++) insereLista(i);

    /* Resolvendo o problema para m = 1 */
    resolveJosephus(4,1);

    return 0;
}
