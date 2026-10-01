#include <stdio.h>

void print_fact(unsigned n){
    printf("%u! =", n);
    for(unsigned i = 1; i < n; i++){
        printf("%u*", i);
    }
    printf("%u\n", n);
}

void print_fact_inv(unsigned n){
    printf("%u! =", n);
    for(unsigned i = n; i > 1; i--){
        printf("%u*", i);
    }
    printf("1\n");
}

int main(){
    unsigned n;
    printf("Enter an unsigned number: ");
    scanf("%u", &n);
    print_fact(n);
    print_fact_inv(n);
}