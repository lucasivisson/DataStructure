/*
Aluno: Lucas Ivisson de Farias Santos
Matricula: 1515094
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct elemento{
  int numero;
  struct elemento *prox;
};

typedef struct elemento Elem;

typedef struct elemento* Lista;

Lista* cria_lista() {
  Lista *li = (Lista *) malloc(sizeof(Lista));
  if(li != NULL)
    *li = NULL;
  return li;
}

void libera_lista(Lista *li) {
  if(li != NULL){
    Elem *no;
    while((*li) != NULL){
      no = *li;
      *li = (*li)->prox;
      free(no);
    }
    free(li);
  }
}

int insere_lista_final(Lista *li, int numero){
  if(li == NULL) //1+(
    return 0; //1)
  Elem *no; //1+
  no = (Elem *) malloc(sizeof(Elem)); //1+
  if(no == NULL) //1+(
    return 0; //1)
  no->numero = numero; //1+
  no->prox = NULL; //1+
  if((*li) == NULL){ //1+(
    *li = no; //1)
  }else{ //1+(
    Elem *aux; //1+
    aux = *li; //1+
    while(aux->prox  != NULL){ //n*
      aux = aux->prox; //1)
    }
    aux->prox = no; //1)
  }
  return 1; //1
}//Funcao de custo: f(n) = 1+(1)+1+1+1+(1)+1+1+1+(1)*1+(1+1+n*(1)+1)+1 = f(n) = 10+(2+n+1)+1 = f(n) = 11+(3+n) = f(n) = n
//Complexidade: O(n)

int tamanho_lista(Lista *li){
  if(li == NULL)
    return 0;
  int cont = 0;
  Elem *no = *li;
  while(no != NULL){
    cont++;
    no = no->prox;
  }
  return cont;
}

int concatena_lista(Lista *li, Lista *result){
  if(li == NULL) //1+( 
    return 0; //1)
  if(result == NULL) //1+(
    return 0; //1)
  int i, tamanho = tamanho_lista(li); //1+
  Elem *no = *li; //1+
  for(i = 0; i < tamanho; i++){ // n*(
    insere_lista_final(result, no->numero); //n+
    no = no->prox; //1)
  }
  return 1; // 1
} // Funcao Custo: f(n) = 1+(1)*1+(1)+1+1+n*(n+(1))+1 = f(n) = 5+n*(n+(1))+1= f(n) = 6+n^2+n = f(n) = n^2
//Complexidade: O(n^2)

int lista_numeros_pares(Lista *li, Lista *pares){
  if(li == NULL) //1+(
    return 0; //1
  if(pares == NULL) //1+(
    return 0; //1
  int i, tamanho = tamanho_lista(li); //1
  Elem *no = *li; //1+
  for(i = 0; i < tamanho; i++){ //n*(
    if(no->numero % 2 == 0){ //1+(
      insere_lista_final(pares, no->numero); //n   
    } //)
    no= no->prox; //1
  } //)
  return 1; //1
} // Funcao Custo: f(n) = 1+(1)*1+(1)+1+1+n*(1+(n))+1+1 = f(n) = 5+n*(1+(n))+2= f(n) = 7+n+n^2 = f(n) = n^2
//Complexidade: O(n^2)

int exibe_lista_dinamica(Lista *li){
  if(li == NULL)
    return 0;
  if((*li) == NULL) //lista vazia
    return 0;
  int i;
  int tamanho = tamanho_lista(li);
  Elem *no = *li;
  for(i = 0; i < tamanho; i++){
    printf("%i ", no->numero);
    no = no->prox;
  }
  return 1;
}

int main() {
int i, j, k, numero;
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

  exibe_lista_dinamica(result);
    
  lista_numeros_pares(result, pares);
  
  printf("\n");

  int tamanho_pares = tamanho_lista(pares);
  if(tamanho_pares == 0){
    printf("0");
  }else{
    exibe_lista_dinamica(pares);  
  }
    

  /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
  return 0;
}
