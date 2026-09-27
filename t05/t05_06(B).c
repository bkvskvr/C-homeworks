#include <stdio.h>

double calculate_fraction(int n) {
    double res = 2.0;

    for (int i = 2 * n - 1; i >= 1; i--) {
        if (i % 2 == 1) {
            res = 1.0 + 1.0 / res;
        } else {
            res = 2.0 + 1.0 / res;
        }
    }

    return res;
}

int main() {
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Wrong input.\n");
        return -1;
    }

    double x = calculate_fraction(n);
    printf("x_%d = %.10lf\n", 2 * n, x);

    return 0;
}