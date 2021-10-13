#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncadDupla.h"

int main() {
  Lista *li; //ponteiro para ponteiro
  li = cria_lista();

  result_tamanho_lista = tamanho_lista(li);
  if(lista_cheia(li)){
    printf("Lista cheia");
  }
  if(lista_vazia(li)){
    printf("Lista cheia");
  }

  int result_insere_lista_inicio = insere_lista_inicio(li, dados_aluno);
  int result_insere_lista_final = insere_lista_final(li, dados_aluno);
  int result_insere_lista_ordenada = insere_lista_final(li, dados_aluno);

  libera_lista(li);

  return 0;
}