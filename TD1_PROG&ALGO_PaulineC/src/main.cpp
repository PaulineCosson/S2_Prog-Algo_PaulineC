#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1 { 3, 4 };
    Fraction f2 { 1, 2 };

    std::cout << "f1 = " << f1;
    // f1.display();
    std::cout << " f2 = " << f2;
    // f2.display();
    std::cout << std::endl;

    Fraction f3 { f1 + f2 };

    std::cout << "f1 + f2 = "<< f3;
    // f3.display();

    std::cout << std::endl << "f1 - f2 = "<< (f1-f2);
    // (f1 - f2).display();

    std::cout << std::endl << "f1 * f2 = " << (f1*f2);
    // (f1 * f2).display();

    std::cout << std::endl << "f1 / f2 = " << (f1/f2);
    // (f1 / f2).display();

    std::cout << std::endl << "1/6 + 2/6 = " << (Fraction{1,6} + Fraction{2,6});
    // (Fraction{1,6} + Fraction{2,6}).display();

    return 0;
}