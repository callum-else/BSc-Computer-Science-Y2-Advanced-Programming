#pragma once

#include "Point.h"
#include <string>
#include <vector>
#include <iostream>

// Base class for all shapes. Stores parameters, virtual functions and 
// functions serving global functions used by all derived classes 
// (identified as defined functions).
class Shape {
// Variables protected so derived classes can access them.
protected:
	Point leftTop;
	std::vector<Point> points;
	std::string pointsString;

	double area;
	double perimeter;

public:
	// Base constructor that only takes a point value, as to remove the repeatative assignment
	// of leftTop from derived classes, and to initialise variables.
	Shape(Point topLeft);
	
	// Purely virtual functions to be overloaded by derived classes.
	virtual void CalculatePoints() = 0;
	virtual void CalculateArea() = 0;
	virtual void CalculatePerimeter() = 0;

	virtual std::string ToString() = 0;

	void Update();

	// Defined global member functions.
	std::string GetPointsString();

	std::string DoubleToString(double d);

	//Overload for operator<< to enable use of 'cout << this'.
	friend std::ostream* operator<<(std::ostream& os, Shape* s);

	// Shape destructor to remove vector, dynamically lengthed -  
	// possibly leading to memory leaks.
	~Shape() {
		delete &points;
	};
};