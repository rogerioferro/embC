/*
 * Object.h
 *
 *  Created on: 6 de nov de 2016
 *      Author: Rogério
 */

#include <stdlib.h>
#include <stdio.h>

#ifndef OBJECT_H_
#define OBJECT_H_

typedef const void * Class, Meth;


/* Macros */

#define TYPE_METH(obj_type)			meth##obj_type

#define CAST(obj_type,var)			((obj_type *)(var))
#define CAST_METH(obj_type,var)		((TYPE_METH(obj_type) *)(var))

#define OBJ_EXTENDS(x)			x _
#define OBJ_EXTENDS_METH(x)		TYPE_METH(x) _
/*********************/

extern Class ObjectClass();

/*Object Attributes*/
typedef struct {
	const void * _class; /* Class Descriptor*/
	const void * _priv; /* Private attributes*/
} Object;

/*Object Methods*/
typedef struct {
	void (*destroy)(void * obj);
} TYPE_METH(Object);



extern const void * Interface(void * obj, Class class);

#endif /* OBJECT_H_ */
