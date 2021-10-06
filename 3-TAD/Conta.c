#include <stdio.h>
#include <stdlib.h>
#include "Conta.h"

contabancaria_t* nova_conta(int num, double saldo) {
  contabancaria_t *conta = malloc(sizeof(contabancaria_t));
  if(conta != NULL) {
    conta->numero = num;
    conta->saldo = saldo;
  }
  return conta;
}

void deposito(contabancaria_t *conta, double valor) {
  conta->saldo += valor;
}

void saque(contabancaria_t *conta, double valor) {
  conta->saldo -= valor;
}

void imprime(contabancaria_t *conta) {
  printf("Número: %d\n", conta->numero);
  printf("Saldo: %f\n", conta->saldo);
}
