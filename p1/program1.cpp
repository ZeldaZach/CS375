#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main(int argv, char** args)
{
	std::ifstream fileX, fileY;
	std::ofstream fileOutput;
	std::vector<char> XAxis, YAxis;

	/* Ensure proper file handling start */
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

	// Value and Direction vectors (Size +1 because of the 0 length option)
	std::vector<std::vector<int> > 	value_matrix(XAxis.size()+1, std::vector<int>(YAxis.size()+1));
	std::vector<std::vector<char> > arrow_matrix(XAxis.size()+1, std::vector<char>(YAxis.size()+1));

	// Insert the 0's and -'s for the 0 length of both X and Y
	for (int i = 0; i < XAxis.size()+1; i++)
	{
		value_matrix[i][0] = 0;
		arrow_matrix[i][0] = '-';
	}
	for (int i = 0; i < YAxis.size()+1; i++)
	{
		value_matrix[0][i] = 0;
		arrow_matrix[0][i] = '-';
	}

	// Populate the remainder of the matrices 
	for (int x = 1; x < XAxis.size()+1; x++)
	{
		for (int y = 1; y < YAxis.size()+1; y++)
		{
			// Match = grab the diagonal ++
			if (XAxis[x - 1] == YAxis[y - 1])
			{
				value_matrix[x][y] = value_matrix[x-1][y-1] + 1;
				arrow_matrix[x][y] = 'D';
			}
			else
			{
				// No Match = largest of top or left
				value_matrix[x][y] = std::max(value_matrix[x-1][y], value_matrix[x][y-1]);
				if (value_matrix[x][y] == value_matrix[x-1][y])
				{
					arrow_matrix[x][y] = 'U';
				}
				else
				{
					arrow_matrix[x][y] = 'L';
				}
			}
		}
	}

	// If Input Strings <= 10
	if (value_matrix.size() <= 10)
	{
		int x = XAxis.size(), y = YAxis.size();
		std::string sequence;

		while (true)
		{
			if (arrow_matrix[x][y] == 'D')
			{
				sequence = XAxis[x - 1] + sequence;
				x--;
				y--;
			}
			else if (arrow_matrix[x][y] == 'U')
			{
				x--;
			}
			else if (arrow_matrix[x][y] == 'L')
			{
				y--;
			}
			else // Probably hit a '-'
			{
				break;
			}
		}

		// Output the row of matrix lenLCS
		for (int x = 0; x < XAxis.size()+1; x++)
		{
			for (int y = 0; y < YAxis.size()+1; y++)
			{
				fileOutput << value_matrix[x][y];
			}
			fileOutput << std::endl;
		}
		fileOutput << sequence << std::endl;
		fileOutput << "Running Time: THETA(" << XAxis.size()*YAxis.size() << ")" << std::endl;
	}
	else // Else Input Strings > 10
	{
		fileOutput << "Maximum Length: " << value_matrix[XAxis.size()][YAxis.size()] << std::endl;
		fileOutput << "Running Time: THETA(" << XAxis.size()*YAxis.size() << ")" << std::endl;
	}

	fileOutput.close();
	return 0;
}