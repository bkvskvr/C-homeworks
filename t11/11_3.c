#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool is_square(int x) {
    if (x < 0) return false;
    int k = (int)sqrt((double)x);
    return (long long)k * k == x || (long long)(k + 1) * (k + 1) == x;
}

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; (long long)i * i <= x; ++i)
        if (x % i == 0) return false;
    return true;
}

bool is_cube(int x) {
    long long k = llround(cbrt((double)x));
    return k * k * k == x;
}

bool is_palindrome(int x) {
    if (x < 0) return false;
    int initial = x;
    long long reversed = 0;
    while (x > 0) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    return reversed == initial;
}

bool is_fibonacci(int x) {
    if (x < 0) return false;
    long long a = 0, b = 1;
    while (a < x) {
        long long c = a + b;
        a = b;
        b = c;
    }
    return a == x;
}

bool matches(int x, char option) {
    switch (option) {
        case 'a': return x % 2 == 0;
        case 'b': return is_cube(x);
        case 'c': return is_square(x);
        case 'd': {
            if (!is_square(x)) return false;
            int root = (int)sqrt((double)x);
            return is_prime(root);
        }
        case 'e': return is_palindrome(x);
        case 'f': return is_fibonacci(x);
        default: return false;
    }
}

int main(void) {
    FILE *f = fopen("F.bin", "wb");
    if (f == NULL) return 1;
    puts("Enter integers (0 ends input):");
    int x;
    while (scanf("%d", &x) == 1 && x != 0) {
        if (fwrite(&x, sizeof(x), 1, f) != 1) {
            fclose(f);
            return 1;
        }
    }
    fclose(f);

    puts("a - even; b - cubes; c - squares; d - exactly 3 divisors;");
    puts("e - palindromes; f - Fibonacci numbers");
    char option;
    if (scanf(" %c", &option) != 1 || option < 'a' || option > 'f') return 1;
    f = fopen("F.bin", "rb");
    FILE *g = fopen("G.bin", "wb");
    if (f == NULL || g == NULL) {
        if (f != NULL) fclose(f);
        if (g != NULL) fclose(g);
        return 1;
    }
    printf("G: ");
    while (fread(&x, sizeof(x), 1, f) == 1) {
        if (matches(x, option)) {
            if (fwrite(&x, sizeof(x), 1, g) != 1) {
                fclose(f);
                fclose(g);
                return 1;
            }
            printf("%d ", x);
        }
    }
    printf("\n");
    fclose(f);
    fclose(g);
    return 0;
}
