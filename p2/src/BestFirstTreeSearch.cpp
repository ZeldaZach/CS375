//
// Created by Zachary Halpern on 4/16/18.
//

#include "BestFirstTreeSearch.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

BestFirstTreeSearch::BestFirstTreeSearch(char *args[]) : best_value(0), nodes(0), leaf_nodes(0), best_add(0), nodes_in_solution(0)
{
    readInputs(args);
    solutions.push({includes, 0, 0, knapsack_fractional(max_capacity, 0, 0, 0), 0});


    while (!solutions.empty())
    {
        Answer current = solutions.top();
        solutions.pop();

        nodes++;

        if (current.c_element < total_entries)
        {
            if (current.t_value >= best_value && current.c_weight < max_capacity)
            {
                std::vector<bool> hold_true = current.include, hold_false = current.include;

                hold_true.push_back(true);
                hold_false.push_back(false);

                Item oitem = items.at(current.c_element);
                int combined_weight = current.c_weight + oitem.weight;
                int combined_profit = current.c_value + oitem.profit;

                int add_item = knapsack_fractional(max_capacity, current.c_element+1, combined_weight, combined_profit);
                int dont_add = knapsack_fractional(max_capacity, current.c_element+1, current.c_weight, current.c_value);

                if (add_item >= best_value)
                {
                    solutions.push({hold_true, combined_weight, combined_profit, add_item, current.c_element+1});

                    if (combined_profit > best_value && combined_weight <= max_capacity)
                    {
                        best_value = combined_profit;
                    }
                    else if (combined_weight > max_capacity)
                    {
                        best_add++;
                    }
                }

                solutions.push({hold_false, current.c_weight, current.c_value, dont_add, current.c_element+1});
            }
            else
            {
                leaf_nodes++;
            }
        }
        else
        {
            leaf_nodes++;
        }

        if (current.c_value == best_value)
        {
            includes = current.include;
        }
    }

    writeOutputs(args);
}

bool BestFirstTreeSearch::writeOutputs(char *args[])
{
    std::ofstream output;

    output.open(args[2], std::ios::out);
    if (! output.is_open())
    {
        std::cerr << "Output is not valid!" << std::endl;
        return false;
    }

    for (int i = 0; i < total_entries; i++)
    {
        if (includes.at(i))
        {
            nodes_in_solution++;
        }
    }

    // Line 1: total_entries of Problem, Max Profit, total_entries of first optimal solution found
    output << total_entries << "," << best_value << "," << nodes_in_solution << "\n";

    // Line 2: Total number of nodes visited, total number of leaves visited
    output << nodes << "," << leaf_nodes << "\n";

    // Line 3 to 3+(k-1): Weight, Profit in order
    for (int i = 0; i < total_entries; i++)
    {
        if (includes.at(i))
        {
            output << items.at(i).weight << "," << items.at(i).profit << "\n";
        }
    }

    output.close();
    return true;
}

bool BestFirstTreeSearch::readInputs(char *args[])
{
    // Try to open Input file
    std::ifstream input;
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
            items.push_back({values.at(0), values.at(1)});
        }
        else
        {
            total_entries = values.at(0);
            max_capacity = values.at(1);
            isFirstLine = !isFirstLine;
        }
    }
    input.close();

    sort(items.begin(), items.end());
    return true;
}

int BestFirstTreeSearch::knapsack_fractional(int cost, int i, int p_weight, int p_profit)
{
    while (p_weight != cost && i < total_entries)
    {
        if ((p_weight + items.at(i).weight) < cost)
        {
            p_weight += items.at(i).weight;
            p_profit += items.at(i).profit;
        }
        else
        {
            float remainder = (cost - p_weight);
            p_weight = cost;
            p_profit += static_cast<int>(items.at(i).p_to_w_ratio * remainder);
        }

        i++;
    }

    return p_profit;
}