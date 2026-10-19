#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define M_MAX 100
#define N_MAX 100

void inputArray(double array[M_MAX][N_MAX], int m, int n) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            scanf("%lf", &array[i][j]);
        }
    }
}
void printArray(double array[M_MAX][N_MAX], int m, int n) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            printf("%lf ", array[i][j]);
        }
        printf("\n");
    }

}
double sum_subdiagonal(double array[M_MAX][N_MAX], int m, int n, int k) {
    double sum = 0;
    for (int i=0; i<m; i++) {
        int j=i-k;
        if (j >= 0 && j < n) {
            sum += array[i][j];
        }
    }
    return sum;
}
int main() {
    //test
    printf("testsing sum_diagonal function: \n");
    double test_matrix[][N_MAX] = {
        {1., 2., 3.},
        {4., 5., 6.},
        {7., 8., 9.}
    };

    double test_sums[5]={3., 8., 15., 12., 7.}; // array to store test sums

    for (int test_k=-3+1; test_k<3; test_k++) {
        double test_sum=sum_subdiagonal(test_matrix, 3, 3, test_k);
        if (fabs(test_sum-test_sums[test_k+2])<1e-6) {
            printf("tests passed for k=%d\n", test_k);
        }
        else {
            printf("test failed for k=%d\n", test_k);
        }
    }
    int m, n, k;
    double array[M_MAX][N_MAX];
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    inputArray(array, m, n);
    printf("the elements of the array are:\n");
    printArray(array, m, n);

    printf("enter the value of k: ");
    scanf("%d", &k);
    double sum = sum_subdiagonal(array, m, n, k);
    printf("the sum by k-diagonal elements are: %lf\n", sum);
}