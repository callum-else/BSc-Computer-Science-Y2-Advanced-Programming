#include "Square.h"

// Square comstructor, assigns all custom elements, base constructor handles leftTop.
// Calls the update function to calculate the shape information.
Square::Square(double x, double y, double edge) : Shape(Point(x,y)) {
	this->edge = std::abs(edge);
	Update();
}

// Function to calculate the area of a square, edge length squared.
void Square::CalculateArea() {
	area = (edge * edge);
}

// Function to calulate the perimeter of a square, 4 * edge length.
void Square::CalculatePerimeter() {
	perimeter = (edge * 4);
}

// Function to calculate where the points of the shape are.
// Assigns points to the samely named vector clockwise from point leftTop.
void Square::CalculatePoints() {
	points.clear();

	points.push_back(leftTop);
	points.push_back(Point(leftTop.x + edge, leftTop.y));
	points.push_back(Point(leftTop.x + edge, leftTop.y + edge));
	points.push_back(Point(leftTop.x, leftTop.y + edge));

	// Using a universal string converter in Shape base class, 
	// same code for every shape type.
	pointsString = GetPointsString();
}

// Function to move the square by adding the modifier to leftTop, then
// calculating the new points based around the new leftTop value.
void Square::Move(double x, double y) {	
	leftTop += Point(x, y); // Uses an operator+= overload.
	CalculatePoints();
}

// Function to scale the square by a given amount.
// Squares need to be scaled Isotropically, so values for x and y need to match.
// If they do not match, an error is thrown and the program continues, instead of
// scaling the shape.
void Square::Scale(double x, double y) {
	try {
		if (x != y)
			throw std::exception("INPUT ERROR: Squares can only be scaled by isotropic values.", 0);
		else {
			edge *= std::abs(x);
			Update();
		}
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

// Function to output all information to a String.
std::string Square::ToString() {
	return ("Square[e=" + DoubleToString(edge) + "] \n"
		+ "Points[" + pointsString + "] \n"
		+ "Area=" + DoubleToString(area) + " Perimeter=" + DoubleToString(perimeter)
		+ "\n");
}