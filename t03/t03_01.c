#include <stdio.h> 
#include <stdint.h>

int digits_sum(short unsigned n) {
    short unsigned hundreds = n / 100;
    short unsigned tens = (n / 10) % 10;
    short unsigned units = n % 10;
    return hundreds + tens + units;
}

int inverse_number(short unsigned n) {
    short unsigned hundreds = n / 100;
    short unsigned tens = (n / 10) % 10;
    short unsigned units = n % 10;
    return units * 100 + tens * 10 + hundreds;
}

int main() {
    short unsigned n;

    printf("Enter 3-digit number: ");
    scanf("%hu", &n);

    if(n < 100 || n > 999) {
        printf("Error: Number is not a 3-digit number.\n");
        return 1;
    }

    short unsigned hundreds = n / 100;
    short unsigned tens = (n / 10) % 10;
    short unsigned units = n % 10;

    printf("Hundreds: %hu\n", hundreds);
    printf("Tens: %hu\n", tens);
    printf("Units: %hu\n", units);
    printf("Sum of digits: %d\n", digits_sum(n));
    printf("Inverse number: %d\n", inverse_number(n));

    printf("Size of n: %zu bytes\n", sizeof(n));
}