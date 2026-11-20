#include "Polygone.h"

#include <iostream>

using namespace std;

int main() {
    Polygone polygon;
    polygon.input();

    if (!cin) {
        return 1;
    }

    int n = Point::counter();

    cout << "Number of vertices: " << n << endl;

    if (n < 3) {
        cout << "A polygon needs at least 3 vertices." << endl;
        return 0;
    }

    cout << "Perimeter: " << polygon.perimeter() << endl;

    return 0;
}