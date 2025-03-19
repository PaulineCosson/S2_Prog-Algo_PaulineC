#include "tris.hpp"

bool is_sorted(std::vector<int> const& vec) {
    return std::is_sorted(vec.begin(), vec.end()); 
}


void bubble_sort(std::vector<int> & vec){
    size_t length {vec.size()};
    int temp{};
    for (size_t i {0}; i < length -1 ; i++){
        for(size_t j{0}; j< length - i -1; j++){
            if(vec[j]>vec[j+1]){
                temp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = temp;
            }
        }
    }
}