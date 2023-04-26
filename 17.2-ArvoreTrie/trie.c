#include <stdlib.h>
#include <string.h>
#include "trie.h"

ASCIITrie* AT_Buscar_R(ASCIITrie* trie, unsigned char *chave, int tamanhoDaString, int profundidade) {
  // verifica se a arvore é nula, se sim retorna null que significa que a palavra não existe na arvore
  if(trie == NULL) {
    return NULL;
  }
  // Quando o tamanho da palavra for igual a quantidade de nós que foram visitados, o nó que vai conter o valor é retornado
  if(profundidade == tamanhoDaString) {
    return trie;
  }
  // Chama a função recursivamente passando o próximo nó que será o nó de acordo com o caractere da palavra que está sendo lida nesse recursão, passa a chave e o tamanho da string novamente e aumenta a quantidade de nós que foram buscados durante a execução do algoritmo.
  return AT_Buscar_R(Trie->filhos[chave[profundidade]], chave, tamanhoDaString, profundidade+1);
}

ASCIITrie* AT_Buscar(ASCIITrie* trie, unsigned char *chave) {
  return AT_Buscar_R(Trie, chave, strlen(chave), 0);
}

ASCIITrie* AT_Criar() {
  ASCIITrie* no;
  no = malloc(sizeof(ASCIITrie));
  no->estado = ATE_LIVRE;
  no->valor = 0;

  for(int i=0; i<256; i++) {
    no->filhos[i] = NULL;
  }
  return no;
}

void AT_Inserir_R(ASCIITrie **trie, unsigned char *chave, int valor, int tamanhoDaString, int profundidade) {
  // Verifica se o Ponteiro para ponteiro é nulo, se sim, criamos um no e apontamos nossa trie para esse no criado.
  if((*trie) == NULL) {
    *trie = AT_Criar();
  }
  // Quando o tamanho da palavra for igual a quantidade de nós que foram visitados, significa que chegamos ao fim da palavra, o nó final recebe o valor da palavra e seu estado é mudado para OCUPADO para significar que ele tem a palavra final e a função acaba.
  if(tamanhoDaString == profundidade) {
    (*trie)->valor = valor;
    (*trie)->estado = ATE_OCUPADO;
    return;
  }
  // Chama a função recursivamente passando o endereço do nó que será o nó de acordo com o caractere da palavra que está sendo lida nesse recursão, passa a chave e o tamanho da string novamente e aumenta a quantidade de nós que foram buscados durante a execução do algoritmo.
  AT_Inserir_R(&(*trie)->filhos[chave[profundidade]], chave, valor, profundidade+1);
}

void AT_Inserir(ASCIITrie **trie, unsigned char *chave, int valor) {
  AT_Inserir_R(trie, chave, valor, strlen(chave), 0);
}

void AT_Remover_R(ASCIITrie **trie, unsigned char *chave, int tamanhoDaString, int profundidade) {
  // Verifica se o Ponteiro para ponteiro é nulo, se sim, retornamos.
  if(*trie == NULL) {
    return;
  }
  // Verificamos se o tamanho da palavra é igual a quantidade de nos percorridos. Se sim, liberamos aquele no, pois antes ele continha um valor. Se não, chamamos a função recursivamente pois ainda tem nos para serem percorridos até chegar no noh que contém o valor final.
  if(tamanhoDaString == profundidade) {
    (*trie)->estado = ATE_LIVRE;
  } else {
    AT_Remover_R(&(*trie)->filhos[chave[profundidade]], chave, tamanhoDaString, profundidade+1);
  }
  //Verifica se o estado do no atual é ocupado, isso significa que ele contém uma palavra associada a ele, se for, retorna.
  if((*trie)->estado == ATE_OCUPADO) {
    return;
  }
  // Faz um loop para verificar se o no atual tem outros nos relacionados a ele com valores diferente de null. Se sim, apenas retorna. Se não, libera o no e atribui seu ponteiro para null, para ser removido na recursão.
  for(int i=0; i<256; i++) {
    if((*trie)->filhos[i] != NULL) {
      return;
    }
  }
  free(*trie);
  *trie = NULL;
}

void AT_Remover(ASCIITrie **trie, unsigned char *chave) {
  AT_Remover_R(trie, chave, strlen(chave), 0);
}