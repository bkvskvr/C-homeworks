#ifndef POLYNOME_H
#define POLYNOME_H

#include <vector>
#include <cmath>

namespace polynome {

template <typename T>
class Polynome {
private:
    std::vector<T> coefficients;

public:
    Polynome(const std::vector<T>& coeffs) : coefficients(coeffs) {}
    Polynome() : coefficients() {}

    void input();
    void print() const;

    T evaluate(T x) const;

    Polynome<T> add(const Polynome<T>& other) const;
    Polynome<T> multiply(const Polynome<T>& other) const;
};

}

#include "Polynome.cpp"

#endif // POLYNOME_H
