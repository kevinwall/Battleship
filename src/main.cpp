#include "../includes/marker.h"

int main()
{

	int SIZE{15};

	char ** A;

	A = new char* [SIZE];

	for(auto i{0}; i < SIZE; i++)
	{
		A[i] = new char [SIZE];
	}

	generator_def(A, SIZE, SIZE);

	auto B = validate_position_col( int col);

	auto C = validate_position_lin( int lin);

	

	delete A;
}