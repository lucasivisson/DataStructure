typedef struct matriz Matriz; //Chamamos a struct matriz de Matriz
/*Função de inicialização de uma matriz, recebe o numero de linhas e colunas e retorna um
ponteiro do tipo Matriz. Ex: mat = novaMatriz(2,2);*/
Matriz* novaMatriz(int linhas, int colunas);
// Libera uma matriz
void liberaMatriz(Matriz *matriz);
//Procedimento de exibição dos valores de uma matriz, linha a linha.
void exibirMatriz(Matriz *matriz);
//Procedimento de inserção dos valores de uma matriz, linha a linha.
void preencherMatriz(Matriz *matriz);
