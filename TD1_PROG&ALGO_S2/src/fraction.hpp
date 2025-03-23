#pragma once
#include <iostream>


struct Fraction {
    int numerator;
    int denominator;

    // void display();
    Fraction& operator+=(Fraction const& f);
    Fraction& operator-=(Fraction const& f);
    Fraction& operator*=(Fraction const& f);
    Fraction& operator/=(Fraction const& f);

    float to_float() const;
    operator float() const;

    Fraction operatorabs();
};

std::ostream& operator<<(std::ostream& os, Fraction const& f);
Fraction operator+(Fraction const& f1, Fraction const& f2);
Fraction operator-(Fraction const& f1, Fraction const& f2);
Fraction operator*(Fraction const& f1, Fraction const& f2);
Fraction operator/(Fraction const& f1, Fraction const& f2);

bool operator==(Fraction const& f1, Fraction const& f2);
bool operator!=(Fraction const& f1, Fraction const& f2);

bool operator<(Fraction const& f1, Fraction const& f2);
bool operator<=(Fraction const& f1, Fraction const& f2);
bool operator>(Fraction const& f1, Fraction const& f2);
bool operator>=(Fraction const& f1, Fraction const& f2);


Fraction operator+(Fraction const& f, int const i);
Fraction operator+(int const i, Fraction const& f);
Fraction operator-(Fraction const& f, int const i);
Fraction operator-(int const i, Fraction const& f);
Fraction operator*(Fraction const& f, int const i);
Fraction operator*(int const i, Fraction const& f);
Fraction operator/(Fraction const& f, int const i);
Fraction operator/(int const i, Fraction const& f);
