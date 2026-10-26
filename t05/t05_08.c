#include <stdio.h>
#include <math.h>

double taylor_exp(double x, double eps) {
    double term = 1.0, sum = term;
    int k = 1;
    while (fabs(term) > eps / 2) {
        term *= (x / k);
        k++;
        sum += term;
    }
    return sum;
}

double gauss_phi(double x, double eps) {
    double term = x, sum = term;
    int k = 1;
    
    while (fabs(term) > eps / 2) {
        term *= (-x * x * (2.0 * k - 1.0)) / (k * (2.0 * k + 1.0));
        k++;
        sum += term;
    }
    return sum;
}

void task8() {
    double x, eps, y;
    
    printf("x = ");
    scanf("%lf", &x);

    do {
        printf("eps = ");
        scanf("%lf", &eps);
    } while (eps <= 0);

    y = taylor_exp(x, eps);
    printf("y = %lf %lf\n", y, exp(x));
    if (fabs(y - exp(x)) > eps) {
        printf("something wrong\n");
    }

    y = gauss_phi(x, eps);
    printf("Phi = %lf\n", y);
}

int main() {
    task8();
    return 0;
}