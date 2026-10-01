#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double task16_g(double x, double eps) {
    double sum = 0.0;
    double term = 1.0;
    int k = 0;

    while (fabs(term) >= eps) {
        sum += term;
        k++;
        term = term * x * x / ((2 * k - 1) * (2 * k));
    }

    return sum;
}

int main() {
    double x, eps;
    printf("x = ");
    scanf("%lf", &x);
    printf("eps = ");
    scanf("%lf", &eps);

    if (eps <= 0) {
        printf("eps must be positive\n");
        return EXIT_SUCCESS;
    }

    double res = task16_g(x, eps);
    printf("Calculated cosh(%lf) is %lf\n", x, res);
    printf("Standard cosh(%lf) is %lf\n", x, cosh(x));

    return EXIT_SUCCESS;
}