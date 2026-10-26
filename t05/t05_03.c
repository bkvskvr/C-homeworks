#include <stdio.h>

int get_steps(int n, int print_seq) {
    int steps = 0;
    long long a = n; 
    
    if (print_seq) {
        printf("%lld", a);
    }
    
    while (a != 1) {
        if (a % 2 == 0) {
            a = a / 2;
        } else {
            a = 3 * a + 1;
        }
        steps++;
        
        if (print_seq) {
            printf(" -> %lld", a);
        }
    }
    
    if (print_seq) {
        printf("\n");
    }
    
    return steps;
}

int main() {
    int n;
    
    printf("Enter a natural number n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }
    
    printf("Sequence for %d:\n", n);
    int steps_for_n = get_steps(n, 1);
    printf("Total steps to reach 1: %d\n\n", steps_for_n);
    
    int max_steps = 0;
    int max_n = 1;
    
    for (int i = 1; i < 1000; i++) {
        int current_steps = get_steps(i, 0);
        
        if (current_steps > max_steps) {
            max_steps = current_steps;
            max_n = i;
        }
    }
    
    printf("Check for all n < 1000 completed.\n");
    printf("Maximum steps: %d (achieved by starting number %d)\n", max_steps, max_n);
    
    return 0;
}