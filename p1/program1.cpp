#include <iostream>
#include <string>
#include <fstream>

int main(int argv, char** args)
{
	std::ifstream fileX, fileY;
	std::ofstream fileOutput;

	if (argv != 4)
	{
		std::cout << "Usage: ./program1 <fileX> <fileY> <fileOutput>" << std::endl;
		exit(1);
	}

	fileX.open(args[1], ios::in);
	if (! fileX.is_open())
	{
		std::cerr << "FileX is not valid!" << std::endl;
		exit(1);
	}

	fileY.open(args[2], ios::in);
	if (! fileY.is_open())
	{
		std::cerr << "FileY is not valid!" << std::endl;
		exit(1);
	}

	fileOutput.open(args[3], ios::out);
	if (! fileOutput.is_open())
	{
		std::cerr << "FileOutput is not valid!" << std::endl;
		exit(1);
	}
}