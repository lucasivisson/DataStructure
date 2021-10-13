#define _CRT_SECURE_NO_WARNINGS
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

//Soma duas matrizes
Matriz* somarMatriz(Matriz *m1, Matriz *m2){
  int lin1, col1, lin2, col2, i, j;
  Matriz *S;
  lin1 = m1->linhas;
  col1 = m1->colunas;
  lin2 = m2->linhas;
  col2 = m2->colunas;
  if(lin1 != lin2 || col1 != col2){
    printf("Matrizes incompativeis!\n");
    exit(4);
  }
  S = novaMatriz(lin1, col1);
  for(i = 0; i < lin1; i++){
    for(j = 0; j < col1; j++){
      S->matriz[i][j] = m1->matriz[i][j] + m2->matriz[i][j];
    }
  }
  return S;
}

//Subtrai duas matrizes
Matriz* subtrairMatriz(Matriz *m1, Matriz *m2){
  int lin1, col1, lin2, col2, i, j;
  Matriz *S;
  lin1 = m1->linhas;
  col1 = m1->colunas;
  lin2 = m2->linhas;
  col2 = m2->colunas;
  if(lin1 != lin2 || col1 != col2){
    printf("Matrizes incompativeis!\n");
    exit(4);
  }
  S = novaMatriz(lin1, col1);
  for(i = 0; i < lin1; i++){
    for(j = 0; j < col1; j++){
      S->matriz[i][j] = m1->matriz[i][j] - m2->matriz[i][j];
    }
  }
  return S;
}

//Transpoe uma matriz
Matriz* transposta(Matriz *m){
  int i, j, lin, col;
  Matriz *T;
  lin = m->linhas;
  col = m->colunas;
  T = novaMatriz(col, lin);
  for(i = 0; i < lin; i++){
    for(j = 0; j < col; j++){
      T->matriz[j][i] = m->matriz[i][j];
    }
  }
  return T;
}

//Multiplica duas matrizes
Matriz* produtoMatriz(Matriz *m1, Matriz *m2){
  int lin1, col1, lin2, col2, i, j, k;
  Matriz *P;
  float temp = 0;

  lin1 = m1->linhas;
  col1 = m1->colunas;
  lin2 = m2->linhas;
  col2 = m2->colunas;

  if(col1 != lin2){
    printf("Matrizes incompativeis!\n");
    exit(6);
  }
  P = novaMatriz(lin1, col2);
  for(i = 0; i < lin1; i++){
    for(k = 0; k < col2; k++){
      for(j = 0; j < col1; j++){
        temp += m1->matriz[i][j] * m2->matriz[j][k];
      }
      P->matriz[i][k] = temp;
      temp = 0;
    }
  }
  return P;
}

//Destroi uma matriz
void liberaMatriz(Matriz *m) {
  int i;
  for(i = 0; i < m->linhas; i++){
    free(m->matriz[i]);
  }
  free(m);
}

//Acessa a quantidade de linhas de uma matriz
int linhasMatriz(Matriz *m){
  if(m == NULL)
    return 0;
  return m->linhas;
}

//Acessa a quantidade de colunas de uma matriz
int Matriz_colunas(Matriz *m){
  if(m == NULL)
    return 0;
  return m->colunas;
}