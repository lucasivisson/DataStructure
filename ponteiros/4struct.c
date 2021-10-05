#include <stdio.h>

int main() {
  struct horario {
    int *pHora;
    int *pMinuto;
    int *pSegundo;
  };

  struct horario hoje;

  int hora = 200;
  int minuto = 300;
  int segundo = 400;

  hoje.pHora = &hora;
  hoje.pMinuto= &minuto;
  hoje.pSegundo = &segundo;

  printf("Hora - %i\n", *hoje.pHora);
  printf("Minuto - %i\n", *hoje.pMinuto);
  printf("Segundo - %i\n", *hoje.pSegundo);

  *hoje.pSegundo = 1000;

  printf("Segundo depois de alterado: %i\n", segundo);

  return 0;
}