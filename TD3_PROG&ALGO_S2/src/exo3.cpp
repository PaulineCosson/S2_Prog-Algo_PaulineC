#include "exo3.hpp"
#include "tris.hpp"
#include "ScopedTimer.hpp"

std::vector<int> generate_random_vector(size_t const size, int const max) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

void test_bubble_sort (std::vector<int>const & randVect){
    ScopedTimer timer("Bubble sort");
    std::vector<int> vec {randVect};
    bubble_sort(vec);
}
void test_quick_sort (std::vector<int>const & randVect){
    ScopedTimer timer("Quick sort");
    std::vector<int> vec {randVect};
    quick_sort(vec);
}
void test_std_sort (std::vector<int>const & randVect){
    ScopedTimer timer("std sort");
    std::vector<int> vec {randVect};
    std::sort(vec.begin(), vec.end());
}