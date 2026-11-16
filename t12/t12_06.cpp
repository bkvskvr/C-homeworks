#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double x;
    char c;

    while (cin >> x) {
        if (x <= 0) {
            cout << "None" << endl;
        }
        else {
            cout << scientific << setw(5) << log(x) << endl;
            cout << fixed << setw(5) << log(x) << endl;
        }

        if (!(cin >> c))
            break;

        if (c != ',')
            break;
    }

    return 0;
}
