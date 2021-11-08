#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"

int main() {
    Pilha *pi;
    pi = cria_pilha();

    int result_insere_pilha = insere_pilha(pi, dados_aluno);

    int result_consulta_pi = consulta_topo_pilha(pi, &dados_aluno);

    int result_tamanho_pilha = tamanho_pilha(pi);
    int result_pilha_cheia = pilha_cheia(pi);
    int result_pilha_vazia = pilha_vazia(pi);

    int result_remove_pilha = remove_pilha(pi);

    libera_pilha(pi);
    return 0;
}