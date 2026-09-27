#include <stdio.h>

// a) y = x^(2n) + x^(2n-1) + ... + x + 1
double poly_a(double x, int n) {
    double sum = 0.0;
    double term = 1.0;
    for (int i = 0; i <= 2 * n; i++) {
        sum += term;
        term *= x;
    }
    return sum;
}

// б) y = x^(3n) + x^(3n-1) + ... + x + 1
double poly_b(double x, int n) {
    double sum = 0.0;
    double term = 1.0;
    for (int i = 0; i <= 3 * n; i++) {
        sum += term;
        term *= x;
    }
    return sum;
}

// в) y = x^(1^2) + x^(2^2) + ... + x^(n^2)
double poly_v(double x, int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        double term = 1.0;
        int p = i * i;
        for (int j = 0; j < p; j++) {
            term *= x;
        }
        sum += term;
    }
    return sum;
}

int main() {
    double x;
    int n;

    printf("Enter x: ");
    scanf("%lf", &x);
    printf("Enter n: ");
    scanf("%d", &n);

    printf("poly_a(x, n) = %lf\n", poly_a(x, n));
    printf("poly_b(x, n) = %lf\n", poly_b(x, n));
    printf("poly_v(x, n) = %lf\n", poly_v(x, n));

    return 0;
}