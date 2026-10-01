#include <stdio.h>
#include <math.h>

double calc_6a(unsigned n) {
    double result = 0;
    for (unsigned i = 0; i < n; i++) {
        result = sqrt(2 + result);
    }
    return result;
}

double calc_6b(unsigned n) {
    double result = 0;
    for (unsigned i = n; i >= 1; i--) {
        result = sqrt(3 * i + result);
    }
    return result;
}

int main() {
    unsigned n;
    printf("Введіть n: ");
    scanf("%u", &n);
    
    printf("Результат 6a: %lf\n", calc_6a(n));
    printf("Результат 6б: %lf\n", calc_6b(n));
    
    return 0;
}