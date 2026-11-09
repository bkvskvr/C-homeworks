#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;
int main () {
    const char* file = "/Users/chocolatechip/CLionProjects/С++2026_2027/labs/lab12/input.txt";
    ifstream f;
    f.open(file, ios::in);
    if ( !f.is_open() ) {
        cerr << "Error opening reading file!" << endl;
        return -1;
    }

    int n = 0;
    double temp;
    while (f >> temp) {
        n++;
    }
    if (n <= 0) {
        cerr << "Error: File is empty" << endl;
        f.close();
        return -2;
    }
    f.close();
    f.open(file);

    double* x = new double[n];

    for ( int i = 0; i < n; i++ ) {
        if (!(f >> x[i])) {
            delete[] x;
            f.close();
            cerr << "error reading file!" << endl;
            return -3;
        }
    }
    f.close();

    const char* file2 = "output.txt";
    ofstream f2;
    f2.open(file2, ios::out);
    if ( !f2.is_open() ) {
        cerr << "Error writing opening file!" << endl;
        delete[] x;
        return -4;
    }
    for ( int i = n-1; i >= 0; i-- ) {
        f2 << fixed << setprecision(3) << sqrt(x[i]) << "\n";
        cout << fixed << setprecision(3) << sqrt(x[i]) << "\n";
    }
    f2.close();

    delete[] x;
    return 0;
}