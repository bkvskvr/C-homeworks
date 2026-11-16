#pragma once

class Point
{
    double x, y;
    static int count;

public:
    Point() : x(0), y(0) {
        ++count;
    }

    Point(double x_, double y_) : x(x_), y(y_) {
        ++count;
    }

    Point(const Point& p) : x(p.x), y(p.y) {
        ++count;
    }

    ~Point() {
        --count;
    }

    static Point input();

    static int counter() {
        return count;
    }

    static double length(const Point& p1, const Point& p2);
};