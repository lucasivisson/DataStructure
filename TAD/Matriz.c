#include <stdlib.h>
#include <math.h>
#include "Matriz.h" // Inclui os protótipos

struct matriz { //Definição do tipos de dados
  int n;
  int m;
};
//Cria uma matriz
Matriz* Matriz_cria(int n, int m) {
  Matriz* matriz = (Matriz*) malloc(sizeof(Matriz));
  if(matriz != NULL) {
    matriz->n = n;
    matriz->m = m;
  }
  return matriz;
}
//Destroi uma matriz
void Matriz_libera(Matriz *matriz) {
  free(matriz);
}
//Acessa a quantidade de linhas de uma matriz
int Matriz_linhas(Matriz *matriz, int *n);
  if(matriz == NULL)
    return 0;
  *n = matriz->n;
}
//Acessa a quantidade de colunas de uma matriz
int Matriz_colunas(Matriz *matriz, int *m);
  if(matriz == NULL)
    return 0;
  *m = matriz->m;
}