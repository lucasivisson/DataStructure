/*
 * paty.c
 *
 *  Created on: 23/03/2015
 *      Author: Danillo
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <assert.h>

/*
  prefixo eh o uma parte da palavra ate o momento em que ela diverge da outra,
  flag eh um array do tamanho da palavra que marca a posicao que ela difere
*/
struct nodo {
	char *prefixo, *flag;
	struct nodo *p[26];
};

struct nodo *root = NULL;

/*
 *
 */

inserir(char *palavra, struct nodo **p) {
	int i, j;

	if (*p == NULL) { // caso a arvore esteja sem palavras
		(*p) = calloc(1, sizeof(struct nodo));
		(*p)->prefixo = strdup(palavra); // copia a palavra toda para o prefixo
		(*p)->flag = calloc(strlen(palavra) + 1, sizeof(char)); /* cria um array do tamanho da quantidade de letras da palavra + 1 para caber o caractere '\0 que determina o fim da string'. */
		(*p)->flag[strlen(palavra)] = 1; /* marca o ultimo caractere da palavra como sendo o que difere, pois nesse momento so existe essa palavra na arvore*/
	}

  /*Percorre o prefixo atual ate achar o indice onde ele difere da palavra passada na funcao*/
	for (i = 0; i < strlen((*p)->prefixo); i++)
		if (palavra[i] != (*p)->prefixo[i])
			break;

  // Verifica se o indice achado eh menor do que o tamanho da palavra do No atual.
	if (i < strlen((*p)->prefixo)) {
    /* Verifica se o indice na palavra eh igual ao fim da palavra, se sim, marca o fim da palavra como sendo o que difere. */
		if (palavra[i] == '\0')
			(*p)->flag[i] = 1;
		else {
      // Cria um no pai que transfere os caracteres ate o ponto que difere para o novo no
			struct nodo *pai = calloc(1, sizeof(struct nodo));
			pai->prefixo = strndup((*p)->prefixo, i);
			pai->flag = calloc(i + 1, sizeof(char));

      // faz o pai receber as posicoes do array que diferem que estavam marcados no No.
			for (j = 0; j <= i; j++)
				pai->flag[j] = (*p)->flag[j];
   
      // Chama a função recursivamente, passando como parametro inicial o resto da palavra começando de onde difere os caracteres(ou seja, palavra sem o prefixo) e depois passando o endereço de memoria do No dentro da posição X do array que significa o numero da letra da continuação da palavra que deve ser inicializada dentro dos filhos do No pai.
			inserir(palavra + i + 1, &pai->p[palavra[i] - 'a']);
      /* Faz o No pai receber a continuacao de onde difere a palavra comparada do No p */
			pai->p[(*p)->prefixo[i] - 'a'] = *p;
      // sizeof(char) = 1
			j = (strlen((*p)->prefixo) - i) * sizeof(char); // ver se é +1 ou +i
      /* o algoritmo do j eh para achar a quantidade de bytes a ser copiado na funcao memmove */ 

      /*Copiando para o No, a continuacao da palavra de onde diferiu o caractere na posicao i e depois realocamos a quantidade de bytes com o realloc*/
			memmove((*p)->prefixo, (*p)->prefixo + i + 1, j);
			(*p)->prefixo = realloc((*p)->prefixo, j);

      /*Copiando para o No, a nova flag pois os valores anteriores foram transferidos para o No pai e depois realocamos a quantidade de bytes com o realloc*/
			memmove((*p)->flag, (*p)->flag + i + 1, j);
			(*p)->flag = realloc((*p)->flag, j);

			*p = pai; //seta o root como pai

		}
	} else if (palavra[i] == '\0') { /* entra aqui no primeiro e no ultimo loop, quando se insere a primeira palavra ou quando se insere a ultima palavra. */
		(*p)->flag[i] = 1;
	} else {
    /* Entra aqui quando estamos com uma palavra nova em que o i eh maior ou igual a quantidade de caracteres da palavra comparada do No*/
		for (j = 0; j < 26; j++) {
			// Acha o proximo caractere pelos filhos do No comparando qual a posicao nao eh nula 
			if ((*p)->p[j] != NULL)
				break;
		}
		if (j < 26) {
			inserir(palavra + i + 1, &(*p)->p[palavra[i] - 'a']);
		} else { //aumenta o prefixo
			(*p)->flag = realloc((*p)->flag, strlen(palavra) + 1);
			for (j = strlen((*p)->prefixo) + 1; j < strlen(palavra); j++)
				(*p)->flag[j] = 0;
			(*p)->flag[j] = 1;
			free((*p)->prefixo);

			(*p)->prefixo = strdup(palavra);
		}
	}
}

void Imprimir(struct nodo **p,int m) {
    int i, count =0;
    char temp;

    //caso de arvore vazia
    if (p == NULL) {
        printf("[]");
        return;
    }
    int tam_prefixo = strlen((*p)->prefixo);
    if (m == 1)printf("[");
    for (i = 0; i < tam_prefixo; ++i) {
        if ((*p)->flag[i + 1] != 1)
            printf("%c", ((*p)->prefixo[i]));
        else {
            temp = toupper((*p)->prefixo[i]);
            printf("%c", temp);
        }
    }
    for (i = 0; i < 26; i++) {
        if ((*p)->p[i] != NULL) {
            printf("[");
            //primeiro caso
            if ((*p)->p[i]->flag[0] == 1) {

                printf("%c", i + 65); //maiusculas
            } else if((strlen((*p)->p[i]->prefixo) == 0 && (*p)->p[i]->flag[0] == 1)) {
                printf("%c", i + 97); //minuscula
            }
		else {
                printf("%c", i + 97); //minuscula
            }
             
            Imprimir(&((*p)->p[i]),0);
        }
    }
    printf("]");
}


void buscar(char *palavra, struct nodo **p, char *finalString, int posicaoAtualCaractere) {
	for (int i = 0; i < 26; i++) {
		// printf("palavra[i]: %c\n", palavra[i]);
		// printf("palavra[i] - 'a': %d\n", palavra[i] - 'a');
		if((*p)->p[i] != NULL && palavra[posicaoAtualCaractere] - 'a' == i) {
			// printf("(*p)->p[i]: %d\n", (*p)->p[i]);
			printf("i: %i\n", i);
			printf("%s\n", (*p)->p[i]->prefixo);

			finalString[posicaoAtualCaractere] = palavra[posicaoAtualCaractere];
			posicaoAtualCaractere++;
			for(int j = 0; j < strlen((*p)->p[i]->prefixo); j++) {
				finalString[posicaoAtualCaractere + j] = (*p)->p[i]->prefixo[j];
				printf("finalString: %s\n", finalString);
				if(j = strlen((*p)->p[i]->prefixo) - 1) {
					posicaoAtualCaractere = posicaoAtualCaractere + j;
				}
			}
			// printf("palavra: %s\n", palavra);
			// printf("finalString: %s\n", finalString);
			if(strcmp(palavra,finalString) == 0) {
				printf("oxeeeee: %s\n", palavra);
				printf("finalString: %s\n", finalString);
				return;
			} else {
				buscar(palavra, &((*p)->p[i]), finalString, posicaoAtualCaractere);
			}
		}
		// printf("%d\n", (*p)->flag[i] != NULL);
	}
	// printf("palavra: %s\n", (*p)->prefixo);
}

int main(int argc , char *argv[]) {
	struct nodo *p = NULL;
	char str[255] = "formado";
	char str1[255] = "formiga";
	char str2[255] = "alergia";
	char str3[255] = "alegria";
  char str4[255] = "alegoria";

	char finalString[30] = "";
	
	
	// while( scanf("%s", &str) != EOF ){
	 
  inserir(str,&p);
  inserir(str1,&p);
  inserir(str2,&p);
  inserir(str3,&p);
  inserir(str4,&p);
	
	buscar(str1, &p, finalString, 0);
		
	// }
	// Imprimir(&p, 1);
	printf("\n");
	
	return 0;
}