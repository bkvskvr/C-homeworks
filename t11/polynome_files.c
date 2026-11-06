#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "polynome_files.h"

void print_polynome(const Polynome* polynome) {
    if (!polynome) return;
    bool printed = false;
    for (int i = 0; i < polynome->count; i++) {
        Monome m = polynome->monomes[i];
        if (m.coefficient == 0) continue;
        if (printed && m.coefficient > 0) printf("+");
        printf("%gx^%d", m.coefficient, m.exponent);
        printed = true;
    }
    if (!printed) printf("0");
    printf("\n");
}

bool input_polynome(Polynome* polynome) {
    if (!polynome) return false;
    polynome->monomes = NULL;
    polynome->count = 0;
    int count;
    printf("Enter the number of monomes: ");
    if (scanf("%d", &count) != 1 || count < 0) return false;
    if (count == 0) return true;

    Monome* monomes = malloc((size_t)count * sizeof(Monome));
    if (!monomes) return false;

    for (int i = 0; i < count; i++) {
        printf("Enter coefficient and exponent for monome %d: ", i + 1);
        if (scanf("%lf %d", &monomes[i].coefficient, &monomes[i].exponent) != 2) {
            free(monomes);
            return false;
        }
    }
    polynome->monomes = monomes;
    polynome->count = count;
    return true;
}

Coefficient polynome_value(const Polynome* polynome, Coefficient x) {
    if (!polynome) return 0.0;
    Coefficient result = 0.0;
    for (int i = 0; i < polynome->count; i++) {
        Monome m = polynome->monomes[i];
        result += m.coefficient * pow(x, m.exponent);
    }
    return result;
}

void derivative(const Polynome* polynome, Polynome* result) {
    if (!result) return;
    result->count = 0;
    result->monomes = NULL;
    if (!polynome || polynome->count <= 0) return;

    result->monomes = malloc((size_t)polynome->count * sizeof(Monome));
    if (!result->monomes) return;

    for (int i = 0; i < polynome->count; i++) {
        Monome m = polynome->monomes[i];
        if (m.exponent == 0) continue;
        result->monomes[result->count].coefficient = m.coefficient * m.exponent;
        result->monomes[result->count].exponent = m.exponent - 1;
        result->count++;
    }
}

Polynome* read_polynome_file(const char* filename) {
    FILE* file = fopen(filename, "rt");
    if (!file) return NULL;

    Polynome* polynome = malloc(sizeof(Polynome));
    if (!polynome) {
        fclose(file);
        return NULL;
    }

    polynome->monomes = NULL;
    polynome->count = 0;
    int count;

    if (fscanf(file, "%d", &count) != 1 || count < 0) {
        fclose(file);
        free(polynome);
        return NULL;
    }

    if (count > 0) {
        polynome->monomes = malloc((size_t)count * sizeof(Monome));
        if (!polynome->monomes) {
            fclose(file);
            free(polynome);
            return NULL;
        }
    }

    for (int i = 0; i < count; i++) {
        if (fscanf(file, "%lf %d", &polynome->monomes[i].coefficient,
                   &polynome->monomes[i].exponent) != 2) {
            fclose(file);
            free_polynome(polynome);
            return NULL;
        }
    }

    polynome->count = count;
    fclose(file);
    return polynome;
}

Polynome* write_polynome_file(const char* filename, const Polynome* polynome) {
    if (!polynome) return NULL;
    FILE* file = fopen(filename, "wt");
    if (!file) return NULL;

    if (fprintf(file, "%d\n", polynome->count) < 0) {
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < polynome->count; i++) {
        Monome m = polynome->monomes[i];
        if (fprintf(file, "%.17g %d\n", m.coefficient, m.exponent) < 0) {
            fclose(file);
            return NULL;
        }
    }

    if (fclose(file) != 0) return NULL;
    return (Polynome*)polynome;
}

Polynome* find_polynome_file(const char* filename, const Polynome* polynome) {
    if (!polynome) return NULL;
    Polynome* stored = read_polynome_file(filename);
    if (!stored) return NULL;

    if (stored->count != polynome->count) {
        free_polynome(stored);
        return NULL;
    }

    for (int i = 0; i < stored->count; i++) {
        if (stored->monomes[i].coefficient != polynome->monomes[i].coefficient ||
            stored->monomes[i].exponent != polynome->monomes[i].exponent) {
            free_polynome(stored);
            return NULL;
        }
    }
    return stored;
}

Polynome* delete_monome(const char* filename, int exponent) {
    Polynome* polynome = read_polynome_file(filename);
    if (!polynome) return NULL;

    int new_count = 0;
    for (int i = 0; i < polynome->count; i++) {
        if (polynome->monomes[i].exponent != exponent) {
            polynome->monomes[new_count++] = polynome->monomes[i];
        }
    }

    polynome->count = new_count;
    if (!write_polynome_file(filename, polynome)) {
        free_polynome(polynome);
        return NULL;
    }
    return polynome;
}

void free_polynome(Polynome* polynome) {
    if (!polynome) return;
    free(polynome->monomes);
    free(polynome);
}
