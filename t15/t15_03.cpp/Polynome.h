#pragma once

#include <iostream>
#include <fstream>

using namespace std;

class Polynome
{
    int n;
    double* a;

public:
    Polynome(int n = 1);

    Polynome(int n, const double* coefficients);

    Polynome(const Polynome& p);

    ~Polynome();

    void input();

    void setCoefficient(int i, double value);

    void output() const;

    Polynome& operator=(const Polynome& p);

    friend ostream& operator<<(ostream& out, const Polynome& p);

    friend istream& operator>>(istream& in, Polynome& p);

    friend void writeBinary(const char* filename, const Polynome& p);

    friend void readBinary(const char* filename, Polynome& p);
};