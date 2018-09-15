#include "../includes/marker.h"

int main()
{

	int SIZE{15};

	int ** A;

	A = new int* [SIZE];

	for(auto i{0}; i < SIZE; i++)
	{
		A[i] = new int [SIZE];
	}

	generator_def(A, SIZE, SIZE);

	//auto B = validate_position_col( SIZE);

	//auto C = validate_position_lin( SIZE);

	print_puzzle(A, SIZE, SIZE);

	delete A;
}