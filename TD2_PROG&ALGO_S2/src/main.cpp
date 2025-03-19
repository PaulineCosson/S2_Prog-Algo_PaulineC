#include <iostream>

#include "utils.hpp"

int main()
{
    std::string expression ;
    std::cout << "Quelle est votre expression ? ";
    std::getline(std::cin, expression);
    // std::cout << expression;
    std::vector<std::string> tokens {split_string(expression)};

    float result {npi_evaluate(tokens)};
    std::cout << npi_evaluate;

}