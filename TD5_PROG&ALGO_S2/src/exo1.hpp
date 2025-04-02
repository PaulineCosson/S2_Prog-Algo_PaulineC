#pragma once

#include <cstring>
#include <string>


size_t folding_string_hash_sum(std::string const& s, size_t max);
size_t folding_string_ordered_hash(std::string const& s, size_t max);
size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m);