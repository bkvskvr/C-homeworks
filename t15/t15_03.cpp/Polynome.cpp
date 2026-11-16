#include "Polynome.h"

using namespace std;

Polynome::Polynome(int n) {
    if (n < 1)
        n = 1;

    this->n = n;
    a = new double[n];

    for (int i = 0; i < n; i++)
        a[i] = 0;
}

Polynome::Polynome(int n, const double* coefficients) {
    if (n < 1)
        n = 1;

    this->n = n;
    a = new double[n];

    for (int i = 0; i < n; i++)
        a[i] = coefficients ? coefficients[i] : 0;
}

Polynome::Polynome(const Polynome& p) {
    n = p.n;
    a = new double[n];

    for (int i = 0; i < n; i++)
        a[i] = p.a[i];
}

Polynome::~Polynome() {
    delete[] a;
}

void Polynome::input() {
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

void Polynome::setCoefficient(int i, double value) {
    if (i >= 0 && i < n)
        a[i] = value;
}

void Polynome::output() const {
    for (int i = n - 1; i >= 0; i--) {
        cout << a[i];

        if (i > 0)
            cout << "*x^" << i << " + ";
    }

    cout << endl;
}

Polynome& Polynome::operator=(const Polynome& p) {
    if (this == &p)
        return *this;

    double* temp = new double[p.n];

    for (int i = 0; i < p.n; i++)
        temp[i] = p.a[i];

    delete[] a;

    n = p.n;
    a = temp;

    return *this;
}

ostream& operator<<(ostream& out, const Polynome& p) {
    for (int i = p.n - 1; i >= 0; i--) {
        out << p.a[i];

        if (i > 0)
            out << "*x^" << i << " + ";
    }

    return out;
}

istream& operator>>(istream& in, Polynome& p) {
    for (int i = 0; i < p.n; i++)
        in >> p.a[i];

    return in;
}

void writeBinary(const char* filename, const Polynome& p) {
    ofstream fout(filename, ios::binary);

    if (!fout) {
        cout << "Error opening file!" << endl;
        return;
    }

    fout.write((char*)&p.n, sizeof(p.n));
    fout.write((char*)p.a, p.n * sizeof(double));

    fout.close();
}

void readBinary(const char* filename, Polynome& p) {
    ifstream fin(filename, ios::binary);

    if (!fin) {
        cout << "Error opening file!" << endl;
        return;
    }

    int n;
    fin.read((char*)&n, sizeof(n));

    if (!fin || n < 1 || n > 1000000) {
        cout << "Invalid file!" << endl;
        return;
    }

    double* temp = new double[n];

    fin.read((char*)temp, n * sizeof(double));

    if (!fin) {
        cout << "Error reading file!" << endl;
        delete[] temp;
        return;
    }

    delete[] p.a;

    p.n = n;
    p.a = temp;

    fin.close();
}