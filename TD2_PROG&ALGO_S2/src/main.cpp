#include <iostream>

#include "exo1.hpp"
#include "exo2.hpp"

int main()
{
    std::string expression ;
    std::cout << "Quelle est votre expression ? ";
    std::getline(std::cin, expression);
    // std::cout << expression;
    std::vector<std::string> tokens {split_string(expression)};
    std::vector<Token> vecTokens{tokenize(tokens)};
    float result {npi_evaluate(vecTokens)};
    std::cout << result;




}