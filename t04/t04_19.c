#include <stdio.h>

int main() {
    int n;
    double p = 1.0;

    printf("Enter a value for n (n > 2): ");
    scanf("%d", &n);

    if (n <= 2) {
        printf("n must be greater than 2\n");
        return 1;
    }

    for (int k = 1; k <= n; k++) {
        p *= (1.0 + 1.0 / ((double)k * k));
    }

    printf("p = %.8lf\n", p);

    return 0;
}