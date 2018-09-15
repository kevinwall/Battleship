#include "../includes/marker.h"
#include "../includes/insert.h"

int * validate_position_col( int col)
{
	int * A = new int[col];

	for( auto i{0} ; i < col; i++)
	{
		A[i] = i;
	} 

	std::random_shuffle( A, A+col );

	return A;
}

int * validate_position_lin( int lin)
{
	int * A = new int[lin];

	for( auto i{0} ; i < lin; i++)
	{
		A[i] = i;
	}

	std::random_shuffle( A, A+lin );

	return A;
}


bool colision_1(int **A, int b, int c, int boat, int lin, int col, int k)
{
	if(k == 0)
	{
		if(c-1 + boat <= col)
		{
			return true;
		}
	}
	else
	{
		if(b-1 +boat <= lin)
		{
			return true;
		}
	}

	return false;
	
}

bool colision_2(int **A, int b, int c, int boat, int lin, int col, int k)
{
	bool valid = true;

	if(b+boat > lin)
	{
		return false;
	}

	if(c+boat > col)
	{
		return false;
	}

	if(k == 0)
	{
		if(b-1 < 0)
		{
			if(c-1 < 0)
			{
				for(auto i{b}; i < b+1; i++)
				{
					for(auto j{c}; j < c+boat; j++)
					{
						if(A[i][j] != 0)
						{
							valid = false;
						}
					}
				}
			}
			else if(c+boat == col-1)
			{
				for(auto i{b}; i < b+1; i++)
				{
					for(auto j{c-1}; j < c+boat-1; j++)
					{
						if(A[i][j] != 0)
						{
							valid = false;
						}
					}
				}
			}
			else if(c+boat < col-1)
			{
				for(auto i{b}; i < b+1; i++)
				{
					for(auto j{c-1}; j < c+boat; j++)
					{
						if(A[i][j] != 0)
						{
							valid = false;
						}
					}
				}
			}
		}
		else if(b+1 == lin-1)
		{
			if(c-1 < 0)
			{
				for(auto i{b-1}; i < b; i++)
				{
					for(auto j{c}; j < c+boat; j++)
					{
						if(A[i][j] != 0)
						{
							valid = false;
						}
					}
				}
			}
			else if(c+boat == col-1)
			{
				for(auto i{b-1}; i < b; i++)
				{
					for(auto j{c-1}; j < c+boat-1; j++)
					{
						if(A[i][j] != 0)
						{
							valid = false;
						}
					}
				}
			}
			else if(c+boat < col-1)
			{
				for(auto i{b-1}; i < b; i++)
				{
					for(auto j{c-1}; j < c+boat; j++)
					{
						if(A[i][j] != 0)
						{
							valid = false;
						}
					}
				}
			}
		}
		else
		{
			if(c-1 < 0)
			{
				for(auto i{b-1}; i < b+1; i++)
				{
					for(auto j{c}; j < c+boat; j++)
					{
						if(A[i][j] != 0)
						{
							valid = false;
						}
					}
				}
			}
			else if(c+boat == col-1)
			{
				for(auto i{b-1}; i < b+1; i++)
				{
					for(auto j{c-1}; j < c+boat-1; j++)
					{
						if(A[i][j] != 0)
						{
							valid = false;
						}
					}
				}
			}
			else if(c+boat < col-1)
			{
				for(auto i{b-1}; i < b+1; i++)
				{
					for(auto j{c-1}; j < c+boat; j++)
					{
						if(A[i][j] != 0)
						{
							valid = false;
						}
					}
				}
			}
		}
	}
	else
	{
		if(c-1 < 0)
		{
			if(b-1 < 0)
			{
				for(auto i{b}; i < b+boat; i++)
				{
					for(auto j{c}; j < c+1; j++)
					{
						if(A[i][j] != 0)
						{
							valid = false;
						}
					}
				}
			}
			else if(b+boat == lin-1)
			{
				for(auto i{b-1}; i < b+boat-1; i++)
				{
					for(auto j{c}; j < c+1; j++)
					{
						if(A[i][j] != 0)
						{
							valid = false;
						}
					}
				}
			}
			else if(b+boat < lin-1)
			{
				for(auto i{b-1}; i < b+boat; i++)
				{
					for(auto j{c}; j < c+1; j++)
					{
						if(A[i][j] != 0)
						{
							valid = false;
						}
					}
				}
			}
		}
		else if(c+1 == col-1)
		{
			if(b-1 < 0)
			{
				for(auto i{b}; i < b+boat; i++)
				{
					for(auto j{c-1}; j < c; j++)
					{
						if(A[i][j] != 0)
						{
							valid = false;
						}
					}
				}
			}
			else if(b+boat == lin-1)
			{
				for(auto i{b-1}; i < b+boat-1; i++)
				{
					for(auto j{c-1}; j < c; j++)
					{
						if(A[i][j] != 0)
						{
							valid = false;
						}
					}
				}
			}
			else if(b+boat < lin-1)
			{
				for(auto i{b-1}; i < b+boat; i++)
				{
					for(auto j{c-1}; j < c; j++)
					{
						if(A[i][j] != 0)
						{
							valid = false;
						}
					}
				}
			}
		}
		else
		{
			if(b-1 < 0)
			{
				for(auto i{b}; i < b+boat; i++)
				{
					for(auto j{c-1}; j < c+1; j++)
					{
						if(A[i][j] != 0)
						{
							valid = false;
						}
					}
				}
			}
			else if(b+boat == lin-1)
			{
				for(auto i{b-1}; i < b+boat-1; i++)
				{
					for(auto j{c-1}; j < c+1; j++)
					{
						if(A[i][j] != 0)
						{
							valid = false;
						}
					}
				}
			}
			else if(b+boat < lin-1)
			{
				for(auto i{b-1}; i < b+boat; i++)
				{
					for(auto j{c-1}; j < c+1; j++)
					{
						if(A[i][j] != 0)
						{
							valid = false;
						}
					}
				}
			}
		}
	}
	
	return valid;
}

bool negate_area(int ** A, int b, int c, int boat, int lin, int col, int k)
{
	if(b+boat > lin)
	{
		return false;
	}

	if(c+boat > col)
	{
		return false;
	}


	if(k == 0)
	{
		if(b-1 < 0)
		{
			if(c-1 < 0)
			{
				for(auto i{b}; i <= b+1; i++)
				{
					for(auto j{c}; j <= c+boat; j++)
					{
						if(A[i][j] == 0)
						{
							A[i][j] = make_symbol(INVALID);
						}
					}
				}
			}
			else if(c+boat == col)
			{
				for(auto i{b}; i <= b+1; i++)
				{
					for(auto j{c-1}; j <= c+boat-1; j++)
					{
						if(A[i][j] == 0)
						{
							A[i][j] = make_symbol(INVALID);
						}
					}
				}
			}
			else if(c+boat < col-1)
			{
				for(auto i{b}; i <= b+1; i++)
				{
					for(auto j{c-1}; j <= c+boat; j++)
					{
						if(A[i][j] == 0)
						{
							A[i][j] = make_symbol(INVALID);
						}
					}
				}
			}	
		}
		else if(b+1 == lin)
		{
			if(c-1 < 0)
			{
				for(auto i{b-1}; i <= b; i++)
				{
					for(auto j{c}; j <= c+boat; j++)
					{
						if(A[i][j] == 0)
						{
							A[i][j] = make_symbol(INVALID);
						}
					}
				}
			}
			else if(c+boat == col)
			{
				for(auto i{b-1}; i <= b; i++)
				{
					for(auto j{c-1}; j <= c+boat-1; j++)
					{
						if(A[i][j] == 0)
						{
							A[i][j] = make_symbol(INVALID);
						}
					}
				}
			}
			else if(c+boat < col-1)
			{
				for(auto i{b-1}; i <= b; i++)
				{
					for(auto j{c-1}; j <= c+boat; j++)
					{
						if(A[i][j] == 0)
						{
							A[i][j] = make_symbol(INVALID);
						}
					}
				}
			}
		}
		else 
		{
			if(c-1 < 0)
			{
				for(auto i{b-1}; i <= b+1; i++)
				{
					for(auto j{c}; j <= c+boat; j++)
					{
						if(A[i][j] == 0)
						{
							A[i][j] = make_symbol(INVALID);
						}
					}
				}
			}
			else if(c+boat == col)
			{
				for(auto i{b-1}; i <= b+1; i++)
				{
					for(auto j{c-1}; j <= c+boat-1; j++)
					{
						if(A[i][j] == 0)
						{
							A[i][j] = make_symbol(INVALID);
						}
					}
				}
			}
			else if(c+boat < col-1)
			{
				for(auto i{b-1}; i <= b+1; i++)
				{
					for(auto j{c-1}; j <= c+boat; j++)
					{
						if(A[i][j] == 0)
						{
							A[i][j] = make_symbol(INVALID);
						}
					}
				}
			}
		}
	}
	else
	{
		if(c-1 < 0)
		{
			if(b-1 < 0)
			{
				for(auto i{b}; i <= b+boat; i++)
				{
					for(auto j{c}; j <= c+1; j++)
					{
						if(A[i][j] == 0)
						{
							A[i][j] = make_symbol(INVALID);
						}
					}
				}
			}
			else if(b+boat == lin)
			{
				for(auto i{b-1}; i <= b+boat-1; i++)
				{
					for(auto j{c}; j <= c+1; j++)
					{
						if(A[i][j] == 0)
						{
							A[i][j] = make_symbol(INVALID);
						}
					}
				}
			}
			else if(b+boat < lin-1)
			{
				for(auto i{b-1}; i <= b+boat; i++)
				{
					for(auto j{c}; j <= c+1; j++)
					{
						if(A[i][j] == 0)
						{
							A[i][j] = make_symbol(INVALID);
						}
					}
				}
			}
		}
		else if(c+1 == col)
		{
			if(b-1 < 0)
			{
				for(auto i{b}; i <= b+boat; i++)
				{
					for(auto j{c-1}; j <= c; j++)
					{
						if(A[i][j] == 0)
						{
							A[i][j] = make_symbol(INVALID);
						}
					}
				}
			}
			else if(b+boat == lin)
			{
				for(auto i{b-1}; i <= b+boat-1; i++)
				{
					for(auto j{c-1}; j <= c; j++)
					{
						if(A[i][j] == 0)
						{
							A[i][j] = make_symbol(INVALID);
						}
					}
				}
			}
			else if(b+boat < lin-1)
			{
				for(auto i{b-1}; i <= b+boat; i++)
				{
					for(auto j{c-1}; j <= c; j++)
					{
						if(A[i][j] == 0)
						{
							A[i][j] = make_symbol(INVALID);
						}
					}
				}
			}
		}
		else
		{
			if(b-1 < 0)
			{
				for(auto i{b}; i <= b+boat; i++)
				{
					for(auto j{c-1}; j <= c+1; j++)
					{
						if(A[i][j] == 0)
						{
							A[i][j] = make_symbol(INVALID);
						}
					}
				}
			}
			else if(b+boat == lin)
			{
				for(auto i{b-1}; i <= b+boat-1; i++)
				{
					for(auto j{c-1}; j <= c+1; j++)
					{
						if(A[i][j] == 0)
						{
							A[i][j] = make_symbol(INVALID);
						}
					}
				}
			}
			else if(b+boat < lin-1)
			{
				for(auto i{b-1}; i <= b+boat; i++)
				{
					for(auto j{c-1}; j <= c+1; j++)
					{
						if(A[i][j] == 0)
						{
							A[i][j] = make_symbol(INVALID);
						}
					}
				}
			}
		}
	}

	return true;
}

void insert_boat(int ** A, int B, int C, int boat, int k)
{
	if(boat == 1)
	{
		A[B][C] = make_symbol( SUBMARINE );
	}
	else if(k == 0)
	{
		for(auto count{0}; count < boat; count++)
		{
			if(count == 0)
			{
				A[B][C+count] = make_symbol(HEAD_H);
			}
			else if(count == boat-1)
			{
				A[B][C+count] = make_symbol(TAIL_H);
			}
			else
			{
				A[B][C+count] = make_symbol(BODY);
			}
			
		}
	}
	else
	{
		for(auto count{0}; count < boat; count++)
		{
			if(count == 0)
			{
				A[B+count][C] = make_symbol(HEAD_V);
			}
			else if(count == boat-1)
			{
				A[B+count][C] = make_symbol(TAIL_V);
			}
			else
			{
				A[B+count][C] = make_symbol(BODY);
			}
			
		}
	}
}

//Função de teste para verificar se há posições válidas para a inserção dos barcos.
bool test_position( int ** A , int * B, int * C, int lin, int col, int boat)
{
	auto pos = validate_position_lin(2);


	//Iterando sobre o vetor B que contém posições randômicas afim de encontrar uma coordenada X aleatória de A.
	for( auto i = 0 ; i < lin ; i++)
	{
		//Iterando sobre o vetor C que contém posições randômicas afim de encontrar a coordenada Y aleatória de A.
		for( auto j = 0; j < col ; j++)
		{
			if(A[B[i]][C[j]] == 0)//Verifica se na posição (X, Y) da matriz há espaço para a inserção.
			{
				for(auto k{0}; k < 2; k++)
				{
					auto res_1 = colision_1(A, B[i], C[j], boat, lin, col, pos[k]);//Testa a colisão 1.
					

					if(res_1 == true)
					{
						auto res_2 = colision_2(A, B[i], C[j], boat, lin, col, pos[k]);

						if(res_2 == true)
						{
							insert_boat(A, B[i], C[j], boat, pos[k]);
							negate_area(A, B[i], C[j], boat, lin, col, pos[k]);

							return true; //Caso o barco for inserido com sucesso, retorna verdadeiro e sai da função.
						}
					}
				}	
			}
		}
	}

	return false;
}