#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1 { 3, 4 };
    Fraction f2 { 1, 2 };

    std::cout << "f1 = " << f1;    
    std::cout << " f2 = " << f2 << std::endl;    

    Fraction f3 { f1 + f2 };
    std::cout << "f1 + f2 = "<< f3;
    std::cout << std::endl << "f1 - f2 = "<< (f1-f2); 
    std::cout << std::endl << "f1 * f2 = " << (f1*f2); 
    std::cout << std::endl << "f1 / f2 = " << (f1/f2); 
    std::cout << std::endl << "1/6 + 2/6 = " << (Fraction{1,6} + Fraction{2,6});

    float d1 {static_cast<float>(f1)};
    std::cout << std::endl << "f1 = " << (d1);

    std::cout << std::endl << "f1 - 2 = "<< (f1-2); 
    std::cout << std::endl << "f1 * 2 = " << (f1*2); 
    std::cout << std::endl << "f1 / 2 = " << (f1/2); 

    return 0;
}