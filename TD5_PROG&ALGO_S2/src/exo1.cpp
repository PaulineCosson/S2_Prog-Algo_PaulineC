#include "exo1.hpp"

//1/
size_t folding_string_hash_sum(std::string const& s, size_t max) {
    size_t hash {0};
    for (char c : s) {
        hash += static_cast<size_t>(c);
        hash %= max;
    }
    return hash;
}

//2/
size_t folding_string_ordered_hash(std::string const& s, size_t max){
    size_t hash {0};
    for (int i{0}; i< s.size(); i++) {
        hash += static_cast<size_t>(s[i])*(i+1);
        hash %= max;
    }
    return hash;
}

//3/
size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m){
    size_t hash {0};
    size_t power{1};
    for (int i{0}; i< s.size(); i++) {
        power *= p;
        hash += static_cast<size_t>(s[i])*power;
        hash %= m;
    }
    return hash;
}

