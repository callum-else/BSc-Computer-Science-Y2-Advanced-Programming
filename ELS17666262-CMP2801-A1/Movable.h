#pragma once
// Pure virtual class for movable, stores virtual functions to move shapes.
// Functions overriden in dervied classes.
class Movable {
public:
	virtual void Move(double x, double y) = 0;
	virtual void Scale(double x, double y) = 0;
};