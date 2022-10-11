#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tabelaHash.h" //incluindo a interface

//tipo do hash
struct hash {
  int qtd, TABLE_SIZE;
  struct Dados **itens;
};

Hash* criar_hash(int TABLE_SIZE){
  Hash *ha = (Hash*) malloc(sizeof(Hash)); //criando o ponteiro da tabela completa
  if(ha != NULL){
    ha->TABLE_SIZE = TABLE_SIZE;//salvando o tamanho da tabela
    //criando as linhas da tabela, do tipo PESSOA ponteiro para ponteiro, com o espaço de cada estrutura Pessoa multiplicado pelo tamanho da tabela.
    ha->itens = (struct Dados **)malloc(TABLE_SIZE * sizeof(struct Dados*));
    if(ha->itens == NULL){
      //caso de erro a alocação das linhas da tabela
      free(ha);
      return NULL;
    }
    //deixando todos os valores de cada linha vazios
    for(int i = 0; i<TABLE_SIZE; i++){
      ha->itens[i] = NULL;
    }
    ha->qtd = 0;
  }

  return ha;
}; 

int destruir_hash(Hash *ha){
  if(ha == NULL){
    return 0; //verificando se a tabela existe
  }
  for(int i = 0; i < ha->TABLE_SIZE; i++){
    free(ha->itens[i]); //limpando cada celula da tabela
  }
  free(ha->itens); //destruindo o array
  free(ha); //destruindo a tabela
  return 1;
};

//FUNCOES DE CALCULO DO HASH
int chaveDivisao(int chave, int TABLE_SIZE){
  return (chave & 0x7FFFFFFF) % TABLE_SIZE; //retirando o sinal de negativo, caso tenha, do numero e dividindo pelo tamanho total da tabela
};

int valorChar(char str){
  int valor = 7;
  valor = 31 * valor + (int) str;
  return valor;
}


void decimalpbinario(int newPos, int *codigo) {
  int aux;
  int posVectorBin=5;
  for (aux = 31; aux >= 0; aux--){
    if(posVectorBin!=0){
      posVectorBin--;
      if (newPos % 2 == 0){ 
        codigo[posVectorBin] = 0;
      } else{
        codigo[posVectorBin] = 1;
      }
      newPos = newPos / 2;
    }
  }
   return;
}


//sondagem linear (apenas incrementando novas posicoes ate achar uma vaga no array)
int sondagem_linear(int pos, int i, int TABLE_SIZE){
  return ((pos + i) & 0x7FFFFFFF) % TABLE_SIZE;
};

//enderecamento aberto
int inserir_endAberto(Hash *ha, char c){
  if (ha == NULL || ha->qtd == ha->TABLE_SIZE){
    return 0; //sem exito ao inserir elemento
  }
  int chave = valorChar(c);
  int pos = chaveDivisao(chave, ha->TABLE_SIZE); //primeiro hash. poderia ser qualquer outro, como multiplicacao ou dobra.
  int newPos;
  for(int i = 0; i < ha->TABLE_SIZE; i++){
    newPos = sondagem_linear(pos, i, ha->TABLE_SIZE);
    // newPos = duplo_hash(pos, chave, i, ha->TABLE_SIZE);
    if (ha->itens[newPos] == NULL){ 
      struct Dados *d2;
      d2 = (struct Dados*) malloc(sizeof(struct Dados));
      if(d2 == NULL){
        return 0; //falha ao alocar espaco
      } 
      d2->character = c;
      decimalpbinario(newPos, d2->codigo);
      ha->itens[newPos] = d2;
      ha->qtd++;
      return 1; //operacao funcionou
    }
  }
  return 0;
};

int buscar_hash_endAberto(Hash *ha, char character, struct Dados *p1){
  if (ha == NULL){
    return 0; //sem exito ao inserir elemento
  }
  int chave = valorChar(character);
  int pos = chaveDivisao(chave, ha->TABLE_SIZE);
  int newPos;
  for(int i = 0; i<ha->TABLE_SIZE; i++){
    newPos = sondagem_linear(pos, i, ha->TABLE_SIZE);
    if(ha->itens[newPos]->character == character){
      *p1 = *ha->itens[newPos];
      return 1; //encontrou
    }
    if(ha->itens[newPos] == NULL){
      return 0; //se esta nulo, o elemento nao esta na tabela, pois se estiver nulo significa que ainda nao chegaram informacoes ate esta posicao.
    }
  }  
  return 0; //not found
};


int mostrar_tabela(Hash *ha){
  if(ha == NULL){
    printf("Esta tabela não existe!\n");
    return 1;
  }
  printf("\n**Mostrando tabela:**\n");
  for(int i = 0; i < ha->TABLE_SIZE; i++){
    if(ha->itens[i] != NULL) {
      printf("    %c  |  ", ha->itens[i]->character);
      for(int j = 0; j<5;j++) {
       printf("%d", ha->itens[i]->codigo[j]);
      }
      printf("\n");
    }
  }
  return 1;
}

