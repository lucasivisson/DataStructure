#ifndef CONTA_BANCARIA_H
#define CONTA_BANCARIA_H

//definição do tipo
typedef struct {
  int numero;
  double saldo;
} contabancaria_t;

//cabeçalho das funções
contabancaria_t* nova_conta(int, double);
void deposito(contabancaria_t*, double);
void saque(contabancaria_t*, double);
void imprime(contabancaria_t*);

#endif