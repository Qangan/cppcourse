#include "point.hpp"
#include <cmath>
Point::Point() : x(0), y(0) {}
Point::Point(double x, double y) : x(x), y(y) {}
double Point::distance(Point &other) {
  return std::sqrt(std::pow((other.x - x), 2) + std::pow((other.y - y), 2));
}
