#include <stdio.h>
#include "trie.h"

int main(int argc, char** argv) {
  ASCIITrie *trie = NULL;

  AT_Inserir(&T, "", 42);
  AT_Inserir(&T, "o", 1);
  AT_Inserir(&T, "rato", 10);
  AT_Inserir(&T, "roeu", 11);
  AT_Inserir(&T, "a", 2);
  AT_Inserir(&T, "roupa", 12);
  AT_Inserir(&T, "do", 3);
  AT_Inserir(&T, "rei", 13);
  AT_Inserir(&T, "de", 14);
  AT_Inserir(&T, "roma", 15);

  ASCIITrie *r;

  r = AT_Buscar(trie, "");

  r = AT_Buscar(trie, "rato");

  r = AT_Buscar(trie, "roeu");

  r = AT_Buscar(trie, "roam");

}
