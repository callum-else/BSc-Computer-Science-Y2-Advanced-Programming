#include "Rectangle.h"

// Rectangle comstructor, assigns all custom elements, base constructor handles leftTop.
// Calls the update function to calculate the shape information.
Rectangle::Rectangle(double x, double y, double height, double width) : Shape(Point(x, y)) {
	this->height = std::abs(height);
	this->width = std::abs(width);
	Update();
}

// Function to calculate the area of a square, height multiplied by the width.
void Rectangle::CalculateArea() {
	area = (height * width);
}

// Function to calulate the perimeter of a rectangle, 2height + 2width.
void Rectangle::CalculatePerimeter() {
	perimeter = (height + width) * 2;
}

// Function to calculate where the points of the shape are.
// Assigns points to the samely named vector clockwise from point leftTop.
void Rectangle::CalculatePoints() {
	points.clear();

	points.push_back(leftTop);
	points.push_back(Point(leftTop.x + width, leftTop.y));
	points.push_back(Point(leftTop.x + width, leftTop.y + height));
	points.push_back(Point(leftTop.x, leftTop.y + height));

	// Using a universal string converter in Shape base class, 
	// same code for every shape type.
	pointsString = GetPointsString();
}

// Function to move the rectangle by adding the modifier to leftTop, then
// calculating the new points based around the new leftTop value.
void Rectangle::Move(double x, double y) {
	leftTop += Point(x, y);
	CalculatePoints();
}

// Function to scale the rectangle height and width by a given amount.
void Rectangle::Scale(double x, double y) {
	width *= std::abs(x);
	height *= std::abs(y);
	Update();
}

// Function to output all information to a String.
std::string Rectangle::ToString() {
	return ("Rectangle[h=" + DoubleToString(height) + " w=" + DoubleToString(width) + "] \n"
		+ "Points[" + pointsString + "] \n"
		+ "Area=" + DoubleToString(area) + " Perimeter=" + DoubleToString(perimeter)
		+ "\n");
}