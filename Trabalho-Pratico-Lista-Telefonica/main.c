#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreAVL.h"
#include "TabelaHash.h"

int main() {
    Hash *ha = criaHash(1427);
    ArvAVL *raiz = cria_ArvAVL();

    int insereComColisao = insereHash_EnderAberto(ha, raiz, 85);
    printf("%d\n", insereComColisao);

    struct dados pessoa;
    pessoa.telefone = 997879611;
    strcpy(pessoa.nome , "Lucas");
    strcpy(pessoa.endereco , "Rua 8 casa 540 vila velha");

    int insere = insere_ArvAVL(raiz, pessoa);
    printf("%d\n", insere);
    int consulta = consulta_ArvAVL(raiz, pessoa);
    printf("%d\n", consulta);
    return 0;
}