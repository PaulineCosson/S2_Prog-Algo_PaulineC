#include <iostream>

int main()
{
    std::string expression ;
    std::cout << "Quelle est votre expression ? ";
    std::getline(std::cin, expression);

    std::cout << expression;
}