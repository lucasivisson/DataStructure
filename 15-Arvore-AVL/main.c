#include <stdlib.h>
#include <stdio.h>

int main() {
    ArvAVL* raiz = cria_ArvAVL();

    int insere = insere_ArvAVL(raiz, valor);

    int estaVazia = estaVazia_ArvAVL(raiz);
    int alt = altura_ArvAVL(raiz);
    int qtdNO = totalNO_ArvAVL(raiz);

    int consulta = consulta_ArvAVL(ArvAVL *raiz, int valor);

    preOrdem_ArvAVL(raiz);
    emOrdem_ArvAVL(raiz);
    posOrdem_ArvAVL(raiz);

    int remove = remove_ArvAVL(raiz, valor);

    libera_ArvAVL(raiz);

    return 0;
}