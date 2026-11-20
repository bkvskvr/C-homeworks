#include "Polynome.h"

using namespace std;

int main() {
    int n;

    cout << "Enter number of coefficients: ";
    cin >> n;

    if (!cin || n < 1)
        return 1;

    Polynome p(n);

    cout << "Enter coefficients:" << endl;
    p.input();

    if (!cin)
        return 1;

    cout << "Polynome: ";
    p.output();

    int i;
    double value;

    cout << "Enter coefficient index: ";
    cin >> i;

    cout << "Enter new value: ";
    cin >> value;

    if (!cin)
        return 1;

    p.setCoefficient(i, value);

    cout << "Modified polynome: " << p << endl;

    Polynome p2(p);

    cout << "Copied polynome: " << p2 << endl;

    Polynome p3;
    p3 = p;

    cout << "Assigned polynome: " << p3 << endl;

    writeBinary("polynome.bin", p);

    Polynome p4;
    readBinary("polynome.bin", p4);

    cout << "Polynome from binary file: " << p4 << endl;

    return 0;
}