#include <stdio.h>

int main(void) {
  struct horario{
    int hora;
    int minuto;
    int segundo;
  };

  struct horario agora, *depois;
  depois = &agora;

  /*
    *depois.hora = 20;
    não podemos fazer isso pois em C, há precedência de sinais e o . é
    executado primeiro que o * fazendo com que a lógica de atribuir 20 a struct agora na variável
    hora seja quebrada, devemos utilizar () para corrigir o erro, ficando assim:
    (*depois).hora = 20; OU
    depois->hora = 20;
  */
  depois->hora = 20;
  depois->minuto = 40;
  depois->segundo = 50;

  int somatorio = 100;

  struct horario antes;

  antes.hora = somatorio + depois->segundo;
  antes.minuto = agora.hora + depois->minuto;
  antes.segundo = depois->minuto + depois->segundo;

  printf("%i:%i:%i\n", antes.hora, antes.minuto, antes.segundo);

  return 0;
}