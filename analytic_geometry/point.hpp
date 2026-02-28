#ifndef POINTHPP
#define POINTHPP
struct Point {
public:
  Point();
  Point(double x, double y);
  double distance(Point &other);
  const double x;
  const double y;
};

#endif
