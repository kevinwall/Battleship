#PROJETO LP1

PROG = ./bin/battleship
CC = g++
CPPFLAGS = -O0 -g -W -Wall -std=c++11 -pedantic
OBJS = Puzzle_Generator.o insert.o marker.o
HEADER = ./includes/insert.h
SRC_DIR     = ./src/
BIN_DIR     = ./bin/

$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $(PROG)
	rm *.o

Puzzle_Generator.o: $(HEADER)
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)Puzzle_Generator.cpp
insert.o: $(HEADER)
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)insert.cpp
marker.o: $(HEADER)
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)marker.cpp
Game:
	$(CC) -Wall -std=c++11 $(SRC_DIR)Game.cpp $(SRC_DIR)Game_Engine.cpp -o $(PROG)
clean:
	rm -f $(PROG) 
