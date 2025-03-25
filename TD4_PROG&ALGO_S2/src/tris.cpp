#include "tris.hpp"

bool is_sorted(std::vector<float> const& vec) {
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

// partitionner(tableau T, entier premier, entier dernier, entier pivot)
//     échanger T[pivot] et T[dernier]  // échange le pivot avec le dernier du tableau , le pivot devient le dernier du tableau
//     j := premier
//     pour i de premier à dernier - 1 // la boucle se termine quand i = (dernier élément du tableau).
//         si T[i] <= T[dernier] alors
//             échanger T[i] et T[j]
//             j := j + 1
//     échanger T[dernier] et T[j]
//     renvoyer j

// tri_rapide(tableau T, entier premier, entier dernier)
//         si premier < dernier alors
//             pivot := choix_pivot(T, premier, dernier)
//             pivot := partitionner(T, premier, dernier, pivot)
//             tri_rapide(T, premier, pivot-1)
//             tri_rapide(T, pivot+1, dernier)

size_t quick_sort_partition(std::vector<float> & vec, size_t left, size_t right, size_t const pivot){
    std::swap(vec[left],vec[right]);
    size_t j {left};
    for (size_t i {left}; i < right-1; i++){
        if(vec[i]<=vec[right]){
            std::swap(vec[i],vec[j]);
            j = j+1;
        }
    }
    std::swap(vec[right],vec[j]);
    return j;
}


void quick_sort(std::vector<float> & vec, size_t const left, size_t const right){
    if (left < right){
        size_t pivot = left;
        pivot = quick_sort_partition (vec, left, right, pivot);
        quick_sort (vec, left, pivot - 1);
        quick_sort (vec, pivot + 1, right);

    }
}

void quick_sort(std::vector<float> & vec) {
    quick_sort(vec, 0, vec.size() - 1);
}

