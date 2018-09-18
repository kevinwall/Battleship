#ifndef MARKER_H
#define MARKER_H

#include <iostream>
#include <algorithm>
#include <iterator>

/**
*@brief Enumeração flags responsável por "tokenizar" os símbolos da matriz.
*/
enum flags
{
	WATER = 0,
	SUBMARINE ,
	HEAD_H,
	HEAD_V,
	TAIL_H,
	TAIL_V,
	BODY,
	INVALID 
};

/**
*@brief Função make_symbol que gera símbolos para o tabuleiro baseado na enumeração.
*@param flags x: Este parâmetro indica o tipo de caractere que se deseja gerar.
*/
int make_symbol( flags x  );

/**
*@brief Gerador default que cria uma matriz preenchida com água.
*@param int** first: Ponteiro para o início da matriz.
*@param int lin: quantidade de linhas da matriz.
*@param int col: quantidade de colunas da matriz.
*/
void generator_def( int ** first, int lin, int col);

/**
*@brief Função para printar o tabuleiro no terminal.
*@param int** first: Ponteiro para o início da matriz.
*@param int lin: quantidade de linhas da matriz.
*@param int col: quantidade de colunas da matriz.
*/
void print_puzzle( int ** first, int lin, int col);

#endif