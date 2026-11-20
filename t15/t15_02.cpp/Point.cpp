#include "Point.h"

#include <iostream>
#include <cmath>

using namespace std;

int Point::count = 0;

Point Point::input() {
    double x = 0, y = 0;
    cout << "Enter x and y: ";
    cin >> x >> y;
    return Point(x, y);
}

double Point::length(const Point& p1, const Point& p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}