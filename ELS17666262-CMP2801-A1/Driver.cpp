/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for assignment
Fall 2019

Written by Ayse Kucukyilmaz

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure
you follow that guideline. Also make sure that you don't
change the main body provided to you here.
Otherwise, your code may not pass the test cases...

GOOD LUCK!

------------------------------------------------------ */

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Movable.h"

#include <iostream>
#include <vector>
#include <string>

#include <regex>

using namespace std;

int main()
{
	string userCommand;
	vector <Shape*> shapes;			// this one will hold your shapes
	vector <string> parameters;		// this one will hold parameters for the commands
	const regex rExpression("\\S+");	// this is the regex epression used for string tokenisation

	while (userCommand.compare("exit") != 0)
	{
		userCommand = ""; // Resetting userCommand at the begining of the loop so exit command is possible.

		cout << "Enter the command: ";
		getline(cin, userCommand);

		char* cstr = new char[userCommand.length() + 1];
		strcpy_s(cstr, userCommand.length() + 1, userCommand.c_str());

		// Using regex to tokenise the inputs.
		// Finds match, removes it and searches again. 
		// Keeps searching until there are no more matches.
		// Using '\S+' regex expression, finds all non-whitespace words - Highly expandable.
		smatch match;
		string searchStr = userCommand;
		while (regex_search(searchStr, match, rExpression)) {
			parameters.push_back(match[0]);
			searchStr = match.suffix();
		}
				
		string command;
		try {

			// Using a try catch to test if anything was actually input, throws exception if not the case.
			if (parameters.size() > 0)
				// Command now stored in parameters[0], so can be checked with strings for a match.
				command = parameters[0];
			else
				throw exception("INPUT ERROR: No inputs detected.");

			// If statements are implemented here, but should have used a map data structure to
			// map the strings to a template function, assigning it a type to create a pointer instance of, 
			// and then storing a pointer in the 'shapes' vector. The shapes could hold a variable for the 
			// required parameter length. This fully utilises the Polymorphic system, and reduces the 
			// amount of code neccessary.
			if (command.compare("addR") == 0) {
				// Using try catches to throw errors if parameter count does not match required params.
				if (parameters.size() != 5) {
					throw exception("INPUT ERROR: Required parameters not provided.");
				}

				Rectangle* r = new Rectangle(
					std::stod(parameters[1].c_str()),	// x
					std::stod(parameters[2].c_str()),	// y
					std::stod(parameters[3].c_str()),	// h
					std::stod(parameters[4].c_str())	// w
				);

				shapes.push_back(r);
				cout << r; // Using << overload to access ToString() method.
			}

			// Duplicates design of previous add command.
			else if (command.compare("addS") == 0) {
				if (parameters.size() != 4)
					throw exception("INPUT ERROR: Required parameters not provided.");

				Square* s = new Square(
					std::stod(parameters[1].c_str()),
					std::stod(parameters[2].c_str()),
					std::stod(parameters[3].c_str())
				);

				shapes.push_back(s);
				cout << s; // Using << overload to access ToString() method.
			}

			// Duplicates design of previous add command.
			// Changed 'if' to 'else if' as to continue chain, allows for encapsulated error handling.
			else if (command.compare("addC") == 0) {
				if (parameters.size() != 4)
					throw exception("INPUT ERROR: Required parameters not provided.");

				Circle* c = new Circle(
					std::stod(parameters[1].c_str()),
					std::stod(parameters[2].c_str()),
					std::stod(parameters[3].c_str())
				);

				shapes.push_back(c);
				cout << c; // Using << overload to access ToString() method.
			}

			// Scale command dynamically casts the shape to type 'Movable'. Allows for use of movable functions. 
			else if (command.compare("scale") == 0) {
				if (parameters.size() != 4)
					throw exception("INPUT ERROR: Required parameters not provided.");

				int index = std::stod(parameters[1].c_str()) - 1;
				if (index < shapes.size() && index >= 0) {
					Movable* m = dynamic_cast<Movable*>(shapes[index]);
					m->Scale(std::stod(parameters[2].c_str()), std::stod(parameters[3].c_str()));
					cout << shapes[index]; // Using << overload to access ToString() method.
				}
				else
					// Throws error if the shape index is not in the range of vector shapes.
					throw exception("INPUT ERROR: Index of shape out of range.");

			}

			// Move works in exactly the same way as Scale, except references the move command.
			else if (command.compare("move") == 0) {
				if (parameters.size() != 4)
					throw exception("INPUT ERROR: Required parameters not provided.");

				int index = std::stoi(parameters[1].c_str()) - 1;
				if (index < shapes.size() && index >= 0) {
					Movable* m = dynamic_cast<Movable*>(shapes[index]);
					m->Move(std::stod(parameters[2].c_str()), std::stod(parameters[3].c_str()));
					cout << shapes[index]; // Using << overload to access ToString() method.
				}
				else
					// Throws error if the shape index is not in the range of vector shapes.
					throw exception("INPUT ERROR: Index of shape out of range.");
			}

			// Display shows all of the shape info. Uses the same method as the Moveable functions to display
			// the shape information for exactly the same reason - would be incredibly inefficient and 
			// not easily expandable to compare with every type though casting. Would defeat the purpose of 
			// OOP & Polymorphism.
			else if (command.compare("display") == 0) {
				for (Shape* s : shapes) {
					cout << s; // Using << overload to access ToString() method.
				}
			}
			
			// Throws exception if there is no command match.
			// Checks if command is not exit first, as it is a valid command.
			else if (command.compare("exit") != 0)
				throw exception("INPUT ERROR: Command Unrecognised.");
		}

		// The catch for any thrown exception. Displays it and moves on.
		catch (exception& e) {
			cout << e.what();
		}

		// Clean up to reset & avoid memory leaks.
		delete []cstr;
		parameters.clear();

		// Adds spacing between commands - aesthetic only.
		cout << endl << endl;
	}

	cout << "Press any key to continue...";

	std::getchar();

	return 0;
}