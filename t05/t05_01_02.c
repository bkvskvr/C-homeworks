#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>

int n;

int task1_a(double a){
    int k = 1;
    double sum = 0.0;
    while (sum < a){
        sum += 1.0 / k;
        k++;
    }
    return k;

}

int main() {
    double a;
    printf("a = ");
    scanf_s("%lf", &a);
    int n = task1_a(a);
    printf("First n,"
        "that makes harmonic row greater than"
        "%lf is %d", a, n);

    return EXIT_SUCCESS;
}

unsigned long long fibonacci(int n){
    unsigned long long f0, f1, f;
    f0 = 1UL;
    f1 = 1UL;
    // 1, 1, 2, 3, 5, 8, 13, ...
    // F0 F1 F
    //    F0 F1 F
    for (int k = 2; k <= n; k++) {
        f = f0 + f1;
        f0 = f1; f1 = f;
    }
    return f;
}

int main2() {
    int n;
    printf("n = ");
    if (scanf("%d", &n) != 1) {
        printf("Incorrect input");
        return -1;
    }
    unsigned long long f = fibonacci(n);
    printf("F(%d)=%llu\n", n, f);
}