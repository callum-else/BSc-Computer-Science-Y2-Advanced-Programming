#include "Point.h"

// Using in-line constructor definition for point.
Point::Point(double x, double y) : x(x), y(y) {};

//Point += overload, allows for the ease of addition when combining Points.
Point& operator+=(Point& a, const Point& b) {
	return a = Point(a.x + b.x, a.y + b.y);
};