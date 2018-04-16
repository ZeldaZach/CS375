FLAGS = -std=c++14 -Wall -Wextra -pedantic -g

all: p1

.PHONY: p1 p2 p3 debug_run clean

p1: src/BestFirstSearch.cpp src/main.cpp
	g++ src/BestFirstSearch.cpp src/main.cpp -o BestFirstSearch $(FLAGS)


debug_run: p1


clean:
	rm -f BestFirstSearch
