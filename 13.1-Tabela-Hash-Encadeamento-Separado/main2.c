#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TabelaHash.h"
#include "ListaDinEncad.h"

int main() {
    Hash *ha = criaHash(1427);

    struct aluno al1;
    al1.matricula = 1515094;
    strcpy(al1.nome , "Lucas");

    struct aluno al2;

    struct aluno al3;
    al3.matricula = 1515093;
    strcpy(al3.nome , "Marta");

    int insereSemColisao = insereHash_SemColisao(ha, al1);
    printf("resultado da inserção: %d\n", insereSemColisao);

    int insereSemColisao2 = insereHash_SemColisao(ha, al3);
    printf("resultado da inserção: %d\n", insereSemColisao2);

    int buscaAluno2 = buscaHash_SemColisao(ha, 1515094, &al2);
    printf("resultado da busca: %d\n", buscaAluno2);
    printf("Nome: %s\n", al2.nome);
    printf("Matricula: %d\n", al2.matricula);

    int buscaAluno3 = buscaHash_SemColisao(ha, 1515093, &al2);
    printf("resultado da busca: %d\n", buscaAluno3);
    printf("Nome: %s\n", al2.nome);
    printf("Matricula: %d\n", al2.matricula);
/*
    int buscaSemColisao = buscaHash_SemColisao(ha, mat, &al_result);

    int insereComColisao = insereHash_EnderAberto(ha, al);
    int buscaComColisao = buscaHash_EnderAberto(ha, mat, &al_result_colisao);

    liberaHash(ha);
*/
    return 0;
}