main: main.cpp board.cpp color.cpp
	g++ main.cpp board.cpp color.cpp -lncursesw

test: test.cpp board.cpp color.cpp
	g++ test.cpp board.cpp color.cpp -lncursesw