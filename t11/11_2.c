#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

size_t input_arrayelements(double* array, size_t max_size) {
    size_t count;
    printf("Enter the number of elements (max %zu): ", max_size);
    if (scanf("%zu", &count) != 1 || count > max_size) {
        return 0;
    }

    for (size_t i = 0; i < count; i++) {
        printf("Enter element %zu: ", i + 1);
        if (scanf("%lf", &array[i]) != 1) {
            return 0;
        }
    }
    return count;
}

void write_arrayelements(const double* array, size_t count) {
    for (size_t i = 0; i < count; i++) {
        printf("a[%zu]: %g\n", i + 1, array[i]);
    }
}

size_t write_arrayelements_to_binaryfile(const double* array, size_t count, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        return 0;
    }

    size_t written = fwrite(array, sizeof(array[0]), count, file);
    fclose(file);
    return written;
}

size_t read_arrayelements_from_binaryfile(double* array, size_t max_size, const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        return 0;
    }

    size_t count = 0;
    while (count < max_size && !feof(file)) {
        size_t read = fread(&array[count], sizeof(array[0]), 1, file);
        if (read != 1) {
            break;
        }
        if (count == 0) {
            printf("%g", array[count]);
        } else {
            printf(", %g", array[count]);
        }
        count++;
    }
    fclose(file);
    return count;
}

int main() {
    const size_t max_size = 100;
    double array[max_size];
    size_t count = input_arrayelements(array, max_size);
    if (count == 0) {
        printf("Error reading array elements.\n");
        return 1;
    }

    write_arrayelements(array, count);
    write_arrayelements_to_binaryfile(array, count, "output.bin");
    read_arrayelements_from_binaryfile(array, max_size, "output.bin");

    return 0;
}
