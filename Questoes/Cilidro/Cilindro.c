#include <stdio.h>
#include <stdlib.h>
#include "Cilindro.h"
#include <math.h>

struct cilindro {
  float raio;
  float altura;
};

Cilindro * novoCilindro(float raio, float altura) {
  Cilindro *cilindro = (Cilindro *) malloc(sizeof(Cilindro));
  if(cilindro != NULL) {
    cilindro->raio = raio;
    cilindro->altura = altura;
  }
  return cilindro;
}

float buscaAltura(Cilindro *cilindro) {
  if(cilindro == NULL) return -1;
  return cilindro->altura;
}

float buscaRaio(Cilindro *cilindro) {
  if(cilindro == NULL) return -1;
  return cilindro->raio;
}

float buscaAreaTotal(Cilindro * cilindro) {
  if(cilindro == NULL) return -1;
  float areaDaBase = 3.14 * pow(cilindro->raio, 2);
  float areaDoLado = 2 * 3.14 * cilindro->raio * cilindro->altura;
  return 2 * areaDaBase + areaDoLado;
}

float buscaVolume(Cilindro * cilindro) {
  if(cilindro == NULL) return -1;
  float areaDaBase = 3.14 * pow(cilindro->raio, 2);
  return areaDaBase * cilindro->altura;
}

void liberaCilindro(Cilindro *cilindro) {
  free(cilindro);
}