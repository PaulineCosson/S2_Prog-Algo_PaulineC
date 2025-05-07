#include <iostream>
#include <print>

#include "tris.hpp"
#include "exo3.hpp"
#include "ScopedTimer.hpp"
#include "exo4.hpp"

int main()
{
    std::vector<int> array {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> melange {2, 7, 5, 1, 9, 8, 3, 4, 6};
    
    for (size_t i {0}; i < melange.size(); i++){
        std::cout << melange[i];
    }

    quick_sort(melange);

    std::cout << std::endl;

    for (size_t i {0}; i < melange.size(); i++){
        std::cout << melange[i];
    }

    // if (is_sorted(melange)) {
    //     std::cout << "Le tableau est trié" << std::endl;
    // } else {
    //     std::cout << "Le tableau n'est pas trié" << std::endl;
    // }
    std::cout << std::endl;

    int id {search(melange,6)};
    std::cout << id << std::endl;

    
    
    std::vector<int> randVect {generate_random_vector(10000,100)};
    //Avec cette taille de vector on note ces vitesses
    test_bubble_sort(randVect); //490.564ms 
    test_quick_sort(randVect); //4.2922ms
    test_std_sort(randVect); //2.5125ms
    // Le bubble sort est significativement plus long que les 2 autres
    // Avec moins de valuers le quick sort est parfois plus rapide que le std sort 
    // mais avec un plus grand nombre de valeurs, les performances du std sort ressortent


}