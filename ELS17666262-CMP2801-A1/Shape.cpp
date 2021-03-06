#include "Shape.h"

// Shape constructor definition.
Shape::Shape(Point topLeft) : leftTop(topLeft), area(0), perimeter(0) {};

// Definition for shape Update function, can be called by any derived accessor.
void Shape::Update() {
	CalculateArea();
	CalculatePerimeter();
	CalculatePoints();
};

// Definition for GetPointsString function, converts all point elements to string.
std::string Shape:: GetPointsString() {
	std::string strPoints = "";
	for (Point p : points)
		strPoints += '(' + DoubleToString(p.GetX()) + ',' + DoubleToString(p.GetY()) + ')';
	return strPoints;
};

// DoubleToString definition, handles string truncation.
std::string Shape::DoubleToString(double d) {
	std::string dStr = std::to_string(d);

	double dp;
	if (std::modf(d, &dp) == 0)
		dStr = dStr.substr(0, dStr.find('.'));
	else
		dStr = dStr.substr(0, dStr.find('.') + 3);

	return dStr;
}

// Definition for << overload. References derived object's ToString() method.
std::ostream* operator<<(std::ostream& os, Shape* s)
{
	os << s->ToString();
	std::ostream* ptr = &os;
	return ptr;
}