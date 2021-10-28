#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100

typedef struct fila Fila;

struct fila{
    int inicio, final, qtd;
    int numeros[MAX];
};

Fila* cria_fila() {
    Fila *fi = (Fila *) malloc(sizeof(struct fila));
    if(fi != NULL){
        fi->inicio = 0;
        fi->final = 0;
        fi->qtd = 0;
    }
    return fi;
}

void libera_fila(Fila *fi) {
    free(fi);
}

int tamanho_fila(Fila *fi) {
    if(fi == NULL)
        return -1;
    return fi->qtd;
}

int fila_cheia(Fila *fi) {
    if(fi == NULL) return -1;
    if(fi->qtd == MAX)
        return 1;
    else
        return 0;
}

int fila_vazia(Fila *fi) {
    if(fi == NULL) return -1;
    if(fi->qtd == 0)
        return 1;
    else
        return 0;
}

int insere_fila(Fila *fi, int numero) {
    if(fi == NULL) return 0;
    if(fila_cheia(fi)) return 0;
    fi->numeros[fi->final] = numero;
    fi->final = (fi->final+1)%MAX;
    fi->qtd++;
    return 1;
}

int remove_fila(Fila *fi) {
    if(fi == NULL || fila_vazia(fi))
        return 0;
    fi->inicio = (fi->inicio+1)%MAX;
    fi->qtd--;
    return 1;
}

int unir_filas(Fila *fi1, Fila *fi2) {
    if(fi1 == NULL || fila_vazia(fi1)) //1+(
        return 0; //1
    if(fi2 == NULL || fila_vazia(fi2)) //1+(
        return 0; //1
    int qtdrepeticao = 1; //1
    int rep; //1
    int tamanho_fi1 = tamanho_fila(fi1); //1
    int tamanho_fi2 = tamanho_fila(fi2); //1
    for(int i=0; i<tamanho_fi2; i++){ //n*(
        rep = 0;
        for(int j=0; j<tamanho_fi1; j++){ //m*(
            if(fi2->numeros[i] == fi1->numeros[j]) { //1+(
                rep++; //1
                if(qtdrepeticao >= 1){ //1+(
                    qtdrepeticao--; //1
                }
            }
        }
        if(rep == 0) { //1+(
            insere_fila(fi1, fi2->numeros[i]); //1
        }
        remove_fila(fi2); //1
    }
    return qtdrepeticao; // 1
}// Funcao Custo: f(n) = 1+(1)+1+(1)+1+1+1+1+n*(m*(1+(1+1+(1))))+1+(1)+1+1 = f(n) = 8+n*(m*(4))+4 = f(n) = 12+n*4m = f(n) = n*m
//Complexidade: O(n*m)

int main() {

    int qtdFila1, qtdFila2, numFila;
    scanf("%d", &qtdFila1); //Digite a quantidade de numeros que vc quer inserir na fila 1:
    scanf("%d", &qtdFila2); //Digite a quantidade de numeros que vc quer inserir na fila 2:
    
    Fila *fi1;
    fi1 = cria_fila();
    
    Fila *fi2;
    fi2 = cria_fila();
    
    for(int i=0; i<qtdFila1; i++) {
        scanf("%d", &numFila); //Digite o numero que vc quer inserir na fila 1:
        insere_fila(fi1, numFila);
    }
    
    for(int j=0; j<qtdFila2; j++) {
        scanf("%d", &numFila); //Digite o numero que vc quer inserir na fila 2:
        insere_fila(fi2, numFila);
    }
    
    int result = unir_filas(fi1, fi2);
    
    for(int k=0; k<fi1->qtd; k++){
        printf("%d ", fi1->numeros[k]);
    }
    printf("\n");
    printf("%d", result);
    
    libera_fila(fi1);
    libera_fila(fi2);
    
    return 0;
}
