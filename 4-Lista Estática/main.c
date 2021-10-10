#include <stdio.h>
#include <string.h>
#include "ListaSequencial.h"

int main() {
  Lista *lista = cria_lista();

  struct aluno al1;
  al1.matricula = 123;
  strcpy(al1.nome , "Lucas");
  al1.n1 = 8;
  al1.n2 = 9;
  al1.n3 = 10;

  struct aluno al2;
  al2.matricula = 223;
  strcpy(al2.nome , "Matheus");
  al2.n1 = 8;
  al2.n2 = 9;
  al2.n3 = 9;

  struct aluno al3;
  al3.matricula = 323;
  strcpy(al3.nome , "Marta");
  al3.n1 = 8;
  al3.n2 = 9;
  al3.n3 = 10;

  struct aluno al4;
  al4.matricula = 205;
  strcpy(al4.nome , "Monica");
  al4.n1 = 7;
  al4.n2 = 6;
  al4.n3 = 10;

  if(insere_lista_inicio(lista, al1)) {
    printf("Aluno(a) %s inserido com sucesso no início da lista\n", al1.nome);
  }
  if(insere_lista_final(lista, al2)) {
    printf("Aluno(a) %s inserido com sucesso no final da lista\n", al2.nome);
  }
  if(insere_lista_ordenada(lista, al3)) {
    printf("Aluno(a) %s inserido com sucesso na lista\n", al3.nome);
  }
  if(insere_lista_ordenada(lista, al4)) {
    printf("Aluno(a) %s inserido com sucesso na lista\n", al4.nome);
  }

  if(lista_vazia(lista)) {
    printf("A lista esta vazia\n");
  } else if(lista_cheia(lista)) {
      printf("A lista esta vazia\n");
    } else if(tamanho_lista(lista)) {
      printf("A lista tem %i itens\n", tamanho_lista(lista));
  } 
  
  struct aluno al_busca;

  if(busca_lista_pos(lista, 2, &al_busca)) {
    printf("Aluno(a) %s da posição 2 encontrado com sucesso\n", al_busca.nome);
  }

  if(busca_lista_mat(lista, 123, &al_busca)) {
    printf("Aluno(a) %s da matricula 123 encontrado com sucesso\n", al_busca.nome);
  }

  if(remove_lista_inicio(lista)) {
    printf("Aluno do inicio da lista removido com sucesso\n");
  }

  if(busca_lista_pos(lista, 2, &al_busca)) {
    printf("Aluno(a) %s da posição 2 encontrado com sucesso\n", al_busca.nome);
  }

  if(remove_lista_final(lista)) {
    printf("Aluno do final da lista removido com sucesso\n");
  }

  if(remove_lista_otimizado(lista, 205)) {
    printf("Aluno da matricula 205 da lista removido com sucesso\n");
  }

  if(remove_lista(lista, 223)) {
    printf("Aluno da matricula 223 da lista removido com sucesso\n");
  }

  if(lista_vazia(lista)) {
    printf("A lista esta vazia\n");
  } else if(lista_cheia(lista)) {
      printf("A lista esta vazia\n");
    } else if(tamanho_lista(lista)) {
      printf("A lista tem %i item(ns)\n", tamanho_lista(lista));
  } 

  libera_lista(lista);

  return 0;
}