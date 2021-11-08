#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100

struct filaEstatica{
    int inicio, final, qtd;
    int numeros[MAX];
};

typedef struct filaEstatica FilaEstatica;

struct filaDinamica{
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};

typedef struct filaDinamica FilaDinamica;

struct elemento{
    int numero;
    struct elemento *prox;
};

typedef struct elemento Elem;

FilaEstatica* cria_fila_estatica() {
    FilaEstatica *fiEstatica = (FilaEstatica *) malloc(sizeof(struct filaEstatica));
    if(fiEstatica != NULL){
        fiEstatica->inicio = 0;
        fiEstatica->final = 0;
        fiEstatica->qtd = 0;
    }
    return fiEstatica;
}

FilaDinamica* cria_fila_dinamica() {
    FilaDinamica* fiDinamica = (FilaDinamica *) malloc(sizeof(FilaDinamica));
    if(fiDinamica != NULL){
        fiDinamica->final = NULL;
        fiDinamica->inicio = NULL;
        fiDinamica->qtd = 0;
    }
    return fiDinamica;
}

int fila_estatica_cheia(FilaEstatica *fiEstatica) {
    if(fiEstatica == NULL) return -1;
    if(fiEstatica->qtd == MAX)
        return 1;
    else
        return 0;
}

int insere_fila_estatica(FilaEstatica *fiEstatica, int numero) {
    if(fiEstatica == NULL) return 0;
    if(fila_estatica_cheia(fiEstatica)) return 0;
    fiEstatica->numeros[fiEstatica->final] = numero;
    fiEstatica->final = (fiEstatica->final+1)%MAX;
    fiEstatica->qtd++;
    return 1;
}

int insere_fila_dinamica(FilaDinamica *fiDinamica, int numero) {
    if(fiDinamica == NULL) return 0;
    Elem *no = (Elem *) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->numero = numero;
    no->prox = NULL;
    if(fiDinamica->final == NULL) //fila vazia
        fiDinamica->inicio = no;
    else
        fiDinamica->final->prox = no;
    fiDinamica->final = no;
    fiDinamica->qtd++;
    return 1;
}

int tamanho_fila_estatica(FilaEstatica *fiEstatica) {
    if(fiEstatica == NULL)
        return -1;
    return fiEstatica->qtd;
}

int fila_estatica_vazia(FilaEstatica *fiEstatica) {
    if(fiEstatica == NULL) return -1;
    if(fiEstatica->qtd == 0)
        return 1;
    else
        return 0;
}

int fila_dinamica_vazia(FilaDinamica *fiDinamica) {
    if(fiDinamica == NULL) return -1;
    if(fiDinamica->inicio == NULL)
        return 1;
    return 0;
}

void libera_fila_estatica(FilaEstatica *fiEstatica) {
    free(fiEstatica);
}

void libera_fila_dinamica(FilaDinamica *fiDinamica) {
    if(fiDinamica != NULL){
        Elem *noExclusao;
        while(fiDinamica->inicio != NULL){
            noExclusao = fiDinamica->inicio;
            fiDinamica->inicio = fiDinamica->inicio->prox;
            free(noExclusao);
        }
        free(fiDinamica);
    }
}

int numero_fila_existe(FilaDinamica *fiDinamica, int numero) {
    if(fiDinamica != NULL){ //1+(
        Elem *aux;
        aux = fiDinamica->inicio;
        Elem *noExiste; //1
        while(fiDinamica->inicio != NULL){ //n*( //loop que passa por todos os numeros da fila e faz a comparacao com o numero passado como argumento para saber se ele existe na fila ou n
            noExiste = fiDinamica->inicio; //1
            if(noExiste->numero == numero) { //1+(
               return 1; //1)
            }
            fiDinamica->inicio = fiDinamica->inicio->prox; //1
        }
        fiDinamica->inicio = aux; // volta a fila para o inicio para n prejudicar a execucao da funcao main. //1
    }
    return 0; //1
}/* Funcao Custo: f(n) = 1+(1+n*(1+(1)+1)+1+1) = f(n) = 1+(3+n*(3))= f(n) = 3+3n = f(n) = n
Complexidade: O(n) */

int interseccao_filas(FilaEstatica *fiEstatica, FilaDinamica *fiDinamica, FilaDinamica *fiDinamicaResult) {
    if(fiEstatica == NULL || fila_estatica_vazia(fiEstatica)) return 0; //verifica se a fila eh vazia //1
    if(fiDinamica == NULL || fila_dinamica_vazia(fiDinamica)) return 0; //1
    if(fiDinamicaResult == NULL) return 0; //1
    
    Elem *no; //1
    Elem *auxFila; //1
    auxFila = fiDinamica->inicio; //1
    int qtdRepeticao = 0; //1
    int numeroFilaDinamica; //1
    int tamanhoFiEstatica = tamanho_fila_estatica(fiEstatica); //1 //pega o tamanho da fila estatica
    for(int i=0; i<tamanhoFiEstatica; i++) { // n*(  //loop que pega o numero da fila estatica
        while(fiDinamica->inicio != NULL){ //m*(  //loop que percorre os numeros da fila dinamica
            no = fiDinamica->inicio; //1
            numeroFilaDinamica = no->numero; //1 //pega o numero da fila dinamica
            if(fiEstatica->numeros[i] == numeroFilaDinamica) { //1+(  /*comparacao se o numero atual do loop da fila estatica eh igual ao da dinamica */
                qtdRepeticao++; //1
                int result_numero_existe = numero_fila_existe(fiDinamicaResult, numeroFilaDinamica); /* funcao que verifica se o numero ja existe na fila de resultado para nao adicionar o mesmo numero mais de uma vez*/ //1+
                if(result_numero_existe == 0) { //1+(
                    insere_fila_dinamica(fiDinamicaResult, numeroFilaDinamica); //1)
                }
            }
            fiDinamica->inicio = fiDinamica->inicio->prox; //1  /*apos comparar um numero da fila dinamica com todos os numeros da fila estatica, a fila dinamica pula para o proximo numero.*/
        }
        fiDinamica->inicio = auxFila; //apos a fila dinamica percorrer todos numeros,reatribuimos o numero inicial a ela
    }
    return qtdRepeticao; //1
}/* Funcao Custo: f(n) = 1+1+1+1+1+1+1+1+1+n*(m*(1+1+1+(1+1+1+(1))+1)+1)+1 = f(n) = 10+n*(m*(9)) = f(n) = 10+n*m+9n = f(n) = n*m = n*m
Complexidade: O(n*m) */

int main() {

    int qtdFila1, qtdFila2, numFila, num;
    scanf("%d", &qtdFila1); //Digite a quantidade de numeros que vc quer inserir na fila 1:
    scanf("%d", &qtdFila2); //Digite a quantidade de numeros que vc quer inserir na fila 2:
    
    FilaEstatica *fiEstatica;
    fiEstatica = cria_fila_estatica();
    
    FilaDinamica *fiDinamica;
    fiDinamica = cria_fila_dinamica();
    
    FilaDinamica *fiDinamicaResult;
    fiDinamicaResult = cria_fila_dinamica();
    
    for(int i=0; i<qtdFila1; i++) {
        scanf("%d", &numFila); //Digite o numero que vc quer inserir na fila 1:
        insere_fila_estatica(fiEstatica, numFila);
    }
    
    for(int j=0; j<qtdFila2; j++) {
        scanf("%d", &numFila); //Digite o numero que vc quer inserir na fila 2:
        insere_fila_dinamica(fiDinamica, numFila);
    }
    
    int result = interseccao_filas(fiEstatica, fiDinamica, fiDinamicaResult);
    
    if(result == 0) {
        printf("ZERO");
    }else if(fiDinamicaResult != NULL){
        Elem *noResult;
        while(fiDinamicaResult->inicio != NULL){
            noResult = fiDinamicaResult->inicio;
            num = noResult->numero;
            printf("%d ", num);
            fiDinamicaResult->inicio = fiDinamicaResult->inicio->prox;
        }
    }
    
    libera_fila_estatica(fiEstatica);
    libera_fila_dinamica(fiDinamica);
    libera_fila_dinamica(fiDinamicaResult);
    
    return 0;
}
