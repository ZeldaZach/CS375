Compile:
$ make

Cleanup:
$ make clean

Execute:
$ ./BestFirstSearch <input.txt> <output.txt>

input.txt format:
total entries, max capacity
item 1 weight, item 1 profit
...
item N weight, item N profit

output.txt format:
input entries, optimal solution profit, inputs in optimal solution
total nodes, leaf nodes
item 1 weight, item 1 profit
...
item M weight, item M profit

Advanced structures:
Priority queue and vectors


Runtime:
Worst: O(2^N)
Best: O(N)