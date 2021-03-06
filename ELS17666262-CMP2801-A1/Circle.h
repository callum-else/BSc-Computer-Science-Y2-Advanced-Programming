#pragma once

#include "Shape.h"
#include "Movable.h"

// Using math.h and _USE_MATH_DEFINES to get access to const variable of PI.
#define _USE_MATH_DEFINES
#include <math.h>

// Circle is derived class of Shape and Movable to access the variables 
// and virtual/non-virtual member functions.
class Circle : public Shape, public Movable {
private:
	double radius;

public:
	// Definitions of public functions.

	// Definition of constructor with appropriate variables required to make a circle.
	Circle(double x, double y, double r);

	// Overriding virtual functions from base classes.
	void CalculateArea();
	void CalculatePerimeter();
	void CalculatePoints();

	std::string ToString();

	void Move(double x, double y);
	void Scale(double x, double y);
};