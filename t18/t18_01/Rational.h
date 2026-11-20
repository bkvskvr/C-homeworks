#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

class Rational
{
    int nom = 1;
    int den = 1;

    void reduce() {
        int d = gcd_rational(nom, den);
        if (d != 0) {
            nom /= d;
            den /= d;
        }
        if (den < 0) {
            nom = -nom;
            den = -den;
        }
    }

public:
    Rational() : nom(1), den(1) {}

    Rational(int n, int m) : nom(n), den(m) {
        if (m == 0)
            throw invalid_argument("Denominator cannot be zero!");
        reduce();
    }

    void input();
    void output();

    double toDouble() const {
        return (double)nom / den;
    }

    int gcd_rational(int a, int b);

    void setNom(int n) {
        nom = n;
        reduce();
    }

    void setDen(int m) {
        if (m == 0)
            throw invalid_argument("Denominator cannot be zero!");
        den = m;
        reduce();
    }

    Rational add(const Rational& x);
    Rational sub(const Rational& x);
    Rational mul(const Rational& x);
    Rational div(const Rational& x);

    Rational operator+(const Rational& x) {
        return add(x);
    }

    Rational operator-(const Rational& x) {
        return sub(x);
    }

    Rational operator-() const {
        return Rational(-nom, den);
    }

    Rational operator*(const Rational& x) {
        return mul(x);
    }

    Rational operator/(const Rational& x) {
        if (x.nom == 0)
            throw runtime_error("Division by zero!");
        return div(x);
    }

    bool operator==(const Rational& x) const {
        return (long long)nom * x.den == (long long)x.nom * den;
    }

    bool operator<=(const Rational& x) const {
        return (long long)nom * x.den <= (long long)x.nom * den;
    }

    bool operator>=(const Rational& x) const {
        return (long long)nom * x.den >= (long long)x.nom * den;
    }

    bool operator>(const Rational& x) const {
        return (long long)nom * x.den > (long long)x.nom * den;
    }

    friend ostream& operator<<(ostream& out, const Rational& x) {
        out << x.nom << "/" << x.den;
        return out;
    }

    friend istream& operator>>(istream& in, Rational& x) {
        int n, m;
        if (in >> n >> m) {
            if (m == 0)
                throw invalid_argument("Denominator cannot be zero!");
            x.nom = n;
            x.den = m;
            x.reduce();
        }
        return in;
    }

    friend void writeFile(const char* filename, const Rational& x);
};