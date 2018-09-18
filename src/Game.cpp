#include "../includes/marker.h"
#include "../includes/insert.h"
#include "../includes/Game_Engine.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>

int main()
{
	std::string file, string; //String utilizada para extrair informações do arquivo
	int qt_maps, lin, col, lin_b, col_b, type, cor_x, cor_y; //Variáveis inteiras responsáveis por: guardar a quantidade de puzzles, quantidade de linhas do puzzle, tipo da coordenada e as coordenadas de x e y
	
	//Lê o nome do arquivo com os puzzles.
	std::cout<<"Digite o nome e caminho (se necessário) do arquivo com os puzzles: "<<std::endl;
	std::cin>>file;

	//Cria uma stream com o arquivo
	std::ifstream maps(file);

	//Retira a primeira linha do arquivo onde está a informação da quantidade de puzzles que o arquivo contém.
	std::getline(maps, string);

	//Cria uma stream para a string que recebe os dados do arquivo.
	std::stringstream buffer(string);

	//Guarda a quantidade de puzzles numa variável e limpa a stringstream
	buffer>>qt_maps;
	buffer.clear();

	//Lê outra linha do arquivo para retirar a quantidade de linhas e colunas da matriz.
	std::getline(maps, string);
	buffer.str(string);
	buffer>>lin;
	buffer>>col;
	buffer.clear();

	std::cout<<"Criando os vetroes: "<<std::endl;
	
	//Cria as matrizes A, B que ficarão responsáveis por guardar a solução e a resposta do jogador, respectivamente
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

	//Cria os vetores C e D que serão responsáveis por armazenar a quantidade de navios por linhas e colunas, respectivamente.
	int *C;

	C = new int [lin];

	int *D;
	
	D = new int [col];

	//Cria o char c que será utilizado para remover da string, cada elemento da matriz.
	char *c = new char;
	int score{0};

	for(auto i{0}; i < qt_maps; i++) //Enquanto houver puzzles no arquivo...
	{
		for(auto j{0}; j < lin; j++) //Itera sobre as linhas da matriz A
		{
			//Retira uma linha do arquivo e reseta o buffer para a string atualizada
			std::getline(maps, string);
			buffer.str(string);

			for(auto k{0}; k < col; k++) //Itera sobre as colunas da matriz A
			{	
				//Retira-se um caractere da string, que repesentará um elemento da matriz solução
				buffer.get(*c);
				A[j][k] = std::atoi(c); //Converte o caractere em inteiro

				if(A[j][k] != 0 and A[j][k] != 7) //Conta quantos navios existem nas linhas e colunas e armazena nos vetores C e D
				{
					C[j] += 1;
					D[k] += 1;
				}
			}

			buffer.clear(); //Limpra o buffer

		}

		zero_seven(A, lin, col); //Retira os 7's da matriz A para facilitar a comparação com a matriz B

		std::cout<<"Olá, seja bem vindo ao battleship puzzle"<<std::endl;
		for(auto rev{0}; rev < 5; rev++)
		{
			//Aqui, o jogador escolherá 5 posições da matriz para revelar
			print_matrix_g(B, C, D, lin, col);
			std::cout<<"Escolha 1 posição da matriz para revelar: lin col "<<std::endl;
			std::cin>>lin_b;
			std::cin>>col_b;

			//Caso o usuário digite uma posição fora dos limites da matriz
			while(lin_b >= lin or col_b >= col or lin_b < 0 or col_b < 0)
			{
				std::cout<<"Você digitou uma posição inválida, insira outra entrada: lin col "<<std::endl;
				print_matrix_g(B, C, D, lin, col);
				std::cin>>lin_b;
				std::cin>>col_b;
			}
	
			//Revela o conteúdo da posição digitada pelo usuário
			B[lin_b][col_b] = A[lin_b][col_b];
		}
		
		//Game loop
		while(true)
		{
			//Espera uma entrada do usuário na forma TIPO X Y onde o tipo representa a peça que se deseja inserir ou remover e X e Y, as coordenadas onde se deseja inserir
			std::cout<<"Digite uma coordenada (Tipo X Y) para marcar ou 0 para submeter seu resultado: "<<std::endl;
			std::cout<<"Tipos de coordenada: "<<std::endl
			<<"1- Submarino;"<<std::endl
			<<"2- Frente do navio (Horizontal);"<<std::endl
			<<"3- Frente do navio (Vertical);"<<std::endl
			<<"4- Traseira do navio (Horizontal);"<<std::endl
			<<"5- Traseira do navio (Vertical);"<<std::endl
			<<"6- Corpo do navio;"<<std::endl
			<<"7- Remover uma peça.";
			print_matrix_g(B, C, D, lin, col);
			std::cin>>type;
			
			//Caso o usuário digite 0, a sua "matriz resposta" é comparada com a matriz solução, caso acerte, seu score é aumentado
			if(type == 0)
			{
				if(comparator(A, B, lin, col) == true)
				{
					std::cout<<"Parabéns, você acertou o puzzle."<<std::endl;
					score++;
				}
				else
				{
					std::cout<<"Que pena, você errou o puzzle."<<std::endl;
				}

				break;
			}

			//Caso o usuário não digite 0, lê-se as coordenadas que se deseja colocar a peça
			std::cin>>cor_x;
			std::cin>>cor_y;

			//Caso o usuário digite uma coordenada não válida
			while(cor_x >= lin or cor_y >= col or cor_x < 0 or cor_y < 0)
			{
				std::cout<<"Você digitou uma posição inválida, insira outra entrada: X Y "<<std::endl;
				print_matrix_g(B, C, D, lin, col);
				std::cin>>cor_x;
				std::cin>>cor_y;
			}

			//Caso o usuário digite o tipo 7 (remoção), a peça naquela coordenada é removida
			if(type == 7)
			{
				B[cor_x][cor_y] = 0;
			}
			else
			{
				//Caso ele tenha digitado uma peça, insere a peça na matriz
				B[cor_x][cor_y] = type;
			}
			

		}

		//Zera-se o vetor C para reciclá-lo para a proxima rodada
		for(auto ziru{0}; ziru < lin; ziru++)
		{
			C[ziru] = 0;
		}

		//Zera-se o vetor B para reciclá-lo para a proxima rodada
		for(auto zirus{0}; zirus < col; zirus++)
		{
			D[zirus] = 0;
		}

		//Zera-se a matriz B para reciclá-la para a proxima rodada
		for(auto alpha{0}; alpha < lin; alpha++)
		{
			for(auto beta{0}; beta < col; beta++)
			{
				B[alpha][beta] = 0;
			}
		}

		//Retira as dimensões da proxima matriz
		std::getline(maps, string);
		buffer.str(string);
		buffer>>lin;
		buffer>>col;
		buffer.clear();
		
	}

	std::cout<<"Obrigado por jogar o battleship, sua pontuação foi: "<<score<<"/"<<qt_maps<<std::endl;

	//Fecha a stream do arquivo e deleta as matrizes e vetores dinamicamentes alocados.
	maps.close();
	delete A;
	delete B;
	delete C;
	delete D;
	delete c;

	return 0;
}