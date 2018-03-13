#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>

int longestCommonSubsequence(std::vector<char> x_axis, std::vector<char> y_axis, int x_index, int y_index)
{
	if (x_index >= x_axis.size() || y_index >= y_axis.size())
	{
		return 0;
	}
	else if (x_axis[x_index] == y_axis[y_index])
	{
		return 1 + longestCommonSubsequence(x_axis, y_axis, x_index+1, y_index+1);
	}
	else
	{
		return std::max(
			longestCommonSubsequence(x_axis, y_axis, x_index+1, y_index),
			longestCommonSubsequence(x_axis, y_axis, x_index, y_index+1)
		);
	}
}

int main(int argv, char** args)
{
	std::ifstream fileX, fileY;
	std::ofstream fileOutput;
	std::vector<char> XAxis, YAxis;
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
		for (int i = 0; i < static_cast<int>(line.length()); ++i)
		{
			XAxis.push_back(line[i]);
		}

		getline(fileY, line);
		for (int i = 0; i < static_cast<int>(line.length()); ++i)
		{
			YAxis.push_back(line[i]);
		}

		fileX.close();
		fileY.close();
	}

	// Stop the clock
	t = clock() - t;
	
	fileOutput << "Maximum Length: " << longestCommonSubsequence(XAxis, YAxis, 0, 0) << std::endl;
	fileOutput << "Running Time: " << static_cast<float>(t)/CLOCKS_PER_SEC << "sec" << std::endl;

	fileOutput.close();
	return 0;
}