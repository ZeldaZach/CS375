FLAGS = -std=c++14 -Wall -Wextra -pedantic

all: p1 p2 p3

.PHONY: p1 p2 p3 debug_run clean

p1: src/program1.cpp
	g++ src/program1.cpp -o program1 $(FLAGS)

p2: src/program2.cpp
	g++ src/program2.cpp -o program2 $(FLAGS)

p3: src/program3.cpp
	g++ src/program3.cpp -o program3 $(FLAGS)

debug_run: p1 p2 p3
	./program1 ./filex.txt ./filey.txt ./output1.txt
	./program2 ./filex.txt ./filey.txt ./output2.txt
	./program3 ./filex.txt ./filey.txt ./output3.txt
	cat ./output1.txt
	cat ./output2.txt
	cat ./output3.txt

clean:
	rm -f program1 program2 program3
