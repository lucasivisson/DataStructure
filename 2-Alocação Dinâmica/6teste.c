#include <stdio.h>
#include <stdlib.h>

int main(){
  struct data {
    int dia;
    int mes;
    int ano;
  };
  typedef struct data Data;

  Data *d = (Data *) malloc(sizeof(Data));
  d->dia = 10;
  printf("endereço de d: %i\n", &d);
  printf("endereço de que d aponta: %i\n", d);
  printf("valor do dia: %i\n", (*d).dia);
  return 0;
}