#include <stdio.h> 
#include <math.h>

int main() {
    double x, y;
    printf("Enter real number x: ");
    scanf("%lf", &x);

    y = cosh(x);
    printf("Cosh: %lf\n", y);
}