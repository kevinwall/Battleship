#include <iostream>
#include <fstream>

bool compare_map( )

char * print_map( int A[]){

}

int main( int argc , char * argv[])
{

	if( argc < 3 or argc > 3)
	{
		std::cerr << "Numero de parametros inválidos \n";
	}

	std::ofstream map;
	map.open("Puzzes.txt");
	map << argv[1];
	
	char A[10][10];

	generator( int )



}