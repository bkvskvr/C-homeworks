#include <stdio.h>

int main() {
    double C, F;
    printf("Enter temperature: ");
    scanf("%lf", &C);
    F = (9 * C / 5.0) + 32;
    printf("F=%.2lf\n", F);
    return 0;
}
