#include <stdio.h>

int main(void) {
  int x;
  x = 10;

  int *ponteiro;
  ponteiro = &x; // o ponteiro aponta para o endereço de memória de x

  printf("%i\n", &x); // com o & acessamos o endereço de memória da variável
  printf("%i\n", *ponteiro); // com * acessamos o valor da variável que o ponteiro está apontando
  printf("%i\n", ponteiro); // sem o * acessamos o valor do endereço de memória da variável que o ponteiro está apontando
  printf("%i\n", &ponteiro);

  return 0;
}