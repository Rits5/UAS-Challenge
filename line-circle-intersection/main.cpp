/*
	Purpose: The program identifies if there will be 0, 1, or 2 intersection between
			 a line and circle and indicates the coordinates of intersection if there
			 are any.
*/

#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

void line_eqn(double x, double m, double y_int_line) {
	double y = m * x + y_int_line;
	printf("Point of intersection (%f, %f)\n", x, y);
}

// x1 and y1 = first point coordinates. x2 and y2 = second point coordinates. cx and cy = centre point of circle. r = radius of the circle
void lineCircleIntersection(double x1, double y1, double x2, double y2, double cx, double cy, double r) {
	double dx = x2 - x1;
	double dy = y2 - y1;
	double m = dy / dx;
	double y_int_line = y1 - m * x1;

	double a = (dx * dx + dy * dy) / 100;
	double b = (2 * (dx * (x1 - cx) + dy * (y1 - cy))) / 10;
	double c = (x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy) - r * r;

	double discriminant = b * b - 4 * a * c;


	//Code to test if all the variable values are as expected
	/*
	cout << "discriminant = " << discriminant << endl;
	cout << "dy = " << dy << endl;
	cout << "dx = " << dx << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "m = " << m << endl;
	*/

	if (discriminant < 0) {
		cout << "No Intersection" << endl;
	}

	else if (discriminant == 0) {
		cout << "One Intersection:" << endl;

		double x_coord = (-b + sqrt(discriminant)) / (2 * a);
		line_eqn(x_coord, m, y_int_line);
	}

	else if (discriminant > 0) {
		cout << "Two Intersections:" << endl;

		double first_x_coord = ((-b + sqrt(discriminant)) / (2 * a));
		line_eqn(first_x_coord, m, y_int_line);

		double second_x_coord = (-b - sqrt(discriminant)) / (2 * a);
		line_eqn(second_x_coord, m, y_int_line);
	}

	cout << "" << endl;
}

int main() {

	lineCircleIntersection(0, 10, 30, 10, 12, 0, 10);  // Line: (0,10), (30,10)
													   //Circle: (12, 0) r = 10

	lineCircleIntersection(0, -10, 15, 15, 9, 3, 5);   // Line: (0,-10), (15,15)
													   //Circle: (9, 3) r = 5

	lineCircleIntersection(0, -10, 15, 15, 10, -5, 4); // Line: (0,-10), (15,15)
													   //Circle: (10, -5) r = 4

	return 0;
}
