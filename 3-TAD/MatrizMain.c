#include "Matriz.h"
#include <stdio.h>

int main() {
  Matriz *A, *B, *C;

  A = novaMatriz(2,2);
  B = novaMatriz(2,2);

  printf("( Matriz A )\n");
  preencherMatriz(A);

  printf("\n\n");
  printf("( Matriz B )\n");
  preencherMatriz(B);

  printf("\n\n");
  printf("( Matriz A )\n");
  exibirMatriz(A);

  printf("\n\n");
  printf("( Matriz B )\n");
  exibirMatriz(B);

  printf("\n\n");

  C = somarMatriz(A,B);
  printf("( A + B )\n");
  exibirMatriz(C);

  printf("\n\n");

  C = subtrairMatriz(A,B);
  printf("( A - B )\n");
  exibirMatriz(C);

  printf("\n\n");

  C = transposta(somarMatriz(A,B));
  printf("( Transposta de A + B )\n");
  exibirMatriz(C);

  printf("\n\n");

  C = produtoMatriz(A,B);
  printf("( A * B )\n");
  exibirMatriz(C);

  printf("\n\n");
  return 0;
}