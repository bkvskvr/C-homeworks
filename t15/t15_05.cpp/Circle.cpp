#include "Circle.h"

#include <iostream>
#include <cmath>

using namespace std;

const double PI = acos(-1.0);
const double EPS = 1e-9;

Circle::Circle(double x_, double y_, double r_) {
    x = x_;
    y = y_;
    r = (r_ > 0) ? r_ : 1;
}

void Circle::input() {
    cout << "Enter x, y, r: ";

    double x_, y_, r_;
    cin >> x_ >> y_ >> r_;

    if (!cin)
        return;

    if (r_ <= 0) {
        cout << "Invalid radius!" << endl;
        return;
    }

    x = x_;
    y = y_;
    r = r_;
}

void Circle::output() const {
    cout << "Center: (" << x << ", " << y << ")" << endl;
    cout << "Radius: " << r << endl;
}

double Circle::diameter() const {
    return 2 * r;
}

double Circle::area() const {
    return PI * r * r;
}

double Circle::perimeter() const {
    return 2 * PI * r;
}

int Circle::intersection(const Circle& c, double points[2][2]) const {
    double dx = c.x - x;
    double dy = c.y - y;

    double d = sqrt(dx * dx + dy * dy);

    if (d < EPS)
        return 0;

    if (d > r + c.r + EPS)
        return 0;

    if (d < fabs(r - c.r) - EPS)
        return 0;

    double a = (r * r - c.r * c.r + d * d) / (2 * d);

    double h2 = r * r - a * a;

    if (h2 < -EPS)
        return 0;

    double xm = x + a * dx / d;
    double ym = y + a * dy / d;

    if (h2 <= EPS) {
        points[0][0] = xm;
        points[0][1] = ym;
        return 1;
    }

    double h = sqrt(h2);

    points[0][0] = xm - h * dy / d;
    points[0][1] = ym + h * dx / d;

    points[1][0] = xm + h * dy / d;
    points[1][1] = ym - h * dx / d;

    return 2;
}