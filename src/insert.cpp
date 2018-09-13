//#include "../includes/insert.cpp"
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

bool test_position( char ** A , int * B, int * C, int lin, int col)
{
	for( auto i = 0 ; i = col ; i++)
	{
		for( auto j = 0; j = lin ; j++)
		{
			
		}
	}
}

int main( ){
	validate_position_col( 10 );

	return EXIT_SUCCESS;
}
