battleship: main.o Executive.o Board.o Player.o
	g++ -std=c++11 -g -Wall main.o Executive.o Board.o Player.o -o battleship

main.o: main.cpp Executive.h Board.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

Player.o: Player.h Player.cpp
	g++ -std=c++11 -g -Wall -c Player.cpp

Board.o: Board.h Board.cpp
	g++ -std=c++11 -g -Wall -c Board.cpp

clean:
	rm *.o battleship
