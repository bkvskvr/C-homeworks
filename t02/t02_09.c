#include <stdio.h>
#include <math.h>

const double MY_PI = 3.141592653589793;

double to_radians(double deg) {
    return deg * (MY_PI / 180.0);
}

double area_by_angles_and_r(double alpha, double beta, double gamma, double r) {
    double rad_a = to_radians(alpha);
    double rad_b = to_radians(beta);
    double rad_c = to_radians(gamma);

    double ctg_a = 1.0 / tan(rad_a / 2.0);
    double ctg_b = 1.0 / tan(rad_b / 2.0);
    double ctg_c = 1.0 / tan(rad_c / 2.0);

    return r * r * (ctg_a + ctg_b + ctg_c);
}

int main() {
    printf("Test area (60, 60, 60 deg, r=1): %g\n", area_by_angles_and_r(60, 60, 60, 1));

    double alpha, beta, gamma, r;

    printf("\nEnter three angles in degrees (alpha beta gamma): ");
    scanf("%lf %lf %lf", &alpha, &beta, &gamma);

    printf("Enter radius of inscribed circle (r): ");
    scanf("%lf", &r);

    double S = area_by_angles_and_r(alpha, beta, gamma, r);
    printf("Area of the triangle S = %g\n", S);

    return 0;
}