#include <stdio.h>
#include <math.h> 

double square(double x){
    return x*x;
}

double length(double x1, double y1, double x2, double y2) {
    return hypot(x2-x1, y2-y1);
}

double area_heron(double a, double b, double c){
    double s = 0.5 * (a+b+c);
    return sqrt(s * (s - a) * (s - b) * (s - c));
}


double area_triangle(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a = length(x1, y1, x2, y2);
    double b = length(x2, y2, x3, y3);
    double c = length(x3, y3, x1, y1);
    return area_heron(a, b, c);
}

int main() {
    
    printf("Length between (0,0) and (3,4): %g\n", length(0, 0, 3, 4));
    printf("Length between (1,1) and (4,5): %g\n", length(1, 1, 4, 5));
    
    printf("Area of triangle with vertices (0,0), (3,0), (0,4): %g\n", area_triangle(0, 0, 3, 0, 0, 4));
    printf("Area of triangle with vertices (1,1), (4,1), (1,5): %g\n", area_triangle(1, 1, 4, 1, 1, 5));
    
    double x1, y1, x2, y2, x3, y3;
    printf("Enter the coordinates of the triangle's vertices (x1 y1 x2 y2 x3 y3): ");
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    printf("Area of the triangle: %g\n", area_triangle(x1, y1, x2, y2, x3, y3));
    
    return 0;
}