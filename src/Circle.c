/*
 * Circle.c
 *
 *  Created on: 6 de nov de 2016
 *      Author: Rogério
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "Circle-private.h"

/* Declare Private Object*/
OBJ_DECLARE(Circle);


/*
 *  Declarations
 **/

Circle * newCircle(int x, int y, int rad);
void CircleClass_ctor(void * _meths_, void * meths_);
void Circle_ctor(void * obj, va_list * app);
void Circle_draw(const void * obj);

/*
 *  Implementations
 **/

/* Class Definition function
 *
 *   The function Name MUST be [Object name]Class
 *   MUST call OBJ_START_CLASS macro
 *
 * */
Class CircleClass() {
	OBJ_START_CLASS(Circle);
}

/* Class Constructor:
 *
 *   The function name MUST be [Object name]Class_ctor
 *   This function is called on the first call of [Object name]Class()
 *   Should call the Class Constructor of SUPER Class and
 *     fill up the object with his own parameters
 *
 * */
void CircleClass_ctor(void * class, void * meth) {

	OBJECT_CLASS(PointClass())->class_ctor(class, meth);

	/* Public Methods*/
	CAST_METH(Point, meth)->draw = Circle_draw;

	/* Private Methods*/
	CAST_CLASS(Object, class)->super 		= PointClass();
	CAST_CLASS(Object, class)->class_ctor	= CircleClass_ctor;
	CAST_CLASS(Object, class)->ctor 		= Circle_ctor;
}

Circle * newCircle(int x, int y, int rad) {

	Circle * obj;

	obj = newObject(CircleClass(), OBJ_SIZE(Circle), x, y, rad);

	assert(obj);

	return obj;
}

void Circle_ctor(void * obj, va_list * app) {

	super_ctor( CircleClass(), obj, app);

	CAST(Circle,obj)->rad = va_arg(*app, int);
}

void Circle_draw(const void * obj) {

	printf("circle at %d,%d rad %d\n",
			CAST(Point,obj)->x, CAST(Point,obj)->y, CAST(Circle,obj)->rad);

}

