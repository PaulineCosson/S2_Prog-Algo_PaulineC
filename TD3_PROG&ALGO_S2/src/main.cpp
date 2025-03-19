#include <iostream>
#include <print>

#include "tris.hpp"

int main()
{
    std::vector<int> array {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> melange {2, 7, 5, 1, 9, 8, 3, 4, 6};
    
    for (size_t i {0}; i < melange.size(); i++){
        std::cout << melange[i];
    }

    bubble_sort(melange);

    std::cout << std::endl;

    for (size_t i {0}; i < melange.size(); i++){
        std::cout << melange[i];
    }

    if (is_sorted(melange)) {
        std::cout << "Le tableau est trié" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }

}