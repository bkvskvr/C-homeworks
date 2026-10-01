#include <stdio.h>

int main(){
    
    int a;
    int k=0;
    int sum = 0;
    double harm_sum = 0;
    
    do{
        printf("Enter a number (0 to exit): ");
        printf("a[%d] = ", k);
        scanf("%d", &a);
        
        sum += a;
        if (a != 0) {
            harm_sum += 1.0 / a;
            k++;
        }
        
    }while (a != 0);
    
    printf("Average of entered numbers: %f\n", k != 0 ? (double)sum / k : 0);
    if (k != 0) {
        printf("Harmonic mean of entered numbers: %f\n", harm_sum / k);
    }
    
}