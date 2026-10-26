#ifndef VECTOR_H
#define VECTOR_H

double* input_vector(int n);
double* add_vectors(const double* vect1, const double* vect2, int n);
void print_vector(const double* vect, int n);
void delete_vector(double* vect);

#endif // VECTOR_H
