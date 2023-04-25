#pragma once

typedef enum ASCIITrie_ESTADO {
  ATE_LIVRE,
  ATE_OCUPADO
} ASCIITrieESTADO;

typedef struct ASCIITrie {
  int valor;
  ASCIITrie_ESTADO estado;
  struct ASCIITrie *filhos[256];
} ASCIITrie;

ASCIITrie* ATE_Buscar(ASCIITrie* trie, unsigned char *chave);