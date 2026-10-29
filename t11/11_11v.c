#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Passenger {
    char surname[50];
} Passenger;

typedef struct Baggage {
    int passenger_id;
    int count;
    double weight;
} Baggage;

bool write_passengers_file(const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        return false;
    }

    int n;
    printf("Enter number of passengers: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fclose(file);
        return false;
    }

    for (int i = 0; i < n; i++) {
        Passenger passenger;
        printf("Enter surname of passenger %d: ", i + 1);
        if (scanf("%49s", passenger.surname) != 1) {
            fclose(file);
            return false;
        }

        if (fwrite(&passenger, sizeof(Passenger), 1, file) != 1) {
            fclose(file);
            return false;
        }
    }

    fclose(file);
    return true;
}

bool write_baggage_file(const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        return false;
    }

    int n;
    printf("Enter number of baggage records: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fclose(file);
        return false;
    }

    for (int i = 0; i < n; i++) {
        Baggage baggage;

        printf("Enter passenger ID: ");
        if (scanf("%d", &baggage.passenger_id) != 1 ||
            baggage.passenger_id <= 0) {
            fclose(file);
            return false;
        }

        printf("Enter number of items: ");
        if (scanf("%d", &baggage.count) != 1 ||
            baggage.count < 0) {
            fclose(file);
            return false;
        }

        printf("Enter total weight: ");
        if (scanf("%lf", &baggage.weight) != 1 ||
            baggage.weight < 0) {
            fclose(file);
            return false;
        }

        if (fwrite(&baggage, sizeof(Baggage), 1, file) != 1) {
            fclose(file);
            return false;
        }
    }

    fclose(file);
    return true;
}

bool find_passenger(const char* filename, Baggage* result) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        return false;
    }

    Baggage baggage;
    bool found = false;

    while (fread(&baggage, sizeof(Baggage), 1, file) == 1) {
        if (!found ||
            baggage.count > result->count ||
            (baggage.count == result->count &&
             baggage.weight < result->weight)) {
            *result = baggage;
            found = true;
        }
    }

    fclose(file);
    return found;
}

bool print_passenger(const char* filename, int id) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL || id <= 0) {
        if (file != NULL) {
            fclose(file);
        }
        return false;
    }

    if (fseek(file, (long)(id - 1) * sizeof(Passenger), SEEK_SET) != 0) {
        fclose(file);
        return false;
    }

    Passenger passenger;
    if (fread(&passenger, sizeof(Passenger), 1, file) != 1) {
        fclose(file);
        return false;
    }

    printf("Passenger: %s\n", passenger.surname);
    fclose(file);
    return true;
}

int main() {
    const char* passengers_file = "passengers.bin";
    const char* baggage_file = "baggage.bin";

    if (!write_passengers_file(passengers_file)) {
        printf("Error writing passengers file.\n");
        return 1;
    }

    if (!write_baggage_file(baggage_file)) {
        printf("Error writing baggage file.\n");
        return 1;
    }

    Baggage result;

    if (find_passenger(baggage_file, &result)) {
        printf("Passenger ID: %d\n", result.passenger_id);
        if (!print_passenger(passengers_file, result.passenger_id)) {
            printf("Passenger not found.\n");
        }
        printf("Number of items: %d\n", result.count);
        printf("Total weight: %lf\n", result.weight);
    } else {
        printf("Baggage not found.\n");
    }

    return 0;
}
