#include <stdlib.h>
#include <string.h>
#include "TabelaHash.h"

struct hash {
    int qtd, TABLE_SIZE;
    struct aluno **itens;
};

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
Método da Divisao: Consiste em calcular o "resto da divisão" do valor inteiro que
representa o elemento pelo tamanho da tabela, "TABLE_SIZE".

- A operação de "E bit-a-bit" com o valor 0x7FFFFFFF elimina o bit de sinal do
valor da "chave".
- Evita o risco de ocorrer um overflow e obtermos um número negativo
*/

int chaveDivisao(int chave, int TABLE_SIZE) {
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
}

/*
Método da Multiplicação: Usa o valor "A", "0 < A < 1", para multiplicar o valor da
"chave" que representa o elemento. Em seguida, a "parte fracionaria" resultante é
multiplicada pelo tamanho da tabela para calcular a posição do elemento
*/

int chaveMultiplicacao(int chave, int TABLE_SIZE) {
    float A = 0.6180339887; // constante 0 < A < 1
    float val = chave * A;
    val = val - (int) val;
    return (int) (TABLE_SIZE * val);
}

/*
Método da Dobra: Utiliza um esquema de dobrar e somar os dígitos do valor para calcular
a sua posição.
- Considera o "valor inteiro" que representa o elemento como uma sequência de dígitos
escritos num pedaço de papel. Enquanto esse valor for maior que o tamanho da tabela, o
papel é dobrado e os dígitos sobrepostos são somados, desconsiderando-se as dezenas.
- Pode ser usado com valores binários.
- Utiliza a operação de "ou exclusivo"
- A dobra é realizada de "k em k bits" o que resulta em um valor de posição entre "0 e 2k+1"
*/

int chaveDobra(int chave, int TABLE_SIZE) {
    int num_bits = 10;
    int parte1 = chave >> num_bits;
    int parte2 = chave & (TABLE_SIZE-1);
    return (parte1 ^ parte2);
}

/*
"Tratando uma string como chave"
- Calcular um valor numérico a partir dos valores ASCII dos caracteres
- Devemos considerar a posição da letra
"Cuidado"
- Não devemos apenas somar os caracteres, pois palavras com letras trocadas irão
produzir o mesmo valor
cama: 99 + 97 + 109 + 97 = 402
maca: 109 + 97 + 99 + 97 = 402
*/

int valorString(char *str) {
    int i, valor = 7;
    int tam = strlen(str);
    for(i=0; i < tam; i++)
        valor = 31 * valor + (int) str[i];
    return valor;
}

int insereHash_SemColisao(Hash *ha, struct aluno al) {
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;
    int chave = al.matricula;
    //int chave = valorString(al.nome);
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

int buscaHash_SemColisao(Hash *ha, int mat, struct aluno *al) {
    if(ha == NULL)
        return 0;
    int pos = chaveDivisao(mat, ha->TABLE_SIZE);
    if(ha->itens[pos] == NULL)
        return 0;
    *al = *(ha->itens[pos]);
    return 1;
}

/*
Tratamento de colisão: Sondagem Linear
- Tenta espalhar os elementos de forma sequencial a partir da posição calculada
utilizando a "função de hashing".
Funcionamento:
- Primeiro elemento (i = 0) é colocado na "posição" obtida pela "função de hashing":
"pos"
- Segundo elemento (nova colisão) é colocado na posição "pos+1"
- Terceiro elemento (nova colisão) é colocado na posição "po+2"
- Apesar de ser simples, essa abordagem apresenta um problema conhecido como "agrupamento
primário".
Agrupamento primário:
- Presença de longas sequências de posições ocupadas
- A medida que a tabela hash fica cheia, o tempo para incluir ou buscar um elemento
aumenta
- Quanto maior o agrupamento primário, maior a probabilidade de aumentá-lo ainda
mais com a inserção de u novo elemento, diminuindo o desempenho da tabela.
*/

int sondagemLinear(int pos, int i, int TABLE_SIZE) {
    return ((pos + i) & 0x7FFFFFFF) % TABLE_SIZE;
}

/*
Tratamento de colisão: Sondagem Quadrática
- Tenta espalhar os elementos utilizando uma equação do segundo grau
"pos + (c1 * i) + (c2 *i²)"
onde
- "pos" é a posição obtida pela "função de hashing"
- "i" é a tentativa atual
- "c1" e "c2" são os coeficientes da equação
Funcionamento:
- Primeiro elemento (i = 0) é colocado na "posição" obtida pela "função de hashing":
"pos"
- Segundo elemento (nova colisão) é colocado na posição "pos + (c1 * 1) + (c2 * 1²)"
- Terceito elemento (nova colisão) é colocado na posição "pos + (c1 * 2) + (c2 * 2²)"
- Resolve o problema de "agrupamento primário"
- Gera um problema conhecido como "agrupamento secundário"
Agrupamento secundário:
- Isso ocorre por que todas as "chaves" que produzam a mesma "posição" inicial na tabela
hash também produzem as mesmas "posições" na "sondagem quadrática"
- Felizmente, a degradação produzida na tabela é menor que a produzida pelos "agrupamentos
primários"

*/

int sondagemQuadratica(int pos, int i, int TABLE_SIZE) {
    pos = pos + 2*i + 5*i*i;
    return (pos & 0x7FFFFFFF) % TABLE_SIZE;
}

/*
Tratamento de colisão: Duplo Hash
- Espalhamento duplo
- Tenta espalhar os elementos utilizando duas "funções de hashing"
"H1 + i * H2"
Onde
- "H1" é utilizada para calcular a "posição inicial" do elemento
- "H2" é utilizada para calcular os "deslocamentos" em relação a "posição inicial"
no caso de uma "colisão"
Funcionamento:
- Primeiro elemento (i = 0) é colocado na "posição" obtida por "H1"
- Segundo elemento (colisão) é colocado na posição "H1 + 1 * H2"
- Terceiro elemento (nova colisão) é colocado na posição "H1 + 2 * H2"
*/

int duploHash(int H1, int chave, int i, int TABLE_SIZE) {
    int H2 = chaveDivisao(chave, TABLE_SIZE-1) + 1;
    return ((H1 + i * H2) & 0x7FFFFFFF) & TABLE_SIZE;
}

int insereHash_EnderAberto(Hash *ha, struct aluno al) {
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;
    int chave = al.matricula;
    int i, pos, newPos;
    pos = chaveDivisao(chave, ha->TABLE_SIZE);
    for(i=0; i<ha->TABLE_SIZE; i++) {
        newPos = sondagemLinear(pos, i, ha->TABLE_SIZE);
        //newPos = sondagemQuadratica(pos, i, ha->TABLE_SIZE);
        //newPos = duploHash(pos, chave, i, ha->TABLE_SIZE);
        if(ha->itens[newPos] == NULL) {
            struct aluno *novo;
            novo = (struct aluno*) malloc(sizeof(struct aluno));
            if(novo == NULL)
                return 0;
            *novo = al;
            ha->itens[newPos] = novo;
            ha->qtd++;
            return 1;
        }
    }
    return 0;
}

int buscaHash_EnderAberto(Hash *ha, int mat, struct aluno *al) {
    if(ha == NULL)
        return 0;
    int i, pos, newPos;
    pos = chaveDivisao(mat, ha->TABLE_SIZE);
    for(i=0; i<ha->TABLE_SIZE; i++) {
        newPos = sondagemLinear(pos, i, ha->TABLE_SIZE);
        //newPos = sondagemQuadratica(pos, i, ha->TABLE_SIZE);
        //newPos = duploHash(pos, chave, i, ha->TABLE_SIZE);
        if(ha->itens[newPos] == NULL)
            return 0;
        if(ha->itens[newPos]->matricula == mat) {
            *al = *(ha->itens[newPos]);
            return 1;
        }
    }
    return 0;
}
