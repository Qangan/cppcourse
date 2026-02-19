#include "line.hpp"
#include <cmath>

Line::Line() : A(1), B(0), C(0) {}
Line::Line(double A, double B, double C) : A(A), B(B), C(C) {}
Line::Line(Point &M_1, Point &M_2)
    : A(M_1.y - M_2.y), B(M_2.x - M_1.x), C(M_1.x * M_2.y - M_2.x * M_1.y) {}
Line Line::perpendicular(Point &M) { return Line(B, -A, -(B * M.x - A * M.y)); }
bool Line::intersect(Line &other) { return (A * other.B - other.A * B) != 0; }
bool Line::contains(Point &M) { return (A * M.x + B * M.y + C) == 0; }
double Line::distance(Point &M) {
  return (std::abs(A * M.x + B * M.y + C) /
          (std::sqrt(std::pow(A, 2) + std::pow(B, 2))));
};
