#include <stdio.h> 

int main() {
    double x;

    printf("Enter the value of x: ");
    scanf("%lf", &x);

    double x2 = x * x;
    double y = (x2 + 1) * (x2 + x) + 1;

    printf("Polynomial value y: %lf\n", y);
    return 0;
}
