#include "fraction.hpp"
#include "utils.hpp"






// exo 1 :
/*Fraction operator+(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator + f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

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
}*/

//exo 2
std::ostream& operator<<(std::ostream& os, Fraction const& f) {
    return os << f.numerator << "/" << f.denominator;
}

//exo 3
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

Fraction& Fraction::operator-=(Fraction const& f) {
    numerator = numerator * f.denominator - f.numerator * denominator;
    denominator = denominator * f.denominator;

    *this = simplify(*this);
    return *this;
}

Fraction& Fraction::operator*=(Fraction const& f) {
    numerator *= f.numerator;
    denominator *= f.denominator;
    *this = simplify(*this);
    return *this;
}

Fraction& Fraction::operator/=(Fraction const& f) {
    numerator *= f.denominator;
    denominator *= f.numerator;
    *this = simplify(*this);
    return *this;
}


Fraction operator+(Fraction const& f1, Fraction const& f2) {
    Fraction temp {f1};
    temp += f2;
    return simplify (temp);
}

Fraction operator-(Fraction const& f1, Fraction const& f2) {
    Fraction temp {f1};
    temp -= f2;
    return simplify (temp);
}

Fraction operator*(Fraction const& f1, Fraction const& f2) {
    Fraction temp {f1};
    temp *= f2;
    return simplify (temp);
}

Fraction operator/(Fraction const& f1, Fraction const& f2) {
    Fraction temp {f1};
    temp /= f2;
    return simplify (temp);
}



//exo 6 :
float Fraction::to_float () const{
    return (static_cast<float>(numerator) / static_cast<float>(denominator));
}

Fraction::operator float() const {
    return to_float();
}


// Pour aller plus loin
// 1/ 
Fraction operator+(Fraction const& f, int const i){
    Fraction iFraction {i,1};
    return simplify (iFraction+f);
}
Fraction operator+(int const i, Fraction const& f){
    return simplify({f+i});
}

Fraction operator-(Fraction const& f, int const i){
    Fraction iFraction {i,1};
    return simplify (f-iFraction);
}
Fraction operator-(int const i, Fraction const& f){
    Fraction iFraction {i,1};
    return simplify({iFraction-f});
}

Fraction operator*(Fraction const& f, int const i){
    Fraction iFraction {i,1};
    return simplify (iFraction*f);
}
Fraction operator*(int const i, Fraction const& f){
    return simplify({f*i});
}

Fraction operator/(Fraction const& f, int const i){
    Fraction iFraction {i,1};
    Fraction temp {f};
    temp /= iFraction;
    return simplify (temp);
}
Fraction operator/(int const i, Fraction const& f){
    Fraction iFraction {i,1};
    return simplify({iFraction/f});
}


