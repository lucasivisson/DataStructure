#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ArvoreTrie.h"

void menu() {
  printf("\t----------\n");
  printf("\t1-Cadastrar\n");
  printf("\t2-Excluir\n");
  printf("\t3-Imprimir\n");
  printf("\t4-Buscar\n");
  printf("\t5-Sair\n");
  printf("\t----------\n");
}

int main() {
  // setLocale(LC_ALL, "Portuguese");
  ArvTrie *arv = cria_arvore();

  char empilhado[256], removido[256], procurar[256];
  int op, i;

  do {
    menu();
    scanf("%d", &op);

    switch(op) {
      case 1: {
        printf("\nDigite a palavra: ");
        fflush(stdin);
        scanf("%s", &empilhado);
        setbuf(stdin, NULL);
        insere_arvore(&arv, empilhado);
        printf("\n Palavra inserida com sucesso!\n");
      break;
      }

      case 2: {
        printf("\nDigite a palavra que deseja remover\n");
        fflush(stdin);
        scanf("%s", &removido);
        setbuf(stdin, NULL);

        if(procura_arvore(arv, removido)) {
          printf("\nPalavra removida com sucesso!\n");
        } else {
          printf("\nA palavra não existe na árvore\n");
        }
        remove_arvore(&arv, removido);
      break; 
      }
      
      case 3: {
        imprime_arvore(arv);
      break;  
      }

      case 4: {
        printf("\nDigite a palavra que deseja procurar: ");
        fflush(stdin);
        scanf("%s", &procurar);
        setbuf(stdin, NULL);

        if(procura_arvore(arv, procurar)) {
          printf("%s existe na arvore\n", procurar);
        } else {
          printf("%s não existe\n", procurar);
        }

      break;
      }
    }
  } while (op != 5);

  return 0;
}