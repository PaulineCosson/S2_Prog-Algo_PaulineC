#include "tris.hpp"

bool is_sorted(std::vector<int> const& vec) {
    return std::is_sorted(vec.begin(), vec.end()); 
}

//exo 1/
void bubble_sort(std::vector<int> & vec){
    size_t length {vec.size()};
    for (size_t i {0}; i < length -1 ; i++){
        for(size_t j{0}; j< length - i -1; j++){
            if(vec[j]>vec[j+1]){
                std::swap(vec[j],vec[j+1]);
            }
        }
    }
}

//exo 2/ 

size_t quick_sort_partition(std::vector<int> & vec, size_t left, size_t right, size_t const pivot){
    std::swap(vec[left],vec[right]);
    size_t j {left};
    for (size_t i {left}; i < right; i++){
        if(vec[i]<vec[right]){
            std::swap(vec[i],vec[j]);
            j +=1;
        }
    }
    std::swap(vec[right],vec[j]);
    return j;
}


void quick_sort(std::vector<int> & vec, size_t const left, size_t const right){
    if (left < right){
        size_t pivot = left;
        pivot = quick_sort_partition (vec, left, right, pivot);

        if(pivot > left + 1) {

            quick_sort (vec, left, pivot - 1);
        }
        if(pivot + 1 < right ) {

            quick_sort (vec, pivot + 1, right);
        }

    }
}

void quick_sort(std::vector<int> & vec) {
    quick_sort(vec, 0, vec.size() - 1);
}

