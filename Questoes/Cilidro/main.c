#include <stdio.h>
#include <stdlib.h>
#include "Cylinder.h"

int main() {
  float radius, height;
  printf("Digite o raio do cilindro (em metros): \n");
  scanf("%f", &radius);
  printf("Digite a altura do cilindro (em metros): \n");
  scanf("%f", &height);
  
  Cylinder *cylinder = newCylinder(radius, height);

  printf("A altura do cilindro eh de %.2f metros\n", getHeight(cylinder));
  printf("O raio do cilindro eh de %.2f metros\n", getRadius(cylinder));
  printf("A área total do cilindro eh de %.2f metros quadrados\n", getTotalArea(cylinder));
  printf("O volume do cilindro eh de %.2f metros cubicos\n", getVolume(cylinder));
  freeCylinder(cylinder);
  return 0;
}