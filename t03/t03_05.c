#include <stdio.h>

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    else {
        return b;
    }
}

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int main(){
    int a,b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    printf("Minimum: %d\n", min(a, b));
    printf("Maximum: %d\n", max(a, b));
}