#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct aluno {
    int numero;
    char nome[30];
};

struct hash {
    int qtd, TABLE_SIZE;
    struct aluno **itens;
};

typedef struct hash Hash;

int chaveDivisao(int chave, int TABLE_SIZE) {
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
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

int insereHash_SemColisao(Hash *ha, struct aluno al) {
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;
    int chave = al.numero;
    int pos = chaveDivisao(chave, ha->TABLE_SIZE);
    struct aluno *novo;
    novo = (struct aluno*) malloc(sizeof(struct aluno));
    if(novo == NULL)
        return 0;
    *novo = al;
    ha->itens[pos] = novo;
    ha->qtd++;
    return 1;
}

int buscaHash_SemColisao(Hash *ha, int numero, struct aluno *al) {
    if(ha == NULL)
        return 0;
    int pos = chaveDivisao(numero, ha->TABLE_SIZE);
    if(ha->itens[pos] == NULL)
        return 0;
    *al = *(ha->itens[pos]);
    return 1;
}

int main() {
    
    Hash *ha = criaHash(1427); //1

    int numero, qtd_buscas; //1
    char nome[30]; //1
    struct aluno novo; //1
    struct aluno result_busca; //1

    for(int i=0; i<10; i++) { //n*(
        //Digite o numero da pessoa:
        scanf("%d", &numero); //1
        //Digite o nome da pessoa:
        scanf("%s", nome); //1
        novo.numero = numero; //1
        strcpy(novo.nome, nome); //1
        insereHash_SemColisao(ha, novo); //1
    }
    
    //Digite a quantidade de buscas:
    scanf("%d", &qtd_buscas); //1
    
    for(int i=0; i<qtd_buscas; i++) { //m
        scanf("%d", &numero); //1
        buscaHash_SemColisao(ha, numero, &result_busca); //1
        printf("%s\n", result_busca.nome); //1
    }
    
    liberaHash(ha); //1
   
    return 0;
} // Funcao custo: f(n) = 1+1+1+1+1+n*(1+1+1+1+1)+1+m*(1+1+1)+1 = f(n) = 7+5n+3m = f(n) = n*m
// Complexidade: O(n*m)
