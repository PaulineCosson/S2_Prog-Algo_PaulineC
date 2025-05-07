#pragma once

#include <vector>
#include <cstdlib>
#include <algorithm>

std::vector<int> generate_random_vector(size_t const size, int const max = 100);

void test_bubble_sort (std::vector<int>const & randVect);
void test_quick_sort (std::vector<int>const & randVect);
void test_std_sort (std::vector<int>const & randVect);