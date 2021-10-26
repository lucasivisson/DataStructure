struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct fila Fila;

Fila* cria_fila();
void libera_fila(Fila *fi);
