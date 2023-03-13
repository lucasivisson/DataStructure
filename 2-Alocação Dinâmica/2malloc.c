#include <stdio.h>
#include <stdlib.h>

int main() {
  /*função malloc():
    Serve para alocar memória durante a execução do programa.
    Ela faz o pedido de memória ao computador e retorna um ponteiro com o endereço do
    início do espaço de memória alocado.
    Funcinamento:
    A função malloc() recebe por parâmetro a quantidade de bytes a ser alocada e retorna:
    NULL: no caso de erro ou
    Ponteiro para a primeira posição do array.
  */
 
  /*
  Alocamos por meio do malloc um espaço de memória 10 vezes maior(40 bytes) do tamanho de um
  tipo inteiro no ponteiro p
  A função malloc retorna um ponteiro do tipo void e para resolver esse problema
  precisamos utilizar o casting que é forçar um molde do tipo de retorno da função
  para o que desejamos e para isso usamos (int *), ou seja, o retorno da função agora
  deixa de ser void e passa a ser um ponteiro do tipo inteiro.
  */
  int *p = (int *) malloc(10 * sizeof(int));

  if(p == NULL) {
    printf("malloc não funcionou");
  }

  *p = 1000;

  printf("%i\n", *p);

  free(p); /* libera o espaço de memória que o ponteiro p esta apontando para outro
  programa do pc poder utilizar
  */
  return 0;
}