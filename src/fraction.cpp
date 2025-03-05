#include "fraction.hpp"
#include "utils.hpp"


//Transformer la fonction display en surcharge de l'opérateur << 
//pour pouvoir afficher une fraction avec std::cout (opérateurs de flux).

// void Fraction::display() {
//     std::cout << numerator << "/" << denominator;
// }

std::ostream& operator<<(std::ostream& os, Fraction const& f) {
    return os << f.numerator << "/" << f.denominator;
}

Fraction operator+(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator + f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

// Fraction add(Fraction const& f1, Fraction const& f2) {
//     Fraction result {
//         f1.numerator * f2.denominator + f2.numerator * f1.denominator
//         f1.denominator * f2.denominator
//     };

//     return simplify(result);
// }


Fraction operator-(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator - f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

Fraction operator*(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.numerator,
        f1.denominator * f2.denominator
    });
}

Fraction operator/(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator,
        f1.denominator * f2.numerator
    });
}

bool operator==(Fraction const& f1, Fraction const& f2) {
    return (f1.numerator * f2.denominator == f1.denominator * f2.numerator);
}

bool operator!=(Fraction const& f1, Fraction const& f2) {
    return !(f1 == f2);
}

//exo 4
bool operator<(Fraction const& f1, Fraction const& f2) {
    return (f1.numerator / f2.denominator < f1.denominator / f2.numerator);
}

bool operator<=(Fraction const& f1, Fraction const& f2) {
    return (f1<f2 || f1==f2);
}

bool operator>(Fraction const& f1, Fraction const& f2) {
    return !(f1<=f2);
}

bool operator>=(Fraction const& f1, Fraction const& f2) {
    return !(f1<f2);
}

//exo 5
Fraction& Fraction::operator+=(Fraction const& f) {
    numerator = numerator * f.denominator + f.numerator * denominator;
    denominator = denominator * f.denominator;
    *this = simplify(*this);
    return *this;
}