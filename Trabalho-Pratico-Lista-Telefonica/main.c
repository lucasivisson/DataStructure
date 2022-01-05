#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"
#include "TabelaHash.h"

int main() {
    Hash *ha = criaHash(1427);
    ArvAVL* raiz = cria_ArvAVL();

    int insere = insere_ArvAVL(raiz, 997879611, "Lucas", "Rua 8 casa 540");
    printf("%d\n", insere);
    int consulta = consulta_ArvAVL(raiz, 997879611);
    printf("%d\n", consulta);
    return 0;
}