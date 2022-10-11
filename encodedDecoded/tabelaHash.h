#ifndef TABELA_HASH_H
#define TABELA_HASH_H

//Estrutura das informacoes na tabela
struct Dados {
  int codigo[5];
  char character;
};


typedef struct hash Hash;
typedef struct Dados DADOS;

void decimalpbinario(int newPos, int* codigo);
Hash* criar_hash(int TABLE_SIZE);
int destruir_hash(Hash *ha);
int inserir_endAberto(Hash *ha, char c);
int buscar_hash_endAberto(Hash *ha, char b1, struct Dados *c);
int mostrar_tabela(Hash *ha);
int valorChar(char str);



#endif