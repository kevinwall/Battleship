#include <iostream>
#include "comparator.h"
//Apena compara duas matrizes 
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