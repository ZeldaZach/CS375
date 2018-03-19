The goal of program1 is to find the longest common subsequence of two given sequences (fileX and fileY)

This program does so by using the bottom-up approach method.

If the length of either inputs (fileX, fileY) > 10 then the output will be:
fileOutput:
uint - longest length
float - time of algorithm

If the length of both inputs <= 10, then the output will be:
fileOutput:
mxn matrix 
string - the longest path to take
uint - longest length
float - time of algorithm

Data structures used include two vector matricies (vector<vector<T> >) that contain the path data.

Computation time of this program is O(X.length * Y.length) => O(nm)

Compile:
$ make p1

Run:
$ ./program1 <fileX> <fileY> <fileOutput>