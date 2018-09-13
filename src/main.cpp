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

	print_puzze(A, SIZE, SIZE);

	delete A;
}