#pragma once

class Fraction {
public:
    Fraction();
    Fraction(int numerator, int denominator);

    ~Fraction();

    int getNumerator();
    int getDenominator();

    void setNumerator(int num);
    void setDenominator(int denom);

    void queryInfo();
    void print();

    void reduce();


private:
    int numerator;
    int denominator;

    void init(int numerator, int denominator);

    // Greatest Common Denominator
    int findGCD(int x, int y);


};
