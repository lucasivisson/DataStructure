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

int remove_lista_final(Lista *li){
  if(li == NULL) // 1+(
    return 0; // 1)
  if((*li) == NULL) //lista vazia //1+(
    return 0; //1)
  
  Elem *ant, *no = *li; //1+
  while(no->prox != NULL){ //n+(
    ant = no; //1+
    no = no->prox; //1)
  }

  if(no == (*li)) //remover o primeiro? //1+(
    *li = no->prox; //1)
  else //1+(
    ant->prox = no->prox; //1)
  free(no); //1+
  return 1; //1
} //Funcao de custo: f(n) = 1+(1)*1+(1)+1+n*(1+1)+1+(1)+1+(1)+1+1 = f(n) = 4+n*(2)+6 = f(n) = 10+2n = f(n) = n
//Complexidade: O(n)

int inverte_lista_dinamica(Lista *li, Lista *invertida){
  if(li == NULL) //1+(
    return 0; //1)
  if((*li) == NULL) //lista vazia //1+(
    return 0; //1)
  if(invertida == NULL) // 1+(
    return 0; // 1)
  int i, tamanho = tamanho_lista(li); //1+
  Elem *no; // 1
  for(i = 0; i < tamanho; i++){ // n*(
    no = *li; // 1+
    while(no->prox != NULL){ // n*(
      no = no->prox; // 1)
    }
    insere_lista_final(invertida, no->numero); //n+
    remove_lista_final(li); //n
  }
  return 1; //1
}//Funcao de custo: f(n) = 1+(1)+1+(1)+1+(1)+1+1+n*(1+n*(1)+n+n)+1 = f(n) = 8+n*(1+3n)+1 = f(n) = 9+n+3n^2 = f(n) = n^2
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
  int i, qtd_numeros, numero;
  scanf("%i", &qtd_numeros); //Digite a quantidade de numeros que voce quer inserir:
    
  Lista *lista = cria_lista();
  Lista *invertida = cria_lista();
    
  for(i = 0; i < qtd_numeros; i++){ //Digite os elementos que vc deseja inserir
    scanf("%i", &numero);
    insere_lista_final(lista, numero);
  }
    
  inverte_lista_dinamica(lista, invertida);
    
  exibe_lista_dinamica(invertida);

  /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
  return 0;
}
