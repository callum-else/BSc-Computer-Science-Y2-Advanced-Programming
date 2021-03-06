#pragma once

#include "Shape.h"
#include "Movable.h"

// Rectangle is derived class of Shape and Movable to access the variables 
// and virtual/non-virtual member functions.
class Rectangle : public Shape, public Movable {
private:
	double height;
	double width;

public:
	// Definitions of public functions.

	// Definition of constructor with appropriate variables required to make a Rectangle.
	Rectangle(double x, double y, double height, double width);

	// Overriding virtual functions from base classes.
	void CalculateArea();
	void CalculatePerimeter();
	void CalculatePoints();

	std::string ToString();

	void Move(double x, double y);
	void Scale(double x, double y);
};