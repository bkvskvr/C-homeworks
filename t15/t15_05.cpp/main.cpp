#include "Circle.h"

#include <iostream>
#include <vector>

using namespace std;

void centerOfMass(const vector<Circle>& circles) {
    if (circles.empty()) {
        cout << "No circles!" << endl;
        return;
    }

    double sx = 0;
    double sy = 0;
    double sum = 0;

    for (int i = 0; i < (int)circles.size(); i++) {
        double m = circles[i].area();

        sx += circles[i].getX() * m;
        sy += circles[i].getY() * m;
        sum += m;
    }

    cout << "Center of mass: ("
         << sx / sum << ", "
         << sy / sum << ")" << endl;
}

int main() {
    vector<Circle> circles;

    int choice;

    do {
        cout << "\n1. Add circle" << endl;
        cout << "2. Delete circle" << endl;
        cout << "3. Show circles" << endl;
        cout << "4. Center of mass" << endl;
        cout << "5. Intersection" << endl;
        cout << "0. Exit" << endl;

        cout << "Choice: ";
        cin >> choice;

        if (!cin)
            break;

        switch (choice) {

        case 1: {
            Circle c;
            c.input();

            if (!cin)
                break;

            circles.push_back(c);

            cout << "Circle added!" << endl;
            break;
        }

        case 2: {
            int i;

            cout << "Enter circle number: ";
            cin >> i;

            if (i >= 1 && i <= (int)circles.size()) {
                circles.erase(circles.begin() + i - 1);
                cout << "Circle deleted!" << endl;
            }
            else {
                cout << "Invalid number!" << endl;
            }

            break;
        }

        case 3: {
            for (int i = 0; i < (int)circles.size(); i++) {
                cout << "\nCircle " << i + 1 << endl;

                circles[i].output();

                cout << "Diameter: "
                     << circles[i].diameter() << endl;

                cout << "Area: "
                     << circles[i].area() << endl;

                cout << "Perimeter: "
                     << circles[i].perimeter() << endl;
            }

            break;
        }

        case 4: {
            centerOfMass(circles);
            break;
        }

        case 5: {
            int i, j;

            cout << "Enter two circle numbers: ";
            cin >> i >> j;

            if (i < 1 || j < 1 ||
                i > (int)circles.size() ||
                j > (int)circles.size()) {

                cout << "Invalid numbers!" << endl;
                break;
            }

            double points[2][2];

            int n = circles[i - 1].intersection(
                circles[j - 1], points
            );

            cout << "Number of intersection points: "
                 << n << endl;

            for (int k = 0; k < n; k++) {
                cout << "("
                     << points[k][0] << ", "
                     << points[k][1] << ")" << endl;
            }

            break;
        }

        case 0:
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}