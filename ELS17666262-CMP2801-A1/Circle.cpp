#include "Circle.h"

// Circle comstructor, assigns all custom elements, base constructor handles leftTop.
// Calls the update function to calculate the shape information.
Circle::Circle(double x, double y, double radius) : Shape(Point(x,y)) {
	this->radius = std::abs(radius);
	Update();
}

// Function to calculate the area of a circle, Pi * radius squared.
void Circle::CalculateArea() {
	area = M_PI * (radius * radius);
}

// Function to calculate the perimeter of a circle, 2 * Pi * radius.
void Circle::CalculatePerimeter() {
	perimeter = 2 * M_PI * radius;
}

// Function to calculate where the points of the shape are.
// Assigns only top left and bottom right points to the 'points' vector 
// clockwise from point leftTop.
void Circle::CalculatePoints() {
	points.clear();

	points.push_back(leftTop);
	points.push_back(
		Point(
			leftTop.x + (2 * radius), 
			leftTop.y + (2 * radius)
		)
	);
	
	// Using a universal string converter in Shape base class, 
	// same code for every shape type.
	pointsString = GetPointsString();
}

// Function to move the circle by adding the modifier to leftTop, then
// calculating the new points based around the new leftTop value.
void Circle::Move(double x, double y) {
	leftTop += Point(x, y);
	CalculatePoints();
}

// Function to scale the circle radius by a given amount.
// Circles need to be scaled Isotropically, so values for x and y need to match.
// If they do not match, an error is thrown and the program continues, instead of
// scaling the shape.
void Circle::Scale(double x, double y) {
	try {
		if (x != y)
			throw std::exception("INPUT ERROR: Circles can only be scaled by isotropic values.", 0);
		else {
			radius *= std::abs(x);
			Update();
		}
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

// Function to output all information to a String.
std::string Circle::ToString() {
	return ("Circle[r=" + DoubleToString(radius) + "] \n"
		+ "Points[" + pointsString + "] \n"
		+ "Area=" + DoubleToString(area) + " Perimeter=" + DoubleToString(perimeter)
		+ "\n");
}