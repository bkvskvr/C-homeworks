#pragma once

class Circle
{
    double x, y, r;

public:
    Circle() : x(0), y(0), r(1) {}

    Circle(double x_, double y_, double r_);

    void input();
    void output() const;

    double diameter() const;
    double area() const;
    double perimeter() const;

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    double getR() const {
        return r;
    }

    int intersection(const Circle& c, double points[2][2]) const;
};