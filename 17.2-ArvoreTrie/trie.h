#pragma once

typedef enum ASCIITrie_ESTADO {
  ATE_LIVRE,
  ATE_OCUPADO,
} ASCIITrieESTADO;

typedef struct ASCIITrie {
  int valor;
  ASCIITrie_ESTADO estado;
  struct ASCIITrie *filhos[256];
} ASCIITrie;

ASCIITrie* AT_Buscar(ASCIITrie *trie, unsigned char *chave);
ASCIITrie* AT_Criar();
void AT_Inserir(ASCIITrie **trie, unsigned char *chave, int value);
void AT_Remover(ASCIITrie **trie, unsigned char *chave);
void AT_Imprimir(ASCIITrie *trie);