#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct TPair {
    unsigned key;
    char data[10];
} TPair;

bool write_pairs_file(const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        return false;
    }

    int n;
    printf("Enter number of records: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        fclose(file);
        return false;
    }

    for (int i = 0; i < n; i++) {
        TPair pair;
        printf("Enter key and data: ");
        if (scanf("%u %9s", &pair.key, pair.data) != 2) {
            fclose(file);
            return false;
        }
        if (fwrite(&pair, sizeof(TPair), 1, file) != 1) {
            fclose(file);
            return false;
        }
    }

    fclose(file);
    return true;
}

void print_pairs_file(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        return;
    }

    TPair pair;
    while (fread(&pair, sizeof(TPair), 1, file) == 1) {
        printf("%u %s\n", pair.key, pair.data);
    }

    fclose(file);
}

bool find_pair(const char* filename, unsigned key, TPair* result) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        return false;
    }

    fseek(file, 0, SEEK_END);
    long n = ftell(file) / sizeof(TPair);
    long left = 0;
    long right = n - 1;

    while (left <= right) {
        long mid = left + (right - left) / 2;
        TPair pair;

        fseek(file, mid * sizeof(TPair), SEEK_SET);
        if (fread(&pair, sizeof(TPair), 1, file) != 1) {
            fclose(file);
            return false;
        }

        if (pair.key == key) {
            *result = pair;
            fclose(file);
            return true;
        }

        if (pair.key < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    fclose(file);
    return false;
}

bool remove_pair(const char* filename, unsigned key) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        return false;
    }

    FILE* temp = tmpfile();
    if (temp == NULL) {
        fclose(file);
        return false;
    }

    TPair pair;
    bool found = false;

    while (fread(&pair, sizeof(TPair), 1, file) == 1) {
        if (pair.key == key) {
            found = true;
        } else {
            fwrite(&pair, sizeof(TPair), 1, temp);
        }
    }

    fclose(file);

    if (!found) {
        fclose(temp);
        return false;
    }

    file = fopen(filename, "wb");
    if (file == NULL) {
        fclose(temp);
        return false;
    }

    rewind(temp);
    while (fread(&pair, sizeof(TPair), 1, temp) == 1) {
        fwrite(&pair, sizeof(TPair), 1, file);
    }

    fclose(file);
    fclose(temp);
    return true;
}

int main() {
    const char* filename = "pairs.bin";

    if (!write_pairs_file(filename)) {
        printf("Error writing file.\n");
        return 1;
    }

    printf("Records:\n");
    print_pairs_file(filename);

    unsigned key;
    printf("Enter key to find: ");
    if (scanf("%u", &key) != 1) {
        return 1;
    }

    TPair result;
    if (find_pair(filename, key, &result)) {
        printf("Found: %u %s\n", result.key, result.data);
    } else {
        printf("Record not found.\n");
    }

    printf("Enter key to remove: ");
    if (scanf("%u", &key) != 1) {
        return 1;
    }

    if (remove_pair(filename, key)) {
        printf("Record removed successfully.\n");
    } else {
        printf("Record not found.\n");
    }

    printf("Records after removing:\n");
    print_pairs_file(filename);

    return 0;
}
