#include <iostream>
#include <algorithm>

int * validate_position_col( int col)
{
	int * A = new int[col];

	for( auto i{0} ; i < col; i++)
	{
		A[i] = i;
	}

	std::random_shuffle( A, A+col );

	for( auto i{0} ; i < col; i++)
	{
		std::cout << A[i] << " " ; 
	}

	return A;
}

int * validate_position_lin( int lin)
{
	int * A = new int[lin];

	for( auto i{0} ; i < col; i++)
	{
		A[i] = i;
	}

	std::random_shuffle( A, A+lin );

	for( auto i{0} ; i < lin; i++)
	{
		std::cout << A[i] << " " ; 
	}

	return A;
}

//Função de teste para verificar se há posições válidas para a inserção dos barcos.
bool test_position( char ** A , int * B, int * C, int lin, int col, int boat)
{
	//Iterando sobre o vetor B que contém posições randômicas afim de encontrar uma coordenada X aleatória de A.
	for( auto i = 0 ; i = col ; i++)
	{
		//Iterando sobre o vetor C que contém posições randômicas afim de encontrar a coordenada Y aleatória de A.
		for( auto j = 0; j = lin ; j++)
		{
			if(A[B[i]][C[j]] == '-')//Verifica se na posição (X, Y) da matriz há espaço para a inserção.
			{
				auto res = posicion_set(A, B[i], C[j], boat);//Posiciona o barco.

				if(res == true)
				{
					return true;//Caso o barco for inserido com sucesso, retorna verdadeiro e sai da função.
				}
			}
		}
	}

	return false;
}

int main( ){
	validate_position_col( 10 );

	return EXIT_SUCCESS;
}
