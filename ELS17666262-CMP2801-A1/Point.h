#pragma once
class Point {
private:
	// Private variables x and y used for storing 2 dimentional
	// coordinates for use within the shape base and derived classes.
	// Stored as doubles, as inputs may have decimal spaces.
	double x;
	double y;

public:
	// Point constructor declaration.
	Point(double x, double y);
	
	// Accssor functions for x and y.
	double GetX() { return x; };
	double GetY() { return y; };
	
	// Using friend classes to allow access to private variables.
	// Could have used getter and setter function types, or made
	// variables public.
	friend class Square;
	friend class Rectangle;
	friend class Circle;

	// Operator Overloading.
	friend Point& operator+=(Point& a, const Point& b);
};