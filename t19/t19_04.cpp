#include <iostream>
#include <vector>
#include <list>
#include <utility>

using namespace std;

vector<list<int>> createMatrix(int rows, int cols) {
    vector<list<int>> matrix(rows);
    for (int i = 0; i < rows; ++i) {
        matrix[i].resize(cols);
    }
    return matrix;
}

void printMatrix(const vector<list<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

vector<list<int>> inputMatrix(int rows, int cols) {
    vector<list<int>> matrix(rows);
    for (int i = 0; i < rows; ++i) {
        matrix[i].clear();
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element for row " << i
                 << ", column " << j << ": ";
            int tmp;
            cin >> tmp;
            matrix[i].push_back(tmp);
        }
    }
    return matrix;
}

int max_row(const list<int>& row) {
    int max_val = row.front();
    for (int val : row) {
        if (val > max_val) {
            max_val = val;
        }
    }
    return max_val;
}

void sort_by_max_row(vector<list<int>>& matrix) {
    list<pair<int, int>> max_pairs;
    int idx = 0;

    for (list<int>& row : matrix) {
        int max_val = max_row(row);
        max_pairs.push_back(make_pair(max_val, idx));
        ++idx;
    }

    max_pairs.sort();
    max_pairs.reverse();

    vector<list<int>> sorted_matrix;
    for (const auto& p : max_pairs) {
        sorted_matrix.push_back(matrix[p.second]);
    }
    matrix = sorted_matrix;
}

int main() {
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    if (!cin || rows <= 0 || cols <= 0 ||
        rows >= 100 || cols >= 100) {
        cout << "Invalid matrix size!" << endl;
        return 1;
    }

    vector<list<int>> matrix = inputMatrix(rows, cols);

    cout << "Original matrix:" << endl;
    printMatrix(matrix);

    sort_by_max_row(matrix);

    cout << "Sorted matrix:" << endl;
    printMatrix(matrix);

    return 0;
}