#include <stdio.h>
#include <stdlib.h>
#include "TabelaHash.h"

int main() {
    Hash *ha = criaHash(1427);

    int insereSemColisao = insereHash_SemColisao(ha, al);
    int buscaSemColisao = buscaHash_SemColisao(ha, mat, &al_result);

    int insereComColisao = insereHash_EnderAberto(ha, al);
    int buscaComColisao = buscaHash_EnderAberto(ha, mat, &al_result_colisao);

    liberaHash(ha);

    return 0;
}