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

/* Private Object*/
typedef struct {
	Point pub;
	privPoint priv;
} _Point;


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
Class PointClass() {
	static TYPE_METH(Point) meth;
	static TYPE_CLASS(Point) class;
	static Class pClass = NULL;
	if (!pClass) {
		pClass = &class;
		PointClass_ctor(&class, &meth);
	}

	return pClass;
}


void PointClass_ctor(void * class, void * meth) {

	superClass_ctor(ObjectClass(), class, meth);

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
	printf("creating Point...\n");

	obj = newObject(PointClass(), sizeof(_Point), x, y);
	assert(obj);

	return obj;
}


void Point_ctor(void * obj, va_list * app) {
	Point * self = obj;

	super_ctor(PointClass(), obj, app);

	self->x = va_arg(*app, int);
	self->y = va_arg(*app, int);

	printf("Point_ctor...\n");
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
