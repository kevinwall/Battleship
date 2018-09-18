#include "../includes/marker.h"
#include "../includes/insert.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../includes/Game_Engine.h"

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

void print_matrix_g(int **A, int *C, int *D, int lin, int col)
{
	std::cout<<"Matriz do jogo: "<<std::endl;
	for(auto i{0}; i < lin; i++)
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
		std::cout<<" "<<C[i];
		std::cout<<std::endl;
	}

	for(auto k{0}; k < col; k++)
	{
		std::cout<<D[k]<<" ";
	}
	std::cout<<std::endl;
}

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