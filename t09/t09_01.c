#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if(n <= 0){
        return 1;
    }

    double* arr = (double*)malloc(n * sizeof(double));
    if(arr == NULL){
        return 1;
    }

    for(int i = 0; i < n; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%lf", &arr[i]);
    }

    double sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i] * arr[i];
    }

    printf("The sum of squares is: %lf\n", sum);

    free(arr);

    return 0;
}
