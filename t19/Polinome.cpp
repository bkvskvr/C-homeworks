#ifndef POLYNOME_CPP
#define POLYNOME_CPP

#include "Polynome.h"
#include <iostream>
#include <algorithm>

namespace polynome {

template <typename T>
void Polynome<T>::input() {
    int n;
    std::cout << "Enter the number of coefficients: ";
    std::cin >> n;
    coefficients.resize(n);

    for (int i = 0; i < n; ++i) {
        std::cout << "Enter coefficient for x^" << i << ": ";
        std::cin >> coefficients[i];
    }
}

template <typename T>
void Polynome<T>::print() const {
    for (int i = 0; i < coefficients.size(); ++i) {
        std::cout << coefficients[i] << "*x^" << i;
        if (i < coefficients.size() - 1)
            std::cout << " + ";
    }
    std::cout << std::endl;
}

template <typename T>
T Polynome<T>::evaluate(T x) const {
    T result = 0;
    T power = 1;

    for (T coeff : coefficients) {
        result += coeff * power;
        power *= x;
    }

    return result;
}

template <typename T>
Polynome<T> Polynome<T>::add(const Polynome<T>& other) const {
    std::vector<T> result_coeffs(
        std::max(coefficients.size(), other.coefficients.size()), 0
    );

    for (int i = 0; i < coefficients.size(); ++i)
        result_coeffs[i] += coefficients[i];

    for (int i = 0; i < other.coefficients.size(); ++i)
        result_coeffs[i] += other.coefficients[i];

    return Polynome<T>(result_coeffs);
}

template <typename T>
Polynome<T> Polynome<T>::multiply(const Polynome<T>& other) const {
    if (coefficients.empty() || other.coefficients.empty())
        return Polynome<T>();

    std::vector<T> result_coeffs(
        coefficients.size() + other.coefficients.size() - 1, 0
    );

    for (int i = 0; i < coefficients.size(); ++i)
        for (int j = 0; j < other.coefficients.size(); ++j)
            result_coeffs[i + j] += coefficients[i] * other.coefficients[j];

    return Polynome<T>(result_coeffs);
}

}

#endif 
