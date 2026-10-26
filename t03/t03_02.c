#include <stdio.h>
#include <stdint.h> // for fixed-width integer types like uint8_t, uint16_t, int32_t etc.

void print_permutations(short n) {
    short hundreds = n / 100;
    short tens = (n / 10) % 10;
    short units = n % 10;

    if (hundreds == tens || hundreds == units || tens == units){
        return; // exit the function if any digits are repeated
    }

    printf("%hu%hu%hu\n", hundreds, tens, units);
    printf("%hu%hu%hu\n", hundreds, units, tens);
    printf("%hu%hu%hu\n", tens, hundreds, units);
    printf("%hu%hu%hu\n", tens, units, hundreds);
    printf("%hu%hu%hu\n", units, hundreds, tens);
    printf("%hu%hu%hu\n", units, tens, hundreds);
}

int main() {
    //int n; // integer type
    short unsigned n; // unsigned integer (natural number)

    printf("Enter 3-digit number: ");
    scanf("%hu", &n);

    if(n < 100 || n > 999) {
        printf("Error: Number is not a 3-digit number.\n");
        return 1;
    }
    
    print_permutations(n);
    printf("Size of n: %zu bytes\n", sizeof(n));
}