#include <iostream>

//Enumeração para facilitar a alocação dos navios na matriz.
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

//Gerador de símbolos para os navios.
char make_symbol( flags x  );

//Gerador da matriz genérica.
void generator_def( char ** first, int lin, int col);

//Função para "printar os caracteres na tela".
void print_puzze( char ** first, int lin, int col);