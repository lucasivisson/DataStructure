typedef struct hash Hash;

Hash* criaHash(int TABLE_SIZE);
int insereHash_EnderAberto(Hash *ha, ArvAVL *raiz, int chave);
void liberaHash(Hash* ha);
int valorString(char *str);
/*
int insereHash_SemColisao(Hash *ha, ArvAVL *raiz, int chave);
int buscaHash_SemColisao(Hash *ha, int mat, struct aluno *al);
int buscaHash_EnderAberto(Hash *ha, int mat, struct aluno *al);
*/