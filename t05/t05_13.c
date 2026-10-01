#include <stdio.h>
#include <stdlib.h>

double task13_a(int n) {
    if (n < 0) return 0.0;

    double* a = (double*)malloc((n + 3) * sizeof(double));
    a[0] = 1.0;
    a[1] = 1.0;
    a[2] = 3.0;

    double p2 = 4.0; 
    for (int k = 3; k <= n; k++) {
        a[k] = a[k - 3] + a[k - 2] / p2;
        p2 *= 2.0;
    }

    double product = 1.0;
    double p3 = 1.0; 
    for (int k = 0; k <= n; k++) {
        product *= (a[k] / p3);
        p3 *= 3.0;
    }

    free(a);
    return product;
}

int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);

    double res = task13_a(n);
    printf("Result P_%d is %lf\n", n, res);

    return EXIT_SUCCESS;
}