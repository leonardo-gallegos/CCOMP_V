#include <cmath>
#include "Triangle.h"

Point builderPoints_triangle[3];

Point *buildArrayPoints(const Point p1, const Point p2,
                        const Point p3)
{
    builderPoints_triangle[0] = p1;
    builderPoints_triangle[1] = p2;
    builderPoints_triangle[2] = p3;

    return builderPoints_triangle;
}

Triangle::Triangle(const Point &a, const Point &b, const Point &c)
    : Polygon(buildArrayPoints(a,
                               b,
                               c),
              3) {}

double Triangle::area() const
{
    double side_1 = std::sqrt(std::pow(std::abs(points.get(0)->getX() - points.get(1)->getX()), 2) + 
                              std::pow(std::abs(points.get(0)->getY() - points.get(1)->getY()), 2));
    double side_2 = std::sqrt(std::pow(std::abs(points.get(2)->getX() - points.get(1)->getX()), 2) + 
                              std::pow(std::abs(points.get(2)->getY() - points.get(1)->getY()), 2));
    double side_3 = std::sqrt(std::pow(std::abs(points.get(0)->getX() - points.get(2)->getX()), 2) + 
                              std::pow(std::abs(points.get(0)->getY() - points.get(2)->getY()), 2));
    double sp = (side_1 + side_2 + side_3) / 2;
    return std::sqrt(sp * (sp - side_1) * (sp - side_2) * (sp - side_3));
}