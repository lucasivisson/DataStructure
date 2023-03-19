#include <stdio.h>
#include <stdlib.h>
#include "Cilindro.h"

int main() {
  float raio, altura;
  printf("Digite o raio do cilindro (em metros): \n");
  scanf("%f", &raio);
  printf("Digite a altura do cilindro (em metros): \n");
  scanf("%f", &altura);
  
  Cilindro *cilindro = novoCilindro(raio, altura);

  printf("A altura do cilindro eh de %.2f metros\n", buscaAltura(cilindro));
  printf("O raio do cilindro eh de %.2f metros\n", buscaRaio(cilindro));
  printf("A área total do cilindro eh de %.2f metros quadrados\n", buscaAreaTotal(cilindro));
  printf("O volume do cilindro eh de %.2f metros cubicos\n", buscaVolume(cilindro));
  liberaCilindro(cilindro);
  return 0;
}