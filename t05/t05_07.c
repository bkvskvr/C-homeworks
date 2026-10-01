#include <stdio.h>
#include <stdlib.h>

double task7(int n) {
    if (n <= 0) return 0.0;

    double a1 = 0.0;
    double b1 = 1.0;
    double pow2 = 2.0; 
    double sum = pow2 / (a1 + b1);

    if (n == 1) return sum;

    double a2 = 1.0;
    double b2 = 0.0;
    pow2 *= 2.0; 
    sum += pow2 / (a2 + b2);

    if (n == 2) return sum;

    double a_prev2 = a1; 
    double a_prev1 = a2; 
    double b_prev1 = b2; 

    for (int k = 3; k <= n; k++) {
        double b_curr = b_prev1 + a_prev1;
        double a_curr = a_prev1 / k + a_prev2 * b_curr;

        pow2 *= 2.0; 
        sum += pow2 / (a_curr + b_curr);

        a_prev2 = a_prev1;
        a_prev1 = a_curr;
        b_prev1 = b_curr;
    }

    return sum;
}

int main() {
    int n;
    
    printf("n = ");
    scanf("%d", &n);

    double res = task7(n);
    printf("S_%d = %lf\n", n, res);

    return EXIT_SUCCESS;
}