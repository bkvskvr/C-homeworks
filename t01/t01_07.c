#include <stdio.h> 
#include <math.h>

int main() {

    double x;

    printf("Enter real number x: ");
    scanf("%lf", &x);

    int x_int = (int) x;
    printf("Integer part: %d", x_int);

    double fractional_part = x - x_int;
    printf("\nFractional part: %lf", fabs(fractional_part));

    int x_floor = floor(x);
    printf("\nFloor value: %d", x_floor);

    int x_ceil = ceil(x);
    printf("\nCeil value: %d", x_ceil);

    int x_round = round(x);
    printf("\nRound value: %d", x_round);
}