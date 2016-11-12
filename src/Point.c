/*
 * Point.c
 *
 *  Created on: 6 de nov de 2016
 *      Author: Rogério
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Point-private.h"


/* Declare Private Object*/
OBJ_DECLARE(Point);

/*
 *  Declarations
 **/

Point * 	newPoint		(int x, int y);
void 		PointClass_ctor	(void * class, void * meth);
void 		Point_ctor		(void * obj, va_list * app);
void 		Point_draw		(const void * obj);
void 		Point_move		(const void * obj, int dx, int dy);


/*
 *  Implementations
 **/


/* Class Definition function
 *
 *   The function Name MUST be [Object name]Class
 *   MUST call OBJ_START_CLASS macro
 *
 * */
Class PointClass() {
	OBJ_START_CLASS(Point);
}


/* Class Constructor:
 *
 *   The function name MUST be [Object name]Class_ctor
 *   This function is called on the first call of [Object name]Class()
 *   Should call the Class Constructor of SUPER Class and
 *     fill up the object with his own parameters
 *
 * */
void PointClass_ctor(void * class, void * meth) {

/* Call Class Constructor of the SUPER Class */
	OBJECT_CLASS(ObjectClass())->class_ctor(class, meth);

/* Fill up Object Parameters*/

	/* Public Methods*/
	CAST_METH(Point, meth)->draw = Point_draw;
	CAST_METH(Point, meth)->move = Point_move;

	/*Private Methods*/
	CAST_CLASS(Object, class)->super 		= ObjectClass();
	CAST_CLASS(Object, class)->class_ctor	= PointClass_ctor;
	CAST_CLASS(Object, class)->ctor 		= Point_ctor;
}


Point * newPoint(int x, int y) {
	Point * obj;

	obj = newObject(PointClass(), OBJ_SIZE(Point), x, y);
	assert(obj);

	return obj;
}


void Point_ctor(void * obj, va_list * app) {
	Point * self = obj;

	super_ctor(PointClass(), obj, app);

	self->x = va_arg(*app, int);
	self->y = va_arg(*app, int);

}

/*Public:*/

void Point_draw(const void * obj) {
	Point * self = (void *) obj;
	printf("\".\" at %d,%d\n", self->x, self->y);
}

void Point_move(const void * obj, int dx, int dy) {
	Point * self = (void *) obj;

	self->x += dx;
	self->y += dy;

	printf("Point moving...\n");
}
