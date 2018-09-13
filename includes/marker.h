//Enumeração para facilitar a alocação dos navios na matriz.
enum flags
{
	WATER = 0,
	SUBMARINE ,
	HEAD_H,
	HEAD_V,
	TAIL_H,
	TAIL_V,
	BODY,
	INVALID 
};

//Gerador de símbolos para os navios.
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
	}
}

//Gerador da matriz genérica
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