#include <stdio.h>
#include <math.h>

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

int min_abs(int a, int b, int c) {
    int d = min(abs(a), abs(b));
    return min(d, abs(c));
}

int max_abs(int a, int b, int c) {
    int d = abs(b);
    if(abs(a) > d){
        d = abs(a);
    }

    return max(d, abs(c));
}

int main(){
    int a,b,c;
    printf("Enter three integers: ");
    scanf("%d %d %d", &a, &b, &c);

    printf("Minimum: %d\n", min(a, b));
    printf("Maximum: %d\n", max(a, b));
    printf("Minimum absolute value: %d\n", min_abs(a, b, c));
    printf("Maximum absolute value: %d\n", max_abs(a, b, c));
}