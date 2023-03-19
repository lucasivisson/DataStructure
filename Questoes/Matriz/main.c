#include "Matriz.h"
#include <stdio.h>

int main() {
  Matriz *A;

  int linhas, colunas;
  printf("Digite a quantidade de linhas da sua matriz: ");
  scanf("%d", &linhas);
  printf("Digite a quantidade de colunas da sua matriz: ");
  scanf("%d", &colunas);

  A = novaMatriz(linhas, colunas);

  printf("( Matriz A )\n");
  preencherMatriz(A);

  printf("\n\n");
  printf("( Matriz A )\n");
  exibirMatriz(A);

  liberaMatriz(A);

  printf("\n\n");
  return 0;
}