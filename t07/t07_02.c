#include <stdio.h>
#define ARRAY_SIZE 4

void print_arrayinreverse(int arr[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        if (i>0) {
            printf("%d, ", arr[i]);
        }else printf("%d", arr[i]);
    }
}
int main() {
    int array[ARRAY_SIZE] = {5, 112, 4, 3};
    print_arrayinreverse(array, ARRAY_SIZE);
}