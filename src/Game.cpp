#include "../includes/marker.h"
#include "../includes/insert.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>

void print_matrix_g(std::vector<std::vector<int>> &A, int lin, int col)
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

int main()
{
	std::string file, string;
	int qt_maps, lin, col, lin_b, col_b, cor;
	
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

	std::cout<<"Criando os vetroes: "<<std::endl;
	std::vector<std::vector<int>> A(lin, std::vector<int>(col));
	std::vector<std::vector<int>> B(lin, std::vector<int>(col));

	for(auto i{0}; i < qt_maps; i++)
	{
		std::cout<<"Entrei no 1° for "<<std::endl;
		for(auto j{0}; i < lin; j++)
		{
			std::cout<<"Entrei no 2° for "<<std::endl;
			for(auto k{0}; k < col; k++)
			{
				std::cout<<"Entrei no 3° for "<<std::endl;
				std::getline(maps, string);
				buffer.str(string);
				A[j][k] = std::atoi(&string[k]);

			}
			buffer.clear();
			std::cout<<"Saí do for "<<std::endl;
		}

		std::cout<<"Olá, seja bem vindo ao battleship puzzle"<<std::endl;
		for(auto rev{0}; rev < 5; rev++)
		{
			print_matrix_g(B, lin, col);
			std::cout<<"Escolha 1 posição da matriz para revelar: lin col "<<std::endl;
			std::cin>>lin_b;
			std::cin>>col_b;

			while(lin_b > 15 and col_b > 15)
			{
				std::cout<<"Você digitou uma posição inválida, insira outra entrada: lin col "<<std::endl;
				std::cin>>lin_b;
				std::cin>>col_b;
			}
	
			B[lin_b][col_b] = A[lin_b][col_b];
		}

		while(true)
		{
			print_matrix_g(B, lin, col);
			std::cout<<"Digite uma coordenada para marcar ou 0 para sair: "<<std::endl;
			std::cin>>cor;

			if(cor == 0)
			{
				break;
			}
		}
	}

	maps.close();
	//std::cout<<"A quantidade de mapas é: "<<qt_maps<<" a de linhas é: "<<lin<<" a de colunas é: "<<col<<" e a primeira linha da matriz é: "<<std::endl<<string<<std::endl;

	return 0;
}