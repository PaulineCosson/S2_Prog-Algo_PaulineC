#include "exo4.hpp"

int search (std::vector<int>const & vec, int findValue){
    long long unsigned int left {0};
    long long unsigned int right {vec.size()-1};
    long long unsigned int middle{(left + right) / 2};

    while (vec[middle]!=findValue){
        
        if (vec[middle]<findValue){
            left = middle+1;
        }
        else {
            right = middle-1;
        }
        middle = (left + right) / 2;

        if (left == right && vec[middle]!=findValue){
            return (-1);
        }
    }
    return (middle);

}