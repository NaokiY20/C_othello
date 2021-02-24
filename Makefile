main: main.cpp board.cpp
	g++ main.cpp board.cpp -lncursesw

test: test.cpp board.cpp
	g++ test.cpp board.cpp -lncursesw