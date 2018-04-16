//
// Created by Zachary Halpern on 4/15/18.
//

#ifndef P2_BESTFIRSTSEARCH_H
#define P2_BESTFIRSTSEARCH_H

#include <vector>
#include <ctime>

class BestFirstSearch
{
    public:
        explicit BestFirstSearch(char *args[]);
        bool readInputs(char *args[]);
        void print();
        void sortItemsByWeight();
        void calculateOptimalKnapsack();

    private:
        std::vector<std::pair<int, int> > itemStash;
        std::vector<std::vector<int> > knapsackMatrix;
        int maxCapacity, totalEntries;

        void createKnapsackMatrix();
        //clock_t clock;
};

#endif //P2_BESTFIRSTSEARCH_H
