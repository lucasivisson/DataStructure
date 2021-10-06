#include <stdio.h>

int main() {
  int x;
  double y;
  int vetor[10];

  struct teste {
    int x;
    float y;
  };

  printf("O tamanho do Int é: %li\n", sizeof(x));
  printf("O tamanho do Double é: %li\n", sizeof(y));
  printf("O tamanho do vetor de 10 elementos é: %li\n", sizeof(vetor));
  printf("O tamanho da struct teste é: %li\n", sizeof(struct teste));
  /*
  A função sizeof retorna o tamanho de bytes que um tipo de dado ocupa na memória
  do nosso computador
  */
}