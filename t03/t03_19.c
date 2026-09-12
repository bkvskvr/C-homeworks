#include <stdio.h>
#include <stdlib.h>


// a)
int is_odd(unsigned int n) {
    return n % 2 != 0;
}

// b)
int ends_with_five(int n) {
    return abs(n) % 10 == 5;
}

// c)
int is_multiple(int n, unsigned int m) {
    return n % m == 0;
}

// d)
int are_both_multiples(unsigned int n, unsigned int k, unsigned int m) {
    return (n % m == 0) && (k % m == 0);
}

int main() {
    unsigned int n_a = 7;
    int n_b = -15;
    int n_c = 24;
    unsigned int m_c = 4;
    unsigned int n_d = 12, k_d = 18, m_d = 6;

    printf("%d\n", is_odd(n_a));
    printf("%d\n", ends_with_five(n_b));
    printf("%d\n", is_multiple(n_c, m_c));
    printf("%d\n", are_both_multiples(n_d, k_d, m_d));

    return 0;
}