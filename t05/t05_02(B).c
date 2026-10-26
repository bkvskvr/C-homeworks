#include <stdio.h>

int fibonacci(int a) {
    unsigned long long f0, f1, f;
    f0 = 0UL;
    f1 = 1UL;

    if (f0 > a) return 0;
    if (f1 > a) return 1;

    for (int k = 2; ; k++) {
        f = f0 + f1;
        if (f > a) {
            return k-1;
        }
        f0 = f1;
        f1 = f;
    }
}

int main() {
    int a;
    printf("Enter a number a: ");
    if (scanf("%d", &a) != 1) {
        printf("Wrong input.");
        return -1;
    }

    int k = fibonacci(a);
    printf("Index = %d\n", k);

    return 0;
}