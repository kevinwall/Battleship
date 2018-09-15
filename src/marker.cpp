#include "../includes/marker.h"

int make_symbol( flags x  )
{
	switch( x )
	{
		case WATER:
			return 0;
			break;
		case SUBMARINE:
			return 1;
			break;
		case HEAD_H:
			return 2;
			break;
		case HEAD_V:
			return 3;
			break;
		case TAIL_H:
			return 4;
			break;
		case TAIL_V:
			return 5;
			break;
		case BODY:
			return 6;
			break;
		case INVALID:
			return 7;
			break;
	}

	return 7;
}

void generator_def( int ** first, int lin, int col)
{
	for( auto i{0} ; i < lin ; i++)
	{
		for( auto j{0} ; j < col ; j++)
		{
			first[i][j] = make_symbol(WATER);
		}
	}


}

void print_puzzle( int ** first, int lin, int col)
{
	std::cout<<"Printing puzzle..."<<std::endl;
	for(auto i{0}; i < lin; i++)
	{
		for(auto j{0}; j < col; j++)
		{
			std::cout<<first[i][j];
		}

	std::cout<<std::endl;

	}
}