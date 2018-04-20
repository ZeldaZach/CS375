//
// Created by Zachary Halpern on 4/16/18.
//

#ifndef P2_BESTFIRSTTREESEARCH_H
#define P2_BESTFIRSTTREESEARCH_H

#include <vector>
#include <queue>

class BestFirstTreeSearch
{
    public:
        BestFirstTreeSearch(char *args[]);

    private:
        struct Item
        {
            int weight, profit;
            float p_to_w_ratio;

            Item (int w, int p) : weight(w), profit(p), p_to_w_ratio(static_cast<float>(profit)/static_cast<float>(weight))
            {
            }

            friend bool operator<(const Item& lhs, const Item& rhs)
            {
                return lhs.p_to_w_ratio > rhs.p_to_w_ratio;
            }
        };

        struct Answer
        {
            std::vector<bool> include;
            int c_weight, c_value, t_value, c_element;

            Answer (std::vector<bool> inc, int cweight, int cvalue, int tvalue, int celement) :
                    include(inc),
                    c_weight(cweight),
                    c_value(cvalue),
                    t_value(tvalue),
                    c_element(celement)
            {
            }

            friend bool operator< (const Answer& lhs, const Answer& rhs)
            {
                return lhs.t_value < rhs.t_value;
            }
        };

        bool readInputs(char *args[]);
        bool writeOutputs(char *args[]);
        int knapsack_fractional(int, int, int);

        std::vector<Item> items;
        std::priority_queue<Answer> solutions;
        std::vector<bool> includes;
        int total_entries, max_capacity, best_value, nodes, leaf_nodes, best_add, nodes_in_solution;

};

#endif //P2_BESTFIRSTTREESEARCH_H
