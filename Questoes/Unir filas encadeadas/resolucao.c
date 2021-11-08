#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct fila Fila;

struct fila{
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};

struct elemento{
    int numero;
    struct elemento *prox;
};

typedef struct elemento Elem;

Fila* cria_fila() {
    Fila* fi = (Fila *) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void libera_fila(Fila *fi) {
    if(fi != NULL){
        Elem *no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int remove_fila(Fila *fi) {
    if(fi == NULL) return 0;
    if(fi->inicio == NULL) //fila vazia
        return 0;
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL)//fila ficou vazia
        fi->final = NULL;
    free(no);
    fi->qtd--;
    return 1;
}

int fila_vazia(Fila *fi) {
    if(fi == NULL) return -1;
    if(fi->inicio == NULL)
        return 1;
    return 0;
}

int insere_fila(Fila *fi, int numero) {
    if(fi == NULL) return 0;
    Elem *no = (Elem *) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->numero = numero;
    no->prox = NULL;
    if(fi->final == NULL) //fila vazia
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    fi->qtd++;
    return 1;
}

int tamanho_fila(Fila *fi) {
    if(fi == NULL) return 0;
    return fi->qtd;
}

int unir_filas(Fila *fi1, Fila *fi2) {
    if(fi1 == NULL || fila_vazia(fi2)) return 0; // verifica se a fila eh vazia //1
    if(fi2 == NULL || fila_vazia(fi2)) return 0; // 1
    Elem *Elem1_inicio = fi1->inicio; // atribui ao elemento auxiliar o inicio da fila //1
    Elem *no2; //1
    Elem *no1; //1
    int qtdrepeticao = 1; // variavel utilizada para retornar o 0 ou 1 caso haja repeticao //1
    int rep, numero1, numero2; //1
    while(fi2->inicio != NULL){ // while para percorrer a fila2 //n*(
        rep = 0; //1
        no2 = fi2->inicio; //1
        numero2 = no2->numero; // pegando o numero de cada loop da fila 2 //1
        while(Elem1_inicio != NULL){ // while para percorrer a fila 1 com base no elemento auxiliar //m*(
            no1 = Elem1_inicio; //1
            numero1 = no1->numero; // pegando o numero de cada loop da fila 1 e //1
            if(numero2 == numero1){ // comparando todos os elementos da fila 1 com um elemento da fila 2 //1+(
                rep++; // incrementa a cada repeticao //1)
                if(qtdrepeticao >= 1){ // se existir repeticao, decrementa a variavel para 0 //1+(
                    qtdrepeticao--; //1)
                }
            }
            Elem1_inicio = Elem1_inicio->prox; // passa para o proximo elemento da fila 1 //1
        }
        if(rep == 0) { // se n houve repeticao, adiciona //1+(
            insere_fila(fi1, numero2); //1)
        }
        fi2->inicio = fi2->inicio->prox; //pula para o proximo elemento da fila 2 //1
        Elem1_inicio = fi1->inicio; //pula para o proximo elemento da fila1 usando o auxiliar //1
    }
    return qtdrepeticao; // retorna 0 caso tenha repeticao e 1 caso n tenha //1
}// Funcao Custo: f(n) = 1+1+1+1+1+1+1+n*(1+1+1+m*(1+1+1+(1+1+(1)))+1)+1+1+1+1+1 = f(n) = 12+n*(3+m*(7)) = f(n) = 12+3n+n*7m = f(n) = n*m
//Complexidade: O(n*m)

int main() {

    int qtdFila1, qtdFila2, numFila, num1;
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
    
    if(fi1 != NULL){
        Elem *no;
        while(fi1->inicio != NULL){
            no = fi1->inicio;
            num1 = no->numero;
            printf("%d ", num1);
            fi1->inicio = fi1->inicio->prox;
        }
    }
    
    printf("\n");
    printf("%d", result);
    
    libera_fila(fi1);
    libera_fila(fi2);
    
    return 0;
}
