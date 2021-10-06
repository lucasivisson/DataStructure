#include <stdio.h>
#include <stdlib.h>

int main() {
  /*
  Alocação de arrays multidimensionais:
  Para alocar um array com mais de 1 dimensão precisamos utilizar o conceito de "ponteiro
  para ponteiro"
  */

  // ponteiro (1 nível): cria um vetor
  int *n = (int *) calloc(5, sizeof(int));
  // ponteiro para ponteiro (2 níveis): permite criar uma matriz
  int **m;
  // ponteiro para ponteiro para ponteiro (3 níveis): permite criar um array de 3 dimensões
  int ***d;

  /*
  Em um ponteiro para ponteiro, cada nível do ponteiro permite criar uma nova dimensão
  no array.
  int* -> permite criar um array de int
  int** -> permite criar um array de int*
  */

  int **p;

  int i, j, N = 2;
  // criar um array de ponteiros (int *)
  p = (int **) calloc(N, sizeof(int *));
  for(i = 0; i < N; i++) {
    // Cria um array de int
    *(p+i) = (int *) calloc(N, sizeof(int)); /* o valor do ponteiro p vai receber um
    endereço de memória de outro ponteiro.
    pdoemos fazer dessa forma tbm: p[i] = (int *) calloc(N, sizeof(int)); */
    for(j = 0; j < N; j++) {
      scanf("%d", &p[i][j]); 
    } 
  }

  for(i = 0; i < N; i++) {
    for(j = 0; j < N; j++) {
      printf("%i", p[i][j]);
    }
    free(p[i]);
  }
  free(p);

  return 0;
}