#include <stdlib.h>
#include "trie.h"

ASCIITrie* ATE_Buscar_R(ASCIITrie* trie, unsigned char *chave, int tamanhoDaString, int profundidade) {
  if(trie == NULL) {
    return NULL;
  }
  if(profundidade == tamanhoDaString) {
    return trie;
  }
  return ATE_Buscar_R(Trie->filhos[chave[profundidade]], chave, tamanhoDaString, profundidade+1);
}

ASCIITrie* ATE_Buscar(ASCIITrie* trie, unsigned char *chave) {
  return ATE_Buscar_R(Trie, chave, strlen(chave), 0);
}