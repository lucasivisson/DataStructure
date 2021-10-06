#include <stdio.h>

int main() {
  int vetor[3] = {1, 2, 3};
  int *ponteiro = vetor;
  /*
  quando utilizamos um ponteiro para um vetor, n precisamos passar o & na variavel
  do vetor e o ponteiro vai tá sempre apontando inicialmente para o primeiro membro
  do vetor.
  Podemos utilizar também da seguinte forma:
  int *ponteiro = &vetor[0];
  */

  printf("%i\n", *ponteiro); // a maneira correta de ver o endereço de memoria é com %p

  ponteiro = &vetor[1];
  printf("%i\n", *ponteiro);

  *(ponteiro + 1) = 10; /* Em (ponteiro + 1) estaremos pulando para o proximo endereço
  de memoria, e o * por fora dos () indica que queremos acessar o valor daquele endereço
  de memória. */

  ponteiro = &vetor[2];
  printf("%i\n", *ponteiro);

  return 0;
}