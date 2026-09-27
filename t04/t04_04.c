#include <stdio.h>

int main() {
    int n;
    double x;
    double sum = 0.0;
    double current_term = 1.0;

    printf("Введіть значення x: ");
    scanf("%lf", &x);
    
    printf("Введіть натуральне число n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        current_term *= x / i; 
        sum += current_term;
    }

    printf("Результат обчислення виразу: %lf\n", sum);

    return 0;
}