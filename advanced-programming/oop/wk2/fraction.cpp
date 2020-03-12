#include <iostream>

#include "mylib.h"
#include "fraction.h"

Fraction::Fraction() {
    std::cout << "Ctor-> Fraction()\n";

    this->init(0, 0);
}

Fraction::Fraction(int numerator, int denominator) {
    std::cout << "Ctor-> Fraction(int, int)\n";

    this->init(numerator, denominator);
}

Fraction::~Fraction() {
    std::cout << "Dtor-> Fraction()-> (";
    this->print();
    std::cout << ")\n";
}

int Fraction::getNumerator() {
    return this->numerator;
}

int Fraction::getDenominator() {
    return this->denominator;
}

void Fraction::setNumerator(int num) {
    this->numerator = num;
}

void Fraction::setDenominator(int denom) {
    this->denominator = denom;
}

void Fraction::queryInfo() {
    this->numerator = getInt(std::cin, "Input numerator: ");
    this->denominator = getInt(std::cin, "Input denominator: ");
}

void Fraction::print() {
    std::cout << this->numerator << "/" << this->denominator;
}

void Fraction::reduce() {
    int gcd = this->findGCD(this->numerator, this->denominator);

    this->numerator /= gcd;
    this->denominator /= gcd;
}

void Fraction::init(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
}

/**
 * 
 * function gcd(a, b)
 *     if b = 0
 *         return a
 *     else
 *         return gcd(b, a mod b)
 * 
 * */
int Fraction::findGCD(int x, int y) {
    if (!y) return x;
    else return this->findGCD(y, x % y);
}
