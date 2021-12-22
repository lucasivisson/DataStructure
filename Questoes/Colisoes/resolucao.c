#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct hash {
    int qtd, TABLE_SIZE;
    int **numeros;
};

typedef struct hash Hash;

int hashMod(int numero, int TABLE_SIZE) {
    return numero % TABLE_SIZE;
}

int sondagemLinear(int pos, int i, int TABLE_SIZE) {
    return ((pos + i) & 0x7FFFFFFF) % TABLE_SIZE;
}

Hash* criaHash(int TABLE_SIZE) {
    Hash *ha = (Hash *) malloc(sizeof(Hash));
    if(ha != NULL) {
        int i;
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->numeros = (int**) malloc(TABLE_SIZE * sizeof(int*));
        if(ha->numeros == NULL) {
            free(ha);
            return NULL;
        }
        ha->qtd = 0;
        for(i=0; i<ha->TABLE_SIZE; i++)
            ha->numeros[i] = NULL;
    }
    return ha;
}

void liberaHash(Hash *ha) {
    if(ha != NULL) {
        int i;
        for(i=0; i<ha->TABLE_SIZE; i++) {
            if(ha->numeros[i] != NULL)
                free(ha->numeros[i]);
        }
        free(ha->numeros);
        free(ha);
    }
}

int insereHash_EnderAberto(Hash *ha, int numero) {
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE) //1
        return 0; //1
    int chave = numero; //1
    int colisao, pos; //1
    colisao = 0; //1
    pos = hashMod(chave, ha->TABLE_SIZE); //1
    if(ha->numeros[pos] == NULL) { //1+(
        int *novoNumero = (int*) malloc(sizeof(int));//1
        if(novoNumero == NULL)//1+(
            return 0;//1)
        *novoNumero = numero;//1
        ha->numeros[pos] = novoNumero;//1
        ha->qtd++;//1
        return colisao;//1)
    } else {//*1+(
        colisao++;//1)
    }
    return colisao;//1
} //Funcao Custo: f(n) = 1+1+1+1+1+1+1+(1+1+(1)+1+1+1+1)*1+(1)+1 = f(n) = 1
//Complexidade: O(1)


int main() {

    Hash *ha = criaHash(10);
    
    int numero, qtd_numeros, qtd_colisoes;
    qtd_colisoes = 0;
    // Digite a quantidade de numeros a ser inseridos na tabela hash:
    scanf("%d", &qtd_numeros);
    
    for(int i=0; i<qtd_numeros; i++) {
        // Digite os numeros que voce vai inserir
        scanf("%d", &numero); //1
        int result = insereHash_EnderAberto(ha, numero);
        qtd_colisoes += result;
    }
        printf("%i\n", qtd_colisoes);
    
    return 0;
}
