/*
TAD Matriz
Declaração:
ex: Matriz *mat;

O tipo Matriz armazena a ordem da matriz(linhas e colunas) e os valores de matriz de
ponteiros tipo double:
struct matriz{
  int linhas;
  int colunas;
  float **matriz;
};
*/
typedef struct matriz Matriz; //Chamamos a struct matriz de Matriz
/*Função de inicialização de uma matriz, recebe o numero de linhas e colunas e retorna um
ponteiro do tipo Matriz. Ex: mat = novaMatriz(2,2);*/
Matriz* novaMatriz(int linhas, int colunas);
// Libera uma matriz
void liberaMatriz(Matriz *matriz);
/*Função para somar matrizes. Recebe dois ponteiros das matrizes que quer somar
e retorna um ponteiro da matriz resultante. Ex: matSoma = somarMatriz(mat1, mat2);*/
Matriz* somarMatriz(Matriz *matriz1, Matriz *matriz2);
//Mesma lógica da soma
//ex: matSub = subtrairMatriz(mat1, mat2);
Matriz* subtrairMatriz(Matriz *matriz1, Matriz *matriz2);
/*Função para multiplicar matrizes. Recebe dois ponteiros das matrizes que quer multiplicar
e retorna um ponteiro da matriz resultante. Ex: mat_P = produtoMatriz(mat1, mat2);*/
Matriz* produtoMatriz(Matriz *matriz1, Matriz *matriz2);
/*Função para transpor matrizes. Recebe uma matriz e retorna sua transposta. Ex: mat_T = 
transposta(mat);*/
Matriz* transposta(Matriz *matriz);
//Informa a quantidade de linhas que a matriz tem
int linhasMatriz(Matriz *matriz);
//Informa a quantidade de colunas que a matriz tem
int colunasMatriz(Matriz *matriz);
//Procedimento de inserção dos valores de uma matriz, linha a linha.
void preencherMatriz(Matriz *matriz);
//Procedimento de exibição dos valores de uma matriz, linha a linha.
void exibirMatriz(Matriz *matriz);
