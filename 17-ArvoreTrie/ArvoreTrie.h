#include <stdbool.h>

typedef struct ArvTrie ArvTrie;

ArvTrie *cria_arvore();
bool insere_arvore(ArvTrie **arv, char *texto);
void imprime_arvore_rec(ArvTrie *arv, unsigned char *prefixo, int comprimento);
void imprime_arvore(ArvTrie *arv);
bool procura_arvore(ArvTrie *arv, char *texto);
bool no_tem_filho(ArvTrie *arv);
ArvTrie *remove_arvore_rec(ArvTrie *arv, unsigned char *texto, bool *removido);
bool remove_arvore(ArvTrie **arv, char *texto);