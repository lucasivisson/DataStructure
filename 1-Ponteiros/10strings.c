#include <stdio.h>

void copiarString(char *copiarDaqui, char *colarAqui) {
  while(*copiarDaqui != '\0') { /* no fim de cada string a linguagem C coloca o último
  caractere como nulo */
    *colarAqui = *copiarDaqui;
    ++copiarDaqui; // Subimos uma posição no vetor
    ++colarAqui; // Subimos uma posição no vetor
  }
  *colarAqui = '\0';
}

int main() {
  void copiarString(char *copiarDaqui, char *colarAqui);

  char string1[] = "Pao com mortadela";
  char string2[20];

  copiarString(string1, string2);
  printf("%s\n", string2);
  /*
  quando usamos o %s para imprimir uma string, para a string ser imprimida corretamente
  precisamos passar uma string que contenha o caractere nulo ao final dela para o C poder
  ler ela corretamente
  */
  return 0;
}