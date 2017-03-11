// Project: CIS022_S2017_Lab7
// Module: CIS022_S2017_Lab7 Morgan Shorter-McFarlane.cpp
// Date: March 10 2017
// Developer: Morgan Shorter-McFarlane
// Purpose: Check if three line segments can make a triange. Determine whether the triangle is scalene, isosceles, or equilateral.
//           Output the result

#include "stdafx.h"  //Include the standard library
#include <iostream>  //Include the standard input and output library
#include <string>    //Include the string library

using namespace std; //Use the standard namespace


int triangleShape( int a, int b, int c) //Define an integer returning fucntion that will determine what kind of triange is made up by the three sides
{					//Normally it is a bad idea to use the same variable names in different scopes like this, but in this case the values will be the same anyway.

	int equalSides = 0; //define and declare the output variable

	if (((a+b) > c) && ((a+c) > b) && ((c+b) > a)) //if it is a triangle (as defined in the exercise instructions)
	{
		equalSides++; // Add one to the output variable
	
		if (a == b)     // add one to the output variable every time we find a matching side
			equalSides++;

		if (b == c) 
			equalSides++;
	
		if (c == a) 
			equalSides++;

		if (equalSides == 4)  //correct for equilateral triangles
			equalSides = 3;
	}
	triangleType Answer = static_cast<triangleType> (equalSides) // Because I lose points if I don't show that I know how to use enumeration types
	
	return equalSides; //return a value from 0-3
}

int main() //Main program entry point
{

	int a; // Declare three variables that will hold the side lengths
	int b;
	int c;
	enum triangleType {noTriangle, scalene, isosceles, equilateral}; //Define superfluous enumeration type
	string triangleText = ""; //Create a string to hold some output text

	cout << "Input three triangle side lengths separated by spaces: "; // Prompt the user for input
	cin << a << b << c;                                                // Collect the input into the three variables declared above

	switch (triangleShape(a, b, c)) //Use a switch to translate the output of triangleShape into text
	{
		case 1:                            //match the number of equal sides to the corresponding type of triange
			triangleText = "scalene (all sides different lengths)";
			break;
		case 2:
			triangleText = "isosceles (two sides of equal lengths)";
			break;
		case 3:
			triangleText = "equilateral (all sides equal in length)";
			break;
		default: 
			triangeText = "not a";  // any other output from triangleShape is not a triangle
	}
	
	//Output what type of triangle was input into the program as a sentence.
	cout << "\n\nThe side lenths that were given produce a(n) " + triangleText + triangleSahape(a, b, c) + " triangle.\n\n\n";  

	system("Pause"); //Pause execution until a user keypress

	return 0; // End the program

}


