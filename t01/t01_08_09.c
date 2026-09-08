#include <stdio.h> 
#include <math.h>

double avg(double a, double b) {
    return (a + b) / 2.0;
}

double harmonic(double a, double b) {
    return 2.0/ ((1.0 / a) + (1.0 / b));
}

int main() {
    double x,y;
    printf("Enter real numbers x, y: ");
    scanf("%lf %lf", &x, &y);
    //scanf("%lf", &x);
    //scanf("%lf", &y);

    printf("difference: %lf\n", x-y);
    printf("multiplication: %lf\n", x*y);
    printf("average: %lf\n", avg(x, y));
    printf("harmonic: %lf\n", harmonic(x, y));
}

