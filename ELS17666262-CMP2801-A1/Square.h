#pragma once

#include "Shape.h"
#include "Movable.h"

// Square is derived class of Shape and Movable to access the variables 
// and virtual/non-virtual member functions.
class Square : public Shape, public Movable {
private:
	double edge;

public:
	// Definitions of public functions.

	// Definition of constructor with appropriate variables required to make a Square.
	Square(double x, double y, double edge);

	// Overriding virtual functions from base classes.
	void CalculateArea();
	void CalculatePerimeter();
	void CalculatePoints();

	std::string ToString();

	void Move(double x, double y);
	void Scale(double x, double y);
};