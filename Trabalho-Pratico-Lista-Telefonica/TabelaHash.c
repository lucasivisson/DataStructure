#include <stdlib.h>
#include <string.h>
#include "TabelaHash.h"
#include "ArvoreAVL.h"

struct hash {
    int qtd, TABLE_SIZE;
    ArvAVL *itens;
};

Hash* criaHash(int TABLE_SIZE) {
    Hash *ha = (Hash *) malloc(sizeof(Hash));
    if(ha != NULL) {
        int i;
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (struct NO**) malloc(TABLE_SIZE * sizeof(struct NO*));
        if(ha->itens == NULL) {
            free(ha);
            return NULL;
        }
        ha->qtd = 0;
        for(i=0; i<ha->TABLE_SIZE; i++)
            ha->itens[i] = NULL;
    }
    return ha;
}
