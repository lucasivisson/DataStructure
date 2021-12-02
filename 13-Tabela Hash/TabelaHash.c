#include <stdlib.h>
#include <string.h>
#include "TabelaHash.h"

struct hash {
    int qtd, TABLE_SIZE;
    struct aluno **itens;
}

Hash* criaHash(int TABLE_SIZE) {
    Hash *ha = (Hash *) malloc(sizeof(Hash));
    if(ha != NULL) {
        int i;
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (struct aluno**) malloc(TABLE_SIZE * sizeof(struct aluno*));
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

void liberaHash(Hash *ha) {
    if(ha != NULL) {
        int i;
        for(i=0; i<ha->TABLE_SIZE; i++) {
            if(ha->itens[i] != NULL)
                free(ha->itens[i]);
        }
        free(ha->itens);
        free(ha);
    }
}

/*
Metodo da Divisao: Consiste em calcular o "resto da divisão" do valor inteiro que
representa o elemento pelo tamanho da tabela, "TABLE_SIZE".

- A operação de "E bit-a-bit" com o valor 0x7FFFFFFF elimina o bit de sinal do
valor da "chave".
- Evita o risco de ocorrer um overflow e obtermos um número negativo
*/

int chaveDivisao(int chave, int TABLE_SIZE) {
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
}