#include <stdlib.h>
#include <stdio.h>
#include "Matriz.h" // Inclui os protótipos

struct matriz { //Definição do tipos de dados
  int linhas;
  int colunas;
  float **matriz;
};
//Cria uma matriz
Matriz* novaMatriz(int linhas, int colunas){
  int i;
  if(linhas < 1 || colunas < 1){
    printf("Numeros de linhas ou colunas invalido!\n");
    exit(1);
  }
  Matriz *m = (Matriz*) malloc(sizeof(Matriz));
  if(m == NULL) {
    printf("Erro de memória!\n");
    exit(2);
  }
  m->linhas = linhas;
  m->colunas = colunas;
  m->matriz = (float **) malloc(linhas * sizeof(float *)); /*Aloca "n" espaços de memoria
  e em cada espaço de memoria vai guardar o valor de um ponteiro.*/
  if(m->matriz == NULL){
    printf("Erro de memoria!\n");
    exit(2);
  }
  for(i = 0; i < linhas; i++){
    m->matriz[i] = (float *) calloc(colunas, sizeof(float));/*Cada linha do ponteiro vai
    receber um espaço de memória de "n" colunas*/
    if(m->matriz[i] == NULL){
      printf("Erro de memoria!\n");
      exit(3);
    }
  }
  return m;
}

//Preenche a matriz
void preencherMatriz(Matriz *m){
  int i, j;
  for(i = 0; i < m->linhas; i++){
    for(j = 0; j < m->colunas; j++){
      printf("Elemento A%i%i: ", i+1, j+1);
      scanf("%f", &m->matriz[i][j]);
    }
  }
}

// Exibindo os elementos de uma matriz
void exibirMatriz(Matriz *m) {
  int i, j;
  for(i = 0; i < m->linhas; i++){
    printf("|");
    for(j = 0; j < m->colunas; j++){
      printf("%5.1f", m->matriz[i][j]);
    }
    printf(" |\n");
  }
}

//Destroi uma matriz
void liberaMatriz(Matriz *m) {
  int i;
  for(i = 0; i < m->linhas; i++){
    free(m->matriz[i]); // libera todos os ponteiro para ponteiro
  }
  free(m); // libera o ponteiro principal
}