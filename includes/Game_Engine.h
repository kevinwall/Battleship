#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

/**
*@brief Função comparator que compara duas matrizes.
*@param int **A matriz A a ser comparada.
*@param int **B matriz B a ser comparada.
*@param int lin quantidade de linhas das matrizes.
*@param int col quantidade de colunas das matrizes
*/
bool comparator( int **A, int ** B, int lin , int col);

/**
*@brief Função print_matrix_g que imprime a matriz do usuário.
*@param int **A matriz A a ser imprimida.
*@param int *C vetor com a quantidade de navios por linha.
*@param int *D vetor com a quantidade de navios por coluna.
*@param int lin quantidade de linhas da matriz A.
*@param int col quantidade de colunas da matriz A
*/
void print_matrix_g(int **A, int *C, int *D, int lin, int col);

/**
*@brief Função print_puzzle que imprime a matriz "base" do jogo (função de debug).
*@param int **A matriz A a ser imprimida.
*@param int lin quantidade de linhas da matriz.
*@param int col quantidade de colunas da matriz.
*/
void print_puzzle(int **A, int lin, int col);

/**
*@brief Função zero_seven que substitui os 7's da matriz por zeros.
*@param int **A matriz A a ser modificada.
*@param int lin quantidade de linhas da matriz.
*@param int col quantidade de colunas da matriz.
*/
void zero_seven(int **A, int lin, int col);

#endif