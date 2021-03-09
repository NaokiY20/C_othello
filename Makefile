main: main.cpp othello.cpp color.cpp
	g++ main.cpp othello.cpp color.cpp -lncursesw

test: test.cpp othello.cpp color.cpp
	g++ test.cpp othello.cpp color.cpp -lncursesw