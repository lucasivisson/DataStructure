#include <stdio.h>

int main() {
  struct lista {
    int valor;
    struct lista *proximo; // é um ponteiro que aponta para uma estrutura do tipo lista.
  };

  struct lista m1, m2, m3;
  struct lista *gancho = &m1;

  m1.valor = 10;
  m2.valor = 20;
  m3.valor = 30;

  m1.proximo = &m2;
  m2.proximo = &m3;
  m3.proximo = (struct lista *)0; /* isso quer dizer que o ponteiro esta apontando para uma
  struct lista do tipo ponteiro que aponta para o valor nulo
  */

  while(gancho != (struct lista *)0) {
    printf("%i\n",gancho->valor);
    gancho = gancho->proximo;
  }

  return 0;
}