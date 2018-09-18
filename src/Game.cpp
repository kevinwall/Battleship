#include "../includes/marker.h"
#include "../includes/insert.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>

void print_matrix_g(int **A, int lin, int col)
{
	std::cout<<"Matriz do jogo: "<<std::endl;
	for(auto i{0}; i < lin; i++)
	{
		for(auto j{0}; j < col; j++)
		{
			if(A[i][j] == 1)
			{
				std::cout<<"*";
			}
			else if(A[i][j] == 2)
			{
				std::cout<<"<";
			}
			else if(A[i][j] == 3)
			{
				std::cout<<"^";
			}
			else if(A[i][j] == 4)
			{
				std::cout<<">";
			}
			else if(A[i][j] == 5)
			{
				std::cout<<"v";
			}
			else if(A[i][j] == 6)
			{
				std::cout<<"o";
			}
			else
			{
				std::cout<<"-";
			}
		}
		std::cout<<std::endl;
	}
}

void print_puzzle(int **A, int lin, int col)
{
	std::cout<<"Matriz do jogo: "<<std::endl;
	for(auto i{0}; i < lin; i++)
	{
		for(auto j{0}; j < col; j++)
		{
			std::cout<<A[i][j];
		}

		std::cout<<std::endl;
	}
}

void zero_seven(int **A, int lin, int col)
{
	for(auto i{0}; i < lin; i++)
	{
		for(auto j{0}; j < col; j++)
		{
			if(A[i][j] == 7)
			{
				A[i][j] = 0;
			}
		}
	}
}

int main()
{
	std::string file, string;
	int qt_maps, lin, col, lin_b, col_b, type, cor_x, cor_y;
	
	std::cout<<"Digite o nome e caminho (se necessário) do arquivo com os puzzles: "<<std::endl;
	std::cin>>file;

	std::ifstream maps(file);

	std::getline(maps, string);

	std::stringstream buffer(string);

	buffer>>qt_maps;
	buffer.clear();

	std::getline(maps, string);
	buffer.str(string);
	buffer>>lin;
	buffer>>col;
	buffer.clear();

	std::cout<<"Dimensão das matrizes: "<<lin<<" "<<col<<std::endl;

	std::cout<<"Criando os vetroes: "<<std::endl;
	
	int ** A;

	A = new int* [lin];

	for(auto i{0}; i < lin; i++)
	{
		A[i] = new int [col];
	}

	int ** B;

	B = new int* [lin];

	for(auto i{0}; i < lin; i++)
	{
		B[i] = new int [col];
	};

	char c;
	for(auto i{0}; i < qt_maps; i++)
	{
		for(auto j{0}; j < lin; j++)
		{
			std::getline(maps, string);
			buffer.str(string);

			for(auto k{0}; k < col; k++)
			{	
				buffer.get(c);
				A[j][k] = std::atoi(&c);

			}
			buffer.clear();
		}

		zero_seven(A, lin, col);

		std::cout<<"Olá, seja bem vindo ao battleship puzzle"<<std::endl;
		for(auto rev{0}; rev < 5; rev++)
		{
			print_matrix_g(B, lin, col);
			std::cout<<"Escolha 1 posição da matriz para revelar: lin col "<<std::endl;
			std::cin>>lin_b;
			std::cin>>col_b;

			while(lin_b >= lin or col_b >= col or lin_b < 0 or col_b < 0)
			{
				std::cout<<"Você digitou uma posição inválida, insira outra entrada: lin col "<<std::endl;
				print_matrix_g(B, lin, col);
				std::cin>>lin_b;
				std::cin>>col_b;
			}
	
			B[lin_b][col_b] = A[lin_b][col_b];
		}
		

		while(true)
		{
			std::cout<<"Digite uma coordenada (Tipo X Y) para marcar ou 0 para sair: "<<std::endl;
			std::cout<<"Tipos de coordenada: "<<std::endl
			<<"1- Submarino;"<<std::endl
			<<"2- Frente do navio (Horizontal);"<<std::endl
			<<"3- Frente do navio (Vertical);"<<std::endl
			<<"4- Traseira do navio (Horizontal);"<<std::endl
			<<"5- Traseira do navio (Vertical);"<<std::endl
			<<"6- Corpo do navio."<<std::endl;
			print_matrix_g(B, lin, col);
			std::cin>>type;
			
			if(type == 0)
			{
				break;
			}

			std::cin>>cor_x;
			std::cin>>cor_y;

			while(cor_x >= lin or cor_y >= col or cor_x < 0 or cor_y < 0)
			{
				std::cout<<"Você digitou uma posição inválida, insira outra entrada: X Y "<<std::endl;
				print_matrix_g(B, lin, col);
				std::cin>>cor_x;
				std::cin>>cor_y;
			}

			B[cor_x][cor_y] = type;

		}
	}

	maps.close();
	//std::cout<<"A quantidade de mapas é: "<<qt_maps<<" a de linhas é: "<<lin<<" a de colunas é: "<<col<<" e a primeira linha da matriz é: "<<std::endl<<string<<std::endl;

	return 0;
}