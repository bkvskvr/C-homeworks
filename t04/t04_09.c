#include <stdio.h>

int main() {
    unsigned long long n;
    unsigned long long power_k = 1;
    int k = 0;

    printf("Enter a value for n: ");
    scanf("%llu", &n);

    while (power_k <= n) {
        power_k *= 2;
        k++;
    }

    printf("Найменше число 2^k > n: 2^%d = %llu\n", k, power_k);

    return 0;
}