#include <stdio.h>
#include <math.h> 

double square(double x){
    return x * x;
}

double Rosenbrock2d(double x, double y){
    return 100 * square(y - square(x)) + square(1 - x);
}

int main(){

    printf("Testing Rosenbrock2d function with some sample inputs:\n");
    printf("Rosenbrock2d(1, 1) = %g %g\n", Rosenbrock2d(1, 1), 0);
    printf("Rosenbrock2d(0, 0) = %g %g\n", Rosenbrock2d(0, 0), 1);
    printf("Rosenbrock2d(-1, 1) = %g %g\n", Rosenbrock2d(-1, 1), 4);
    printf("Rosenbrock2d(2, 3) = %g %g\n", Rosenbrock2d(2, 3), 101);
    
    
    double x, y;
    printf("Enter x and y: ");
    scanf("%lf %lf", &x, &y);
    printf("Rosenbrock2d(%g, %g) = %g\n", x, y, Rosenbrock2d(x, y));
    
    return 0;
}