#include<stdio.h>
#include<math.h>
#include<string.h>

/* Thiago Inocêncio */

char tabuleiro[50][50];
int posColuna[50];
int numSolucoes=0;

int verificarposColunaicao(int lin, int col, int n) {

      int i, novaPosicao;

      for (i = 0; i < col; i++) {
            novaPosicao = posColuna[i];

            if(novaPosicao == lin || novaPosicao == (lin - (col - i)) || novaPosicao == (lin + (col - i)))
              return 0;
      }

      return 1;
}

void mostrarSolucao(int n) {

    int i, j;

    printf("\n\n");

    printf("Solucao %d:\n\n" , numSolucoes);

	for(i = 0; i < n; i++) {
        printf("\t\t");
        for(j = 0; j < n; j++) {
            printf("%c " , tabuleiro[i][j]);
        }
        printf("\n");
	}
}

int resolveDesafio(int lin, int col, int n) {

    if(verificarposColunaicao(lin, col, n)) {

        tabuleiro[lin][col] = 'R';
        posColuna[col] = lin;

        if(col == n-1) {
            numSolucoes++;
            mostrarSolucao(n);
            tabuleiro[lin][col] = '#';
            return 0;

        } else {
            resolveDesafio(0, col+1, n);
        }
    }

    tabuleiro[lin][col] = '#';

    if(col == n-1 && lin == n-1) return 0;

    if(lin+1 < n) resolveDesafio(lin+1, col, n);
     else return 0;

     return 0;
}

int nRainhas(int n) {

   resolveDesafio(0, 0, n);

   return numSolucoes;
}

int main() {
	int numeroRainhas;

	printf("Digite o numero de rainhas: ");
	scanf("%d", &numeroRainhas);

	memset(tabuleiro, '#', sizeof(tabuleiro));

    printf("\nPara n = %d" , numeroRainhas);
	printf("\nNumero de solucoes: %d\n" , nRainhas(numeroRainhas));

	return 0;
}
