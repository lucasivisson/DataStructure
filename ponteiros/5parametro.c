#include <stdio.h>

int main() {
  void testeVariavel(int x);
  void testePonteiro(int *pX);
  int teste = 1;
  int *pTeste = &teste;

  testeVariavel(teste);
  testePonteiro(pTeste); /* devemos passar o ponteiro sem o * pois assim estaremos passando
  corretamente. Se passarmos o ponteiro como parametro usando o * estaremos passando o seu
  valor e n o endereço de memoria que o ponteiro aponta.
  */
  printf("%i\n", teste); 

  return 0;
}

void testeVariavel(int x) { // a função recebe uma copia do valor de x
  ++x;
}

void testePonteiro(int *pX) { // a função recebe um ponteiro que aponta para x
  ++*pX;
}