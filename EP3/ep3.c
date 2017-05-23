#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

/*
 Thiago Inocêncio
*/

typedef struct no No;
struct no {
   char conteudo;
   No *prox;
};

void empilha(char conteudo, No **pilha);
char desempilha(No **pilha);
void imprimePilha(No *pilha);
int bemFormada(char str[]);

void empilha(char conteudo, No **pilha){

    No *temp = malloc(sizeof(No));
    temp->conteudo = conteudo;


    if(*pilha == NULL) {
        *pilha = temp;
        temp->prox = NULL;
    } else {

        temp->prox = *pilha;
        *pilha = temp;

    }

}

void imprimePilha(No *pilha) {

    while(pilha != NULL) {
       printf("%c " , pilha->conteudo);
        pilha = pilha->prox;
    }
}

char desempilha(No **pilha) {

    char conteudo;
    No *temp;
    temp = *pilha;

    if(*pilha == NULL) return ' ';

    conteudo = temp->conteudo;

    *pilha = temp->prox;

    free(temp);

    return conteudo;
}

int bemFormada(char str[]) {

     int i;
     size_t len;
     No *pilha = NULL;

     len = strlen(str);

     for(i = 0; i < len; i++) {
        switch (str[i]) {
            case ' ' : continue;
            case '(' : case '{' : case '[' :
                empilha(str[i], &pilha); break;
            case ')' :
                if(desempilha(&pilha) != '(') return 0;
            break;
            case ']' :
                if(desempilha(&pilha) != '[') return 0;
            break;
            case '}' :
                if(desempilha(&pilha) != '{') return 0;
            break;
            default: continue;
        }
     }

     if(pilha == NULL) return 1;
     else  return 0;

}

int main()
{
    char str1[20] = "( () { ( ) } )";
    char str2[20] = "( ";
    char str3[20] = "( ( ( ) ) )";
    char str4[20] = "{} () [] {[()]}";
    char str5[20] = "( } ) ) { } [";
    char str6[20] = "{           }";
    char str7[20] = "{     ()      }";
    char str8[20] = "{     )(      }";
    char str9[20] = "{[()]}";

    printf("A string %s esta %s\n", str1, bemFormada(str1) ? "Bem formada !" : "Mal formada !");
    printf("A string %s esta %s\n", str2, bemFormada(str2) ? "Bem formada !" : "Mal formada !");
    printf("A string %s esta %s\n", str3, bemFormada(str3) ? "Bem formada !" : "Mal formada !");
    printf("A string %s esta %s\n", str4, bemFormada(str4) ? "Bem formada !" : "Mal formada !");
    printf("A string %s esta %s\n", str5, bemFormada(str5) ? "Bem formada !" : "Mal formada !");
    printf("A string %s esta %s\n", str6, bemFormada(str6) ? "Bem formada !" : "Mal formada !");
    printf("A string %s esta %s\n", str7, bemFormada(str7) ? "Bem formada !" : "Mal formada !");
    printf("A string %s esta %s\n", str8, bemFormada(str8) ? "Bem formada !" : "Mal formada !");
    printf("A string %s esta %s\n", str9, bemFormada(str9) ? "Bem formada !" : "Mal formada !");

    return 0;
}
