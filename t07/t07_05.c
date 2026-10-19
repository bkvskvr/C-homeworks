#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

int input_natural_array_until_zero(int array[], int max_size){
    int count = 0;
    for(int i = 0; i < max_size; i++){
        printf("a[%d]= ", i + 1);
        int val;
        int result_input = scanf("%d", &val);
        if(result_input != 1){
            printf("Invalid input\n");
            return count;
        }
        if(val == 0){
            break;
        }
        if(val < 0){
            printf("Please enter a natural number (or 0 to stop)\n");
            i--;
            continue;
        }
        array[count++] = val;
    }
    return count;
}

void count_even_odd(int array[], int size, int *even_count, int *odd_count){
    *even_count = 0;
    *odd_count = 0;
    for(int i = 0; i < size; i++){
        if(array[i] % 2 == 0){
            (*even_count)++;
        } else {
            (*odd_count)++;
        }
    }
}

int main(){
    int array[MAX_SIZE];
    int size = input_natural_array_until_zero(array, MAX_SIZE);

    int even_count, odd_count;
    count_even_odd(array, size, &even_count, &odd_count);

    printf("Total elements: %d\n", size);
    printf("Even elements count: %d\n", even_count);
    printf("Odd elements count: %d\n", odd_count);

    return 0;
}
