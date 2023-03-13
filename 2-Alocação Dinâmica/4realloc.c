#include <stdio.h>
#include <stdlib.h>

int main() {
  /*função calloc():
    Serve para alocar memória durante a execução do programa.
    Ela faz o pedido de memória ao computador e retorna um ponteiro com o endereço do
    início do espaço de memória alocado.
    Funcinamento:
    A função realloc() recebe por parâmetro:
    - ponteiro para um bloco de memória já alocado;
    - a quantidade de bytes a ser alocada.
    e retorna:
    - NULL: no caso de erro;
    - ponteiro para a primeira posição do array.
  */

  //Exemplo:
  //Cria um array de 50 inteiros (200 bytes)
  int *v = (int *) malloc(50 * sizeof(int));
  //Aumenta a memória alocada para 100 inteiros (200 bytes)
  v = (int *) realloc(v, 100 * sizeof(int));

  /*
  Se o ponteiro para o bloco de memória previamente alocado for NULL, a função realloc()
  irá alocar memória da mesma forma como a função malloc().
  */
  int *p = (int *) realloc(NULL, 50 * sizeof(int));

  free(v);
  free(p);

  return 0;
}