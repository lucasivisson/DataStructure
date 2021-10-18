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
  Lista *li; // 1 +
  li = (Lista *) malloc(sizeof(struct lista)); // 1 +
  if(li != NULL) // 1 + (
    li->qtd = 0; // 1 )
  return li; //+ 1
} //Funcao Custo: f(n) = 1 + 1 + 1 + (1) + 1 = f(n) = 4
// Complexidade: O(4)

void libera_lista(Lista *li){
  free(li); // 1
} // Funcao Custo: f(n) = 1
//Complexidade: O(1)

int insere_lista_final(Lista *li, int numero){
  if(li == NULL) //1+(
    return 0; // 1)
  if(li->qtd == MAX) //lista cheia //1+(
    return 0; // 1)
  li->numeros[li->qtd] = numero; // 1 +
  li->qtd++; // 1 +
  return 1; // 1
} //Funcao Custo: f(n) = 1+(1)*1+(1)*1+1+1 = f(n) = 1+1+1+1+1 = f(n) = 5
// Complexidade: O(5)

int concatena_lista(Lista *li, Lista *result){
  if(li == NULL) //1+( 
    return 0; //1)
  if(result == NULL) //1+(
    return 0; //1)
  int i; //1+
  for(i = 0; i < li->qtd; i++){ // n*(
    insere_lista_final(result, li->numeros[i]); //1)
  }
  return 1; // 1
} // Funcao Custo: f(n) = 1+(1)*1+(1)+1+n*(1)+1 = f(n) = 1+1+1+1+n+1= f(n) = 5 + n = f(n) = n
//Complexidade: O(n)

int lista_numeros_pares(Lista *li, Lista *pares){
  if(li == NULL) //1+(
    return 0; //1
  if(pares == NULL) //1+(
    return 0; //1
  int i; //1
  for(i = 0; i < li->qtd; i++){ //n*(
    if(li->numeros[i] % 2 == 0){ //1+(
      insere_lista_final(pares, li->numeros[i]); //1   
    } //)
  } //)
  return 1; //1
} // Funcao Custo: f(n) = 1+(1)*1+(1)+1+n*(1+(1))+1 = f(n) = 1+1+1+1+n*(2)+1= f(n) = 5 + 2n = f(n) = n
//Complexidade: O(n)

int tamanho_lista(Lista *li){
  if(li == NULL) //1+(
    return -1; //1)
  else //1+(
    return li->qtd; //1)
}// Funcao Custo: f(n) = 1+(1)*1+(1) = f(n) = 1+1+1 = f(n) = 3 
//Complexidade: O(3)

int main() {
  int i, j, k, l, m, numero;
  int qtd_listas;
  scanf("%i", &qtd_listas); //Digite a quantidade de listas que voce quer inserir:
  int qtd_elementos[qtd_listas];
  for(i = 0; i < qtd_listas; i++){ //Digite a quantidade de elementos que voce quer inserir:
    scanf("%i", &qtd_elementos[i]);
  }
  Lista *lista = cria_lista();
  Lista *result = cria_lista();
  Lista *pares = cria_lista();
    
  for(j = 0; j < qtd_listas; j++){
    libera_lista(lista);
    lista = cria_lista();
    for(k = 0; k < qtd_elementos[j]; k++){
      scanf("%i", &numero);
      insere_lista_final(lista, numero);
    }
    concatena_lista(lista, result);
  }
    
  int tamanho = tamanho_lista(result);
  for(l = 0; l < tamanho; l++){
    printf("%i ", result->numeros[l]);
  }
    
  printf("\n");
    
  lista_numeros_pares(result, pares);
  int tamanho_pares = tamanho_lista(pares);
  if(tamanho_pares == 0){
    printf("0");
  }else{
    for(m = 0; m < tamanho_pares; m++){
      printf("%i ", pares->numeros[m]);
    }   
  }
    

  /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
  return 0;
}
