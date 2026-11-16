#include <iostream>
#include <string>
#include "Rational.h"

namespace my_namespace {

    template<typename T>
    T max2(T a, T b)
    {
        return (a > b) ? a : b;
    }

}

int main() {
    int x, y;
    std::cout << "Enter two numbers: ";
    std::cin >> x >> y;
    std::cout << "The maximum is: "
              << my_namespace::max2(x, y) << std::endl;

    double a, b;
    std::cout << "Enter two floating-point numbers: ";
    std::cin >> a >> b;
    std::cout << "The maximum is: "
              << my_namespace::max2(a, b) << std::endl;

    std::string s1, s2;
    std::cout << "Enter two strings: ";
    std::cin >> s1 >> s2;
    std::cout << "The maximum is: "
              << my_namespace::max2(s1, s2) << std::endl;

    Rational r1, r2;
    std::cout << "Enter two rational numbers (numerator and denominator): ";
    std::cin >> r1 >> r2;
    std::cout << "The maximum is: "
              << my_namespace::max2(r1, r2) << std::endl;

    return 0;
}