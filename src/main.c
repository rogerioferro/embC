/*
 ============================================================================
 Name        : my_circles.c
 Author      : Rogério Ferro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdlib.h>

#include "Circle.h"

#define MAX	5

int main(int argc, char ** argv) {
	Point * point[MAX];
	point[0] = (Point *) newCircle(1, 2, 3);
	point[1] = newPoint(4, 5);
	point[2] = (Point *) newCircle(3, 7, 5);
	point[3] = newPoint(3, 8);
	point[4] = NULL;


	{
		Point ** p;
		const void * meths;
		p = point;
		while (*p) {
			meths = Interface(*p, PointClass());
			if (meths) {
				CAST_METH(Point,meths)->draw(*p);
				CAST_METH(Point,meths)->move(*p, 10, 20);
				CAST_METH(Point,meths)->draw(*p);
				CAST_METH(Object,meths)->destroy(*p);
		}
			p++;
		}
	}

	return 0;
}
