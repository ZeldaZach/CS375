//
// Created by Zachary Halpern on 4/15/18.
//



#include "BestFirstSearch.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iomanip>

BestFirstSearch::BestFirstSearch(char *args[])
{
    if (!readInputs(args))
    {
        return;
    }

    sortItemsByWeight();
    calculateOptimalKnapsack();

}

void BestFirstSearch::calculateOptimalKnapsack()
{
    // Zero out matrix
    createKnapsackMatrix();
    print();

    for (int i = 0; i < totalEntries; i++)
    {
        for (int c = 0; c < maxCapacity; c++)
        {
            int weight = itemStash.at(i).first, profit = itemStash.at(i).second;

            if (weight <= c)
            {
                knapsackMatrix.at(i+1).at(c) = std::max(
                        knapsackMatrix.at(i).at(c),
                        knapsackMatrix.at(i).at(c-weight) + profit
                    );
            }
            else
            {
                knapsackMatrix.at(i+1).at(c) = knapsackMatrix.at(i).at(c);
            }
        }
    }
}

void BestFirstSearch::createKnapsackMatrix()
{
    // Matrix is now maxCapacity x totalEntries in size
    // Also zero'd out
    knapsackMatrix.resize(totalEntries+1);
    for (int i = 0; i < totalEntries; i++)
    {
        knapsackMatrix[i].resize(maxCapacity+1);
        std::fill(knapsackMatrix[i].begin(), knapsackMatrix[i].end(), 0);
    }
}

bool BestFirstSearch::readInputs(char *args[])
{
    std::ifstream input;

    // Try to open Input file
    input.open(args[1], std::ios::in);
    if (! input.is_open())
    {
        std::cerr << "Input is not valid!" << std::endl;
        return false;
    }

    std::string line;
    bool isFirstLine = true;
    while (std::getline(input, line)) // Get the line "2,40"
    {
        std::string value;
        std::vector<int> values;
        std::stringstream data(line);

        while (std::getline(data, value, ',')) // Turns 2,40 into [2, 40]
        {
            values.push_back(stoi(value));
        }

        if (!isFirstLine)
        {
            itemStash.push_back(std::make_pair(values[0], values[1]));
        }
        else
        {
            totalEntries = values[0];
            maxCapacity = values[1];
            isFirstLine = !isFirstLine;
        }
    }

    input.close();
    return true;
}

void BestFirstSearch::sortItemsByWeight()
{
    std::sort(itemStash.begin(), itemStash.end());
}

void BestFirstSearch::print()
{
    std::cout << "Items: ";
    for (auto iter = itemStash.begin(); iter != itemStash.end(); iter++)
    {
        std::cout << "[" << iter->first << "," << iter->second << "] ";
    }
    std::cout << std::endl;

    std::cout << "Capacity: " << maxCapacity << std::endl;

    std::cout << "Matrix: " << std::endl;
    for (int i = 0; i < totalEntries; i++)
    {
        for (int j = 0; j < maxCapacity; j++)
        {
            std::cout << std::setw(4) << knapsackMatrix[i][j];
        }
        std::cout << std::endl;
    }
}


