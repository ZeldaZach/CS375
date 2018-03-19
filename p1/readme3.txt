The goal of Program 3 is to find the longest common subsequence of two gien sequences (fileX, fileY) using a recursive approach with memoization.

This program will output the following:
fileOutput:
uint - longest length
float - algorithm execution time

Data structures used include one vector matrix (vector<vector<T> >) that contain the path data.

Computation time of this program is O(X.length * Y.length) => O(nm)

Compile:
$ make p3

Run:
$ ./program3 <fileX> <fileY> <fileOutput>