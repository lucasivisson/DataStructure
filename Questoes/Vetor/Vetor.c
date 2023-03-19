#include <stdio.h>
#include <stdlib.h>
#include "Vetor.h" // Inclui os protótipos

struct vetor { // Definição do tipo de dados
  int tamanho;
  float *vetor;
};

//Cria um vetor
Vetor * novoVetor(int tamanho) {
  Vetor *v = (Vetor *) malloc(sizeof(Vetor));
  if(v == NULL) {
    printf("Erro de memória!\n");
    exit(2);
  }
  v->tamanho = tamanho;
  v->vetor = (float *) calloc(tamanho, sizeof(float)); /* Cria um vetor dinamicamente alocando a quantidade de memória definida pelo usuário pela quantidade de valores dentro do vetor */ 
  if(v->vetor == NULL) {
    printf("Erro de memória!\n");
    exit(2);
  }
  return v;
}

//Preenche o vetor
void preencheVetor(Vetor *v) {
  for(int i=0; i<v->tamanho; i++) {
    printf("Elemento A%i: ", i+1);
    scanf("%f", v->vetor+i); /* passa para a posição da memória seguinte e atribui valor a aquela posição de memória que o ponteiro está apontando */
  }
}

// exibe o vetor
void exibeVetor(Vetor *v) {
  printf("[");
  for(int i=0; i<v->tamanho; i++) {
    printf(" %.1f ", *(v->vetor+i)); /* passa para a posição da memória seguinte e pega o valor daquele ponteiro */
  }
  printf("]\n");
}

// libera o vetor
void liberaVetor(Vetor *v) {
  free(v->vetor); // libera o ponteiro para ponteiro
  free(v); // libera o ponteiro principal
}