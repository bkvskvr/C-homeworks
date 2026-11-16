#pragma once
#include <iostream>
using namespace std;

class Rational
{
    int nom;
    int den;

    static int gcd_rational(int a, int b);

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
        if (den == 0)
            den = 1;
        reduce();
    }

    void input();
    void output() const;

    double toDouble() const {
        return (double)nom / den;
    }

    void setNom(int n) {
        nom = n;
        reduce();
    }

    void setDen(int m) {
        if (m != 0) {
            den = m;
            reduce();
        }
    }

    Rational add(const Rational& x) const;
    Rational sub(const Rational& x) const;
    Rational mul(const Rational& x) const;
    Rational div(const Rational& x) const;

    Rational operator+(const Rational& x) const {
        return add(x);
    }

    Rational operator-(const Rational& x) const {
        return sub(x);
    }

    Rational operator*(const Rational& x) const {
        return mul(x);
    }

    Rational operator/(const Rational& x) const {
        return div(x);
    }

    bool operator==(const Rational& x) const {
        return (long long)nom * x.den == (long long)x.nom * den;
    }

    bool operator!=(const Rational& x) const {
        return !(*this == x);
    }

    bool operator<(const Rational& x) const {
        return (long long)nom * x.den < (long long)x.nom * den;
    }

    bool operator>(const Rational& x) const {
        return x < *this;
    }

    bool operator<=(const Rational& x) const {
        return !(x < *this);
    }

    bool operator>=(const Rational& x) const {
        return !(*this < x);
    }

    friend ostream& operator<<(ostream& out, const Rational& x) {
        out << x.nom << "/" << x.den;
        return out;
    }

    friend istream& operator>>(istream& in, Rational& x) {
        int n, m;
        if (in >> n >> m) {
            if (m == 0) {
                in.setstate(ios::failbit);
            }
            else {
                x.nom = n;
                x.den = m;
                x.reduce();
            }
        }
        return in;
    }
};