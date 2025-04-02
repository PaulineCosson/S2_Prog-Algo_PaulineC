#include <iostream>

#include "exo1.hpp"
#include "exo2.hpp"


int main()
{
    std::string s1 {"abc"};
    std::string s2 {"cba"};
    size_t hash1{0};
    size_t hash2 {0};

    size_t max{1000000009};
    hash1 = folding_string_hash_sum(s1,max);
    hash2 = folding_string_hash_sum(s2,max);
    std::cout << "hachage simple chaine 1 : " << hash1 << " chaine 2 : " << hash2 << std::endl;

    hash1 = folding_string_ordered_hash(s1,max);
    hash2 = folding_string_ordered_hash(s2,max);
    std::cout << "hachage ordonné chaine 1 : " << hash1 << " chaine 2 : " << hash2 << std::endl;

    size_t p {31};
    hash1 = polynomial_rolling_hash(s1,p,max);
    hash2 = polynomial_rolling_hash(s2,p,max);
    std::cout << "polynomial rolling hash : chaine 1 : " << hash1 << " chaine 2 : " << hash2 << std::endl;

    

}