typedef struct NO *ArvAVL;

int insere_ArvAVL(ArvAVL *raiz, int telefone, char nome[50], char endereco[50]);
int remove_ArvAVL(ArvAVL *raiz, int valor);
ArvAVL* cria_ArvAVL();
void libera_ArvAVL(ArvAVL *raiz);
int estaVazia_ArvAVL(ArvAVL *raiz);
int altura_ArvAVL(ArvAVL *raiz);
int totalNO_ArvAVL(ArvAVL *raiz);
void preOrdem_ArvAVL(ArvAVL *raiz);
void emOrdem_ArvAVL(ArvAVL *raiz);
void posOrdem_ArvAVL(ArvAVL *raiz);
int consulta_ArvAVL(ArvAVL *raiz, int valor);