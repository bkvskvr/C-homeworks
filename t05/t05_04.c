#include <stdio.h>

double task4(int n) {
    double fact_inv = 1.0, p = 1.0;

    for (int i = 1; i <= n; i++){
        fact_inv /= i;
        p *= (1 + fact_inv);
    }
    return p;
}