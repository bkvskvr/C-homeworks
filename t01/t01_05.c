#include <stdio.h>

int main() {
    int x;
    printf("Enter real number x: ");
    scanf("%d", &x);

    int y = x * x;
    int res = y * x;
    res *= res;

    printf("Value: %d\n", res);
}