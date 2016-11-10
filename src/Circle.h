/*
 / * Circle.h
 *
 *  Created on: 6 de nov de 2016
 *      Author: Rogério
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Point.h"

extern Class CircleClass();

/*Object Attributes*/
typedef struct {
	OBJ_EXTENDS(Point);
	int rad;
} Circle;

/*Object Methods*/
typedef struct {
	OBJ_EXTENDS_METH(Point);
} TYPE_METH(Circle);

/*Object Creator*/
extern Circle * newCircle(int x, int y, int rad);

#endif /* CIRCLE_H_ */
