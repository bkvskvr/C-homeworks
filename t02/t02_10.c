#include <stdio.h>
#include <math.h> 

const double PI = 3.14159265358979323846;

double calculate_angle(double a, double b, double c){
    return acos((b*b + c*c - a*a)/ (2*b*c));
}

double calculate_angle_degrees(double phi){
    return phi * (180.0 / PI);
}

int main() {

    double phi_test = calculate_angle(5, 3, 4);
    printf("Test angle in radians: %.2f\n", phi_test);
    printf("Test angle in degrees: %.2f\n", calculate_angle_degrees(phi_test));

    double phi_test2 = calculate_angle(1, 1, 1); 
    printf("Test angle in radians: %.2f\n", phi_test2);
    printf("Test angle in degrees: %.2f\n", calculate_angle_degrees(phi_test2));

    double a, b, c;
    printf("Enter the lengths of the three sides of the triangle (a b c): ");
    scanf("%lf %lf %lf", &a, &b, &c);
    
    double alpha, beta, gamma;
    double alpha_rad = calculate_angle(a, b, c);
    double beta_rad  = calculate_angle(b, a, c);
    double gamma_rad = calculate_angle(c, a, b);
    
    alpha = calculate_angle_degrees(alpha_rad);
    beta  = calculate_angle_degrees(beta_rad);
    gamma = calculate_angle_degrees(gamma_rad);
    
    printf("The angles of the triangle are: %.2f, %.2f, %.2f radians\n", alpha_rad, beta_rad, gamma_rad);
    printf("The angles of the triangle are: %.2f, %.2f, %.2f degrees\n", alpha, beta, gamma);
    
    return 0;
}