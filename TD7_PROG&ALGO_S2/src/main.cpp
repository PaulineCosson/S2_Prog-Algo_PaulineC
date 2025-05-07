#include "graphe.hpp"
#include <iostream>



int main()
{
    std::unordered_map<int, std::vector<WeightedGraphEdge>> adjacency_list {
        {0, {{1, 1.0f}, {4, 2.0f}}},
        {1, {{2, 2.0f}, {3, 4.0f}}},
        {2, {{3, 1.0f}}},
        {3, {{4, 6.0f}}},
        {4, {}},
    };
}