FLAGS = -std=c++14 -Wall -Wextra -g

all: p1 p2 p3

p1:
	g++ src/program1.cpp -o program1 $(FLAGS)

p2:
	g++ src/program2.cpp -o program2 $(FLAGS)

p3:
	g++ src/program3.cpp -o program3 $(FLAGS)

run:
	./program1 ./filex.txt ./filey.txt ./output1.txt
	./program2 ./filex.txt ./filey.txt ./output2.txt
	./program3 ./filex.txt ./filey.txt ./output3.txt

outputs: run
	cat ./output1.txt
	cat ./output2.txt
	cat ./output3.txt

clean:
	rm -f program1 program2 program3
	rm -f output1.txt output2.txt output3.txt
	rm -rf *.dSYM
