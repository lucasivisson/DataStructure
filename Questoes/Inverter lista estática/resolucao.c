/*
Nome: Lucas Ivisson de Farias Santos
Matricula: 1515094
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100

struct lista {
  int qtd;
  int numeros[MAX];
};

typedef struct lista Lista;

Lista* cria_lista(){
  Lista *li;
  li = (Lista *) malloc(sizeof(struct lista));
  if(li != NULL)
    li->qtd = 0;
  return li;
}

void libera_lista(Lista *li){
  free(li);
}

int insere_lista_final(Lista *li, int numero){
  if(li == NULL)
    return 0;
  if(li->qtd == MAX)
    return 0;
  li->numeros[li->qtd] = numero;
  li->qtd++;
  return 1;
}

int inverte_lista(Lista *li, Lista *invertida){
  if(li == NULL) //1+(
    return 0; //1)
  if(invertida == NULL) //1+(
    return 0; //1)
  int i; //1
  for(i = 0; i < li->qtd; i++){ //n*(
    invertida->numeros[li->qtd-1-i] = li->numeros[i]; //1)
  }
  return 1; //1
} // Funcao custo: f(n) = 1+(1)*1+(1)+1+n*(1)+1 = f(n) = 5 + n = f(n) = n
// Complexidade: O(n)

int tamanho_lista(Lista *li){
  if(li == NULL)
    return -1;
  else
    return li->qtd;
}

int main() {
  int i, j, qtd_numeros, numero;
  scanf("%i", &qtd_numeros); //Digite a quantidade de numeros que voce quer inserir:
    
  Lista *lista = cria_lista();
  Lista *invertida = cria_lista();
    
  for(i = 0; i < qtd_numeros; i++){ //Digite os elementos que vc deseja inserir
    scanf("%i", &numero);
    insere_lista_final(lista, numero);
  }
    
  inverte_lista(lista, invertida);
    
  for(j = 0; j < qtd_numeros; j++){
    printf("%i ", invertida->numeros[j]);
  }

  /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
  return 0;
}
