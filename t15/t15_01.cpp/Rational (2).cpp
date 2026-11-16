#include "Rational (2).h"
#include <stdexcept>

int Rational::gcd_rational(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void Rational::input() {
    cout << "Input n,m: ";
    cin >> *this;
}

void Rational::output() const {
    cout << nom << "/" << den << endl;
}

Rational Rational::add(const Rational& x) const {
    Rational r;
    r.nom = nom * x.den + x.nom * den;
    r.den = den * x.den;
    r.reduce();
    return r;
}

Rational Rational::sub(const Rational& x) const {
    Rational r;
    r.nom = nom * x.den - x.nom * den;
    r.den = den * x.den;
    r.reduce();
    return r;
}

Rational Rational::mul(const Rational& x) const {
    Rational r;
    r.nom = nom * x.nom;
    r.den = den * x.den;
    r.reduce();
    return r;
}

Rational Rational::div(const Rational& x) const {
    if (x.nom == 0) {
        throw runtime_error("Division by zero!");
    }

    Rational r;
    r.nom = nom * x.den;
    r.den = den * x.nom;
    r.reduce();
    return r;
}