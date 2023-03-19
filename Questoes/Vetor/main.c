#include <stdio.h>
#include <stdlib.h>
#include "Vetor.h"

int main() {
  int tamanhoVetor;
  printf("Digite o tamanho do seu vetor: ");
  scanf("%d", &tamanhoVetor);
  Vetor *v = novoVetor(tamanhoVetor);
  preencheVetor(v);
  exibeVetor(v);
  liberaVetor(v);

  return 0;
}