#include <iostream>
#include <fstream>

bool compare_map( )

char * print_map( int A[]){

}

int main( int argc , char * argv[])
{

	std::string qtd_puzzle = argv[1];
	std::string lin = argv[2];
	std::string col = argv[3];

	if( argc != 4)
	{
		std::cerr << "Número de parâmetros inválidos \n";
	}

	std::ofstream map;
	map.open("Puzzles.txt");
	map << argv[1];
	
	char A[10][10];

	generator( int )

	auto B = validate_position_col( int col);

	auto C = validate_position_lin( int lin);


}