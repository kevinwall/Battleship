#include "../includes/marker.h"
#include "../includes/insert.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

int main()
{
	std::string file, string;
	int qt_maps, lin, col;

	std::cout<<"Digite o nome e caminho (se necessário) do arquivo com os puzzles: "<<std::endl;
	std::cin>>file;

	std::ifstream maps(file);

	std::getline(maps, string);

	std::stringstream buffer(string);

	buffer>>qt_maps;
	buffer.clear();

	std::getline(maps, string);
	buffer.str(string);
	std::cout<<"String: "<<string<<std::endl;
	buffer>>lin;
	buffer>>col;

	std::getline(maps, string);
	maps.close();
	std::cout<<"A quantidade de mapas é: "<<qt_maps<<" a de linhas é: "<<lin<<" a de colunas é: "<<col<<" e a primeira linha da matriz é: "<<std::endl<<string<<std::endl;

	return 0;
}