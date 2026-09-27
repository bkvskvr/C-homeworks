#include <stdio.h>
#include <math.h>

double calc_polynomial(double x, int n) {
    double sum = 0.0;
    for (int i = 0; i <= n; i++) {
        sum += pow(x, i);
    }
    return sum;
}

int main() {
    double x = 2.0;
    int n = 3;
    
    printf("%lf\n", calc_polynomial(x, n));
    
    return 0;
}