#include "../includes/marker.h"
#include "../includes/insert.h"

//Função que gera posições X aleatórias para iterar sob a matriz.
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

//Função que gera posições Y aleatórias para iterar sob a matriz.
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

//Função que verifica o caso de colisão 1: se o barco não vai ultrapassar a matriz.
bool colision_1(int b, int c, int boat, int lin, int col, int k)
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

//Função que verifica a condição de colisão 2: outros barcos ou bordas ao redor.
bool colision_2(int **A, int b, int c, int boat, int lin, int col, int k)
{
	bool valid = true;

	if(b+boat > lin) //Verifica se o barco não vai passar das bordas (linhas)
	{
		return false;
	}

	if(c+boat > col) //Verifica se o barco não vai passar o limite dass bordas (colunas)
	{
		return false;
	}

	if(k == 0) //Caso de posicionar o barco na horizontal
	{
		if(b-1 < 0) //Caso o barco esteja "colado" com a borda superior da matriz.
		{
			if(c-1 < 0) //Caso o barco esteja "colado" com a borda esquerda da matriz.
			{
				for(auto i{b}; i < b+1; i++) //Itera evitando passar dos limites da matriz (definidos acima)
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
			else if(c+boat == col-1) //Caso o barco esteja na borda direita da matriz
			{
				for(auto i{b}; i < b+1; i++) //Itera evitando passar dos limites da matriz (definidos acima)
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
			else if(c+boat < col-1) //Caso o barco não toque as bordas e não ultrapasse os limites da matriz
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
		else if(b+1 == lin-1) //Caso o barco esteja na borda inferior da matriz
		{
			if(c-1 < 0) //Caso o barco esteja na borda esquerda inferior da matriz.
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
			else if(c+boat == col-1) //Caso o barco esteja na borda inferior direita da matriz
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
			else if(c+boat < col-1) //Caso o barco não toque as bordas e não passe dos limites da matriz
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
		else //Caso o barco não toque a borda (com relação as linhas)
		{
			if(c-1 < 0) //Caso o barco toque a borda esquerda
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
			else if(c+boat == col-1) //Caso o barco toque a borda direita
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
			else if(c+boat < col-1) //Caso o barco não toque nenhuma das bordas e não ultrapasse o limite da matriz
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
	else //Caso o barco seja colocado na vertical
	{
		if(c-1 < 0) //Caso o barco toque a borda esquerda
		{
			if(b-1 < 0) //Caso o barco toque a borda de cima
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
			else if(b+boat == lin-1) //Caso o barco toque a borda de baixo
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
			else if(b+boat < lin-1) //Caso o barco naõ toque nenhuma borda (com relação as linhas)
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
		else if(c+1 == col-1) //Caso o barco toque a borda direita
		{
			if(b-1 < 0) //Caso o barco toque a borda de cima
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
			else if(b+boat == lin-1) //Caso o barco toque a borda de baixo
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
			else if(b+boat < lin-1) //Caso o bardo não toque em nennhuma borda (com rellação as linhas)
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
		else //Caso o barco não toque nenhuma borda (com relação as colunas)
		{
			if(b-1 < 0) //Caso o barco toque a borda de cima
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
			else if(b+boat == lin-1) //Caso o barco toque na borda de baixo
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
			else if(b+boat < lin-1) //Caso o barco não toque nenhumma borda (Com relação as linhas)
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

//Função que invalida as áreas proximas ao barco já inserido
bool negate_area(int ** A, int b, int c, int boat, int lin, int col, int k)
{
	if(b+boat > lin) //Verifica se o barco passou dos limites da matriz.
	{
		return false;
	}

	if(c+boat > col) //Verifica se o barco passou dos limites da matriz
	{
		return false;
	}


	if(k == 0) //Caso o barco esteja na horizontal
	{
		if(b-1 < 0) //Caso o barco toque a borda de cima
		{
			if(c-1 < 0) //Caso o barco toque na borda esquerda
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
			else if(c+boat == col)//Caso o barco toque na borda direita
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
			else if(c+boat < col-1) //Caso o barco não toque em nenhuma borda (Com relação as colunas)
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
		else if(b+1 == lin) //Caso o barco esteja logo antes da ultima posição da matriz (Com relação a linha)
		{
			if(c-1 < 0) //Caso o barco esteja na tocando a borda esquerda.
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
			else if(c+boat == col) //Caso o barco esteja tocando a borda direita
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
			else if(c+boat < col-1) //Caso o barco não esteja tocando nehuma borda (com relação as colunas)
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
		else //Caso o barco não toque em nenhuma borda (em relação as linhas)
		{
			if(c-1 < 0) //Caso o barco toque a borda da esquerda
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
			else if(c+boat == col) //Caso o barco esteja tocando a borda direita
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
			else if(c+boat < col-1) //Caso o barco não toque nenhuma borda (em relação as colunas)
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
	else //Caso o barco seja posicionado na vertical
	{
		if(c-1 < 0) //Caso o barco toque a borda da esquerda
		{
			if(b-1 < 0) //Caso o barco toque a borda de cima
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
			else if(b+boat == lin) //Caso o barco toque a borda da direita
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
			else if(b+boat < lin-1) //Caso o barco não toque nenhuma borda (em relação as linhas)
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
		else if(c+1 == col) //Caso o barco toque a borda da direita
		{
			if(b-1 < 0) //Caso o barco toque a borda de cima
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
			else if(b+boat == lin) //Caso o barco toque a borda de baixo
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
			else if(b+boat < lin-1) //Caso o barco não toque nenhuma borda (em relação as linhas)
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
		else //Caso o barco não toque em nenhuma borda (em relação as colunas)
		{
			if(b-1 < 0) //Caso o barco toque a borda de cima
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
			else if(b+boat == lin) //Caso o barco toque a borda de baixo
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
			else if(b+boat < lin-1) //Caso o barco não toque nenhuma borda (com relação as linhas)
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

//Função que insere o barco na matriz
void insert_boat(int ** A, int B, int C, int boat, int k)
{
	if(boat == 1) //Caso o barco seja um submarino, ele é inserido aqui
	{
		A[B][C] = make_symbol( SUBMARINE );
	}
	else if(k == 0) //Caso o barco não seja um submarido e for inserido na horizontal
	{
		for(auto count{0}; count < boat; count++)
		{
			if(count == 0)
			{
				A[B][C+count] = make_symbol(HEAD_H); //Insere o símbolo da cabeça horizontal na matriz
			}
			else if(count == boat-1)
			{
				A[B][C+count] = make_symbol(TAIL_H); //INsere o símbolo da cauda horizontal na matriz
			}
			else
			{
				A[B][C+count] = make_symbol(BODY); //Insere o símbolo do corpo do navio na matriz
			}
			
		}
	}
	else //Caso o barco seja inserido na vertical
	{
		for(auto count{0}; count < boat; count++) 
		{
			if(count == 0)
			{
				A[B+count][C] = make_symbol(HEAD_V); //Insere o símbolo da cabeça vertical na matriz
			}
			else if(count == boat-1)
			{
				A[B+count][C] = make_symbol(TAIL_V); //Insere o símbolo da cabeça vertical na matriz
			}
			else
			{
				A[B+count][C] = make_symbol(BODY); //Insere o símbolo do corpo do navio na matriz
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
					auto res_1 = colision_1(B[i], C[j], boat, lin, col, pos[k]);//Testa a colisão 1.
					

					if(res_1 == true)
					{
						auto res_2 = colision_2(A, B[i], C[j], boat, lin, col, pos[k]); //Testa a colisão 2

						if(res_2 == true)
						{
							insert_boat(A, B[i], C[j], boat, pos[k]); //Insere o barco na posição encontrada
							negate_area(A, B[i], C[j], boat, lin, col, pos[k]); //Invalida as posições ao redor do barco inserido

							return true; //Caso o barco for inserido com sucesso, retorna verdadeiro e sai da função.
						}
					}
				}	
			}
		}
	}

	return false;
}