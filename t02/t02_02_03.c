#include <stdio.h> 
#include <math.h>

double square(double x) {
    return x * x;
}

double hypotenuse_square(double a, double b) {
    return square(a) + square(b);
}

double hypotenuse(double a, double b) {
    return sqrt(hypotenuse_square(a, b));
}

double area_rect_triangle(double a, double b) {
    return 0.5 * a * b;
}

double area_heron(double a, double b, double c) {
    double s = 0.5 * (a + b + c);
    return sqrt(s* (s - a) * (s - b) * (s- c));
}

int main() {
    double a, b, c;

    printf("Enter 2 sides: ");
    scanf("%lf %lf", &a, &b);

    c = hypotenuse(a, b);
    printf("The hypotenuse is: %g %g\n", c, hypot(a, b));

    printf("The area of the right triangle is: %g\n", area_rect_triangle(a, b));
    
    printf("The area of the riangle using Heron's formula is: %g\n", area_heron(a, b, c));

}