//
// Created by Zachary Halpern on 4/15/18.
//

#include <iostream>
#include <ctime>
#include "BestFirstSearch.h"

int main(int argv, char** args)
{
    if (argv != 3)
    {
        std::cout << "Usage: " << args[0] << " <input> <output>" << std::endl;
        exit(1);
    }

    auto *BFS = new BestFirstSearch(args);

    delete BFS;
}
