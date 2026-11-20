#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <stdexcept>

using namespace std;

template<typename T>
class Matrix {
private:
    vector<vector<T>> data;
    int rows, cols;

public:
    Matrix(int n, int m) : rows(n), cols(m) {
        if (n <= 0 || m <= 0)
            throw invalid_argument("Invalid matrix size!");

        data.resize(n, vector<T>(m));
    }

    void input() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << "a[" << i << "][" << j << "] = ";
                if (!(cin >> data[i][j]))
                    throw runtime_error("Invalid input!");
            }
        }
    }

    friend ostream& operator<<(ostream& out, const Matrix<T>& a) {
        for (int i = 0; i < a.rows; i++) {
            for (int j = 0; j < a.cols; j++) {
                out << a.data[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }

    friend Matrix<T> operator+(const Matrix<T>& a, const Matrix<T>& b) {
        if (a.rows != b.rows || a.cols != b.cols)
            throw invalid_argument("Matrix sizes must be equal!");

        Matrix<T> result(a.rows, a.cols);

        for (int i = 0; i < a.rows; i++) {
            transform(
                a.data[i].begin(),
                a.data[i].end(),
                b.data[i].begin(),
                result.data[i].begin(),
                plus<T>()
            );
        }

        return result;
    }

    friend vector<T> operator*(const Matrix<T>& a, const vector<int>& v) {
        if (a.cols != (int)v.size())
            throw invalid_argument("Invalid vector size!");

        vector<T> result(a.rows, T{});

        for (int i = 0; i < a.rows; i++) {
            for (int j = 0; j < a.cols; j++) {
                result[i] += a.data[i][j] * v[j];
            }
        }

        return result;
    }

    friend Matrix<T> operator*(const Matrix<T>& a, const Matrix<T>& b) {
        if (a.cols != b.rows)
            throw invalid_argument("Invalid matrix sizes!");

        Matrix<T> result(a.rows, b.cols);

        for (int i = 0; i < a.rows; i++) {
            for (int j = 0; j < b.cols; j++) {
                result.data[i][j] = T{};

                for (int k = 0; k < a.cols; k++) {
                    result.data[i][j] +=
                        a.data[i][k] * b.data[k][j];
                }
            }
        }

        return result;
    }
};

template<typename T>
void printVector(const vector<T>& v) {
    for (T value : v) {
        cout << value << " ";
    }
    cout << endl;
}

int main() {
    try {
        cout << "Integer matrices:" << endl;

        Matrix<int> a(2, 2);
        Matrix<int> b(2, 2);

        cout << "Enter matrix A:" << endl;
        a.input();

        cout << "Enter matrix B:" << endl;
        b.input();

        cout << "\nMatrix A:" << endl;
        cout << a;

        cout << "Matrix B:" << endl;
        cout << b;

        cout << "A + B:" << endl;
        cout << a + b;

        cout << "A * B:" << endl;
        cout << a * b;

        vector<int> v = {1, 2};

        cout << "A * vector:" << endl;
        printVector(a * v);

        cout << "\nFloat matrices:" << endl;

        Matrix<float> c(2, 2);
        Matrix<float> d(2, 2);

        cout << "Enter matrix C:" << endl;
        c.input();

        cout << "Enter matrix D:" << endl;
        d.input();

        cout << "C + D:" << endl;
        cout << c + d;

        cout << "C * D:" << endl;
        cout << c * d;

        cout << "C * vector:" << endl;
        printVector(c * v);
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}