#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main(int argv, char** args)
{
	std::ifstream fileX, fileY;
	std::ofstream fileOutput;
	std::vector<char> XAxis, YAxis;

	if (argv != 4)
	{
		std::cout << "Usage: ./program1 <fileX> <fileY> <fileOutput>" << std::endl;
		exit(1);
	}

	// Try to open FileX
	fileX.open(args[1], std::ios::in);
	if (! fileX.is_open())
	{
		std::cerr << "FileX is not valid!" << std::endl;
		exit(1);
	}

	// Try to open FileY
	fileY.open(args[2], std::ios::in);
	if (! fileY.is_open())
	{
		std::cerr << "FileY is not valid!" << std::endl;
		fileX.close();
		exit(1);
	}

	// Try to open FileOutput
	fileOutput.open(args[3], std::ios::out);
	if (! fileOutput.is_open())
	{
		std::cerr << "FileOutput is not valid!" << std::endl;
		fileX.close();
		fileY.close();
		exit(1);
	}

	// Populate the "DNA" vectors
	{
		std::string line;
		getline(fileX, line);
		for (int i = 0; i < static_cast<int>(line.length()); ++i)
		{
			XAxis.push_back(line[i]);
		}

		getline(fileY, line);
		for (int i = 0; i < static_cast<int>(line.length()); ++i)
		{
			YAxis.push_back(line[i]);
		}
	}

	std::vector<std::vector<int> > matrix(XAxis.size()+1, std::vector<int>(YAxis.size()+1));
	
	for (int x = 1; x < static_cast<int>(matrix.size()); x++)
	{
		for (int y = 1; y < static_cast<int>(matrix.at(x).size()); y++)
		{
			if (XAxis.at(x-1) == YAxis.at(y-1))
			{
				matrix.at(x).at(y) = matrix.at(x-1).at(y-1) + 1;
			}
			else
			{
				matrix.at(x).at(y) = std::max(matrix.at(x-1).at(y), matrix.at(x).at(y-1));
			}
		}
	}

	for (unsigned int i = 0; i < matrix.size(); ++i)
	{
	    for (unsigned int j = 0; j < matrix.at(i).size(); ++j)
	    {
	        std::cout << matrix[i][j];
	    }
	    std::cout << std::endl;
	}

	std::cout << "Max length is " << matrix.at(XAxis.size()).at(YAxis.size()) << std::endl;


}