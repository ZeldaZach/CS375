#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct Program3
{
	int longestCommonSubsequence(int, int);
	std::vector<char> XAxis, YAxis;
	std::vector<std::vector<int> > value_matrix;
};

int Program3::longestCommonSubsequence(int x_index, int y_index)
{
	if (value_matrix[x_index][y_index] == -1)
	{
		if (x_index >= static_cast<int>(XAxis.size()) || y_index >= static_cast<int>(YAxis.size()))
		{
			value_matrix[x_index][y_index] = 0;
		}
		else if (XAxis[x_index] == YAxis[y_index])
		{
			value_matrix[x_index][y_index] = 1 + longestCommonSubsequence(x_index+1, y_index+1);
		}
		else
		{
			value_matrix[x_index][y_index] = std::max(
				longestCommonSubsequence(x_index+1, y_index),
				longestCommonSubsequence(x_index, y_index+1)
			);
		}
	}
	
	return value_matrix[x_index][y_index];
}

int main(int argv, char** args)
{
	Program3 p3;
	std::ifstream fileX, fileY;
	std::ofstream fileOutput;
	clock_t t = clock();

	/* Ensure proper file handling start */
	if (argv != 4)
	{
		std::cout << "Usage: " << args[0] << " <fileX> <fileY> <fileOutput>" << std::endl;
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
	/* Ensure proper file handling end */


	/* Populate the X and Y vectors */
	{
		std::string line;
		getline(fileX, line);
		for (char i : line)
        {
			p3.XAxis.push_back(i);
		}

		getline(fileY, line);
		for (char i : line)
        {
			p3.YAxis.push_back(i);
		}

		fileX.close();
		fileY.close();
	}

	// Value and Direction vectors (Size +1 because of the 0 length option)
	p3.value_matrix.resize(p3.XAxis.size() + 1);
	
	// Default the matrix
	for (int i = 0; i < static_cast<int>(p3.XAxis.size()+1); i++)
	{
		p3.value_matrix[i].resize(p3.YAxis.size()+1);
		for (int j = 0; j < static_cast<int>(p3.YAxis.size()+1); j++)
		{
			p3.value_matrix[i][j] = -1;
		}
	}

	// Stop the clock
	t = clock() - t;
	
	fileOutput << "Maximum Length: " << p3.longestCommonSubsequence(0, 0) << std::endl;
	fileOutput << "Running Time: " << static_cast<float>(t)/CLOCKS_PER_SEC << "sec" << std::endl;

	fileOutput.close();
	return 0;
}