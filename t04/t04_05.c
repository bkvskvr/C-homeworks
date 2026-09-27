#include <stdio.h>
#include <math.h>

unsigned long long dbl_factorial(unsigned char n){
    if (n == 0 || n == 1) return 1;
    unsigned long long result = 1ULL;
    for (unsigned char i = n; i > 1; i -= 2) {
        result *= i;
    }
    return result;
}

int main(){
    unsigned char n;
    printf("Enter a value for n: ");
    scanf("%hhu", &n);
    
    printf("dbl_factorial(%hhu) = %llu\n", n, dbl_factorial(n));
}