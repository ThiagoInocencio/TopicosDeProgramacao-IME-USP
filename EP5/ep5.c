#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10
#define M 30

/* Thiago Inocêncio */

char **ordenacaoCrescente (char palavras[N][M]);
char **ordenacaoDecrescente (char palavras[N][M]);

char **ordenacaoCrescente (char palavras[N][M]) {

    int i = 0, j = 0;
    char * chave = (char *) malloc(sizeof(char*) * M);
    char ** mat;

    for(i = 0; i < N; i++) {
        strcpy(chave, palavras[i]);
        j = i - 1;
        while(j >= 0 && strcmp(chave, palavras[j]) < 0) {
            strcpy(palavras[j+1], palavras[j]);
            j--;
        }

        strcpy(palavras[j+1], chave);
    }

    mat = (char **) malloc(N * sizeof(char *));
    for(i = 0; i < N; i++) {
            mat[i] = (char *) malloc(M * sizeof(char));
           mat[i] = palavras[i];
    }

    free(chave);

  return mat;
}

char **ordenacaoDecrescente(char palavras[N][M]) {

    int i, j;
    char * chave = (char *) malloc(sizeof(char*) * M);
    char ** mat;

    for(i = 0; i < N; i++) {
        strcpy(chave, palavras[i]);
        j = i - 1;
        while(j >= 0 && strcmp(chave, palavras[j]) > 0) {
            strcpy(palavras[j+1], palavras[j]);
            j--;
        }

        strcpy(palavras[j+1], chave);
    }

    mat = (char **) malloc(N * sizeof(char *));
    for(i = 0; i < N; i++) {
            mat[i] = (char *) malloc(M * sizeof(char));
            mat[i] = palavras[i];
    }


    free(chave);

    return mat;
}

int main()
{
    int i;
    char str[10][M] = {"lovelace", "snyder", "jennings", "meltzer", "wescoff", "bilas", "mcnulthy", "lichterman", "hopper", "hamilton"};
    /*char str1[6][M] = {"heinlein", "gibson", "clarke", "asimov", "wallace", "kindred"};*/

    char ** ordenado = NULL;
    ordenado = ordenacaoCrescente(str);

    for(i=0 ; i < N; i++) {
        printf("%s " , ordenado[i]);
    }

    printf("\n");

    ordenado = ordenacaoDecrescente(str);
     for(i=0 ; i < N; i++) {
        printf("%s " , ordenado[i]);
    }

    return 0;
}
