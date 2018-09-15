#include "../includes/marker.h"
#include "../includes/insert.h"

int main()
{
	int size = 12;

	auto B = validate_position_lin(size);
	auto C = validate_position_col(size);
	std::ofstream map;
	map.open("Puzzles.txt");
	map<<100<<std::endl;


	int ** A;

	A = new int* [size];

	for(auto i{0}; i < size; i++)
	{
		A[i] = new int [size];
	}

	generator_def(A, size, size);

	for(auto mapas{0}; mapas < 100; mapas++)
	{
		map<<size<<" "<<size<<std::endl;
		test_position(A, B, C, size, size, 4);

		for(auto i{0}; i < 2; i++)
		{
			test_position(A, B, C, size, size, 3);
		}

		for(auto i{0}; i < 3; i++)
		{
			test_position(A, B, C, size, size, 2);
		}

		for(auto i{0}; i < 4; i++)
		{
			test_position(A, B, C, size, size, 1);
		}
	
		for(auto i{0}; i < size; i++)
		{
			for(auto j{0}; j < size; j++)
			{
				map<<A[i][j];
			}
			map<<std::endl;
		}

		
		generator_def(A, size, size);
		B = validate_position_lin(size);
		C = validate_position_col(size);

	}

	map.close();

	return 0;
}