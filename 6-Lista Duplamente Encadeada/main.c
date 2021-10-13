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

  int result_consulta_lista_pos = consulta_lista_pos(li, posicao, &dados_aluno);
  int result_consulta_lista_mat = consulta_lista_mat(li, matricula, &dados_aluno);

  int result_remove_lista_inicio = remove_lista_inicio(li);
  int result_remove_lista_final = remove_lista_final(li);
  int result_remove_lista = remove_lista(li, matricula_aluno);

  libera_lista(li);
  return 0;
}