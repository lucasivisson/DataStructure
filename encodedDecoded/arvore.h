typedef struct NO{
    char dado;
    struct NO *l, *r;
}NO;

typedef NO* Arvore;

Arvore* criar_arvore();
int inserir_elemento(Arvore* arv, char c, char *pos);
char buscar_elemento(Arvore* arv, char *pos);
void imprimir_arvore_pre(Arvore* arv);
char* getPre(Arvore* arv);
void destruir_arvore(Arvore* arv);