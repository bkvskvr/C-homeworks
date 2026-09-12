#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_zero(double x){
    return fabs(x) < 1e-9;
}

int solve_quadratic(double a, double b, double c){
    if (is_zero(a)) {
        if (is_zero(b)) {
            if(is_zero(c)){
                printf("Infinite solutions\n");
                return -1;
            }
            printf("No solution\n");
            return 0;
        }
        double root = -c / b;
        printf("x1= %lf\n", root);
        return 1;
    }
    
    double discriminant = b * b - 4 * a * c;
    if (is_zero(discriminant)) {
        double root = -b / (2 * a);
        printf("x1= %lf\n", root);
        return 1;
    } else if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("x1= %lf\n", root1);
        printf("x2= %lf\n", root2);
        return 2;
    } else {
        printf("No real roots\n");
        return 0;
    }
}

int main(){

    printf("Number of roots: %d\n", solve_quadratic(1,-3,2));
    printf("Number of roots: %d\n", solve_quadratic(2,-4,2));
    printf("Number of roots: %d\n", solve_quadratic(1,2,5));
    printf("Number of roots: %d\n", solve_quadratic(0,-3,2));
    printf("Number of roots: %d\n", solve_quadratic(0,0,2));
    printf("Number of roots: %d\n", solve_quadratic(0,0,0));

    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    int result = solve_quadratic(a, b, c);
    printf("%d\n", result);
}