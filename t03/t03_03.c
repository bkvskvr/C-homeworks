#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(){

    int64_t x, y, z;
    printf("Enter three integers: ");
    int r = scanf("%" SCNd64 ",%" SCNd64 ",%" SCNd64, &x, &y, &z);
    
    if (r != 3){
        printf("Invalid input. \n");
        return 1;
    }
    printf("You entered: %" PRId64 ", %" PRId64 ", %" PRId64 "\n", x, y, z);

    int64_t dob = (int64_t) x * y * z;

    printf("Product of the three integers: %" PRId64 "\n", dob);
}