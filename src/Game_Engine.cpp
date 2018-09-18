#include "../includes/marker.h"
#include "../includes/insert.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../includes/Game_Engine.h"

//Função que irá comparar as matrizes (base e do jogador).
bool comparator( int **A, int ** B, int lin , int col)
{
	for( int i{0} ; i < lin ; i++)
	{
		for( int j{0} ; j < col ; j++)
			{
				if( A[i][j] != B[i][j])
				{
					return false; 
				}
			}
	}

	return true;
}

//Função que imprime a matriz do usuário.
void print_matrix_g(int **A, int *C, int *D, int lin, int col)
{
	std::cout<<"Matriz do jogo: "<<std::endl;
	for(auto i{0}; i < lin; i++) //Percorre a "matriz de tokens" e imprime os termos equivalentes na tela
	{
		for(auto j{0}; j < col; j++)
		{
			if(A[i][j] == 1)
			{
				std::cout<<"* ";
			}
			else if(A[i][j] == 2)
			{
				std::cout<<"< ";
			}
			else if(A[i][j] == 3)
			{
				std::cout<<"^ ";
			}
			else if(A[i][j] == 4)
			{
				std::cout<<"> ";
			}
			else if(A[i][j] == 5)
			{
				std::cout<<"v ";
			}
			else if(A[i][j] == 6)
			{
				std::cout<<"o ";
			}
			else
			{
				std::cout<<"- ";
			}

		}
		std::cout<<" "<<C[i]; //Imprime a quantidade de navios existentes em cada linha
		std::cout<<std::endl;
	}

	for(auto k{0}; k < col; k++) //Imprime a quantidade de navios existentes em cada coluna
	{
		std::cout<<D[k]<<" ";
	}
	std::cout<<std::endl;
}

//Função para debug que imprime a matriz tokenizada
void print_puzzle(int **A, int lin, int col)
{
	std::cout<<"Matriz do jogo: "<<std::endl;
	for(auto i{0}; i < lin; i++)
	{
		for(auto j{0}; j < col; j++)
		{
			std::cout<<A[i][j];
		}

		std::cout<<std::endl;
	}
}

//Função que substitui os 7's da matriz "base" por zeros (para a comparação)
void zero_seven(int **A, int lin, int col)
{
	for(auto i{0}; i < lin; i++)
	{
		for(auto j{0}; j < col; j++)
		{
			if(A[i][j] == 7)
			{
				A[i][j] = 0;
			}
		}
	}
}