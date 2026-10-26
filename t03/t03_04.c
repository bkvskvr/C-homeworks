#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int16_t mult(int8_t a, int8_t b){
    return (int16_t)(a * b);
}

int main(){
    uint64_t x, y, z;
    printf("Enter three integers: ");
    scanf("%" SCNu64 " %" SCNu64 " %" SCNu64, &x, &y, &z);

    printf("You entered: %" PRIu64 ", %" PRIu64 ", %" PRIu64 "\n", x, y, z);

    uint64_t d = x * y * z;
    printf("Product: %" PRIu64 "\n", d);

    uint8_t a8, b8;
    printf("Enter two 8-bit integers: ");
    scanf("%" SCNu8 " %" SCNu8, &a8, &b8);
    
    printf("You entered: %" PRIu8 ", %" PRIu8 "\n", a8, b8);
    
    int16_t result = mult((int8_t)a8, (int8_t)b8);
    printf("Product: %" PRId16 "\n", result);
    
    return 0;
}