﻿# Introdução: #

Este projeto tem como intenção implementar o jogo puzzle battleship assim como um gerador de puzzles para se utilizar no jogo.

# Bibliotecas: #

As bibliotecas utilizadas para a implementação deste projeto, fora as padrões do C++, foram:
- marker.h:
	Biblioteca utilizada para inserir os caracteres na matriz e para depurar o código.
- insert.h: 
	Biblioteca que insere os barcos na matriz do puzzle.
- Game_Engine.h:
	Biblioteca com funções utilizadas para executar o jogo

# Arquivo puzzle: #

O arquivo gerado pelo Puzzle_Generator.cpp tem vem na seguinte formatação:

P<br />
N M <br />
000000000<br />
000000000<br />
000000000<br />
000000000<br />
000000000<br />
000000000<br />
N M<br />
000000000<br />
000000000<br />
000000000<br />
000000000<br />
000000000<br />


Onde P é a quantidade de puzzles e N e M as dimensões do tabuleiro de jogo.

# Como compilar: #

Para utilizar o gerador de puzzles: <br />
Basta entrar no diretório do projeto e digitar o comando: <br />
**make** <br />
Depois basta digitar: <br />
**./bin/battleship P N M** (Lembrando: P = quantidade de puzzles, N = quatidade de linhas e M = quantidade de colunas)<br />
Após isso, será gerado um arquivo Puzzles.txt na pasta onde foi executado o comando make. Este arquivo contém as matrizes geradas pelo gerador de puzzles

Para utilizar o jogo: <br />
Basta entrar no diretório do projeto e digitar o comando: <br />
**make game** <br />
Depois basta digitar: <br />
**./bin/battleship**

# Autoria: #

Todos os códigos aqui implementados foram desenvolvidos por [Kevin Wallacy de Souza Maciel](https://github.com/kevinwall) (Email de contato: <kevinwall@ufrn.edu.br>) e [Giovanne da Silva Santos](https://github.com/GSDante) (Email de contato: <giovannedssantos@gmail.com>) <br />
&copy; IMD/UFRN 2018-2019
