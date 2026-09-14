#include <stdio.h>
#include <math.h>

int main() {
    long double m1,m2,r,F;
    printf("Enter masses m1 and m2, and distance r: ");
    scanf("%Lf %Lf %Lf", &m1, &m2, &r);
    const long double G = 6.67430e-11L; /* gravitational constant */
    F = G * m1 * m2 / r / r;
    printf("Gravitational force F = %.9Lf or %Le\n", F, F);
}