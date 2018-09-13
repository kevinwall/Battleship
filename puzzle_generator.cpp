#include <iostream>
#include <fstream>

enum flags
{
	WATER = 0,
	SUBMARINE ,
	HEAD_OR_TAIL,
	BODY,
	INVALID 
};

void make_symbol( flags x  )
{
	switch( x )
	{
		case WATER:
			std::cout << " - ";
			break;
		case SUBMARINE:
			std::cout << " 0 ";
			break;
		case HEAD_OR_TAIL:
			std::cout << " < "
			break;
		case BODY:
			std::cout << " O ";
			break;
	}
}

bool compare_map( )

char * generator( char ** A[][], int qtd)
{
	int count {0};
	while( count != qtd)
	{	
	
		for( auto i ; i <= col ; i++){
			for( auto j ; j <= lin ; j++){
				
			}
		}
	}
}

char * print_map( int A[]){

}

int main( int argc , char * argv[])
{

	if( argc < 3 or argc > 3)
	{
		std::cerr << "Numero de parametros inválidos \n";
	}

	std::ofstream map;
	map << argv[1];
	
	char A[10][10];

	generator( int )



}