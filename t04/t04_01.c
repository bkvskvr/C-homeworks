#include <stdio.h>
#include <math.h>

double rec_sinus(double x, unsigned n){
    double y = x;
    for(unsigned i = 1; i <= n; i++){
        y = sin(y);
    }
    return y;
}

int main(){
    double x;
    printf("Enter a float number: ");
    scanf("%lf", &x);
    unsigned n;
    printf("Enter an unsigned number: ");
    scanf("%u", &n);
    
    printf("rec_sinus(1.54, 2) = %lf %lf\n", rec_sinus(1.54, 2), sin(sin(1.54)));
    
    double result = rec_sinus(x, n);
    printf("Result: %lf\n", result);
}