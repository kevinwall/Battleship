#include "../includes/marker.h"

char make_symbol( flags x  )
{
	switch( x )
	{
		case WATER:
			return '-';
			break;
		case SUBMARINE:
			return '0';
			break;
		case HEAD_H:
			return '<';
			break;
		case HEAD_V:
			return '^';
			break;
		case TAIL_H:
			return '>';
			break;
		case TAIL_V:
			return 'V';
			break;
		case BODY:
			return 'O';
			break;
		case INVALID:
			return 'x';
			break;
	}

	return 'x';
}

void generator_def( char ** first, int lin, int col)
{
	for( auto i{0} ; i < lin ; i++)
	{
		for( auto j{0} ; j < col ; j++)
		{
			first[i][j] = make_symbol(WATER);
		}
	}
}

void print_puzze( char ** first, int lin, int col)
{
	std::cout<<"Printing puzze..."<<std::endl;
	for(auto i{0}; i < lin; i++)
	{
		for(auto j{0}; j < col; j++)
		{
			std::cout<<first[i][j];
		}

	std::cout<<std::endl;

	}
}