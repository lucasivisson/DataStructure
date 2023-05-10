#include <stdio.h>

int X(int a) {
  if(a<=0)
    return 0;
  else
    return a+X(a-1);
};

int X_nao_recursivo(int a) {
  int resultado = 0;
  for(int i=a; i>0; i--) {
    resultado += i;
  }
  return resultado;
}

int main() {
  int resultado = X(6);
  int resultado_nao_recursivo = X(6);

  printf("resultado = %d\n", resultado);
  printf("resultado nao recursivo = %d\n", resultado_nao_recursivo);

  return 0;
}