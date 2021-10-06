typedef struct matriz Matriz; //Chamamos a struct matriz de Matriz
//Cria uma nova matriz
Matriz* Matriz_cria(int n, int y);
// Libera uma matriz
void Matriz_libera(Matriz *matriz);
//Acessa os valores "n" e "m" de uma matriz
Matriz* Matriz_soma(Matriz *matriz1, Matriz *matriz2, Matriz *matriz_result);
//Acessa os valores "n" e "m" de uma matriz
Matriz* Matriz_subtrai(Matriz *matriz, int *n, int *m);
//Informa a quantidade de linhas que a matriz tem
int Matriz_linhas(Matriz *matriz, int *n);
//Informa a quantidade de colunas que a matriz tem
int Matriz_colunas(Matriz *matriz, int *m);
