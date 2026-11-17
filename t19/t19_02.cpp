#include <iostream>
#include <vector>
#include <cmath>

bool input_vector(std::vector<double>& v) {
    double value;
    std::cout << "Enter size: ";
    int size;
    std::cin >> size;

    if (!std::cin || size <= 0)
        return false;

    for (int i = 0; i < size; ++i) {
        std::cout << "Enter element: ";
        std::cin >> value;

        if (!std::cin)
            return false;

        v.push_back(value);
    }

    return !v.empty();
}

void print_vector(const std::vector<double>& v) {
    for (double value : v) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

std::vector<double> input_vector(int d) {
    std::vector<double> v(d);

    for (int i = 0; i < d; ++i) {
        std::cout << "Enter element: ";
        std::cin >> v[i];
    }

    return v;
}

double norm_vector(const std::vector<double>& v) {
    double sum = 0.0;

    for (double value : v) {
        sum += value * value;
    }

    return std::sqrt(sum);
}

int main() {
    int n, d;

    std::cout << "Enter number of vectors: ";
    std::cin >> n;

    std::cout << "Enter dimension d: ";
    std::cin >> d;

    if (!std::cin || n <= 0 || d <= 0) {
        std::cout << "Invalid input!" << std::endl;
        return 1;
    }

    std::vector<std::vector<double>> vectors;

    for (int i = 0; i < n; ++i) {
        std::cout << "Enter vector " << i + 1 << ":" << std::endl;
        vectors.push_back(input_vector(d));

        if (!std::cin) {
            std::cout << "Invalid input!" << std::endl;
            return 1;
        }
    }

    double sum_norms = 0.0;

    for (int i = 0; i < vectors.size(); ++i) {
        std::cout << "Vector " << i + 1 << ": ";

        print_vector(vectors[i]);

        double norm = norm_vector(vectors[i]);

        std::cout << "Norm: " << norm << std::endl;

        sum_norms += norm;
    }

    std::cout << "Sum of norms: " << sum_norms << std::endl;

    return 0;
}