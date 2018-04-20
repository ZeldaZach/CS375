//
// Created by Zachary Halpern on 4/15/18.
//

#include <iostream>
#include "BestFirstTreeSearch.h"

int main(int argv, char** args)
{
    if (argv != 3)
    {
        std::cout << "Usage: " << args[0] << " <input> <output>" << std::endl;
        exit(1);
    }


    BestFirstTreeSearch BFTS(args);

}
