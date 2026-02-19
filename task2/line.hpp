#ifndef LINE_HPP
#include "point.hpp"
#define LINE_HPP
struct Line {
public:
  Line();
  Line(double A, double B, double C);
  Line(Point &M_1, Point &M_2);
  Line perpendicular(Point &M);
  bool intersect(Line &other);
  bool contains(Point &M);
  double distance(Point &M);
  const double A;
  const double B;
  const double C;
};
#endif
