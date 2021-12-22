#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"

struct NO {
    int info;
    int alt; //altura daquela sub-arvore
    struct NO *esq;
    struct NO *dir;
}

//Calcula a altura de um nó
int alt_NO(struct NO *no) {
    if(no == NULL)
        return -1;
    else
        return no->alt;
}

//Calcula o fator de balanceamento de um nó
int fatorBalanceamento_NO(struct NO *no) {
    // labs serve para pegar apenas o modulo, retirando o positivo ou negativo
    return labs(alt_NO(no->esq) - alt_NO(no->dir));
}

//Calcula o maior valor
int maior(int x, int y) {
    if(x > y)
        return x;
    else
        return y;
}