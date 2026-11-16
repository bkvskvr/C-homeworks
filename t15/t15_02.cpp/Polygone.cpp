#include "Polygone.h"

#include <iostream>
#include <string>

using namespace std;

void Polygone::input() {
    string answer;

    while (true) {
        cout << "Enter a vertex? (yes/no): ";

        if (!(cin >> answer) || answer == "no" || answer == "No") {
            break;
        }

        if (answer == "yes" || answer == "Yes") {
            Point p = Point::input();

            if (!cin) {
                cout << "Invalid coordinates." << endl;
                return;
            }

            points.push_back(p);
            n++;
        }
    }
}

double Polygone::perimeter() const {
    if (n < 3) {
        return 0;
    }

    double sum = 0;

    for (int i = 1; i < n; i++) {
        sum += Point::length(points[i - 1], points[i]);
    }

    sum += Point::length(points[n - 1], points[0]);

    return sum;
}