#include <stdio.h>
#include <stdlib.h>

int input_array_int(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("arr[%d]= ", i + 1);
        int result_input = scanf("%d", &array[i]);
        if (result_input != 1) {
            printf("Invalid input\n");
            return i;
        }
    }
    return size;
}

void task12() {
    int size;
    printf("Enter the size of the array: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Error: Invalid dimension\n");
        return;
    }

    int array[size];

    int d1 = input_array_int(array, size);
    if (d1 != size) {
        printf("Error: Array input mismatch\n");
        return;
    }

    int max_count = 0;

    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (array[j] == array[i]) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
        }
    }

    printf("Mode(s) (appears %d times): ", max_count);
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (array[j] == array[i]) {
                count++;
            }
        }
        
        if (count == max_count) {
            int is_duplicate = 0;
            for (int k = 0; k < i; k++) {
                if (array[k] == array[i]) {
                    is_duplicate = 1;
                    break;
                }
            }
            if (!is_duplicate) {
                printf("%d ", array[i]);
            }
        }
    }
    printf("\n");
}

int main() {
    task12();
    return 0;
}