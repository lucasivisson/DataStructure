#include <stdio.h>
#include "ArvoreBinaria.h"

int main() {
    ArvBin* raiz = cria_ArvBin();

    int insere = insere_ArvBin(raiz, valor);

    int estaVazia = estaVazia_ArvBin(raiz);
    int alt = altura_ArvBin(raiz);
    int qtdNO = totalNO_ArvBin(raiz);

    int consulta = consulta_ArvBin(ArvBin *raiz, int valor);

    preOrdem_ArvBin(raiz);
    emOrdem_ArvBin(raiz);
    posOrdem_ArvBin(raiz);

    int remove = remove_ArvBin(raiz, valor);

    libera_ArvBin(raiz);

    return 0;
}