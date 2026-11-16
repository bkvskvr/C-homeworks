#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
int main() {
    unsigned n;
    cout << "n = ";
    cin >> n;

    int* m = new int[n];
    for ( unsigned i = 0; i < n; i++ ) {
        cout << "m[" << i << "] = ";
        cin >> m[i];
    }

    const char* file = "xfile.txt";

    fstream f;
    f.open(file, ios::out);
    if ( !f.is_open() ) {
        cerr << "Error writing opening file!" << endl;
        delete[] m;
        f.close();
        return -1;
    }
    for ( unsigned i = 0; i < n; i++ ) {
        f << m[i] << " ";
    }
    f.close();

    f.open(file, ios::in);
    if ( !f.is_open() ) {
        cerr << "Error reading opening file!" << endl;
        delete[] m;
        f.close();
        return -1;
    }

    double* x = new double[n];

    for ( unsigned i = 0; i < n; i++ ) {
        double tmp;
        if (!(f >> tmp)) {
            delete[] m;
            delete[] x;
            cerr << "error reading file!" << endl;
            return -2;
        }
        x[i] = tmp;
    }

    f.close();

    const char* file2 = "xfile2.txt";
    fstream g( file2, ios::out );
    if ( !g.is_open() ) {
        cerr << "Error writing opening file!" << endl;
        delete[] m;
        delete[] x;
        return -3;
    }
    for ( unsigned i = 0; i < n; i++ ) {
        g << pow( x[i], m[i] )<< "\n";
        cout << pow( x[i], m[i] ) << "\n";
    }
    g.close();

    delete[] m;
    delete[] x;
    return 0;
}