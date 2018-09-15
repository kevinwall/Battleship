#include "../includes/marker.h"
#include <iostream>
#include <algorithm>

int * validate_position_col( int col)
{
	int * A = new int[col];

	for( auto i{0} ; i < col; i++)
	{
		A[i] = i;
	}

	std::cout <<"Vetor colunas: ["; 
	for( auto i{0} ; i < col; i++)
	{
		std::cout << A[i] << " " ; 
	}
	std::cout<<"]"<<std::endl ; 

	std::random_shuffle( A, A+col );

	std::cout <<"Vetor colunas: ["; 
	for( auto i{0} ; i < col; i++)
	{
		std::cout << A[i] << " " ; 
	}
	std::cout<<"]"<<std::endl ; 

	return A;
}

int * validate_position_lin( int lin)
{
	int * A = new int[lin];

	for( auto i{0} ; i < lin; i++)
	{
		A[i] = i;
	}

	std::cout <<"Vetor linhas: ["; 
	for( auto i{0} ; i < lin; i++)
	{
		std::cout << A[i] << " " ; 
	}
	std::cout<<"]"<<std::endl ; 

	std::random_shuffle( A, A+lin );

	std::cout <<"Vetor linhas: ["; 
	for( auto i{0} ; i < lin; i++)
	{
		std::cout << A[i] << " " ; 
	}
	std::cout<<"]"<<std::endl ; 

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
			else
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
			else
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
			else
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
			else
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
			else
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
			else
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

void negate_area(int ** A, int b, int c, int boat, int lin, int col, int k)
{
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
			else
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
		else if(b+boat == lin-1)
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
			else
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
			else
			{
				for(auto i{b-1}; i <= b+1; i++)
				{
					for(auto j{c-1}; j <= c+boat; j++)
					{
						//std::cout<<"Valor de C no teste 2: "<<c+j<<std::endl;
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
			else if(b+boat == lin-1)
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
			else
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
		else if(c+1 == col-1)
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
			else if(b+boat == lin-1)
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
			else
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
			else if(b+boat == lin-1)
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
			else
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
}

void insert_boat(int ** A, int B, int C, int boat, int k)
{
	//std::cout<<"Valor de B: "<<B<<" Valor de C: "<<C<<std::endl;
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
				std::cout<<"Valor de B : "<<B[i]<<" e C: "<<C[j]<<std::endl;
				for(auto k{0}; k < 2; k++)
				{
					//std::cout<<"TESTE 1"<<std::endl;
					auto res_1 = colision_1(A, B[i], C[j], boat, lin, col, pos[k]);//Testa a colisão 1.
					

					if(res_1 == true)
					{
						//std::cout<<"Valor do barco: "<<boat<<std::endl;
						//std::cout<<"TESTE 2"<<std::endl;
						auto res_2 = colision_2(A, B[i], C[j], boat, lin, col, pos[k]);
						//std::cout<<"Saí do teste 2"<<std::endl;
						if(res_2 == true)
						{
							insert_boat(A, B[i], C[j], boat, pos[k]);
							std::cout<<"Inseri um barco "<<boat<<std::endl;
							negate_area(A, B[i], C[j], boat, lin, col, pos[k]);
							return true;//Caso o barco for inserido com sucesso, retorna verdadeiro e sai da função.
						}
					}
				}	
			}
		}
	}

	return false;
}

int main()
{

	auto B = validate_position_lin(15);
	auto C = validate_position_col(15);

	int ** A;

	A = new int* [15];

	for(auto i{0}; i < 15; i++)
	{
		A[i] = new int [15];
	}

	generator_def(A, 15, 15);

	print_puzzle( A, 15, 15);

	test_position(A, B, C, 15, 15, 4);

	print_puzzle( A, 15, 15);

	for(auto i{0}; i < 2; i++)
	{
		test_position(A, B, C, 15, 15, 3);
		print_puzzle( A, 15, 15);
	}

	
	for(auto i{0}; i < 3; i++)
	{
		test_position(A, B, C, 15, 15, 2);
		print_puzzle( A, 15, 15);
	}

	for(auto i{0}; i < 4; i++)
	{
		test_position(A, B, C, 15, 15, 1);
		print_puzzle( A, 15, 15);
	}
	

	return 0;
}