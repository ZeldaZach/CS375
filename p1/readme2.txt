The goal of Program2 is to find the longest common subsequence of two given inputs (fileX, fileY) using a recurisve approach without memoization.

Output will be:
fileOutput:
uint - longest length
float - algorithm execution time

Data structures used include one vector matrix (vector<vector<T> >) that contain the path data.

Computation time of this program is O(2^(X.length * Y.length)) => O(2^(nm))

Compile:
$ make p2

Run:
$ ./program2 <fileX> <fileY> <fileOutput>