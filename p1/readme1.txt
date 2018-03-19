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

Operations:
$ make p1
$ ./program1 <fileX> <fileY> <fileOutput>