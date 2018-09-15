#include "../includes/marker.h"
#include "../includes/insert.h"
#include <cstdlib>

int main( int argc, char const *argv[] )
{

	int qt_maps = std::atoi(argv[1]);
	int size_l = std::atoi(argv[2]);
	int size_c = std::atoi(argv[3]);


	auto B = validate_position_lin(size_l);
	auto C = validate_position_col(size_c);
	std::ofstream map;
	map.open("Puzzles.txt");
	map<<qt_maps<<std::endl;


	int ** A;

	A = new int* [size_l];

	for(auto i{0}; i < size_l; i++)
	{
		A[i] = new int [size_c];
	}

	generator_def(A, size_l, size_c);

	for(auto mapas{0}; mapas < qt_maps; mapas++)
	{
		map<<size_l<<" "<<size_c<<std::endl;
		test_position(A, B, C, size_l, size_c, 4);

		for(auto i{0}; i < 2; i++)
		{
			test_position(A, B, C, size_l, size_c, 3);
		}

		for(auto i{0}; i < 3; i++)
		{
			test_position(A, B, C, size_l, size_c, 2);
		}

		for(auto i{0}; i < 4; i++)
		{
			test_position(A, B, C, size_l, size_c, 1);
		}
	
		for(auto i{0}; i < size_l; i++)
		{
			for(auto j{0}; j < size_c; j++)
			{
				map<<A[i][j];
			}
			map<<std::endl;
		}

		
		generator_def(A, size_l, size_c);
		B = validate_position_lin(size_l);
		C = validate_position_col(size_c);

	}

	map.close();

	return 0;
}