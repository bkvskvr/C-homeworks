#include <stdio.h>
#include <math.h>

const double MY_PI = 3.14159265358979323846;

double ellipse_area(double a, double b) {
    return MY_PI * a * b;
}

int main() {
    printf("Test area (a=3, b=4): %g\n", ellipse_area(3, 4));

    double a, b;
    printf("\nEnter radiuses a and b: ");
    scanf("%lf %lf", &a, &b);

    printf("Area of ellipse = %g\n", ellipse_area(a, b));

    return 0;
}