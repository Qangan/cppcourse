#include "line.hpp"
#include "point.hpp"
#include <iostream>

int main() {
  Point p1(0, 0);
  Point p2(3, 4);
  Point p3(5, 2);
  Point p4(1, 1);
  Point p5(4, 5);

  std::cout << p1.distance(p2) << std::endl;

  Line line1(p1, p2);
  Line line2(p4, p5);

  std::cout << line1.distance(p3) << std::endl;

  Line perp = line1.perpendicular(p3);
  std::cout << perp.A << " " << perp.B << " " << perp.C << std::endl;
  std::cout << perp.distance(p3) << std::endl;

  std::cout << "Lines 1 and 2: " << line1.intersect(line2) << std::endl;
  std::cout << "Lines 1 and 3: " << line1.intersect(perp) << std::endl;
  return 0;
}
