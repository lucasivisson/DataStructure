#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define NUM_CHARS 256

typedef struct ArvTrie {
  struct ArvTrie *filhos[NUM_CHARS];
  bool terminal;
} ArvTrie;

ArvTrie *cria_arvore() {
  ArvTrie *arv = (ArvTrie *) malloc(sizeof(ArvTrie));
  for(int i=0; i<NUM_CHARS; i++) {
    arv->filhos[i] = NULL;
  }
  arv->terminal = false;
  return arv;
}

bool insere_arvore(ArvTrie **arv, char *texto) {
  if(*arv == NULL) {
    *arv = cria_arvore();
  }

  unsigned char *caracter = (unsigned char *) texto;
  ArvTrie *tmp = *arv;

  int comprimento = strlen(texto);

  for(int i = 0; i < comprimento; i++) {
    if(tmp->filhos[caracter[i]] == NULL) {
      tmp->filhos[caracter[i]] = cria_arvore();
    }
    tmp = tmp->filhos[caracter[i]];
  }
  if(tmp->terminal) {
    return false;
  } else {
    tmp->terminal = true;
    return true;
  }
}

void imprime_arvore_rec(ArvTrie *arv, unsigned char *prefixo, int comprimento) {
  unsigned char novoprefixo[comprimento+2];
  memcpy(novoprefixo, prefixo, comprimento);
  novoprefixo[comprimento+1]=0;

  if(arv->terminal) {
    printf("Palavra: %s \n", prefixo);
  }

  for(int i=0; i<NUM_CHARS; i++) {
    if(arv->filhos[i] != NULL) {
      novoprefixo[comprimento] = i;
      imprime_arvore_rec(arv->filhos[i], novoprefixo, comprimento+1);
    }
  }
}

void imprime_arvore(ArvTrie *arv) {
  if(arv == NULL) {
    printf("Arvore Vazia \n");
    return;
  }
  imprime_arvore_rec(arv, NULL, 0);
}

bool procura_arvore(ArvTrie *arv, char *texto) {
  unsigned char *caracter = (unsigned char *) texto;
  int comprimento = strlen(texto);
  ArvTrie *tmp = arv;

  for(int i=0; i<comprimento; i++) {
    if(tmp->filhos[caracter[i]] == NULL) {
      return false;
    }
    tmp = tmp->filhos[caracter[i]];
  }
  return tmp->terminal;
}

bool no_tem_filho(ArvTrie *arv) {
  if(arv == NULL) {
    return false;
  }
  for(int i=0; i<NUM_CHARS; i++) {
    if(arv->filhos[i] != NULL) {
      return true;
    }
  }
  return false;
}

ArvTrie *remove_arvore_rec(ArvTrie *arv, unsigned char *texto, bool *removido) {
  if(arv == NULL) {
    return arv;
  }

  if(*texto == '\0') {
    if(arv->terminal) {
      arv->terminal = false;
      *removido = true;

      if(no_tem_filho(arv) == false) {
        free(arv);
        arv = NULL;
      }
    }
    return arv;
  }

  arv->filhos[texto[0]] = remove_arvore_rec(arv->filhos[texto[0]], texto+1, removido);
  if(*removido && no_tem_filho(arv) == false && arv->terminal == false) {
    free(arv);
    arv = NULL;
  }
  return arv;
}

bool remove_arvore(ArvTrie **arv, char *texto) {
  unsigned char *caracter = (unsigned char *) texto;
  bool resultado = false;

  if(*arv == NULL) {
    return false;
  }

  *arv = remove_arvore_rec(*arv, caracter, &resultado);

  return resultado;
}