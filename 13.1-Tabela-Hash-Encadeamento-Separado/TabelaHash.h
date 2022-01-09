#include "ListaDinEncad.h"

typedef struct hash Hash;

Hash* criaHash(int TABLE_SIZE);
int insereHash_SemColisao(Hash *ha, struct aluno al);
int valorString(char *str);
void liberaHash(Hash* ha);
int buscaHash_SemColisao(Hash *ha, int mat, struct aluno *al);