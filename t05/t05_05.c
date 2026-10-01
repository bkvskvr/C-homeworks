#include <stdio.h>
#include <stdlib.h>

int task5() {
    int x1, x2, x3, x, k = 4;
    x1 = x2 = x3 = -99;
    x = x1 + x3 + 100;
    while (x <= 0) {
        x = x1 + x3 + 100;
        x1 = x2;
        x2 = x3;
        x3 = x;
        k++;
    }
    printf("the first x greater 0 is ");
    printf("x = %d with index %d", x, k);

    return EXIT_SUCCESS;
}

int main() {
    task5();
}