#pragma once

#include "Point.h"
#include <vector>

class Polygone
{
    int n;
    std::vector<Point> points;

public:
    Polygone() : n(0) {}

    void input();
    double perimeter() const;
};