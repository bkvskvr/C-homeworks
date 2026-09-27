#include <stdio.h>

double calc_7(double x, unsigned n) {
    double sum = 1.0;
    double term = 1.0;
    for (unsigned i = 1; i <= n; i++) {
        term *= x / i; // Отримуємо наступний член ряду, множачи попередній на (x / i)
        sum += term;
    }
    return sum;
}

int main() {
    double x;
    unsigned n;
    printf("Введіть x (|x| < 1): ");
    scanf("%lf", &x);
    printf("Введіть n: ");
    scanf("%u", &n);
    
    printf("Результат 7: %lf\n", calc_7(x, n));
    return 0;
}