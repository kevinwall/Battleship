#include <iostream>
#include <algorithm>
#include <fstream>

/**
*@brief Função validate_position_col que cria um vetor de posições aleatórias Y.
*@param int col: quantidade de colunas da matriz.
*/
int * validate_position_col( int col);

/**
*@brief Função validate_position_lin que cria um vetor de posições aleatórias X.
*@param int col: quantidade de linhas da matriz.
*/
int * validate_position_lin( int lin);

/**
*@brief Função colision_1 que verifica se o barco não passa dos limites da matriz.
*@param int b posição X do barco.
*@param int c posição Y do barco.
*@param int boat tamanho do barco.
*@param int lin quantidade de linhas da matriz.
*@param int col quantidade de colunas da matriz.
*@param int k posição do barco (vertical ou horizontal)
*/
bool colision_1(int b, int c, int boat, int lin, int col, int k);

/**
*@brief Função colision_2 que verifica se o barco não está situado na vizinhança da outros barcos.
*@param int **A ponteiro para o início da matriz
*@param int b posição X do barco.
*@param int c posição Y do barco.
*@param int boat tamanho do barco.
*@param int lin quantidade de linhas da matriz.
*@param int col quantidade de colunas da matriz.
*@param int k posição do barco (vertical ou horizontal)
*/
bool colision_2(int **A, int b, int c, int boat, int lin, int col, int k);

/**
*@brief Função negate_area que invalida a vizinhança de um barco.
*@param int **A ponteiro para o início da matriz
*@param int b posição X do barco.
*@param int c posição Y do barco.
*@param int boat tamanho do barco.
*@param int lin quantidade de linhas da matriz.
*@param int col quantidade de colunas da matriz.
*@param int k posição do barco (vertical ou horizontal)
*/
bool negate_area(int ** A, int b, int c, int boat, int lin, int col, int k);

/**
*@brief Função insert_boat que insere um barco na matriz.
*@param int **A ponteiro para o início da matriz
*@param int B posição X do barco.
*@param int C posição Y do barco.
*@param int boat tamanho do barco.
*@param int k posição do barco (vertical ou horizontal)
*/
void insert_boat(int ** A, int B, int C, int boat, int k);

/**
*@brief Função test_position que tenta inserir um barco na matriz em função das corrdenadas aleatórias.
*@param int **A ponteiro para o início da matriz
*@param int *B Vetor com coordenadas X do barco.
*@param int *C Vetor com coordenadas Y do barco.
*@param int lin quantidade de linhas da matriz.
*@param int col quantidade de colunas da matriz.
*@param int boat tamanho do barco
*/
bool test_position( int ** A , int * B, int * C, int lin, int col, int boat);