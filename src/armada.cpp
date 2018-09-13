#include "../includes/armada.h"
/*
	ONE BATTLESHIP -> FOUR SLOTS
	TWO CRUISERS -> THREE SLOTS
	THREE DESTROYERS -> TWO SLOTS
	FOUR SUBMARINES -> ONE SLOTS
*/
void horizontal_battleship( int x, int y )
{
	char A[x][y];

	A[x][y] = make_symbol( HEAD_H );
	A[x+1][y] = make_symbol( BODY );
	A[x+2][y] = make_symbol( BODY );
	A[x+3][y] = make_symbol( TAIL_H );

}

void vertical_battleship( int x, int y )
{
	char A[x][y];

	A[x][y] = make_symbol( HEAD_V );
	A[x][y+1] = make_symbol( BODY );
	A[x][y+2] = make_symbol( BODY );
	A[x][y+3] = make_symbol( TAIL_V );

}

void horizontal_cruiser( int x, int y )
{

	char A[x][y];

	A[x][y] = make_symbol( HEAD_H );
	A[x+1][y] = make_symbol( BODY );
	A[x+2][y] = make_symbol( TAIL_H );
}

void vertical_cruiser( int x, int y )
{

	char A[x][y];

	A[x][y] = make_symbol( HEAD_V );
	A[x][y+1] = make_symbol( BODY );
	A[x][y+2] = make_symbol( TAIL_V );
}

void horizontal_cruiser( int x, int y )
{

	char A[x][y];

	A[x][y] = make_symbol( HEAD_H );
	A[x+1][y] = make_symbol( TAIL_H );
}

void vertical_cruiser( int x, int y )
{

	char A[x][y];

	A[x][y] = make_symbol( HEAD_V );
	A[x][y+1] = make_symbol( TAIL_V );
}