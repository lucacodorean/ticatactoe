output: main.o board.o game.o
	g++ main.o board.o game.o -o output -std=c++17

main.o: main.cpp
	g++ -c main.cpp

board.o: board.cpp
	g++ -c board.cpp

game.o: game.cpp
	g++ -c game.cpp

clean: 
	rm *.o