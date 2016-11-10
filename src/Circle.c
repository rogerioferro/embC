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

/* Private Object*/
typedef struct {
	Circle pub;
	privCircle priv;
} _Circle;


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

Class CircleClass() {
	static TYPE_METH(Circle) meths; /* Public Methods*/
	static TYPE_CLASS(Circle) class; /* Private Methods*/

	static Class pClass = NULL;
	if (!pClass) {
		pClass = &class;
		CircleClass_ctor(&class, &meths);
	}
	return pClass;
}

void CircleClass_ctor(void * class, void * meth) {

	superClass_ctor(PointClass(), class, meth);

	/* Public Methods*/
	CAST_METH(Point, meth)->draw = Circle_draw;

	/* Private Methods*/
	CAST_CLASS(Object, class)->super 		= PointClass();
	CAST_CLASS(Object, class)->class_ctor	= CircleClass_ctor;
	CAST_CLASS(Object, class)->ctor 		= Circle_ctor;
}

Circle * newCircle(int x, int y, int rad) {

	Circle * obj;

	printf("creating Circle...\n");

	obj = newObject(CircleClass(), sizeof(_Circle), x, y, rad);

	assert(obj);

	return obj;
}

void Circle_ctor(void * obj, va_list * app) {

	super_ctor( CircleClass(), obj, app);

	CAST(Circle,obj)->rad = va_arg(*app, int);

	printf("Circle_ctor...\n");
}

void Circle_draw(const void * obj) {

	printf("circle at %d,%d rad %d\n",
			CAST(Point,obj)->x, CAST(Point,obj)->y, CAST(Circle,obj)->rad);

}

