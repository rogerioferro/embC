/*
 * Point.h
 *
 *  Created on: 6 de nov de 2016
 *      Author: Rogério
 */

#ifndef POINT_H_
#define POINT_H_

#include "Object.h"

extern Class PointClass();

/*Object Attributes*/
typedef struct {
	extends(Object);
	int x;
	int y;
} Point;

/*Object Methods*/
typedef struct {
	extends(methObject);
	void (*draw)(const void * obj);
	void (*move)(const void * obj, int dx, int dy);
} methPoint;

/*Object Creator*/
extern Point * newPoint(int x, int y);

#endif /* POINT_H_ */
