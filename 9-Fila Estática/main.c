#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.h"

int main() {
    Fila *fi;
    fi = cria_fila();

    int result_insere_fila = insere_fila(fi, dados_aluno);

    int resut_consulta_fila = consulta_fila(fi, &dados_aluno);

    int result_tamanho_fila = tamanho_fila(fi);
    int result_fila_cheia = fila_cheia(fi);
    int result_fila_vazia = fila_vazia(fi);

    int result_remove_fila = remove_fila(fi);

    libera_fila(fi);
    return 0;
}