#include <stdio.h>
#define ARRAY_SIZE 10

int input_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        int rez_input = scanf("%d", &arr[i]);
        if (rez_input != 1) {
            printf("Wrong input. Please try again.\n");
            return i;
        }
    }
    return n;
}
void print_array(const int arr[], int n) {
    printf("The array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int max_array(const int arr[], int n) {
    if (n<=0 || arr == NULL) {
        printf("The array is empty.\n");
        return -1;

    }
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr[ARRAY_SIZE];
    int n = input_array(arr, ARRAY_SIZE);
    if (n>0) {
        print_array(arr, n);
        int max = max_array(arr, n);
        if (max != -1) {
            printf("The max element is: %d\n", max);
        }
    }
    return 0;
}