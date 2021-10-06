#include <stdio.h>
#include <stdlib.h>

int main() {
  /*função calloc():
    Serve para alocar memória durante a execução do programa.
    Ela faz o pedido de memória ao computador e retorna um ponteiro com o endereço do
    início do espaço de memória alocado.
    Funcinamento:
    A função calloc() recebe por parâmetro o numero do array a ser alocado e o tamanho
    de cada elemento do array e retorna:
    NULL: no caso de erro ou
    Ponteiro para a primeira posição do array.
    OBS: Diferente de malloc, a função calloc limpa o espaço de memória que ela vai 
    utilizar na alocação
  */

  int *p = (int *) calloc(10, sizeof(int));
  /*
  O primeiro parametro do calloc significa a quantidade de vezes que vc vai alocar
  o espaço de memória passado no segundo parâmetro
  */

  if(p == NULL) {
    printf("malloc não funcionou");
  }

  *(p+1) = 10; // o segundo endereço de memória alocado do array recebe o valor 10

  for(int i = 0; i < 10; i++) {
    printf("Endereço de p%i = %p | Valor de p%i = %i\n", i, (p+i), i, p[i]);
  }

  free(p);

  return 0;
}