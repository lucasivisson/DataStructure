struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct NO *ArvAVL;

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