FLAGS = -std=c++14 -Wall -Wextra -g -Wno-sign-compare

all: p1 p2

p1:
	g++ program1.cpp -o program1 $(FLAGS)
	./program1 ./filex.txt ./filey.txt ./output1.txt
	cat ./output1.txt

p2:
	g++ program2.cpp -o program2 $(FLAGS)
	./program2 ./filex.txt ./filey.txt ./output2.txt
	cat ./output2.txt

clean:
	rm program1 program2
