chess:
	g++ src/main.cpp src/board.cpp src/game.cpp -o chess -Wall -Wextra -pedantic -std=c++20 -Iinclude

clean:
	rm -f chess