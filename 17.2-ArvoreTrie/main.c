#include <stdio.h>
#include "trie.h"

int main(int argc, char** argv) {
  ASCIITrie *trie = NULL;

  AT_Inserir(&trie, "", 42);
  AT_Inserir(&trie, "o", 1);
  AT_Inserir(&trie, "rato", 10);
  AT_Inserir(&trie, "roeu", 11);
  AT_Inserir(&trie, "a", 2);
  AT_Inserir(&trie, "roupa", 12);
  AT_Inserir(&trie, "do", 3);
  AT_Inserir(&trie, "rei", 13);
  AT_Inserir(&trie, "de", 14);
  AT_Inserir(&trie, "roma", 15);

  imprime_arvore(trie);

  ASCIITrie *r;

  r = AT_Buscar(trie, "");

  r = AT_Buscar(trie, "rato");

  r = AT_Buscar(trie, "roeu");

  r = AT_Buscar(trie, "roam");

}
