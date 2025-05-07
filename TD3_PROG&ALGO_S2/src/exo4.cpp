#include "exo4.hpp"

int search (std::vector<int>const & vec, int findValue){
    long long unsigned int left {0};
    long long unsigned int right {vec.size()-1};
    long long unsigned int middle{(left + right) / 2};

    while (vec[middle]!=findValue){
        
        if (vec[middle]<vec[findValue]){
            left = middle;
        }
        else {
            right = middle;
        }
        middle = (left + right) / 2;

        if (left == right && vec[middle]!=vec[findValue]){
            return (-1);
        }
    }
    return (middle);

}