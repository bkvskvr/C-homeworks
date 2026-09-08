#include <stdio.h> 
#include <math.h>

int main() {
    float x = 0.0001f;
    double x1 = 24.33E5;
    long double x2 = 1e-4L;

    printf("%g\n", x);
    printf("%lf\n", x1);
    printf("%Lg\n", x2);

    double pi = M_PI;
    printf("%lf\n", pi);
    double Le = M_E;
    printf("%lf\n", Le);
    long double Le1 = exp(1.0L);
    printf("%Lf\n", Le1);

    double sqrt5 = sqrt(5);
    printf("%lf\n", sqrt5);
    double ln = log(100);
    printf("%lf\n", ln);

    return 0;
}
