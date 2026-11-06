
#ifndef POLYNOME_FILES_H
#define POLYNOME_FILES_H

#include <stdbool.h>
#include <stddef.h>

typedef double Coefficient;

typedef struct Monome {
    Coefficient coefficient;
    int exponent;
} Monome;

typedef struct Polynome {
    Monome* monomes;
    int count;
} Polynome;

void print_polynome(const Polynome* polynome);

bool input_polynome(Polynome* polynome);
Coefficient polynome_value(const Polynome* polynome, Coefficient x);
void derivative(Polynome* polynome, Polynome* result);

Polynome* read_polynome_file(const char* filename);
Polynome* find_polynome_file(const char* filename, const Polynome* polynome);
Polynome* delete_polynome(const char* filename, int exponent);

#endif
