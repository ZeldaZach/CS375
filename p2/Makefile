FLAGS = -std=c++14 -Wall -Wextra -pedantic -g

all: p1

.PHONY: p1 clean

p1: src/BestFirstTreeSearch.cpp src/main.cpp
	g++ src/BestFirstTreeSearch.cpp src/main.cpp -o BestFirstSearch $(FLAGS)

clean:
	rm -rf BestFirstSearch *.dSYM
