#include <stdio.h>
#include <stdlib.h>
#include "Conta.h"

int main() {
  contabancaria_t *conta1 = nova_conta(918556, 300.000);

  printf("\nAntes da movimentação: \n");
  imprime(conta1);

  deposito(conta1, 50.00);
  saque(conta1, 70.00);

  printf("\nDepois da movimentação: \n");
  imprime(conta1);

  return 0;
}